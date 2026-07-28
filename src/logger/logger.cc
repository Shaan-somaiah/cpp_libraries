#include "cppLibraries/logger.h"
#include <string>
#include <iostream>

namespace cppLibraries {
    Logger::Logger() = default;

    Logger::Logger(const std::string& file_path) : m_log_file(file_path){
        m_log_to_file = true;
        if(!m_log_file){
            std::cout << "Unable to open log file!";
        }
    }

    Logger::~Logger(){
        if(m_log_file.is_open()){
            m_log_file.close();    
        }
    }

    void Logger::LogInfo(const std::string& message) {
        if(m_log_to_file){
            m_log_file << "[INFO] " << message << "\n";
        }
        std::cout << "[INFO] " << message << "\n";
    }

    void Logger::LogWarning(const std::string& message) {
        if(m_log_to_file){
            m_log_file << "[WARN] " << message << "\n";
        }
        std::cout << "[WARN] " << message << "\n";
    }

    void Logger::LogError(const std::string& message) {
        if(m_log_to_file){
            m_log_file << "[ERRO] " << message << "\n";
        }
        std::cout << "[ERRO] " << message << "\n";
    }
} // namespace cppLibraries