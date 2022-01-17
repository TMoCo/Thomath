/*
* Author: Thomas Moreno Cooper
* Date created: 17/01/2021
* Copyright 2022 under the MIT License
*/

#include "unit_tests.h"

int main(int argc, char** argv)
{
  assert(argc == 2);
  return run_test(atoi(argv[1]));
}