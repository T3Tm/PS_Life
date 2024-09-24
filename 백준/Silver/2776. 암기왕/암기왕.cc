#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n'
/*

*/
using namespace std;
int main() {
	fast; int t; cin >> t;
	while (t--) {
		int n,m; cin >> n;
		unordered_set<int>a;
		for (int i = 0, b; i < n; i++)cin >> b,a.insert(b);
		cin >> m;
		for (int j = 0, b; j < m; j++)cin >> b, cout << a.count(b) << endl;
	}
}