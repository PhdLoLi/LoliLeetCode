class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int three, one = 1, two = 2;
        for(int i = 0; i < n - 2; i++) {
            three = two + one;
            one = two;
            two = three;
        }
        return three;
    }
};
int main() {}
