#include "Projectile.h"
#include "KinematicEntity.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemySpawner.h"
#include "UIManager.h"

using namespace godot;

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options * o)
{
	Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options * o)
{
	Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void* handle)
{
	Godot::nativescript_init(handle);

	register_class<Projectile>();

	// Entities
	register_class<KinematicEntity>();
	register_class<Player>();
	register_class<Enemy>();

	register_class<EnemySpawner>();
	register_class<UIManager>();
}