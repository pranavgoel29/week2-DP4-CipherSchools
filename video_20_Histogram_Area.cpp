vector<int> nextSmallerElementToTheLeft(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }
        ans[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    return ans;
}

vector<int> nextSmallerElementToTheRight(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }
        ans[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    return ans;
}

int maxArea(vector<int> heights)
{
    int n = heights.size();
    vector<int> left = nextSmallerElementToTheLeft(heights);
    vector<int> right = nextSmallerElementToTheRight(heights);
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        int area = width * heights[i];
        maxArea = max(maxArea, area);
    }
    return maxArea;
}