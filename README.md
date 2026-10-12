# DSA Assignment - Queue Programming Questions

This repository contains C implementations for Data Structures & Algorithms (DSA) queue assignment questions covering **Linear Queue**, **Circular Queue**, **Double Ended Queue (Deque)**, and **Priority Queue**.

---

## 📁 Repository Structure

| File | Description |
| :--- | :--- |
| [`1_linear_queue.c`](1_linear_queue.c) | Implementation of Linear Queue using an array. |
| [`2_circular_queue.c`](2_circular_queue.c) | Implementation of Circular Queue using an array of size 5. |
| [`3_deque.c`](3_deque.c) | Implementation of Double Ended Queue (Deque) using an array. |
| [`4_priority_queue.c`](4_priority_queue.c) | Implementation of Priority Queue using an array. |

---

## 📌 Questions & Operations Performed

### 1. Linear Queue (`1_linear_queue.c`)
**Problem Statement:** Write a C program to implement a Linear Queue using an array. Perform the following operations:
1. Insert `10`, `20`, and `30` into the queue.
2. Delete two elements from the Front.
3. Insert `40` into the Rear.
4. Display the remaining elements.

**Expected Result:** Remaining elements are `30` and `40`.

---

### 2. Circular Queue (`2_circular_queue.c`)
**Problem Statement:** Write a C program to implement a Circular Queue using an array of size 5. Perform the following operations:
5. Insert `10`, `20`, `30`, and `40`.
6. Delete two elements from the Front.
7. Insert `50` and `60` into the queue (demonstrating wrap-around).
8. Display the elements of the Circular Queue.

**Expected Result:** Remaining elements in circular order are `30`, `40`, `50`, and `60`.

---

### 3. Double Ended Queue (Deque) (`3_deque.c`)
**Problem Statement:** Write a C program to implement a Deque using an array. Perform the following operations:
9. Insert `10` from Front.
10. Insert `20` from Rear.
11. Insert `30` from Front.
12. Delete one element from Front.
13. Delete one element from Rear.
14. Display the remaining elements.

**Expected Result:** Remaining element is `10`.

---

### 4. Priority Queue (`4_priority_queue.c`)
**Problem Statement:** Write a C program to implement a Priority Queue using an array. Perform the following operations:
15. Insert `10` with priority 2.
16. Insert `20` with priority 1.
17. Insert `30` with priority 3.
18. Delete the element having the highest priority.
19. Display the remaining elements with their priorities.

> **Convention:** Lower numerical priority value indicates higher priority (`Priority 1 > Priority 2 > Priority 3`). Element `20` (Priority 1) is deleted as highest priority.

**Expected Result:** Remaining elements are `[10 (P:2)]` and `[30 (P:3)]`.

---

## 🛠️ Compilation and Execution

You can compile and run any of the programs using GCC:

### 1. Linear Queue
```bash
gcc 1_linear_queue.c -o 1_linear_queue
./1_linear_queue
```

### 2. Circular Queue
```bash
gcc 2_circular_queue.c -o 2_circular_queue
./2_circular_queue
```

### 3. Double Ended Queue (Deque)
```bash
gcc 3_deque.c -o 3_deque
./3_deque
```

### 4. Priority Queue
```bash
gcc 4_priority_queue.c -o 4_priority_queue
./4_priority_queue
```

---

## 🖥️ Sample Outputs

### 1. Linear Queue Output
```text
=====================================================
           QUESTION 1: LINEAR QUEUE                  
=====================================================

--- Operation 1: Insert 10, 20, and 30 into the queue ---
Successfully inserted 10 at Rear (Index: 0).
Successfully inserted 20 at Rear (Index: 1).
Successfully inserted 30 at Rear (Index: 2).
Current state: Queue elements (Front to Rear): [ 10 20 30 ] (Front index: 0, Rear index: 2)

--- Operation 2: Delete two elements from the Front ---
Successfully deleted 10 from Front (Index: 0).
Successfully deleted 20 from Front (Index: 1).
Current state: Queue elements (Front to Rear): [ 30 ] (Front index: 2, Rear index: 2)

--- Operation 3: Insert 40 into the Rear ---
Successfully inserted 40 at Rear (Index: 3).
Current state: Queue elements (Front to Rear): [ 30 40 ] (Front index: 2, Rear index: 3)

--- Operation 4: Display the remaining elements ---
Queue elements (Front to Rear): [ 30 40 ] (Front index: 2, Rear index: 3)

=====================================================
          Program Execution Completed Successfully   
=====================================================
```

