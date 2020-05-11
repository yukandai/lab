import os
os.system("clear")
cadena=input("\nIngrese la cadena separada por comas: ") #ingreso de la cadena a ordenar
cadena2='' #inicializamos una cadena vacia, para realizar el analisis
lista=[]  #inicializo lista 

for i in range(0,len(cadena)):
        if(cadena[i]!=','):
            cadena2=cadena2+cadena[i] #si no tengo una coma, entonces agrego el caracter leido a mi cadena2
        else:
            lista.append(int(cadena2)) #si tengo coma, almaceno el str generado en cadena2 como int
            cadena2='' #reinicio cadena 2, para generar el proximo str

lista.append(int(cadena2)) # guardo el ultimo str generado

lista.sort(reverse=True) #ordeno la lista en orden descendente
print("\nLa cadena ordenada es:",lista)
print()
