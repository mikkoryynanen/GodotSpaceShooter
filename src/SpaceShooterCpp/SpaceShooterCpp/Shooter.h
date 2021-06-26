#pragma once

#include <Godot.hpp>
#include <KinematicBody2D.hpp>
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>

namespace godot
{
	class Shooter
	{
	private:
		ResourceLoader* loader;

		godot::String projPath;
		float shootTimer;
		float shootInterval;

	public:
		void Process(Node& root, Vector2 position, float delta);

		Shooter(godot::String projectilePath);
		~Shooter();
	};
}