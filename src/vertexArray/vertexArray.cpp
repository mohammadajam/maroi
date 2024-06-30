#include "vertexArray.h"

VertexArray::VertexArray() {
    glGenVertexArrays(1, &VertexArrayID);
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &VertexArrayID);
}

void VertexArray::bind() const {
    GLAssert(glBindVertexArray(VertexArrayID));
}

void VertexArray::unbind() const {
    GLAssert(glBindVertexArray(0));
}
