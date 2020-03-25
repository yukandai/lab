def fibo(n, a=0, b=1):
    while n != 0:
        return fibo(n - 1, b, a + b)
    return a


for i in range(0, 10):
    print(fibo(i))

"""
EXPLICACION

El for loop de la linea 7 corre al metodo fibo 10 veces, primero con n = 0 y
luego aumentandolo en uno cada vez.


En el primer loop de la linea 7 se corre el metodo fibo con n = 0,
por lo tanto, a y b toman sus valores predeterminados 0 y 1 respectivamente.
El metodo fibo, al ser n = 0, devuelve el valor de a, es decir, 0.


En el segundo loop, n es 1, por lo tanto, al correr el metodo fibo,
este se llama a si mismo con n = 0, a = 1 y b = a+b = 1. En esta segunda
llamada al metodo fibo, este devuelve el valor de a por que se lo llamo
con n = 0, por lo tanto, la llamada original del metodo fibo devuelve el
valor de a, que es 1.


En el tercer loop, se llama al metodo fibo con n = 2, lo que significa que
este devolvera el valor de a despues de haberse llamado a si mismo dos veces:

La primera vez se llamara a si mismo con n = 1, a = 1 y b = 1, lo que significa
que la condicion del while se vuelve a cumplir y se vuelve a llamar a si mismo
por segunda vez vez:

Aqui, no se cumple la condicion del while por q se llamo al metodo con n = 0,
a = 1 y b = 2, entonces se devuelve el valor de a, que es 1.


En el cuarto loop, se llama al metodo con n = 3, lo que significa que fibo se
llamara a si mismo 3 veces:

La primera vez se llama con n = 2, a = 1 y b = 1

La segunda vez se llama con n = 1, a = 1 y b = 2

la tercera vez se llama con n = 0, a = 2 y b = 3, por lo tanto, como n es 0,
se devuelve el valor de a, que es 2.

Este proceso se repite 10 veces, cada vez que se corre el metodo fibo, n indica
cuantas veces se llamara a si mismo, a tendra el valor de b y b sera la suma
de a y el nuevo valor de a, es decir, cada vez que se llama fibo a si mismo,
asigna a a la suma de su anterior valor mas su valor mas reciente, empezando
desde cero hasta el valor de n formando asi la serie de fibonacci.

"""
