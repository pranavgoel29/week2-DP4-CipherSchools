vector<int> nextGreaterElementII(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nextGreater;
    stack<int> s;
    for (int i = 0; i < nums2.size(); i++) {
        while (!s.empty() && nums2[s.top()] < nums2[i]) {
            nextGreater[nums2[s.top()]] = nums2[i];
            s.pop();
        }
        s.push(i);
    }
    
    for (int i = 0; i < nums2.size(); i++) {
        while (!s.empty() && nums2[s.top()] < nums2[i]) {
            nextGreater[nums2[s.top()]] = nums2[i];
            s.pop();
        }
    }
    
    vector<int> result;
    for (int num : nums1) {
        result.push_back(nextGreater.count(num) ? nextGreater[num] : -1);
    }
    return result;
}