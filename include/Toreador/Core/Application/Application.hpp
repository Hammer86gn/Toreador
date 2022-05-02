#ifndef TOREADOR_APPLICATION_HPP
#define TOREADOR_APPLICATION_HPP

#include <string>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace toreador {

    struct ApplicationSettings {
        int width;
        int height;
        int refreshRate;

        bool vsync;
        bool resize;
        bool maximized;
    };


    class Application {
    public:
        Application(const std::string& name, ApplicationSettings settings);
        ~Application();

    private:
        void setupApplication();

        std::string m_name;
        toreador::ApplicationSettings m_settings; // Should this be passed as a function parameter? - Chloe

        GLFWwindow* m_window;
    };

}

#endif// TOREADOR_APPLICATION_HPP
