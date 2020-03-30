#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

template <class I>
class sort_algorithms{
    private:
    vector<I>* unsorted = new vector<I>();
    public:
    sort_algorithms(vector<I>* unsorted){
        this->unsorted = unsorted;
    }

    void insert_sort();

    virtual ~sort_algorithms(){};
};

template <class I>
ostream& operator << (ostream& os, const vector<I> & objects);

#endif //SORT_ALGORITHMS_H