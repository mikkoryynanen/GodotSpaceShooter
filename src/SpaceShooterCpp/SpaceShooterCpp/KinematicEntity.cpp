#include "KinematicEntity.h"

using namespace godot;

void KinematicEntity::_register_methods()
{
	register_method((char*)"_init", &KinematicEntity::_init);
	register_method((char*)"_ready", &KinematicEntity::_ready);
	register_method((char*)"_process", &KinematicEntity::_process);
}

void KinematicEntity::_init()
{
}

void KinematicEntity::_ready()
{
	//rootNode = get_owner();
}

void KinematicEntity::_process(float delta)
{
	move_and_slide(motion);

	/*Size2 viewportSize = get_viewport_rect().size;
	Vector2 currentPosition = get_position();
	if (currentPosition.y >= viewportSize.y)
	{
		set_position(Vector2(currentPosition.y, viewportSize.y));
	}*/
}

void KinematicEntity::SetMotion(Vector2 setPostion)
{
	motion = setPostion;
}
