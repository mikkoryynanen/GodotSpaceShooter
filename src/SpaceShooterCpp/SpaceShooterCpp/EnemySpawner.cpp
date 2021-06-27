#include "EnemySpawner.h"

using namespace godot;

void EnemySpawner::_register_methods()
{
	register_method("_ready", &EnemySpawner::_ready);
	register_method("_init", &EnemySpawner::_init);
	register_method("_process", &EnemySpawner::_process);
}

void EnemySpawner::_ready()
{
	loader = ResourceLoader::get_singleton();
	root = get_owner();
}

void EnemySpawner::_init()
{
}

void EnemySpawner::_process(float delta)
{
	spawnTimer += delta;
	if (spawnTimer >= spawnRate)
	{
		Ref<PackedScene> r = loader->load("res://Scenes/Enemy.tscn");
		Node* enemy = r->instance();

		root->add_child(enemy);

		KinematicBody2D* kE = (KinematicBody2D*)enemy;
		kE->set_position(Vector2(0, RandomNumberGenerator::RandomFloat(0.0f, 500.0f)));

		float randomScale = RandomNumberGenerator::RandomFloat(3.0f, 8.0f);
		kE->set_scale(Vector2(randomScale, randomScale));

		spawnTimer = 0.0f;
		spawnedEnemies++;
	}
}