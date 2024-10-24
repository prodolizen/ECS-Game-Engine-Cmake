#include "TriangleRenderer.h"

namespace zengine
{
	void TriangleRenderer::onInitialise()
	{
	}
	void TriangleRenderer::onRender()
	{
		m_shader.set_mesh(m_mesh);
		m_shader.draw();
	}
}