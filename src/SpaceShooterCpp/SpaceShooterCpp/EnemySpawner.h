#pragma once

#include <Godot.hpp>
#include <Node2D.hpp>
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>
#include <KinematicBody2D.hpp>

#include "RandomNumberGenerator.h"

namespace godot
{
	class EnemySpawner : public Node2D
	{
		GODOT_CLASS(EnemySpawner, Node2D);

	private:
		float spawnRate = 1.25f;
		float spawnTimer = 0.0f;
		int spawnedEnemies = 0;

		ResourceLoader* loader;
		Node* root;

	public:
		static void _register_methods();
		void _init();
		void _ready();
		void _process(float delta);
	};
}
