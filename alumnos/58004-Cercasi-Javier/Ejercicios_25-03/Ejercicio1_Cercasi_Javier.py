class Pedido:

    def __init__(self):
        self.numero= input("Ingrese un numero:\n")

    def chequeo(self):

        if not self.numero:
            print("No ingreso ninguna palabra")

        try:
            n=int(self.numero)
            print (n+int(2*str(n))+int(3*str(n)))

        except:
            print("Disculpe, solo acepto numeros")

if __name__ == "__main__":
    p = Pedido()
    p.chequeo()