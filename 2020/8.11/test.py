import random

counter = 1
while counter <= 10000:
    counter = counter + 1
    n = 20
    m = random.randint(1, min(n * 10, 1000))
    print(m, n, sep = " ", end = " ")
    for i in range(n):
        track = random.randint(1, m)
        if i != 1:
            print(track, end = " ")
        else:
            print(31, end = " ")
    print(" ")    