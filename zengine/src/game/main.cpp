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
	entity->addComponent<TriangleRenderer>();

	core->start();

	return 0;
}
