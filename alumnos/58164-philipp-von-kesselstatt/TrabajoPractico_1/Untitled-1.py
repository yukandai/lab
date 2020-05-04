import os


path = __file__.replace("Untitled-1.py", "")

size = os.path.getsize(path + "dog.ppm")
p = open(path + "dog.ppm", "rb")


imagen = b""
for i in range(size + 1):
    if i == 14:
        imagen += b"\n# holas"

    imagen += p.read(1)


for num in range(imagen.count(b"\n# ")):
    comment_start = imagen.find(b"\n# ")
    comment_end = imagen.find(b"\n", comment_start + 1)
    imagen = imagen.replace(imagen[comment_start:comment_end], b"")

print(imagen.count(b"\n# "))
print(comment_start, comment_end)
print(imagen[:60])

x = open(path + "probando_1.ppm", "wb", os.O_CREAT)
x.write(imagen)
x.close()
