#ifndef TOREADOR_ENTRYPOINT_HPP
#define TOREADOR_ENTRYPOINT_HPP

#include <Toreador/Core/Application/Application.hpp>

extern toreador::Application* toreador::createApplication( int argc, const char** argv );

int main( int argc, const char** argv )
{
    auto game = toreador::createApplication( argc, argv );
    // TODO(Chloe) this

    delete game;
    return 0x0;
}

#endif// TOREADOR_ENTRYPOINT_HPP
