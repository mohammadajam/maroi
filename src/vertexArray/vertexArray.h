#pragma once

#include "../base.h"

class VertexArray {
    public:
        VertexArray();
        ~VertexArray();

        void bind() const;
        void unbind() const;

    private:
        U32 VertexArrayID;
};
