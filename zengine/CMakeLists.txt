cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(MYENGINE)

include_directories(
  src
  contrib/include
)

link_directories(
  contrib/lib
)

add_library(myengine
	src/myengine/Core.h 
	src/myengine/Core.cpp
	src/myengine/myengine.h
	src/myengine/Entity.h
	src/myengine/Entity.cpp
	src/myengine/Component.h
	src/myengine/Component.cpp  
	src/myengine/TriangleRenderer.h
	src/myengine/TriangleRenderer.cpp
)

target_link_libraries(
myengine SDL2 GLEW32 OpenGL32
)

add_executable(game
 src/game/main.cpp
 src/game/Employee.h
 src/game/Employee.cpp
)

target_link_libraries(game myengine)