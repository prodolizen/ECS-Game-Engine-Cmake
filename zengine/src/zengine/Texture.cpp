#include "Texture.h"
#include "iostream"

namespace zengine {

	void Texture::onLoad()
	{
		m_texture = std::make_shared<rend::Texture>(std::string(getPath()).c_str());
	}
} 