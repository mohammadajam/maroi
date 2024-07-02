#pragma once

#include <GL/glew.h>
#include "../base.h"

class IndexBuffer {
    public:
        IndexBuffer(U16 indices[], U32 size);
        ~IndexBuffer();

        void bind() const;
        void unbind() const;

    private:
        U32 IndexBufferID;
};
