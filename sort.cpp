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

template <class I>
int sort_algorithms<I>::partition(int low,int high){
    
    int iter = unsorted->at(high);
        int i = low - 1;

        for(int j = low; j <= high - 1; j++){

            if(unsorted->at(j) < iter){
                i++;
                swap(&unsorted->at(i), &unsorted->at(j));
            }
        }

        swap(&unsorted->at(i+1), &unsorted->at(high));

        return (i + 1);
}

template <class I>
void sort_algorithms<I>::build_heap(int n, int root){
    I higher = root;
    I left = 2*root + 1;
    I right = 2*root + 2;

    if(left < n and unsorted->at(left) > unsorted->at(higher))
        higher = left;
    if(right < n and unsorted->at(right) > unsorted->at(higher))
        higher =  right;
    if(higher != root){
        swap(&unsorted->at(root), &unsorted->at(higher));
        build_heap(n, higher);
    } 
}

// Main methods

template <class I>
sort_algorithms<I>::sort_algorithms(vector<I>* unsorted){
    this->unsorted = unsorted;
}

template <class I>
void sort_algorithms<I>::insert_sort(){
    for(int i = 1 ; i < int(unsorted->size()) ; i++){
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
void sort_algorithms<I>::merge_sort(int left, int right){
    if (left < right){
        I middle = left + (right - left) / 2;
        merge_sort(left, middle);
        merge_sort(middle + 1, right);

        merge(left, middle, right);
    }
}

template <class I>
void sort_algorithms<I>::quick_sort(int low,int high){
    if (low < high)
    {
        int div = partition(low, high);

        quick_sort(low, div - 1);  // Before pi
        quick_sort(div + 1, high); // After pi
    }
}

template <class I>
void sort_algorithms<I>::heap_sort(){
    for(int i = unsorted->size() / 2 - 1; i >= 0; i--)
        build_heap(unsorted->size(), i);

    for(int i = unsorted->size() - 1; i >= 0; i--) {
        swap(&unsorted->at(0), &unsorted->at(i));
        build_heap(i,0);
    } 
}

template <class I>
void sort_algorithms<I>::shell_sort(){
    int n = unsorted->size();
    for (int iter = n / 2; iter > 0; iter /= 2) {
        for (int i = iter; i < n; i += 1) {
            int tmp = unsorted->at(i);
            int j; 
            for (j = i; j >= iter && unsorted->at(j - iter) > tmp; j -= iter) 
                unsorted->at(j) = unsorted->at(j - iter);
            unsorted->at(j) = tmp;
        } 
    } 
}

template <class I>
void sort_algorithms<I>::bin_sort(){
    int n = unsorted->size();
    vector<I> tmp[n];
    for (int i = 0; i < n; i++){
        int bin = n*unsorted->at(i);
        tmp[bin].push_back(unsorted->at(i));
    }
    for (int i = 0; i < n; i++)
        sort(tmp[i].begin(), tmp[i].end());
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < tmp[i].size(); j++)
            unsorted->at(index++) = tmp[i][j];
}
