#include <array>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int main(){

    // Sequence containers
    std::vector<int> vec1 = {1,2,3,4,5};
    vec1.pop_back();
    vec1.push_back(1);
    vec1.emplace(vec1.begin() ,4);
    vec1.emplace_back(6);

    for (const auto&i : vec1){
        std::cout<< i << " ";
    }
    std::cout<<'\n';
    std::cout<<"is container empty? " <<vec1.empty() <<'\n';

    // HOW TO PUSH FRONT?
    std::deque<int> deq1 = {2,3,4,5};
    deq1.push_front(1);  //deck 增加了 push_front 和 pop_front 方法

    for (const auto&i : deq1){
        std::cout<< i << " ";
    }
    std::cout<<'\n';

    // Associative containers

    std::set<int> set1 = {1,5,3,4,5};

    for (const auto&i : set1){
        std::cout<< i << " ";
    }
    std::cout<<'\n';

    std::map<std::string, int> staff = {{"tom", 32}, {"jerry", 28}};
    staff.insert({"susan", 21});
    staff["jeff"] = 23;


    int tom_age = staff["tom"];

    std::cout <<"the age of tom is " <<tom_age << '\n';
    std::cout <<"the age of susan is " <<staff["susan"] << '\n';

    staff.erase("susan");
    if (staff.find("susan") != staff.end()){
        std::cout <<"the age of susan is " <<staff["susan"] << '\n';
    }
    else {
        std::cout<< "susan is not a staff." <<'\n';
    }

    for (const auto&kv: staff){
        std::cout<< kv.first << " is " << kv.second <<'\n';
    }

    std::unordered_map<std::string, int> enginner = {{"issac", 65}};

    std::unordered_set<int> set2 = {1,2,3,4};

    // std::priority_queue<int> que2 = {3,2,10,1,9};

    std::array<int, 6> arr1 = {3,2,1,4,5,2};


    return 0;
}
