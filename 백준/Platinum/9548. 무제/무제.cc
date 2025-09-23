#include <bits/stdc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;cin >> t;
	while(t--){
		string s; cin >> s;
		crope S(s.c_str());
		string cmd, r;
		int x, y;
		while(cin >> cmd){
			if(cmd[0] == 'E')break;
			
			if(cmd[0] == 'I'){
				cin >> r >> x;
				S.insert(x, r.c_str());
			}else{
				cin >> x >> y;
				cout << S.substr(x, y - x + 1) << '\n';
			}
		}
	}
	return 0;
}