#pragma once

#include <Godot.hpp>
#include <KinematicBody2D.hpp>

namespace godot
{
	class KinematicEntity : public KinematicBody2D
	{
		GODOT_CLASS(KinematicEntity, KinematicBody2D);

	protected:
		const int SPEED = 300;
		Vector2 motion;

		Node* rootNode = nullptr;

	public:
		static void _register_methods();
		virtual void _init();
		virtual void _ready();
		virtual void _process(float delta);

		void SetMotion(Vector2 setPostion);
	};
}