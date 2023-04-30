#include <bits/stdc++.h>

using namespace std;

//template <typename Type>
class Heap{
public:
    Heap()
    {
        h.reserve(SIZE);
        h.push_back("0");
    }

    void add(string data)
    {
        h.push_back(data);
        heapify_up(h.size() - 1);
    }

    string get_min()
    {
        string mini = h[1];
        h[1] = h[h.size() - 1];
        h.pop_back();
        heapify_down(1);
        return mini;
    }
private:
    static const int SIZE = 100;
    vector<string> h;

    int parent(int i) { return i/2; }
    void heapify_down(int i)
    {
        while (i < h.size()-1){
            int i_min = h[i*2] > h[i*2 + 1] ? i*2 + 1 : i*2; // берем мин ребенка
            if (h[i] > h[i_min]) { swap(h[i], h[i_min]); }
            i = i_min;
        }
    }
    void heapify_up(int i)
    {
        while (i > 0){
            if (h[i] < h[parent(i)]) {
                swap(h[i], h[parent(i)]);
            }
            i = parent(i);
        }
    }
};

int main(){
    Heap h;
    h.add("aa");
    h.add("bb");
    assert(h.get_min() == "aa");
    h.add("cc");
    assert(h.get_min() == "bb");
    h.add("aa");
    assert(h.get_min() == "aa");
    //cout << ("aaa" == "bbbb");
}
