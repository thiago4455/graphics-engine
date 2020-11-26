#include <iostream>
#include <glad.h>
#include <GLFW/glfw3.h>

#include "Shader.h"

void resize_framebuffer(GLFWwindow* window, int width, int height);
void input_manager(GLFWwindow *window);

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;


int main() {

    // Incializar e configurar o GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Criar janela do GLFW
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Graphics Engine", NULL, NULL);
    if(window == NULL){
        std::cout << "Erro ao criar janela do GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Carregar ponteiros de funções do OpenGL
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Erro ao inicializar GLAD" << std::endl;
        return -1;
    }

    unsigned  int shaderProgram = Shader("../res/Sample.shader").create();

    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
    };

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glfwSetFramebufferSizeCallback(window, resize_framebuffer);
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    // Render loop
    while(!glfwWindowShouldClose(window))
    {
        input_manager(window);

        glClearColor(0.4f, 0.3f, 0.6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);



        glUseProgram(shaderProgram);
        glDrawArrays(GL_TRIANGLES, 0, 3);


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //Limpar recursos alocados do GLFW
    glfwTerminate();
    return 0;
}


//Gerenciar inputs
void input_manager(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// Evento ao alterar tamanho da janela
void resize_framebuffer(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}