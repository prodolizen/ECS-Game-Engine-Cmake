#include "Mesh.h"
#include <bugl.h>

namespace zenderer
{
	Mesh::Mesh(const std::string _path)
	{
		m_path = _path;
		m_id = 0;
		m_vertices = 0;
		m_dirty = false;
	}

	GLuint Mesh::getId()
	{
		if (!m_id)
		{
			m_id = buLoadModel(m_path, m_vertices);
		}

		return m_id;
	}

	size_t Mesh::getVerts()
	{
		return m_vertices;
	}
}