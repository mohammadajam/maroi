#pragma once

#include "../base.h"

#include <stdio.h>
#include <fstream>
#include <sstream>
#include <vector>


class Shader {
    private:
        U32 ProgramID;

    public:
        Shader(const char* vertex_file_path, const char* fragment_file_path);
        ~Shader();

        void useShader();
};
