/*
 Written by Maziar Ghorbani
*/

#ifndef __UTILITYHLS__
#define __UTILITYHLS__

// user-defined pair class
template<class T1, class T2>
class pairHLS {
public:
    T1 first;
    T2 second;

public:
    pairHLS() : first(0), second(0) {}

    pairHLS(const T1 &x, const T2 &y) {
        this->first = x;
        this->second = y;
    }

    pairHLS<T1, T2> make_pairHLS(const T1 &x, const T2 &y) {
        this->first = x;
        this->second = y;
        return *this;
    }
};

// user-defined make_pairHLS function
template<class T1, class T2>
pairHLS<T1, T2> make_pairHLS(const T1 &x, const T2 &y) {
    return (pairHLS<T1, T2>(x, y));
}

// user-defined None const iterator class
template <class T>
class iteratorHLS {
protected:
    T* current;

public:
    iteratorHLS() {}

    ~iteratorHLS() {}

    iteratorHLS(T* initLoc) : current(initLoc) {}

    bool operator!=(const iteratorHLS& rhs) const {
        return this->current != rhs.current;
    }

    iteratorHLS& operator++() {
        current++;
        return *this;
    }

    T& operator*() {
        return *current;
    }

    const T& operator*() const {
        return *current;
    }
};

// user-defined const iterator class
template <class T>
class const_iteratorHLS : public iteratorHLS<T> {
protected:
    T* current;

public:
    const int& operator*() {
        return *current;
    }
};

// user-defined vector class
template <class T>
class vectorHLS {

private:
    int size_;
    int capacity_;
    T data[10];

public:
    vectorHLS() : size_(0), capacity_(10) {}

    ~vectorHLS() {}

    vectorHLS(int capacity) : size_(0), capacity_(capacity) {}

    int size() {
        return size_;
    }

    void push_back(const T& v) {
        data[size_] = v;
        size_++;
    }

    void clear() {
        for(int i=0; i<size_; i++)
            data[i].~T();
        size_ = 0;
    }

    vectorHLS& operator=(const vectorHLS& v) {
        if(this != &v) {
            capacity_ = v.capacity_;
            size_ = v.size_;
            T data_[capacity_];
            for(int i=0; i<size_; i++)
                data_[i] = v.data_[i];
        }
        return *this;
    }

    const T& operator[](int i) const {
        return data[i];
    }

    T& operator[](int i) {
        return data[i];
    }

    const const_iteratorHLS<T> begin() const {
        return const_iteratorHLS<T>(data);
    }

    iteratorHLS<T> begin() {
        return iteratorHLS<T>(data);
    }

    const const_iteratorHLS<T> end() const {
        return const_iteratorHLS<T>(data + size_);
    }

    iteratorHLS<T> end() {
        return iteratorHLS<T>(data + size_);
    }
};

#endif
