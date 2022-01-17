# thomath
A personal maths library I use in my computer graphics projects. 

Current features:
- Structures for representing vectors of two to four floating point values, 4x4 matrices and quaternions.
- Constants used in graphics.
- Some useful routines

Originally developed as part of my raytracer project which itself was built from university coursework, this is a code base for mathematics routines, data structures and constants I will gradually add to as needed by the graphics techniques I implement in future projects.

I also try to implement optimisations where possible such as by using SIMD intrinsics for vec4 and matrix4 operations.

Desirable features I would possibly have/like to add:
- templates for flexibitiy, allowing for vectors of integers or doubles for instance.
- Numerical integrations schemes for physics simulations.
- Curves/splines (Bézier, Catmull-Rom, etc).
- Matrix inverse
- Patches
- Error accumulation
