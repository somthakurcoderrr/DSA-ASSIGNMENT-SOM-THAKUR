# Assignment 2 — Section A: 2 Marks (Short / Definition)

---

### Q1. What is a data structure? Differentiate between linear and non-linear data structures.

**Answer:**
A **data structure** is a specialized format for organizing, storing, processing, and retrieving data efficiently in computer memory. It defines the relationship between data items and the operations that can be performed on them.

#### Difference between Linear and Non-Linear Data Structures:

| Parameter | Linear Data Structure | Non-Linear Data Structure |
| :--- | :--- | :--- |
| **Arrangement** | Elements are arranged sequentially or linearly, one after another. | Elements are arranged in a hierarchical or interconnected manner. |
| **Traversal** | Can be traversed in a single run (single-level traversal). | Requires multi-level traversal (multiple valid paths exist). |
| **Predecessor / Successor** | Every element (except first and last) has a unique predecessor and successor. | An element can be connected to multiple elements (e.g., parent/children). |
| **Memory Allocation** | Typically contiguous or linear linked nodes. | Nodes distributed non-linearly across heap memory. |
| **Examples** | Array, Linked List, Stack, Queue. | Tree, Graph, Trie, Heap. |

---

### Q2. What is an array? Write two advantages and two disadvantages.

**Answer:**
An **array** is a linear data structure consisting of a collection of elements of the same data type (homogeneous), stored at contiguous memory locations, and accessible via index numbers ($0$ to $n-1$).

#### Advantages:
1. **Constant-Time Random Access ($O(1)$):** Any element can be accessed immediately using its index via memory address calculation formula: $\text{Address}(A[i]) = \text{Base Address} + i \times \text{Size of element}$.
2. **Cache Friendliness & Memory Efficiency:** Due to contiguous memory allocation, arrays exhibit high spatial locality of reference, leading to excellent CPU cache performance and zero pointer memory overhead.

#### Disadvantages:
1. **Fixed Size (Static Allocation):** The size of a static array must be known at compile time and cannot grow or shrink dynamically, leading to memory waste or overflow.
2. **Expensive Insertion and Deletion ($O(n)$):** Inserting or deleting an element at an arbitrary position requires shifting subsequent elements forward or backward.

---

### Q3. Why is random access in an array $O(1)$?

**Answer:**
Random access in an array takes **$O(1)$ constant time** because elements are stored in **contiguous (sequential) memory locations**, and each element occupies the same number of bytes ($c$ bytes).

The compiler/CPU can compute the exact physical memory address of any element $A[i]$ in a single arithmetic instruction using the direct address mapping formula:
$$\text{Memory Address}(A[i]) = \text{Base Address} + (i \times c)$$
where:
- $\text{Base Address}$: Memory address of the first element $A[0]$.
- $i$: The index being accessed ($0$-based).
- $c$: Size of each element in bytes (e.g., 4 bytes for `int`).

Because addition and multiplication take $O(1)$ CPU cycles, jumping directly to any index does not require sequential scanning, making access time constant.

---

### Q4. What are row-major and column-major order?

**Answer:**
Row-major and column-major orders are two different conventions used by compilers to linearize a multi-dimensional (2D) array in 1D contiguous physical memory.

1. **Row-Major Order (Used in C, C++, Python):**
   - Elements are stored **row by row**.
   - The entire first row is placed in contiguous memory, followed by the entire second row, and so on.
   - For an array $A[R][C]$ with base address $B$ and element size $W$:
     $$\text{Address}(A[i][j]) = B + [i \times C + j] \times W$$

2. **Column-Major Order (Used in Fortran, MATLAB, R):**
   - Elements are stored **column by column**.
   - The entire first column is placed in contiguous memory, followed by the second column, and so on.
   - For an array $A[R][C]$ with base address $B$ and element size $W$:
     $$\text{Address}(A[i][j]) = B + [j \times R + i] \times W$$

---

### Q5. What is a stack? Explain the LIFO principle.

**Answer:**
A **stack** is an abstract linear data structure that follows a restricted insertion and deletion discipline: elements can only be added or removed from a single end, known as the **top of the stack**.

#### LIFO Principle (Last-In, First-Out):
- **LIFO** means the element inserted most recently is the first one to be removed.
- Conversely, the earliest element inserted remains at the bottom and is removed last.
- **Analogy:** A stack of dining plates. The plate placed on top last is picked up first.
- **Key Operations:**
  - `push(x)`: Adds item $x$ to the top.
  - `pop()`: Removes and returns the top item.
  - `peek()`: Inspects the top item without removing it.

---

### Q6. What are stack overflow and stack underflow?

**Answer:**

1. **Stack Overflow:**
   - Occurs when an attempt is made to `push` an element onto a stack that has already reached its maximum capacity.
   - **Condition (Array of size `MAX`):** `top == MAX - 1`.
   - **Consequence:** Results in runtime error or crash (e.g., infinite recursion exhausting call stack memory).

2. **Stack Underflow:**
   - Occurs when an attempt is made to `pop` or `peek` from an empty stack.
   - **Condition:** `top == -1` (or `top == NULL` in a linked list implementation).
   - **Consequence:** Invalid memory access or returns error code indicating no data is available.

---

### Q7. What is a queue? Explain the FIFO principle.

**Answer:**
A **queue** is an abstract linear data structure that operates on two distinct ends:
- Elements are inserted at the **Rear** (Tail).
- Elements are removed from the **Front** (Head).

#### FIFO Principle (First-In, First-Out):
- **FIFO** dictates that the first element inserted into the queue is the first element to be removed.
- Elements are served in strict arrival order, guaranteeing fairness.
- **Analogy:** A line of customers at a ticket counter. The first person in line gets tickets first.
- **Key Operations:**
  - `enqueue(x)`: Inserts $x$ at Rear ($O(1)$).
  - `dequeue()`: Removes element from Front ($O(1)$).

