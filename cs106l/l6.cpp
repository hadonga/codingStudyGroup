#include "iostream"
#include <set>
#include <vector>


struct Bibble{
    int zarf;
};

int main(){

    std::set<int> set1 = {1,3,4,2};

    for (auto it = set1.begin(); it != set1.end(); ++it){
        const auto&elem = *it;
        std::cout << elem ;
    }

    std::cout << '\n';

    std::vector<Bibble> v { {9},{8}};
    // std::vector<Bibble> v {5};
    std::cout<<"size of v is:" << v.size() << '\n';

    auto it = v.begin() +1 ;
    int m = it->zarf;
    std::cout<< "zarf is " << m << '\n';

    return 0;
}
