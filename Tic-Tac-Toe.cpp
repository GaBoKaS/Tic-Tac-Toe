#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
int board[]={0,0,0, 0,0,0, 0,0,0};
int MoveNr=0;
bool GameOver=false;
int Draw=0, Xwin=0, Owin=0;
void Move()
{
    MoveNr++;
    int place;
    if(MoveNr%2!=0) cout<<"\n   X ";
    else cout<<"\n   O ";
    cout<<"Player move:";
    cin>>place;
    cout<<endl;
    if(board[place-1]==0 && place<=9 && place >=1)
    {
        if(MoveNr%2!=0)
            board[place-1]=1;
         else if(MoveNr%2==0)
            board[place-1]=2;
    }

    else MoveNr--;

}
void Screen()
{
    cout<<"---Tic-Tac-Toe!!!---\n   ";
    for(int i=6;i<9; i++)
    {
        cout<<setw(3);
        if(board[i]==1) cout<<"X";
        else if(board[i]==2) cout<<"O";
        else cout<<" ";
        if((i+1)%3==0) cout<<endl<<"   ------------\n   ";
        else cout<<"|";
    }
    for(int i=3;i<6; i++)
    {
        cout<<setw(3);
        if(board[i]==1) cout<<"X";
        else if(board[i]==2) cout<<"O";
        else cout<<" ";
        if((i+1)%3==0) cout<<endl<<"   ------------\n   ";
        else cout<<"|";
    }
    for(int i=0;i<3; i++)
    {
        cout<<setw(3);
        if(board[i]==1) cout<<"X";
        else if(board[i]==2) cout<<"O";
        else cout<<" ";
        if(i!=2) cout<<"|";
    }
    cout<<endl<<"Moves done this game:"<<MoveNr<<endl;

    if(Xwin>0) cout<<"\nX Player won "<<Xwin<< " times.\n";
    if(Owin>0) cout<<"\nY Player won "<<Owin<< " times.\n";
    if(Draw>0) cout<<"\nDraw count: "<<Draw<<endl;

}
int Test()
{
    for(int i=1; i<=2;i++)
    {
        if(board[0]==i && board[1]==i && board[2]==i ||
           board[3]==i && board[4]==i && board[5]==i ||
           board[6]==i && board[7]==i && board[8]==i ||
           board[0]==i && board[3]==i && board[6]==i ||
           board[1]==i && board[4]==i && board[7]==i ||
           board[2]==i && board[5]==i && board[8]==i ||
           board[0]==i && board[4]==i && board[8]==i ||
           board[2]==i && board[4]==i && board[6]==i )
           return i;
    }
    return 0;
}
void Reset()
{
    for(int i=0; i<9; i++)
    board[i]=0;
    MoveNr=0;
}
void Win()
{
    system("cls");
    Screen();
    cout<<"\nPlayer ";
    if(Test()==1){cout<<"X"; Xwin++;}
    else {cout<<"O"; Owin++;}
    cout<<" Won!!!\n";
    cout<<"Press ENTER to restart:";
    Reset();
    system("pause");
    system("cls");
}
int main()
{
    while(!GameOver)
    {
        Screen();
        Move();
        if(Test()!=0) Win();
        else system("cls");
        if(MoveNr==9)
        {
            Reset();
            cout<<"Nobody Won, reseted\n";
            Draw++;
        }
    }
}
