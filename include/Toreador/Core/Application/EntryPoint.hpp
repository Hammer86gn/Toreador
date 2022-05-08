#ifndef TOREADOR_ENTRYPOINT_HPP
#define TOREADOR_ENTRYPOINT_HPP

#include <Toreador/Core/Application/Application.hpp>
#include <glad/gl.h>

extern toreador::Application* toreador::createApplication( int argc, const char** argv );

int main( int argc, const char** argv )
{
    auto game = toreador::createApplication( argc, argv );

    while(!glfwWindowShouldClose(game->getWindow())) {

        glfwMakeContextCurrent(game->getWindow());
        glClear(GL_COLOR_BUFFER_BIT);

        game->onTestRender();

        if (game->useVSync()) {
            glfwSwapBuffers( game->getWindow() );
        }

        glfwPollEvents();
    }


    delete game;
    return 0x0;
}

#endif// TOREADOR_ENTRYPOINT_HPP
