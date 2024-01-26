# 오답노트

### k진수에서 소수 개수 구하기
- 진수 변환 후 string으로 저장 : `string[::-1]` 이용
- `string.split()`
    - 파라미터를 기준으로 split하는데, 빈 문자열이 생길 수 있어 처리해줘야 함. ex) '21100011' -> '211', '', '', '11'
    - `l = [int(k) for k in m.split('0') if k]`

### n진수 변환
- n진수 변환
    ```
    def conv(n, k):
        s = ''
        while k > 0:
            if k % n >= 10:
                s += str(chr(k % n + 55))
            else:
                s += str(k % n)
            k //= n
        return s[::-1]
    ```

### 주차 요금 계산
- 딕셔너리 key 기준으로 정렬 : `dict(sorted(d.items()))`
    - `sorted(d)` - key만 추출하여 정렬함
    - value 기준 정렬 : `dict(sorted(d.items(), key=lambda x:x[1]))`
- `dict.keys()`, `dict.values()` - dict_keys, dict_values 객체를 반환함. (리스트와는 다름)