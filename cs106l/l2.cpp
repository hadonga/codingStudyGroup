
#include <sstream>
#include <iostream>


int string_to_interger(const std::string &input_value){
  std::istringstream iss(input_value);
  int result;
  iss >> result;
  return result;

}

int main (){

  std::cout<<"ostring_example"<<'\n';
  std::ostringstream oss("Ito-En Green Tea");
  std::cout<<oss.str()<<'\n';

  oss << "16.9 Ounces";

  std::cout<< oss.str()<<'\n';
  std::cout<<"dddd"<<'\n';

  std::cout<<"istring_example"<<'\n';
  std::istringstream iss("16.9 Ounces");
  int amount;
  std::string unit;

  iss >> amount >> unit;
  iss >> unit;

  std::cout << amount/2 <<" " << unit <<'\n';

  std::string input= "80";
  std::cout<< string_to_interger(input)<<'\n';


  return 0;
}
