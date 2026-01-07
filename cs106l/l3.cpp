#include <iostream>
#include <map>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>

struct StanfordID {
        std::string name;
        std::string sunet;
        int idNumber;
    };

StanfordID issueNewID() {
    StanfordID id;
    id.name = "Stanford Tree";
    id.sunet = "Tree";
    id.idNumber = 2;
    return id;
}

int main(){
    std::map<std::string, std::vector<std::pair<int, std::unordered_map<char, double>>>> complexType;

    // std::map<std::string, std::vector<std::pair<int, std::unordered_map<char, double>>>>::iterator it = complexType.begin();
    auto it= complexType.begin();

    std::map<std::string, int>  ages{
        {"Alice", 24},
        {"Bob",32},
        {"Charlie", 21}
    };

    std::cout << "Alice's age:" << ages["Alice"]<<'\n';
    std::cout << "Charlie's age:" << ages.at("Charlie")<<'\n';

    std::vector<int> numbers{1,2,3,4,5};
    for (const auto &num : numbers){
        std::cout<< num << " ";
    }
    std::cout<< '\n';

    // Strucutred Binding (C++17)

    auto [name, sunet,idNumber] = issueNewID();
    std::cout << name << sunet << idNumber <<'\n';
    return 0;
}
