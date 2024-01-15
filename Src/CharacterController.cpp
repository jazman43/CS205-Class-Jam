#include "CharacterController.h"



CharacterController::CharacterController()
{
	

	camera.position = Vector3{ 0.0f, 2.0f, 4.0f };
	camera.target = Vector3{ 0.0f, 2.0f, 0.0f };
	camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
	camera.fovy = 60.f;
	camera.projection = CAMERA_PERSPECTIVE;

	cameraMode = CAMERA_FIRST_PERSON;
}

Camera CharacterController::GetPlayerCam()
{
	return camera;
}

void CharacterController::CharacterMovement(Vector3 ground_Pos, Vector3 ground_Size)
{
	groundPos = ground_Pos;
	groundSize = ground_Size;

	/*
	if (IsKeyPressed(KEY_SPACE) && !jumping && IsGrounded()) {
		jumping = true;
	}
	*/
	
	

	UpdateCameraPro(&camera,
		Vector3{
			IsKeyDown(KEY_W)* movementSpeed - IsKeyDown(KEY_S) * movementSpeed,
			IsKeyDown(KEY_D)* movementSpeed - IsKeyDown(KEY_A) * movementSpeed,
			IsKeyPressed(KEY_SPACE) * 0.1f
		},
		Vector3{
			GetMouseDelta().x * 0.05f,
			GetMouseDelta().y * 0.05f,
			0.0f
		},
		GetMouseWheelMove() * 2.0f
	);

	/*
	if (jumping) {
		camera.position.y -= gravity;
		if (camera.position.y <= 0.0f) {
			camera.position.y = 0.0f;
			jumping = false;
		}
	}
	*/
}

void CharacterController::DrawPlayer()
{
	DrawCube(playerPosition, 0.5f, 1.0f, 0.5f, RED);
}

bool CharacterController::IsGrounded()
{
	Ray ray = {0};

	ray.position = camera.position;
	ray.direction = Vector3{ 0.0f,-1.0f,0.0f };
	

	return collision.HasCollied(ray , groundPos, groundSize);
}