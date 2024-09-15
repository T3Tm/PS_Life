#include <bits/stdc++.h>
using namespace std;

/*
    p와 q는 서로 거울 대칭이고, 
    p와 d는 서로 점 대칭이다. 
    b와 d는 서로 거울 대칭이고, 
    b와 q는 서로 점 대칭이다. 
    알파벳 u와 n의 경우 또한 서로 점 대칭을 이룬다. 
    또한 i, m, v, w과 같은 알파벳은 그 자체로 거울 대칭이고, 
    s, z는 그 자체로 점 대칭이다. 
    l, o, x는 점 대칭이자 거울 대칭인 알파벳이다.
    거울 :  p -> q
           b -> d
           i -> i
           m -> m
           v -> v
           w -> w
           l -> l
           o -> o
           x -> x
*/
unordered_map<char,char> mirror{
    {'l', 'l'}, {'o','o'}, {'x','x'},{'p','q'},{'q','p'},
    {'b','d'},{'d','b'}, {'i','i'},{'m','m'},{'v','v'},{'w','w'},
};

/*
    점   :  p -> d
           b -> q
           u -> n
           s -> z
           l -> l
           o -> o
           x -> x
*/
unordered_map<char,char> dot{
    {'p', 'd'}, {'b','q'} , {'u','n'}, {'s','s'},
    {'l', 'l'}, {'o','o'}, {'x','x'},{'d','p'},{'q','b'},
    {'n','u'},{'z','z'}
};

int manacher(const string& s, unordered_map<char, char>& trans){
    int l = s.size();
    vector<int>A(l, -1);
    int r=-1,q=-1;

    for(int i=0;i < l;i++){
        if(trans.find(s[i]) == trans.end())continue;//아예 들어있지도 않은 아이라면 그냥 안됨.
        if(r>=i){
            int ii = 2 * q - i ;
            A[i] = min(r-i, A[ii]);
        }else{
            //자기 자신으로 되는 아이들인지 판단 아니면 그냥 continue;
            if(s[i] != trans[s[i]])continue;
            A[i] = 0;
        }
        while(i - A[i] - 1>=0 && s[i + A[i] + 1]){
            if(trans.find(s[i+A[i]+1]) == trans.end())break;
            if(s[i - A[i] - 1] != trans[s[i+A[i]+1]])break;
            A[i]++;
        }
        if(i + A[i] > r){
            r = i + A[i];
            q = i;
        }
    }
    return *max_element(A.begin(), A.end());
}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    string tmp;cin >> tmp;
    string word;
    for(auto &v: tmp){
        word.push_back('o');
        word.push_back(v);
    }
    word.push_back('o');

    int ret = max(manacher(word, mirror), manacher(word, dot));
    if(ret == 0){
        cout << "NOANSWER";
    }else{
        cout << ret;
    }
    return 0;
}