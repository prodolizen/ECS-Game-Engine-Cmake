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
	//look at renderer initialise and display functions
	//potentially derive from triangleRenderer

	std::shared_ptr<Core> core = Core::initialize();

	/*std::shared_ptr<Entity> triangle = core->addEntity();
	std::shared_ptr<TriangleRenderer> tr2 = triangle->addComponent<TriangleRenderer>();*/


	std::shared_ptr<Entity> cat = core->addEntity();

	cat->addComponent<Player>();
	
	std::shared_ptr<Renderer> renderer = cat->addComponent<Renderer>();
	renderer->setModel(core->getResources()->load<Model>("../assets/curuthers/curuthers.obj"));
	//std::shared_ptr<TriangleRenderer> triangleRenderer = cat->addComponent<TriangleRenderer>();
	//triangleRenderer->setTexture(core->getResources()->load<Texture>("../assets/curuthers/Whiskers_diffuse.png"));
	renderer->setTexture(core->getResources()->load<Texture>("../assets/curuthers/Whiskers_diffuse.png"));
	cat->getTransform()->setPosition(glm::vec3(0.5f, -1, -3));
	//renderer->onInitialize();
	
	//entity->
	//entity->addComponent<TriangleRenderer>();
	
	core->start();

	return 0;
}
