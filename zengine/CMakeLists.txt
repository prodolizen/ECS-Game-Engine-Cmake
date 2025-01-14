cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(zengine)

add_definitions(-DSDL_MAIN_HANDLED)

include_directories(
  src
  contrib/include
)

link_directories(
  contrib/lib
)

# zengine library
add_library(zengine
  src/zengine/Core.h 
  src/zengine/Core.cpp
  src/zengine/myengine.h
  src/zengine/Entity.h
  src/zengine/Entity.cpp
  src/zengine/Component.h
  src/zengine/Component.cpp  
  src/zengine/TriangleRenderer.h
  src/zengine/TriangleRenderer.cpp	
  src/zengine/Resource.h
  src/zengine/Resource.cpp
  src/zengine/Texture.h
  src/zengine/Texture.cpp
  src/zengine/Audio.h
  src/zengine/Audio.cpp
  src/zengine/Model.h
  src/zengine/Model.cpp
  src/zengine/Renderer.h
  src/zengine/Renderer.cpp
  src/zengine/Resources.h
  src/zengine/Transform.h
  src/zengine/Transform.cpp
  src/zengine/Input.h
  src/zengine/Input.cpp
  src/zengine/Player.h
  src/zengine/Player.cpp
  src/zengine/Collision.h
  src/zengine/Collision.cpp
  src/zengine/stb_vorbis.c
  src/zengine/Maths.h
  src/zengine/Maths.cpp
  src/zengine/GUI.h
  src/zengine/GUI.cpp
  src/zengine/Window.h
  src/zengine/Window.cpp
)

target_link_libraries(
	zengine rend
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
target_link_libraries(game zengine)

# Set startup project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT game)

