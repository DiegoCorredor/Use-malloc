#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu();
void burbuja();
void insercion();
void quick();
void seleccion();
void merge();
void quicksort(int *arr, int low, int high);
void mezcla(int vector[], int n);

int main(){
	menu();
	return 0;
}

void menu(){
	int r;
	
		printf("\nMenu:\n");
		printf("\n1. Burbuja\n");
		printf("2. Insercion\n");
		printf("3. Quicksort\n");
		printf("4. Seleccion\n");
		printf("5. Mergesrot\n");
		printf("6. SALIR\n");
		printf("\nIngrese la opcion que desea y a continuacion el tamaño que desea ordenar:\n");
		scanf("%i",&r);
		switch(r){
			case 1: burbuja();break;
			case 2: insercion();break;
			case 3: quick();break;
			case 4: seleccion();break;
			case 5: merge();break;
		}	
}

void burbuja(){
	int i,j,aux,n,aleatorio,P,U;
	srand(time(NULL));
	int **m;
	scanf("%d",&n);
	m=(int**)malloc(n*sizeof(int*));
			if(m==NULL){
				printf("No se pudo reservar el espacio en memoria.\n");
				exit(1);
			}
	int array[n]; 
	for(i=0;i<n;i++){
		aleatorio=rand();
		array[i]=aleatorio;
	}
	for(i=0;i<(n-1);i++){
		for(j=0;j<(n-1);j++){ 
			if(array[j]>array[j+1]){ 
				aux=array[j];
				array[j]=array[j+1];
				array[j+1]=aux;
			}
		}
	}
	for (i=0;i<n;i++){
		printf("\n%i",array[i]);
	}
}

void insercion(){
		int i,pos,n,aux,p,aleatorio,P,U;
	int **m;
	srand(time(NULL));
	scanf("%d",&n);
	m=(int**)malloc(n*sizeof(int*));
			if(m==NULL){
				printf("No se pudo reservar el espacio en memoria.\n");
				exit(1);
			}
	int array[n];
	for(i=0;i<n;i++){
		aleatorio=rand();
		array[i]=aleatorio;
	}
	for(i=0;i<n;i++){
		pos=i;
		aux=array[i];
		while((pos>0)&&(aux<array[pos-1])){
			array[pos]=array[pos-1];
			pos--;
		}
		array[pos]=aux;
	}
	for (i=0;i<n;i++){
		printf("\n%i",array[i]);
	}
}

void quick(){
	int  n, i,aleatorio,U,P;
  srand(time(NULL));
  scanf("%d", &n);
  int **m;
	m=(int**)malloc(n*sizeof(int*));
			if(m==NULL){
				printf("No se pudo reservar el espacio en memoria.\n");
				exit(1);
			}
	int arr[n];
  for(i = 0; i < n; i++){
  	aleatorio=rand();
		arr[i]=aleatorio;
	}
  quicksort(arr, 0, n-1);
  for(i = 0; i < n; i++)
    printf("\n%d", arr[i]);
}
void quicksort(int *arr, int low, int high)
{
  int pivot, i, j, temp;
  if(low < high) {
    pivot = low;
    i = low;
    j = high;
    while(i < j) {
      while(arr[i] <= arr[pivot] && i <= high)
        i++;
      while(arr[j] > arr[pivot] && j >= low)
        j--;
      if(i < j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    temp = arr[j];
    arr[j] = arr[pivot];
    arr[pivot] = temp;
    quicksort(arr, low, j-1);
    quicksort(arr, j+1, high);
  }
}

void seleccion(){
	int i,j,aux,n,p,min,**m,aleatorio,P,U;
	srand(time(NULL));
	scanf("%d",&n);
	m=(int**)malloc(n*sizeof(int*));
			if(m==NULL){
				printf("No se pudo reservar el espacio en memoria.\n");
				exit(1);
			}
	int array[n];
	for(i=0;i<n;i++){
		aleatorio=rand();
		array[i]=aleatorio;
	}
	for(i=0;i<n;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(array[j]<array[min]){
				min=j;
			}
		}
		aux=array[i];
		array[i]=array[min];
		array[min]=aux;
	}
	for(i=0;i<n;i++){
		printf("\n%d",array[i]);
	}
}

void merge(){
	srand(time(NULL));
    int i,n,**m,aleatorio,P,U;
    scanf("%d",&n);
	int vector[n];
	m=(int**)malloc(n*sizeof(int*));
			if(m==NULL){
				printf("No se pudo reservar el espacio en memoria.\n");
				exit(1);
			}
	for(i=0;i<n;i++){
		aleatorio=rand();
		vector[i]=aleatorio;
	}
	mezcla(vector,n);
    for(i=0;i<n;i++)
        printf("\n%i", vector[i]);}
void mezclar(int arreglo1[], int n1, int arreglo2[], int n2, int arreglo3[])
{
    int x1=0, x2=0, x3=0;
    while (x1<n1 && x2<n2) {
        if (arreglo1[x1]<arreglo2[x2]) {
            arreglo3[x3] = arreglo1[x1];
            x1++;
        } else {
            arreglo3[x3] = arreglo2[x2];
            x2++;
        }
        x3++;
    }
    while (x1<n1) {
        arreglo3[x3] = arreglo1[x1];
        x1++;
        x3++;
    }
    while (x2<n2) {
        arreglo3[x3] = arreglo2[x2];
        x2++;
        x3++;
    }
}
void mezcla(int vector[], int n)
{
    int *vector1, *vector2, n1, n2,x,y;
    if (n>1)
    {
        if (n%2 == 0)
            n1=n2=(int) n / 2;
        else
        {
            n1=(int) n / 2;
            n2=n1+1;
        }
        vector1=(int *) malloc(sizeof(int)*n1);
        vector2=(int *) malloc(sizeof(int)*n2);
        for(x=0;x<n1;x++)
            vector1[x]=vector[x];
        for(y=0;y<n2;x++,y++)
            vector2[y]=vector[x];
        mezcla(vector1, n1);
        mezcla(vector2, n2);
        mezclar(vector1, n1, vector2, n2, vector);
        free(vector1);
        free(vector2);
    }    
}
