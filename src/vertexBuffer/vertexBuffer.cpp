#include "vertexBuffer.h"

VertexBuffer::VertexBuffer(const void* data) {
    glGenBuffers(1, &VertexBufferID);
    bind();
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
    unbind();
}

VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &VertexBufferID);
}

void VertexBuffer::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, VertexBufferID);
}

void VertexBuffer::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
