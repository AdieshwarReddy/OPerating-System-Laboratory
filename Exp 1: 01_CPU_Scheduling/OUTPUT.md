# Experiment 1: Output and Performance Comparison

## Test Case 1

### Input

| Process | Burst Time | Priority |
|---------|------------|----------|
| P1 | 5 | 2 |
| P2 | 3 | 1 |
| P3 | 8 | 3 |

Time Quantum: 2

### FCFS Output

| Process | BT | WT | TAT | RT |
|---------|----|----|-----|----|
| P1 | 5 | 0 | 5 | 0 |
| P2 | 3 | 5 | 8 | 5 |
| P3 | 8 | 8 | 16 | 8 |

### SJN Output

| Process | BT | WT | TAT | RT |
|---------|----|----|-----|----|
| P2 | 3 | 0 | 3 | 0 |
| P1 | 5 | 3 | 8 | 3 |
| P3 | 8 | 8 | 16 | 8 |

### Round Robin Output

| Process | BT | WT | TAT | RT |
|---------|----|----|-----|----|
| P1 | 5 | 7 | 12 | 0 |
| P2 | 3 | 6 | 9 | 2 |
| P3 | 8 | 8 | 16 | 4 |

### Priority Scheduling Output

| Process | BT | PR | WT | TAT | RT |
|---------|----|----|----|-----|----|
| P2 | 3 | 1 | 0 | 3 | 0 |
| P1 | 5 | 2 | 3 | 8 | 3 |
| P3 | 8 | 3 | 8 | 16 | 8 |

### Performance Comparison

| Algorithm | Avg WT | Avg TAT | Avg RT |
|-----------|--------|---------|--------|
| FCFS | 4.33 | 9.67 | 4.33 |
| SJN | 3.67 | 9.00 | 3.67 |
| Round Robin | 7.00 | 12.33 | 2.00 |
| Priority | 3.67 | 9.00 | 3.67 |

## Test Case 2

### Input

| Process | Burst Time | Priority |
|---------|------------|----------|
| P1 | 4 | 1 |
| P2 | 2 | 3 |
| P3 | 6 | 2 |

Time Quantum: 2

### Performance Comparison

| Algorithm | Avg WT | Avg TAT | Avg RT |
|-----------|--------|---------|--------|
| FCFS | 3.33 | 7.33 | 3.33 |
| SJN | 2.67 | 6.67 | 2.67 |
| Round Robin | 4.00 | 8.00 | 2.00 |
| Priority | 4.67 | 8.67 | 4.67 |

## Observations

- FCFS is simple to implement.
- SJN reduces average waiting time.
- Round Robin provides better average response
  time for the given test cases.
- Priority Scheduling executes processes
  according to their assigned priorities.

## Abbreviations

- BT: Burst Time
- WT: Waiting Time
- TAT: Turnaround Time
- RT: Response Time
- PR: Priority

## Result

The four CPU scheduling algorithms were
implemented and their expected performance
metrics were compared using two test cases.
