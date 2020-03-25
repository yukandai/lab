class Lista():
    def lista(self):
        lista = input("Ingrese la lista de numeros dividida por comas:\n ").split(",")
        for i in range(len(lista)): lista[i] = int(lista[i])
        lista.sort(reverse=True)
        print("Esta es la lista ordenada de manera descendente:\n", lista)

if __name__ == "__main__":
    Lista = Lista()
    Lista.lista()