class Suma2 ():
    def __init__(self):
        self.num1 = 0
        self.num2 = 0
    
    def suma(self):
        self.sum = 0
        for i in range(self.num2):
            self.sum = self.sum + int(str(self.num1) * (i + 1))
            n =+ 1 
        return self.sum
    
    def interfaz(self):
        self.num1 = int(input("Ingrese el numero a sumar:\n"))
        self.num2 = int(input("Ingrese la cantidad de veces que desee que se sume el numero:\n"))
        suma = self.suma()
        print ("La suma total es: ", suma)
if __name__ == "__main__":

    Suma = Suma2()
    Suma.interfaz()