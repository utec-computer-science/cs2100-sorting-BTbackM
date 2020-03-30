
#include <iostream>
#include <vector>
#include "sort.cpp"

using namespace std;

int main(){
    vector<char>* unsorted = new vector<char>();
    *unsorted = {'e','d','c','b','a'};
    sort_algorithms<char> test(unsorted);
    // test.insert_sort(); // Works
    // test.selection_sort(); // Works
    // test.bubble_sort(); // Works
    // test.merge_sort(0, 4); // Works
    // test.quick_sort(0, 4); //Works
    test.heap_sort(); // Works
    cout << *unsorted << endl;
    return 0;
}