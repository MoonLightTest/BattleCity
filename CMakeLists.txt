cmake_minimum_required(VERSION 3.24.3 FATAL_ERROR)

set(PROJECT_NAME "BattleCity")
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME}
 /Users/moonlight/Documents/GitMyVersion/battle-city/BattleCity/src/main.cpp
 /Users/moonlight/Documents/GitMyVersion/battle-city/BattleCity/src/Renderer/ShaderProgram.cpp
 /Users/moonlight/Documents/GitMyVersion/battle-city/BattleCity/src/Renderer/ShaderProgram.h
 /Users/moonlight/Documents/GitMyVersion/battle-city/BattleCity/src/Resources/ResourceManager.cpp
 /Users/moonlight/Documents/GitMyVersion/battle-city/BattleCity/src/Resources/ResourceManager.h
 )

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} glfw)

add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} glad)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:${PROJECT_NAME}>/res)