
set(TARGET_NAME_UNIT_TEST geometry-unit-test)
add_executable(${TARGET_NAME_UNIT_TEST})

find_package(GTest REQUIRED)

file(GLOB UNIT_TEST_CPP_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

target_sources(${TARGET_NAME_UNIT_TEST}
    PUBLIC
        ${UNIT_TEST_CPP_FILES}
        main.cpp)

target_link_libraries(${TARGET_NAME_UNIT_TEST} 
    PUBLIC
        gtest::gtest)
        
