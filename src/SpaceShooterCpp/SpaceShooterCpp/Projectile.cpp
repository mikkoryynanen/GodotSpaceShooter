#include "Projectile.h"

using namespace godot;

void Projectile::_register_methods()
{
	register_method((char*)"_init", &Projectile::_init);
	register_method((char*)"_ready", &Projectile::_ready);
	register_method((char*)"_process", &Projectile::_process);
}

void Projectile::_init()
{
	/*const godot::String gsRaycast = "RayCast2D";
	Node* n;
	godot::Array a = get_children();
	int64_t childCount = get_child_count();
	for (int64_t i = 0; i < childCount; i++)
	{
		n = get_child(i);
		if (gsRaycast == n->get_name())
		{
			raycast = (RayCast2D*)n;
		}
	}*/
	
}

void Projectile::_ready()
{
	raycast = (RayCast2D*)get_node("RayCast2D");
	raycast->add_exception(this);

	uiManager = (UIManager*)get_node("root/main/Player/Camera2D/UI");
}

void Projectile::_process(float delta)
{
	Vector2 direction = Vector2(0, 0);
	direction.x += SPEED;
	move_and_slide(direction);

	if (raycast->is_colliding())
	{
		Enemy* e = (Enemy*)raycast->get_collider();		
		if (e != nullptr)
		{
			e->queue_free();
		}

		if(uiManager != nullptr)
			uiManager->UpdatePoints();

		queue_free();
	}
}

godot::Projectile::Projectile()
{
}

godot::Projectile::~Projectile()
{
}
