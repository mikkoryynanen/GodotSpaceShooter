#pragma once

#include <core/Godot.hpp>
#include <RayCast2D.hpp>

#include "Enemy.h"
#include "UIManager.h"

namespace godot
{
	class Projectile : public KinematicBody2D
	{
		GODOT_CLASS(Projectile, KinematicBody2D)

	private:
		const int SPEED = 1500;
		RayCast2D* raycast;

		UIManager* uiManager = nullptr;

	public:
		static void _register_methods();
		void _init();
		void _ready();
		void _process(float delta);

		Projectile();
		~Projectile();
	};
}

