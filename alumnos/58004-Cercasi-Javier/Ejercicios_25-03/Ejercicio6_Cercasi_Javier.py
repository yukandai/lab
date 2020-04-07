class Pedido:

    def __init__(self):
        self.numero= input("Ingrese numeros separados por comas:\n")
        self.lista=self.numero.split(sep=",")  
        self.lista_correcta=[]
    
    def chequeo(self):
        
        if not self.numero:
            print("No ingreso ningun numero")

        for i in range(len(self.lista)):
       
            try:
                n=int(self.lista[i])
                self.lista_correcta.append(n)

            except:
                print("Disculpe, solo acepto numeros")

        self.lista_correcta.sort(reverse=True)
        print("La lista ingresada es:",self.lista)
        print("\nLa lista de enteros correcta y ordenada es:",self.lista_correcta)  

if __name__ == "__main__":
    p = Pedido()
    p.chequeo()