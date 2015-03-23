#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using std::string;
using std::map;
class Solution {
public:
    int romanToInt(string s) {
//      map<char, int> hashtable({{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}}); 
      std::unordered_map<char,int> hashtable({{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}});
      int result = 0;
      for (int i = 0; i < s.size(); i++) {
        if (i + 1 < s.size() && hashtable[s[i + 1]] > hashtable[s[i]]) 
          result -= hashtable[s[i]];
        else 
          result += hashtable[s[i]];
      }
      return result;      
    }
};

int main(int argc, char* argv[]) {
  Solution so;
  string s = "IV";
  if (argc > 1)
    s = argv[1];
  std::cout << so.romanToInt(s) << std::endl;
  return 0;
}
