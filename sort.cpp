#include "sort.h"

template <class I>
void sort_algorithms<I>::insert_sort(){
    for(auto i = 1 ; i < int(unsorted->size()) ; i++){
        I it = unsorted->at(i);
        int j = i - 1;
        while(j >=0 && unsorted->at(j)>it) {
            unsorted->at(j + 1) = unsorted->at(j);
            j = j - 1;

        }
        unsorted->at(j + 1) = it;
    }
}

template <class I>
ostream& operator << (ostream& os, const vector<I> & objects){
    for (const auto &object : objects){
        cout << object << " ";
    }
    return os;
}