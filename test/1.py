def obterPressaoDesejada():
    while True:
        try:
            pressaoDesejada = int(input("Digite a pressão desejada (entre 1 e 40): "))
            if 1 <= pressaoDesejada <= 40:
                return pressaoDesejada
            else:
                print("Por favor, digite um valor entre 1 e 40.")
        except ValueError:
            print("Por favor, digite um número inteiro válido.")


def obterPressaoAtual():
    while True:
        try:
            pressaoAtual = int(input("Digite a pressão atual (entre 1 e 40): "))
            if 1 <= pressaoAtual <= 40:
                return pressaoAtual
            else:
                print("Por favor, digite um valor entre 1 e 40.")
        except ValueError:
            print("Por favor, digite um número inteiro válido.")


pressaoDesejada = obterPressaoDesejada()
pressaoAtual = obterPressaoAtual()


if pressaoDesejada > pressaoAtual:
    diferenca = pressaoDesejada - pressaoAtual
elif pressaoAtual > pressaoDesejada:
    diferenca = pressaoAtual - pressaoDesejada
print(diferenca)
