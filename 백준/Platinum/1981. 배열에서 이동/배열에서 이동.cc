#include <bits/stdc++.h>
using namespace std;
int n;
int arr[102][102];
int visited[102][102];
int dx[]{0, 0, 1, -1};
int dy[]{1, -1, 0, 0};
bool bfs(int gap, int criteria, int v) {
    queue<pair<int, int>> q;
    if (arr[0][0] < criteria || arr[0][0] > criteria + gap) return false;
    q.push({0, 0});
    visited[0][0] = v;
    while (!q.empty()) {
        auto [x, y] = q.front();
        if (x == n - 1 && y == n - 1) return true;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (arr[nx][ny] < criteria || arr[nx][ny] > criteria + gap) continue;
            if (visited[nx][ny] == v) continue;
            visited[nx][ny] = v;
            q.push({nx, ny});
        }
    }
    return false;
}
int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> arr[i][j];

    int left = 0, right = 200;  // gap 차이라고 한다면..?

    int v{1};
    while (left <= right) {  // 8번
        int mid = (left + right) >> 1;
        bool avail{};
        // mid 의 갭차이로
        // min을 조정한다면?
        for (int i = 0; i <= 200; i++) {
            bool avails = bfs(mid, i, v);
            v++;
            if (avails) {
                avail = true;
                break;
            }
        }
        if (avail) {  // 가능하다면 앞으로 떙기자
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << left;
    return 0;
}