#pragma once
#include "../framework.h"
#include <string>

namespace Gly
{
    class GLY_API Shader
    {
    private:
        unsigned int program;

    public:
        Shader(const char* vertFilePath, const char* fragFilePath);

        ~Shader();

        bool checkError(int id, const char* source) const;
        unsigned int GetProgram();
        std::string readFileToString(const std::string& filePath);
    };
}
