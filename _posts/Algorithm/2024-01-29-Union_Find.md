---
title: "[Algorithm] Disjoint Sets(서로소 집합)"
date: 2024-01-29 15:56:00 +09:00
categories: [Algorithm, Problem Solving(PS)]
tags: [Algorithm, C++, 자료 구조, 분리 집합]
---
## **1. 개요**
서로소 집합(Disjoint Sets)은, 분리 집합이라고도 한다. 이름에서 파악할 수 있듯이, 각각의 집합이 공통 원소를 가지지 않는 집합을 의미한다.

정의를 살펴보면 두 집합 A와 B가, `A ∩ B = Ø`를 만족하면, 서로소 집합이라고 한다. 이 조건은 집합이 3개 이상인 경우에도 유효하다.

## **2. Union-Find(유니온-파인드)**
서로소 집합의 구현과 연산은 Union-Find로 이루어진다. 이름 그대로, 노드를 합치는 Union(병합) 연산과 노드의 루트 노드를 찾는 Find(찾기) 연산을 반복하는 알고리즘이다.

아래의 예제는 정점의 개수 n과 간선의 개수 m이 주어졌을 때, 이후의 m개의 줄에 간선을 잇는 두 개의 노드가 주어진다면 해당 자료 구조가 트리를 구성하는지 아닌지 판별하는 문제이다.

### **입력 예제**
```
<!-- case 1 -->
6 5
1 2
2 3
3 4
4 5
5 6

<!-- case 2 -->
6 6
1 2
2 3
1 3
4 5
5 6
6 4
```

### **출력 예제**
```
YES
NO
```

### **풀이**
- 아직 어떤 집합에 속해 있는지 특정되지 않았기 때문에, 모든 int 배열의 원소를 자기 자신의 인덱스와 맞춰준다.

```c++
int par[n+1];

for (int i = 1; i <= n; i++)
    par[i] = i;
```

- 주어진 두 개의 점들을 병합한다. 병합할 때 하나의 집합임을 확인하기 위해, 인덱스가 작은 쪽으로 병합한다.

```c++
void union_sets(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x > y)
        swap(x, y);

    par[y] = x;
}
```

- 특정 정점의 부모를 찾는다. 집합의 개수는 find 함수에서 찾을 수 있는 부모(즉, Root 노드)의 개수와 같다.

```c++
int find(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}
```

- 트리를 구성하는지 여부를 찾는다.

```c++
bool is_disjoint()
{
    bool flag = 1;
    for (int i = 1; i < n; i++)
    {
        if (par[i] != par[i+1])
            return !flag;
    }

    return flag;
}
```

- 구현 코드

```c++
#include <iostream>

using namespace std;

int n, m;
int par[11];

int find(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

void union_sets(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x > y)
        swap(x, y);

    par[y] = x;
}

bool is_disjoint()
{
    for (int i = 1; i < n; i++)
    {
        if (par[i] != par[i+1])
            return 0;
    }

    return 1;
}

void find_answer()
{
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        union_sets(u, v);
    }

    if (is_disjoint())
        cout << "YES";
    else
        cout << "NO";
}

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        par[i] = i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    find_answer();
}
```

## **3. BOJ_4803 트리**
보다 쉬운 이해를 위해, 백준 4803번. 트리를 가져왔다. 해당 문제 역시 정점과 간선의 개수가 주어지고, 간선을 잇는 두 점을 통해 해당 자료구조가 트리인지 아닌지 판별하는 문제이고, 나아가 주어진 정점으로 몇 개의 트리가 완성되는지 묻는 문제이다.
> [BOJ_4803. 트리](https://wnsvy7203.github.io/posts/4803)