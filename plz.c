}
string vowels=argv[1];
string numbers="6310";
replace (vowels,numbers);
return 0;
}

int replace (string vowels ,string numbers)
{


int length=strlen(vowels);

    for(int i=0;i<length;i++)

 if( vowels[i]=='a' )
 {

 switch(i)
 {
   case 6:

    break;
 }
 }
else if(vowels[i]=='e')
{
switch(i)
{
case 3:
   break;
}
}
else if(vowels[i]=='i')
{
switch (i)
{
 case 1:
 break;
}
}
else if(vowels[i]=='o')
{
switch(i)
{
   case 0:
   break;
}
}


}