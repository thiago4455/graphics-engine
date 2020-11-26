//
// Created by thiagomattos on 26/11/20.
//

#ifndef GRAPHICS_ENGINE_WINDOW_H
#define GRAPHICS_ENGINE_WINDOW_H
#include <GLFW/glfw3.h>


class Window {
public:
    static const int WINDOW_WIDTH = 800;
    static const int WINDOW_HEIGHT = 600;
    Window();
    void input_manager();
    void setViewport();
    bool shoudClose();
    GLFWwindow* window;
};


#endif //GRAPHICS_ENGINE_WINDOW_H
