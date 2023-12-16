cmake_minimum_required(VERSION 3.27.4)
project(Chaos-TheoJJF LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(chaos_exe 
    src/main.cpp
    src/Chaotic_Dynamical_Systems.cpp
    src/Lorenz_System.cpp
    src/Thomas_System.cpp
)
target_link_libraries(chaos_exe PRIVATE sfml-graphics)
target_compile_features(chaos_exe PRIVATE cxx_std_23)

if(WIN32)
    add_custom_command(
        TARGET chaos_exe
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:CMakeSFMLProject>
        VERBATIM)
endif()

install(TARGETS chaos_exe)
