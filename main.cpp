
#include <iostream>
#include <vector>
#include "sort.cpp"

using namespace std;

int main(){
    vector<int>* unsorted = new vector<int>();
    *unsorted = {5,4,3,2,1};
    sort_algorithms<int> test(unsorted);
    test.insert_sort();
    cout << *unsorted << endl;
    return 0;
}