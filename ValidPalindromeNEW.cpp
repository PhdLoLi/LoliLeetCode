#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

      if(s.empty() == true)
        return true;

      transform(s.begin(), s.end(), s.begin(), ::toupper);

      string::iterator begin = s.begin();
      string::iterator end = s.end() - 1;

      while(begin < end)
      {
        while(begin < end && !isAlpha(*begin)) begin ++;
        while(begin < end && !isAlpha(*end)) end --;

        if(begin >= end)
          return true;

        if(*begin != *end)
          return false;

        begin ++;
        end --;
      }
      return true; 
    }

    bool isAlpha(char c)
    {
      if (c >= '0' && c <= '9')
        return true; //Number
      else if (c >= 'A' && c <= 'Z')
        return true; //UpperCase
      else 
        return false;
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
