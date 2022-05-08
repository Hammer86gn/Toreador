#ifndef TOREADOR_SHADER_HPP
#define TOREADOR_SHADER_HPP

#include <string>

namespace toreador {
    namespace render {
        class Shader {
        public:
            Shader(std::string& vertexShader, std::string& fragmentShader);
            ~Shader();

            unsigned int getShaderID();

            void bind();
        private:
            unsigned int m_shaderID;
        };
    }
}

#endif// TOREADOR_SHADER_HPP
