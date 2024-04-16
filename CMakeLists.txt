cmake_minimum_required(VERSION 3.28)
project(ibkr_tool)

add_subdirectory(third_party)
add_executable(ibkr_tool src/main.cpp
        src/CppClient.cpp
)

target_include_directories(ibkr_tool
        PUBLIC
        ${tws_api_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(ibkr_tool
        PRIVATE
        tws_api
        intelrdfpmath)

target_compile_features(ibkr_tool PUBLIC cxx_std_20)