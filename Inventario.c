#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define  N_PRODUCTOS 10

int main () {

    char nombres[N_PRODUCTOS][20];
    float precios[N_PRODUCTOS] = {0};
    int opc = 0, opc1 = 0, valido = 0;

    int contP = 0;

    do
    {
        printf("\nSelecione una opcion:\n");
        printf("1.Registrar producto\n");
        printf("2.Mostrar inventario\n");
        printf("3.Calcular precio total del inventario\n");
        printf("4.Mostrar producto mas caro y mas barato\n");
        printf("5.Calcular precio promedio\n");
        printf("6.Buscar producto por nombre\n");
        printf(">> ");
        scanf("%d",&opc1);

        switch (opc1)
        {
        case 1:
            if(contP<N_PRODUCTOS){
                do
                {
                    valido = 1;
                    printf("Ingrese el nombre del producto %d: ",contP+1);
                    scanf(" %19[^\n]",nombres[contP]);
                    for (int j = 0; nombres[contP][j] != '\0'; j++)
                    {
                        if(!isalpha((unsigned char)nombres[contP][j]) && nombres[contP][j] != ' '){
                            valido = 0;
                        }
                    }
                    if(!valido){
                        printf("Error: el nombre solo puede contener letras\n");
                    }
                } while (!valido);
                printf("Ingrese el precio de %s: ",nombres[contP]);
                scanf("%f",&precios[contP]);
                if(precios[contP]<0){
                    printf("Error: el precio no puede ser negativo\n");
                    break;
                }
                contP++;
            }else{
                printf("No se puede ingresar mas productos\n");
            }
            break;
        case 2:
            if(contP==0){
                printf("Error: no hay productos registrados\n");
                break;
            }
            printf("#\t\tNombre\t\tPrecio\n");
            for (int i = 0; i < contP; i++)
            {
                printf("%d\t\t%s\t\t%.2f\n",i+1,nombres[i],precios[i]);
            }
            break;
        case 3:
        {
            float total=0;
            if(contP==0){
                printf("Error: no hay productos registrados\n");
                break;
            }
            for (int i = 0; i < contP; i++)
            {
                total+=precios[i];
            }
            printf("Precio total del inventario: %.2f\n",total);
            break;
        }
        case 4:
        {
            int iMax=0, iMin=0;
            if(contP==0){
                printf("Error: no hay productos registrados\n");
                break;
            }
            for (int i = 1; i < contP; i++)
            {
                if(precios[i]>precios[iMax]){
                    iMax=i;
                }
                if(precios[i]<precios[iMin]){
                    iMin=i;
                }
            }
            printf("Producto mas caro: %s (%.2f)\n",nombres[iMax],precios[iMax]);
            printf("Producto mas barato: %s (%.2f)\n",nombres[iMin],precios[iMin]);
            break;
        }
        case 5:
        {
            float suma=0;
            if(contP==0){
                printf("Error: no hay productos registrados\n");
                break;
            }
            for (int i = 0; i < contP; i++)
            {
                suma+=precios[i];
            }
            printf("Precio promedio: %.2f\n",suma/contP);
            break;
        }
        case 6:
        {
            char buscar[20];
            int encontrado=0;
            if(contP==0){
                printf("Error: no hay productos registrados\n");
                break;
            }
            printf("Ingrese el nombre a buscar: ");
            scanf(" %19[^\n]",buscar);
            for (int i = 0; i < contP; i++)
            {
                if(strcmp(nombres[i],buscar)==0){
                    printf("Producto encontrado: %s - Precio: %.2f\n",nombres[i],precios[i]);
                    encontrado=1;
                    break;
                }
            }
            if(!encontrado){
                printf("El producto %s no existe en el inventario\n",buscar);
            }
            break;
        }
        default:
            printf("Error: opcion no valida\n");
            break;
        }

        printf("Desea seleccionar una opcion 1.Si/2.No: ");
        scanf("%d",&opc);
    } while (opc==1);

    return 0;
}
