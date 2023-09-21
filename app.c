#include "STD_TYPES.h"
#include "TicTacToe.h"
#include <stdio.h>

int main ()
{
	uint8 ModeSelect,WrongChoice=0,PlayAgain='Y';
	
	while ((PlayAgain=='Y')||(PlayAgain=='y'))
	{
		TableInit(sign,9);
		
		printf ("\n\nWelcome to Tic Tac Toe game.\n\n");
		printf ("To select MultiPlayer mode please select: M\n");
		printf ("To select Single Player mode please select: S\n");
		printf ("Your choice: ");
		scanf (" %c",&ModeSelect);
		
		while (WrongChoice<=3)
		{
			if ((ModeSelect=='M')||(ModeSelect=='m'))
			{
				WrongChoice=0;
				MultiPlayerMode(sign,9);
				break;
			}
			
			else if ((ModeSelect=='s')||(ModeSelect=='S'))
			{
				WrongChoice=0;
				SinglePlayerMode(sign,9);
				break;
			}
			
			else 
			{
				printf ("Wrong choice please try again: ");
				WrongChoice++;
			}
		}
		
		if (WrongChoice==3)
		{
			printf ("Sorry, you selected a wrong choice 3 times.");
		}
		
		else
		{
			printf ("\n\nTo play again Please select Y.\n");
			printf ("To quit please select any other key.\n");
			printf ("\nYour choice: ");
			scanf (" %c",&PlayAgain);
		}
	}
	
	printf ("\n\t\t\tTHANK YOU.\n\n");
}

