cmake_minimum_required(VERSION 3.28)
project(tws_api_test_client)

set(CMAKE_CXX_STANDARD 20)

add_executable(tws_api_test_client
        Cpp/TestCppClient/AccountSummaryTags.cpp
        Cpp/TestCppClient/AvailableAlgoParams.cpp
        Cpp/TestCppClient/ContractSamples.cpp
        Cpp/TestCppClient/Main.cpp
        Cpp/TestCppClient/OrderSamples.cpp
        Cpp/TestCppClient/ScannerSubscriptionSamples.cpp
        Cpp/TestCppClient/StdAfx.cpp
        Cpp/TestCppClient/CppClient.cpp
        Cpp/TestCppClient/Utils.cpp
)

target_include_directories(
        tws_api_test_client
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_link_libraries(tws_api_test_client
        PRIVATE
        tws_api
        intelrdfpmath
)