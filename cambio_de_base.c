#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Función para convertir un dígito hexadecimal a decimal
int hexToDecimal(char hexDigit) {
    if (isdigit(hexDigit)) {                        //aca se verifica que el char esta entre 0-9 
        return hexDigit-'0';                            //si es cierto no hace falta convertirlo
    } else {
        return toupper(hexDigit) - 'A' + 10;        //de lo contrario significa que es una letra entonces se convierte a decimal restando rl valor ACII de A y sumando 10
    }
}

// Función para convertir un número en una base a decimal
int toDecimal(const char *number, int base) {
    int decimal = 0;
    int power = 1;                                  //potencia actual
    int length = strlen(number);                    //longitud del numero de la base dada

    for (int i = length - 1; i >= 0; i--) {         //empieza en orden inverso, desde el digito menos significativo
        int digit = (base == 16) ? hexToDecimal(number[i]) : (number[i] - '0');     // verifica si es hexa, si es asi usa la funcion anterior, si no resta el valor ASCII de 0 (48) para obtener el valor numerico en lugar del valor ASCII del caracter
        decimal += digit * power;
        power *= base;                              //actualiza la potencia para posicionar correctamente cada digito
    }

    return decimal;
}

// Función para convertir un número decimal a una base dada
void fromDecimal(int decimal, int base) {
    if (decimal == 0) {
        printf("0\n");
        return;
    }

    char result[100];
    int index = 0;

    while (decimal > 0) {                   //para decimales mayores a 0
        int remainder = decimal % base;     //reciduo del numero entre la base
        result[index++] = (remainder < 10) ? (char)(remainder + '0') : (char)(remainder - 10 + 'A');        //si es menor a 10 usa el caracter correspondiente, si es mayor usa la letra correspondiente
        decimal /= base;                    //divide el decimal por l base para continuar con el siguiente digito
    }

    // Imprimir el resultado en orden inverso
    printf("El resultado en base %d es: ", base);
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
    printf("\n");
}

int main() {
    char input[100];
    int baseFrom, baseTo;

    // Solicitar entrada al usuario
    printf("1. Ingrese el numero: ");
    scanf("%s", input);

    
    while (baseFrom < 2 || baseFrom > 16) // comprueba que la base del numero esté entre 2 y 16
    {
        printf("2. Ingrese la base del numero (2-16): ");
        scanf("%d", &baseFrom);
        if (baseFrom < 2 || baseFrom > 16)
        {
            printf("Bases no validas. Debe estar entre 2 y 16.\n");
        }
    }
    
    
    while (baseTo < 2 || baseTo > 16) // comprueba que la base a la que se desea convertir esté entre 2 y 16
    {
        printf("3. Ingrese la base a la que desea convertir (2-16): ");
        scanf("%d", &baseTo);
        if (baseTo < 2 || baseTo > 16)
        {
            printf("Base a convertir no validas. Debe estar entre 2 y 16.\n");
        }
    }

    // Convertir a decimal
    int decimalNumber = toDecimal(input, baseFrom);

    // Convertir de decimal a la base deseada
    fromDecimal(decimalNumber, baseTo);

    return 0;
}