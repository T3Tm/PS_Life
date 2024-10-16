#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<char>> board;
/*
    bfs를 돌리는데 해당하는 구간에
    260,000은 충분히 다돌지 않나..
    해당하는 열쇠를 얻으면 새로운
*/
int visited[102][102];
int key;
int dx[]{0, 0, 1, -1};
int dy[]{1, -1, 0, 0};
// 열쇠를 얻으면 매번 새로운 방문을 찍는다.
void findLocation(queue<pair<int, int>>& q, vector<pair<int, int>>& remain) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!(i == 0 || i == n - 1 || j == 0 || j == m - 1)) {
                continue;
            }
            if (board[i][j] == '*') continue;
            if ('A' <= board[i][j] && board[i][j] <= 'Z') {
                if (key & (1 << (board[i][j] - 'A'))) {
                    board[i][j] = '.';  // 열쇠 있음
                } else {
                    remain.push_back({i, j});
                    visited[i][j] = key;
                    continue;
                }
            } else if ('a' <= board[i][j] && board[i][j] <= 'z') {  // 문
                key |= 1 << (board[i][j] - 'a');
                board[i][j] = '.';
            }
            q.push({i, j});
            visited[i][j] = key;
        }
    }
}
int bfs() {
    queue<pair<int, int>> q;
    memset(visited, -1, sizeof visited);
    int cnt{};
    vector<pair<int, int>> remain;
    findLocation(q, remain);
    for (int repeat{}; repeat < 27 && !q.empty(); repeat++) {  // 최대 26번만 반복하면 된다. 알파벳 떄문에
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (board[x][y] == '$') {
                cnt++;
                board[x][y] = '.';
            } else if ('A' <= board[x][y] && board[x][y] <= 'Z') {
                if (!(key & (1 << (board[x][y] - 'A')))) {
                    remain.push_back({x, y});
                    continue;
                }
                board[x][y] = '.';  // 열쇠 있음
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (visited[nx][ny] != -1 || board[nx][ny] == '*') continue;
                if ('A' <= board[nx][ny] && board[nx][ny] <= 'Z') {
                    if (key & (1 << (board[nx][ny] - 'A'))) {
                        board[nx][ny] = '.';  // 열쇠 있음
                    } else {
                        remain.push_back({nx, ny});
                        visited[nx][ny] = key;
                        continue;
                    }
                } else if ('a' <= board[nx][ny] && board[nx][ny] <= 'z') {  // 문
                    key |= 1 << (board[nx][ny] - 'a');
                    board[nx][ny] = '.';
                }
                visited[nx][ny] = key;
                q.push({nx, ny});
            }
        }
        while (!remain.empty()) {
            auto [x, y] = remain.back();
            remain.pop_back();
            q.push({x, y});
        }
    }

    return cnt;
}
int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        key = 0;
        cin >> n >> m;
        board = vector<vector<char>>(n, vector<char>(m + 1, ' '));
        for (auto& i : board) {
            string a;
            cin >> a;
            for (int j = 0; j < m; j++) i[j] = a[j];
        }
        string keys;
        cin >> keys;
        for (auto& i : keys) {
            if (i == '0') break;
            key |= 1 << (i - 'a');
        }
        cout << bfs() << '\n';
    }
    return 0;
}