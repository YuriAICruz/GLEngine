#include "Model.h"

#include "GLTools.h"
#include "Material.h"

#include <GL/glew.h>
#include <iostream>

#ifndef TINYGLTF_IMPLEMENTATION

#define TINYGLTF_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#ifndef _DEBUG
#define TINYGLTF_NOEXCEPTION
#define JSON_NOEXCEPTION
#endif // _DEBUG

#include "tiny_gltf/tiny_gltf.h"
#endif // TINYGLTF_HEADER_ONLY

namespace Gly
{
    Model::Model(const std::vector<float>& vertices, const std::vector<unsigned int>& triangles, Material* mat) :
        material(mat),
        vertices(vertices),
        triangles(triangles)
    {
    }

    Model::Model(const char* gltfFilePath, Material* mat, bool binary) :
        material(mat)
    {
        tinygltf::Model model;
        tinygltf::TinyGLTF loader;

        std::string err, warn;
        bool success;

        vertices.clear();
        triangles.clear();

        if (binary)
        {
            success = loader.LoadBinaryFromFile(&model, &err, &warn, gltfFilePath);
        }
        else
        {
            success = loader.LoadASCIIFromFile(&model, &err, &warn, gltfFilePath);
        }
        if (!warn.empty())
        {
            std::cout << "Warning: " << warn << std::endl;
        }
        if (!err.empty())
        {
            std::cerr << "Error: " << err << std::endl;
        }
        if (!success)
        {
            std::cerr << "Failed to load glTF file." << std::endl;
            return;
        }

        for (const tinygltf::Mesh& mesh : model.meshes)
        {
            for (const tinygltf::Primitive& primitive : mesh.primitives)
            {
                const tinygltf::Accessor& indexAccessor = model.accessors[primitive.indices];

                // TODO: read attribs other that vertex positions
                for (const auto& attrib : primitive.attributes)
                {
                    tinygltf::Accessor accessor = model.accessors[attrib.second];
                    int byteStride =
                        accessor.ByteStride(model.bufferViews[accessor.bufferView]);

                    int size = 1;
                    if (accessor.type != TINYGLTF_TYPE_SCALAR)
                    {
                        size = accessor.type;
                    }

                    int vaa = -1;
                    if (attrib.first.compare("POSITION") == 0) vaa = 0;
                    if (attrib.first.compare("NORMAL") == 0) vaa = 1;
                    if (attrib.first.compare("TEXCOORD_0") == 0) vaa = 2;
                    if (vaa == -1)
                    {
                        std::cout << "invalid attribute: " << attrib.first << "\n";
                    }
                }
                
                const auto& positionAccessor = model.accessors[primitive.attributes.at("POSITION")];
                const auto& positionBufferView = model.bufferViews[positionAccessor.bufferView];
                const auto& positionBuffer = model.buffers[positionBufferView.buffer];
                const float* positionPtr = reinterpret_cast<const float*>(&positionBuffer.data[positionAccessor.byteOffset + positionBufferView.byteOffset]);

                for (size_t i = 0; i < positionAccessor.count; ++i) {
                    vertices.push_back(positionPtr[i * 3]);
                    vertices.push_back(positionPtr[i * 3 + 1]);
                    vertices.push_back(positionPtr[i * 3 + 2]);
                }
                
                const auto& indexBufferView = model.bufferViews[indexAccessor.bufferView];
                const auto& indexBuffer = model.buffers[indexBufferView.buffer];
                const uint16_t* indexPtr = reinterpret_cast<const uint16_t*>(&indexBuffer.data[indexAccessor.byteOffset + indexBufferView.byteOffset]);

                for (size_t i = 0; i < indexAccessor.count; i += 3) {
                    triangles.push_back(indexPtr[i]);
                    triangles.push_back(indexPtr[i + 1]);
                    triangles.push_back(indexPtr[i + 2]);

                    const uint16_t i0 = indexPtr[i];
                    const uint16_t i1 = indexPtr[i + 1];
                    const uint16_t i2 = indexPtr[i + 2];
                }
            }
        }
    }

    void Model::generateBuffer()
    {
        unsigned int verticesCount = vertices.size() / vertexDataCount;

        GLCall(glGenVertexArrays(1, &vao));
        GLCall(glBindVertexArray(vao));

        GLCall(glGenBuffers(1, &buffer));
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, buffer));
        GLCall(
            glBufferData(GL_ARRAY_BUFFER, verticesCount * vertexDataCount * sizeof(float), vertices.data(),
                GL_STATIC_DRAW));

        GLCall(glEnableVertexAttribArray(0));
        GLCall(glVertexAttribPointer(0, vertexDataCount, GL_FLOAT, GL_FALSE, sizeof(float) * vertexDataCount, 0));


        unsigned int trianglesCount = triangles.size() / 3;
        GLCall(glGenBuffers(1, &indexBuffer));
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer));
        GLCall(
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, trianglesCount * 3 * sizeof(float), triangles.data(), GL_STATIC_DRAW
            ));
    }

    void Model::render()
    {
        unsigned int trianglesCount = triangles.size() / 3;

        GLCall(glBindVertexArray(vao));
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, buffer));
        material->useMaterial();
        GLCall(glDrawElements(GL_TRIANGLES, trianglesCount * 3, GL_UNSIGNED_INT, nullptr));
    }
}
