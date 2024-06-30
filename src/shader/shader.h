#pragma once

#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>

#include <stdio.h>
#include <fstream>
#include <sstream>
#include <vector>


class Shader {
    private:
        GLuint ProgramID;

    public:


        Shader(const char * vertex_file_path,const char * fragment_file_path);
        ~Shader();

        void useShader();

        void setUniformMVP(glm::mat4 MVP);



};
