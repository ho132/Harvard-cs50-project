#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    FILE *pt=fopen("w.txt","r");
    char r;
    while((r=fgetc(pt))!=EOF)
{
    printf("%c",r);

}
fclose(pt);
 FILE * pt1=fopen("w.txt","w");
fputc('l',pt);
fclose(pt);
FILE*pt2=fopen("w.txt","r");

int arr [10];

fread(arr,sizeof(int),10,pt2);
double *arr1=malloc(sizeof(double)*80);
fread(arr1,sizeof(double),80,pt2);   //storing values in arrays
char c;
fread(&c,sizeof(char),1,pt2);//storing char
fclose(pt2);
int arr3[2];
FILE*pt3=fopen("w5.txt","w");

fwrite(arr3,sizeof(int),2,pt3);
char ic;
fwrite(&ic,sizeof(char),1,pt3);
}