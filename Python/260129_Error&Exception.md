---
date: 2026-01-29
tags: [Python, Error, Basics]

---

# 에러와 예외 처리
### 디버깅
소프트웨어에서 발생하는 버그를 찾아내고 수정하는 과정.

프로그램의 오작동 원인을 식별하여 수정하는 작업.
#### 디버깅 방법
1. 코드 리뷰
   - 코드를 꼼꼼히 읽어보며 논리적 오류나 오타를 찾음.
   - 동료와 함께 코드 리뷰를 진행하여 다양한 시각에서 문제를 발견.
2. 출력문 활용
   - 코드 중간중간에 출력문을 삽입하여 변수 값이나 흐름을 확인.
   - 예상과 다른 값이 출력되는 부분을 집중적으로 점검.
   - 예시:
   ```python
    def add(a, b):
         result = a + b
         print(f"Debug: a={a}, b={b}, result={result}")  # 디버깅 출력문
         return result
    ```
3. 디버거 사용
   - IDE나 디버깅 도구를 활용하여 코드 실행을 단계별로 추적.
   - 변수 값, 호출 스택 등을 실시간으로 확인하며 문제를 분석.
   - Python tutor (https://pythontutor.com/) 같은 온라인 디버거도 유용.
### 에러
프로그램 구문이 올바르지 않은 경우에 발생하는 문제.
#### 문법 오류 (Syntax Error)
코드가 언어의 문법 규칙을 따르지 않을 때 발생.
#### 논리 오류 (Logical Error)
코드가 문법적으로는 올바르지만, 의도한 대로 동작하지 않을 때 발생.

논리 오류의 경우 프로그램상에서 정상 실행되기 때문에 디버깅이 더 어려울 수 있음.
### 예외
프로그램 실행 중에 발생하는 예외 상황.
#### 내장 예외(Built-in Exceptions)
파이썬에서 미리 정의된 예외 클래스들.
- 예시: `ZeroDivisionError`, `IndexError`, `KeyError`, `TypeError`, `NameError`, `ValueError` 등
- 
## 예외 처리
파이썬에서 예외가 발생했을 때 프로그램이 비정상 종료되지 않도록 처리하는 방법.
#### 예외처리 사용 구문 예시
```python
try:
    # 예외가 발생할 수 있는 코드
    x = input("숫자를 입력하세요: ")
    result = 10 / int(x)
except ZeroDivisionError:
    # 예외 발생 시 처리할 코드
    print("0으로 나눌 수 없습니다.")
except ValueError:
    print("유효한 숫자를 입력하세요.")
else:
    # 예외가 발생하지 않았을 때 실행할 코드
    print(f"결과는 {result}입니다.")
finally:
    # 예외 발생 여부와 상관없이 항상 실행되는 코드
    print("프로그램 종료.")
```
### try-except 구문
try 블록 내에서 예외가 발생할 수 있는 코드를 작성하고, except 블록에서 해당 예외를 처리.

만약 개발자가 예외처리를 하지 않은 예외가 발생하면, 프로그램이 비정상 종료됨.
```python
try:
    # 예외가 발생할 수 있는 코드
    pass
except SomeException:
    # 예외 발생 시 처리할 코드
    pass
```

### 복수 예외 처리
하나의 try 블록에서 여러 종류의 예외를 처리할 수 있음.
```python
try:
    # 예외가 발생할 수 있는 코드
    pass
except (TypeError, ValueError):
    # TypeError 또는 ValueError 발생 시 처리할 코드
    pass
```
또는
```python
try:
    # 예외가 발생할 수 있는 코드
    pass
except TypeError:
    # TypeError 발생 시 처리할 코드
    pass
except ValueError:
    # ValueError 발생 시 처리할 코드
    pass
```
### 예상하지 못한 예외 처리
```python
try:
    # 예외가 발생할 수 있는 코드
    pass
except Exception: 
    # 모든 예외 발생 시 처리할 코드
    print(f"예외가 발생했습니다. {Exception}")
```
이렇게 모든 예외를 포괄적으로 처리할 수 있지만, 구체적인 예외 처리를 하는 것이 디버깅에 더 유리함.
### else & finally 구문
거의 try 블록에서 처리가 가능하지만, else 와 finally 블록을 사용할 수도 있음.
- else: 예외가 발생하지 않았을 때 실행되는 코드 블록.
- finally: 예외 발생 여부와 상관없이 항상 실행되는 코드 블록.
## etc
### 예외 처리 주의사항
1. else-if 문과 같이 순서에 따라 예외를 처리해야 할 때는 구체적인 예외부터 처리.
   - 예외 처리 순서는 구체적인 예외가 먼저 오도록 해야 함.
   - 범용적인 예외가 먼저 오면, 그 뒤에 오는 구체적인 예외는 절대 처리되지 않음.
2. 과도한 예외 처리는 오히려 디버깅을 어렵게 만들 수 있으므로, 필요한 부분에만 예외 처리 적용.
### 예외 객체 다루기