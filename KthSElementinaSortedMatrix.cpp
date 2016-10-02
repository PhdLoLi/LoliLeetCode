#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
class Solution {
public:
//    struct Point {
//      int x; int y;
//      Point (int xx, int yy) : x(xx), y(yy) {}
//      bool operator==(const Point& a) const{
//        return (a.x == this->x && a.y == this->y);
//      }
//      Point operator+(int i) {
//        return Point(this->x + i, this->y + i);
//      }
//      Point operator-(int i) {
//        return Point(this->x - i, this->y - i);
//      }
//    };
//
//    int comSqr(Point left, Point right) {
//      if (right.x < left.x) return 0;
//      return (right.x - left.x + 1) * (right.y - left.y + 1);
//    }
//
//    int kthS(vector<vector<int>>& matrix, int k, Point left, Point right) {
//      if (left == right || k == 1) return matrix[left.x][left.y];
//      Point mid(left.x + (right.x - left.x) / 2, left.y + (right.y - left.y) / 2);
//      int LL = comSqr(left, mid - 1);
//      if (k <= LL) return kthS(matrix, k, left, mid - 1);
//      int RR = comSqr(left, right) - comSqr(mid + 1, right);
//      if (k > RR) return kthS(matrix, k - RR, mid + 1, right);
//      return min(kthS(matrix, k - LL, Point(left.x, mid.y), Point(mid.x, right.y)), kthS(matrix, k - LL, Point(mid.x, left.y), Point(right.x, mid.y)));
//    
//    }
//
//    int kthSmallest(vector<vector<int>>& matrix, int k) {
//      return kthS(matrix, k, Point(0, 0), Point(matrix.size() - 1, matrix.size() - 1));    
//    }

  // binary search 
  int kthSmallestBS(vector<vector<int>>& matrix, int k) {
    int left = matrix[0][0], right = matrix.back().back();
    while (left < right) {
      int mid = left + (right - left) / 2;
      int cnt = 0, n = matrix.size();
      for (int i = n - 1, j = 0; i >= 0 && j < n;) {
        if (matrix[i][j] <= mid) {
          cnt += i + 1;
          j++;
        }
        else i--;
      }
      if (cnt < k) left = mid + 1;
      else right = mid;
    }
    return left;    
  }

  struct Node {
    int x;
    int y;
    int val;
    Node(int xx, int yy, int v) : x(xx), y(yy), val(v) {}
    bool operator < (const Node& a) const {
      return val > a.val;
    }
  };
  // heap 
  int kthSmallestHeap(vector<vector<int>>& matrix, int k) {
    priority_queue<Node> q;
    int n = matrix.size();
    q.push(Node(0, 0, matrix[0][0]));
    while (--k > 0) {
      Node a = q.top();
      q.pop();
      if (a.x == 0 && a.y < n - 1) q.push(Node(a.x, a.y + 1, matrix[a.x][a.y + 1]));
      if (a.x < n - 1) q.push(Node(a.x + 1, a.y, matrix[a.x + 1][a.y]));

    }
    return q.top().val;   
  }


  // the idea below is wrong!!!!
  struct Int {
    int val;
    Int(int v) : val(v) {}
    bool operator < (const Int& a) const {
      return val > a.val;
    }
  };
  // heap 
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<Int> q;
    int n = matrix.size();
    q.push(Int(matrix[0][0]));
    int i = 0, j = 0;
    for (int j = 0; k-- > 1 && j < n; j++) {
      q.pop();
      if (j < n - 1) q.push(Int(matrix[0][j + 1]));
      q.push(Int(matrix[1][j]));

    }
    for (int i = 2; k > 1 && i < n; i++) {
      for (int j = 0; k-- > 1 && j < n; j++) {
        q.pop();
        q.push(Int(matrix[i][j]));
      }
    }
    return q.top().val;   
  }



  // heap 2

};
int main() {
  Solution so;
}
