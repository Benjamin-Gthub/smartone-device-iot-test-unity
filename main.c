#include <stdio.h>
#include "src/operations.h"

int tmain(void) {
    printf("Hello, World!\n");
    int num1, num2, res;
    // Leer dos números desde la entrada estándar (teclado)
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);  // scanf usa stdin por defecto

    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);  // scanf usa stdin por defecto

    res= sum(num1,num2);

    printf("La suma es: %d\n", res);
//    printf("La suma es: %d\n", sum(num1,num2));
    return 0;
}
