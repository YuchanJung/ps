# 오답노트

### 크레인 인형뽑기 게임
- 리스트 비어있는지 체크 -> `if listname`, `if not listname`

### 완주하지 못한 선수
- `hash(key)` - key 값에 따라 고유한 hash 값 생성
- `collections.Counter`
    - python dict의 서브클래스
    - `{key: value}` 형태
    - 덧셈, 뺄셈이 가능하다.

### 캐시
- `collections.deque()` - `maxlen`을 파라미터로 지정할 수 있음. maxlen 초과 시 자동 pop 후 append.

### 튜플
-  2차원 배열 정렬 시 각 값들(문자열, 배열)의 길이를 기준으로 할 때 -> `list.sort(key=len)`

### 뉴스 클러스터링
- `set`을 이용해 합집합, 교집합 구할 수 있음.
    - `s1 & s2` or `s1.intersection(s2)`
    - `s1 | s2` or `s1.union(s2)`
    - `s1 - s2` or `s1.difference`
    - 대칭 차집합 : `s1 ^ s2`
- 위 문제는 중복을 허용하는 다중 집합 문제라 `set` 없이 풀이 가능