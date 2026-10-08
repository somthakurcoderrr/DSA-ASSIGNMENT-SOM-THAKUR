# DSA Assignment - Queue Programming Questions in C

This repository contains the complete C-language implementation for the queue assignment questions:

1. Linear Queue
2. Circular Queue
3. Deque
4. Priority Queue

Each program is implemented as a separate C file and can be compiled using GCC.

## Files

- `linear_queue.c` - Linear Queue using array
- `circular_queue.c` - Circular Queue using array
- `deque.c` - Double Ended Queue (Deque) using array
- `priority_queue.c` - Priority Queue using array

## Compile and Run

```bash
gcc linear_queue.c -o linear_queue
./linear_queue
```

```bash
gcc circular_queue.c -o circular_queue
./circular_queue
```

```bash
gcc deque.c -o deque
./deque
```

```bash
gcc priority_queue.c -o priority_queue
./priority_queue
```

## Assignment Notes

- Linear Queue: FIFO order
- Circular Queue: wrap-around array logic
- Deque: insertion and deletion from both ends
- Priority Queue: elements are served in priority order (lower number = higher priority)

This project is prepared for college DSA assignment submission.
