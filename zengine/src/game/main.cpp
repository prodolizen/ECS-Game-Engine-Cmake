#include <iostream>
#include <zengine/myengine.h>

using namespace zengine;

struct Player : Component
{
	//int m_dummy;

	void onInitialize() //virtual functions?? within component
	{
		printf("Player::initialize\n");
	}

	void onTick()
	{
		printf("Player::tick\n");
	}
};

int main()
{
	std::shared_ptr<Core> core = Core::initialize();
	std::shared_ptr<Entity> cat = core->addEntity();
	cat->addComponent<Player>();
	std::shared_ptr<Renderer> renderer = cat->addComponent<Renderer>();
	renderer->setModel(core->resourceRef()->load<Model>("../assets/models/curuthers/curuthers.obj")); 
	//renderer->setTexture(core->resourceRef()->load<Texture>("../assets/textures/Whiskers_diffuse.png"));
	std::shared_ptr<TriangleRenderer> triangleRenderer = cat->addComponent<TriangleRenderer>();
	triangleRenderer->setTexture(core->resourceRef()->load<Texture>("../assets/textures/Whiskers_diffuse.png"));
	//entity->
	//entity->addComponent<TriangleRenderer>();
	
	core->start();

	return 0;
}
