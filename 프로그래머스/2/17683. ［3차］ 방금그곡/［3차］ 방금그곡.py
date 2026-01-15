'''
'26. 1. 15.(목)

1. 재생 시간과 제공된 악보를 직접 보면서 비교한다.
2. 음악 제목, 재생이 시작, 끝난 시각, 악보 제공
3. 도부터 시까지 12개

4. 기억한 멜로디 m
5. 방송된 곡의 정보 배열


1. m과 musicinfos 둘다 C#같이 샵은 처리하기 어렵기 때문에
이것을 소문자로 대체!
'''
def time_trans(s, e) -> int:
    h, t = map(int, s.split(':'))
    hh, tt = map(int, e.split(':'))
    return max((hh * 60 + tt) - (h * 60 + t), 0)

def solution(m, musicinfos):
    answer = '(None)'
    time = -1
    for i in range(26):
        m = m.replace(chr(i + 65) + '#', chr(i + 97))
        # 샵이 붙어잇으면 소문자로 대체!
    
    for music in musicinfos:
        st, et, song, sheet = music.split(',')
        now_time = time_trans(st, et)
        print(now_time)
        
        #print("now_time : ", now_time)
        for i in range(26):
            sheet = sheet.replace(chr(i + 65) + '#', chr(i + 97))
            # 샵이 붙어잇으면 소문자로 대체!
        length = len(sheet)
        
        div = max(length, now_time) // length
        
        sheet = sheet * 1000
        #print(sheet[:1])
        
        #패턴이 들어있는지 확인
        if m in sheet[:now_time]:
            if time < now_time:
                answer = song
                time = now_time
                
    return answer