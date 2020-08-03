s = 0
for i in range(1, 21):
    fact = 1
    for j in range(1, i + 1):
        fact = fact * j
    s = s + fact
print(s)