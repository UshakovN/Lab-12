#include "Exception.h"

BADTYPE::BADTYPE(const char* str) {
    error = str;
}

void BADTYPE::GetInfo() const {
    printf("%s", error);
    return;
}

EMPTY::EMPTY(const char* str) {
    error = str;
}

void EMPTY::GetInfo() const {
    printf("%s", error);
    return;
}