---

### Q8. Write the four types of queues.

**Answer:**
The four fundamental types of queues in data structures are:
1. **Simple / Linear Queue:** Elements are added at the Rear and removed from the Front sequentially. Once Rear reaches the end, vacant spaces from earlier dequeues cannot be reused without shifting.
2. **Circular Queue:** The last position is logically connected back to the first position like a ring (`(rear + 1) % size`), eliminating space wastage of linear queues.
3. **Double-Ended Queue (Deque):** Insertion and deletion can take place from both ends (Front and Rear).
4. **Priority Queue:** Each element is assigned a priority; elements with higher priority are dequeued before lower-priority elements, regardless of arrival order.

---

### Q9. What is a priority queue?

**Answer:**
A **Priority Queue** is an advanced variant of a queue where each element possesses an associated **priority value**. 

#### Core Rules:
1. An element with **higher priority** is processed and dequeued before an element with lower priority.
2. If two elements share the same priority, they are typically processed according to their arrival order (FIFO).
3. **Types:**
   - **Min-Priority Queue:** Smallest numerical key has highest priority (e.g., Dijkstra's algorithm).
   - **Max-Priority Queue:** Largest numerical key has highest priority (e.g., OS CPU task scheduling).

---

### Q10. What is a deque?

**Answer:**
A **Deque** (pronounced *"deck"*, short for **Double-Ended Queue**) is a generalized linear data structure where elements can be inserted and deleted from **both ends** (Front and Rear).

#### Variations of Deque:
1. **Input-Restricted Deque:** Insertion is permitted at only one end (Rear), but deletion is allowed from both ends (Front and Rear).
2. **Output-Restricted Deque:** Deletion is permitted at only one end (Front), but insertion is allowed at both ends (Front and Rear).
- Common applications include sliding window problems, palindrome checkers, and browser history caching.

---

### Q11. What is a call stack?

**Answer:**
A **call stack** (execution stack / runtime stack) is a special stack data structure maintained automatically by the operating system/runtime environment to keep track of active subroutines, function calls, and execution flow.

#### How it Works:
1. When a function is invoked, an **Activation Record (Stack Frame)** containing function parameters, local variables, and return memory address is **pushed** onto the call stack.
2. When the function returns, its frame is **popped** off the stack, and execution resumes at the return address.
3. It natively powers nested function calls and **recursion**. Exceeding its bounded limit causes a `StackOverflowError`.

---

### Q12. Write three real-life applications of a stack.

**Answer:**
1. **Undo / Redo Mechanism in Software:** Text editors (e.g., Word, VS Code) push user actions onto an Undo stack; pressing Ctrl+Z pops the most recent action to restore prior state.
2. **Web Browser Navigation (Back / Forward Buttons):** Previously visited URLs are pushed onto a history stack. Clicking the "Back" button pops the current page and displays the previously pushed URL.
3. **Function Call / Recursion Management in Compilers:** Compilers track active function frames, return addresses, and scoped variables using the runtime call stack.

---

### Q13. Write three real-life applications of a queue.

**Answer:**
1. **CPU Task Scheduling & Process Management:** Operating systems use Ready Queues (e.g., Round Robin scheduling) to allocate CPU time slices to waiting processes fairly in FIFO order.
2. **Print Spooling:** When multiple print jobs are sent to a shared printer, they are held in a printer queue and printed in the exact order of receipt.
3. **Asynchronous Message Buffering:** Communication systems and message brokers (e.g., RabbitMQ, Kafka, network packet routers) store incoming packets in queues to handle traffic spikes smoothly.

---

### Q14. What are time complexity and space complexity?

**Answer:**

1. **Time Complexity:**
   - The quantified measure of the amount of computational time an algorithm takes to run as a function of the input size $n$.
   - Rather than measuring actual seconds (which depend on hardware), it quantifies the number of elementary operations executed.

2. **Space Complexity:**
   - The total amount of computer memory (RAM) required by an algorithm to execute to completion as a function of input size $n$.
   - It is calculated as:
     $$\text{Total Space} = \text{Fixed Space (Code & constants)} + \text{Variable / Auxiliary Space (Data inputs, variables, recursion stack)}$$

---

### Q15. Explain Big-O, Omega, and Theta notations.

**Answer:**
Asymptotic notations describe algorithm efficiency as input size $n \to \infty$:

1. **Big-O Notation ($O$ — Asymptotic Upper Bound / Worst Case):**
   - $f(n) = O(g(n))$ if there exist positive constants $c$ and $n_0$ such that:
     $$0 \le f(n) \le c \cdot g(n) \quad \text{for all } n \ge n_0$$
   - Represents the **guaranteed worst-case running time** (the algorithm will never take longer than this upper ceiling).

2. **Big-Omega Notation ($\Omega$ — Asymptotic Lower Bound / Best Case):**
   - $f(n) = \Omega(g(n))$ if there exist positive constants $c$ and $n_0$ such that:
     $$0 \le c \cdot g(n) \le f(n) \quad \text{for all } n \ge n_0$$
   - Represents the **best-case running time** (the algorithm will take at least this much time).

3. **Big-Theta Notation ($\Theta$ — Asymptotic Tight Bound / Average Case):**
   - $f(n) = \Theta(g(n))$ if there exist positive constants $c_1, c_2,$ and $n_0$ such that:
     $$c_1 \cdot g(n) \le f(n) \le c_2 \cdot g(n) \quad \text{for all } n \ge n_0$$
   - Bounds the function both from above and below, describing the **exact asymptotic growth rate**.
