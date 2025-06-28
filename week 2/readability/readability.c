#include <cs50.h>
#include <stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

int main(void)
{
    string text = get_string("Text: ");


int letter=0;
int word=1;
int sentence=0;

    for(int i=0 ; i<strlen (text);i++)
    {

    if(isalpha(text[i]))
    {
letter++;
    }

else if(text[i] == ' ')
    {
    word++;
}

else if(text[i] == '.' || text[i] == '!' || text[i] == '?')
{
    sentence++;
}
    }



float average1=(float)letter / word*100;
float averages=(float)sentence / word*100;
float calculation=(0.0588 * average1 )- (0.296 * averages) - (15.8);
int index=round(calculation);

if(index>=16)
{
  printf("Grade 16+\n");

}

else if(index<1)
{
    printf("Before Grade 1\n");

}

else
{

printf("Grade %i\n",index );

}
return 0;
}

