#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 100
#define RIGHE 4
#define COLONNE 4

struct Mystruct
{

float avg;

char id;

int rc;

};



void leggimat(float mat[NMAX][NMAX], int *righe, int *colonne);
void calcola_media(int righe, int colonne , struct Mystruct vet[NMAX], float mat[NMAX][NMAX]);
void bubblesort(struct Mystruct vet[NMAX], int size);
void stampastruct(struct Mystruct vet[NMAX], int size);
void scritturabinaria(struct Mystruct vet[NMAX], int size);

int main()
{
struct Mystruct vet[NMAX];
float mat[NMAX][NMAX];
int righe;
int colonne;
righe =colonne =4;

memset(vet, 0, sizeof(struct Mystruct)*NMAX);
memset(mat, 0, sizeof(float)*16);


            leggimat(mat, &righe, &colonne);
            calcola_media(righe, colonne, vet, mat);
            bubblesort(vet, righe+colonne);
            stampastruct(vet, righe+colonne);
            scritturabinaria(vet, righe+colonne);
}

//END INT MAIN





void leggimat(float mat[NMAX][NMAX], int *righe, int *colonne)
{

    FILE *fp;
    fp=fopen("input.txt", "r");

    if(fp!=NULL)
     {
            for(int i=0; i<*righe; i++)
            {
                for(int j=0; j<*colonne; j++)
                {
            fscanf(fp, "%f", &mat[i][j]);
                }
            }
            fclose(fp);
         printf("\n");

            //TEST
            for(int i=0; i<*righe; i++)
        {
            for(int j=0; j<*colonne; j++)
            {

                printf("%.0f ", mat[i][j]);

            }
            printf("\n");
        }
       }
       else printf("ERRORE!");
}

void calcola_media(int righe, int colonne ,struct Mystruct vet[NMAX], float mat[NMAX][NMAX])
{
//MEDIA RIGHE
for(int i=0; i<righe; i++)
    {
        float sommarighe=0;
    for(int j=0; j<colonne; j++)
        {
sommarighe+= mat[i][j];
        }
vet[i].avg=sommarighe/colonne;
vet[i].id='r';
vet[i].rc=i;
     }

//MEDIA COLONNE
for(int j=0; j<colonne; j++)
{
        float sommacolonne=0;
    for(int i=0; i<righe; i++)
    {
sommacolonne +=mat[i][j];
    }
vet[j+righe].avg=sommacolonne/righe;
vet[j+righe].id='c';
vet[j+righe].rc=j;
}


}//FINE


void bubblesort(struct Mystruct vet[NMAX], int size)
{
//BUBBLE SORT CON GLI ELEMENTI DELLA STRUCT!!
struct Mystruct temp;

for(int i=0; i<size-1; i++)
{
    for(int j=0; j<size-i-1; j++)
    {
       if(vet[j].avg > vet[j+1].avg)
       {
        //memcpy(&temp, &vet[j+1], sizeof(struct Mystruct));
        //memcpy(&vet[j+1], &vet[j], sizeof(struct Mystruct));
        //memcpy(&vet[j], &temp, sizeof(struct Mystruct));
       temp=vet[j+1];
       vet[j+1]=vet[j];
       vet[j]=temp;
       }
    }
}

}//FINE

void stampastruct(struct Mystruct vet[NMAX], int size)
{
      printf("\n");
      for(int i=0; i<size; i++)
      {
      printf("\n%2f, {id:%c, rc:%d}", vet[i].avg, vet[i].id, vet[i].rc);
      }//CON 2 STAMPA SOLO 2 CIFRE DECIMALI

}


void scritturabinaria(struct Mystruct vet[NMAX], int size)
{
FILE *fp;
fp=fopen("output.bin", "wb");

if(fp!=NULL)
   {
    fwrite(vet, sizeof(struct Mystruct), size, fp);
    printf("\nSCRITTURA AVVENUTA CON SUCCESSO!");
    fclose(fp);
   }

}//FINE
