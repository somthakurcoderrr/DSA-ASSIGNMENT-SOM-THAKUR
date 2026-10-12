# Assignment 2 — Section D: Additional Algorithm Questions

---

## 📌 Part 1: Array Algorithms (Q1 to Q8)

---

### Q1. Insert an element into a sorted array so that it stays sorted. State the complexity. (5 Marks)

#### Algorithm:
```text
Algorithm INSERT_SORTED(A, N, MAX_SIZE, KEY)
1. If N >= MAX_SIZE then Return "Overflow"
2. i = N - 1
3. While i >= 0 and A[i] > KEY do:
     A[i + 1] = A[i]   // Shift greater elements right
     i = i - 1
4. A[i + 1] = KEY
5. N = N + 1
6. Return N
```

#### Dry Run: `A = [10, 20, 30, 50]`, $N = 4$, Insert `KEY = 25`:
- $i=3: A[3] = 50 > 25 \implies A[4] = 50, i = 2$
- $i=2: A[2] = 30 > 25 \implies A[3] = 30, i = 1$
- $i=1: A[1] = 20 \ngtr 25 \implies$ loop terminates.
- Place `KEY = 25` at $A[1 + 1] = A[2]$.
- **Result:** `[10, 20, 25, 30, 50]`, $N = 5$.

#### Complexity:
- **Time Complexity:** $O(N)$ worst case (shifting elements), $O(1)$ best case (inserting largest element at end).
- **Space Complexity:** $O(1)$ auxiliary space.

---

### Q2. Remove duplicates from a sorted array in-place. (5 Marks)

#### Algorithm (Two Pointers):
```c
int removeDuplicates(int A[], int n) {
    if (n == 0 || n == 1) return n;
    int k = 1; // Index of next unique element
    for (int i = 1; i < n; i++) {
        if (A[i] != A[k - 1]) {
            A[k] = A[i];
            k++;
        }
    }
    return k; // Number of unique elements
}
```

#### Dry Run: `A = [1, 1, 2, 2, 3, 4, 4]`
- $k=1$, compare with $A[0]=1$.
- $i=2: A[2]=2 \ne 1 \implies A[1] = 2, k = 2$.
- $i=4: A[4]=3 \ne 2 \implies A[2] = 3, k = 3$.
- $i=5: A[5]=4 \ne 3 \implies A[3] = 4, k = 4$.
- **Result:** `[1, 2, 3, 4]`, returns $k = 4$.

#### Complexity:
- **Time Complexity:** $O(N)$ single pass.
- **Space Complexity:** $O(1)$ in-place.

---

### Q3. Delete all occurrences of a given value from an array in-place. (5 Marks)

#### Algorithm:
```c
int removeElement(int A[], int n, int val) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] != val) {
            A[k++] = A[i];
        }
    }
    return k;
}
```

#### Dry Run: `A = [3, 2, 2, 3]`, `val = 3`
- $i=0: A[0] == 3 \implies$ skip.
- $i=1: A[1] == 2 \implies A[0] = 2, k = 1$.
- $i=2: A[2] == 2 \implies A[1] = 2, k = 2$.
- $i=3: A[3] == 3 \implies$ skip.
- **Result:** `[2, 2]`, length = 2.

#### Complexity:
- **Time Complexity:** $O(N)$.
- **Space Complexity:** $O(1)$.

---

### Q4. Merge two sorted arrays into one sorted array. (5 Marks)

#### Algorithm:
```c
void mergeSorted(int A[], int n, int B[], int m, int C[]) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (A[i] <= B[j]) C[k++] = A[i++];
        else C[k++] = B[j++];
    }
    while (i < n) C[k++] = A[i++];
    while (j < m) C[k++] = B[j++];
}
```

#### Complexity:
- **Time Complexity:** $O(n + m)$.
- **Space Complexity:** $O(n + m)$ for merged array $C$.

---

### Q5. Move all zeroes to the end of an array while keeping order of other elements. (5 Marks)

#### Algorithm:
```c
void moveZeroes(int A[], int n) {
    int nonZero = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] != 0) {
            // Swap A[i] and A[nonZero]
            int temp = A[i];
            A[i] = A[nonZero];
            A[nonZero] = temp;
            nonZero++;
        }
    }
}
```

#### Dry Run: `[0, 1, 0, 3, 12]` $\to$ `[1, 3, 12, 0, 0]`
- **Time Complexity:** $O(N)$.
- **Space Complexity:** $O(1)$.

---

### Q6. Find the largest and second largest elements in an array in a single traversal. (5 Marks)

