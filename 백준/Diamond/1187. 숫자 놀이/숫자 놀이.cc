#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>mod;//나머지를 기준으로 idx를 넣어놓는 곳
//갯수 저장하기
vector<int>modcnt;
int n;
vector<int> result;
vector<int>arr;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n;
    arr.resize(2 * n - 1);
    vector<int>tmp;
    for(int i=0;i<2 *n -1;i++){
        cin >> arr[i];
        tmp.push_back(arr[i]);
    }
    //전처리는 홀수는 거르기
    //1차에서는 일단 홀수

    
    for(int i=1;1 << i <= n;i++){//2이라면
        mod.clear();mod.resize(1 << i);//2칸 만들기
        modcnt.clear(); modcnt.resize(1 << i);
        vector<int>temp;
        for(int t=0;t<tmp.size();t+= 1 << (i-1)){//2개씩 잘라야 되는 구나
            int total{};
            for(int j=0;j<1 << (i-1);j++){
                total = (total + tmp[t + j])%(1 << i);
            }
            mod[total].push_back(t);//tmp에 시작 인덱스
            modcnt[total]++;
        }
        for(int t=0;t<modcnt[0]/2;t++){
            for(int p=0;p<2;p++){
                for(int z = 0;z< 1 << (i-1);z++){
                    temp.push_back(tmp[mod[0][t*2+p]+z]);
                }
            }
        }
        //1번만 반복해야 된다.
        for(int t=0;t<modcnt[1 << (i-1)]/2;t++){
        //0 2 4
            for(int p = 0; p<2;p++){
                for(int z = 0;z< 1 << (i-1);z++){
                    temp.push_back(tmp[mod[1 << (i-1)][t*2 + p] + z]);
                }
            }
        }
        tmp.clear();
        for(auto &v:temp){
            tmp.push_back(v);//넣어주기
        }
    }
    
    unordered_map<int, int>last;
    for(auto &v:tmp){
        last[v]++;
    }
    for(int i=0;i < arr.size();i++){
        if(last.find(arr[i]) != last.end()){
            if(last[arr[i]] != 0){
                last[arr[i]]--;
                cout << arr[i] << ' ';
            }
        }
    }
    return 0;
}