#ifndef BASE_H
#define BASE_H

#include <GL/glew.h>
#include <iostream>
#include <signal.h>

// Assert Macros

bool GLLogCall(const char* function, const char* file, int line);

#define GLClearError() while(glGetError() != GL_NO_ERROR);

#if !defined(AssertBreak)
#define AssertBreak() raise(SIGTRAP);
#endif

#define Assert(x) if (!(x)) AssertBreak();

#define GLAssert(F) GLClearError();\
    F;\
    Assert(GLLogCall(#F, __FILE__, __LINE__));


// Helper Macros

#define ArrayCount(a) (sizeof(a)/sizeof(*(a)))

#define EvalPrint(var) std::cout << #var << " = " << var << "\n";

// Basic Data Types

#include <stdint.h>

typedef int8_t S8;
typedef int16_t S16;
typedef int32_t S32;
typedef int64_t S64;
typedef uint8_t U8;
typedef uint16_t U16;
typedef uint32_t U32;
typedef uint64_t U64;

typedef float F32;
typedef double F64;

// Vectors

// Int Vectors

union V2S32 {
    struct {
        S32 x;
        S32 y;
    };
    S32 v[2];
};

union V3S32 {
    struct {
        S32 x;
        S32 y;
        S32 z;
    };
    S32 V[3];
};

union V4S32 {
    struct {
        S32 x;
        S32 y;
        S32 z;
        S32 w;
    };
    S32 v[4];
};

// Float Vectors

union V2F32 {
    struct {
        F32 x;
        F32 y;
    };
    F32 v[2];
};

union V3F32 {
    struct {
        F32 x;
        F32 y;
        F32 z;
    };
    F32 v[3];
};

union V4F32 {
    struct {
        F32 x;
        F32 y;
        F32 z;
        F32 w;
    };
    F32 v[4];
};

// Create Vectors

static V2S32 v2s32(S32 x, S32 y);
static V3S32 v3s32(S32 x, S32 y, S32 z);
static V4S32 v4s32(S32 x, S32 y, S32 z, S32 w);

static V2F32 v2f32(F32 x, F32 y);
static V3F32 v3f32(F32 x, F32 y, F32 z);
static V4F32 v4f32(F32 x, F32 y, F32 z, F32 w);

// Vector Operators

// S32
static V2S32 operator+(V2S32 &a, V2S32 &b);
static V3S32 operator+(V3S32 &a, V3S32 &b);
static V4S32 operator+(V4S32 &a, V4S32 &b);

static V2S32 operator-(V2S32 &a, V2S32 &b);
static V3S32 operator-(V3S32 &a, V3S32 &b);
static V4S32 operator-(V4S32 &a, V4S32 &b);

static V2S32 operator*(V2S32 &a, V2S32 &b);
static V3S32 operator*(V3S32 &a, V3S32 &b);
static V4S32 operator*(V4S32 &a, V4S32 &b);

// F32
static V2F32 operator+(V2F32 &a, V2F32 &b);
static V3F32 operator+(V3F32 &a, V3F32 &b);
static V4F32 operator+(V4F32 &a, V4F32 &b);

static V2F32 operator-(V2F32 &a, V2F32 &b);
static V3F32 operator-(V3F32 &a, V3F32 &b);
static V4F32 operator-(V4F32 &a, V4F32 &b);

static V2F32 operator*(V2F32 &a, V2F32 &b);
static V3F32 operator*(V3F32 &a, V3F32 &b);
static V4F32 operator*(V4F32 &a, V4F32 &b);

// Matrix

//typedef S32 MatI4[4][4];
//typedef F32 MatF4[4][4];

typedef union {
    struct {
        S32 x1y1,x2y1,x3y1,x4y1;
        S32 x1y2,x2y2,x3y2,x4y2;
        S32 x1y3,x2y3,x3y3,x4y3;
        S32 x1y4,x2y4,x3y4,x4y4;
    };
    S32 mat[4][4];
} MatI4;

typedef struct {
    struct {
        F32 x1y1,x2y1,x3y1,x4y1;
        F32 x1y2,x2y2,x3y2,x4y2;
        F32 x1y3,x2y3,x3y3,x4y3;
        F32 x1y4,x2y4,x3y4,x4y4;
    };
    F32 mat[4][4];
} MatF4;

static MatI4 operator+(MatI4 &a, MatI4 &b);
static MatI4 operator-(MatI4 &a, MatI4 &b);
static MatI4 operator*(MatI4 &a, MatI4 &b);

static MatF4 operator+(MatF4 &a, MatF4 &b);
static MatF4 operator-(MatF4 &a, MatF4 &b);
static MatF4 operator*(MatF4 &a, MatF4 &b);

#endif
