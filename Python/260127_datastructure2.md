---
date: 2026-01-26 ~ 27
tags: [Python, datastructure, method, non-sequence, Basics]

---
# 비시퀀스 데이터구조 메서드
데이터 구조의 **메서드**를 호출하여 다양한 **기능**을 활용하기
## 딕셔너리 메서드
1. `get(key, default=None)` : 키에 해당하는 값을 반환, 키가 없으면 default 반환
   ```python
    d = {'a': 1, 'b': 2}
    d.get('a')        # 1
    d.get('c')        # None
    d.get('c', 0)     # 0
    print(d['c'])     # KeyError
   ```
   상황에 따라 조회에 실패할 시 프로그램 종료가 필요하다면 대괄호 표기법을 사용.

   하지만 일반적인 상황에서는 `get()` 메서드를 사용하는 것이 더 안전.
2. `keys()` : 딕셔너리의 모든 키를 반환
   ```python
    d = {'a': 1, 'b': 2}
    d.keys()          # dict_keys(['a', 'b'])
   ```
   따라서 print 보다는, for 반복문 등에서 활용하는 것이 더 적합.
   ```python
    for key in d.keys():
        print(key, d[key])
   ```
3. `values()` : 딕셔너리의 모든 값을 반환
   ```python
    d = {'a': 1, 'b': 2}
    d.values()        # dict_values([1, 2])
   ```
4. `items()` : 딕셔너리의 모든 (키, 값) 쌍을 반환
   ```python
    d = {'a': 1, 'b': 2}
    d.items()        # dict_items([('a', 1), ('b', 2)])
   ```
   각 아이템이 튜플로 반환되므로, [언패킹](260121_lazy_evaluation.md)하여 사용할 수 있음.
   ```python
    for key, value in d.items():
        print(key, value)
   ```
5. `pop(key, default=None)` : 지정한 키에 해당하는 항목을 제거하고 값을 반환
   ```python
    d = {'a': 1, 'b': 2}
    d.pop('a')       # 1
    print(d)         # {'b': 2}
    d.pop('c', 0)    # 0
    d.pop('c')       # KeyError
   ```
6. `clear()` : 딕셔너리의 모든 항목을 제거
   ```python
    d = {'a': 1, 'b': 2}
    d.clear()
    print(d)         # {}
   ```
7. `setdefault(key, default=None)` : 키가 없으면 default 값을 설정하고 반환
   ```python
    d = {'a': 1}
    d.setdefault('b', 2)  # 2
    print(d)              # {'a': 1, 'b': 2}
    d.setdefault('a', 3)  # 1
    print(d)              # {'a': 1, 'b': 2}
    d.setdefault('c')     # None
    print(d)              # {'a': 1, 'b': 2, 'c': None}
    d.setdefault('d', 4)  # 4
    print(d)              # {'a': 1, 'b': 2, 'c': None, 'd': 4}
   ```
   `get()`과 유사하지만, 키가 없을 때 항목을 추가하는 차이가 있음.
8. `update([other_dict])` : 다른 딕셔너리의 항목들로 현재 딕셔너리를 업데이트
   ```python
    d = {'a': 1}
    d.update({'b': 2, 'c': 3})
    print(d)         # {'a': 1, 'b': 2, 'c': 3}
    d.update({'a': 10})
    print(d)         # {'a': 10, 'b': 2, 'c': 3}

   ```
## 세트 메서드
### **세트에 대해**

고유한 항목들의 정렬되지 않은 컬렉션
- Set은 내부적으로 해시 테이블을 사용하여 항목들을 저장
- 항목들은 순서가 없으며, 인덱싱이나 슬라이싱이 불가능

### **주요 세트 메서드**

1. `add(elem)` : 세트에 항목 elem을 추가
   ```python
    s = {1, 2, 3}
    s.add(4)
    print(s)         # {1, 2, 3, 4}
   ```
2. `update(*others)` : 여러 이터러블의 항목들을 세트에 추가
   ```python
    s = {1, 2, 3}
    s.update([4, 5], {6, 7})
    print(s)         # {1, 2, 3, 4, 5, 6, 7}
   ```
3. `clear()` : 세트의 모든 항목을 제거
   ```python
    s = {1, 2, 3}
    s.clear()
    print(s)         # set()
   ```
4. `remove(elem)` : 세트에서 항목 elem을 제거, 없으면 KeyError 발생
   ```python
    s = {1, 2, 3}
    s.remove(2)
    print(s)         # {1, 3}
    s.remove(4)      # KeyError
   ```
