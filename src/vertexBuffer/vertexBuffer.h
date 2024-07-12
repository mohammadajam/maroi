#pragma once

#include "../base.h"

class VertexBuffer {
    public:
        VertexBuffer(const void* data, U32 size);
        ~VertexBuffer();

        void bind() const;
        void unbind() const;

    private:
        U32 VertexBufferID;
};
