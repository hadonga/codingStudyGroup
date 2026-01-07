#include <string>
#include <iostream>
#include "l7.hpp"

//default constructor
// compiler will know to call this when no arguments are provided
StanfordID::StanfordID(){
  name = "Unknown";
  sunet = "unknown";
  idNumber = 0;
}

//parameterized constructor
StanfordID::StanfordID(std::string name, std::string sunet, int idNumber){
  this->name = name;
  this->sunet = sunet;
  if (idNumber > 0) {
    this->idNumber = idNumber;
  } else {
    this->idNumber = -1; // invalid ID
  }
}


// 在 C++ 中，this 是一个隐式的指针，指向当前对象的实例。在成员函数中，
// 它用于访问对象的成员变量或成员函数。当成员变量名与局部变量（或函数参数）名发生冲突时，
// 必须使用 this 来明确指定访问的是成员变量；否则，编译器会优先解析为局部变量，导致错误。

std::string StanfordID::getName(){
  return this->name;
}

std::string StanfordID::getSunet(){
  return this->sunet;
}

int StanfordID::getID(){
  return this->idNumber;
} 


int main(){
  StanfordID t1; // calls default constructor
  StanfordID t2("Alice Smith", "asmith", 123456); // calls
  std::string t2_name = t2.getName();
  std::string t2_sunet = t2.getSunet();
  int t2_id = t2.getID(); 

  std::cout << "T2 Name: " << t2_name << '\n';
  std::cout << "T2 Sunet: " << t2_sunet << '\n';
  std::cout << "T2 ID: " << t2_id << '\n';

  t2.~StanfordID(); // destructor call,一般不用手动调用，出作用域后会自动析构， 除非在高级场景（如 placement new)。

  std::cout << t2.getName() << '\n';  // 为什么不会报错？ 编译器不检查运行时状态，对象内存仍存在。
  
  return 0;
  // t.age =20;

}