#pragma once

#include <core/Godot.hpp>
#include <KinematicBody2D.hpp>
#include <Input.hpp>
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>
#include <SceneTree.hpp>

#include "Projectile.h"
#include "Shooter.h"
#include "KinematicEntity.h"

namespace godot
{
	class Player : public KinematicEntity
	{
		GODOT_CLASS(Player, KinematicEntity);

	private:
		const int SPEED = 300;	

		Shooter* shooter = nullptr;
		Node* rootNode = nullptr;


	public:
		//void _register_methods();
		void _init();
		void _ready();
		void _process(float delta);

		void HandleInput();

		Player();
		~Player();
	};
}