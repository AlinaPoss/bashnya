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
    Type mini(){
        return min_elem;
    }
};

template <typename Type>
class Queue {
    Stack<Type> s1, s2;
public:
    bool push(Type data)
    {
        if (s1.empty_() == 1)
            s1.push(data);
        else
            s2.push(data);
        return 1;
    }
    int pop()
    {
        Type popy;
        if (s1.size_() != 0) {
            while (s1.size_() != 0){
                s2.push(s1.pop());
            }
            popy = s2.pop();
        } else
        if (s2.size_() != 0) {
            while (s2.size_() != 0){
                s1.push(s2.pop());
            }
            popy = s1.pop();
        }
        return popy;
    }
    int size_()
    {
        return s1.size_() + s2.size_();
    }

};


int main(){
    // Тесты стека
    /*
    Stack<int> m;           //ostatok:
    assert(m.push(5) == 1); // 5
    assert(m.push(4) == 1); // 5 4
    assert(m.push(3) == 1); // 5 4 3
    assert(m.size_() == 3);
    assert(m.mini() == 3);
    assert(m.pop() == 3);   // 5 4
    assert(m.size_() == 2);
    assert(m.back_() == 4);
    assert(m.pop() == 4);   // 5
    assert(m.empty_() == 0);
    assert(m.pop() == 5);   // empty
    assert(m.empty_() == 1);
    */

    //Тесты очереди
    /*
    Queue<int> q;
    assert(q.push(5) == 1);
    assert(q.push(6) == 1);
    assert(q.push(7) == 1);
    assert(q.size_() == 3);
    assert(q.pop() == 5);
    assert(q.pop() == 6);
    assert(q.size_() == 1);
    assert(q.push(8) == 1);
    assert(q.pop() == 7);
    assert(q.pop() == 8);
    assert(q.size_() == 0);
    assert(q.push(5) == 1);
    assert(q.push(6) == 1);
    assert(q.push(7) == 1);
    assert(q.size_() == 3);
    /*



}
