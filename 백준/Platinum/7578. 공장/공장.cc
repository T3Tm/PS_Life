#include <bits/stdc++.h>
using namespace std;
int MX = 1;
vector<int> tree;
void init(int n){
    int size = 2;
    while(size <= n)size <<= 1;
    MX = size;
    tree.resize(size << 1);
}

void update(int x, int y){//최댓값
    for(tree[x+=MX] = y; x > 1; x>>=1)tree[x >> 1] = tree[x] + tree[x^1];
}
int query(int left, int right){
    int ret{};
    for(left += MX, right +=MX; left < right; left >>=1, right >>=1){
        if(left & 1)ret += tree[left++];
        if(right &1)ret += tree[--right];
    }
    return ret;
}

const int SIZE = 1e6 + 2;
int mark[SIZE];
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin >> n;//나보다 큰 아이들 알아내기
    init(n);
    for(int i = MX; i < MX + n; i++){
        int tmp;cin >> tmp;
        mark[tmp] = i - MX + 1;
    }


    long long result{};
    for(int i{1};i<=n;i++){
        int tmp;cin >> tmp;
        tmp = mark[tmp];
        update(tmp-1, 1);//2,4,1,3,5
        int ret = query(0, tmp);
        result += i - ret;
    }
    cout << result;

    return 0;
}