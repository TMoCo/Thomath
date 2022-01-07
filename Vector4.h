/*
* AUTHOR: THOMAS MOENO COOPER
* LAST MODIFIED: 15/12/2021
* COPYRIGHT UNDER THE MIT LICENSE
*/

//
// Vector4 class declaration
//

#ifndef VECTOR4_H
#define VECTOR4_H 1

#include "Vector3.h"
#include <xmmintrin.h>

constexpr size_t SIZE_OF_VEC4 = 0x10;

typedef struct Vector4 {
public:
  Vector4() :_v{} {}

  Vector4(const Vector3 vec3, float w = 1.0f) : _v{ vec3[0], vec3[1], vec3[2], w } {}

  Vector4(float X, float Y, float Z, float W = 1.0f) : _v{ X, Y, Z, W } {}

  Vector4(const float* values) : _v{ values[0], values[1], values[2], values[3]} {}

  Vector4(const Vector4& other) : _v{ other.x, other.y, other.z, other.w } {}

  Vector4(const __m128& vector) : __v{ vector } {}

  // binary operators
  Vector4& operator =(const Vector4& other);

  bool operator ==(const Vector4& other) const;

  Vector4& operator +=(const Vector4& other);

  Vector4& operator -=(const Vector4& other);

  Vector4& operator /=(const Vector4& other);

  Vector4& operator *=(const Vector4& other);

  Vector4& operator /=(const float& other);

  Vector4& operator *=(const float& factor);

  friend inline Vector4 operator +(Vector4 lhs, const Vector4& rhs) 
  {
    return lhs += rhs;
  }

  friend inline Vector4 operator -(Vector4 lhs, const Vector4& rhs) 
  {
    return lhs -= rhs;
  }

  friend inline Vector4 operator /(Vector4 lhs, const Vector4& rhs) 
  {
    return lhs /= rhs;
  }

  friend inline Vector4 operator *(Vector4 lhs, const Vector4& rhs) 
  {
    return lhs *= rhs;
  }

  Vector4 operator -() const;

  float& operator [](const uint32_t index);

  const float& operator [](const uint32_t index) const;

  Vector3 toPoint() const;

  Vector3 toVector3() const;

  float dot(const Vector4& other) const;

  float length() const;

  Vector4 normalize() const;

  float sum() const;

private:
  union
  {
    float     _v[4];
    __m128 __v;
    struct
    {
      float x, y, z, w;
    };
  };

} Vector4;

Vector4 operator /(Vector4 lhs, const float& rhs);

Vector4 operator *(Vector4 lhs, const float& rhs);

Vector4 operator *(const float& lhs, Vector4 rhs);

std::istream& operator >> (std::istream& inStream, Vector4& vector);

std::ostream& operator << (std::ostream& outStream, const Vector4& vector);

#endif // ! VECTOR4_H
