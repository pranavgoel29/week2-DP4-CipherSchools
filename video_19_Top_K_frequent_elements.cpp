class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    for (int num : nums) {
        count[num]++;
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    for (auto& [num, frequency] : count) {
        heap.push({frequency, num});
        if (heap.size() > k) {
            heap.pop();
        }
    }
    
    vector<int> result;
    while (!heap.empty()) {
        result.push_back(heap.top().second);
        heap.pop();
    }
    
    reverse(result.begin(), result.end());
    return result;
    }
};