cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(MYENGINE)

add_definitions(-DSDL_MAIN_HANDLED)

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
	src/myengine/Resource.h
	src/myengine/Resource.cpp
	src/myengine/Texture.h
	src/myengine/Texture.cpp
)

add_library(zenderer
	src/zenderer/Shader.h
	src/zenderer/Shader.cpp
	src/zenderer/Mesh.h	
	src/zenderer/Mesh.cpp
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