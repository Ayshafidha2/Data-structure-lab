#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int queue[SIZE];
int front,rear;
void main()
{
void insertq(int);
int deleteq();
int searchq(int);
int data,opt,tfront,ans;
do
{
printf("\n 1.insert \n");
printf("\n 2.delete \n");
printf("\n 3.search \n");
printf("\n 4.exit \n");
printf("your option is:");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("Data:");
       scanf("%d",&data);
       insertq(data);
       break;
case 2:data=deleteq();
       printf("deleted item= %d",data);
       break;
case 3:printf("item searched:");
       scanf("%d",&data);
       ans=searchq(data);   
       if(ans==1)
       printf("found \n");
       else
       printf("Not found \n");
       break;
case 4:exit(0);
}
}
while(1);
}
void insertq (int item)
{
if(rear==SIZE-1)
printf("queue is full \n");
else
queue[++rear]=item;
}
int deleteq()
{
if(front==rear)
{
printf("queue is empty \n");
exit(0);
}
else 
return queue[++front];
}
int searchq(int item)
{
int tfront=front+1;
while(tfront!=rear && queue[tfront]!=item)
++tfront;
if(queue[tfront]==item)
return 1;
else
return 0;
}

