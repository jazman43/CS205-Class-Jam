#pragma once
#include "raylib.h"
#include "rcamera.h"
#include "Collisions.h"



class CharacterController
{
private:
	Collisions collision;

	Camera camera = { 0 };

	Vector3 playerPosition;
	
	float movementSpeed = 0.1f;

	int cameraMode;

	bool jumping;
	float jumpForce;
	float gravity;

	bool IsGrounded();

	Vector3 groundPos;
	Vector3 groundSize;
	
public:
	CharacterController();
	~CharacterController()
	{

	}
	Camera GetPlayerCam();

	void CharacterMovement(Vector3 ground_Pos, Vector3 ground_Size);
	
	void DrawPlayer();

	void Gravity();
};

