#ifndef TOREADOR_SYSTEM_HPP
#define TOREADOR_SYSTEM_HPP

#include <string>

namespace toreador {
    namespace utils {

        std::string getOSName();
        std::string getRunningPath();

        std::string getGraphicsVendor();
        std::string getGraphicsRenderer();
    }
}

#endif// TOREADOR_SYSTEM_HPP
