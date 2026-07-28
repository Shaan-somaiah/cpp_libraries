include(FetchContent)

## build options
option(USE_SYSTEM_PACKAGES "Use system packages instead of fetching dependencies" ON)

option(USE_GLOG "Use glog for logging" ON)
option(USE_GFLAGS "Use gflags for command-line flag parsing" ON)

## Check if required packages are already installed, if not complile from source

## Google gflags library 
if(USE_GFLAGS)
    if(USE_SYSTEM_PACKAGES)
        find_package(gflags CONFIG QUIET)
    endif()

    if(NOT gflags_FOUND)
        message(STATUS "gflags not installed locally, building from source!!")

        FetchContent_Declare(
            gflags
            GIT_REPOSITORY https://github.com/gflags/gflags.git
            GIT_TAG v2.3.0
            GIT_SHALLOW TRUE
        )

        FetchContent_MakeAvailable(gflags)

    else()
        message(STATUS "Using system installed gflags!")
    endif()
endif()

## Google logging library 
if(USE_GLOG)
    if(USE_SYSTEM_PACKAGES)
        find_package(glog CONFIG QUIET)
    endif()

    if(NOT glog_FOUND)
        message(STATUS "glog not installed locally, building from source!!")

        FetchContent_Declare(
            glog
            GIT_REPOSITORY https://github.com/google/glog.git
            GIT_TAG v0.7.1
            GIT_SHALLOW TRUE
        )

        FetchContent_MakeAvailable(glog)

    else()
        message(STATUS "Using system installed glog!")
    endif()
endif()

