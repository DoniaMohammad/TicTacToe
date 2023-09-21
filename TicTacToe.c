#include "STD_TYPES.h"
#include <stdio.h>
#include <stdlib.h>

void TableInit(uint8 sign[],uint8 size)
{
	uint8 i;
	for (i=0; i<10 ; i++)
	{
		sign[i] = ' ';
	}
}

void DisplayBoard (uint8 sign[],uint8 size)
{
	printf ("\n							NUMPAD LOCATIONS\n");
	printf ("		|		|		  	    |   |  \n");
	printf ("	%c	|	%c	|	%c		  7 | 8 | 9\n",sign[7],sign[8],sign[9]);
	printf ("		|		|	 		    |   |  \n");
	printf ("----------------------------------------------	  	  ---------\n");
	printf ("		|		|			    |   |  \n");
	printf ("	%c	|	%c	|	%c		  4 | 5 | 6\n",sign[4],sign[5],sign[6]);
	printf ("		|		|			    |   |  \n");
	printf ("----------------------------------------------		  ---------\n");
	printf ("		|		|			    |   |  \n");
	printf ("	%c	|	%c	|	%c		  1 | 2 | 3\n",sign[1],sign[2],sign[3]);
	printf ("		|		|			    |   |  \n\n");
}

uint8 CheckWin (uint8 sign[],uint8 size)
{
	//row 1 completed
	if ((sign[7]==sign[8])&&(sign[8]==sign[9]))
	{
		return sign[7];
	}
	
	//row 2 completed
	else if ((sign[4]==sign[5])&&(sign[4]==sign[6]))
	{
		return sign[4];
	}
	
	//row 3 completed
	else if ((sign[1]==sign[2])&&(sign[1]==sign[3]))
	{
		return sign[1];
	}
	
	//column 1 completed
	else if ((sign[7]==sign[4])&&(sign[7]==sign[1]))
	{
		return sign[7];
	}
	
	//column 2 completed
	else if ((sign[8]==sign[5])&&(sign[8]==sign[2]))
	{
		return sign[8];
	}
	
	//column 3 completed
	else if ((sign[9]==sign[6])&&(sign[9]==sign[3]))
	{
		return sign[9];
	}
	
	//diagonal 1 completed
	else if ((sign[9]==sign[5])&&(sign[9]==sign[1]))
	{
		return sign[9];
	}
	
	//diagonal 2 completed
	else if ((sign[7]==sign[5])&&(sign[7]==sign[3]))
	{
		return sign[7];
	}
	
	//draw "All blocks are full but no wins"
	else if ( (sign[7]!=' ')&&(sign[8]!=' ')&&(sign[9]!=' ')
			&&(sign[4]!=' ')&&(sign[5]!=' ')&&(sign[6]!=' ')
			&&(sign[1]!=' ')&&(sign[2]!=' ')&&(sign[3]!=' '))
	{
		return 'Z';
	}
}

void Player1 (uint8 sign[],uint8 size,uint8 choice)
{
	uint8 ChoiceTries=0,FullBlock=0;
	
	while ((ChoiceTries<=3)&&(FullBlock<=3))
	{
		//correct choice
		if ((choice>=1)&&(choice<=9))
		{
			//if the block is empty
			if (sign[choice]==' ')
			{
				sign[choice]='X';
				ChoiceTries=0;
				break;
			}
			
			//if the block if full
			else
			{
				printf ("\nFull Block.\nPlayer 1, Please select another one: ");
				scanf("%d",&choice);
				FullBlock++;
			
				if (FullBlock==3)
				{
					printf ("\nYou selected a full block 3 times.\n");
				}
			}
		}	
		
		//wrong choice
		else
		{
			printf ("\nWrong choice.\nPlayer 1, Please try again: ");
			scanf ("%d",&choice);
			ChoiceTries++;
		}
	}
	
	if (ChoiceTries==3)
	{
		printf ("\nYou entered a wrong choice 3 times.");
	}
}

