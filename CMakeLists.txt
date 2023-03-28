
cmake_minimum_required(VERSION 3.22)
project(DA_Projeto_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(DA_Projeto_1 src/main.cpp src/CSV_reader.cpp include/Estacao.h src/Estacao.cpp include/Menu.h include/Gestor.h src/Menu.cpp src/Gestor.cpp)

include_directories(DA_Projeto_1 /include)


find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()
    set(DOXYGEN_IN "Doxyfile")
    set(DOXYGEN_OUT "${CMAKE_SOURCE_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)
    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)
