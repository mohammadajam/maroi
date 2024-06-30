#include "base.h"
#include "window/window.h"
#include "vertexArray/vertexArray.h"


const int screenWidth = 1280;
const int screenHeight = 720;
const char* title = "Maroi";

int main() {
    Window window(screenWidth, screenHeight, title);

    VertexArray VA;

    VA.bind();

    MatI4 a;

    for (S32 i = 0; i < 4; i++) {
        for (S32 j = 0; j < 4; j++) {
            a.mat[i][j] = i+j;
        }
    }

    MatI4 b;

    MatI4 d = IdentityMatI4;

    for (S32 i = 0; i < 4; i++) {
        for (S32 j = 0; j < 4; j++) {
            b.mat[i][j] = (i+j)*2;
        }
    }

    a = a * b;

    //V2F32 b = v2f32(1.0f, 2.0f);

    for (S32 i = 0; i < 4; i++) {
        for (S32 j = 0; j < 4; j++) {
            std::cout << a.mat[i][j] << " ";
        }
        std::cout << "\n";
    }

    MatI4 e = a * d;

    std::cout << "\n\n";

    for (S32 i = 0; i < 4; i++) {
        for (S32 j = 0; j < 4; j++) {
            std::cout << e.mat[i][j] << " ";
        }
        std::cout << "\n";
    }

    int c = 10;
    
    do {
        glfwPollEvents();

    } while(glfwGetKey(window.getWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(window.getWindow()));

    return 0;
}
