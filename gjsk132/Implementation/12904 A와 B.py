target = input()
words = list(input())

for i in range(len(words)-len(target)):
    if (n := words.pop()) == 'B':
        words.reverse()

print(1 if target == "".join(words) else 0)