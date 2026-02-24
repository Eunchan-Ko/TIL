---
date: 2026-02-02 ~ 2026-02-03
tags: [Algorithms, Theory, Backtracking]

---
# Backtracking & DFS
DFS는 그래프의 모든 노드에 대한 탐색.

Backtracking은 완전 탐색 문제에 대한 접근 방법

이를 접합해서 DFS의 계산 개수를 줄여 알고리즘을 최적화해낼 수 있다.

## Backtracking 진행 절차
1. 상태 공간 Tree 구성
2. DFS로 Tree 탐색
    1. 각 노드가 유망한지 판단
    2. 유망하지 않으면 해당 node의 자식 노드 탐색 X (가지치기)
3. 해답 도달 시 해답 기록