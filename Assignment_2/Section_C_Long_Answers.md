# Assignment 2 — Section C: 10 Marks (Long Answer / Numerical)

---

### Q1. Infix to Postfix: Convert $A + B * (C - D) / E$ to postfix using a stack table. Also write the algorithm.

#### 1. Infix to Postfix Conversion Algorithm (Shunting-Yard):
```text
Algorithm INFIX_TO_POSTFIX(infix)
1. Initialize an empty character stack S and an empty output string postfix.
2. Define operator precedence:
     '^' -> 3
     '*', '/' -> 2
     '+', '-' -> 1
     '(' -> 0
3. For each token in infix from left to right:
     a. If token is an Operand (alphanumeric):
          Append token to postfix.
     b. Else if token is '(':
          Push '(' onto S.
     c. Else if token is ')':
          While S is not empty and S.top() != '(':
               Pop from S and append to postfix.
          Pop '(' from S.
     d. Else if token is an Operator (op):
          While S is not empty and precedence(S.top()) >= precedence(op):
               Pop from S and append to postfix.
          Push op onto S.
4. While S is not empty:
     Pop from S and append to postfix.
5. Return postfix.
```

#### 2. Conversion Table for $A + B * (C - D) / E$:

| Step | Symbol Scanned | Stack Content (Bottom $\to$ Top) | Postfix Expression Output | Action Taken |
| :---: | :---: | :---: | :---: | :--- |
| **1** | `A` | *(empty)* | `A` | Operand $\to$ append to output |
| **2** | `+` | `+` | `A` | Operator $\to$ push to stack |
| **3** | `B` | `+` | `A B` | Operand $\to$ append to output |
| **4** | `*` | `+ *` | `A B` | `*` has higher precedence than `+` $\to$ push |
| **5** | `(` | `+ * (` | `A B` | Left parenthesis $\to$ push |
| **6** | `C` | `+ * (` | `A B C` | Operand $\to$ append to output |
| **7** | `-` | `+ * ( -` | `A B C` | Inside `(`, push `-` |
| **8** | `D` | `+ * ( -` | `A B C D` | Operand $\to$ append to output |
| **9** | `)` | `+ *` | `A B C D -` | Right paren $\to$ pop until `(`, discard `(` |
| **10** | `/` | `+ /` | `A B C D - *` | `/` has equal precedence to `*` $\to$ pop `*`, push `/` |
| **11** | `E` | `+ /` | `A B C D - * E` | Operand $\to$ append to output |
| **End** | *EOL* | *(empty)* | `A B C D - * E / +` | Pop remaining operators: `/` then `+` |

**Final Postfix Expression:** $\mathbf{ABCD-*E/+}$

- **Time Complexity:** $O(N)$ (each token pushed/popped at most once).
- **Space Complexity:** $O(N)$ stack space.

---

### Q2. Postfix Evaluation: Evaluate `5 3 2 * + 4 -` and show the stack step by step.

#### Algorithm:
1. Scan the postfix tokens from left to right.
2. If the token is an **operand**, push its numerical value onto the stack.
3. If the token is an **operator** `op`:
   - Pop operand 2: $B = \text{pop}()$
   - Pop operand 1: $A = \text{pop}()$
   - Compute result: $R = A \text{ op } B$
   - Push $R$ back onto the stack.
4. At the end, the stack contains exactly one element: the final evaluated result.

#### Step-by-Step Stack Trace:

| Step | Symbol Scanned | Action Performed | Stack (Bottom $\to$ Top) |
| :---: | :---: | :--- | :--- |
| **1** | `5` | Operand $\to$ Push `5` | `[5]` |
| **2** | `3` | Operand $\to$ Push `3` | `[5, 3]` |
| **3** | `2` | Operand $\to$ Push `2` | `[5, 3, 2]` |
| **4** | `*` | Operator $\to$ Pop $2, 3$; Compute $3 \times 2 = 6$; Push `6` | `[5, 6]` |
| **5** | `+` | Operator $\to$ Pop $6, 5$; Compute $5 + 6 = 11$; Push `11` | `[11]` |
| **6** | `4` | Operand $\to$ Push `4` | `[11, 4]` |
| **7** | `-` | Operator $\to$ Pop $4, 11$; Compute $11 - 4 = 7$; Push `7` | `[7]` |
| **End** | *EOL* | Pop final result | **Result = 7** |

