#include <iostream>
#include <string>


using namespace std;



string StringChallenge(string &str) {

    int n = str.size();
    bool capital = false, number = false, special = false;
    
    if (n < 8 || n > 30) return "false";
    

    for (int i = 0; i < n; ++i) {
      if (isupper(str[i])) capital = true;
      else if (isdigit(str[i])) number = true;
      else if (!isalnum(str[i]) && !isspace(str[i])) special = true;
    }
    return capital && number && special ? "true" : "false";


}

int main() {
  string str = "passWord123!!!!";
  cout << StringChallenge(str) << endl; 
  return 0;
}