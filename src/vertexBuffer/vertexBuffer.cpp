#include "vertexBuffer.h"

VertexBuffer::VertexBuffer(const void* data, U32 size) {
    GLAssert(glGenBuffers(1, &VertexBufferID));
    bind();
    GLAssert(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
    unbind();
}

VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &VertexBufferID);
}

void VertexBuffer::bind() const {
    GLAssert(glBindBuffer(GL_ARRAY_BUFFER, VertexBufferID));
}

void VertexBuffer::unbind() const {
    GLAssert(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