**Final Evaluated Answer:** $\mathbf{7}$

- **Time Complexity:** $O(N)$ single pass.
- **Space Complexity:** $O(N)$ stack size.

---

### Q3. Circular Queue: Full Implementation, Modulo Logic, and Empty/Full Conditions.

#### Why Circular Queue?
In a standard linear queue, once `rear == SIZE - 1`, no more elements can be inserted even if `front` has advanced and memory at indices $0, 1, \dots$ is vacant (false overflow). Circular queues resolve this by wrapping indices around to $0$ using modulo arithmetic: $\text{next} = (\text{index} + 1) \pmod{\text{SIZE}}$.

#### State Conditions:
- **Empty Condition:** `front == -1`
- **Full Condition:** `(rear + 1) % SIZE == front`

#### Full C Implementation:
```c
#include <stdio.h>
#define SIZE 5

int cqueue[SIZE];
int front = -1, rear = -1;

int isEmpty() { return front == -1; }
int isFull()  { return (rear + 1) % SIZE == front; }

void enqueue(int val) {
    if (isFull()) {
        printf("Circular Queue Overflow!\n");
        return;
    }
    if (isEmpty()) front = rear = 0;
    else rear = (rear + 1) % SIZE;
    cqueue[rear] = val;
}

int dequeue() {
    if (isEmpty()) {
        printf("Circular Queue Underflow!\n");
        return -1;
    }
    int val = cqueue[front];
    if (front == rear) front = rear = -1; // Queue becomes empty
    else front = (front + 1) % SIZE;
    return val;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    int i = front;
    printf("Queue elements: ");
    while (1) {
        printf("%d ", cqueue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
```
- **Enqueue Time Complexity:** $O(1)$
- **Dequeue Time Complexity:** $O(1)$
- **Space Complexity:** $O(\text{SIZE})$

---

### Q4. Implement a Queue using Two Stacks and analyze the complexity of both operations.

#### Concept:
We use two stacks: `s1` (input stack) and `s2` (output stack).
- **Enqueue:** Push directly onto `s1`.
- **Dequeue:** If `s2` is empty, transfer all elements from `s1` to `s2` (which reverses their order to FIFO). Then pop from `s2`.

```c
#include <stdio.h>
#define MAX 100

int s1[MAX], s2[MAX];
int top1 = -1, top2 = -1;

void push1(int x) { s1[++top1] = x; }
int pop1() { return s1[top1--]; }
void push2(int x) { s2[++top2] = x; }
int pop2() { return s2[top2--]; }

void enqueue(int x) {
    if (top1 == MAX - 1) { printf("Overflow!\n"); return; }
    push1(x);
}

int dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue Underflow!\n");
        return -1;
    }
    if (top2 == -1) {
        while (top1 != -1) {
            push2(pop1());
        }
    }
    return pop2();
}
```

#### Complexity Analysis:
- **Enqueue:** Always $O(1)$.
- **Dequeue:**
  - Worst case: $O(N)$ (when `s2` is empty and $N$ items transfer from `s1` to `s2`).
  - **Amortized Time Complexity:** $O(1)$ (each item is pushed to `s1`, popped from `s1`, pushed to `s2`, and popped from `s2` exactly once).
- **Space Complexity:** $O(N)$ total elements stored.

---

### Q5. Implement a Stack using Two Queues and analyze the complexity of push and pop.

#### Approach (Making Push Costly):
Maintain two queues: `q1` and `q2`.
- **Push ($x$):**
  1. Enqueue $x$ into `q2`.
  2. Dequeue all elements from `q1` one by one and enqueue them into `q2`.
  3. Swap names of `q1` and `q2`.
- **Pop():**
  - Simply dequeue from `q1`.

```c
// Pseudocode Logic
void push(int x) {
    enqueue(q2, x);
    while (!isEmpty(q1)) {
        enqueue(q2, dequeue(q1));
    }
    swap(q1, q2);
}

int pop() {
    if (isEmpty(q1)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return dequeue(q1);
}
```

