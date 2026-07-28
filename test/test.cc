#include <cppLibraries/logger.h>

int main() {

    cppLibraries::Logger i_logger("/tmp/logTest");
    i_logger.LogError("Error");
    i_logger.LogWarning("Warning");
    i_logger.LogInfo("Info");
}
