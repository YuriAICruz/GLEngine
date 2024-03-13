#include "Model.h"
#include <GL/glew.h>

#include "GLTools.h"

namespace Gly
{
    void Model::generateBuffer()
    {
        unsigned int verticesCount = vertices.size() / vertexDataCount;

        GLCall(glGenBuffers(1, &buffer));
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, buffer));
        GLCall(glBufferData(GL_ARRAY_BUFFER, verticesCount * vertexDataCount * sizeof(float), vertices.data(), GL_STATIC_DRAW));

        GLCall(glEnableVertexAttribArray(0));
        GLCall(glVertexAttribPointer(0, vertexDataCount, GL_FLOAT, GL_FALSE, sizeof(float) * vertexDataCount, 0));
        GLCall(glUseProgram(material.GetProgramId()));
        
        unsigned int trianglesCount = triangles.size() / 3;
        GLCall(glGenBuffers(1, &indexBuffer));
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer));
        GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, trianglesCount * 3 * sizeof(float), triangles.data(), GL_STATIC_DRAW));
    }

    void Model::render()
    {
        unsigned int trianglesCount = triangles.size() / 3;

        GLCall(glDrawElements(GL_TRIANGLES, trianglesCount * 3, GL_UNSIGNED_INT, nullptr));
    }
}
