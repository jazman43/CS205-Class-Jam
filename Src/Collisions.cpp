#include "Collisions.h"

Collisions::Collisions()
{
}

Collisions::~Collisions()
{
}



bool Collisions::HasCollied(Ray ray, Vector3 objPos , Vector3 objSize)
{
    BoundingBox objBox = { 0 };
    objBox.min.x = objPos.x - objSize.x / 2;
    objBox.min.y = objPos.y - objSize.y / 2;
    objBox.min.z = objPos.z - objSize.z / 2;

    objBox.max.x = objPos.x + objSize.x / 2;
    objBox.max.y = objPos.y + objSize.y / 2;
    objBox.max.z = objPos.z + objSize.z / 2;
    

    RayCollision rayhit = GetRayCollisionBox(ray, objBox);
    

    return rayhit.hit;
}

bool Collisions::HasCollied(Vector3 objPos, Vector3 objSize, Vector3 objPos1, Vector3 objSize1)
{
    BoundingBox objBox = { 0 };
    objBox.min.x = objPos.x - objSize.x / 2;
    objBox.min.y = objPos.y - objSize.y / 2;
    objBox.min.z = objPos.z - objSize.z / 2;

    objBox.max.x = objPos.x + objSize.x / 2;
    objBox.max.y = objPos.y + objSize.y / 2;
    objBox.max.z = objPos.z + objSize.z / 2;

    BoundingBox objBox1 = { 0 };
    objBox.min.x = objPos1.x - objSize1.x / 2;
    objBox.min.y = objPos1.y - objSize1.y / 2;
    objBox.min.z = objPos1.z - objSize1.z / 2;

    objBox.max.x = objPos1.x + objSize1.x / 2;
    objBox.max.y = objPos1.y + objSize1.y / 2;
    objBox.max.z = objPos1.z + objSize1.z / 2;

    

    return CheckCollisionBoxes(objBox, objBox1);
}
