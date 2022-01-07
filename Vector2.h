/*
* AUTHOR: THOMAS MOENO COOPER
* LAST MODIFIED: 13/12/2021
* COPYRIGHT UNDER THE MIT LICENSE
*///
// Vector2 class declaration
//

#ifndef VECTOR2_H
#define VECTOR2_H 1

#include <cstdint>
constexpr size_t SIZE_OF_VEC2 = 0x8;

typedef class Vector2 {
public:
  Vector2() : _v{} {}
  
  Vector2(float x, float y) : x(x), y(y) {}
  
  Vector2(const Vector2& other) : _v{ other.x, other.y } {}

  Vector2(const float* values) : _v{ values[0], values[1] } {}

  Vector2& operator =(const Vector2& other);

  Vector2& operator -=(const Vector2& other);

  Vector2& operator +=(const Vector2& other);

  Vector2& operator *=(const Vector2& other);
  
  Vector2& operator /=(const float& factor);

  friend inline Vector2 operator -(Vector2 lhs, const Vector2& rhs) 
  {
    return lhs -= rhs;
  }

  friend inline Vector2 operator +(Vector2 lhs, const Vector2& rhs) 
  {
    return lhs += rhs;
  }

  // access operators
  float& operator [](const uint32_t index);

  const float& operator [](const uint32_t index) const;

private:
  union
  {
    float _v[2];

    struct
    {
      float x, y;
    };
  };

} Vector2;

Vector2 operator *(Vector2 lhs, const float& rhs);

Vector2 operator /(Vector2 lhs, const float& rhs);

Vector2 operator *(const float& lhs, Vector2 rhs);



#endif // ! VECTOR2_H
