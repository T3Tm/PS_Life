#include <bits/stdc++.h>
using namespace std;

struct loc {
    int x, y;
};
//각 y을 인덱스 맵핑해놓기

const int MX = 75000;
long long tree[MX*2 + 2];

void init(int n){
    for(int i = n-1;i>0;i--)tree[i] = tree[i<<1]+tree[i<<1 | 1];
}

void update(int idx, long long v, int& n){
    for(tree[idx+=n] = v;idx > 1; idx>>=1)tree[idx >> 1] = tree[idx] + tree[idx^1];
}

long long query(int i, int j, int& n){
    long long ret{};
    for(i+=n,j+=n; i<j;i>>=1, j>>=1){
        if(i&1)ret += tree[i++];
        if(j&1)ret += tree[--j];
    }
    return ret;
}

unordered_map<int,int>y_position;//y의 값을 인덱스로 처리하기
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t;cin >> t;
    while(t--){
        int n;cin >> n;//일단 입력을 다 받고 x좌표를 기준으로 오름차순으로 arr를 만들어주자.
        memset(tree, 0, sizeof tree);//초기화

        vector<loc> arr(n);
        vector<int>y_pos;
        for(auto &[x,y]:arr){
            cin >> x >> y;
            y_pos.push_back(y);
        }

        sort(arr.begin(),arr.end(),[](const loc&a, const loc&b){//같다면 무조건 왼쪽 위를 봐야하니 큰 것을 먼저
            if(a.x == b.x)return a.y > b.y;
            return a.x < b.x;
        });
        
        sort(y_pos.begin(), y_pos.end());//정렬해주고
        
        for(int i{};i<y_pos.size();i++){
            y_position[y_pos[i]] = i+1;//해당 y값이 들어왔을 때 index를 빠르게 알려주기
        }//[1: N]
        int l = y_pos.size();//끝은 N이다.

        long long result{};
        for(int i=0;i<n;i++){
            //바꾸기 전에 나보다 크거나 같은 범위 내에 y_position 이상의 index 값 다 갖고 오기
            auto& [x,y] = arr[i];//y의 값을 하나 증가되게 바꾸기
            result += query(y_position[y]-1, l, l);//이놈 인덱스 이후의 값 갱신
            update(y_position[y]-1, tree[y_position[y]+l-1]+1, l);
        }
        cout << result << '\n';
    }
    return 0;
}
