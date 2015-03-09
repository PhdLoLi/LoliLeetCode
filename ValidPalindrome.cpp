#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

      if(s.empty() == true)
        return true;

      string::iterator begin = s.begin();
      string::iterator end = s.end() - 1;
      int typeB = 0;
      int typeE = 0;

      while(begin < end)
      {
        do
        {
          typeB = charType(*begin);
          if (typeB == 0)
          {
            begin ++;
            if (begin >= end)
              return true;
          }
        }while(typeB == 0);
//        std::cout << "Now begin: " << *begin << " typeB: " << typeB << std::endl;

        do
        {
          typeE = charType(*end);
          if (typeE == 0)
          {
            end --;
            if (begin >= end)
              return true;
          }
        }while(typeE == 0);
//        std::cout << "Now end: " << *end << " typeE: " << typeE << std::endl;

//        if(toupper(*begin) != toupper(*end))
//        {
//          return false;
//        }

        if(typeB == typeE)
        {
          if (*begin != *end)
            return false;
        }else if (typeB == 2 && typeE == 3)
        {
           if ((*begin + 32) != *end)
            return false;
        }else if (typeB == 3 && typeE == 2)
        {
           if ((*begin - 32) != *end)
            return false;
        }else 
          return false;

        begin ++;
        end --;
      }
      return true; 
    }

    int charType(char c)
    {
      if (c >= '0' && c <= '9')
        return 1; //Number
      else if (c >= 'A' && c <= 'Z')
        return 2; //UpperCase
      else if (c >= 'a' && c <= 'z')
        return 3; //Lowercase
      else 
        return 0;
    }
};

int main(int argc, char * argv[])
{
  string s;
  if (argc > 1)
    s = argv[1];
  else
    s = "A man, a plan, a canal: Panama";
  Solution solu;
  std::cout << solu.isPalindrome(s) << std::endl; 
}
