cmake_minimum_required(VERSION 3.15)
project(casadi_cpp CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(CASADI REQUIRED)

# For some reason, even if casadi is found (CASADI_FOUND is 1) and some variables are popuplated,
# the ones that we are interested in for linking are not. So we have to do it manually. 
# We use the variable CASADI_DIR to construct the variables CASADI_INCLUDE_DIR and CASADI_LIBRARIES.
set(CASADI_INCLUDE_DIR "${CASADI_DIR}/../../../include")
set(CASADI_LIBRARIES "${CASADI_DIR}/../../../lib/libcasadi.dylib")
# make them absolute paths
get_filename_component(CASADI_INCLUDE_DIR "${CASADI_INCLUDE_DIR}" ABSOLUTE)
get_filename_component(CASADI_LIBRARIES "${CASADI_LIBRARIES}" ABSOLUTE)

# dump all variables to see what is going on
message(STATUS "CASADI_INCLUDE_DIR: ${CASADI_INCLUDE_DIR}")
message(STATUS "CASADI_LIBRARIES: ${CASADI_LIBRARIES}")
get_cmake_property(_variableNames VARIABLES)
foreach (_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
endforeach()

add_executable(main main.cpp)
include_directories(${CASADI_INCLUDE_DIR}) # this is actually not necessary because the include are somehow still found automatically by the compiler 
target_link_libraries(main ${CASADI_LIBRARIES})
