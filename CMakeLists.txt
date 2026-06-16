cmake_minimum_required(VERSION 3.12)

project(dndterm)

include(FetchContent)

FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
  GIT_TAG v7.0.0  # Replace with a version, tag, or commit hash
)

FetchContent_MakeAvailable(ftxui)

add_executable(dndterm)
target_sources(dndterm
	PRIVATE
		src/main.cpp
		src/ui/ui.cpp
		src/ui/ui.h
)
target_link_libraries(dndterm
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
)



