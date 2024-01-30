def pyramid(height):
    for i in range(0, height, +1):
        for j in range(height, i + 1, -1):
            print(" ", end="")
        for k in range(i + 1):
            print("#", end="")
        print()


height = 0
while height > 8 or height <= 0:
    height = int(input("height: "))

pyramid(height)
