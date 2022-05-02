#include <Toreador/Utils/System.hpp>
#include <filesystem>
#include <glad/gl.h>

namespace fs = std::filesystem;

std::string toreador::utils::getOSName()
{
#ifdef _WIN64
    return "Windows 64-bit";
#elif _WIN32
    return "Windows 32-bit";
#elif __APPLE__ || __MACH__
    return "OSX";
#elif __linux__
    return "Linux";
#elif __FreeBSD__
    return "FreeBSD"
#elif __unix || __unix__
    return "Unix";
#else
    return "Unkown OS";
#endif
}

std::string toreador::utils::getRunningPath()
{
    return fs::current_path().string();
}

std::string toreador::utils::getGraphicsVendor()
{
    return ( const char* ) glGetString( GL_VENDOR );
}

std::string toreador::utils::getGraphicsRenderer()
{
    return ( const char* ) glGetString( GL_RENDERER );
}
