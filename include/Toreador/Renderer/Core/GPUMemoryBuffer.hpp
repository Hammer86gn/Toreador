#ifndef TOREADOR_GPUMEMORYBUFFER_HPP
#define TOREADOR_GPUMEMORYBUFFER_HPP

#include <glad/gl.h>
#include <Toreador/Renderer/Core/Shader.hpp>

namespace toreador {
    namespace render {
        struct VertexAttribute;
        enum class VertexAttributeType;

        class GPUMemoryBuffer {
        public:
            GPUMemoryBuffer();
            ~GPUMemoryBuffer();

            void upsertVertices(float[]);
            void upsertIndices(unsigned int[]);

            void insertVertexAttribute(VertexAttribute vertexAttribute);
            void insertShader(Shader& shader);

            void draw(int elements);
        private:
            unsigned int m_bufferID;
            unsigned int m_elementBufferID;
            unsigned int m_vaoID;
            unsigned int m_shaderID;
        };

        struct VertexAttribute {
                unsigned int position; // if layout (location = 0) and position is 0 it will configure location
                unsigned int size; // e.g. size of 3 means a vec3
                VertexAttributeType type;
                unsigned int offset = 0; // Example vertex = {1 , 1, 1, 255, 53, 42} if we want a size of 3 and we want color then we would in this example offset by 3 because the color in this example starts at the 4th
        };

        enum class VertexAttributeType {
            BYTE = GL_BYTE,
            UNSIGNED_BYTE = GL_UNSIGNED_BYTE,
            SHORT = GL_SHORT,
            UNSIGNED_SHORT = GL_UNSIGNED_SHORT,
            INT = GL_INT,
            UNSIGNED_INT = GL_UNSIGNED_INT,
            FLOAT = GL_FLOAT,
            DOUBLE = GL_DOUBLE,
        };

    }
}

#endif// TOREADOR_GPUMEMORYBUFFER_HPP
