#ifndef CPP_LIBRARIES_LOGGER_H
#define CPP_LIBRARIES_LOGGER_H

#include <string>
#include <fstream>

namespace cppLibraries {

    class Logger{

        private:
            std::ofstream m_log_file;
            // only log to file if filepath is passed while constructing LOGGER object
            bool m_log_to_file{false}; 

        public:
            Logger();
            Logger(const std::string& file_path);
            ~Logger();

            void LogInfo(const std::string& message);
            void LogWarning(const std::string& message);
            void LogError(const std::string& message);
    };
} // namespace cppLibraries

#endif //CPP_LIBRARIES_LOGGER_H
