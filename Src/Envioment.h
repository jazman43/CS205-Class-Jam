#pragma once
#include "raylib.h"

#define MAX_COLUMNS 20;

class Envioment
{
private:
	float heights[20] = { 0 };
	Vector3 positions[20] = { 0 };
	Color colors[20] = { 0 };

public:
	Envioment();

	~Envioment();


	void DrawGround();

};

