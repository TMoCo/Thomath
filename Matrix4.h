/*
* AUTHOR: THOMAS MOENO COOPER
* LAST MODIFIED: 15/12/2021
* COPYRIGHT UNDER THE MIT LICENSE
*/

//
// Matrix4 class declaration (Note: column major)
//

#ifndef MATRIX4_H
#define MATRIX4_H 1

#include "Vector4.h"
#include "Quaternion.h"

constexpr size_t SIZE_OF_MAT4 = 0x40;

typedef struct Matrix4 {
public:
  Matrix4();

  Matrix4(const float* values);

  Matrix4& operator =(const Matrix4& other);

  bool operator ==(const Matrix4& other) const;

  Matrix4& operator +=(const Matrix4& other);

  Matrix4& operator -=(const Matrix4& other);

  Matrix4& operator *=(const Matrix4& other);

  Matrix4& operator *=(const float& factor);

  Matrix4& operator /=(const float& other);

  friend inline Matrix4 operator *(Matrix4 lhs, const Matrix4& rhs) 
  {
    return lhs *= rhs;
  }

  friend inline Matrix4 operator +(Matrix4 lhs, const Matrix4& rhs) 
  {
      return lhs += rhs;
  }

  friend inline Matrix4 operator -(Matrix4 lhs, const Matrix4& rhs) 
  {
      return lhs -= rhs;
  }

  friend inline Vector4 operator *(Matrix4 mat, const Vector4& vec)
  {
    return
    {
     _mm_add_ps( // 7 instructions instead of 24
        _mm_add_ps(
          _mm_mul_ps(_mm_set_ps1(vec[0]), mat.__m[0]),
          _mm_mul_ps(_mm_set_ps1(vec[1]), mat.__m[1])),
        _mm_add_ps(
          _mm_mul_ps(_mm_set_ps1(vec[2]), mat.__m[2]),
          _mm_mul_ps(_mm_set_ps1(vec[3]), mat.__m[3])))
    };
  }

  float* operator [](const uint32_t index);

  const float* operator [](const uint32_t index) const;

  static Matrix4 identity();

  static Matrix4 transpose(const Matrix4& m);

  static Matrix4 translation(const Vector3& v);

  static Matrix4 rotation(const Quaternion& q);

  static Matrix4 scale(const Vector3& scale);

  static Matrix4 perspective(float FOV, float aspectRatio, float near, float far);

  static Matrix4 lookAt(const Vector3& eye, const Vector3& target, const Vector3& up);

private:
  union
  {
    float _m[16];
    __m128 __m[4];
  };

} Matrix4;

Matrix4 operator *(Matrix4 lhs, const float rhs);

Matrix4 operator *(const float lhs, Matrix4& rhs);

Matrix4 operator /(Matrix4 lhs, const float rhs);

Vector4 operator *(Matrix4 mat, const Vector4& vec);

std::istream & operator >> (std::istream &outStream, Matrix4 &matrix);

std::ostream & operator << (std::ostream &outStream, const Matrix4 &matrix);

#endif // !MATRIX4_H
