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
  src/myengine/Audio.h
  src/myengine/Audio.cpp
  src/myengine/Model.h
  src/myengine/Model.cpp
  src/myengine/Renderer.h
  src/myengine/Renderer.cpp
  src/myengine/Resources.h
)

target_link_libraries(
	myengine rend
)

add_library(rend
  src/rend/Animation.cpp
  src/rend/Buffer.cpp
  src/rend/Debug.cpp
  src/rend/Font.cpp
  src/rend/Mesh.cpp
  src/rend/Model.cpp
  src/rend/ModelShader.cpp
  src/rend/RenderTexture.cpp
  src/rend/Shader.cpp
  src/rend/TextShader.cpp
  src/rend/Texture.cpp
  src/rend/rendmath.cpp
  src/rend/utils.cpp
)
target_link_libraries(rend SDL2 GLEW32 OpenGL32 openal32)


# Add game executable
add_executable(game
  src/game/main.cpp
)

# Link libraries to the game
target_link_libraries(game myengine)
