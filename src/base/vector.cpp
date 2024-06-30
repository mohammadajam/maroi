#include "../base.h"


// Create Vectors
// S32
V2S32 v2s32(S32 x, S32 y) {
    return V2S32 {x, y};
}
V3S32 v3s32(S32 x, S32 y, S32 z) {
    return V3S32 {x, y, z};
}
V4S32 v4s32(S32 x, S32 y, S32 z, S32 w) {
    return V4S32 {x, y, z, w};
}

// F32
V2F32 v2f32(F32 x, F32 y) {
    return V2F32 {x, y};
}
V3F32 v3f32(F32 x, F32 y, F32 z) {
    return V3F32 {x, y, z};
}
V4F32 v4f32(F32 x, F32 y, F32 z, F32 w) {
    return V4F32 {x, y, z, w};
}

// Vector Operators
// S32 Operator +
V2S32 operator+(V2S32 &a, V2S32 &b) {
    return {a.x+b.x, a.y+b.y};
}
V3S32 operator+(V3S32 &a, V3S32 &b) {
    return {a.x+b.x, a.y+b.y, a.z+b.z};
}
V4S32 operator+(V4S32 &a, V4S32 &b) {
    return {a.x+b.x, a.y+b.y, a.z+b.z, a.w+b.w};
}

// S32 Operator -
V2S32 operator-(V2S32 &a, V2S32 &b) {
    return {a.x-b.x, a.y-b.y};
}
V3S32 operator-(V3S32 &a, V3S32 &b) {
    return {a.x-b.x, a.y-b.y, a.z-b.z};
}
V4S32 operator-(V4S32 &a, V4S32 &b) {
    return {a.x-b.x, a.y-b.y, a.z-b.z, a.w-b.w};
}

// S32 Operator *
V2S32 operator*(V2S32 &a, V2S32 &b) {
    return {a.x*b.x, a.y*b.y};
}
V3S32 operator*(V3S32 &a, V3S32 &b) {
    return {a.x*b.x, a.y*b.y, a.z*b.z};
}
V4S32 operator*(V4S32 &a, V4S32 &b) {
    return {a.x*b.x, a.y*b.y, a.z*b.z, a.w*b.w};
}

// F32 Operator +
V2F32 operator+(V2F32 &a, V2F32 &b) {
    return {a.x+b.x, a.y+b.y};
}
V3F32 operator+(V3F32 &a, V3F32 &b) {
    return {a.x+b.x, a.y+b.y, a.z+b.z};
}
V4F32 operator+(V4F32 &a, V4F32 &b) {
    return {a.x+b.x, a.y+b.y, a.z+b.z, a.w+b.w};
}

// F32 Operator -
V2F32 operator-(V2F32 &a, V2F32 &b) {
    return {a.x-b.x, a.y-b.y};
}
V3F32 operator-(V3F32 &a, V3F32 &b) {
    return {a.x-b.x, a.y-b.y, a.z-b.z};
}
V4F32 operator-(V4F32 &a, V4F32 &b) {
    return {a.x-b.x, a.y-b.y, a.z-b.z, a.w-b.w};
}

// F32 operator *
V2F32 operator*(V2F32 &a, V2F32 &b) {
    return {a.x*b.x, a.y*b.y};
}
V3F32 operator*(V3F32 &a, V3F32 &b) {
    return {a.x*b.x, a.y*b.y, a.z*b.z};
}
V4F32 operator*(V4F32 &a, V4F32 &b) {
    return {a.x*b.x, a.y*b.y, a.z*b.z, a.w*b.w};
}


