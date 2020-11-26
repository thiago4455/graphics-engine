//
// Created by thiagomattos on 11/23/20.
//

#ifndef PHYS_ENGINE_SHADER_H
#define PHYS_ENGINE_SHADER_H
#include <map>

class Shader {

public:
    enum struct ShaderType{
        NONE = -1,
        VERTEX = 0,
        FRAGMENT = 1,
        COMPUTE = 2,
        GEOMETRY = 3

    };

    struct ShaderSource{
        ShaderType type = ShaderType::NONE;
        std::string source;
    };

    Shader(const std::string&  path);
    unsigned int create();

    private:
        ShaderSource sources[4];
};

static const unsigned int  GL_SHADER_TYPES[4]  = { GL_VERTEX_SHADER, GL_FRAGMENT_SHADER , GL_COMPUTE_SHADER , GL_GEOMETRY_SHADER };
static const std::map<std::string, Shader::ShaderType> TYPE_MAP = {
        { "vertex", Shader::ShaderType::VERTEX },
        { "fragment", Shader::ShaderType::FRAGMENT },
        { "compute", Shader::ShaderType::COMPUTE },
        { "geometry", Shader::ShaderType::GEOMETRY },
};


#endif //PHYS_ENGINE_SHADER_H
