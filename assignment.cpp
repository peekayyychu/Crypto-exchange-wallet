#include <iostream>
#include <vector>
#include <string> 

int main(){
   std::vector<std::string> strings{};
   strings.push_back("A");
   strings.push_back("B");
   strings.push_back("C");
   for (const std::string& s : strings){
      s.push_back('D');
   }
   for (std::string& s : strings){
      std::cout << s << std::endl;
   }

}
