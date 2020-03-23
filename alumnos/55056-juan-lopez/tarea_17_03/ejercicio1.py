
import sys

if (len(sys.argv) > 1):
    entrada=sys.argv[1]
    num=int(entrada)
    num1=entrada+entrada+entrada
    num2=entrada+entrada
    resultado = (int(num1) 
                + int(num2) 
                + num)
    salida = (entrada 
            + '+' 
            + num2 
            + '+' 
            + num1 
            + '=' 
            + str(resultado))
    print salida
    
else:
    print "Indicar numero para realizar la suma n+nn+nnn"


