# Assignment 2 — Section B: 5 Marks (Short Answer / Algorithm)

---

## 📌 Part 1: Array Algorithms (Q1 to Q6)

---

### Q1. Write an algorithm to insert an element at a given position in an array. Show the shifting and state the complexity.

#### Algorithm:
```text
Algorithm INSERT_AT_POSITION(A, N, MAX_SIZE, POS, VALUE)
Input: 
  A: Array of elements
  N: Current number of elements
  MAX_SIZE: Maximum capacity of array
  POS: 0-based index where element is to be inserted (0 <= POS <= N)
  VALUE: Element to insert
Output: Updated array with N + 1 elements

1. If N >= MAX_SIZE then:
     Print "Array Overflow: Cannot insert"
     Return N
2. If POS < 0 or POS > N then:
     Print "Invalid Position"
     Return N
3. For i = N - 1 down to POS do:
     A[i + 1] = A[i]       // Shift element one position to the right
4. A[POS] = VALUE          // Insert new element
5. N = N + 1               // Increment total count
6. Return N
```

#### Shifting Diagram & Dry Run:
Let array $A = [10, 20, 30, 40]$, $N = 4$. Insert `VALUE = 25` at `POS = 2`:
```text
Initial Array:
Index:    0    1    2    3    4
Value:  [10] [20] [30] [40] [ ]

Step 1: Shift elements right from index 3 down to index 2:
Shift A[3] to A[4]: [10] [20] [30] [  ] [40]
Shift A[2] to A[3]: [10] [20] [  ] [30] [40]

Step 2: Place VALUE = 25 at index 2:
Final:              [10] [20] [25] [30] [40], N = 5
```

#### Complexity Analysis:
- **Best Case Time Complexity:** $O(1)$ (when inserting at end: $\text{POS} = N$, zero shifting).
- **Worst Case Time Complexity:** $O(N)$ (when inserting at beginning: $\text{POS} = 0$, all $N$ elements shift).
- **Average Time Complexity:** $O(N)$.
- **Space Complexity:** $O(1)$ (in-place auxiliary memory).

---

### Q2. Write an algorithm to delete the element at a given position. State the complexity.

#### Algorithm:
```text
Algorithm DELETE_AT_POSITION(A, N, POS)
Input: 
  A: Array of elements
  N: Current count of elements
  POS: 0-based index to delete (0 <= POS < N)
Output: Updated array with N - 1 elements and deleted value

1. If N <= 0 then:
     Print "Array Underflow: Array is empty"
     Return -1
2. If POS < 0 or POS >= N then:
     Print "Invalid Position"
     Return -1
3. DELETED_VAL = A[POS]
4. For i = POS to N - 2 do:
     A[i] = A[i + 1]       // Shift element one position to the left
5. N = N - 1               // Decrement total count
6. Return DELETED_VAL
```

#### Dry Run:
Let $A = [10, 20, 25, 30, 40]$, $N = 5$. Delete at `POS = 2` (`DELETED_VAL = 25`):
```text
Index:    0    1    2    3    4
Value:  [10] [20] [25] [30] [40]

Shift left:
A[2] = A[3]  -->  [10] [20] [30] [30] [40]
A[3] = A[4]  -->  [10] [20] [30] [40] [40]

Update N = 4:
Result Array:     [10] [20] [30] [40]
```

#### Complexity Analysis:
- **Best Case Time Complexity:** $O(1)$ (deleting last element $\text{POS} = N-1$, zero shifts).
- **Worst Case Time Complexity:** $O(N)$ (deleting first element $\text{POS} = 0$, $N-1$ shifts).
- **Space Complexity:** $O(1)$ auxiliary space.

---

### Q3. Write the algorithms for linear search and binary search and compare them.

#### 1. Linear Search Algorithm:
```text
Algorithm LINEAR_SEARCH(A, N, TARGET)
1. For i = 0 to N - 1 do:
     If A[i] == TARGET then:
       Return i    // Element found at index i
2. Return -1       // Element not found
```

#### 2. Binary Search Algorithm (Requires Sorted Array):
```text
Algorithm BINARY_SEARCH(A, N, TARGET)
1. LOW = 0, HIGH = N - 1
2. While LOW <= HIGH do:
     MID = LOW + (HIGH - LOW) / 2
     If A[MID] == TARGET then:
       Return MID
     Else if A[MID] < TARGET then:
       LOW = MID + 1
     Else:
       HIGH = MID - 1
3. Return -1       // Element not found
```

