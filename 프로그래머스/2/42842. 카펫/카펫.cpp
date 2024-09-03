#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    
    for(int garo = yellow; garo >= 1; garo--){
        if(yellow % garo != 0)continue;
        int sero = yellow / garo;
        
        if((garo + 2) * (sero + 2) == brown + yellow){
            answer = {garo + 2, sero + 2};
            break;
        }
    }
    return answer;
}