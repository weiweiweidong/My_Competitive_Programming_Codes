<div align="right">
  Language:
  <a title="中文" href="../README.md">中文</a> | 
  English | 
  <a title="日本語" href="README_jp.md">日本語</a>
</div>


# My Competitive Programming Codes

This repository is mainly used to store my notes and codes from learning various algorithms and participating in programming contests.

<p align="center">
  <a href="https://github.com/weiweiweidong/My_Competitive_Programming_Codes">
    <img src="https://my-markdown-picture-bedding.oss-ap-northeast-1.aliyuncs.com/uPic/2025-01-05/Cover_Algorithm.jpeg">
  </a>
  <h3 align="center">My Competitive Programming Codes</h3>
</p>

## Table of Contents

- [Project Introduction](#project-introduction) 
- [File Structure](#file-structure)
- [License](#license)
- [Links](#links)

****

### Project Introduction

During my studies, I gradually developed a keen interest in algorithms and came to understand their central role in computer science. For a programmer, algorithms are not only a fundamental skill but also the cornerstone of building efficient and reliable software, as well as a key driver for innovation and breakthroughs in fields like artificial intelligence and distributed systems. This repository mainly records my learning process and reflections on algorithms, and I hope it may be helpful or inspiring to you. 

The project revolves around two main parts: 

- `./1_AcWing_Algo_Course`: This folder contains all the materials I studied in the AcWing algorithm course. 
- `./2_AtCoder/01_AtCoder_Beginner(ABC)`: This folder contains my code and notes from the AtCoder Beginner Contests. 

### File Structure 

Below is the file tree structure of this project:

```
filetree 
├── 0_History_Archive
├── 1_AcWing_Algo_Course
│   ├── 1_Basic_Algorithms
│   ├── 2_Advanced_Algorithms
│   └── 99_AcWing_Week
├── 2_AtCoder
│   ├── 01_AtCoder_Beginner(ABC)
│   ├── 02_AtCoder_Regular(ARC)
│   ├── 04_AtCoder_Heuristic(AHC)
│   ├── 10_Permanent_Contests
│   ├── 15_Practice
│   └── 20_Virtual_ABC_Practice
├── 3_Codeforces
├── 4_LeetCode
├── 900_template
├── 901_docs
└── 999_test_file_clear_script
```

`filetree`

- `0_History_Archive` ：Mainly stores historical files that have not been sorted.

- **`1_AcWing_Algo_Course`：Contains all the codes and study notes from the AcWing algorithm course.**

  - **`1_Basic_Algorithms`** ：Holds all codes and notes from the AcWing Basic Algorithms course. The detailed file structure is as follows:

    ```
    1_Basic_Algorithms
    ├── CH1
    │   ├── 1_Quick_Sort
    │   ├── 2_Merge_Sort
    │   ├── 3_Binary_Search_int
    │   ├── 4_Binary_Search_float
    │   ├── 5_High_Accuracy
    │   ├── 6_Prefix_Sum
    │   ├── 7_Difference
    │   ├── 8_Two_Pointers
    │   ├── 9_Bit
    │   ├── 10_Discretization
    │   └── 11_Interval_Merging
    ├── CH2
    │   ├── 1_Linked_List
    │   ├── 2_Stack
    │   ├── 3_Queue
    │   ├── 4_Monotonic_Stack
    │   ├── 5_Monotonous_Queue
    │   ├── 6_KMP
    │   ├── 7_Trie
    │   ├── 8_Union_Find
    │   ├── 9_Heap
    │   └── 10_Hash_Table
    ├── CH3
    │   ├── 1_DFS
    │   ├── 2_BFS
    │   ├── 3_Graph_DFS
    │   ├── 4_Graph_BFS
    │   ├── 5_Topological_Sorting
    │   ├── 6_Dijkstra
    │   ├── 7_Bellman_Ford
    │   ├── 8_SPFA
    │   ├── 9_ Floyd
    │   ├── 10_Prim
    │   ├── 11_Kruskal
    │   └── 12_Bipartite_Graph
    ├── CH4
    │   ├── 1_Prime
    │   ├── 2_Divisor
    │   ├── 3_Euler's_Totient_Function
    │   ├── 4_Binary_Exponentiation
    │   ├── 5_EXGCD
    │   └── 7_Combination
    ├── CH5_Dynamic_Programming
    │   ├── 1_Knapsack_DP
    │   ├── 2_Linear_DP
    │   ├── 3_Interval_DP
    │   ├── 4_Counting_DP
    │   ├── 5_Digit_DP
    │   ├── 7_Tree_DP
    │   └── 8_Memoization_Search
    └── CH6_Greedy
        ├── 1_Interval
        ├── 2_Huffman_Tree
        ├── 3_Inequality
        └── 4_Formula_Derivation
    ```

  - **`2_Advanced_Algorithms` ：(in progress): Contains all codes and notes from the AcWing Advanced Algorithms course. Details are as follows**

    ```
    2_Advanced_Algorithms
    ├── CH1
    │   ├── 1_Digital_Triangle_Model
    │   ├── 2_Longest_Ascending_Subsequence_Model
    │   ├── 3_Backpack_DP
    │   ├── 4_State_Machine_Model
    │   ├── 5_State_Compression_DP
    │   ├── 6_Interval_DP
    │   ├── 7_Tree_DP
    │   ├── 8_Digit_DP
    │   └── 9_Monotonic_Queue_Optimization_DP
    ├── CH2
    │   ├── 12_Bi_Directional_DFS
    │   ├── 1_Flood_Fill
    │   ├── 2_Shortest_Path_Model
    │   ├── 3_MultiSource_BFS
    │   ├── 4_MinimalSteps_Model
    │   ├── 5_DoubleEndedQueue_BFS
    │   ├── 6_Bi_Directional_BFS
    │   ├── 7_A_star
    │   ├── 8_Connectivity_Model_DFS
    │   ├── 9_Search_Order_DFS
    │   ├── 10_Pruning_Optimization_DFS
    │   └── 11_Iteration_Deepens
    ├── CH3
    │   ├── 1_Single_Source_Shortest_Circuit
    │   │   ├── 1_Graph_Construction
    │   │   ├── 2_Application
    │   │   └── 3_Extension
    │   └── 9_LCA
    ├── CH4
    │   ├── 1_Union_Find
    │   ├── 2_Binary_Indexed_Trees
    │   └── 3_Segment_Tree
    ├── CH5
    │   ├── 1_Prime
    │   ├── 2_Prime_Factorization
    │   ├── 3_Fast_Pow
    │   ├── 4_Divisor
    │   ├── 5_Euler's_Totient_Function
    │   ├── 6_Congruence_Modulo
    │   ├── 7_Matrix_Multiplication
    │   ├── 8_Combination_Count
    │   ├── 11_Probability_and_Expectation
    │   └── 12_Game_Theory
    └── CH6
        ├── 1_Bit
        ├── 2_ Recursion
        ├── 3_Prefix_Sum
        ├── 4_Binary_Search
        ├── 5_Sort
        └── 6_RMQ
    ```

  - `99_AcWing_Week` ：Contains codes from weekly contests on AcWing.

- `2_AtCoder`：

  - **`01_AtCoder_Beginner(ABC)`：(in progress): Stores my code and notes from participating in AtCoder Beginner Contests.**  Detailed notes are also updated on my blog: [JoeyDDong's Blog](https://joeyddong.top/).

    ```
    .
    ├── ABC_363_(A~F)
    ├── ABC_375_(A~F)
    ├── ABC_376_(A~E)
    ├── ABC_377_(A~G)
    ├── ABC_378_(A~F)
    ├── ABC_379_(A~F)
    ├── ABC_380_(A~E)
    ├── ABC_381_(A~E)
    ├── ABC_382_(A~D)
    ├── ABC_383_(A~E)
    ├── ABC_384_(A~F)
    ├── ABC_385_(A~E)
    ├── ABC_386_(A~F)
    └── ABC_387
    └── ...（In progress）
    ```

### License

This project is licensed under the MIT License. For more details, please refer to [LICENSE](../LICENSE).

### Links

Personal Blog: [JoeyDDong's Blog](https://joeyddong.top/)