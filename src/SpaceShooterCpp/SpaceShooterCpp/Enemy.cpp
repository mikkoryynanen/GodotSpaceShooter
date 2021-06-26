#include "Enemy.h"

using namespace godot;

void Enemy::_register_methods()
{
	register_method((char*)"_init", &Enemy::_init);
	register_method((char*)"_ready", &Enemy::_ready);
	register_method((char*)"_process", &Enemy::_process);
}

void Enemy::_init()
{
	shooter = new Shooter("res://Scenes/Projectile.tscn");
}

void Enemy::_ready()
{
	rootNode = get_owner();
}

void Enemy::_process(float delta)
{
	motion = Vector2(-SPEED, 0);

	move_and_slide(motion);

	//shooter->Process(*rootNode, get_position(), delta);
}

void Enemy::TakeDamage(int damage)
{
	queue_free();
}

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}
