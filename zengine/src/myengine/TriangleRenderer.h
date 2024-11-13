#include "Component.h"
#include "Mesh.h"
#include "Shader.h"

namespace zengine
{
	struct TriangleRenderer : Component
	{
		TriangleRenderer();
		void onInitialize();

	private:		
		void onDisplay();
		Shader m_shader;
		Mesh m_mesh;
	};
}

