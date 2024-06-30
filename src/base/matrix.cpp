#include "../base.h"

// Matrix Operators
// MatI4
MatI4 operator+(MatI4 &a, MatI4 &b) {
    MatI4 temp;
    for (S32 i = 0; i < 4; i++) {
        for (S32 j = 0; j < 4; j++) {
            temp.mat[i][j] = a.mat[i][j] + b.mat[i][j];
        }
    }
    return temp;
}
MatI4 operator-(MatI4 &a, MatI4 &b) {
    MatI4 temp;
    for (S32 i = 0; i < 4; i++) {
        for (S32 j = 0; j < 4; j++) {
            temp.mat[i][j] = a.mat[i][j] - b.mat[i][j];
        }
    }
    return temp;
}
MatI4 operator*(MatI4 &a, MatI4 &b) {
    MatI4 mult;
    for(S32 i = 0; i < 4; i++)
        for(S32 j = 0; j < 4; j++)
            for(S32 k = 0; k < 4; k++)
            {
                mult.mat[i][j] += a.mat[i][k] * b.mat[k][j];
            }
    return mult;
}

// MatF4
MatF4 operator+(MatF4 &a, MatF4 &b) {
    MatF4 temp;
    for (S32 i = 0; i < 4; i++) {
        for (S32 j = 0; j < 4; j++) {
            temp.mat[i][j] = a.mat[i][j] + b.mat[i][j];
        }
    }
    return temp;
}
MatF4 operator-(MatF4 &a, MatF4 &b) {
    MatF4 temp;
    for (S32 i = 0; i < 4; i++) {
        for (S32 j = 0; j < 4; j++) {
            temp.mat[i][j] = a.mat[i][j] - b.mat[i][j];
        }
    }
    return temp;
}
MatF4 operator*(MatF4 &a, MatF4 &b) {
    MatF4 mult;
    for(S32 i = 0; i < 4; i++)
        for(S32 j = 0; j < 4; j++)
            for(S32 k = 0; k < 4; k++)
            {
                mult.mat[i][j] += a.mat[i][k] * b.mat[k][j];
            }
    return mult;
}