#### Comparison Table:

| Parameter | Linear Search | Binary Search |
| :--- | :--- | :--- |
| **Prerequisite** | Works on both sorted and unsorted arrays. | **Array MUST be sorted**. |
| **Strategy** | Sequential scan (Brute Force). | Divide and Conquer. |
| **Best Case Time** | $O(1)$ (element at index 0). | $O(1)$ (element at middle). |
| **Worst Case Time** | $O(N)$ | $O(\log_2 N)$ |
| **Average Case Time** | $O(N)$ | $O(\log_2 N)$ |
| **Space Complexity** | $O(1)$ | $O(1)$ iterative / $O(\log N)$ recursive. |

---

### Q4. Reverse an array in-place and state its complexity.

#### Two-Pointer Algorithm:
```text
Algorithm REVERSE_ARRAY_IN_PLACE(A, N)
1. LEFT = 0, RIGHT = N - 1
2. While LEFT < RIGHT do:
     // Swap A[LEFT] and A[RIGHT]
     TEMP = A[LEFT]
     A[LEFT] = A[RIGHT]
     A[RIGHT] = TEMP
     LEFT = LEFT + 1
     RIGHT = RIGHT - 1
3. Return A
```

#### Dry Run on `[1, 2, 3, 4, 5]`:
- Start: `LEFT = 0 (1)`, `RIGHT = 4 (5)` $\to$ Swap $\to$ `[5, 2, 3, 4, 1]`
- Next: `LEFT = 1 (2)`, `RIGHT = 3 (4)` $\to$ Swap $\to$ `[5, 4, 3, 2, 1]`
- Next: `LEFT = 2`, `RIGHT = 2` $\to$ `LEFT < RIGHT` is false $\to$ Terminate.

#### Complexity:
- **Time Complexity:** $O(N)$ (executes exactly $\lfloor N / 2 \rfloor$ swaps).
- **Space Complexity:** $O(1)$ (in-place modification, single temporary variable).

---

### Q5. Rotate an array by $k$ positions.

#### Reversal Algorithm (Rotate Right by $k$):
To rotate an array of size $N$ right by $k$ positions:
1. Normalize $k$: $k = k \pmod N$.
2. Reverse the entire array: `Reverse(A, 0, N - 1)`.
3. Reverse the first $k$ elements: `Reverse(A, 0, k - 1)`.
4. Reverse the remaining $N - k$ elements: `Reverse(A, k, N - 1)`.

#### Dry Run: Array `[1, 2, 3, 4, 5, 6, 7]`, $N = 7, k = 3$:
- Step 1: Reverse entire array $\to$ `[7, 6, 5, 4, 3, 2, 1]`
- Step 2: Reverse first $k=3$ elements $\to$ `[5, 6, 7, 4, 3, 2, 1]`
- Step 3: Reverse elements from index $3$ to $6$ $\to$ `[5, 6, 7, 1, 2, 3, 4]`

#### Complexity:
- **Time Complexity:** $O(N)$ (Three reversal passes: $N/2 + k/2 + (N-k)/2 = N$ swaps).
- **Space Complexity:** $O(1)$ auxiliary space.

---

### Q6. Write the address calculation formula for a 2D array (row-major / column-major) and solve one numerical.

#### Formulas:
Let array be declared as $A[LR \dots UR, \, LC \dots UC]$:
- $M = \text{Total rows} = (UR - LR + 1)$
- $N = \text{Total columns} = (UC - LC + 1)$
- $B = \text{Base Address}$
- $W = \text{Element size in bytes}$

1. **Row-Major Order Address:**
   $$\text{Address}(A[i][j]) = B + \big( (i - LR) \times N + (j - LC) \big) \times W$$
2. **Column-Major Order Address:**
   $$\text{Address}(A[i][j]) = B + \big( (j - LC) \times M + (i - LR) \big) \times W$$

#### Numerical Example:
**Question:** Given array $A[-2 \dots 3, \, 1 \dots 5]$ with Base Address $B = 1000$ and element size $W = 4$ bytes. Calculate the address of $A[1][3]$ in:
1. Row-major order
2. Column-major order