### 2. Circular Queue Output
```text
=====================================================
          QUESTION 2: CIRCULAR QUEUE (SIZE = 5)       
=====================================================

--- Operation 5: Insert 10, 20, 30, and 40 into the queue ---
Successfully inserted 10 at Rear (Index: 0).
Successfully inserted 20 at Rear (Index: 1).
Successfully inserted 30 at Rear (Index: 2).
Successfully inserted 40 at Rear (Index: 3).
Current state: Circular Queue elements (Front to Rear): [ 10 20 30 40 ] (Front index: 0, Rear index: 3)

--- Operation 6: Delete two elements from the Front ---
Successfully deleted 10 from Front (Index: 0).
Successfully deleted 20 from Front (Index: 1).
Current state: Circular Queue elements (Front to Rear): [ 30 40 ] (Front index: 2, Rear index: 3)

--- Operation 7: Insert 50 and 60 into the queue ---
Successfully inserted 50 at Rear (Index: 4).
Successfully inserted 60 at Rear (Index: 0).
Current state: Circular Queue elements (Front to Rear): [ 30 40 50 60 ] (Front index: 2, Rear index: 0)

--- Operation 8: Display the elements of the Circular Queue ---
Circular Queue elements (Front to Rear): [ 30 40 50 60 ] (Front index: 2, Rear index: 0)

=====================================================
          Program Execution Completed Successfully   
=====================================================
```

### 3. Deque Output
```text
=====================================================
         QUESTION 3: DOUBLE ENDED QUEUE (DEQUE)      
=====================================================

--- Operation 9: Insert 10 from Front ---
Successfully inserted 10 at Front (Index: 0).
Current state: Deque elements (Front to Rear): [ 10 ] (Front index: 0, Rear index: 0)

--- Operation 10: Insert 20 from Rear ---
Successfully inserted 20 at Rear (Index: 1).
Current state: Deque elements (Front to Rear): [ 10 20 ] (Front index: 0, Rear index: 1)

--- Operation 11: Insert 30 from Front ---
Successfully inserted 30 at Front (Index: 4).
Current state: Deque elements (Front to Rear): [ 30 10 20 ] (Front index: 4, Rear index: 1)

--- Operation 12: Delete one element from Front ---
Successfully deleted 30 from Front (Index: 4).
Current state: Deque elements (Front to Rear): [ 10 20 ] (Front index: 0, Rear index: 1)

--- Operation 13: Delete one element from Rear ---
Successfully deleted 20 from Rear (Index: 1).
Current state: Deque elements (Front to Rear): [ 10 ] (Front index: 0, Rear index: 0)

--- Operation 14: Display the remaining elements ---
Deque elements (Front to Rear): [ 10 ] (Front index: 0, Rear index: 0)

=====================================================
          Program Execution Completed Successfully   
=====================================================
```

### 4. Priority Queue Output
```text
=====================================================
             QUESTION 4: PRIORITY QUEUE              
  (Rule: Lower priority number = Higher priority)    
=====================================================

--- Operation 15: Insert 10 with priority 2 ---
Successfully inserted Value: 10 with Priority: 2.
Current state: Priority Queue elements [Value (Priority)]: [10 (P:2)] (Total elements: 1)

--- Operation 16: Insert 20 with priority 1 ---
Successfully inserted Value: 20 with Priority: 1.
Current state: Priority Queue elements [Value (Priority)]: [20 (P:1)] [10 (P:2)] (Total elements: 2)

--- Operation 17: Insert 30 with priority 3 ---
Successfully inserted Value: 30 with Priority: 3.
Current state: Priority Queue elements [Value (Priority)]: [20 (P:1)] [10 (P:2)] [30 (P:3)] (Total elements: 3)

--- Operation 18: Delete the element having the highest priority ---
Successfully deleted element with highest priority: Value: 20 (Priority: 1).
Current state: Priority Queue elements [Value (Priority)]: [10 (P:2)] [30 (P:3)] (Total elements: 2)

--- Operation 19: Display the remaining elements with their priorities ---
Priority Queue elements [Value (Priority)]: [10 (P:2)] [30 (P:3)] (Total elements: 2)

=====================================================
          Program Execution Completed Successfully   
=====================================================
```

