#include "DrawingHelpers.h"

#include "GFXVideo3d.h"


// I feel guilty for this function, sorry. I couldn't figure out how to do this with DirectX :(
void rotatey(D3DXVECTOR3& vec, float radiant)
{
	float x = cos(radiant) * vec.x + sin(radiant) * vec.z;
	float y = vec.y;
	float z = -sin(radiant) * vec.x + cos(radiant) * vec.z;

	vec.x = x;
	vec.y = y;
	vec.z = z;
}
