#Ejercicio 5: Explicacion programa de sucesion de fibonacci
def fibo(n,a=0,b=1): 
#definimos la funcion fijando los parametros a=0 y b=1
    while n!=0:
        return fibo(n-1,b,a+b) 
        #llamamos nuevamente a la funcion pero decrementamos 
        #los parametros de n e una unidad y cambiamos los 
        # parametros de a por el de b y el de por a+b
    return a 
    #al terminar el bucle el valor de a 
    # (siendo que a=b excepto para n=0 que a=0) se devuelve 
    # el valor que corresponde a la sucesion de fibonacci

for i in range(0,10):
    print(fibo(i)) #llama a la funcion 10 veces
