operation = int(
    input(
        "Pick an operation:\n\n1. Sum\n2. Subtraction\n3. Multiplications\n4. Division\n\n"
    )
)

x = float(input("x: "))
y = float(input("y: "))

match operation:
    case 1:
        print(x + y)
    case 2:
        print(x - y)
    case 3:
        print(x * y)
    case 4:
        if y != 0:
            print(x / y)
        else:
            print("Error: Division by zero")
    case _:
        print("Invalid operation")
