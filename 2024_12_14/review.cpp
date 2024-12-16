#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){

    // define an array 

    vector<int> arr1d(3, 0);
    arr1d = {1,2,3};

    // define an 2d array
    vector<vector<int>> arr2d((3,3));
    arr2d ={{1,2,3},{4,5}};

    //  to iter an array
    for (auto a: arr1d){
        cout<< a<< '\n';
    }

    for (auto &b: arr2d){
        for (auto a: b) 
            cout << a << '\n';
    }

    // sort 2d array 
    vector<vector<int>> arr = {
        {1, 6, 8, 4, 3},
        {3, 4, 7, 2, 1}
    };

    vector<int> idxs(arr[0].size(), 0);
    iota(idxs.begin(), idxs.end(), 0); //从0开始填充
    sort(idxs.begin(), idxs.end(), [&](int i, int j) {
        return (arr[0][i] < arr[0][j]);
    });  //
    for (auto idx: idxs){
        cout << arr[0][idx] << ',';
    }
    cout << '\n';

    for (auto idx: idxs) {
        cout << arr[1][idx] << ',';
    }
    cout << '\n';

    return 0;
}