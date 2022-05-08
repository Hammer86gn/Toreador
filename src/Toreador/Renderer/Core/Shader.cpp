#include <Toreador/Renderer/Core/Shader.hpp>
#include <glad/gl.h>
#include <iostream>

toreador::render::Shader::Shader( std::string& vertexShader, std::string& fragmentShader )
{
    std::cout << "Creating Vertex Shader\n";
    unsigned int vertexShaderID = glCreateShader( GL_VERTEX_SHADER );
    std::cout << "Setting Source\n";
    const char* srcV = vertexShader.c_str();
    glShaderSource( vertexShaderID, 1, &srcV, NULL );
    std::cout << "Compiling Shader\n";
    glCompileShader( vertexShaderID );

    int success;
    char dump[1024];
    glGetShaderiv( vertexShaderID, GL_COMPILE_STATUS, &success );
    std::cout << "Checked Compile status\n";

    if ( !success ) {
        int logLen;
        glGetShaderInfoLog( vertexShaderID, 1024, &logLen, dump );
        std::cout << "Failed to compile Vertex Shader:\n" << dump << "\n";
    }

    unsigned int fragmentShaderID = glCreateShader( GL_FRAGMENT_SHADER );
    const char* srcF = fragmentShader.c_str();
    glShaderSource( fragmentShaderID, 1,  &srcF, NULL );
    glCompileShader( fragmentShaderID );

    glGetShaderiv( fragmentShaderID, GL_COMPILE_STATUS, &success );

    if ( !success ) {
        int logLen;
        glGetShaderInfoLog( fragmentShaderID, 1024, &logLen, dump );
        std::cout << "Failed to compile Fragment Shader:\n" << dump << "\n";
    }

    this->m_shaderID = glCreateProgram();
    glAttachShader( this->m_shaderID, vertexShaderID );
    glAttachShader( this->m_shaderID, fragmentShaderID );
    glLinkProgram( this->m_shaderID );

    glGetShaderiv( this->m_shaderID, GL_LINK_STATUS, &success );

    if ( !success ) {
        int logLen;
        glGetShaderInfoLog( this->m_shaderID, 1024, &logLen, dump );
        std::cout << "Failed to link shader program:\n" << dump << "\n";
    }

    glDeleteShader( vertexShaderID );
    glDeleteShader( fragmentShaderID );
}

toreador::render::Shader::~Shader()
{
    glDeleteProgram( this->m_shaderID );
}

unsigned int toreador::render::Shader::getShaderID()
{
    return this->m_shaderID;
}

void toreador::render::Shader::bind()
{
    glUseProgram( this->m_shaderID );
}
