/*
* AUTHOR: THOMAS MOENO COOPER
* LAST MODIFIED: 15/12/2021
* COPYRIGHT UNDER THE MIT LICENSE
*/

//
// Vector3 class definition
//

#include "Vector3.h"
#include "constants.h"
#include <math.h>

Vector3& Vector3::operator =(const Vector3& other) 
{
  x = other.x;
  y = other.y;
  z = other.z;
  return *this;
}

bool Vector3::operator ==(const Vector3& other) const 
{
  return (x == other.x) && (y == other.y) && (z == other.z);
}

Vector3& Vector3::operator +=(const Vector3& other) 
{
  x += other.x;
  y += other.y;
  z += other.z;
  return *this;
}

Vector3& Vector3::operator -=(const Vector3& other) 
{
  x -= other.x;
  y -= other.y;
  z -= other.z;
  return *this;
}

Vector3& Vector3::operator /=(const Vector3& other) 
{
  x /= other.x;
  y /= other.y;
  z /= other.z;
  return *this;
}

Vector3& Vector3::operator *=(const Vector3& other) 
{
  x *= other.x;
  y *= other.y;
  z *= other.z;
  return *this;
}

Vector3& Vector3::operator /=(const float& factor) 
{
  float inverseFactor = 1.0f / factor;
  x *= inverseFactor;
  y *= inverseFactor;
  z *= inverseFactor;
  return *this;
}

Vector3& Vector3::operator *=(const float& factor) 
{
  x *= factor;
  y *= factor;
  z *= factor;
  return *this;
}

Vector3 Vector3::operator -() const 
{
  return { -x, -y, -z };
}

float& Vector3::operator [](const uint32_t index) 
{ 
  return _v[index];
}

const float& Vector3::operator [](const uint32_t index) const 
{
  return _v[index];
}

float Vector3::dot(const Vector3& other) const 
{
  return x * other.x + y * other.y + z * other.z;
}

Vector3 Vector3::cross(const Vector3& other) const 
{
  return { y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x };
}

float Vector3::length() const 
{ 
#if (__cplusplus >= 201703L)
  return std::hypot(_v[0], _v[1], _v[2]);
#else
  return sqrtf(dot(*this));
#endif
}

float Vector3::lengthSquared() const
{
  return dot(*this);
}

Vector3 Vector3::normalize() const 
{
  return *this / length();
}

bool Vector3::isZeroVector() const
{
  return (x + y + z) < EPSILON;
}

Vector3 Vector3::reflect(const Vector3& v, const Vector3& normal) 
{
  return v - 2.0f * v.dot(normal) * normal;
}

Vector3 Vector3::refract(const Vector3& v, const Vector3& normal, const float& iorRatio)
{
  float cosTheta = fmin(normal.dot(-v), 1.0f);
  Vector3 perpendicular = iorRatio * (v + cosTheta * normal);
  Vector3 parallel = -sqrtf(fabs(1.0f - perpendicular.lengthSquared())) * normal;
  return perpendicular + parallel;
}

Vector3 operator /(Vector3 lhs, const float& rhs)
{
  return lhs /= rhs;
}

Vector3 operator /(const float lhs, Vector3& rhs)
{
  return Vector3{ lhs } / rhs;
}


Vector3 operator *(const float& lhs, Vector3 rhs)
{
  return rhs *= lhs;
}

Vector3 operator *(Vector3 lhs, const float& rhs)
{
  return lhs *= rhs;
}

std::istream& operator >> (std::istream& inStream, Vector3& vector)
{
  return inStream >> vector[0] >> vector[1] >> vector[2];
}

std::ostream& operator << (std::ostream& outStream, const Vector3& vector)
{
  return outStream << vector[0] << ' ' << vector[1] << ' ' << vector[2];
}