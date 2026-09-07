cmake_minimum_required(VERSION 3.12)
project(dndterm)

include(FetchContent)

FetchContent_Declare(ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
    GIT_TAG v7.0.1  # Replace with a version, tag, or commit hash
)

FetchContent_Declare(json
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG v3.12.0
)

FetchContent_MakeAvailable(ftxui)
FetchContent_MakeAvailable(json)

add_executable(dndterm)
target_sources(dndterm
	PRIVATE
		src/main.cpp
        src/ui/ui.cpp
        src/util/dice.cpp
)
target_link_libraries(dndterm
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component
        PRIVATE nlohmann_json::nlohmann_json
)