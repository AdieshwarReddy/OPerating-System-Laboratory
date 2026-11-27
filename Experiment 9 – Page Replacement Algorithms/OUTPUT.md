# Experiment 9: Page Replacement Output

## Input Configuration

- Total Page References: 13
- Number of Frames: 3
- Reference String:

  7 0 1 2 0 3 0 4 2 3 0 3 2

## Program 1: FIFO

Total Page Faults: 10
Total Page Hits: 3
Page Fault Rate: 76.92%
Page Hit Rate: 23.08%

## Program 2: LRU

Total Page Faults: 9
Total Page Hits: 4
Page Fault Rate: 69.23%
Page Hit Rate: 30.77%

## Program 3: Optimal

Total Page Faults: 7
Total Page Hits: 6
Page Fault Rate: 53.85%
Page Hit Rate: 46.15%

## Step-by-Step Comparison

| Page | FIFO | LRU | Optimal |
|------|------|-----|---------|
| 7 | Fault | Fault | Fault |
| 0 | Fault | Fault | Fault |
| 1 | Fault | Fault | Fault |
| 2 | Fault | Fault | Fault |
| 0 | Hit | Hit | Hit |
| 3 | Fault | Fault | Fault |
| 0 | Fault | Hit | Hit |
| 4 | Fault | Fault | Fault |
| 2 | Fault | Fault | Hit |
| 3 | Fault | Fault | Hit |
| 0 | Fault | Fault | Fault |
| 3 | Hit | Hit | Hit |
| 2 | Hit | Hit | Hit |

## Performance Comparison

| Parameter | FIFO | LRU | Optimal |
|-----------|------|-----|---------|
| References | 13 | 13 | 13 |
| Frames | 3 | 3 | 3 |
| Page Faults | 10 | 9 | 7 |
| Page Hits | 3 | 4 | 6 |
| Fault Rate | 76.92% | 69.23% | 53.85% |
| Hit Rate | 23.08% | 30.77% | 46.15% |

## Observations

- FIFO replaces the oldest loaded page.
- LRU replaces the least recently accessed page.
- Optimal replaces the page needed farthest
  in the future.
- Optimal produces the minimum page faults
  for the given reference string.
- LRU performs better than FIFO for this input.
- Optimal requires knowledge of future references.

## Result

FIFO, LRU and Optimal page replacement algorithms
were implemented and compared successfully.
Optimal achieved the lowest page fault rate
for the given reference string.
