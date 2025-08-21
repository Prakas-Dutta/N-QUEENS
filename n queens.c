#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<conio.h>
typedef struct
{
	int row,column;
}position;
int number=0;
position fixed[12];
int set=0, size=0;
char board[12][12];

int downRight(int r, int c)
{
	int i;
	while(r!=size && c!=size)
	{
		for(i=0;i<set;i++)
		{
			if(fixed[i].column==c && fixed[i].row==r)
			return 1;
		}
		r++;
		c++;
	}
	return 0;
}

int downLeft(int r, int c)
{
	int i;
	while(r!=size && c!=-1)
	{
		for(i=0;i<set;i++)
		{
			if(fixed[i].column==c && fixed[i].row==r)
			return 1;
		}
		r++;
		c--;
	}
	return 0;
}

int upRight(int r, int c)
{
	int i;
	while(r!=-1 && c!=size)
	{
		for(i=0;i<set;i++)
		{
			if(fixed[i].column==c && fixed[i].row==r)
			return 1;
		}
		r--;
		c++;
	}
	return 0;
}

int upLeft(int r, int c)
{
	int i;
	while(r!=-1 && c!=-1)
	{
		for(i=0;i<set;i++)
		{
			if(fixed[i].column==c && fixed[i].row==r)
			return 1;
		}
		r--;
		c--;
	}
	return 0;
}

int rowColumn(int r, int c)
{
	int i;
	for(i=0;i<set;i++)
	{
		if(fixed[i].row==r || fixed[i].column==c)
		return 1;
	}
	return 0;
}

void reset()
{
	int i,j=0;
	for(i=0;i<size;i++)
	for(j=0;j<size;j++)
	board[i][j]='.';
	for(i=0;i<size;i++)
	fixed[i].column=fixed[i].row=-1;
}
int check(int r, int c)//If rule matched is found then return 0
{
	if(upLeft(r,c)||upRight(r,c)||downLeft(r,c)||downRight(r,c)||rowColumn(r,c))
	return 0;
	else return 1;
}
void print()
{
	int i,j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		printf("%c ",board[i][j]);
		printf("\n");
	}
}

int findPath(int r)
{
	int i;
	if(set==size)
	{
		number++;
		printf("%d\n",number);
		print();
		printf("\n\n");
	}
	else if(r!=size)
	{
		for(i=0;i<size;i++)
		{
			if(check(r,i))
			{
				board[r][i]='Q';
				fixed[set].row=r;
				fixed[set].column=i;
				set++;
				findPath(r+1);
				board[r][i]='.';
				set--;
			}
		}
	}		
}
main()
{
	printf("Enter size of nxn chess board...");
	scanf("%d",&size);
	board[size][size];
	fixed[size];
	reset();
	findPath(0);
	printf("Completed:)\nTotal %d number of combinations found.", number);
	getch();
}
