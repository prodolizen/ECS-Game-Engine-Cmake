#include "Resource.h"

struct Texture : Resource
{
	void onLoad();
private:
	std::shared_ptr<Texture> m_texture;
};