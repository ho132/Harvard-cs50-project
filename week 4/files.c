#include<stdio.h>

int main(void)
{
    FILE*you=fopen("lk.txt","w");
    fputs("LAma\n",you);
    fclose(you);
    FILE * ju=fopen("l.txt","r");
    char fr[100];
   while(fgets(fr,100,ju)!= NULL)
   {

    printf("%s\n",fr);
    break;
    }
    fclose(ju);


    int p=40;
    FILE *file=fopen("kj.txt","w");
    scanf("%d",&p);
    fprintf(file,"%d\n",p);
    fclose(file);

     int t=4;
    FILE*gg=fopen("y.test","w");
    //fscanf(gg,"%d\n",&t);

    fprintf(gg,"l: %d",t);
}