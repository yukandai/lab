import os
os.system("clear")
def fibo(n,a=0,b=1): #valores iniciales por defecto de la serie para n=0
   while n!=0:
      return fibo(n-1,b,a+b)
      #* n de 1 a 9 aplico la formulo de serie fibonacci donde:
      #* a=b anterior // b= a+b anterior // n=n-1 
   return a # cuando n=0 -> devuelvo a

for i in range(0,10): #calculo la serie de fibonacci para n de 0 a 9
   print(fibo(i))