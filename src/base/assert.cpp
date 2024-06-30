#include "../base.h"


bool GLLogCall(const char* function, const char* file, int line) {
    while (GLenum error = glGetError()) {
        std::cout << "GL ERROR :: " << error << '\n';
        std::cout << "Function: " << function << "\nFile: " << file << "\nline: " << line << '\n';
        return false;
    }
    return true;
}
