/*
* AUTHOR: THOMAS MOENO COOPER
* LAST MODIFIED: 15/12/2021
* COPYRIGHT UNDER THE MIT LICENSE
*/

//
// constants
//

#ifndef CONSTANTS_H
#define CONSTANTS_H 1

#include <cstdint>
#include <cfloat>
#include "Vector3.h"

typedef enum : uint32_t
{
  X = 0,
  Y = 1,
  Z = 2
} AXIS;

// OpenGL directions (assumes right-handed coordinate system)
constexpr Vector3 UP{ 0.0f,  1.0f,  0.0f };
constexpr Vector3 DOWN{ 0.0f, -1.0f,  0.0f };
constexpr Vector3 LEFT{ -1.0f,  0.0f,  0.0f };
constexpr Vector3 RIGHT{ 1.0f,  0.0f,  0.0f };
constexpr Vector3 FRONT{ 0.0f,  0.0f, -1.0f };
constexpr Vector3 BACK{ 0.0f,  0.0f,  1.0f };

constexpr float PI      = 3.141592653589793238463f;
constexpr float PI_TWO  = 1.570796326794896619231f;
constexpr float PI_FOUR = 0.7853981633974483096157f;
constexpr float PI_180  = 0.01745329251994329576924f;
constexpr float TWO_PI  = 6.283185307179586476925f;
constexpr float FOUR_PI = 12.56637061435917295385f;
constexpr float REC_PI = 0.3183098861837906715378f;
constexpr float REC_TWO_PI = 0.1591549430918953357689f;

constexpr float EPSILON = 0.00000001f;
constexpr float MACHINE_EPSILON = FLT_EPSILON;

#endif // !CONSTANTS_H
