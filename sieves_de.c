#include<stdio.h>
#include<stdlib.h>
#define FIN_ARRAY 0
unsigned int* Sieves(unsigned int n);

int main(){
    unsigned int n = 5;
    unsigned int *primos;
    
    while (n !=  0) {
        printf("Busca primos (ingresa 0 para salir):\n Ingresa hasta que numero quieres encontrar primos. Ex 100:\n>> ");
        scanf("%u",&n);
        
        if (n > 2)
        {
            primos = Sieves(n);
            for (int i = 0; *(primos+i) != 0; i++){
                printf("%u, ", *(primos+i));
            }
        } else {
            printf("Ingresa numero a partir de 3\n");
        }
         
         
         
    }
     return 0;
}


unsigned int* Sieves (unsigned int n){
    
    
    n = n + (n&1); //xx...xx and 00...01,
    //es necesario que n siempre sea par, para las operaciones binarias que hago despues
    n = (n - 2) >> 1;//Dividir entre 2 usando bitshift
    
    //Un arreglo del size de n/2 - 2
    unsigned int* candidatos = (unsigned int*) malloc(sizeof(unsigned int) * n);
   
    //Los pares ni sirven, pa que los generamos lol
    for(unsigned int i = 3; i <= (n << 1) + 2; i+=2 ){//Se llenan con los candidatos
           *(candidatos + ((i - 3) >> 1) ) = i; //Siempre estamos diviendo un numero par, por lo que le bitshift si nos sirve
       }
    
   
    
    /* Marcar los numeros que no son primos */
    unsigned int numPrueba = 0; //Numero al que le saco sus multiplos
    unsigned int numPrimos = 0;//Me va a servir para crear el arreglo de puros numeros primos."
       
    for (unsigned int i = 0; i < n-1; i++){
        numPrueba = *(candidatos + i);
        
        if (numPrueba != 0) {
            numPrimos ++;
            for (unsigned int j = 0; j < ((n-i)/numPrueba); j++){
            //Los multiplos inpares de x num impar esta 2*y veces lejos
            //Recuerda que nuestra solo tiene impares
            
                *(candidatos + i + (j+1)*numPrueba) = 0;
               }
           }
       }
    
    
    
    
   //Nuevo arreglo para los primos
    unsigned int* primos = (unsigned int*) malloc(sizeof(unsigned int) * (numPrimos + 2));
    
    //Guardando los primos en un nuevo arreglo
    int contador = 0;
    for (unsigned int j = 0; j < n; j++) {
        int temp = *(candidatos + j);
       
        if ( temp != 0){
            *(primos + contador) = *(candidatos + j);
            contador++;
        }
    }
    *(primos + numPrimos + 1) = FIN_ARRAY; //Para saber el fin del array
       
    
    return primos;
}