#### Complexity Analysis:
- **Push Time Complexity:** $O(N)$ (shifts all $N-1$ elements to maintain LIFO ordering).
- **Pop Time Complexity:** $O(1)$ (direct dequeue from front of `q1`).
- **Space Complexity:** $O(N)$ queue storage.

---

### Q6. Balanced Parentheses Algorithm and Dry Run on `{[()]}` and `{[(])}`.

#### Algorithm:
```text
Algorithm CHECK_BALANCED_PARENTHESES(expression)
1. Initialize empty character stack S.
2. For each char c in expression:
     a. If c is '(', '{', or '[':
          Push c onto S.
     b. Else if c is ')', '}', or ']':
          If S is empty -> Return False (Unmatched closing)
          topChar = S.pop()
          If (c == ')' and topChar != '(') or
             (c == '}' and topChar != '{') or
             (c == ']' and topChar != '['):
               Return False (Mismatched pair)
3. Return (S is empty)   // True if balanced, False if unclosed brackets remain
```

#### Dry Run 1: `{[()]}` (Valid):
1. `{` $\to$ Push `{`. Stack: `['{']`
2. `[` $\to$ Push `[`. Stack: `['{', '[']`
3. `(` $\to$ Push `(`. Stack: `['{', '[', '(']`
4. `)` $\to$ Pop `(`. Matches `)` $\checkmark$. Stack: `['{', '[']`
5. `]` $\to$ Pop `[`. Matches `]` $\checkmark$. Stack: `['{']`
6. `}` $\to$ Pop `{`. Matches `}` $\checkmark$. Stack: `[]`
7. End of string, stack is empty $\implies$ **BALANCED (Valid)**.

#### Dry Run 2: `{[(])}` (Invalid):
1. `{` $\to$ Push `{`. Stack: `['{']`
2. `[` $\to$ Push `[`. Stack: `['{', '[']`
3. `(` $\to$ Push `(`. Stack: `['{', '[', '(']`
4. `]` $\to$ Closing `]`, but top is `(`. **Mismatch!** $\implies$ **UNBALANCED (Invalid)**.

- **Time Complexity:** $O(N)$ single pass.
- **Space Complexity:** $O(N)$ worst-case stack depth.

---

### Q7. Explain the applications of a stack (Recursion, Undo/Redo, Expression Evaluation, Backtracking).

1. **Recursion:**
   - Every recursive invocation pauses the current function state and pushes a new activation frame (parameters, local variables, return address) onto the system **call stack**. Base cases trigger unwinding by popping frames in reverse order.
2. **Undo / Redo Operations:**
   - Used in editors, graphics suites, and browser navigation. State snapshots are pushed to an Undo stack. Pressing undo pops the latest state and pushes it to a Redo stack.
3. **Expression Evaluation & Syntax Parsing:**
   - Compilers convert high-level human arithmetic (infix) to postfix/prefix and evaluate expressions using stacks in $O(N)$ time with zero ambiguity regarding operator precedence.
4. **Backtracking Algorithms:**
   - Used in maze solving, N-Queens problem, Depth-First Search (DFS) on graphs, and game decision trees. Decisions are pushed as steps are explored; if a dead end is reached, steps are popped to backtrack to the most recent viable choice point.

---

### Q8. Complexity Comparison Table of Array, Stack, and Queue & When to Use Which.

| Data Structure | Access | Search | Insert (Beginning) | Insert (End) | Delete (Beginning) | Delete (End) | Space Complexity |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Array** | $O(1)$ | $O(N)$ | $O(N)$ | $O(1)$ | $O(N)$ | $O(1)$ | $O(N)$ |
| **Stack** | $O(N)$ | $O(N)$ | $O(1)$ (Top) | $O(1)$ (Top) | $O(1)$ (Top) | $O(1)$ (Top) | $O(N)$ |
| **Queue (Linear)** | $O(N)$ | $O(N)$ | N/A | $O(1)$ (Rear) | $O(1)$ (Front) | N/A | $O(N)$ |
| **Circular Queue** | $O(N)$ | $O(N)$ | N/A | $O(1)$ (Rear) | $O(1)$ (Front) | N/A | $O(N)$ |
| **Deque** | $O(N)$ | $O(N)$ | $O(1)$ (Front) | $O(1)$ (Rear) | $O(1)$ (Front) | $O(1)$ (Rear) | $O(N)$ |

