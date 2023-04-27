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
    int sexy = 0; //
    Node<Type> *top;
public:
    Stack() { top = nullptr; }
    void push(Type data)
    {
        Node<Type> *remind = new Node<Type>(data);
        if (!remind) {
            cout <<  "\nStack Overflow. You are stupid :)";
            exit(1);
        }
        remind -> data = data;
        remind -> prev = top;
        top = remind;
        sexy ++;
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
        sexy --;
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
};


template <typename Type>
class Stack_with_min {
    Stack<Type> baze, miniki;
public:
    void push(Type data)
    {
        baze.push(data); // поместить заданный элемент в основной stack
        if (miniki.size_() == 0) {
            miniki.push(data);
        } else {
            if (data <= miniki.back_()){
                miniki.push(data);
            }
        }
    }
    Type pop()
    {
        Type top = baze.pop();
        if (top == miniki.back_()){
            miniki.pop();
        }
        return top;
    }
    Type back_()
    {
        return baze.back_();
    }
    int size_()
    {
        return baze.size_();
    }
    Type mini(){
        return miniki.back_();
    }
    bool empty_()
    {
        return baze.size_() == 0;
    }
};

template <typename Type>
class Queue {
    Stack<Type> s1, s2;
public:
    void push(Type data)
    {
        s1.push(data);
    }
    int pop()
    {
        Type popy;
        if (s2.size_() != 0)
            return s2.pop();
        else {
            while (s1.size_() != 0) {
                s2.push(s1.pop());
            }
            return s2.pop();
        }
    }
    int size_()
    {
        return s1.size_() + s2.size_();
    }
};


int main(){
    // Тесты стека
    /*
    Stack_with_min<int> m;           //ostatok:
    m.push(5);        // 5
    m.push(4); // 5 4
    m.push(3); // 5 4 3
    assert(m.size_() == 3);
    assert(m.mini() == 3);
    assert(m.pop() == 3);   // 5 4
    assert(m.size_() == 2);
    assert(m.back_() == 4);
    assert(m.pop() == 4);   // 5
    assert(m.empty_() == false);
    assert(m.pop() == 5);   // empty
    assert(m.empty_() == true);
    m.push(-2);
    assert(m.mini() == -2);
    */

    //Тесты очереди
    /*
    Queue<int> q;
    q.push(5);
    q.push(6);
    q.push(7);
    assert(q.size_() == 3);
    assert(q.pop() == 5);
    assert(q.pop() == 6);
    assert(q.size_() == 1);
    q.push(8);
    assert(q.pop() == 7);
    assert(q.pop() == 8);
    assert(q.size_() == 0);
    q.push(5);
    q.push(6);
    q.push(7);
    assert(q.size_() == 3);
    */
}
