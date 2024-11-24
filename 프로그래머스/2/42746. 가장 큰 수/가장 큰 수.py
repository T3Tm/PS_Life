def solution(numbers):
    answer = ''
    save_num= []
    for number in numbers:
        c = (str(number) * 4)[:4]
        length = len(str(number))
        save_num.append((c, length))
    for c,length in sorted(save_num,reverse=1):
        answer+=c[:length]
    return str(int(answer))