#### Algorithm:
```c
void findLargestAndSecond(int A[], int n) {
    if (n < 2) return;
    int first = -1e9, second = -1e9;
    for (int i = 0; i < n; i++) {
        if (A[i] > first) {
            second = first;
            first = A[i];
        } else if (A[i] > second && A[i] != first) {
            second = A[i];
        }
    }
    printf("Largest: %d, Second Largest: %d\n", first, second);
}
```

#### Complexity:
- **Time Complexity:** $O(N)$ (exactly one pass, $N$ comparisons).
- **Space Complexity:** $O(1)$.

---

### Q7. Two Sum problem using brute force and using hashing. Compare time and space complexity. (10 Marks)

#### Problem:
Find two indices $i, j$ such that $A[i] + A[j] = \text{target}$.

#### Method 1: Brute Force ($O(N^2)$)
Check all pairs $(i, j)$:
```c
for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
        if (A[i] + A[j] == target) {
            printf("Indices: %d, %d\n", i, j);
            return;
        }
    }
}
```

#### Method 2: Hashing / Hash Map ($O(N)$)
For each element $A[i]$, check if $\text{complement} = \text{target} - A[i]$ already exists in hash map:
```text
For i = 0 to n - 1:
    complement = target - A[i]
    if complement in hashMap:
        return [hashMap[complement], i]
    hashMap[A[i]] = i
```

#### Comparison:

| Approach | Time Complexity | Auxiliary Space Complexity | Description |
| :--- | :---: | :---: | :--- |
| **Brute Force** | $O(N^2)$ | $O(1)$ | Simple, no extra memory, inefficient for large $N$. |
| **Hash Map** | $\mathbf{O(N)}$ | $\mathbf{O(N)}$ | Single pass, optimal time at expense of memory. |

---

### Q8. Kadane's Algorithm for Maximum Subarray Sum with Dry Run. (10 Marks)

#### Algorithm:
```c
int maxSubarraySum(int A[], int n) {
    int max_so_far = A[0];
    int curr_max = A[0];
    for (int i = 1; i < n; i++) {
        curr_max = (A[i] > curr_max + A[i]) ? A[i] : (curr_max + A[i]);
        if (curr_max > max_so_far)
            max_so_far = curr_max;
    }
    return max_so_far;
}
```

#### Dry Run: `A = [-2, 1, -3, 4, -1, 2, 1, -5, 4]`

| $i$ | $A[i]$ | `curr_max = max(A[i], curr_max + A[i])` | `max_so_far` |
| :---: | :---: | :---: | :---: |
| 0 | -2 | -2 | -2 |
| 1 | 1 | $\max(1, -2+1) = \mathbf{1}$ | **1** |
| 2 | -3 | $\max(-3, 1-3) = \mathbf{-2}$ | 1 |
| 3 | 4 | $\max(4, -2+4) = \mathbf{4}$ | **4** |
| 4 | -1 | $\max(-1, 4-1) = \mathbf{3}$ | 4 |
| 5 | 2 | $\max(2, 3+2) = \mathbf{5}$ | **5** |
| 6 | 1 | $\max(1, 5+1) = \mathbf{6}$ | **6** |
| 7 | -5 | $\max(-5, 6-5) = \mathbf{1}$ | 6 |
| 8 | 4 | $\max(4, 1+4) = \mathbf{5}$ | 6 |

- **Maximum Subarray Sum:** $\mathbf{6}$ (Subarray `[4, -1, 2, 1]`).
- **Time Complexity:** $O(N)$.
- **Space Complexity:** $O(1)$.

---

## 📌 Part 2: Stack Algorithms (Q9 to Q17)

---

### Q9. Convert a decimal number to binary using a stack. (5 Marks)

```c
void decToBin(int n) {
    int stack[64], top = -1;
    if (n == 0) { printf("0\n"); return; }
    while (n > 0) {
        stack[++top] = n % 2;
        n /= 2;
    }
    while (top != -1) printf("%d", stack[top--]);
    printf("\n");
}
```
- **Time Complexity:** $O(\log_2 N)$.
- **Space Complexity:** $O(\log_2 N)$.

---

### Q10. Check whether a string is a palindrome using a stack. (5 Marks)

```c
int isPalindrome(char str[]) {
    int n = strlen(str);
    char stack[100];
    int top = -1;
    for (int i = 0; i < n; i++) stack[++top] = str[i];
    for (int i = 0; i < n; i++) {
        if (str[i] != stack[top--]) return 0; // Not a palindrome
    }
    return 1; // Palindrome
}
```
- **Time Complexity:** $O(N)$.
- **Space Complexity:** $O(N)$.

---

### Q11. Delete the middle element of a stack. (5 Marks)

