//
// Created by thiagomattos on 11/23/20.
//

#include <glad.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Shader.h"

unsigned int CompileShader(Shader::ShaderSource source){
    unsigned int id = glCreateShader(GL_SHADER_TYPES[(int) source.type]);
    const char* _src = source.source.c_str();
    glShaderSource(id, 1, &_src, nullptr);
    glCompileShader(id);
    return id;
}


Shader::Shader(const std::string& path) {
    std::ifstream s(path);
    std::string l;
    std::stringstream ss;
    ShaderType type = ShaderType::NONE;

    while(getline(s, l)){
        if(l.find("#shader") != std::string::npos){
            l.erase(0,8);
            if(type != ShaderType::NONE){
                sources[(int) type].source = ss.str();
                std::stringstream tmp;
                ss.swap(tmp);
            }
            type = TYPE_MAP.at(l);
            sources[(int) type].type = type;
        } else {
            ss << l << '\n';
        }
    }
    sources[(int) type].source = ss.str();
}

unsigned int Shader::create() {
    unsigned  int program = glCreateProgram();
    int shadersLenght = sizeof(Shader::sources)/sizeof(ShaderSource);
    unsigned int shaders[shadersLenght];
    for (int i = 0; i < shadersLenght; i++) {
        if(sources[i].type != ShaderType::NONE){
            shaders[i] = CompileShader(sources[i]);
            glAttachShader(program, shaders[i]);
        }
    }
    glLinkProgram(program);
    glValidateProgram(program);
    for (int i = 0; i < shadersLenght; ++i) {
        if(sources[i].type != ShaderType::NONE){
            glDeleteShader(shaders[i]);
        }
    }
    return program;
}