#### When to Use Which:
- **Array:** When fast random access via index ($O(1)$) is essential and size is relatively fixed.
- **Stack:** When operations must strictly follow Last-In-First-Out (LIFO), such as syntax matching, expression parsing, function recursion, or undo history.
- **Queue:** When operations must follow First-In-First-Out (FIFO) fairness, such as task scheduling, print spooling, and Breadth-First Search (BFS).

---

### Q9. Priority Queue: Array vs Heap Implementation with Insertion/Deletion Complexity.

#### Comparison:

| Parameter | Unsorted Array | Sorted Array | Binary Heap (Min/Max Heap) |
| :--- | :---: | :---: | :---: |
| **Insert** | $O(1)$ (append at end) | $O(N)$ (find position & shift) | $\mathbf{O(\log N)}$ (heapify-up) |
| **Delete-Max/Min** | $O(N)$ (scan for extreme) | $O(1)$ (remove from end/front) | $\mathbf{O(\log N)}$ (heapify-down) |
| **Peek Max/Min** | $O(N)$ | $O(1)$ | $\mathbf{O(1)}$ (root element) |
| **Building Queue** | $O(N)$ | $O(N \log N)$ | $\mathbf{O(N)}$ (bottom-up build) |

#### Rationale:
Binary heaps strike the ideal trade-off: both insertion and deletion take guaranteed **$O(\log N)$** logarithmic time, outperforming arrays for frequent interleaved insertions and deletions.

---

### Q10. Solve Sliding Window Maximum using a Deque in $O(N)$.

#### Problem:
Given an array `nums` and window size $k$, find the maximum value in every sliding window of size $k$ as the window slides from left to right.

#### Algorithm ($O(N)$ Monotonic Deque):
Store **indices** in a deque such that elements corresponding to these indices are in strictly **monotonically decreasing** order.

```text
Algorithm SLIDING_WINDOW_MAX(nums, n, k)
1. Initialize empty Deque DQ.
2. For i = 0 to n - 1:
     a. Remove indices from front if they are out of current window:
        While DQ is not empty and DQ.front() <= i - k:
            DQ.pop_front()
     b. Remove indices from back whose values are <= nums[i]:
        While DQ is not empty and nums[DQ.back()] <= nums[i]:
            DQ.pop_back()
     c. DQ.push_back(i)
     d. If i >= k - 1:
        Window maximum is nums[DQ.front()]
```

#### Dry Run: `nums = [1, 3, -1, -3, 5, 3, 6, 7]`, $k = 3$
- $i=0 (1)$: DQ = `[0]`
- $i=1 (3)$: Pop index 0 ($1 \le 3$). DQ = `[1]`
- $i=2 (-1)$: DQ = `[1, 2]`. $i \ge 2 \implies \mathbf{\max = nums[1] = 3}$.
- $i=3 (-3)$: DQ = `[1, 2, 3]`. $\mathbf{\max = nums[1] = 3}$.
- $i=4 (5)$: Remove index 1 ($1 \le 4-3$). Pop indices 2, 3 ($< 5$). DQ = `[4]`. $\mathbf{\max = nums[4] = 5}$.
- $i=5 (3)$: DQ = `[4, 5]`. $\mathbf{\max = nums[4] = 5}$.
- $i=6 (6)$: Pop indices 4, 5 ($< 6$). DQ = `[6]`. $\mathbf{\max = nums[6] = 6}$.
- $i=7 (7)$: Pop index 6 ($< 7$). DQ = `[7]`. $\mathbf{\max = nums[7] = 7}$.
- **Output:** `[3, 3, 5, 5, 6, 7]`

#### Complexity:
- **Time Complexity:** $O(N)$ (Each index is pushed and popped at most once).
- **Space Complexity:** $O(k)$ auxiliary space for the deque.
