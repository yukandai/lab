def fibo(n,a=0,b=1):
   
   while n!=0:
      return fibo(n-1,b,a+b)
   return a

for i in range(0,10):
   print(fibo(i))

#     En este caso, la serie de fibonacci se basa en sumar una sucesión de números (que comienza
# con a=0 y b=1), en el cual los números subsiguientes corresponde siempre a la suma de los 
# dos números anteriores. Y asi, si no establecemos un numero de fin de ciclo ("0,10"),
# esta sucesion seguira hasta el infinito.

#     El programa se basa en definir 3 variables:
# "a" y "b" con los dos primeros valores de la serie de fibonacci
# "n" como numero de fin de ciclo

#     Dicho bucle while permite repetir la ejecución de 
# instrucciones mientras se cumpla la condicion que "n" sea distinto a 0. Esta funcion utiliza
# la recursion ya que se devuelve a la funcion "fibo" el valor de "n-1",es decir cuantas veces
# debe llamarse a si misma dicha funcion. Ademas devuelve el valor "b" que sobrescribe el de "a",
# y el valor "a+b" que sobreescribe al de "b". El valor de n que inicialmente va aumentando
# en "1",es gracias al valor de "i",("fibo(i)"), que el bucle "for" utiliza para imprimir
# dichos valores.

#     El bucle for imprime 10 valores de la serie de fibonacci, gracias a las cotas inferior y 
# superior establecidas.
