#include <iostream>
#include <zengine/myengine.h>

using namespace zengine;

int main()
{
    std::shared_ptr<Core> core = Core::initialize();

    // Player entity
    std::shared_ptr<Entity> cat = core->addEntity();
    cat->addComponent<Player>();
    cat->addComponent<RigidBody>();
    std::shared_ptr<BoxCollider> cbc = cat->addComponent<BoxCollider>();
    cbc->setSize(glm::vec3(1, 1, 1));
    std::shared_ptr<Renderer> renderer = cat->addComponent<Renderer>();
    renderer->setModel(core->getResources()->load<Model>("../assets/curuthers/curuthers.obj"));
    renderer->setTexture(core->getResources()->load<Texture>("../assets/curuthers/Whiskers_diffuse.png"));
    cat->getTransform()->setPosition(glm::vec3(0, -1, -20));
	cat->getTransform()->setRotation(glm::vec3(0, 0, 0));
    std::shared_ptr<Audio> catAudio = cat->addComponent<Audio>();
    catAudio->playSound("../assets/sounds/upbeat.ogg", true);

    // GUI for player entity
    std::shared_ptr<GUI> catGUI = cat->addComponent<GUI>();
    catGUI->addElement(GUIElement(glm::vec2(-1, 0.8f), glm::vec2(0.6f, 0.25f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), "PlayerScore"));

    // Skull entity
    std::shared_ptr<Entity> skull = core->addEntity();
    std::shared_ptr<Renderer> renderer2 = skull->addComponent<Renderer>();
    std::shared_ptr<BoxCollider> sbc = skull->addComponent<BoxCollider>();
    sbc->setSize(glm::vec3(1, 1, 1));
    skull->addComponent<RigidBody>();
    renderer2->setModel(core->getResources()->load<Model>("../assets/skull/12140_Skull_v3_L2.obj"));
    renderer2->setTexture(core->getResources()->load<Texture>("../assets/skull/Skull.jpg"));
    skull->getTransform()->setPosition(glm::vec3(5, 0, -20));
    skull->getTransform()->setScale(glm::vec3(0.1, 0.1, 0.1));
    skull->getTransform()->setRotation(glm::vec3(5, 0, 0));
    skull->addComponent<Audio>();

    core->start();

    return 0;
}
