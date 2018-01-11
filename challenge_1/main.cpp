#include <iostream>
using namespace std;

const bool isCharInLetterRange(const char c){
    return (c >= 65 && c <= 90) || 
           (c >= 97 && c <= 122) ||
           (c >= 48 && c <= 57);
}


string LongestWord(string sen) { 

  string string_max = "";
  size_t max_length = 0;
  string current_string = "";
  size_t current_length = 0;
  for(auto& it : sen){
      if(!isCharInLetterRange(it)){
          if(current_length > max_length){
              string_max = current_string;
              max_length = current_length;
          }
          current_string = "";
          current_length = 0;
      }
      else{
          current_string += it;
          ++current_length;
      }
  }
  if(current_length > max_length)
      string_max = current_string;
  return string_max; 
            
}

int main() { 
  
  // keep this function call here
  cout << LongestWord(gets(stdin));
  return 0;
    
}