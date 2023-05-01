#include <bits/stdc++.h>

using namespace std;

template <typename Type>
class Vector{
private:
    Type* arr;
    int size_{};
    int capacity_{};
public:
    Vector() {
        this-> size_ = 0;
        this-> capacity_ = 2;
        this-> arr = new Type[this-> size_];
    }

    int get_size(){
        return this-> size_;
    }

    int capacity() {
        return this-> capacity_;
    }

    Type get(int i){
        if (i < 0 || i >= (this-> size_)){
            cout <<  "\nStack Overflow. You are stupid :)";
            exit(1);
        }
        return this-> arr[i];
    }

    void addMemory() {
        this-> capacity_ *= 2;
        Type tmp[this-> capacity_];
        for (size_t i = 0; i < size_; i++)
            tmp[i] = arr[i];
        this-> arr = tmp;
        delete[] tmp;
    }

    void add(Type data){
        if (this-> size_ >= this-> capacity_) addMemory();
        arr[this-> size_ ++] = data;
    }

    Type pop(){
        int head = this-> size_ - 1;
        Type el = this-> arr[head];
        this-> size_ --;
        head --;
        int cap = this-> capacity_;
        if (head < cap / 4){
            Type tmp[cap / 2];
            for (int i = 0; i < cap / 2; i++){
                tmp[i] = this-> arr[i];
            }
            this-> arr = tmp;
            this-> capacity_ /= 2;
        }
        return el;
    }

    ~Vector() {
        delete[] arr;
    }
};

int main() {
    Vector<int> v;
    v.add(3);
    v.add(4);
    assert(v.get(0) == 3);
    assert(v.get(1) == 4);
    v.add(5);
    assert(v.get(2) == 5);
    v.add(6);
    assert(v.get(3) == 6);
    assert(v.get_size() == 4);
    assert(v.pop() == 6);
    assert(v.pop() == 5);
    assert(v.pop() == 4);
    assert(v.pop() == 3);
    assert(v.get_size() == 0);
    v.add(3);
    v.add(4);
    assert(v.get(0) == 3);
    assert(v.get(1) == 4);
}

