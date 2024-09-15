#include <bits/stdc++.h>

using namespace std;
const int MX = 200002;
int n;
pair<int,int> tree[MX];//index, value
void init() {
    for(int i=n-1;i>0;i--){
        if(tree[i<<1].second > tree[i<<1 | 1].second){
            tree[i] = tree[i<<1 | 1];
        }
        else if(tree[i << 1].second == tree[i << 1 | 1].second){
            tree[i] = {min(tree[i << 1].first, tree[i << 1 | 1].first), tree[i << 1].second};
        }else{
            tree[i] = tree[i << 1];
        }
    }
}

void update(int i, int v){
    for(tree[i+=n].second  = v; i>1;i>>=1){
        if(tree[i].second > tree[i^1].second){
            tree[i >> 1] = tree[i^1];
        }
        else if(tree[i].second == tree[i^1].second){
            tree[i >> 1] = {min(tree[i].first, tree[i^1].first), tree[i].second};
        }else{
            tree[i >> 1] = tree[i];
        }
    }
}
int query(int l, int r){
    pair<int,int> ret{-1, (int)1e9 + 1};
    for(l += n, r +=n; l < r; l >>= 1, r >>= 1){
        if(l & 1){
            if(tree[l].second < ret.second){
                ret = tree[l];
            }
            else if(tree[l].second == ret.second){
                ret.first = min(tree[l].first, ret.first);
            }
            l++;
        }
        if(r & 1){
            --r;
            if(tree[r].second < ret.second){
                ret = tree[r];
            }
            else if(tree[r].second == ret.second){
                ret.first = min(tree[r].first, ret.first);
            }
        }
    }
    return ret.first;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n;
    for(int i=n;i<2*n;i++){
        cin >> tree[i].second;
        tree[i].first = i - n + 1;
    }
    init();
    int m;cin >> m;
    while(m--){
        int cmd,a,b;cin >> cmd >> a >> b;
        if(cmd == 1){
            update(a-1,b); 
        }else{
            cout << query(a-1,b) << '\n';
        }
    }
    return 0;
}