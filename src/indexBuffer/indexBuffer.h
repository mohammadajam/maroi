#pragma once

#include "../base.h"

class IndexBuffer {
    public:
        IndexBuffer(U16 indices[], U32 size);
        ~IndexBuffer();

        void bind() const;
        void unbind() const;

        U32 getCount() const;

    private:
        U32 IndexBufferID;
        U32 count;
};
