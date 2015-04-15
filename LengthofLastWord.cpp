#include <string>
using std::string;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int counter = 0;
        int i = s.size() - 1;
        while (i >= 0 && s[i] == ' ') i--;
        for (; i >= 0 && s[i] != ' '; i--) counter++;
        return counter;
    }
};
int main() {
}
