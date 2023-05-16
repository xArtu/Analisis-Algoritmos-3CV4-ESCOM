#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int DAC_Max(int a[], int index, int l);
int DAC_Min(int a[], int index, int l);

int DAC_Max(int a[], int index, int l)
{
    int max;
    if (l - 1 == 0)
    {
        return a[index];
    }
    if (index >= l - 2)
    {
        if (a[index] > a[index + 1])
            return a[index];
        else
            return a[index + 1];
    }

    max = DAC_Max(a, index + 1, l);

    if (a[index] > max)
        return a[index];
    else
        return max;
}

int DAC_Min(int a[], int index, int l)
{
    int min;
    if (l - 1 == 0)
    {
        return a[index];
    }
    if (index >= l - 2)
    {
        if (a[index] < a[index + 1])
            return a[index];
        else
            return a[index + 1];
    }

    min = DAC_Min(a, index + 1, l);

    if (a[index] < min)
        return a[index];
    else
        return min;
}

int main()
{
    // Defining the variables
    int min, max, N, i;
    N = 10000; // Tamaño del arreglo

    // Inicializar el generador de números aleatorios
    srand(time(NULL));

    // Crear el arreglo de forma aleatoria
    int a[N];
    for (i = 0; i < N; i++)
    {
        a[i] = rand(); // Generar números aleatorios entre 0 y 999
    }

    // recursion - Llamar a la función DAC_Max
    max = DAC_Max(a, 0, N);

    // recursion - Llamar a la función DAC_Min
    min = DAC_Min(a, 0, N);

    printf("El numero minimo en el arreglo es: %d\n", min);
    printf("El numero maximo en el arreglo es: %d\n", max);

    return 0;
}