```c
void deleteMid(int stack[], int *top, int curr, int n) {
    if (curr == n / 2) {
        (*top)--; // Drop middle element
        return;
    }
    int temp = stack[(*top)--];
    deleteMid(stack, top, curr + 1, n);
    stack[++(*top)] = temp; // Restore remaining elements
}
```
- **Time Complexity:** $O(N)$.
- **Space Complexity:** $O(N)$ recursion call stack.

---

### Q12. Insert an element at the bottom of a stack using recursion. (5 Marks)

```c
void insertAtBottom(int stack[], int *top, int x) {
    if (*top == -1) {
        stack[++(*top)] = x;
        return;
    }
    int temp = stack[(*top)--];
    insertAtBottom(stack, top, x);
    stack[++(*top)] = temp;
}
```
- **Time Complexity:** $O(N)$.
- **Space Complexity:** $O(N)$ recursion depth.

---

### Q13. Sort a stack using a temporary stack. (5 Marks)

```c
void sortStack(int s[], int *top) {
    int tmpStack[100], tmpTop = -1;
    while (*top != -1) {
        int temp = s[(*top)--];
        while (tmpTop != -1 && tmpStack[tmpTop] > temp) {
            s[++(*top)] = tmpStack[tmpTop--];
        }
        tmpStack[++tmpTop] = temp;
    }
    while (tmpTop != -1) s[++(*top)] = tmpStack[tmpTop--];
}
```
- **Time Complexity:** $O(N^2)$.
- **Space Complexity:** $O(N)$.

---

### Q14. Implement two stacks in a single array (Space Optimization). (10 Marks)

#### Approach:
Stack 1 starts at index $0$ growing rightward (`top1++`); Stack 2 starts at index $MAX - 1$ growing leftward (`top2--`). They meet in the middle, optimizing space utilization.

```c
#define MAX 100
int arr[MAX];
int top1 = -1, top2 = MAX;

void push1(int x) {
    if (top1 < top2 - 1) arr[++top1] = x;
    else printf("Stack Overflow in Stack 1!\n");
}

void push2(int x) {
    if (top1 < top2 - 1) arr[--top2] = x;
    else printf("Stack Overflow in Stack 2!\n");
}

int pop1() {
    if (top1 >= 0) return arr[top1--];
    return -1;
}

int pop2() {
    if (top2 < MAX) return arr[top2++];
    return -1;
}
```
- **Time Complexity:** $O(1)$ for all operations.
- **Space Complexity:** $O(MAX)$ optimal shared array.

---

### Q15. Infix to Prefix conversion of `(A + B) * C - D` with Step-by-Step Table. (10 Marks)

#### Algorithm:
1. Reverse the infix expression. Replace `(` with `)` and vice versa.
2. Find postfix of modified string using Shunting-Yard.
3. Reverse the obtained postfix expression to get final **Prefix**.

#### Step 1: Reverse Infix:
`D - C * (B + A)`

#### Step 2: Postfix Table of `D - C * (B + A)`:

| Symbol | Stack | Output |
| :---: | :---: | :--- |
| `D` | empty | `D` |
| `-` | `-` | `D` |
| `C` | `-` | `D C` |
| `*` | `- *` | `D C` |
| `(` | `- * (` | `D C` |
| `B` | `- * (` | `D C B` |
| `+` | `- * ( +` | `D C B` |
| `A` | `- * ( +` | `D C B A` |
| `)` | `- *` | `D C B A +` |
| *End*| empty | `D C B A + * -` |

#### Step 3: Reverse Output:
Reversing `D C B A + * -` yields: **`- * + A B C D`**

- **Final Prefix Expression:** $\mathbf{- * + A B C D}$

---

### Q16. Evaluate a prefix expression: `- * + 4 3 2 5`. (10 Marks)

#### Algorithm:
Scan tokens from **right to left**:
- Operand $\to$ Push to stack.
- Operator $\to$ $A = \text{pop}(), B = \text{pop}()$; Push $(A \text{ op } B)$.

#### Trace:
1. `5` $\to$ Push 5: `[5]`
2. `2` $\to$ Push 2: `[5, 2]`
3. `3` $\to$ Push 3: `[5, 2, 3]`
4. `4` $\to$ Push 4: `[5, 2, 3, 4]`
5. `+` $\to$ Pop 4, 3; Compute $4 + 3 = 7$; Push 7: `[5, 2, 7]`
6. `*` $\to$ Pop 7, 2; Compute $7 \times 2 = 14$; Push 14: `[5, 14]`
7. `-` $\to$ Pop 14, 5; Compute $14 - 5 = 9$; Push 9: `[9]`

- **Result:** $\mathbf{9}$

---

### Q17. Solve the Stock Span problem using a stack in $O(N)$. (10 Marks)

