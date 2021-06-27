#include "UIManager.h"

using namespace godot;

void UIManager::_register_methods()
{
	register_method("_init", &UIManager::_init);
	register_method("_ready", &UIManager::_ready);
}

void UIManager::_init()
{
}

void UIManager::_ready()
{
	pointsLabel = (Label*)get_node("Points");
	pointsLabel->set_text("Points: 0");
}

void UIManager::UpdatePoints()
{
	currentPoints++;

	pointsLabel->set_text((godot::String)currentPoints);
}

UIManager::UIManager()
{
	currentPoints = 0;
}

UIManager::~UIManager()
{
}
