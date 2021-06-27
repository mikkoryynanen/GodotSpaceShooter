#include "Enemy.h"
#include "UIManager.h"

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

	lifeTime += delta;
	if (lifeTime > 30)
	{
		TakeDamage(INT64_MAX);
	}
}

void Enemy::TakeDamage(int damage)
{
	queue_free();
}

Enemy::Enemy()
{
	lifeTime = 0.0f;
}

Enemy::~Enemy()
{
}
