import keyboard
import serial 
import time

def main():
    ard = serial.Serial('com3',9600)    #Mediante la función Serial creamos la comunicación necesaria con el puerto conectado a Arduino, es necesario saber el puerto y el BR asignados
    time.sleep(2)
    while True:
        incoming = str(ard.readline())  #Mediante la función readline el programa recoge lo que pasa por el puerto serial
        if 'Actuar' in incoming:        #En caso el string escrito esté dentro de lo que el serial recoge se ejecutará la comunicación con windows
            keyboard.send("windows+d")  #Las teclas seleccionadas para la ejecución son Windows+d que utilizadas en windows intercalarà entre mostrar el escritorio y volver al estado anterior a este

        if keyboard.is_pressed('p'):    #Este trozo de codigo es para terminar el programa y mediante la libreria keyboard detectamos si un botón está presionado, en este caso la p de Pause
            break
        incoming = ""



if __name__== '__main__':
    main()