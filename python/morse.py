lista = {".-": "a",
         "-...": "b",
         "-.-.": "c",
         "-..": "d",
         ".": "e",
         "..-.": "f",
         "--.": "g",
         "....": "h",
         "..": "i",
         ".---": "j",
         "-.-": "k",
         ".-..": "l",
         "--": "m",
         "-.": "n",
         "---": "o",
         ".--.": "p",
         "--.-": "q",
         ".-.": "r",
         "...": "s",
         "-": "t",
         "..-": "u",
         "...-": "v",
         ".--": "w",
         "-..-": "x",
         "-.--": "y",
         "--..": "z"}

morse = str(input("Digite o código morse:\n"))

char = 0

saida = ""

while char < len(morse):
    caractere = []
    espaco = False

    while char < len(morse) and morse[char] != "/":
        caractere.append(morse[char])
        char += 1
    
    if char < len(morse) and morse[char] == "/":
        if (char + 1) < len(morse) and morse[char + 1] == "/":
            espaco = True
            char += 2
        else:
            char += 1

    codigo = "".join(caractere)

    if codigo in lista:
        saida += lista[codigo]
        if espaco:
            saida += " "
    else:
        saida = "ERRO! Algum código está incorreto."
        break

print(f"Tradução:\n\"{saida}\"")
