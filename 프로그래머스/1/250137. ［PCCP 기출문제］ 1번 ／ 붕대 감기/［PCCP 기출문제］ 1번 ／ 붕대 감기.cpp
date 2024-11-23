#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
    1. t초 동안 붕대를 감으면 1초동안 x의 체력 회복
    2. t초 연속으로 붕대를 감으면 y만큼 추가 회복
    최대 체력 존재함 max_health
    공격 당하면 기술 취소, 체력 회복 안 됨
    
    기술 끝나면 붕대 감기 사용, 연속 시간 0초 초기화
    시전 시간, 초당 회복량, 추가 회복량
*/
int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int idx{};//attacks 인덱스 갖고 오기
    
    int time{1};//현재 진행된 시간
    int last_attack{0};//마지막으로 공격 받은 시간 갖고 오기
    
    int max_health = health;//최대 체력 보존
    while(idx < attacks.size() && time <= attacks[idx][0] && health){
        if(time == attacks[idx][0]){//현재 공격 받을 떄임
            last_attack = time;//현재 시간으로 바꿔주기
            health = max(0, health - attacks[idx++][1]);//체력 달기
        }else{//현재 회복 타임
            health = min(max_health, health + bandage[1]);//초당 회복으로 들어감.
            if(time - last_attack == bandage[0]){//연속 성공
                last_attack = time;//현재 시간으로 만들기
                health = min(max_health, health + bandage[2]);
            }
        }
        time++;
    }
    return (health ? health : -1);
}