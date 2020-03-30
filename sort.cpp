#include "sort.h"

// Additional methods

template <class I>
ostream& operator << (ostream& os, const vector<I> & objects){
    for (const auto &object : objects){
        cout << object << " ";
    }
    return os;
}

template <class I>
void sort_algorithms<I>::swap(I *first, I *second){
    I tmp = *first;
    *first = *second;
    *second = tmp;
}

// Main methods

template <class I>
sort_algorithms<I>::sort_algorithms(vector<I>* unsorted){
    this->unsorted = unsorted;
}

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

template<class I>
void sort_algorithms<I>::selection_sort() {
    for(int i = 0; i < unsorted->size() - 1 ; i++){
        int it = i;
        for(int j = i + 1 ; j < unsorted->size() ; j++){
            if(unsorted->at(j) < unsorted->at(it)){
                it = j;
            }
        }
        swap(&unsorted->at(it), &unsorted->at(i));
    }
}

