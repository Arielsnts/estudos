def formatar(num):
    return f"{num[:2]} {num[2:7]}-{num[7:]}"


print("~~ Agenda de Contatos ~~")
print("--------------------")
print("1 - Cadastrar contato\n2 - Procurar contato\n3 - Remover contato\n4 - Sair")
print("--------------------")

agenda = {}

while True:
    escolha = int(input("\nDigite a opção: "))

    if escolha < 1 or escolha > 4:
        print("\nOpção inválida! Digite novamente.")
        continue
    elif escolha == 4:
        break

    if escolha == 1:
        nome = str(input("\nDigite o nome do contato: "))
        while True:
            numero = str(input("Digite o número do contato: "))
            if len(numero) != 11:
                print("Número inválido! Digite um número com 11 caracteres!")
            else: break

        agenda[nome] = numero
    elif escolha == 2:
        nome = str(input("\nDigite o nome do contato: "))

        if nome in agenda:
            print("\n--------------------")
            print(f"Nome: {nome}\nNúmero: {formatar(agenda[nome])}")
            print("--------------------")
        else: 
            print("\n--------------------")
            print("Contato não encontrado")
            print("--------------------")

    elif escolha == 3:
        nome = str(input("\nDigite o nome do contato: "))
        if nome in agenda:
            del agenda[nome]
            print("\n--------------------")
            print("Contato excluído!")
            print("--------------------")
        else: 
            print("\n--------------------")
            print("Contato não encontrado")
            print("--------------------")