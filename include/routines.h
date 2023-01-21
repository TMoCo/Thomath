/*
* AUTHOR: THOMAS MOENO COOPER
* LAST MODIFIED: 15/12/2021
* COPYRIGHT UNDER THE MIT LICENSE
*/

//
// Mathematical routines
//

#ifndef ROUTINES_H
#define ROUTINES_H 1

#include "constants.h"
#include <assert.h>
#include <cmath>


constexpr inline float radians(float x)
{
  return x * PI_180;
}

template<class T>
constexpr inline T clamp(T val, T min, T max)
{
  assert(min < max);
  return (val > max ? max : val) < min ? min : val;
}

constexpr inline bool quadratic(float a, float b, float c, float* t0, float* t1)
{
  double d = (double)b * (double)b - 4.0 * (double)a * (double)c;
  
  if (d < 0.0)
  {
    return false;
  }
  
  double rootDelta = sqrt(d);
  double q = b < 0.0 ? -0.5 * ((double)b - rootDelta) : -0.5 * ((double)b + rootDelta);
  
  *t0 = (float)(q / a);
  *t1 = (float)(c / q);
  
  if (*t0 > *t1)
  {
    std::swap(*t0, *t1);
  }

  return true;
}

inline float inverseSquareRoot(float x)
{
  uint32_t *i = reinterpret_cast<uint32_t*>(&x);
  *i = 0x5F375A86 - (*i >> 1);
  return x * (1.5f - 0.5f * x * x * x);
}

constexpr inline float lerp(const float& a, const float& b, float t)
{
  return a * (1.0f - t) + b * t;
}

inline Vector3 lerp(const Vector3& a, const Vector3& b, float t)
{
  return a * (1.0f - t) + b * t;
}

#endif // !ROUTINES_H
