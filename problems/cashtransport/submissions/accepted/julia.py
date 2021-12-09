N, M, K = [int(q) for q in input().split()]

values = [int(a) for a in input().split()]
A = []
B = []

for i in range(M):
    a, b = [int(q) for q in input().split()]
    A.append(a)
    B.append(b)
    values[b] += values[a]
    values[a] = 0

legal_transport = []
seen_before = set()

for i in range(M-1, -1, -1):
    if B[i] in seen_before:
        continue
    seen_before.add(A[i])
    legal_transport.append(values[A[i]])

legal_transport.sort()

print(sum(legal_transport[-K:]))
