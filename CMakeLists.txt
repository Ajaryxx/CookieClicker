cmake_minimum_required(VERSION 3.31.6)


project(CookieClicker
VERSION 0.0.1
LANGUAGES CXX)

#cmake vars
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
#we always want to compile static
set(BUILD_SHARED_LIBS OFF)

#project vars
set(CookieClicker_Exe "CookieClicker")

#download need libraries
include(FetchContent)
FetchContent_Declare(
	SFML
	GIT_REPOSITORY https://github.com/SFML/SFML
	GIT_TAG 3.0.2
	GIT_SHALLOW TRUE
)
set(TGUI_BACKEND "SFML_GRAPHICS")
FetchContent_Declare(
	TGUI
	GIT_REPOSITORY https://github.com/texus/TGUI
	GIT_TAG v1.11.0
	GIT_SHALLOW TRUE
)
FetchContent_Declare(
	ImGUI
	GIT_REPOSITORY https://github.com/ocornut/imgui
	GIT_TAG v1.91.9b
	GIT_SHALLOW TRUE
)

FetchContent_Declare(
	ImGuiSFML
	GIT_REPOSITORY https://github.com/SFML/imgui-sfml
	GIT_TAG v3.0
	GIT_SHALLOW TRUE
)
set(IMGUI_SFML_FIND_SFML OFF)
set(SFML_BUILD_NETWORK OFF)

FetchContent_MakeAvailable(SFML)
FetchContent_MakeAvailable(TGUI)
FetchContent_MakeAvailable(ImGUI)
set(IMGUI_DIR ${imgui_SOURCE_DIR})

FetchContent_MakeAvailable(ImGuiSFML)

#create exe
add_executable(${CookieClicker_Exe} "src/main.cpp")

#set target game properties
set_target_properties(${CookieClicker_Exe} PROPERTIES
CXX_STANDARD 23
CXX_STANDARD_REQUIRED ON
CXX_EXTENSIONS OFF)

target_include_directories(${CookieClicker_Exe} PRIVATE "include")
target_precompile_headers(${CookieClicker_Exe} PRIVATE "include/PCH.hpp")

target_link_libraries(${CookieClicker_Exe} PRIVATE 

SFML::Graphics
SFML::Window
SFML::System
SFML::Audio

TGUI::TGUI

ImGui-SFML::ImGui-SFML
)

#we always want to compile static
target_compile_definitions(${CookieClicker_Exe} PUBLIC SFML_STATIC TGUI_STATIC)
#set Release or Debug
target_compile_definitions(${CookieClicker_Exe} PUBLIC 
$<$<CONFIG:Debug>:GAME_DEBUG>
$<$<CONFIG:Release>:GAME_RELEASE>)

#add all subdirectories
add_subdirectory(src)

