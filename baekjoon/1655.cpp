#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    priority_queue<int> max_heap; // 최대 힙 (중간값 이하)
    priority_queue<int, vector<int>, greater<int>> min_heap; // 최소 힙 (중간값 초과)
    
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        
        // 1. 크기 균형에 따라 삽입
        if(max_heap.size() == min_heap.size()) {
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }
        
        // 2. 필요시 조정: 최대 힙의 top은 최소 힙의 top보다 작거나 같아야 함
        if(!min_heap.empty() && !max_heap.empty() && max_heap.top() > min_heap.top()) {
            int max_top = max_heap.top();
            int min_top = min_heap.top();
            
            max_heap.pop();
            min_heap.pop();
            
            max_heap.push(min_top);
            min_heap.push(max_top);
        }
        
        // 3. 중간값 출력 (최대 힙의 top)
        cout << max_heap.top() << '\n';
    }
    return 0;
}
