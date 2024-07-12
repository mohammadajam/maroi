#pragma once

#include "../base.h"
#include <GLFW/glfw3.h>
#include <iostream>

class Window {
    public:
        Window(const S32 screenWidth, const S32 screenHeight, const char* title);
        ~Window();

        GLFWwindow* getWindow() const;

    private:
        GLFWwindow* window;
};
