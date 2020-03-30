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

template <class I>
void sort_algorithms<I>::merge(I left, I middle, I right){
    I it, et, ot;
        I n = middle - left + 1;
        I m =  right - middle;
        vector<I>* L = new vector<I>(), *R = new vector<I>();
        for (it = 0; it < n; it++)
            L->push_back(unsorted->at(left+it));
        for (et = 0; et < m; et++)
            R->push_back(unsorted->at(middle + 1 + et));
        it = 0;
        et = 0;
        ot = left;
        while (it < n && et < m){
            if (L->at(it) <= R->at(et)){
                unsorted->at(ot) = L->at(it);
                it++;
            }
            else{
                unsorted->at(ot) = R->at(et);
                et++;
            }
            ot++;
        }
        while (it < n){
            unsorted->at(ot) = L->at(it);
            it++;
            ot++;
        }
        while (et < m){
            unsorted->at(ot) = R->at(et);
            et++;
            ot++;
        }
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
void sort_algorithms<I>::selection_sort(){
    for(int i = 0; i < int(unsorted->size()) - 1 ; i++){
        int it = i;
        for(int j = i + 1 ; j < unsorted->size() ; j++){
            if(unsorted->at(j) < unsorted->at(it)){
                it = j;
            }
        }
        swap(&unsorted->at(it), &unsorted->at(i));
    }
}

template<class I>
void sort_algorithms<I>::bubble_sort(){
    for (int i = 0; i < int(unsorted->size()) - 1; i++){
        for (int j = 0; j < unsorted->size() - i - 1; j++){
            if (unsorted->at(j) > unsorted->at(j + 1))
                swap(&unsorted->at(j), &unsorted->at(j + 1));
        }
    }
}

template <class I>
void sort_algorithms<I>::merge_sort(I left, I right){
    if (left < right){
        I middle = left + (right - left) / 2;
        merge_sort(left, middle);
        merge_sort(middle + 1, right);

        merge(left, middle, right);
    }
}

