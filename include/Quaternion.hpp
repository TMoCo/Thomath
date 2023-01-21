/*
* AUTHOR: THOMAS MOENO COOPER
* LAST MODIFIED: 15/12/2021
* COPYRIGHT UNDER THE MIT LICENSE
*/

//
// Quaternion class declaration
//

#ifndef QUATERNION_H
#define QUATERNION_H 1

#include "Vector3.hpp"
#include "Vector4.hpp"

typedef struct Quaternion {
public:
  union
  {
    Vector4 _q;
    struct
    {
      Vector3 vector;
      float scalar;
    };
  };

  Quaternion(const Vector3& vector = {}, float scalar = 1.0f) : vector{ vector }, scalar{ scalar } {}

  Quaternion(const Quaternion& other) : _q{ other._q } {}

  Quaternion(float x, float y, float z, float w) : _q{ x, y, z, w } {}

  Quaternion(const float* values) : _q{ values } {}

  Quaternion(const Vector4& vector) : _q{ vector } {}

  Quaternion&operator = (const Quaternion &other);

  bool operator ==(const Quaternion& other) const;

  Quaternion& operator +=(const Quaternion& other);

  Quaternion& operator -=(const Quaternion& other);

  Quaternion& operator /=(const Quaternion& other);

  Quaternion& operator *=(const Quaternion& other);

  Quaternion& operator /=(const float& other);

  Quaternion& operator *=(const float& factor);

  friend inline Quaternion operator +(Quaternion lhs, const Quaternion& rhs) 
  {
    return lhs += rhs;
  }

  friend inline Quaternion operator -(Quaternion lhs, const Quaternion& rhs) 
  {
    return lhs -= rhs;
  }

  friend inline Quaternion operator /(Quaternion lhs, const Quaternion& rhs) 
  {
    return lhs /= rhs;
  }

  friend inline Quaternion operator *(Quaternion lhs, const Quaternion& rhs) 
  {
    return lhs *= rhs;
  }
  
  Quaternion operator -() const;

  float& operator [](const uint32_t index);

  const float& operator [](const uint32_t index) const;

  Vector3 getVector() const;

  float getScalar() const;

  float norm() const;

  Quaternion unit() const;

  Quaternion conjugate() const;

  Quaternion inverse() const;

  static Quaternion angleAxis(float angle, const Vector3& axis);

  static Quaternion eulerAngles(float pitch, float yaw, float roll);

  static Quaternion getRotationFrom(const Vector3& from, const Vector3& to);

  static Vector3 rotateVector(const Vector3& vector, const Quaternion& quaternion);

} Quaternion;

Quaternion operator /(Quaternion lhs, const float rhs);

Quaternion operator *(Quaternion lhs, const float rhs);

Quaternion operator *(const float lhs, Quaternion& rhs);

std::istream & operator >> (std::istream &inStream, Quaternion& value);

std::ostream & operator << (std::ostream &outStream, const Quaternion& value);

#endif // ! QUATERNION_H
