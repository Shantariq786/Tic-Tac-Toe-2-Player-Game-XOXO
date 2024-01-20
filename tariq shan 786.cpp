#include<iostream>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn = 'X';
int row,coloumn;
bool gamedraw=false;
void display_board()
{
	system("cls");
	cout<<"\n\n        #TICK TOC TOE GAME"<<endl;
	cout<<"\tPlayer1[X] \n\tPlayer2[O]\n\n";
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t  "<< board[0][0]<<"  |  "<<board[0][1]<<" |  "<<board[0][2]<<"  \n";
	cout<<"\t\t_____|_____|_____\n";
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \n";
	cout<<"\t\t_____|_____|_____\n";
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \n";
	cout<<"\t\t     |     |     \n";
}

void player_turn()
{
	int choice;
	if (turn == 'X')
	cout<<"\n\t Player1 [X] Turn:";
	if (turn == 'O')
	cout<<"\n\t Player2 [O] Turn:";
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
		row=0 ; coloumn=0 ; break;
	    }
		case 2:
			{
		row=0 ; coloumn=1 ; break;
	}
		case 3:
			{
		row=0 ; coloumn=2 ; break;
	}
		case 4:
			{
		row=1 ; coloumn=0 ; break;
	}
		case 5:
			{
		row=1 ; coloumn=1 ; break;
	}
		case 6:
			{
		row=1 ; coloumn=2 ; break;
	}
		case 7:
			{
		row=2 ; coloumn=0 ; break;
	}
		case 8:
			{
		row=2 ; coloumn=1 ; break;
	}
		case 9:
			{
		row=2 ; coloumn=2 ; break;
	}
		
		default:
			{
			cout<<"Invalid choice\n";
		}
	}
	if (turn=='X' && board[row][coloumn]!='X' && board[row][coloumn]!='O')//i applied the condition after first 'and' to check that it is must that the box should not filled with x or o than there will be no repetition of x over x or vice versa,
	{
		board[row][coloumn]='X';
		turn='O';
	}
	else if (turn=='O'  && board[row][coloumn]!='X' && board[row][coloumn]!='O')//i applied the condition after first 'and' to check that it is must that the box should not filled with x or o than there will be no repetition of x over x or vice versa,
	{
		board[row][coloumn]='O';
		turn='X';
	}
	else
	{
		cout<<"\tBox is allready filled! Please try again :)";
		player_turn();// I called the function again here to execute the fuction again tu get the turn of user again;
	}
	display_board();//After the execution of all above code i called the function again here tu display the board again;
}
bool gameover()
	// check win
	{
		for(int i=0;i<3;i++)
		{// This loop will execute to check weather the the any player has not win the game.
		if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])//it will compare the column 1,2 and 3 to check either they hace have same values, e-g all 'X or all 'O.And after and the condition explains that we will compare rows,
		return false;
	    }
	    
	    
	    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])// This will check along dignolas weather the one of the two players win the game or not!
	    {
	    return false;
	    }
		//if there is any box which is not filled
		for(int i=0;i<3;i++)
		{
		  for(int j=0;j<3;j++)
		  {
    		if(board[i][j]!='X' && board[i][j]!='O')
		    return true;
		  }
        	}
		
		//To display draw if no one of both players win the game,
		gamedraw=true;
		return false;
		}


int main()
{
	while(gameover())
	{
    display_board();
	player_turn();
	gameover();
	}
	
	
	if(turn=='X' && gamedraw == false) // we will display the message of "Win" only when these both conditions will statisfy,
	{
		cout<<"Player2 [O] Wins! Congrats:)\n";
	}
	else if(turn=='O' && gamedraw == false)
	{
		cout<<"Player1 [X] Wins! Congrats:)\n";
	}
	else
	{
		cout<<"GAME DRAW!!\n";
	}
}
