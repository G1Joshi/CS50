import cs50

h = cs50.get_int("Height: ")

if (h < 1 or h > 8):
    while (h < 1 or h > 8):
        h = cs50.get_int("Height: ")

for i in range(h):
    for j in range(h-1, i, -1):
        print(" ", end="")
    for j in range(i, -1, -1):
        print("#", end="")
    print("")
