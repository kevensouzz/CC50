def obterNumeroDePremiados():
    while True:
        numeroDePremiados = int(input(""))
        if 1 <= numeroDePremiados <= 5:
            return numeroDePremiados
        else:
            print("")


def obterTamanhosSolicitados():
    while True:
        entrada = input("")
        string = entrada.split()
        tamanhosSolicitados = [int(numero) for numero in string]
        if len(tamanhosSolicitados) == numeroDePremiados:
            return tamanhosSolicitados
        else:
            print("")


def obterPequenasProduzidas():
    while True:
        pequenasProduzidas = int(input(""))
        if pequenasProduzidas <= len(tamanhosSolicitados):
            return pequenasProduzidas
        else:
            print("")


def obterMediasProduzidas():
    while True:
        mediasProduzidas = int(input(""))
        if mediasProduzidas <= len(tamanhosSolicitados):
            return mediasProduzidas
        else:
            print("")


numeroDePremiados = obterNumeroDePremiados()
tamanhosSolicitados = obterTamanhosSolicitados()
pequenasProduzidas = obterPequenasProduzidas()
mediasProduzidas = obterMediasProduzidas()

p = 0
m = 0

for num in tamanhosSolicitados:
    if num == 1:
        p += 1
    elif num == 2:
        m += 1

if pequenasProduzidas == p and mediasProduzidas == m:
    print("S")
else:
    print("N")