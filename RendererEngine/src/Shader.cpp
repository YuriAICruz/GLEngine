#include "Shader.h"

#include <fstream>
#include <iostream>
#include <malloc.h>
#include <sstream>
#include <thread>
#include <GL/glew.h>

namespace Gly
{
    Shader::Shader(const char* vertFilePath, const char* fragFilePath)
    {
        program = glCreateProgram();
        unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
        std::string str = readFileToString(vertFilePath);
        const char* c = str.c_str();
        glShaderSource(vs, 1, &c, nullptr);
        glCompileShader(vs);

        if (checkError(vs, c))
        {
            glDeleteShader(vs);
            return;
        }

        unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);
        str = readFileToString(fragFilePath);
        c = str.c_str();
        glShaderSource(fs, 1, &c, nullptr);
        glCompileShader(fs);

        if (checkError(fs, c))
        {
            glDeleteShader(fs);
            return;
        }

        glAttachShader(program, vs);
        glAttachShader(program, fs);

        glLinkProgram(program);
        glValidateProgram(program);

        glDeleteShader(vs);
        glDeleteShader(fs);
    }

    Shader::~Shader()
    {
        glDeleteProgram(program);
    }

    bool Shader::checkError(int id, const char* source) const
    {
        int result;
        glGetShaderiv(id, GL_COMPILE_STATUS, &result);

        if (result == GL_FALSE)
        {
            int length;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

            char* message = (char*)alloca(length * sizeof(char));
            glGetShaderInfoLog(id, length, &length, message);
            std::cout << "Failed to compile: " << message << std::endl;
            std::cout << "SOURCE CODE:\n{\n" << source << "\n}" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(400));
            return true;
        }

        return false;
    }

    unsigned int Shader::GetProgram()
    {
        return program;
    }

    std::string Shader::readFileToString(const std::string& filePath)
    {
        std::ifstream file(filePath);

        std::string line;
        std::string content;

        //skip first line
        std::getline(file, line);

        int lineIndex = 0;
        if (file.is_open())
        {
            while (std::getline(file, line))
            {
                if (lineIndex > 0)
                {
                    content += "\n";
                }

                content += line;
                lineIndex++;
            }
            file.close();
        }
        else
        {
            std::stringstream ss;
            ss << "Unable to open file: " << filePath;
            throw std::runtime_error(ss.str());
        }

        return content;
    }
}
