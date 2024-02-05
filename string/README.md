# 오답노트
## C++
---
### 숫자 문자열과 영단어
- `#include <regex>`
    - `regex_replace(str, A, B)` - str에서 A를 B로 바꿈. A는 정규표현식이 옴


## Python
---

### 숫자 문자열과 영단어
- 시간 복잡도 생각 안할거면 `replace()` 사용하자 (`a.replace()` 하면 변환한 문자열 반환. `a`를 바꾸진 않음)
    - 문자열에서 자릿수 다른 수 처리할 때 사용 가능(ex. 0 ~ 10 -> 10만 't'로 replace 한 뒤 for문에서 쉽게 처리)  
- 딕셔너리 key, value 쌍 -> `for key, value in dict.items()`

### 개인정보 수집 유효기간
- `date` (ex. '2000.01.31') 비교 -> 년, 월, 일 하나씩 비교할 필요 없이 `day`로 변환해서 비교하자
- `enumerate`로 인덱스 접근
- 딕셔너리도 `for`문으로 한 줄로 작성 가능

### 신규 아이디 추천
- 대문자 소문자 변환 `upper()`, `lower()`
- `replace()` 대신 여러 문자를 한번에 바꾸는 `translate()` 를 사용할 수 있음 -> 근데 까먹지 않을까..?
    ```
    key = "~!@#$%^&*()=+[{]}:?,<>/" # 특수문자 제거
    value = " " * len(key)
    table = str.maketrans(key, value)
    
    my_string = my_string.translate(table) 
    ```
- `startswidth()`, `endswidth()` 
    - 그냥 `string[0]`, `string[-1]` 로 접근해도 되는데 위 문제에서 문자열이 공백일 때를 생각 안해서 오류 났었음.. 대안이 있다는 것만 알아두자.
- `string`은 `append`말고 `+=`
- `string.isalpha()`, `string.isdigit()` : 문자 하나 or 문자열에 적용 가능

### 신고 결과 받기
- 리스트 내에서 중복 제거하고 사용하려면 `set()` 쓰자
    - 해시 테이블 구조 사용
    - `in` 연산 시 `set`, `dict` 은 평균 `O(1)` / `list`는 평균 `O(n)`

### 비밀지도
- `bin`, `oct`, `hex` - 2진수(`0b`), 8진수(`0o`), 16진수(`0x`)로 변환
- `str` - 숫자를 문자열로 변환. 2진수, 8진수, 16진수는 접두어도 변환되기 때문에 [2:]로 제거해줘야 함.
- `rjust` : 오른쪽으로 정렬하도록 도와줌
- `ljust` : 왼쪽으로 정렬하도록 도와줌
    - 공백의 수, 공백을 메워줄 문자를 넣어줌
    ```
    val = "77".rjust(5, "0")
    print(val) # 00077

    val = "222".ljust(5, "0")
    print(val) # 22200
    ```
- `zfill` : 0을 왼쪽에 채워주는 역할
    ```
    val = "123".zfill(5)
    print(val)  # 00123
    ```