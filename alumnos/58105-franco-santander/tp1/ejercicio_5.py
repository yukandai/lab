def fibo(n,a=0,b=1):                #Esta funcion realiza la serie de Fibonacci
   while n!=0:                      #Mientras que n sea distinto de cero se ejecuta el bucle
      return fibo(n-1,b,a+b)        #N disminuye en uno, 'a' toma el valor de 'b' y 'b' toma el valor de 'a+b'  
   return a                         #Luego la funcion nos devuelve el valor de 'a'

for i in range(0,10):               #Despues imprime los valores que devuelve la funcion a medida que se le va dando valores a 'n'
   print(fibo(i))                   #'n' tomara los valores desde el 0 hasta el 10,segun el range. Puede tomar otros valores si modificamos el range 