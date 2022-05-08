#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int StackElementType;
#define Stack_Size 1000
#define STACKINCREMENT 10

//------用栈实现简易计算器

typedef struct
{
	StackElementType elem[Stack_Size]; 
	int top; /*用来存放栈顶元素的下标，top 为-1 表示空栈*/
}SeqStack;
typedef struct 	//存放运算符			
{
	StackElementType data[Stack_Size];
	int top;
}CharStack;


void InitSStack(SeqStack *S)
{
 	S->top = -1; 
}
void InitCStack(CharStack *C)
{
 	C->top = -1; 
}

int Push_num(SeqStack *S,StackElementType x)//入栈 
{
	if(S->top==Stack_Size-1)
		return (FALSE);
	S->top++;
	S->elem[S->top]=x;
	return 1;	
}
int Push_char(CharStack *C,StackElementType c)
{
	if(C->top==Stack_Size-1)
		return (FALSE);
	C->top++;
	C->data[C->top]=c;
	return 1;
}

int Pop_num(SeqStack *S,StackElementType x)   //出栈 
{ /* 将栈 S 的栈顶元素弹出，放到 x 所指的存储空间中 */

	if(S->top==-1)
		return (FALSE);
	else
	{
		x=S->elem[S->top--];
		return x;	
	}
}
int Pop_char(CharStack *C,StackElementType c)
{
	if(C->top==-1)
		return (FALSE);
	else
	{
		c=C->data[C->top--];
		return c;	
	}
}

int Get_num(SeqStack *S)//取数 
{
	return S->elem[S->top];
}
int Get_char(CharStack *C)
{
	return C->data[C->top];
}

int Num_empty(SeqStack *S) 
{
	return (S->top==-1?TRUE:FALSE);
}
int Char_empty(CharStack *C)
{
	return (C->top==-1?TRUE:FALSE);
}

int cal(int c,int n1,int n2)
{
	switch(c)
	{
		case 3:
			return (n1+n2);
			break;
		case 4:
			return (n1-n2);
			break;
		case 5:
			return (n1*n2);
			break;
	}

}
int check(char s[])
{
	 if(s[0]=='A'&&s[1]=='d'&&s[2]=='d')
            return 3;
     if(s[0]=='S'&&s[1]=='u'&&s[2]=='b')
            return 4;
     if(s[0]=='M'&&s[1]=='u'&&s[2]=='l')
            return 5;
}

int main()
{
	SeqStack S;
	InitSStack(&S);
	CharStack C;
	InitCStack(&C);
	int i=0,j=0,num,sum=0,n;
   char s[3],h='a';
	int n1,n2;
	scanf("%d",&num);//输入操作符总数 
	for(i=0;i<num;i++)
	{
		if(i==0)
		{
			getchar();
		}
	
		for(j=0;j<3;j++)
		{
			scanf("%c",&s[j]);
		}	
		Push_char(&C,check(s));

		while(1)
		{
				
			scanf("%d",&n);
			Push_num(&S,n);	
		
			if(getchar()!=' ')
				break;
		}
		
	}



/*	n1=Pop_num(&S,n1);
		n2=Pop_num(&S,n2);
		sum=cal(Pop_char(&C,h),n1,n2);

	while(!Num_empty(&S))	
		{
			n1=sum;
			n2=Pop_num(&S,n2);
			sum=cal(Pop_char(&C,h),n1,n2);
								
		}
		printf("%d",sum);*/



	n1=Get_num(&S);
	Pop_num(&S,Get_num(&S));
	n2=Get_num(&S);
	Pop_num(&S,n2);
	sum=cal(Get_char(&C),n1,n2);
	
	Pop_char(&C,Get_char(&C));
	while(Num_empty(&S)!=TRUE)	
		{
			n1=sum;
			n2=Get_num(&S);
			Pop_num(&S,n2);
			sum=cal(Get_char(&C),n1,n2);
			Pop_char(&C,Get_char(&C));					
		}
		printf("%d",sum);
	return 0;
}
