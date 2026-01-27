---
date: 2026-01-26 ~ 27
tags: [Python, datastructure, method, sequence, Basics]

---

# Method
데이터 구조의 **메서드**를 호출하여 다양한 **기능**을 활용하기
- **객체**에 속한 함수
- 
## 공통 시퀀스 메서드
1. `index(x)` : 시퀀스에서 첫번째로 일치하는 항목 x의 인덱스를 반환
2. `count(x)` : 시퀀스에서 항목 x의 개수를 반환
```python
s = 'banana'
s.index('a')  # 1
s.count('a')  # 3
```
## 불변 시퀀스 메서드 (문자열 전용)
### 탐색 및 검증
### 문자열 조작

## 가변 시퀀스 메서드 (리스트 전용)
### 값 추가 및 삭제
### 정렬

## 복사
### 객체와 참조
### 얕은 복사
### 깊은 복사

## ETC
### List Comprehension
파이썬만의 독특한 문법으로, 기존 리스트를 기반으로 새로운 리스트를 생성하는 방법
`[expression for item in iterable if condition]`
```python
squared_numbers = [x**2 for x in range(10)]
## 결과: [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]
```
다만 복잡한 로직이 필요한 경우에는 일반적인 for 루프를 사용하는 것이 가독성에 더 좋을 수 있음
### 메서드 체이닝
여러 메서드를 연속해서 호출하는 기법
```python
text = "  Hello, World!  "
cleaned_text = text.strip().upper().replace(" ", "_")
## 결과: "HELLO,_WORLD!"
```
리스트에서의 메서드 체이닝 예시
```python
# 안되는 예시
numbers = [5, 2, 9, 1, 5, 6]

## 결과: [1, 2, 5, 6, 9]
```
### 문자 유형 판별 메서드