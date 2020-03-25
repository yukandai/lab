
class Numero():

    def ingreso_por_teclado(self):
        ingreso = input("Ingrese un numero \n")
        return (ingreso)

    def sumar(self):
        num=self.ingreso_por_teclado()
        a = num
        b = (num*2)
        c = (num*3)
        print (int(a)+int(b)+int(c))

if __name__ == "__main__":
    u = Numero()
    u.sumar()