**Solution:**
- $LR = -2, \, UR = 3 \implies M = 3 - (-2) + 1 = 6$
- $LC = 1, \, UC = 5 \implies N = 5 - 1 + 1 = 5$
- Target: $i = 1, \, j = 3$
- Offset row: $(i - LR) = 1 - (-2) = 3$
- Offset col: $(j - LC) = 3 - 1 = 2$

1. **Row-Major Order:**
   $$\text{Address}(A[1][3]) = 1000 + (3 \times 5 + 2) \times 4 = 1000 + (17 \times 4) = 1000 + 68 = \mathbf{1068}$$

2. **Column-Major Order:**
   $$\text{Address}(A[1][3]) = 1000 + (2 \times 6 + 3) \times 4 = 1000 + (15 \times 4) = 1000 + 60 = \mathbf{1060}$$

---

## 📌 Part 2: Stack Algorithms (Q7 to Q11)

---

### Q7. Implement a stack using an array (`push`, `pop`, `peek`, `isEmpty`, `isFull`).

```c
#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

int isEmpty() { return top == -1; }
int isFull()  { return top == MAX - 1; }

void push(int x) {
    if (isFull()) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack[top--];
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack[top];
}
```
- **Time Complexity:** $O(1)$ for all operations (`push`, `pop`, `peek`, `isEmpty`, `isFull`).
- **Space Complexity:** $O(MAX)$ array space.

---

### Q8. Write push and pop using a linked list.

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;

void push(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Heap Overflow!\n");
        return;
    }
    newNode->data = val;
    newNode->next = top;
    top = newNode; // Insert at head
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return -1;
    }
    struct Node* temp = top;
    int poppedVal = temp->data;
    top = top->next;
    free(temp);
    return poppedVal;
}
```
- **Time Complexity:** $O(1)$ for both `push` and `pop`.
- **Space Complexity:** $O(N)$ dynamic node memory ($12$–$16$ bytes per node).

---

### Q9. Reverse a string using a stack.

#### Algorithm:
1. Initialize an empty character stack.
2. Traverse input string from left to right and `push` every character onto the stack.
3. Pop characters from the stack one by one and write them back to the string from index $0$ to $N-1$.
4. Return reversed string.

```c
#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int n = strlen(str);
    char stack[100];
    int top = -1;

    for (int i = 0; i < n; i++) stack[++top] = str[i];
    for (int i = 0; i < n; i++) str[i] = stack[top--];
}
```
- **Time Complexity:** $O(N)$ (One pass to push, one pass to pop).
- **Space Complexity:** $O(N)$ auxiliary stack space.

---

### Q10. Find the Next Greater Element (NGE) using a stack.

For each element in array $A$, the Next Greater Element is the first element to its right that is greater than it.

#### Algorithm ($O(N)$ Monotonic Stack):
```text
1. Initialize empty Stack S and result array NGE of size N.
2. Iterate i from N - 1 down to 0:
     a. While stack is not empty and S.top() <= A[i]:
          S.pop()
     b. If stack is empty:
          NGE[i] = -1
        Else:
          NGE[i] = S.top()
     c. S.push(A[i])
3. Return NGE
```

#### Dry Run: `A = [4, 5, 2, 25]`
- $i=3, A[3]=25$: Stack empty $\implies NGE[3] = -1$. Push 25. Stack: `[25]`.
- $i=2, A[2]=2$: Stack top is $25 > 2 \implies NGE[2] = 25$. Push 2. Stack: `[25, 2]`.
- $i=1, A[1]=5$: Pop 2 ($2 \le 5$). Top is $25 > 5 \implies NGE[1] = 25$. Push 5. Stack: `[25, 5]`.
- $i=0, A[0]=4$: Top is $5 > 4 \implies NGE[0] = 5$. Push 4. Stack: `[25, 5, 4]`.
- **Result:** `NGE = [5, 25, 25, -1]`.
- **Time Complexity:** $O(N)$ (Each element pushed and popped at most once).
- **Space Complexity:** $O(N)$ stack space.

---

### Q11. Min Stack: Implement `getMin()` in $O(1)$.

#### Approach (Two Stacks):
Use a primary stack for values and an auxiliary `minStack` tracking the minimum element at every depth.

```c
#include <stdio.h>
#define MAX 100

