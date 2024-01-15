#include "Envioment.h"

Envioment::Envioment()
{
    

    for (int i = 0; i < 20; i++)
    {
        heights[i] = GetRandomValue(1, 12);
        positions[i] = Vector3{ (float)GetRandomValue(-15, 15), heights[i] / 2.0f, (float)GetRandomValue(-15, 15) };
        colors[i] = Color{ (unsigned char)GetRandomValue(20, 255), (unsigned char)GetRandomValue(10, 55), 30, 255 };
    }


}

Envioment::~Envioment()
{
}



void Envioment::DrawGround()
{
    DrawPlane(Vector3 { 0.0f, 0.0f, 0.0f }, Vector2 { 32.0f, 32.0f }, LIGHTGRAY);
    
    DrawCube(Vector3 { -16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, BLUE); 
    DrawCube(Vector3 { 16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, LIME); 
    DrawCube(Vector3 { 0.0f, 2.5f, 16.0f }, 32.0f, 5.0f, 1.0f, GOLD);

    for (int i = 0; i < 20; i++)
    {
        DrawCube(positions[i], 2.0f, heights[i], 2.0f, colors[i]);
        DrawCubeWires(positions[i], 2.0f, heights[i], 2.0f, MAROON);
    }
}
