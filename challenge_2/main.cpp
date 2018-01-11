#include <iostream>
using namespace std;


const bool isCharInLetterRange(const char c){
    return (c >= 65 && c <= 90) || 
           (c >= 97 && c <= 122);
}


char increaseLetter(char c){
    if(c + 1 == 91)
      return 65;
    else if( c + 1 == 123)
      return 97;
    else return ++c;
}

bool isLetterVowel(char c){
    return c == 97  ||
           c == 101 ||
           c == 105 ||
           c == 111 ||
           c == 117;
           
}

string LetterChanges(string str) {
  string changed_str;
  for(auto& it : str){
     char inc_letter = it;
     if(isCharInLetterRange(it)){
       inc_letter = increaseLetter(it);
       if(isLetterVowel(inc_letter))
         inc_letter = inc_letter - 32;
     }
     changed_str += inc_letter;
  }
     
  return changed_str; 
            
}

int main() { 
  
  // keep this function call here
  cout << LetterChanges(gets(stdin));
  return 0;
    
}
