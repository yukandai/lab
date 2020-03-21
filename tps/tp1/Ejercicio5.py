def fibo(n,a=0,b=1): #valores iniciales

    while n!=0: 
        return fibo(n-1,b,a+b) # n va de 1 a 9 
                               # Aplica la formula de Fibonacci
        # // a=b resultado anterio // b= a+b del resultado anterior
    return a                   
    
            
for i in range(0,10): #calcula la serie de fibonacci para n de 0 a 9
    print(fibo(i))