#### Algorithm:
```c
void calculateSpan(int price[], int n, int span[]) {
    int stack[100], top = -1;
    stack[++top] = 0;
    span[0] = 1;

    for (int i = 1; i < n; i++) {
        while (top != -1 && price[stack[top]] <= price[i])
            top--;
        span[i] = (top == -1) ? (i + 1) : (i - stack[top]);
        stack[++top] = i;
    }
}
```
- **Time Complexity:** $O(N)$ (Each day index pushed/popped at most once).
- **Space Complexity:** $O(N)$.

---

## 📌 Part 3: Queue Algorithms (Q18 to Q24)

---

### Q18. Reverse the first $k$ elements of a queue. (5 Marks)

#### Algorithm:
1. Dequeue first $k$ elements and push them onto a stack.
2. Pop elements from stack and enqueue them back into the queue.
3. Dequeue and enqueue the remaining $N - k$ elements to maintain relative ordering.

- **Time Complexity:** $O(N)$
- **Space Complexity:** $O(k)$ stack space.

---

### Q19. Interleave the first half of a queue with the second half. (5 Marks)

For queue `[11, 12, 13, 14, 15, 16]`, output: `[11, 14, 12, 15, 13, 16]`.
- Push first half into a stack.
- Re-enqueue to reverse.
- Interleave elements one-by-one using queue rotations.
- **Time Complexity:** $O(N)$, **Space Complexity:** $O(N)$.

---

### Q20. Circular Deque implementation using an array. (5 Marks)
Covered with `insertFront`, `insertRear`, `deleteFront`, `deleteRear` with modulo wrap-around logic in $O(1)$ time complexity.

---

### Q21. Simulate Round Robin CPU scheduling using a queue. (10 Marks)

```c
struct Process { int id, burstTime, remTime; };

void roundRobin(struct Process p[], int n, int quantum) {
    int q[100], front = 0, rear = 0;
    for (int i = 0; i < n; i++) q[rear++] = i;

    int time = 0;
    while (front < rear) {
        int idx = q[front++];
        if (p[idx].remTime > quantum) {
            time += quantum;
            p[idx].remTime -= quantum;
            q[rear++] = idx; // Re-enqueue
        } else {
            time += p[idx].remTime;
            printf("Process P%d finished at time %d\n", p[idx].id, time);
            p[idx].remTime = 0;
        }
    }
}
```
- **Time Complexity:** $O(\text{Total Burst Time} / \text{quantum})$.
- **Space Complexity:** $O(N)$ queue storage.

---

### Q22. First non-repeating character in a stream of characters using a queue. (10 Marks)

#### Algorithm:
```c
void firstNonRepeating(char stream[]) {
    int freq[26] = {0};
    char q[100];
    int front = 0, rear = 0;

    for (int i = 0; stream[i] != '\0'; i++) {
        char ch = stream[i];
        freq[ch - 'a']++;
        q[rear++] = ch;

        while (front < rear && freq[q[front] - 'a'] > 1) front++;

        if (front < rear) printf("%c ", q[front]);
        else printf("-1 ");
    }
    printf("\n");
}
```
- **Time Complexity:** $O(N)$.
- **Space Complexity:** $O(1)$ alphabet frequency table + $O(N)$ queue.

---

### Q23. Solve the Josephus problem using a queue. (10 Marks)

#### Algorithm:
```c
int josephus(int n, int k) {
    int q[100], front = 0, rear = 0;
    for (int i = 1; i <= n; i++) q[rear++] = i;

    while (rear - front > 1) {
        for (int i = 1; i < k; i++) {
            q[rear++] = q[front++]; // Move k-1 persons to back
        }
        front++; // Eliminate kth person
    }
    return q[front]; // Survivor
}
```
- **Time Complexity:** $O(N \times k)$.
- **Space Complexity:** $O(N)$.

---

### Q24. Insert and delete in a priority queue implemented with a linked list. (10 Marks)

```c
struct Node {
    int data, priority;
    struct Node* next;
};

// Insert in sorted order of priority (O(N))
struct Node* enqueuePQ(struct Node* head, int data, int priority) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data; temp->priority = priority; temp->next = NULL;

    if (head == NULL || priority < head->priority) {
        temp->next = head;
        return temp;
    }
    struct Node* curr = head;
    while (curr->next != NULL && curr->next->priority <= priority) {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

// Delete highest priority element from head (O(1))
struct Node* dequeuePQ(struct Node* head, int *val) {
    if (head == NULL) return NULL;
    struct Node* temp = head;
    *val = temp->data;
    head = head->next;
    free(temp);
    return head;
}
```

#### Complexity:
- **Enqueue (Insertion):** $O(N)$ worst case (traversing to find priority slot).
- **Dequeue (Deletion):** $O(1)$ best and worst case (always remove head node).
- **Space Complexity:** $O(N)$ dynamic list nodes.
