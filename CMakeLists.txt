cmake_minimum_required(VERSION 3.31.6)


project(CookieClicker
VERSION 0.0.1
LANGUAGES C CXX)

#global Project settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

#Project variables
set(PROJ_EXE "CookieClicker")
set(GLAD_LIB "Glad")
set(THIRD_PARTY_LIBS "ThirdParty")

#fetch SDL content
include(FetchContent)
FetchContent_Declare(
	SDL3
	GIT_REPOSITORY https://github.com/libsdl-org/SDL
	GIT_TAG release-3.2.22
	GIT_SHALLOW ON
)
FetchContent_MakeAvailable(SDL3)

#fetch GLM content
FetchContent_Declare(
	GLM
	GIT_REPOSITORY https://github.com/g-truc/glm
	GIT_TAG 1.0.1
	GIT_SHALLOW ON
)
FetchContent_MakeAvailable(GLM)

#fetch spdlog content
FetchContent_Declare(
	spdlog
	GIT_REPOSITORY https://github.com/gabime/spdlog
	GIT_TAG v1.15.3
	GIT_SHALLOW ON
)
FetchContent_MakeAvailable(spdlog)

#make library for glad
add_library(${GLAD_LIB} STATIC "${THIRD_PARTY_LIBS}/glad/src/glad.c")
target_include_directories(${GLAD_LIB} PUBLIC "${THIRD_PARTY_LIBS}/glad/include/")

find_package(OpenGL REQUIRED)

#link all to exe
add_executable(${PROJ_EXE} "src/main.cpp")
target_link_libraries(${PROJ_EXE} PRIVATE SDL3::SDL3 glm::glm OpenGL::GL ${GLAD_LIB} spdlog::spdlog)
target_include_directories(${PROJ_EXE} PRIVATE "include/")
target_precompile_headers(${PROJ_EXE} PRIVATE "include/PCH.hpp")

add_subdirectory(src)