void Player2 (uint8 sign[],uint8 size,uint8 choice)
{
	uint8 ChoiceTries=0,FullBlock=0;
	
	while ((ChoiceTries<=3)&&(FullBlock<=3))
	{
		//correct choice
		if ((choice>=1)&&(choice<=9))
		{
			//if the block is empty
			if (sign[choice]==' ')
			{
				sign[choice]='O';
				ChoiceTries=0;
				break;
			}
			
			//if the block if full
			else
			{
				printf ("\nFull Block.\nPlayer 2, Please select another one: ");
				scanf("%d",&choice);
				FullBlock++;
			
				if (FullBlock==3)
				{
					printf ("\nYou selected a full block 3 times.\n");
				}
			}
		}	
		
		//wrong choice
		else
		{
			printf ("\nWrong choice.\nPlayer 2, Please try again: ");
			scanf ("%d",&choice);
			ChoiceTries++;
		}
	}
	
	if (ChoiceTries==3)
	{
		printf ("\nYou entered a wrong choice 3 times.");
	}
}


void MultiPlayerMode (uint8 sign[],uint8 size)
{
	uint8 i=0,j,P1,P2,Check;
	
	printf ("\n\nWelcome to Multi Player Mode:\n\n");
	printf ("Player 1: X	Player 2: O\n");
	DisplayBoard(sign,9);
	
	while (i<5)
	{
		//Player 1 trun
		printf ("\nPlayer 1, Please enter your choice: ");
		scanf ("%d",&P1);
		
		Player1 (sign,9,P1);
		DisplayBoard (sign,9);
		
		if (CheckWin(sign,9)=='X')
		{
			printf ("\n\nPlayer 1 is the winner.\n\n");
			break;
		}
			
		else if (CheckWin(sign,9)=='O')
		{
			printf ("\n\nPlayer 2 is the winner.\n\n");
			break;
		}
		
		else if (CheckWin(sign,9)=='Z')
		{
			printf ("\n\nDraw.\n\n");
			break; 
		}
		
		else
		{
			i++;
		}
		
			
		//Player 2 turn	
		printf ("\nPlayer 2, Please enter your choice: ");
		scanf ("%d",&P2);
		
		Player2 (sign,9,P2);
		DisplayBoard (sign,9);
		
		if (CheckWin(sign,9)=='X')
		{
			printf ("\n\nPlayer 1 is the winner.\n\n");
			break;
		}
		
		else if (CheckWin(sign,9)=='O')
		{
			printf ("\n\nPlayer 2 is the winner.\n\n");
			break;
		}
		
		else if (CheckWin(sign,9)=='Z')
		{
			printf ("\n\nDraw.\n\n");
			break;
		}
		else 
		{
			i++;
		}
	}
}

void Computer (uint8 sign[],uint8 size,uint8 choice)
{
	printf ("Computer's turn.\n");
	//if the block is Full
	while (sign[choice]!=' ')
	{
		choice=((rand()%10)+1);
	}
	
	//Empty block
	sign[choice] = 'O';
}

void SinglePlayerMode (uint8 sign[],uint8 size)
{
	uint8 i=0,j,choice,Check,RandomChoice; 
	
	printf ("\n\nWelcome to Single Player Mode.\n");
	printf ("You are: X		computer is: O\n");
	DisplayBoard(sign,9);
	
	while (i<5)
	{
		printf ("\nPlease enter your choice: ");
		scanf ("%d",&choice);
		Player1 (sign,9,choice);
		DisplayBoard (sign,9);
		
		if (CheckWin(sign,9)=='X')
		{
			printf ("\n\nPlayer 1 is the winner.\n\n");
			break;
		}
		
		else if (CheckWin(sign,9)=='O')
		{
			printf ("\n\nComputer is the winner.\n\n");
			break;
		}
		
		else if (CheckWin(sign,9)=='Z')
		{
			printf ("\n\nDraw.\n\n");
			break;
		}
		
		else 
		{
			i++;
		}
		
		RandomChoice=((rand()%10)+1);
	
		Computer(sign,9,RandomChoice);
		DisplayBoard (sign,9);
		
		if (CheckWin(sign,9)=='X')
		{
			printf ("\n\nPlayer 1 is the winner.\n\n");
			break;
		}
		
		else if (CheckWin(sign,9)=='O')
		{
			printf ("\n\nComputer is the winner.\n\n");
			break;
		}
		
		else if (CheckWin(sign,9)=='Z')
		{
			printf ("\n\nDraw.\n");
			break;
		}
		
		else 
		{
			i++;
		}
		
	}
}
