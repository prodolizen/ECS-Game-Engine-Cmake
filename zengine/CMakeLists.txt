cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(MYENGINE)

add_definitions(-DSDL_MAIN_HANDLED)

include_directories(
  src
  contrib/include
  src/zenderer
)

link_directories(
  contrib/lib
)

# zenderer library
add_library(zenderer
  src/zenderer/Shader.h
  src/zenderer/Shader.cpp
  src/zenderer/Mesh.h
  src/zenderer/Mesh.cpp
)

target_link_libraries(zenderer SDL2 GLEW32 OpenGL32)

# myengine library
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

# Link zenderer to myengine
target_link_libraries(myengine zenderer SDL2 GLEW32 OpenGL32)

# Add game executable
add_executable(game
  src/game/main.cpp
  src/game/Employee.h
  src/game/Employee.cpp
)

# Link libraries to the game
target_link_libraries(game myengine zenderer)
