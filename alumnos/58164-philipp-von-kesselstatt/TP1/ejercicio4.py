def ejercicio4(filepath):

    x = ""

    txt = open(filepath)

    enteros = txt.read()

    txt.close()

    enteros = enteros.split(",")

    enteros = [int(num) for num in enteros]

    for element in enteros:

        for num in range(element):

            x += "═"

        print(x)
        x = ""


# ejercicio4("/home/philipp/Git/file.txt")
