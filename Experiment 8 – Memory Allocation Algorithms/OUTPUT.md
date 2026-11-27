# Experiment 8: Memory Allocation Output

## Input Configuration

Number of Memory Blocks: 5
Number of Processes: 4

### Memory Block Sizes

| Block | Size (KB) |
|-------|-----------|
| B1 | 100 |
| B2 | 500 |
| B3 | 200 |
| B4 | 300 |
| B5 | 600 |

### Process Sizes

| Process | Size (KB) |
|---------|-----------|
| P1 | 212 |
| P2 | 417 |
| P3 | 112 |
| P4 | 426 |

## Program 1: First Fit

| Process | Size | Allocated Block |
|---------|------|-----------------|
| P1 | 212 | B2 |
| P2 | 417 | B5 |
| P3 | 112 | B2 |
| P4 | 426 | Not Allocated |

Processes Allocated: 3
Processes Not Allocated: 1

## Program 2: Best Fit

| Process | Size | Allocated Block |
|---------|------|-----------------|
| P1 | 212 | B4 |
| P2 | 417 | B2 |
| P3 | 112 | B3 |
| P4 | 426 | B5 |

Processes Allocated: 4
Processes Not Allocated: 0

## Program 3: Worst Fit

| Process | Size | Allocated Block |
|---------|------|-----------------|
| P1 | 212 | B5 |
| P2 | 417 | B2 |
| P3 | 112 | B5 |
| P4 | 426 | Not Allocated |

Processes Allocated: 3
Processes Not Allocated: 1

## Performance Comparison

| Parameter | First Fit | Best Fit | Worst Fit |
|-----------|-----------|----------|-----------|
| Total Processes | 4 | 4 | 4 |
| Allocated | 3 | 4 | 3 |
| Not Allocated | 1 | 0 | 1 |
| Allocation Rate | 75% | 100% | 75% |
| Used Memory (KB) | 741 | 1167 | 741 |
| Remaining Memory (KB) | 959 | 533 | 959 |

## Remaining Memory Blocks

| Block | First Fit | Best Fit | Worst Fit |
|-------|-----------|----------|-----------|
| B1 | 100 | 100 | 100 |
| B2 | 176 | 83 | 83 |
| B3 | 200 | 88 | 200 |
| B4 | 300 | 88 | 300 |
| B5 | 183 | 174 | 276 |

## Observations

- First Fit selects the first suitable block.
- Best Fit selects the smallest suitable block.
- Worst Fit selects the largest suitable block.
- Remaining block space can be reused.
- Best Fit allocated all four processes
  for the given input.
- Algorithm performance depends on the
  memory block sizes and process sizes.

## Result

First Fit, Best Fit and Worst Fit memory
allocation algorithms were implemented
and compared using C++.
