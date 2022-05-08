#include <iostream>

#include <Toreador/Core/Application/Application.hpp>
#include <Toreador/Core/Application/EntryPoint.hpp>

#include <Toreador/Utils/System.hpp>

#include <Toreador/Renderer/Core/GPUMemoryBuffer.hpp>

namespace test {
    toreador::ApplicationSettings settings = { 720,  720,  60,

                                               true, true, false };

    class TestApplication : public toreador::Application {
    public:
        TestApplication() : toreador::Application( "Test Game", settings )
        {
            TOREADOR_PRINT_DEBUG();
            std::cout << "Created Test Game\n";


        }

        void onTestRender() override {
            renderTest();
        }

        static void renderTest() {
            std::string vertexShaderSource = "#version 400 core\n"
                                             "layout (location = 0) in vec3 aPos;\n"
                                             "void main()\n"
                                             "{\n"
                                             "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                             "}";

            std::string fragmentShaderSource = "#version 400 core\n"
                                             "out vec4 FragColor;\n"
                                             "void main()\n"
                                             "{\n"
                                             "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                             "}";

            float vertices[] = {
                    0.5f,  0.5f, 0.0f, // top right
                    0.5f, -0.5f, 0.0f,  // bottom right
                    -0.5f, -0.5f, 0.0f,  // bottom left
                    -0.5f,  0.5f, 0.0f,  // top left
            };
            unsigned int indices[] = {
                    0, 1, 3,   // first triangle
                    1, 2, 3    // second triangle
            };

            toreador::render::Shader shader(vertexShaderSource, fragmentShaderSource);

            auto* buffer = new toreador::render::GPUMemoryBuffer();
            buffer->insertShader(shader);
            buffer->upsertVertices(vertices);
            buffer->upsertIndices(indices);
            buffer->insertVertexAttribute({0, 3, toreador::render::VertexAttributeType::FLOAT});
            buffer->draw(6);

        }
    };
}// namespace test

toreador::Application* toreador::createApplication( int argc, const char** argv )
{
    return new test::TestApplication();
}