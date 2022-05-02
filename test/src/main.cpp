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
            std::cout << "Created Test Game\n";

            std::cout << "------ [DEBUG INFO] ------\n"
                      << "GPU: \n"
                      << "    Vendor: " << toreador::utils::getGraphicsVendor() << "\n"
                      << "    Renderer: " << toreador::utils::getGraphicsRenderer() << "\n"
                      << "System: \n"
                      << "    OS: " << toreador::utils::getOSName() << "\n"
                      << "    Running Path: " << toreador::utils::getRunningPath() << "\n"
                      << "------ [DEBUG INFO] ------\n";

        }
    };
}// namespace test

toreador::Application* toreador::createApplication( int argc, const char** argv )
{
    return new test::TestApplication();
}