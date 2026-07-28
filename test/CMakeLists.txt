set(CORE_LIB_NAME ${PROJECT_NAME}_core)
set(CORE_TEST_NAME ${PROJECT_NAME}_test)

add_executable(${CORE_TEST_NAME} test.cc)

target_link_libraries(${CORE_TEST_NAME}
     PRIVATE ${CORE_LIB_NAME}
)

add_test(NAME ${PROJECT_NAME}.test COMMAND 
${CORE_TEST_NAME})
