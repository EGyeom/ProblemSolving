#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> s(nums.begin(), nums.end());
    answer = nums.size()/2 < s.size() ? nums.size()/2 : s.size();
    return answer;
}