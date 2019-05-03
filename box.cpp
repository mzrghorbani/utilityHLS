#include "box.h"

box::box() {
    x = 0;
    y = 0;
}

box::~box() = default;

void box::setX(int x) {
    box::x = x;
}

void box::setY(float y) {
    box::y = y;
}

int box::getX() const {
    return x;
}

float box::getY() const {
    return y;
}

box::box(const box &b) {
    box::x = b.x;
    box::y = b.y;
}
