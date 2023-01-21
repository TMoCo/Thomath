/*
* AUTHOR: THOMAS MOENO COOPER
* LAST MODIFIED: 15/12/2021
* COPYRIGHT UNDER THE MIT LICENSE
*/

//
// Quaternion class definition
//

#include "Quaternion.hpp"
#include "routines.hpp"

Quaternion& Quaternion::operator = (const Quaternion &other) 
{
  _q = other._q;
  return *this;
}

bool Quaternion::operator ==(const Quaternion& other) const 
{
  return _q == other._q;
}

Quaternion& Quaternion::operator +=(const Quaternion& other)
{
  _q += other._q;
  return *this;
}

Quaternion& Quaternion::operator -=(const Quaternion& other) 
{
  _q -= other._q;
  return *this;
}

Quaternion& Quaternion::operator /=(const Quaternion& other) 
{
  _q *= other.inverse()._q;
  return *this;
}

Quaternion& Quaternion::operator *=(const Quaternion& other) 
{
  float tmp = scalar;
  scalar = scalar * other.scalar - vector.dot(other.vector);
  vector = tmp * other.vector + other.scalar * vector + vector.cross(other.vector);
  return *this;
}

Quaternion& Quaternion::operator /=(const float& factor) 
{
  _q /= factor;
  return *this;
}

Quaternion& Quaternion::operator *=(const float& factor)
{
  _q *= factor;
  return *this;
}

Quaternion Quaternion::operator -() const 
{
  return  { -_q };
}

float& Quaternion::operator [](const uint32_t index) 
{
  return _q[index];
}

const float& Quaternion::operator [](const uint32_t index) const 
{
  return _q[index];
}

Vector3 Quaternion::getVector() const 
{
  return vector;
}

float Quaternion::getScalar() const 
{
  return scalar;
}

float Quaternion::norm() const 
{
  return _q.length();
}

Quaternion Quaternion::unit() const 
{
  return *this / norm();
}

Quaternion Quaternion::conjugate() const 
{
  return { -_q[0], -_q[1], -_q[2], _q[3] };
}

Quaternion Quaternion::inverse() const 
{
  return conjugate() / _q.dot(_q);
}

Quaternion Quaternion::angleAxis(float angle, const Vector3& axis)
{
  return Quaternion(axis.normalize() * sinf(angle * 0.5f), cosf(angle * 0.5f));
}

Quaternion Quaternion::eulerAngles(float pitch, float yaw, float roll)
{
  // pitch -> x rotation / yaw -> y rotation / roll -> z rotation
  float pitch2 = radians(pitch * 0.5f), yaw2 = radians(yaw * 0.5f), roll2 = radians(roll * 0.5f);
  float sinpitch = sinf(pitch2), sinyaw = sinf(yaw2), sinroll = sinf(roll2);
  float cospitch = cosf(pitch2), cosyaw = cosf(yaw2), cosroll = cosf(roll2);
  return {
  sinyaw * sinpitch * cosroll + cosyaw * cospitch * sinroll,
  sinyaw * cospitch * cosroll + cosyaw * sinpitch * sinroll,
  cosyaw * sinpitch * cosroll - sinyaw * cospitch * sinroll,
  cosyaw * cospitch * cosroll - sinyaw * sinpitch * sinroll
  };
}

Quaternion Quaternion::getRotationFrom(const Vector3& from, const Vector3& to)
{
  return Quaternion{ from.cross(to), sqrtf(from.dot(from) * to.dot(to) + from.dot(to)) }.unit();
}

Vector3 Quaternion::rotateVector(const Vector3& vector, const Quaternion& quaternion)
{
  Vector3 t = (2.0f * quaternion.vector).cross(vector);
  return vector + quaternion.scalar * t + quaternion.vector.cross(t);
}

Quaternion operator /(Quaternion lhs, const float rhs) 
{
  return lhs /= rhs;
}

Quaternion operator *(const float lhs, Quaternion& rhs) 
{
  return rhs *= lhs;
}

Quaternion operator *(Quaternion lhs, const float rhs) 
{
  return rhs * lhs;
}

std::istream& operator >> (std::istream &inStream, Quaternion &quaternion) 
{
  return inStream >> quaternion._q;
}

std::ostream & operator << (std::ostream &outStream, const Quaternion &quaternion) 
{
  return outStream << quaternion._q; 
}
