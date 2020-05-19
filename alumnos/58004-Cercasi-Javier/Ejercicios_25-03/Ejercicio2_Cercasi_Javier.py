class Pedido:

    def __init__(self):
        self.numero= input("Ingrese un numero:\n")
        self.numero2= input("Ingrese la cantidad de veces a repetir el numero:\n")

    def chequeo(self):

        if not self.numero:
            print("No ingreso ninguna palabra")

        try:
            n=int(self.numero)
            m=0
            for i in range(int(self.numero2)):
                m = m + int((i+1)*str(n))
            print (m)

        except:
            print("Disculpe, solo acepto numeros")

if __name__ == "__main__":
    p = Pedido()
    p.chequeo()