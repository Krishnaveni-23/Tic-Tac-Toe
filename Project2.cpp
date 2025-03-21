//tic tac toe

#include <iostream>
#include <ctime>
using namespace std; 

void drawBoard(char *space);
void playerMove(char *space,char player);
void computerMove(char *space,char computer);
bool checkWinner(char *space,char player,char computer);
bool checkTie(char *space);


int main()
{
    cout<<"TIC TAC TOE";
    
    char space[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    
    char player = 'X';
    char computer = 'O';
    bool running = true;
    
    drawBoard(space);
    
    while(running)
    {
        playerMove(space,player);
        drawBoard(space);
        if(checkWinner(space,player,computer))
        {
            running = false;
            break;
        }
        else if (checkTie(space))
        {
           running = false;
           break; 
        }
        
        computerMove(space,computer);
        drawBoard(space);
        if(checkWinner(space,player,computer))
        {
            running = false;
            break;
        }
        else if (checkTie(space))
        {
           running = false;
            break; 
        }
    }
    cout<<"thanks for playing"<<endl;
    return 0;
}

void drawBoard(char *space)
{
    cout<<'\n'<<endl;
    cout<<"     |     |   "<<endl;
    cout<<"  "<<space[0]<<"  |  "<<space[1]<<"  |  "<<space[2]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |   "<<endl;
    cout<<"  "<<space[3]<<"  |  "<<space[4]<<"  |  "<<space[5]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |   "<<endl;
    cout<<"  "<<space[6]<<"  |  "<<space[7]<<"  |  "<<space[8]<<"  "<<endl;
    cout<<"     |     |   "<<endl;
    cout<<'\n'<<endl;
   
}

void playerMove(char *space,char player)
{
    int number;
    do
    {
       cout<<"enter a number between (1 to 9):" <<endl;
       cin>>number;
       number--;
       
       if (space[number] == ' ')
       {
           space[number] = player;
           break;
       }
    }while(number > 0 && number < 9);
}

void computerMove(char *space,char computer)
{
    int number;
    srand(time(0));
    
    while(true)
    {
        number = rand() % 9;
       
        if (space[number] == ' ')
           {
               space[number] = computer;
               break;
           }  
    }   
}

bool checkWinner(char *space,char player,char computer)
{
   if ((space[0] != ' ') && (space[0] == space[1]) && (space[1] == space[2]))
   {
       space[0] == player ? cout<<"you win"<<endl : cout<<"you lose"<<endl;
   }
   
   else if ((space[3] != ' ') && (space[3] == space[4]) && (space[4] == space[5]))
   {
       space[3] == player ? cout<<"you win"<<endl : cout<<"you lose"<<endl;
   }
   
   else if ((space[6] != ' ') && (space[6] == space[7]) && (space[7] == space[8]))
   {
       space[6] == player ? cout<<"you win"<<endl : cout<<"you lose"<<endl;
   }
   
   else if ((space[0] != ' ') && (space[0] == space[3]) && (space[3] == space[6]))
   {
       space[0] == player ? cout<<"you win"<<endl : cout<<"you lose"<<endl;
   }
   
   else if ((space[1] != ' ') && (space[1] == space[4]) && (space[4] == space[7]))
   {
       space[1] == player ? cout<<"you win"<<endl : cout<<"you lose"<<endl;
   }
   
   else if ((space[2] != ' ') && (space[2] == space[5]) && (space[5] == space[8]))
   {
       space[2] == player ? cout<<"you win"<<endl : cout<<"you lose"<<endl;
   }
   
   else if ((space[0] != ' ') && (space[0] == space[4]) && (space[4] == space[8]))
   {
       space[0] == player ? cout<<"you win"<<endl : cout<<"you lose"<<endl;
   }
   
   else if ((space[2] != ' ') && (space[2] == space[4]) && (space[4] == space[6]))
   {
       space[2] == player ? cout<<"you win"<<endl : cout<<"you lose"<<endl;
   }
   else
   {
       return false;
   }
   return true;
}

bool checkTie(char *space)
{
    for (int i=0; i < 9 ;i++) 
    {
       if(space[i] == ' ')
       {
           return false;
       }
    }
    cout<<"it's a tie"<<endl;
    return true;
}
