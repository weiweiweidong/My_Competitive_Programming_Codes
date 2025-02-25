# **E - Palindromic Shortest Path**

Problem：[E - Palindromic Shortest Path](https://atcoder.jp/contests/abc394/tasks/abc394_e)

## 题目：

给定 N 个节点的有向图。

使用邻接矩阵 C 来表示图。

- 如果 $C_{i,j}$ 为 `-`，表示节点 `i` 与节点 `j` 之间没有边
- 如果 $C_{i,j}$ 为小写字母，表示有一条节点 `i` 指向节点 `j` 的边，且边的代码为这个小写字母

对于每一个整数对 $(i,j)$，回答下面问题：

- 从 i 到 j，是否存在最短的回文串路径。如果存在，输出距离；如果不存在，输出 `-1`

## 约束条件：

$1 \leq N \leq 100$

## 思路：

