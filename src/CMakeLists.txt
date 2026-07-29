set(CORE_LIB_NAME ${PROJECT_NAME}_core)

add_library(${CORE_LIB_NAME} STATIC)
add_library(cpp_libraries::core ALIAS ${CORE_LIB_NAME})

target_link_libraries(
    ${CORE_LIB_NAME} 
    PUBLIC project_options
    PRIVATE project_warnings
)

## Optional dependencies 
if(USE_GFLAGS)
    target_link_libraries(${CORE_LIB_NAME}
        PRIVATE
            gflags
    )
endif()

if(USE_GLOG)
    target_link_libraries(${CORE_LIB_NAME}
        PRIVATE
            glog::glog
    )
endif()

## Include directories
target_include_directories(${CORE_LIB_NAME}
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

## Source subdirectories
add_subdirectory(logger)
add_subdirectory(thread_pool)
