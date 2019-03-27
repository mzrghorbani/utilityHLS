/*
 Written by Maziar Ghorbani
*/
#ifndef __LRUTILITYHLS__
#define __LRUTILITYHLS__

// user-defined pair class
template<class T1, class T2>
class pair_ {
public:
    T1 first_;
    T2 second_;

public:
    pair_() {
        first_ = 0;
        second_ = 0;
    }

    pair_(const T1 &x, const T2 &y) {
        this->first_ = x;
        this->second_ = y;
    }

    pair_<T1, T2> make_pair(const T1 &x, const T2 &y) {
        this->first = x;
        this->second = y;
        return *this;
    }
};

// user-defined make_pair function
template<class T1, class T2>
pair_<T1, T2> make_pair_(const T1 &x, const T2 &y) {
    return (pair_<T1, T2>(x, y));
}

// user-defined None const iterator class
template <class T>
class iterator_ {
protected:
    T* current;

public:
    iterator_() = default;
    explicit iterator_(T* initLoc) {
        current = initLoc;
    }

    bool operator!=(const iterator_& rhs) const {
        return this->current != rhs.current;
    }

    iterator_& operator++() {
        current++;
        return *this;
    }

    virtual T& operator*() {
        return *current;
    }

    const T& operator*() const {
        return *current;
    }
};

// user-defined const iterator class
template <class T>
class ReadOnlyIterator_ : public iterator_<T> {
protected:
    T* current;

public:
    const int& operator*() {
        return *current;
    }
};

// user-defined vector class
template <class T>
class vector_ {

private:
    int vsize_;
    int maxSize_;
    T data_[10];

public:
    vector_() {
        maxSize_ = 0;
        vsize_ = 0;
    }

    explicit vector_(int i) {
        maxSize_ = i;
        vsize_ = 0;
    }

    int size() {
        return vsize_;
    }

    void push_back(const T& i) {
        if(vsize_+1 > maxSize_) {
            expand();
        }
        data_[vsize_] = i;
        vsize_++;
    }

    vector_& operator=(const vector_& v) {
        if(this != &v) {
            maxSize_ = v.maxSize_;
            vsize_ = v.vsize_;
            T data_[maxSize_];
            for(int i=0; i<vsize_; i++)
                data_[i] = v.data_[i];
        }
        return *this;
    }

    void expand() {
        maxSize_ = vsize_ * 2;
        T temp[maxSize_];
        for(int i=0; i<vsize_; i++)
            temp[i] = data_[i];
        data_[0] = temp[0];
    }

    const T& operator[](int i) const {
        return data_[i];
    }

    T& operator[](int i) {
        return data_[i];
    }

    const ReadOnlyIterator_<T> begin() const {
        return ReadOnlyIterator_<T>(data_);
    }

    iterator_<T> begin() {
        return iterator_<T>(data_);
    }

    const ReadOnlyIterator_<T> end() const {
        return ReadOnlyIterator_<T>(data_ + vsize_);
    }

    iterator_<T> end() {
        return iterator_<T>(data_ + vsize_);
    }

//    const T* begin() const {
//        return data_;
//    }
//    const T* end() const {
//        return data_ + vsize_;
//    }

    ~vector_() = default;

};

#endif
