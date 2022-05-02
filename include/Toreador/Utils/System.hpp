#ifndef TOREADOR_SYSTEM_HPP
#define TOREADOR_SYSTEM_HPP

#include <string>

namespace toreador {
    namespace utils {

        std::string getOSName();
        std::string getRunningPath();

        std::string getGraphicsVendor();
        std::string getGraphicsRenderer();

#define TOREADOR_PRINT_DEBUG() std::cout << "------ [DEBUG INFO] ------\n" \
                                << "GPU: \n" \
                                << "    Vendor: " << toreador::utils::getGraphicsVendor() << "\n" \
                                << "    Renderer: " << toreador::utils::getGraphicsRenderer() << "\n" \
                                << "System: \n" \
                                << "    OS: " << toreador::utils::getOSName() << "\n" \
                                << "    Running Path: " << toreador::utils::getRunningPath() << "\n" \
                                << "------ [DEBUG INFO] ------\n";

    }
}

#endif// TOREADOR_SYSTEM_HPP
