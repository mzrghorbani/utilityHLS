#ifndef __BOX__
#define __BOX__

class box {
private:
    int x;
    float y;

public:
    box();
    ~box();
    void setX(int x);
    int getX() const;
    void setY(float y);
    float getY() const;
};

#endif
