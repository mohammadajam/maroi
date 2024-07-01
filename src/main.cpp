#include "window/window.h"
#include "vertexArray/vertexArray.h"
#include "vertexBuffer/vertexBuffer.h"
#include "shader/shader.h"

const int screenWidth = 1280;
const int screenHeight = 720;
const char* title = "Maroi";

int main() {
    Window window(screenWidth, screenHeight, title);

    VertexArray VA;

    V3F32 ver[3];
    ver[0] = {0.0f, 1.0f, 0.0f};
    ver[1] = {-1.0f, -1.0f, 0.0f};
    ver[2] = {1.0f, -1.0f, 0.0f};

    VertexBuffer VB(ver, sizeof(ver));

    VA.bind();
    VB.bind();

    GLAssert(glEnableVertexAttribArray(0));
    GLAssert(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0));
    
    Shader shader("shader/shader.vertex", "shader/shader.fragment");
    shader.useShader();

    do {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, ArrayCount(ver));

        glfwSwapBuffers(window.getWindow());

    } while(glfwGetKey(window.getWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(window.getWindow()));

    return 0;
}
