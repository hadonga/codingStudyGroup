// vector 动态数组容器
// push_back, pop_back, insert, erase, size, empty, 
// 迭代器， begin(), end()

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> nums;

    for (int i= 0; i < 15; ++i) {
        if (i%2) nums.push_back(15-i);
        else nums.push_back(7);
    }
    
    for (auto &n: nums){
        cout << n << " ,";
    }
    cout << endl;

    //对向量进行排序

    sort(nums.begin(), nums.end());
    for (auto n:nums){
        cout << n << ", ";
    }
    cout << endl;

    //对向量进行去重

    // auto uni = unique(nums.begin(), nums.end());
    // nums.erase(uni, nums.end());

    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    for (auto &n: nums) {

        cout << n << ", ";
    }
    cout << endl;

    nums.insert(nums.begin()+ 2, 5);
    for (auto &n: nums) {

        cout << n << ", ";
    }
    cout << endl;
     

    


    return 0;
}