5. `pop()` : 세트에서 임의의 항목을 제거하고 반환
   ```python
    s = {1, 2, 3}
    elem = s.pop()
    print(elem)      # 예: 1
    print(s)         # 예: {2, 3}
   ```
   임의의 항목을 제거함으로 프로그램을 실행할 때마다 다른 결과가 나올 수 있음.
6. `discard(elem)` : 세트에서 항목 elem을 제거, 없으면 아무 일도 일어나지 않음
   ```python
    s = {1, 2, 3}
    s.discard(2)
    print(s)         # {1, 3}
    s.discard(4)     # 아무 일도 일어나지 않음
    print(s)         # {1, 3}
   ```
   `remove()`와 달리, 항목이 없어도 에러가 발생하지 않음.

### 집합 연산 메서드
1. set1.difference(set2) : 차집합을 반환 `set1 - set2`
   ```python
    s1 = {1, 2, 3}
    s2 = {3, 4, 5}
    result = s1.difference(s2)
    print(result)    # {1, 2}
    result = s1 - s2
   ```
2. set1.intersection(set2) : 교집합을 반환 `set1 & set2`
   ```python
    s1 = {1, 2, 3}
    s2 = {3, 4, 5}
    result = s1.intersection(s2)
    print(result)    # {3}
    result = s1 & s2
   ```
3. set1.union(set2) : 합집합을 반환 `set1 | set2`
   ```python
    s1 = {1, 2, 3}
    s2 = {3, 4, 5}
    result = s1.union(s2)
    print(result)    # {1, 2, 3, 4, 5}
    result = s1 | s2
   ```
4. set1.issubset(set2) : 부분집합 여부 반환 `set1 <= set2`
   ```python
    s1 = {1, 2}
    s2 = {1, 2, 3, 4}
    result = s1.issubset(s2)
    print(result)    # True
    result = s1 <= s2
   ```
5. set1.issuperset(set2) : 상위집합 여부 반환 `set1 >= set2`
   ```python
    s1 = {1, 2, 3, 4}
    s2 = {1, 2}
    result = s1.issuperset(s2)
    print(result)    # True
    result = s1 >= s2
   ```
# 참고
## 딕셔너리의 확장
### `defaultdict` (collections 모듈)
파이썬 내장 모듈 `collections`에서 제공하는 `defaultdict`는 기본 딕셔너리와 유사하지만, 존재하지 않는 키에 접근할 때 자동으로 기본값을 생성 `.setdefault()` 메서드와 유사한 기능을 제공
```python
from collections import defaultdict
d = defaultdict(int)  # 기본값이 0인 딕셔너리 생성
dl = defaultdict(list) # 기본값이 빈 리스트인 딕셔너리 생성
d['a'] += 1          # 'a' 키가 없으므로 기본값 0에서 시작하여 1이 됨
print(d)             # defaultdict(<class 'int'>, {'a': 1})
dl['b'].append(2)    # 'b' 키가 없으므로 기본값 빈 리스트에서 시작하여 [2]가 됨
print(dl)            # defaultdict(<class 'list'>, {'b': [2]})
```
defaultdict는 특히 카운팅, 그룹화 등에서 유용하게 사용될 수 있음.

defaultdict를 dictationary로써 활용하려면 `dict()` 생성자를 사용

**주의**: defaultdict는 기본값을 자동으로 생성하기 때문에, 존재하지 않는 키에 접근할 때 의도치 않게 항목이 추가될 수 있음. 따라서 이 점을 염두에 두고 사용해야 함.
## 파이썬 문법 규격
BNF (Backus-Naur Form)
- 파이썬 문법을 형식적으로 정의한 규격
- 비교적 간결하고 명확하게 문법 구조를 표현
  
EBNF (Extended Backus-Naur Form)
- BNF의 확장된 형태
- 더 많은 표현력을 제공
- 1. 선택적 요소 (optional elements): 대괄호 `[]`로 표현
  - 예: `<expression> ::= <term> [ ('+' | '-') <term> ]`
- 2. 반복 요소 (repetitive elements): 중괄호 `{}`로 표현
  - 예: `<arguments> ::= <argument> { ',' <argument> }`
- 3. 그룹화 (grouping): 소괄호 `()`로 표현
  - 예: `<factor> ::= '(' <expression> ')' | <number> | <identifier>`
## 해시테이블
해시테이블은 키-값 쌍을 저장하는 데이터 구조이다.

![hash function](../imgs/hash%20function.png)

- 해시 함수: 키를 고정된 크기의 해시 값으로 변환
