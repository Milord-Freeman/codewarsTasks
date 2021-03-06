
//https://www.codewars.com/kata/roman-numerals-decoder/train/cpp
#include <iostream>
#include <string>

using namespace std;

string myReplace(string& sourceString, 
                 const string& toReplace,
                 const string& replaceWith){
    
    size_t position = sourceString.find(toReplace);
    if (position == string::npos) return sourceString;
    else return sourceString.replace(position, toReplace.length(), replaceWith);
}

int solution(string roman) {
  myReplace(roman, "IV", "IIII");
  myReplace(roman, "IX", "VIIII");
  myReplace(roman, "XL", "XXXX");
  myReplace(roman, "XC", "LXXXX");
  myReplace(roman, "CD", "CCCC");
  myReplace(roman, "CM", "DCCCC");
  
  int result = 0;
 for (auto romanChar : roman){  
    switch (romanChar){
      case 'I': result+=1; break;
      case 'V': result+=5; break;
      case 'X': result+=10; break;
      case 'L': result+=50; break;
      case 'C': result+=100; break;
      case 'D': result+=500; break;
      case 'M': result+=1000; break;
      default: result+=0; break; // WTF?!
    }
  }
  return result;
}
