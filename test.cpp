#include "test.h"

test::test() {
    x = 0;
    y = 0;
}

test::~test() = default;

void test::setX(int x) {
    test::x = x;
}

void test::setY(float y) {
    test::y = y;
}

int test::getX() const {
    return x;
}

float test::getY() const {
    return y;
}
