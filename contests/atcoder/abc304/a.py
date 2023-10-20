n = int(input())
people = []

for _ in range(n):
    a, b = input().split()
    people.append((a, int(b)))

youngest = min(people, key=lambda x: x[1])
index = people.index(youngest)

for _ in range(len(people)):
    print(people[index][0])
    index = (index + 1) % len(people)
