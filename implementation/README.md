# 오답노트

## C++

### 뱀
- head, tail -> `deque` 이용

### 경사로
- `memset(array, 0, sizeof(int) * length)` -> `cstring` 헤더파일 필요함

## Python

### 실패율
- 리스트 `count`
- 정렬 `sort`, `sorted`, `key=lambda x:value`
    - `keys()`, `values()`, `items()` -> key만 뽑고 싶으면 딕셔너리 이름만 넣어도 됨. keys 생략 가능
        ```sorted(result, key=lambda x: result[x], reverse=True)```

### 가장 많이 받은 선물
- 2차원 배열 열 원소들의 합 - 배열 만들때 마지막에 '총계' 행 추가해주고 같이 기록하면 편함  