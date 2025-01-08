#include "Texture.h"

namespace zengine {

	void Texture::onLoad()
	{
		m_texture = std::make_shared<Texture>(std::string(getPath().c_str()));
	}
}
