#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int x;
    int y ;

}point;

int main(void)
{
    point pt1;

    pt1.x=3;
    pt1.y=4;

    printf("pt1:X:%d\ny:%d\n",pt1.x,pt1.y);

    point*pt2=&pt1;
    pt2->x=4;
    pt2->y=5;

    printf("pt1:%d\n%d\n",pt1.x,pt1.y);
    printf("pt2:%d\n%d\n",pt2->x,pt2->y);
    point *pt3=malloc(sizeof(point));
    pt3->x=6;
    pt3->y=9;
printf("pt3:%d\n%d\n",pt3->x,pt3->y);
(*pt3).x=2;
(*pt3).y=4;
printf("pt3:%d\n%d\n",(*pt3).x,(*pt3).y); //u can do this way instead of ->
}