#include<stdio.h>
#include<conio.h>
#include<process.h>
#define end 0
void main()
{
	char input,input1,input2;
	int a,b,order,add,add1;
	order=add=0;
	a=b=100;
	while(input!='x')
	{
		clrscr();
		main_menu();
		scanf("%c",& input);

		if(input=='a'||input=='A')
		{
			printf("\nWhich Resistor value you want to Enter");
			input2 = resistor_size();
			if(input2=='a'||input2=='A')
			{
				order=resistor_number();
				if(order>a)
				{
					printf("Not Enough %d", order);
					printf(" 100 ohm resistor left in Stock");
				}
				else
				{
					int i;
					for(i=0;i<order;i++)
					{
						a=a-1;
						add=add+1;
					}
				}
				printf("\nYou now have %d",a);
				printf("\t100 ohm resistors left in the Stock");
				printf("\nYou now have %d",b);
				printf("\t1000 ohm resistors left in the Stock");
				order=0;
			}
			else if(input2=='b'||input2=='B')
			{
				order=resistor_number();
				if(order>b)
				{
					printf("Not Enough %d", order);
					printf(" 1000 ohm resistor left in Stock");
				}
				else
				{
					int j;
					for(j=0;j<order;j++)
					{
						b=b-1;
						add1=add1+1;
					}
				}
				printf("\nYou now have %d",a);
				printf("\t100 ohm resistors left in the Stock");
				printf("\nYou now have %d",b);
				printf("\t1000 ohm resistors left in the Stock");

				order=0;
			}

			getch();

		}
		else if(input=='b'||input=='B')
		{
			printf("\nWhich Resistor value you want to Remove");
			input2 = resistor_size();
			if(input2=='a'||input2=='A')
			{
				order=resistor_number();
				if(order>a)
				{
					printf("Not Enough %d", order);
					printf(" 100 ohm resistor left in Stock");
				}
				else if((a+order)<=100)
				{
					int i;
					for(i=0;i<order;i++)
					{
						a=a+1;
						add=add-1;
					}
				}
				else
				{
					printf("\n You cannot Remove Resistors");
				}
				printf("\nYou now have %d",a);
				printf("\t100 ohm resistors left in the Stock");
				printf("\nYou now have %d",b);
				printf("\t1000 ohm resistors left in the Stock");
				order=0;
			}
			else if(input2=='b'||input2=='B')
			{
				order=resistor_number();
				if(order>b)
				{
					printf("Not Enough %d", order);
					printf(" 1000 ohm resistor left in Stock");
				}
				else if((b+order)<=100)
				{
					int j;
					for(j=0;j<order;j++)
					{
						b=b+1;
						add1=add1-1;
					}
				}
				else
				{
					printf("\n You cannot Remove Resistors");
				}
				printf("\nYou now have %d",a);
				printf("\t100 ohm resistors left in the Stock");
				printf("\nYou now have %d",b);
				printf("\t1000 ohm resistors left in the Stock");

				order=0;
			}

			getch();
		}
		else if(input=='c'||input=='C')
		{
			printf("------INVENTORY BALANCE------");
			printf("\nYou now have %d", (100-a));
			printf(" 100 ohm resistors in Stock");
			printf("\nYou now have %d",(100-b));
			printf(" 1000 ohm resistors in Stock");
			getch();

		}
		else if(input=='x'||input=='x')
		{
			exit(end);
		}
		else
		{
			fflush(stdin);
			printf("Invalid Selection");
			fflush(stdin);

		}


	}


}
int main_menu()
{
	printf("\n\t-------Main Menu--------- ");
	printf("\n\ta) Add Resistors to Inventory");
	printf("\n\tb) Take Resistors from Inventory");
	printf("\n\tc) Resistors remaining in Inventory");
	printf("\n\tx) Exit");
	printf("\nPlease Select one of the Choices above (a -> x) :");
	return 0;
}
int resistor_size(char in)
{

	do
	{
		printf("\na) 100 ohm");
		printf("\nb) 1000 ohm");
		printf("\nEnter the option: ");
		fflush(stdin);
		scanf("%s",& in);
		if(in=='a'||in=='b'||in=='A'||in=='B')
		{
		       break;
		}
		else
		{
			fflush(stdin);
			printf("Invalid Selection");

		}
	}
	while(in!='a'||in!='b');
	return in;
}
int resistor_number()
{
	int order1;
	order1=0;
	printf("\nHow many Elements You want to Order/remove from inventory:");
	fflush(stdin);
	scanf("%d",& order1);
	return order1;
}
