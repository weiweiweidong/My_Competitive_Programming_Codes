<div align="right">
  Language:
  中文 | 
  <a title="English" href="901_docs/README_en.md">English</a> | 
  <a title="日本語" href="901_docs/README_jp.md">日本語</a>
</div>


# My Competitive Programming Codes

本仓库主要用于存储我在学习各种算法和参加算法竞赛的笔记和代码。

<p align="center">
  <a href="https://github.com/weiweiweidong/My_Competitive_Programming_Codes">
    <img src="https://my-markdown-picture-bedding.oss-ap-northeast-1.aliyuncs.com/uPic/2025-01-05/Cover_Algorithm.jpeg">
  </a>
  <h3 align="center">My Competitive Programming Codes</h3>
</p>


## 目录

- [项目介绍](#项目介绍)
- [文件结构说明](#文件结构说明)
- [版权说明](#版权说明)
- [链接](#链接)

****

### 项目介绍

在上学期间，我逐渐对算法产生了兴趣，并深刻体会到它在计算机科学中的核心地位。对于一名程序员来说，算法不仅是基本功，更是构建高效、可靠软件的基石，同时也是人工智能、分布式系统等领域不断创新与突破的关键。本仓库主要记录了我学习算法的过程及思考，希望这些内容能给你带来帮助或启发。

项目整体有两个部分最为核心：

- `./1_AcWing_Algo_Course` ：文件夹记录了我在 AcWing 算法课程中学习到的知识
- `./2_AtCoder/01_AtCoder_Beginner(ABC)`：文件夹存储了我在 AtCoder Beginner Contest 比赛中的代码和笔记。

### 文件结构说明

下面是本项目的文件树结构：

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

- `0_History_Archive` ：主要存储未整理的历史文件。

- **`1_AcWing_Algo_Course`：存储了 AcWing 算法课程的所有代码和学习笔记**

  - **`1_Basic_Algorithms`** ：存储了 AcWing 初级算法课程的所有代码和学习笔记。详细文件结构如下：

    ```
    1_Basic_Algorithms
    ├── CH1
    │   ├── 1_Quick_Sort
    │   ├── 2_Merge_Sort
    │   ├── 3_Binary_Search_int
    │   ├── 4_Binary_Search_float
    │   ├── 5_High_Accuracy
    │   ├── 6_Prefix_Sum
    │   ├── 7_Difference
    │   ├── 8_Two_Pointers
    │   ├── 9_Bit
    │   ├── 10_Discretization
    │   └── 11_Interval_Merging
    ├── CH2
    │   ├── 1_Linked_List
    │   ├── 2_Stack
    │   ├── 3_Queue
    │   ├── 4_Monotonic_Stack
    │   ├── 5_Monotonous_Queue
    │   ├── 6_KMP
    │   ├── 7_Trie
    │   ├── 8_Union_Find
    │   ├── 9_Heap
    │   └── 10_Hash_Table
    ├── CH3
    │   ├── 1_DFS
    │   ├── 2_BFS
    │   ├── 3_Graph_DFS
    │   ├── 4_Graph_BFS
    │   ├── 5_Topological_Sorting
    │   ├── 6_Dijkstra
    │   ├── 7_Bellman_Ford
    │   ├── 8_SPFA
    │   ├── 9_ Floyd
    │   ├── 10_Prim
    │   ├── 11_Kruskal
    │   └── 12_Bipartite_Graph
    ├── CH4
    │   ├── 1_Prime
    │   ├── 2_Divisor
    │   ├── 3_Euler's_Totient_Function
    │   ├── 4_Binary_Exponentiation
    │   ├── 5_EXGCD
    │   └── 7_Combination
    ├── CH5_Dynamic_Programming
    │   ├── 1_Knapsack_DP
    │   ├── 2_Linear_DP
    │   ├── 3_Interval_DP
    │   ├── 4_Counting_DP
    │   ├── 5_Digit_DP
    │   ├── 7_Tree_DP
    │   └── 8_Memoization_Search
    └── CH6_Greedy
        ├── 1_Interval
        ├── 2_Huffman_Tree
        ├── 3_Inequality
        └── 4_Formula_Derivation
    ```

  - **`2_Advanced_Algorithms` ：（更新中）。存储了 AcWing 高级算法课程的所有代码和学习笔记。详细文件结构如下：**

    ```
    2_Advanced_Algorithms
    ├── CH1
    │   ├── 1_Digital_Triangle_Model
    │   ├── 2_Longest_Ascending_Subsequence_Model
    │   ├── 3_Backpack_DP
    │   ├── 4_State_Machine_Model
    │   ├── 5_State_Compression_DP
    │   ├── 6_Interval_DP
    │   ├── 7_Tree_DP
    │   ├── 8_Digit_DP
    │   └── 9_Monotonic_Queue_Optimization_DP
    ├── CH2
    │   ├── 12_Bi_Directional_DFS
    │   ├── 1_Flood_Fill
    │   ├── 2_Shortest_Path_Model
    │   ├── 3_MultiSource_BFS
    │   ├── 4_MinimalSteps_Model
    │   ├── 5_DoubleEndedQueue_BFS
    │   ├── 6_Bi_Directional_BFS
    │   ├── 7_A_star
    │   ├── 8_Connectivity_Model_DFS
    │   ├── 9_Search_Order_DFS
    │   ├── 10_Pruning_Optimization_DFS
    │   └── 11_Iteration_Deepens
    ├── CH3
    │   ├── 1_Single_Source_Shortest_Circuit
    │   │   ├── 1_Graph_Construction
    │   │   ├── 2_Application
    │   │   └── 3_Extension
    │   └── 9_LCA
    ├── CH4
    │   ├── 1_Union_Find
    │   ├── 2_Binary_Indexed_Trees
    │   └── 3_Segment_Tree
    ├── CH5
    │   ├── 1_Prime
    │   ├── 2_Prime_Factorization
    │   ├── 3_Fast_Pow
    │   ├── 4_Divisor
    │   ├── 5_Euler's_Totient_Function
    │   ├── 6_Congruence_Modulo
    │   ├── 7_Matrix_Multiplication
    │   ├── 8_Combination_Count
    │   ├── 11_Probability_and_Expectation
    │   └── 12_Game_Theory
    └── CH6
        ├── 1_Bit
        ├── 2_ Recursion
        ├── 3_Prefix_Sum
        ├── 4_Binary_Search
        ├── 5_Sort
        └── 6_RMQ
    ```

  - `99_AcWing_Week` ：存储 AcWing 周赛的代码

- `2_AtCoder`：

  - **`01_AtCoder_Beginner(ABC)`：（更新中）存储目前参加 AtCoder 比赛的代码和笔记。**详细笔记会同步更新在博客 [JoeyDDong's Blog](https://joeyddong.top/) 中。

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
    └── ...（更新中）
    ```

### 版权说明

该项目签署了MIT 授权许可，详情请参阅 [LICENSE](LICENSE)

### 链接

个人博客：[JoeyDDong's Blog](https://joeyddong.top/)



