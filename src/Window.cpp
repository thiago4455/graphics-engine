//
// Created by thiagomattos on 26/11/20.
//

#include <glad.h>
#include <iostream>
#include "Window.h"

Window::Window() {
    // Incializar e configurar o GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Criar janela do GLFW
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Graphics Engine", NULL, NULL);
    if(window == NULL){
        std::cout << "Erro ao criar janela do GLFW" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);

    // Carregar ponteiros de funções do OpenGL
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Erro ao inicializar GLAD" << std::endl;
    }
}

// Evento ao alterar tamanho da janela
void resize_framebuffer(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}
void Window::setViewport() {
    glfwSetFramebufferSizeCallback(window, resize_framebuffer);
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
}

//Gerenciar inputs
void Window::input_manager()
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

bool Window::shoudClose() {
    return glfwWindowShouldClose(window);
}