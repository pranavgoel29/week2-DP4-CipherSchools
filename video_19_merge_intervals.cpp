#include <bits/stdc++.h>
using namespace std;


bool comparator(const pair<int,int> a, const pair<int,int> b) {
    return a.first < b.first;
}

bool areOverlapping(const pair<int,int> a, const pair<int,int> b) {
    return a.second >= b.first;
}

pair<int,int> mergeOverlappingIntervals(const pair<int,int> a, const pair<int,int> b) {
    return make_pair(a.first, max(a.second, b.second));
}

vector<vector<int>> mergeIntervals(vector<vector<int>> &interval)
{
    vector<pair<int,int>> intervals;
    for (int i = 0; i < interval.size(); i++) {
        intervals.push_back(make_pair(interval[i][0], interval[i][1]));
    }
    sort(intervals.begin(), intervals.end(), comparator);
    vector<pair<int,int>> mergedIntervals;
    mergedIntervals.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
        if (areOverlapping(mergedIntervals.back(), intervals[i])) {
            mergedIntervals.back() = mergeOverlappingIntervals(mergedIntervals.back(), intervals[i]);
        } else {
            mergedIntervals.push_back(intervals[i]);
        }
    }
    vector<vector<int>> ans;
    for (int i = 0; i < mergedIntervals.size(); i++) {
        ans.push_back({mergedIntervals[i].first, mergedIntervals[i].second});
    }
    return ans;
}

int main()
{

    return 0;
}