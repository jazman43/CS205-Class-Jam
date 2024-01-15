#pragma once
#include "raylib.h"


class Collisions
{
private:


public:

	Collisions();

	~Collisions();

	bool HasCollied(Ray ray, Vector3 objPos , Vector3 objSize);
	bool HasCollied(Vector3 objPos, Vector3 objSize, Vector3 objPos1, Vector3 objSize1);
};

