#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    // hash_map for unicode all
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

    // fixed 26 vector
    bool isAnagramII(string s, string t) {
        if (s.size() != t.size()) return false;
        int m[26] = {0};
        for (int i = 0; i < s.size(); ++i) ++m[s[i] - 'a'];
        for (int i = 0; i < t.size(); ++i) {
            if (--m[t[i] - 'a'] < 0) return false;
        }
        return true;
    }

    // sort version using stl of string and algorithm
    bool isAnagramIII(string s, string t) {
        if (s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t)
            return true;
        else return false;
    }
};
int main() {
}
