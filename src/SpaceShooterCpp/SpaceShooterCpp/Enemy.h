#pragma once

#include <Godot.hpp>
#include <KinematicBody2D.hpp>

#include "Shooter.h"

namespace godot
{
	class Enemy : public KinematicBody2D
	{
		GODOT_CLASS(Enemy, KinematicBody2D);

	private:
		const int SPEED = 100;
		Vector2 motion;

		Shooter* shooter;
		Node* rootNode;

		//int health = 0;
		float lifeTime = 0.0f;

	public:
		static void _register_methods();
		void _init();
		void _ready();
		void _process(float delta);

		void TakeDamage(int damage);

		Enemy();
		~Enemy();

	};
}

