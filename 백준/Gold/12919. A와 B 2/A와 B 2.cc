#include <bits/stdc++.h>
using namespace std;
string s,t;
/*
    도달 가능하면 1, 없으면 0이다.
    1. 뒤에 A가 있다면 삭제한다.
    2. 뒤를 재정의하고 B를 앞으로 넣는다.
    뒤에 A가 있다면 삭제
*/

bool bfs(const string& src, const string& dst){
    unordered_set<string> visited;

    visited.insert(src);//방문 표시
    queue<pair<string, bool>>q;
    q.push({src, 0});//뒤에 있는 인자는 앞인지 뒤인지 알아보는 것
    //0이라면 뒤는 정말 뒤라는 것
    //1이라면 뒤는 앞이라는 것
    string reverse_dst = dst;

    reverse(reverse_dst.begin(), reverse_dst.end());
    while(!q.empty()){
        auto [now, front_back] = q.front();q.pop();
        if(front_back){
            if(reverse_dst == now)return 1;
        }else{
            if(dst == now)return 1;
        }

        if(!front_back){//진짜 뒤가 뒤임
            if(now.back() == 'A'){//삭제한다.
                string tmp = now;
                tmp.pop_back();
                if(visited.find(tmp) == visited.end()){
                    visited.insert(tmp);
                    q.push({tmp, front_back});
                }
            }
            //앞에 B가 있으면 
            if(now[0] == 'B'){
                string tmp = now.substr(1);
                if(visited.find(tmp) == visited.end()){
                    visited.insert(tmp);
                    q.push({tmp, !front_back});
                }
            }
        }else{//앞이 뒤임
            if(now[0] == 'A'){//삭제한다.
                string tmp = now.substr(1);
                if(visited.find(tmp) == visited.end()){
                    visited.insert(tmp);
                    q.push({tmp, front_back});
                }
            }
            //앞에 B가 있으면 
            if(now.back() == 'B'){
                string tmp = now;
                tmp.pop_back();
                if(visited.find(tmp) == visited.end()){
                    visited.insert(tmp);
                    q.push({tmp, !front_back});
                }
            }
        }
    }
    return 0;
}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    cin >> s >> t;
    cout << bfs(t, s);

    return 0;
}