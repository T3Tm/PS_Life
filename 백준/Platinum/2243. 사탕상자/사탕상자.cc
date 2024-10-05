// #include <bits/stdc++.h>
// using namespace std;
// /*
//     [1, 10^6]
// */
// const int END = (int)1e6; 
// int tree[(END << 1) + 2];
// int n;
// const int ROOT = 1;

// void update(int idx, int v){
//     for(tree[idx+=END] += v; idx > 1; idx>>=1)tree[idx >> 1] = tree[idx] + tree[idx^1];
// }

// int kth(int node, int k){//1 -> END
//     if(node > END)return node - END;// 1,,6
//     int cnt = tree[node << 1];//왼쪽 자식의 개수를 확인한다.
//     if(cnt >= k)return kth(node << 1, k);
//     else return kth(node << 1 | 1, k - cnt);
// }

// int main(){
//     cin.tie(0) -> sync_with_stdio(0);
//     cin >> n;
//     while(n--){
//         int cmd,num;cin >> cmd >> num;//1e6 + 1 -> 1e5 * 5 -> 1e5 * 2 -> 1e5
//         if(cmd == 1){
//             int ret = kth(ROOT, num);//num번째
//             cout << ret << '\n';
//             update(ret, -1);
//         }else{
//             int tmp;cin >> tmp;
//             update(num,tmp);
//         }
//     }
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;
/*
    [1, 10^6]
*/
int END = 2;
vector<int> tree;
int n;
const int ROOT = 1;

void update(int idx, int v){
    for(tree[idx+=END/2] += v; idx > 1; idx>>=1)tree[idx >> 1] = tree[idx] + tree[idx^1];
}

int kth(int node, int k){//1 -> END
    if(node >= END/2)return node - END/2;
    int cnt = tree[node << 1];//왼쪽 자식의 개수를 확인한다.
    if(cnt >= k)return kth(node << 1, k);
    else return kth(node << 1 | 1, k - cnt);
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n;
    
    while(true) {
        if(END >= 1000000) {
            END *= 2;
            break;
        }
        END *= 2;
    }
    // 최대 갯수 << 1
    
    tree.resize(END);
        
    while(n--){
        int cmd,num;cin >> cmd >> num;//1e6 + 1 -> 1e5 * 5 -> 1e5 * 2 -> 1e5
        if(cmd == 1){
            int ret = kth(ROOT, num);//num번째
            cout << ret + 1 << '\n';
            update(ret, -1);
        }else{
            int tmp;cin >> tmp;
            update(num - 1,tmp);
        }
    }
    return 0;
}