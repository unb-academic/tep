from enum import IntEnum
from itertools import combinations

N = int(input())

intervals: list[tuple[int, int]] = []

class EventType(IntEnum):
    START = 0
    END = 1

def count_intersections(intervals: list[tuple[int, int]]) -> int:
    events: list[tuple[int, EventType, int]] = []

    for idx, (a, b) in enumerate(intervals):
        events.append((a, EventType.START, idx))
        events.append((b, EventType.END, idx))

    events.sort()
    
    actives = set()
    res = 0

    for _, event_type, idx in events:
        if event_type == EventType.START:
            res += len(actives)
            actives.add(idx)
        else:
            actives.remove(idx)

    return res

for _ in range(N):
    a, b = map(int, input().split())
    intervals.append((a, b))

print(count_intersections(intervals))
