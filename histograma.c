#include <stdio.h>
#include <stdlib.h>

int main() { // Abrir el archivo en modo de lectura
    FILE *archivo = fopen("archivo1.txt", "r");
    int histograma[128] = {0}; // Declarar e inicializar el histograma
    int caracter; // Leer cada carácter del archivo y contar su frecuencia
    
    if (archivo == NULL) { // Verificar si se pudo abrir el archivo
        printf("Error al abrir el archivo");
        return 1;  // Salir del programa con código de error
    }

    while ((caracter = fgetc(archivo)) != EOF) { //usa la funcion fgetc para obtener los caracteres y los guarda para compararlos
        histograma[caracter]++;
    }

    fclose(archivo); // Cerrar el archivo después de leer

    printf("Histograma de caracteres:\n"); // Imprime el histograma comparando cada caracter
    for (int i = 0; i < 128; i++) {
        if (histograma[i] > 0) {
            printf("'%c': %d\n", (char)i, histograma[i]);
        }
    }

    return 0;
}