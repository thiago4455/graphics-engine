#include <iostream>
#include <glad.h>

#include "Shader.h"
#include "Window.h"

int main() {

    Window glWindow = Window();

    unsigned int shaderProgram = Shader("../res/Sample.shader").create();

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

    glWindow.setViewport();

    // Render loop
    while(!glWindow.shoudClose())
    {
        glWindow.input_manager();

        glClearColor(0.4f, 0.3f, 0.6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(glWindow.window);
        glfwPollEvents();
    }

    //Limpar recursos alocados do GLFW
    glfwTerminate();
    return 0;
}