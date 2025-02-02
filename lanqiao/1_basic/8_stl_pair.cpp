#include<utility>
#include<iostream>
#include<vector>
#include<algorithm>


int main(){
    std::pair<int, std::string> p1(3,"Mike");
    std::cout <<p1.first<< ",  " << p1.second << " \n";
    
    //嵌套- 点云xyz, 可使用此方法
    std::pair<int, std::pair<int, int>> p2(3,std::make_pair(4,5));
    std::cout <<p2.first<< ",  " << p2.second.first<< ",  " << p2.second.second << " \n";
    
    //排序- 按照first, second 

    std::vector<std::pair<int, int>> vec;

    vec.push_back(std::make_pair(3,2));
    vec.push_back(std::make_pair(2,2));
    vec.push_back(std::make_pair(2,1));
    
    std::sort(vec.begin(), vec.end());

    for (auto &p:vec){
        std::cout << p.first << " ," << p.second << " \n";
    }
    
    return 0;
}