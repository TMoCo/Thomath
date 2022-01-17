/*
* Author: Thomas Moreno Cooper
* Date created: 17/01/2021
* Copyright 2022 under the MIT License
*/


#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H 1

#include <assert.h>
#include "../Vector3.h"
#include "../Vector2.h"
#include "../Vector4.h"
#include "../Matrix4.h"
#include "../Quaternion.h"

int testQuaternion()
{
  return 0;
}

int testMatrix4()
{
  return 0;
}

int testVector2()
{
  return 0;
}

int testVector3()
{
  return 0;
}

int testVector4()
{
  return 0;
}

int run_test(int testId)
{
  switch (testId)
  {
  case 0:
    return testVector2();
  case 1:
    return testVector3();
  case 2:
    return testVector4();
  case 3:
    return testMatrix4();
  case 4:
    return testQuaternion();
  default:
    return -1; // invalid test id
  }
}

#endif // !UNIT_TESTS_H

