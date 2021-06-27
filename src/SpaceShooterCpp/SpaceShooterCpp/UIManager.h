#pragma once

#include <Godot.hpp>
#include <Control.hpp>
#include <Label.hpp>

namespace godot
{
	class UIManager : public Control
	{
		GODOT_CLASS(UIManager, Control);

	private:
		static UIManager *singleton;

		int currentPoints;
		Label* pointsLabel;

	public:
		static void _register_methods();
		void _init();
		void _ready();

		void UpdatePoints();

		UIManager();
		~UIManager();
	};
}
