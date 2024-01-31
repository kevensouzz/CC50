from decimal import Decimal, getcontext


def calc(change_owed):
    coins_needed = 0
    coins = [Decimal("0.25"), Decimal("0.10"), Decimal("0.05"), Decimal("0.01")]

    for coin in coins:
        while change_owed >= coin:
            change_owed -= coin
            coins_needed += 1

    print(f"{coins_needed} coins were needed!")


def get_change_owed(prompt):
    while True:
        value = Decimal(input(prompt))
        if value > 0:
            return value
        else:
            print("Please enter a positive value.")


change_owed = get_change_owed("Enter the change owed: ")
calc(change_owed)
