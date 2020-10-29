# !!! WARNING !!! AUTO-GENERATED FILE, PLEASE DO NOT MODIFY IT AND USE
# https://docs.platformio.org/page/projectconf/section_env_build.html#build-flags
#
# If you need to override existing CMake configuration or add extra,
# please create `CMakeListsUser.txt` in the root of project.
# The `CMakeListsUser.txt` will not be overwritten by PlatformIO.

cmake_minimum_required(VERSION 3.13)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

project("flower-pumping" C CXX)

include(CMakeListsPrivate.txt)

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/CMakeListsUser.txt)
include(CMakeListsUser.txt)
endif()

add_custom_target(
    Production ALL
    COMMAND platformio -c clion run "$<$<NOT:$<CONFIG:All>>:-e${CMAKE_BUILD_TYPE}>"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    Debug ALL
    COMMAND platformio -c clion run --target debug "$<$<NOT:$<CONFIG:All>>:-e${CMAKE_BUILD_TYPE}>"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

link_directories(src/lib)
add_executable(Z_DUMMY_TARGET ${SRC_LIST} src/screen.cpp src/screen.h src/pinout.h src/data_lake.cpp src/data_lake.h src/humidity_sensor.cpp src/humidity_sensor.h src/self_supply_sensor.cpp src/self_supply_sensor.h src/watering.cpp src/watering.h src/states.h src/states/self_check_state.cpp src/states/self_check_state.h src/states/measurement_state.cpp src/states/measurement_state.h src/configuration.h src/common_math.cpp src/common_math.h src/states.cpp src/states/watering_state.cpp src/states/watering_state.h src/display_service.cpp src/display_service.h)
