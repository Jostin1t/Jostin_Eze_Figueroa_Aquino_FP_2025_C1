#include <stdio.h>
#include <stdlib.h>
#define SALIR 0
#define SUMAR 1
#define RESTAR 2
#define MULTIPLICAR 3
#define DIVIDIR 4
#define ERR_OK 0
#define ERR_DbZ 1

void inNumeros(float*num1, float*num2);
int sum(float n1, float n2, float *r);
int resta(float n1, float n2, float *r);
int dividir(float num, float deno, float *r);
int mul(float n1, float n2, float *r);

int main()
{
    int menu = -1;
    int cod_err = ERR_OK;
    float num1 = 0.0;
    float num2 = 0.0;
    float result = 0.0;
    do
    {
        printf("\n1-Suma\n2-Resta\n3-Multiplicacion\n4-Division\n0-Salir\n");
        scanf("%d", &menu);
        if(menu == SUMAR)
        {
            inNumeros(&num1, &num2);
            cod_err = sum(num1, num2, &result);
            printf("\nLa suma de %f mas %f es = %f", num1, num2, result);
        }
        else if(menu == RESTAR)
        {
            inNumeros(&num1, &num2);
            cod_err = resta(num1, num2, &result);
            printf("\nLa resta de %f menos %f es = %f", num1, num2, result);
        }
        else if(menu == MULTIPLICAR)
        {
            inNumeros(&num1, &num2);
            cod_err = mul(num1, num2, &result);
            printf("\nLa multiplicacion de %f por %f es = %f", num1, num2, result);
        }
        else if(menu == DIVIDIR)
        {
            inNumeros(&num1, &num2);
            cod_err = dividir(num1, num2, &result);
            if(cod_err == ERR_OK)
            {
                printf("\nLa division de %f por %f es = %f", num1, num2, result);
            }
            else
            {
                if(cod_err == ERR_DbZ)
                {
                    printf("\nError al dividir por 0");
                }
                else
                {
                    printf("\nError general");
                }
            }
        }
        else
        {
            printf("\nValor de menu no valido");
        }
    }
    while(menu != SALIR);
    printf("\nFin!");
    return 0;
}

void inNumeros(float*num1, float*num2)
{
    float temp;
    printf("\nIngresa numero 1:");
    scanf("%f", &temp);
    *num1 = temp;
    printf("\nIngresa numero 2:");
    scanf("%f", &temp);
    *num2 = temp;
}

int sum(float n1, float n2, float *r)
{
    *r = n1 + n2;
    return ERR_OK;
}

int resta(float n1, float n2, float *r)
{
    *r = n1 - n2;
    return ERR_OK;
}

int dividir(float num, float deno, float *r)
{
    if(deno == 0)
    {
        return ERR_DbZ;
    }
    else
    {
        *r = num / deno;
        return ERR_OK;
    }
}

int mul(float n1, float n2, float *r)
{
    *r = n1 * n2;
    return ERR_OK;
}
