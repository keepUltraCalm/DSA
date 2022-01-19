#include <bits/stdc++.h>
using namespace std;

struct minHeap {
    int cap;
    int size;
    int *arr;
    minHeap(int x) {
        cap = x;
        size = 0;
        arr = new int[x];
    }
    int left(int i) {
        return 2 * i + 1;
    }
    int right(int i) {
        return 2 * i + 2;
    }
    int parent(int i) {
        return (i-1) / 2;
    }
    void arrange(int i) {
        while (i != 0 && arr[i] < arr[parent(i)]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    void insert(int i) {
        if (cap == size) {
            cout << "Heap already full";
            return;
        }
        size++;
        arr[size - 1] = i;
        arrange(size - 1);
    }
    //doesn't remove element
    int get_min() {
        return arr[0];
    }
    //pass the index of the node which you think is violating heap..others are correct
    void min_heapify(int i) {
        int smallest = i;
        while (smallest < size) {
            int lt = left(smallest);
            int rt = right(smallest);
            if (lt < size && arr[lt] < arr[smallest])
                smallest = lt;
            if (rt < size && arr[rt] < arr[smallest])
                smallest = rt;
            if (smallest != i)
                swap(arr[i], arr[smallest]);
            i = smallest;
        }
    }
    int extract_min() {
        if (size == 0) {
            cout << "Heap Empty";
            return -1;
        }
        if (size == 1) {
            size--;
            return arr[0];
        }
        swap(arr[0], arr[size - 1]);
        size--;
        min_heapify(0);
        return arr[size];
        //because of size--
    }
    void replace_key(int i, int x) {
        arr[i] = x;
        arrange(i);
    }
    void delete_key(int i) {
        replace_key(i, INT_MIN);
        int z = extract_min();
        return;
    }
    //clearly upper bounded by nlogn
    void buildHeap(){
        int s = parent(size-1);
        for(int i=s; i>=0; i--)
            min_heapify(i);
    }
    //doing from down to up because every operation we did..
    //we assumed down that...i... everything is correct
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif

    minHeap *hh = new minHeap(5);

    return 0;
    //floor and normal division gives same result
}
