cmake_minimum_required(VERSION 3.31.6)

project(SimpleStateChanges LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add SFML from GitHub
include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        2.6.2
)
FetchContent_MakeAvailable(SFML)

# Add executable
add_executable(SimpleStateChanges
	${PROJECT_SOURCE_DIR}/main.cpp
	${PROJECT_SOURCE_DIR}/src/AssetManager.cpp  
	${PROJECT_SOURCE_DIR}/src/A_State.cpp  
	${PROJECT_SOURCE_DIR}/src/B_State.cpp  
	${PROJECT_SOURCE_DIR}/src/Game.cpp  
	${PROJECT_SOURCE_DIR}/src/InputManager.cpp  
	${PROJECT_SOURCE_DIR}/src/MainMenuState.cpp  
	${PROJECT_SOURCE_DIR}/src/SplashState.cpp  
	${PROJECT_SOURCE_DIR}/src/StateMachine.cpp

	${PROJECT_SOURCE_DIR}/include/AssetManager.hpp  
	${PROJECT_SOURCE_DIR}/include/A_State.hpp  
	${PROJECT_SOURCE_DIR}/include/B_State.hpp  
	${PROJECT_SOURCE_DIR}/include/DEFINITION.hpp  
	${PROJECT_SOURCE_DIR}/include/Game.hpp  
	${PROJECT_SOURCE_DIR}/include/InputManager.hpp  
	${PROJECT_SOURCE_DIR}/include/MainMenuState.hpp  
	${PROJECT_SOURCE_DIR}/include/SplashState.hpp  
	${PROJECT_SOURCE_DIR}/include/State.hpp  
	${PROJECT_SOURCE_DIR}/include/StateMachine.hpp

)

# Link SFML libraries
target_link_libraries(SimpleStateChanges
    PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
)

