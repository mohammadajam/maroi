#include "indexBuffer.h"

IndexBuffer::IndexBuffer(U16 indices[], U32 size) {
    glGenBuffers(1, &IndexBufferID);
    bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, &indices[0], GL_STATIC_DRAW);
    unbind();

    count = size/sizeof(U16);
}

IndexBuffer::~IndexBuffer() {
    glDeleteBuffers(1, &IndexBufferID);
}

void IndexBuffer::bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBufferID);
}

void IndexBuffer::unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

U32 IndexBuffer::getCount() const {
    return count;
}
