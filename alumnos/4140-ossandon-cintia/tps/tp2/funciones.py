#!/usr/bin/python3

## TP2 - Cintia Ossandon

import os
import sys
import array
import threading
import time
import tp2

sem = threading.Semaphore(1)

def process_red(offset, interleave, l_message, message):
    # recorro el mensaje para ir guardando las letras en el PIXEL rojo
    my_message = []
    for m in range(0, len(message),3):
        my_message.append(m)

    msg = ""
    while msg != "DONE":
        sem.acquire()
        global content
        content = content
        sem.release()
        msg = content

def process_green(offset, interleave, l_message, message):
    # recorro el mensaje para ir guardando las letras en el PIXEL rojo
    my_message = []
    for m in range(1, len(message),3):
        my_message.append(m)

    msg = ""
    while msg != "DONE":
        sem.acquire()
        global content
        content = content
        sem.release()
        msg = content

def process_blue(offset, interleave, l_message, message):
    # recorro el mensaje para ir guardando las letras en el PIXEL rojo
    my_message = []
    for m in range(2, len(message),3):
        my_message.append(m)

    msg = ""
    while msg != "DONE":
        sem.acquire()
        global content
        content = content
        sem.release()
        msg = content

def process_color(color, offset, interleave, l_total, message):
    if (color == "R"):
        process_red(offset, interleave, l_total, message)
    elif (color == "G"):
        process_green(offset+1, interleave, l_total, message)
    else:
        process_blue(offset+2, interleave, l_total, message)

def check_interleave(interleave, l_message, raster):
    if (interleave < raster / l_message):
        return True
    else:
        return False

def save_content(content, output):
    fd = open_or_create_file(output, os.O_WRONLY | os.O_APPEND)
    os.write(fd, bytearray(content))
    os.close(fd)

def save_header(header, output):
    fd = open_or_create_file(output, os.O_WRONLY | os.O_CREAT)
    os.write(fd, bytearray(header))
    os.close(fd)

def create_header(source, comment):
    fr = open_file_for_read(source)
    read = os.read(fr, 27)
    count = 0
    header = b""
    lines = read.splitlines()
    for line in lines:
        if (count == 1):
            header = header + comment + b"\n"
        header = header + line + b"\n"
        count = count + 1
    os.close(fr)
    return header

def apply_rot13(message, q_encript):
    codec = "abcdefghijklmnopqrstuvwxyz"
    codec2 = codec + codec
    output = ""
    for char in str(message):
        index = (codec.find(char))
        if index >= 0:
            output = output + codec2[index+13]
        else :
            output = output + char
    q_encript.put(output)

def create_comment(encryption, offset, interleave, l_total):
    crypt = ""
    if (encryption == 1):
        crypt = "-C"
    comment = bytes("#UMCOMPU2" + str(crypt) + " " + str(offset) + " " + str(interleave) + " " + str(l_total), 'utf-8')
    return comment

def get_file_content(file):
    fd = open_file_for_read(file)
    content_file = os.read(fd, 1000)
    return content_file

def open_file_for_read(file):
    fd = os.open(file, os.O_RDONLY)
    return fd

def open_or_create_file(file, mode):
    fd = os.open(file, mode)
    return fd
