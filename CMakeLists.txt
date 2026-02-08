cmake_minimum_required(VERSION 3.31.6)

project(CookieClicker
VERSION 0.0.1
LANGUAGES CXX)

#Proj variables
set(GAME_EXE "CookieClicker")


#setup EXE Target	
add_executable(${GAME_EXE} "src/main.cpp")

if(WIN32)
    target_link_options(${GAME_EXE} PRIVATE
        "$<$<CONFIG:Release>:/SUBSYSTEM:WINDOWS>"
    )
endif()

set_target_properties(${GAME_EXE} PROPERTIES
CXX_STANDARD 23
CXX_STANDARD_REQUIRED ON
CXX_EXTENSIONS OFF)

#fetch needed libraries
include(FetchContent)

FetchContent_Declare(
	sfml
	GIT_REPOSITORY https://github.com/SFML/SFML
	GIT_TAG 3.0.2
	GIT_SHALLOW TRUE
)
FetchContent_Declare(
	tgui
	GIT_REPOSITORY https://github.com/texus/TGUI/
	GIT_TAG v1.12.0
	GIT_SHALLOW TRUE
)
#---using imgui for this project?---

FetchContent_MakeAvailable(sfml)
set(TGUI_BACKEND "SFML_GRAPHICS")
set(SFML_DIR ${SFML_SOURCE_DIR})
FetchContent_MakeAvailable(tgui)

#link with EXE
target_include_directories(${GAME_EXE} PRIVATE "include/")
target_link_libraries(${GAME_EXE} PRIVATE sfml-graphics sfml-window sfml-audio sfml-system TGUI::TGUI)
target_precompile_headers(${GAME_EXE} PRIVATE "include/PCH.hpp")

target_compile_definitions(${GAME_EXE} PRIVATE 
$<$<CONFIG:Debug>:__DEBUG>
$<$<CONFIG:Release>:__RELEASE>)

target_compile_definitions(${GAME_EXE} PRIVATE SFML_STATIC TGUI_STATIC)


add_subdirectory(src)