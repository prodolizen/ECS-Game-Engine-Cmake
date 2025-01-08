#include "Component.h"
//#include <zenderer/Mesh.h>
//#include <zenderer/Shader.h>
//#include "Texture.h"
#include <memory>
#include <rend/rend.h>

namespace zengine
{
	struct TriangleRenderer : Component
	{
		//TriangleRenderer();
		void onInitialize();

	private:		
		void onDisplay();
		//zenderer::Shader m_shader;
		//zenderer::Mesh m_mesh;
		std::shared_ptr<rend::Mesh> m_mesh;
		std::shared_ptr<rend::Shader> m_shader;
		//Texture m_texture;
	};
}

