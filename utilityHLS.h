//
// Created by eepgmmg1 on 25/04/19.
//

#ifndef __UTILITYHLS__
#define __UTILITYHLS__

template<typename T>
struct less {
    bool operator()(const T &x, const T &y) const { return x < y; }
};

template<typename T>
struct remove_reference {
    typedef T type;
};

template<typename T>
T &&forward(typename remove_reference<T>::type &a) { return static_cast<T &&>( a ); }

template<typename T>
T &&move(T &&t) { return static_cast<typename remove_reference<T>::type &&>( t ); }

// pairHLS class
template<typename T1, typename T2>
class pairHLS {
public:
    T1 first;
    T2 second;

    pairHLS() : first(), second() {}

    pairHLS(const T1 &a, const T2 &b) : first(a), second(b) {}

    template<typename U1, typename U2>
    pairHLS(const pairHLS<U1, U2> &p) : first(p.first), second(p.second) {}

    template<typename U1>
    pairHLS(U1 &&x, const T2 &y) : first(forward<U1>(x)), second(y) {}

    pairHLS &operator=(const pairHLS &p) {
        first = p.first;
        second = p.second;
        return *this;
    }

    template<class U1, class U2>
    pairHLS &operator=(pairHLS<U1, U2> &&p) {
        first = move(p.first);
        second = move(p.second);
        return *this;
    }

    template<typename _U1, typename _Arg0, typename... _Args>
    pairHLS(_U1 &&__x, _Arg0 &&__arg0, _Args &&... __args) :
            first(forward<_U1>(__x)), second(forward<_Arg0>(__arg0), forward<_Args>(__args)...) {}

};

template<typename T1, typename T2>
inline bool operator==(const pairHLS<T1, T2> &x, const pairHLS<T1, T2> &y) {
    return x.first == y.first && x.second == y.second;
}

template<typename T1, typename T2>
inline bool operator<(const pairHLS<T1, T2> &x, const pairHLS<T1, T2> &y) {
    return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
}

template<typename T1, typename T2>
inline bool operator!=(const pairHLS<T1, T2> &x, const pairHLS<T1, T2> &y) {
    return !(x == y);
}

template<typename T1, typename T2>
inline pairHLS<T1, T2> make_pairHLS(T1 x, T2 y) {
    return pairHLS<T1, T2>(x, y);
}

// arrayHLS class
template<typename T>
class arrayHLS {
private:
    unsigned int size_;
    T data_[10];

public:
//    friend std::ostream &operator<<(std::ostream &os, const arrayHLS &other) {
//        os << other.size_ << " | ";
//        for (int i = 0; i < other.size_; i++) {
//            os << other[i] << ",";
//        }
//        return os;
//    }

    arrayHLS() : size_(0), data_{} {}

    arrayHLS(const arrayHLS &val) {
        size_ = val.size_;
        for (unsigned int i = 0; i < size_; i++) {
            data_[i] = val.data_[i];
        }
    }


    ~arrayHLS() {}

    void push_back(const T &val) {
        data_[size_] = val;
        size_++;
    }

    arrayHLS &operator=(const arrayHLS &rhs) {
        if (this != &rhs) {
            size_ = rhs.size_;
            for (unsigned int i = 0; i < size_; i++) {
                data_[i] = rhs.data_[i];
            }
        }
        return *this;
    }

    T &operator[](unsigned int i) {
        return data_[i];
    }

    const T &operator[](const unsigned int &i) const {
        return data_[i];
    }

    unsigned int size() const {
        return size_;
    }

    void clear() {
        size_ = 0;
    }

    T *begin() {
        return data_;
    }

    const T *begin() const {
        return data_;
    }

    T *end() {
        return (data_ + size_);
    }

    const T *end() const {
        return (data_ + size_);
    }

};

// mapHLS class
template<typename key, typename T>
class mapHLS {
public:
    typedef mapHLS<key, T> mty;
    typedef key key_type;
    typedef T mapped_type;
    typedef pairHLS<key_type, mapped_type> value_type;
    typedef value_type *iterator;
    typedef const value_type *const_iterator;

private:
    key_type size_;
    value_type data_[30];

public:
    mapHLS() : size_(0), data_{} {}

    ~mapHLS() {}

    mapHLS(const mty &rhs) : size_(rhs.size_), data_{} {
        int count = 0;
        for (iterator i = &rhs.data_[0]; i != &rhs.data_[rhs.size_]; ++i, ++count) {
            &data_[count] = *i;
        }
    }

    mapHLS &operator=(const value_type &rhs) {
        int count = 0;
        for (iterator i = &rhs.data_[0]; i != &rhs.data_[rhs.size_]; ++i, ++count) {
            data_[count] = i;
        }
    }

    mty &push_back(const value_type &val) {
        data_[size_].first = val.first;
        data_[size_].second = val.second;
        size_++;
        return *this;
    }

    void erase(const key_type &i) {
        iterator itr;
        for (itr = begin(); itr != end(); ++itr) {
            if (itr->first == i) {
                itr->first = 0;
            }
        }
    }

    bool hasKey(const key_type &_key) {
        const_iterator itr;
        for (itr = cbegin(); itr != cend(); ++itr) {
            if (itr->first == _key) {
                return true;
            }
        }
        return false;
    }

    mapped_type &operator[](const key_type &_Key) {
        if (hasKey(_Key)) {
            for (iterator i = begin(); i != end(); ++i) {
                if (i->first == _Key) {
                    return i->second;
                }
            }
        }
        unsigned int op = size_;
        push_back(value_type(_Key, mapped_type()));
        return data_[op].second;
    }

    void sort() {
        unsigned int i, j, temp;
        for(i=0;i<size_;i++) {
            for(j=0;j<size_;j++) {
                if(data_[i].first < data_[j].first) {
                    temp = data_[i].first;
                    data_[i].first = data_[j].first;
                    data_[j].first = temp;
                }
            }
        }
    }

    unsigned int size() const {
        return size_;
    }

    bool empty() const {
        return size_ == 0;
    }

    void clear() {
        size_ = 0;
    }

    iterator begin() {
        return &data_[0];
    }

    const_iterator cbegin() const {
        return &data_[0];
    }

    iterator end() {
        return &data_[size_];
    }

    const_iterator cend() const {
        return &data_[size_];
    }
};

#endif