def solution(nums):
    data = {}
    for num in nums:
        data[num] = data.get(num, 0) + 1
    
    return min(len(data.keys()), len(nums)//2)