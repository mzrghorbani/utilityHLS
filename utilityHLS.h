//
// Created by eepgmmg1 on 25/04/19.
//

#ifndef __UTILITYHLS__
#define __UTILITYHLS__

template<typename T>
inline const T &minHLS(const T &a, const T &b) {
    if (b < a)
        return b;
    return a;
}

template<typename T>
inline const T &maxHLS(const T &a, const T &b) {
    if (b > a)
        return b;
    return a;
}

template<typename T>
struct remove_referenceHLS {
    typedef T type;
};

template<typename T>
struct remove_referenceHLS<T &> {
    typedef T type;
};

template<typename T>
struct remove_referenceHLS<T &&> {
    typedef T type;
};

template<typename T>
T &&forwardHLS(typename remove_referenceHLS<T>::type &a) { return static_cast<T &&>(a); }

template<class InputIt, class T>
InputIt findHLS(InputIt first, InputIt last, const T &value) {
    for (; first != last; ++first) {
        if (*first == value) {
            return first;
        }
    }
    return last;
}

template<typename T>
typename remove_referenceHLS<T>::type &&moveHLS(T &&arg) {
    return static_cast<typename remove_referenceHLS<T>::type &&>(arg);
}

template<class InputIt, class OutputIt>
OutputIt moveHLS(InputIt first, InputIt last, OutputIt itr) {
    while (first != last) {
        *itr++ = moveHLS(*first++);
    }
    return itr;
}

template<class ForwardIterator, class T>
ForwardIterator removeHLS(ForwardIterator first, ForwardIterator last, const T &value) {
    ForwardIterator result = first;
    while (first != last) {
        if (!(*first == value)) {
            *result = *first;
            ++result;
        }
        ++first;
    }
    return result;
}

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
    pairHLS(U1 &&x, const T2 &y) : first(forwardHLS<U1>(x)), second(y) {}

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

    template<typename U1, typename Arg0, typename... Args>
    pairHLS(U1 &&x, Arg0 &&arg0, Args &&... args) :
            first(forwardHLS<U1>(x)), second(forwardHLS<Arg0>(arg0), forwardHLS<Args>(args)...) {}
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
public:
    typedef T value_type;
    typedef value_type *iterator;
    typedef const value_type *const_iterator;

private:
    unsigned int size_;
    T data_[10];

public:
    arrayHLS() : size_(0) {
        unsigned int i = 0;
        for (i = 0; i < size_; ++i) {
            data_[i] = 0;
        }
    }

    ~arrayHLS() {}

    arrayHLS(unsigned int value) : size_(value) {
        unsigned int i = 0;
        for (i = 0; i < size_; ++i) {
            data_[i] = 0;
        }
    }

    void push_back(const value_type &value) {
        data_[size_] = value;
        size_++;
    }

    arrayHLS &operator=(const arrayHLS &rhs) {
        if (this != &rhs) {
            size_ = rhs.size_;
            for (unsigned int i = 0; i < size_; ++i) {
                data_[i] = rhs.data_[i];
            }
        }
        return *this;
    }

    void erase(const value_type &value) {
        for (iterator itr1 = begin(); itr1 != end(); ++itr1) {
            if (*itr1 == value) {
                for (iterator itr2 = itr1; itr2 != end(); ++itr2) {
                    *itr2 = *(itr2 + 1);
                }
            }
        }
        size_--;
    }

    void erase(iterator pos) {
        for (iterator itr1 = begin(); itr1 != end(); ++itr1) {
            if (itr1 == pos) {
                for (iterator itr2 = itr1; itr2 != end(); ++itr2) {
                    *itr2 = *(itr2 + 1);
                }
            }
        }
        size_--;
    }

    void erase(iterator pos1, iterator pos2) {
        unsigned int count = 0;
        for (iterator itr1 = begin(); itr1 != end(); ++itr1) {
            if (itr1 == pos1) {
                count = 1;
                for (iterator itr2 = itr1; itr2 != pos2; ++itr2) {
                    count++;
                }
            }
        }
        for (int i = 1; i < count; ++i) {
            erase(pos1);
        }
    }


    value_type &operator[](unsigned int idx) {
        return data_[idx];
    }

    const value_type &operator[](const unsigned int &idx) const {
        return data_[idx];
    }

    unsigned int size() const {
        return size_;
    }

    void clear() {
        size_ = 0;
    }

    bool empty() const {
        return begin() == end();
    }

    iterator begin() {
        return &data_[0];
    }

    const_iterator begin() const {
        return &data_[0];
    }

    iterator end() {
        return &data_[size_];
    }

//    (&data_[0] + size_)
    const_iterator end() const {
        return &data_[size_];
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

public:
    key_type size_;
    value_type data_[30];

public:
    mapHLS() : size_(0) {
        unsigned int i = 0;
        unsigned int j = 0;
        for (i = 0; i < 30; ++i) {
            data_[i].first = 0;
            for (j = 0; j < 10; ++j) {
                data_[j].second = 0;
            }
        }
    }

    ~mapHLS() {
        unsigned int i = 0;
        unsigned int j = 0;
        if (!empty()) {
            for (i = 0; i < size_; ++i) {
                data_[i].first = 0;
                for (j = 0; j < 10; ++j) {
                    data_[j].second = 0;
                }
            }
        }
    }

    mapHLS(const mty &rhs) : size_(rhs.size_) {
        unsigned int count = 0;
        for (iterator itr = &rhs.data_[0]; itr != &rhs.data_[rhs.size_]; ++itr, ++count) {
            &data_[count] = *itr;
        }
    }

    mapHLS &operator=(const value_type &rhs) {
        unsigned int count = 0;
        for (iterator itr = &rhs.data_[0]; itr != &rhs.data_[rhs.size_]; ++itr, ++count) {
            data_[count] = itr;
        }
    }

    mty &push_back(const value_type &value) {
        data_[size_].first = value.first;
        data_[size_].second = value.second;
        size_++;
        return *this;
    }

    void erase(const key_type &idx) {
        iterator itr;
        for (itr = begin(); itr != end(); ++itr) {
            if (itr->first == idx) {
                itr->first = 0;
                itr->second = 0;
            }
        }
    }

    bool hasKey(const key_type &idx) {
        const_iterator itr;
        for (itr = begin(); itr != end(); ++itr) {
            if (itr->first == idx) {
                return true;
            }
        }
        return false;
    }

    mapped_type &operator[](const key_type &idx) {
        if (hasKey(idx)) {
            for (iterator i = begin(); i != end(); ++i) {
                if (i->first == idx) {
                    return i->second;
                }
            }
        }
        unsigned int op = size_;
        push_back(value_type(idx, mapped_type()));
        return data_[op].second;
    }

    void sort() {
        unsigned int i, j;
        unsigned int temp;
        for (i = 0; i < size_; i++) {
            for (j = i + 1; j < size_; j++) {
                if (data_[i].first > data_[j].first) {
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
        return begin() == end();
    }

    void clear() {
        size_ = 0;
    }

    iterator begin() {
        return &data_[0];
    }

    const_iterator begin() const {
        return &data_[0];
    }

    iterator end() {
        return &data_[size_];
    }

    const_iterator end() const {
        return &data_[size_];
    }
};

#endif