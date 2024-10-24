#include <GL/glew.h>
#include <string>

struct Mesh
{
	Mesh(const std::string _path);
	GLuint getId();
	size_t getVerts();

private:
	GLuint m_id;
	std::string m_path;
	size_t m_vertices;
	bool m_dirty;
};