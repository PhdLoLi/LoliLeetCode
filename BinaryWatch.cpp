#include <vector>
#include <iostream> 
#include <bitset>
using namespace std;

class Solution {
public:
    vector<string> res;
    bitset<6> m;
    bitset<4> h;
    void bkWatch(int cnt, int pos) {
        if (m.to_ulong() > 59 || h.to_ulong() > 11 || (pos > 9 && cnt != 0)) return;
        if (cnt == 0) {
            string s;
            s.append(to_string(h.to_ulong()) + ":");
            int mm = m.to_ulong();
            if (mm < 10) s.push_back('0');
            s.append(to_string(mm));
            res.push_back(s);
            cout << s <<  endl;
        } else {
            bkWatch(cnt, pos + 1);
//            cout << "after cnt " << m << " " << h << endl;
            if (pos < 6) m.set(pos, 1);
            else h.set(pos - 6, 1);
            bkWatch(cnt - 1, pos + 1);
//            cout << "after cnt - 1" << m << " " << h << endl;
            if (pos < 6) m.set(pos, 0);
            else h.set(pos - 6, 0);
        }
    }
    vector<string> readBinaryWatch(int num) {
        if (num > 8) return res;
        bkWatch(num, 0);
        return res;
    }
};

int main() {
  Solution so;
  so.readBinaryWatch(2);
}
