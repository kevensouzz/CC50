def obterPrimeiraIdade():
    while True:
        primeiraIdade = int(input(""))
        if 5 <= primeiraIdade <= 100:
            return primeiraIdade
        else:
            print("")


def obterSegundaIdade():
    while True:
        segundaIdade = int(input(""))
        if 5 <= segundaIdade <= 100:
            return segundaIdade
        else:
            print("")


def obterTerceiraIdade():
    while True:
        terceiraIdade = int(input(""))
        if 5 <= terceiraIdade <= 100:
            return terceiraIdade
        else:
            print("")


PrimeiraIdade = obterPrimeiraIdade()
SegundaIdade = obterSegundaIdade()
TerceiraIdade = obterTerceiraIdade()

if PrimeiraIdade < SegundaIdade < TerceiraIdade:
    print(SegundaIdade)
elif SegundaIdade < PrimeiraIdade < TerceiraIdade:
    print(PrimeiraIdade)
elif PrimeiraIdade < TerceiraIdade < SegundaIdade:
    print(TerceiraIdade)
