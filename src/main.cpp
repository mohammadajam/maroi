#include "window/window.h"
#include "vertexArray/vertexArray.h"
#include "vertexBuffer/vertexBuffer.h"
#include "indexBuffer/indexBuffer.h"
#include "shader/shader.h"

const int screenWidth = 1280;
const int screenHeight = 720;
const char* title = "Maroi";

int main() {
    Window window(screenWidth, screenHeight, title);

    VertexArray VA;

    V3F32 ver[4];
    ver[0] = {1.0f, 1.0f, 0.0f};
    ver[1] = {-1.0f, 1.0f, 0.0f};
    ver[2] = {-1.0f, -1.0f, 0.0f};
    ver[3] = {1.0f, -1.0f, 0.0f};

    V3F32 verColor[4];
    verColor[0] = {1.0f, 0.0f, 0.0f};
    verColor[1] = {0.0f, 1.0f, 0.0f};
    verColor[2] = {0.0f, 0.0f, 1.0f};
    verColor[3] = {1.0f, 1.0f, 1.0f};

    U16 indices[] = {0, 1, 2, 2, 3, 0};

    IndexBuffer IB(indices, sizeof(indices));

    VertexBuffer VB(ver, sizeof(ver));

    VertexBuffer VBColor(verColor, sizeof(verColor));

    VA.bind();

    VB.bind();
    glEnableVertexAttribArray(0);
    GLAssert(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0));
    VB.unbind();    

    VBColor.bind();
    glEnableVertexAttribArray(1);
    GLAssert(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0));
    VBColor.unbind();

    IB.bind();

    Shader shader("shader/shader.vertex", "shader/shader.fragment");
    shader.useShader();

    do {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //glDrawArrays(GL_TRIANGLES, 0, ArrayCount(ver));
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, (void*)0);

        glfwSwapBuffers(window.getWindow());

    } while(glfwGetKey(window.getWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(window.getWindow()));

    return 0;
}
