/*
* AUTHOR: THOMAS MOENO COOPER
* LAST MODIFIED: 13/12/2021
* COPYRIGHT UNDER THE MIT LICENSE
*/

//
// Vector2 class definition
//

#include "Vector2.h"

Vector2& Vector2::operator =(const Vector2& other) 
{
  std::memcpy(this->_v, other._v, SIZE_OF_VEC2); // 2 * sizeof(float) = 8
  return *this;
}

Vector2& Vector2::operator -=(const Vector2& other) 
{
  this->x -= other.x;
  this->y -= other.y;
  return *this;
}

Vector2& Vector2::operator +=(const Vector2& other) 
{
  this->x += other.x;
  this->y += other.y;
  return *this;
}

Vector2& Vector2::operator *=(const Vector2& other)
{
  this->x *= other.x;
  this->y *= other.y;
  return *this;
}

Vector2& Vector2::operator /=(const float& factor) 
{
  float inv = 1.0f / factor;
  this->x *= inv;
  this->y *= inv;
  return *this;
}

float& Vector2::operator [](const uint32_t index) 
{ 
  return this->_v[index]; // index greater than 1 not defined
}

const float& Vector2::operator [](const uint32_t index) const 
{
  return this->_v[index];
}

Vector2 operator *(Vector2 lhs, const float& rhs) 
{
  return Vector2{lhs[0] * rhs, lhs[1] * rhs};
}

Vector2 operator /(Vector2 lhs, const float& rhs) 
{
  return lhs /= rhs;
}

Vector2 operator *(const float& lhs, Vector2 rhs) 
{
  return Vector2{rhs[0] * lhs, rhs[1] * lhs};
}