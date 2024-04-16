cmake_minimum_required(VERSION 3.28)
project(tws_api)

option(BUILD_EXAMPLES "Whether or not to build examples" ON)

if (BUILD_EXAMPLES)
    message(STATUS "Building example...")
    add_subdirectory(samples)
endif ()

add_library(
        tws_api
        client/ContractCondition.cpp
        client/Decimal.cpp
        client/DefaultEWrapper.cpp
        client/EClient.cpp
        client/EClientSocket.cpp
        client/EDecoder.cpp
        client/EMessage.cpp
        client/EMutex.cpp
        client/EOrderDecoder.cpp
        client/EReader.cpp
        client/EReaderOSSignal.cpp
        client/ESocket.cpp
        client/executioncondition.cpp
        client/MarginCondition.cpp
        client/OperatorCondition.cpp
        client/OrderCondition.cpp
        client/PercentChangeCondition.cpp
        client/PriceCondition.cpp
        client/SoftDollarTier.cpp
        client/StdAfx.cpp
        client/TimeCondition.cpp
        client/Utils.cpp
        client/VolumeCondition.cpp
)

target_include_directories(
        tws_api
        PUBLIC
        client
)

target_compile_features(tws_api PUBLIC cxx_std_20)