void insertAtBottom(stack<int> &s, int x) {
    if (s.empty()) {
        s.push(x);
        return;
    }
    int y = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(y);
}

void reverse(stack<int> &s)
{
    if (s.empty()) {
        return;
    }
    int x = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s, x);
}