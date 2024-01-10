# 오답노트

### 실패율
- 리스트 `count`
- 정렬 `sort`, `sorted`, `key=lambda x:value`
    - `keys()`, `values()`, `items()` -> key만 뽑고 싶으면 딕셔너리 이름만 넣어도 됨. keys 생략 가능
        ```sorted(result, key=lambda x: result[x], reverse=True)```