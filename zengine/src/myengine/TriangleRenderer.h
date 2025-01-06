#include "Component.h"
#include <zenderer/Mesh.h>
#include <zenderer/Shader.h>
#include "Texture.h"

namespace zengine
{
	struct TriangleRenderer : Component
	{
		TriangleRenderer();
		void onInitialize();

	private:		
		void onDisplay();
		zenderer::Shader m_shader;
		zenderer::Mesh m_mesh;
		//Texture m_texture;
	};
}

