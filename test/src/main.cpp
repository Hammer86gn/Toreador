#include <iostream>

#include <Toreador/Core/Application/Application.hpp>
#include <Toreador/Core/Application/EntryPoint.hpp>

#include <Toreador/Utils/System.hpp>

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
    };
}// namespace test

toreador::Application* toreador::createApplication( int argc, const char** argv )
{
    return new test::TestApplication();
}