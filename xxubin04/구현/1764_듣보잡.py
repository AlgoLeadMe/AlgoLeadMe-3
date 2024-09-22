input = open(0).readline

N, M = map(int, input().split())
never_listen = set()
never_seen = set()

for n in range(N):
    never_listen.add(input().rstrip())

for m in range(M):
    never_seen.add(input().rstrip())

never_listen_seen = sorted(list(never_listen & never_seen))

print(len(never_listen_seen))

for i in never_listen_seen:
    print(i)