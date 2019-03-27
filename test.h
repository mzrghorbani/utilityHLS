#ifndef __TEST__
#define __TEST__

class test {
private:
    int x;
    float y;

public:
    test();
    virtual ~test();
    void setX(int x);
    int getX() const;
    void setY(float y);
    float getY() const;
};

#endif
