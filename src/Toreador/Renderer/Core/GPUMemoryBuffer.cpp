#include <Toreador/Renderer/Core/GPUMemoryBuffer.hpp>

toreador::render::GPUMemoryBuffer::GPUMemoryBuffer()
{
    glGenBuffers(1, &this->m_bufferID);
    glGenBuffers(1, &this->m_elementBufferID);
    glGenVertexArrays(1, &this->m_vaoID);
}

toreador::render::GPUMemoryBuffer::~GPUMemoryBuffer() {
    glDeleteBuffers(1, &this->m_bufferID);
    glDeleteBuffers(1, &this->m_elementBufferID);
    glDeleteVertexArrays(1, &this->m_vaoID);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void toreador::render::GPUMemoryBuffer::upsertVertices( float data[] )
{
    glBindVertexArray(this->m_vaoID);

    glBindBuffer(GL_ARRAY_BUFFER, this->m_bufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
}

void toreador::render::GPUMemoryBuffer::upsertIndices( unsigned int data[] )
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_elementBufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
}

int calcSizeOfVertexAttribType(toreador::render::VertexAttributeType type, int size) {
    long dataTypeSize;

    switch ( type ) {

        case toreador::render::VertexAttributeType::BYTE:
            dataTypeSize = sizeof(char);
            break;
        case toreador::render::VertexAttributeType::UNSIGNED_BYTE:
            dataTypeSize = sizeof(unsigned char);
            break;
        case toreador::render::VertexAttributeType::SHORT:
            dataTypeSize = sizeof(short);
            break;
        case toreador::render::VertexAttributeType::UNSIGNED_SHORT:
            dataTypeSize = sizeof(unsigned short);
            break;
        case toreador::render::VertexAttributeType::INT:
            dataTypeSize = sizeof(int);
            break;
        case toreador::render::VertexAttributeType::UNSIGNED_INT:
            dataTypeSize = sizeof(unsigned int);
            break;
        case toreador::render::VertexAttributeType::FLOAT:
            dataTypeSize = sizeof(float);
            break;
        case toreador::render::VertexAttributeType::DOUBLE:
            dataTypeSize = sizeof(double);
            break;
    }

    return dataTypeSize * size;
}

void toreador::render::GPUMemoryBuffer::insertVertexAttribute( toreador::render::VertexAttribute vertexAttribute )
{
    glVertexAttribPointer(vertexAttribute.position, vertexAttribute.size, (GLenum) vertexAttribute.type, GL_FALSE, calcSizeOfVertexAttribType(vertexAttribute.type, vertexAttribute.size), (void*) vertexAttribute.offset);
    glEnableVertexAttribArray(vertexAttribute.position);
}

void toreador::render::GPUMemoryBuffer::insertShader( toreador::render::Shader& shader )
{
    this->m_shaderID = shader.getShaderID();
}

void toreador::render::GPUMemoryBuffer::draw(int elements)
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glUseProgram(this->m_shaderID);
    glBindVertexArray(this->m_vaoID);
    glDrawElements(GL_TRIANGLES, elements, GL_UNSIGNED_INT, 0);
}