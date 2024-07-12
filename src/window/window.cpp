#include "window.h"

Window::Window(const S32 screenWidth, const S32 screenHeight, const char* title) {
    if(!glfwInit()) {
        std::cout << "ERROR: glfwInit\n";
        exit(-1);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(screenWidth, screenHeight, title, NULL, NULL);

    if (!window) {
        std::cout << "ERROR: glfwCreateWindow\n";
        exit(-1);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if(glewInit() != GLEW_OK) {
        std::cout << "ERROR: glewInit : " << stderr <<"\n";
        exit(-1);
    }
}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

GLFWwindow* Window::getWindow() const {
    return window;
}
