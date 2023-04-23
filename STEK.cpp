#include <bits/stdc++.h>

using namespace std;

template <typename Type>
class Node{
public:
    Type data;
    Node<Type> *prev;
    Node<Type>(Type n)
    {
        this->data = n;
        this->prev = nullptr;
    }
};

template <typename Type>
class Stack {
    int sexy = 0; // типо size :)
    int min_elem;
    Node<Type> *top;
public:
    Stack() { top = nullptr; }
    bool push(Type data)
    {
        Node<Type> *remind = new Node<Type>(data);
        if (!remind) {
            cout <<  "\nStack Overflow. You are stupid :)";
            return 0;
        }
        if (top == nullptr)
            min_elem = data;
        remind -> data = data;
        remind -> prev = top;
        top = remind;
        sexy ++;
        min_elem = min(min_elem, data);
        return 1;
    }
    bool empty_()
    {
        return top == nullptr;
    }
    Type pop()
    {
        Node<Type> *temp;
        if (top == nullptr) {
            cout <<  "\nStack Overflow. You are stupid :)";
            exit(1);
        }
        temp = top;
        Type elem = top -> data;
        top = top -> prev;
        delete temp;
        return elem;
    }
    Type back_()
    {
        if (top == nullptr) {
            cout <<  "\nStack Overflow. You are stupid :)";
            exit(1);
        }
        return top -> data;
    }
    int size_()
    {
        return sexy;
    }
    Type mini(){
        return min_elem;
    }
};


int main(){
    int n = 5;
    Stack<int> m;           //ostatok:
    assert(m.push(5) == 1); // 5
    assert(m.push(4) == 1); // 5 4
    assert(m.size_() == 2);
    assert(m.mini() == 4);
    assert(m.pop() == 4); // 5
    assert(m.back_() == 5);
    assert(m.pop() == 5); //
    assert(m.empty_() == 1);

}
