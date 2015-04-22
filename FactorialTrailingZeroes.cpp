class Solution {
public:
    int trailingZeroes(int n) {
        int times = 0;
        while (n /= 5) {
            times += n;
        }
        return times;
    }
};
int main() {
}
