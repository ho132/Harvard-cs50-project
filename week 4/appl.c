#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(void)
{
    char  d[100];
    FILE * file2=fopen("uy.txt","w");
    printf("Enter a sent :");
    scanf("%99[^\n]",d);
    fprintf(file2,"%s",d);




char filename[100];
char ch;
FILE * file=fopen("filename","r");
printf("Enter the filename to read:");
if(fgets(filename,100,stdin)!=NULL)
{
  int len =strlen(filename);
  if(len>0 && filename[len-1]=='\n')
  {
    filename[len-1]='\0';
  }
}
if(file==NULL)
{
 printf("file doesnt  exist or cant be opened.\n");
 return 1 ;
}
printf("Content of the file %s: \n",filename);


while((ch=fgetc(file)) != EOF )
{
  putchar(ch);
}
fclose(file);
return 0;





}