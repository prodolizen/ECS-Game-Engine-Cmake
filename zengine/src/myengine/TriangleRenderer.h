#include "Component.h"
#include "Mesh.h"
#include "Shader.h"

namespace zengine
{
	struct TriangleRenderer : Component
	{
	private:
		void onInitialise();
		void onRender();

		Shader m_shader;
		Mesh m_mesh;
	};
}

