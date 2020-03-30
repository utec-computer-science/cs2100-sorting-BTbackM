#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

#include <iostream>
#include <ostream>
#include <vector>
#include <math.h>

using namespace std;

template <class I>
class sort_algorithms{
    private:
    vector<I>* unsorted = new vector<I>();
    public:
    sort_algorithms(vector<I>* unsorted);

    // Additional methods

    void swap(I *first, I *second);
    void merge(I left, I middle, I right);
    int partition(int low, int high);
    void build_heap(int n, int root);

    // Main methods

    void insert_sort();
    void selection_sort();
    void bubble_sort();
    void merge_sort(int left, int right);
    void quick_sort(int low,int high);
    void heap_sort();
    void shell_sort();

    virtual ~sort_algorithms(){
        unsorted->clear();
        delete unsorted;
    };
};

// Additional methods

template <class I>
ostream& operator << (ostream& os, const vector<I> & objects);

#endif //SORT_ALGORITHMS_H