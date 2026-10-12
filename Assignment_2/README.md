# Assignment 2: Data Structures — Array, Stack, and Queue

Comprehensive, marks-optimized answers, algorithms, step-by-step traces, and C implementations for all sections of **Assignment 2**.

---

## 📑 Table of Contents

| Section | Topic | Marks | Document Link | Questions Covered |
| :---: | :--- | :---: | :--- | :---: |
| **Section A** | Short / Definition Questions | **2 Marks Each** | [**`Section_A_Definitions.md`**](Section_A_Definitions.md) | Q1 – Q15 (15 questions) |
| **Section B** | Short Answer / Algorithms | **5 Marks Each** | [**`Section_B_Algorithms.md`**](Section_B_Algorithms.md) | Q1 – Q16 (16 questions) |
| **Section C** | Long Answer / Numerical Problems | **10 Marks Each** | [**`Section_C_Long_Answers.md`**](Section_C_Long_Answers.md) | Q1 – Q10 (10 questions) |
| **Section D** | Additional Algorithm Questions | **5 / 10 Marks** | [**`Section_D_Additional_Questions.md`**](Section_D_Additional_Questions.md) | Q1 – Q24 (24 questions) |

---

## ⚡ Quick Complexity Cheat Sheet

| Data Structure | Access | Search | Insertion | Deletion | Space Complexity |
| :--- | :---: | :---: | :---: | :---: | :---: |
| **Array** | $O(1)$ | $O(n)$ | $O(n)^*$ | $O(n)^*$ | $O(n)$ |
| **Stack (Array / Linked List)** | $O(n)$ | $O(n)$ | $O(1)$ (push) | $O(1)$ (pop) | $O(n)$ |
| **Queue (Simple Array)** | $O(n)$ | $O(n)$ | $O(1)$ (enqueue) | $O(1)^{**}$ (dequeue) | $O(n)$ |
| **Circular Queue** | $O(n)$ | $O(n)$ | $O(1)$ | $O(1)$ | $O(n)$ |
| **Double Ended Queue (Deque)** | $O(n)$ | $O(n)$ | $O(1)$ (both ends) | $O(1)$ (both ends) | $O(n)$ |
| **Priority Queue (Binary Heap)** | $O(1)$ | $O(n)$ | $O(\log n)$ | $O(\log n)$ | $O(n)$ |

> **Notes:**  
> $^*$ In an array, insertion/deletion at the end is $O(1)$; at the beginning or middle it is $O(n)$ due to element shifting.  
> $^{**}$ In a simple array queue, dequeue is $O(n)$ if elements are shifted left; with a moving `front` pointer it is $O(1)$.

---

## 💡 Key Exam & Viva Rules
1. **Operator Precedence in Infix $\to$ Postfix/Prefix:**  
   `^` (Highest, Right-to-Left) $>$ `*`, `/` (Left-to-Right) $>$ `+`, `-` (Left-to-Right)
2. **Circular Queue:**  
   - Full Condition: `(rear + 1) % SIZE == front`
   - Empty Condition: `front == -1`
3. **Stack Overflows and Underflows:**  
   - Overflow: Push operation on a full stack (`top == MAX - 1`).  
   - Underflow: Pop operation on an empty stack (`top == -1`).
