#include <Toreador/Core/Application/Application.hpp>
#include <glad/gl.h>
#include <iostream>

toreador::Application::Application( const std::string& name, toreador::ApplicationSettings settings )
{
    this->m_name = name;
    this->m_settings = settings;

    this->setupApplication();
}

toreador::Application::~Application()
{
    glfwDestroyWindow( this->m_window );
    glfwTerminate();
}

void toreador::Application::setupApplication()
{
    if ( !glfwInit() ) {
        std::cout << "Failed to initialize GLFW\n Stopping\n";
        // TODO(Chloe) Stop
    }

    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 0 );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

    glfwWindowHint( GLFW_REFRESH_RATE, this->m_settings.refreshRate );
    glfwWindowHint( GLFW_MAXIMIZED, this->m_settings.maximized ? GLFW_TRUE : GLFW_FALSE );
    glfwWindowHint( GLFW_RESIZABLE, this->m_settings.resize ? GLFW_TRUE : GLFW_FALSE );

    this->m_window =
            glfwCreateWindow( this->m_settings.width, this->m_settings.height, this->m_name.c_str(), NULL, NULL );

    if ( !this->m_window ) {
        std::cout << "Failed to initialize the GLFW Window\n Stopping\n";
        glfwTerminate();
        // TODO(Chloe) Stop
    }

    glfwMakeContextCurrent( this->m_window );
    if ( gladLoadGL( glfwGetProcAddress ) == 0 ) {
        std::cout << "Failed to initialize GLAD\n Stopping\n";
        glfwTerminate();
    }

    glViewport( 0, 0, this->m_settings.width, this->m_settings.height );
}

GLFWwindow* toreador::Application::getWindow()
{
    return this->m_window;
}

bool toreador::Application::useVSync()
{
    return this->m_settings.vsync;
}
