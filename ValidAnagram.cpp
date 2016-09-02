#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> hash_table;

        for (int i = 0; i < s.size(); i++) {
            if (hash_table.find(s[i]) == hash_table.end()) 
                hash_table[s[i]] = 1;
            else hash_table[s[i]]++;
        }
        for (int i = 0; i < t.size(); i++) {
            if (hash_table.find(t[i]) == hash_table.end())
                return false;
            else hash_table[t[i]]--;
        }
        
        for (auto it = hash_table.begin(); it != hash_table.end(); ++it) {
            if (it->second != 0) return false;
        }
        return true;
    }
};
int main() {
}
