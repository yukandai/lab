class Suma():
    def __init__(self):
        self.n1 = 0 
    def suma(self):
        self.suma = self.n1 + int(str(self.n1) * 2) + int(str(self.n1) * 3)
        return self.suma
    def interfaz(self):
        self.n1 = int(input("Ingrese el numero a sumar:\n"))
        suma = self.suma()
        print ("La suma total es: ", suma)
if __name__ == "__main__":
    Suma = Suma()
    Suma.interfaz()