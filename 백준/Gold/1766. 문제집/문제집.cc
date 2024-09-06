#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    int indegree[32002]{};
    vector<vector<int>> graph(n + 1);
    for (int i{}; i < m; i++) {
        int a, b;
        cin >> a >> b;
        indegree[b]++;
        graph[a].push_back(b);
    }

    priority_queue<int, vector<int>, greater<int>> q;
    for (int i{1}; i <= n; i++) {
        if (!indegree[i]) q.push(i);
    }
    while (!q.empty()) {
        auto front = q.top();
        q.pop();
        cout << front << ' ';
        for (auto &next : graph[front]) {
            indegree[next]--;
            if (!indegree[next]) q.push(next);
        }
    }
    return 0;
}