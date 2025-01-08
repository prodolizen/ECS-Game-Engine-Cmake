#include <iostream>
#include <myengine/myengine.h>

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
	std::shared_ptr<Entity> entity = core->addEntity();
	entity->addComponent<Player>();
	std::shared_ptr<Renderer> renderer = entity->addComponent<Renderer>();
	renderer->setModel(core->resourceRef()->load<Model>("../models/curuthers/curuthers.obj")); 
	//entity->
	//entity->addComponent<TriangleRenderer>();
	
	core->start();

	return 0;
}
