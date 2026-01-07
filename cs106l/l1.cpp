
#include <iostream>
#include <map>
#include <pthread.h>
#include <string>
#include <utility>

int main(){
  std::pair<std::string, int>  dozen{"Eggs", 12};
  std::cout<< dozen.first <<": " << dozen.second << '\n';

  std::pair<double, double> pt1{1.2, 4.2};

  return 0;
}
