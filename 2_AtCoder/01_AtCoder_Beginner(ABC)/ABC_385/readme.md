## ReadMe

# **D - Santa Claus 2**

Problem：[D - Santa Claus 2](https://atcoder.jp/contests/abc385/tasks/abc385_d)

## 题目：

二维平面上有坐标为 $(X_1,Y_1), ... ,(X_N,Y_N)$ 共 $N$ 个房子。

最开始，圣诞老人在起点 $(S_x,S_y)$ 处，按照序列 $(D_1,C_1), ... ,(D_M,C_M)$ 方式移动

- 若 $(x,y)$ 是当前点坐标
  - 若 $D_i$ 是 `U`，则沿着直线从 $(x,y)$ 移动到 $(x, y+C_i)$
  - 若 $D_i$ 是 `D`，则沿着直线从 $(x,y)$ 移动到 $(x, y-C_i)$
  - 若 $D_i$ 是 `L`，则沿着直线从 $(x,y)$ 移动到 $(x-C_i, y)$
  - 若 $D_i$ 是 `R`，则沿着直线从 $(x,y)$ 移动到 $(x+C_i, y)$

求出完成所有移动后，圣诞老人经过的房子的数量。（若多次经过相同房间，只计算 1 次）

## 约束条件：

$1 \leq N \leq 2\times 10^5$

$1 \leq M \leq 2\times 10^5$

$-10^9 \leq X_i,Y_i \leq 10^9$

There is no house at $(S_x,S_y)$.

$1 \leq C_i \leq 10^9$

## 思路：

