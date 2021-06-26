#include "Shooter.h"

using namespace godot;

// Should be called on every frame
void Shooter::Process(Node& root, Vector2 position, float delta)
{
	if (projPath == "" || loader == nullptr)
	{
		return;
	}

	shootTimer += delta;
	if (shootTimer >= shootInterval)
	{
		Ref<PackedScene> resource = loader->load(projPath);
		Node* proj = resource->instance();
		
		root.add_child(proj);
		KinematicBody2D* kProj = (KinematicBody2D*)proj;
		kProj->set_position(position);

		shootTimer = 0.0f;
	}
}

Shooter::Shooter(godot::String projectilePath)
{
	loader = ResourceLoader::get_singleton();

	projPath = projectilePath;
	shootTimer = 0.0f;
	shootInterval = 1.0f;
}

Shooter::~Shooter()
{
	projPath = "";
}
