#include "Player.h"

using namespace godot;

//
//void Player::_register_methods()
//{
//	KinematicEntity::_register_methods();
//}

void Player::_init()
{
	KinematicEntity::_init();

	shooter = new Shooter("res://Scenes/Projectile.tscn");	
}

void Player::_ready()
{
	KinematicEntity::_ready();

	rootNode = get_owner();
}

void Player::_process(float delta)
{
	HandleInput();

	KinematicEntity::_process(delta);

	if (rootNode != nullptr && shooter != nullptr)
	{
		shooter->Process(*rootNode, get_position(), delta);
	}

	/*Size2 viewportSize = get_viewport_rect().size;
	Vector2 currentPosition = get_position();
	if (currentPosition.y >= viewportSize.y)
	{
		set_position(Vector2(currentPosition.y, viewportSize.y));
	}*/
}

void Player::HandleInput()
{
	motion = Vector2(0, 0);

	Input* input = Input::get_singleton();

	if (input->is_action_pressed("ui_left"))
	{
		motion.x -= SPEED;
	}
	if (input->is_action_pressed("ui_right"))
	{
		motion.x += SPEED;
	}
	if (input->is_action_pressed("ui_up"))
	{
		motion.y -= SPEED;
	}
	if (input->is_action_pressed("ui_down"))
	{
		motion.y += SPEED;
	}

	SetMotion(motion);
}

Player::Player()
{
	
}

Player::~Player()
{
}
