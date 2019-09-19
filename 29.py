
powers_set = set()

for x in range(2, 101):
    beginning = x
    for y in range(99):
        beginning = beginning * x
        powers_set.add(beginning)

print(len(powers_set))
