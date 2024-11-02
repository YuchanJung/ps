def make_dict(str):
    d = {}
    for i in range(len(str) - 1):
        if str[i].isalpha() and str[i + 1].isalpha():
            key = str[i] + str[i + 1]
            if d.get(key):
                d[key] += 1
            else:
                d[key] = 1
    return d
                
def solution(str1, str2):
    d1 = make_dict(str1.lower())
    d2 = make_dict(str2.lower())
    intersection = 0
    union = 0
    if not d1 and not d2:
        return 65536
        
    for key in d1.keys():
        if key in d2:
            intersection += min(d1[key], d2[key])
            union += max(d1[key], d2[key])
        else:
            union += d1[key]
            
    for key in d2.keys():
        if key not in d1:
            union += d2[key]
    
    return int(intersection / union * 65536)