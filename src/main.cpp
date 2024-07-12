#include "window/window.h"
#include "vertexArray/vertexArray.h"
#include "vertexBuffer/vertexBuffer.h"
#include "indexBuffer/indexBuffer.h"
#include "shader/shader.h"

const int screenWidth = 1280;
const int screenHeight = 720;
const char* title = "Maroi";

const U32 quadCount = 10;
const U32 VertexCount = quadCount*4;
const U32 IndexCount = quadCount*6;

int main() {
    Window window(screenWidth, screenHeight, title);

    VertexArray VA;

    F32 posOffset = .12f;
    V3F32 ver[VertexCount];
    for (S32 i = 0; i < quadCount; i++) {
        ver[(i*4)] = {.1f+(i*.1f), .1f, 0.0f};
        ver[(i*4)+1] = {-.1f+(i*.1f)+posOffset, .1f, 0.0f};
        ver[(i*4)+2] = {-.1f+(i*.1f)+posOffset, -.1f, 0.0f};
        ver[(i*4)+3] = {.1f+(i*.1f), -.1f, 0.0f};
    }

    V3F32 verColor[VertexCount];
    for (S32 i = 0; i < quadCount; i++) {
        verColor[(i*4)] = {1.0f, 0.0f, 0.0f};
        verColor[(i*4)+1] = {0.0f, 1.0f, 0.0f};
        verColor[(i*4)+2] = {0.0f, 0.0f, 1.0f};
        verColor[(i*4)+3] = {1.0f, 1.0f, 1.0f};
    }

    
    U16 indices[IndexCount];

    U32 offset = 0;
    for (S32 i = 0; i < IndexCount; i += 6) {
        indices[i + 0] = 0 + offset;
        indices[i + 1] = 1 + offset;
        indices[i + 2] = 2 + offset;

        indices[i + 3] = 2 + offset;
        indices[i + 4] = 3 + offset;
        indices[i + 5] = 0 + offset;

        offset += 4;
    }

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
        glDrawElements(GL_TRIANGLES, IB.getCount(), GL_UNSIGNED_SHORT, (void*)0);

        glfwSwapBuffers(window.getWindow());

    } while(glfwGetKey(window.getWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(window.getWindow()));

    return 0;
}
