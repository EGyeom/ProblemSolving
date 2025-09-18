#include <vector>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int n = sequence.size();
    int left = 0, right = 0;
    int sum = sequence[0];
    int minLen = n + 1;
    int ansLeft = 0, ansRight = 0;
    
    while (right < n) {
        if (sum < k) {
            right++;
            if (right < n) sum += sequence[right];
        } else if (sum > k) {
            sum -= sequence[left];
            left++;
            if (left > right) {
                right = left;
                if (right < n) sum = sequence[right];
            }
        } else {
            int len = right - left + 1;
            if (len < minLen) {
                minLen = len;
                ansLeft = left;
                ansRight = right;
            }
            sum -= sequence[left];
            left++;
            if (left > right) {
                right = left;
                if (right < n) sum = sequence[right];
            }
        }
    }
    
    return {ansLeft, ansRight};
}
