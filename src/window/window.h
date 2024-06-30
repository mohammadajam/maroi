#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window {
    public:
        Window(const int screenWidth, const int screenHeight, const char* title);
        ~Window();

        GLFWwindow* getWindow() const;

    private:
        GLFWwindow* window;
};
