---
date: 2026-01-21
tags: [Python, Control of Flow, Basics]

---
# Control of Flow (제어문)
오늘은 제어문에 대해 수업을 진행했다. 이에 따라 제어문에 대해 정리해본다.
## 제어문
코드의 실행 흐름을 제어하는 구문이다. 조건에 따라 코드 블록을 실행하거나 반복적으로 실행할 수 있다.
### 조건문 
주어진 조건에 따라 조건이 `True`인 경우에만 코드 블록을 실행하는 구문이다.
### if 문
조건문의 기본 형태
- `if` 키워드 다음에 조건을 표현식을 작성하고, 콜론(`:`)으로 끝낸다.
- 조건식이 `True`일 때 실행할 코드 블록은 들여쓰기로 구분한다.
### elif 문
- `elif` 키워드 다음에 조건을 표현식을 작성하고, 콜론(`:`)으로 끝낸다.
- 조건식이 `True`일 때 실행할 코드 블록은 들여쓰기로 구분한다.
- 다른 언어의 경우에는 `else if`로 작성되기도 한다.
### else 문
- `else` 키워드 다음에 콜론(`:`)으로 끝낸다.
- 조건식이 `False`일 때 실행할 코드 블록은 들여쓰기로 구분한다.
```python
# 조건문 예시
age = int(input("나이를 입력하세요: "))
age = 
if age < 18:
    print("미성년자입니다.")
elif age == 18:
    print("갓 성인이 되었습니다.")
else:
    print("성인입니다.")
```
### 조건문 제어 키워드
- `pass`: 조건문에서 아무 작업도 수행하지 않고 넘어가고 싶을 때 사용한다.
```python
age = 20
if age < 18:
    pass  # 미성년자에 대한 처리를 나중에 구현할 예정
else:
    print("성인입니다.")
```
### 반복문 (for 문, while 문)
주어진 코드블록을 여러번 실행하는 구문이다.
### for 반복
반복 가능한 객체의 요소들을 반복하는데 주로 사용된다.

int, float 같은 숫자형은 반복 불가능하다. -> `range()` 함수 활용
```python
# for 반복문 예시
fruits = ["apple", "banana", "cherry"]
for fruit in fruits:
    print(fruit)
```
**특징**

반복 횟수가 정해져있다.
#### range() 함수 활용
특정 숫자 범위만큼 반복하고 싶을 때 `range()` 함수는 지정된 범위의 숫자 시퀀스를 생성하는데 사용된다.

#### 딕셔너리 반복
딕셔너리 객체를 반복할 때는 기본적으로 키를 반복한다.
```python
# 딕셔너리 반복문 예시
my_dict = {'a': 1, 'b': 2, 'c': 3}
for key in my_dict:
    print(f"Key: {key}, Value: {my_dict[key]}")

```
### while 반복
while 조건이 `True`인 동안 코드 블록을 반복 실행한다.  
= 조건식이 `False`가 될 때까지 반복 실행한다.
```python
# while 반복문 예시
count = 0
while count < 5:
    print("Count:", count)
    count += 1
```
**특징**
반복 

횟수가 정해져있지 않다.
```python
input_value = ""
while input_value.lower() != "exit":
    input_value = input("종료하려면 'exit'를 입력하세요: ")
    print("입력한 값:", input_value)
```

### 반복문 제어 키워드
- `break`: 반복문을 즉시 종료한다.
```python
for i in range(10):
    if i == 5:
        break  # i가 5일 때 반복문 종료
    print(i)
    # 출력: 0, 1, 2, 3, 4
```
- `continue`: 현재 반복을 건너뛰고 다음 반복으로 넘어간다.
```python
for i in range(10):
    if i % 2 == 0:
        continue  # i가 짝수일 때 현재 반복 건너뛰기
    print(i)
    # 출력: 1, 3, 5, 7, 9
```

## 유용한 내장함수 (심화)
### map() 함수

### zip() 함수