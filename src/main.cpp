#include "window/window.h"
#include "vertexArray/vertexArray.h"


const int screenWidth = 1280;
const int screenHeight = 720;
const char* title = "Maroi";

int main() {
    Window window(screenWidth, screenHeight, title);

    VertexArray VA;

    VA.bind();

    int c = 10;


    do {
        glfwPollEvents();

    } while(glfwGetKey(window.getWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(window.getWindow()));

    return 0;
}