int mainStack[MAX], minStack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) return;
    top++;
    mainStack[top] = x;
    if (top == 0 || x <= minStack[top - 1])
        minStack[top] = x;
    else
        minStack[top] = minStack[top - 1];
}

int pop() {
    if (top == -1) return -1;
    return mainStack[top--];
}

int getMin() {
    if (top == -1) return -1;
    return minStack[top];
}
```
- **Time Complexity:** $O(1)$ for `push`, `pop`, `getMin`.
- **Space Complexity:** $O(N)$ auxiliary space.

---

## 📌 Part 3: Queue Algorithms (Q12 to Q16)

---

### Q12. Implement a queue using an array (`enqueue`, `dequeue`).

```c
#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int val = queue[front++];
    if (front > rear) front = rear = -1; // Reset
    return val;
}
```
- **Time Complexity:** $O(1)$ for `enqueue` and `dequeue`.
- **Space Complexity:** $O(MAX)$ array space.

---

### Q13. Implement a queue using a linked list.

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

int dequeue() {
    if (front == NULL) {
        printf("Queue Underflow!\n");
        return -1;
    }
    struct Node* temp = front;
    int val = temp->data;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
    return val;
}
```
- **Time Complexity:** $O(1)$ for both `enqueue` and `dequeue`.
- **Space Complexity:** $O(N)$ dynamic nodes.

---

### Q14. Deque operations (insert / delete from both ends).

```c
#define SIZE 5
int deque[SIZE], front = -1, rear = -1;

void insertFront(int x) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) return; // Full
    if (front == -1) front = rear = 0;
    else if (front == 0) front = SIZE - 1;
    else front--;
    deque[front] = x;
}

void insertRear(int x) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) return;
    if (front == -1) front = rear = 0;
    else if (rear == SIZE - 1) rear = 0;
    else rear++;
    deque[rear] = x;
}

int deleteFront() {
    if (front == -1) return -1; // Empty
    int val = deque[front];
    if (front == rear) front = rear = -1;
    else if (front == SIZE - 1) front = 0;
    else front++;
    return val;
}

int deleteRear() {
    if (front == -1) return -1;
    int val = deque[rear];
    if (front == rear) front = rear = -1;
    else if (rear == 0) rear = SIZE - 1;
    else rear--;
    return val;
}
```
- **Time Complexity:** $O(1)$ for all 4 operations.
- **Space Complexity:** $O(SIZE)$ array space.

---

### Q15. Reverse a queue with the help of a stack.

#### Algorithm:
1. Dequeue all elements from the queue one by one and push them onto an auxiliary stack until the queue is empty.
2. Pop all elements from the stack one by one and enqueue them back into the queue until the stack is empty.

#### Dry Run:
- Initial Queue (Front $\to$ Rear): `[10, 20, 30, 40]`
- Dequeue and Push:
  - Stack top $\to$ bottom: `[40, 30, 20, 10]`
- Pop and Enqueue:
  - Enqueue 40, 30, 20, 10
- Resulting Queue (Front $\to$ Rear): `[40, 30, 20, 10]`
- **Time Complexity:** $O(N)$ ($2N$ operations).
- **Space Complexity:** $O(N)$ auxiliary stack space.

---

### Q16. Generate binary numbers from 1 to $n$ using a queue.

#### Algorithm:
1. Create a queue of strings and enqueue `"1"`.
2. Run a loop $n$ times:
   - Dequeue front string $S$.
   - Print $S$.
   - Enqueue $S + "0"$.
   - Enqueue $S + "1"$.

#### Dry Run for $n = 5$:
- Enqueue `"1"`.
- $i=1$: Dequeue `"1"`, print `"1"`. Enqueue `"10"`, `"11"`. Queue: `["10", "11"]`
- $i=2$: Dequeue `"10"`, print `"10"`. Enqueue `"100"`, `"101"`. Queue: `["11", "100", "101"]`
- $i=3$: Dequeue `"11"`, print `"11"`. Enqueue `"110"`, `"111"`. Queue: `["100", "101", "110", "111"]`
- $i=4$: Dequeue `"100"`, print `"100"`.
- $i=5$: Dequeue `"101"`, print `"101"`.
- Output: `1, 10, 11, 100, 101`.
- **Time Complexity:** $O(n)$ string operations.
- **Space Complexity:** $O(n)$ queue memory.
