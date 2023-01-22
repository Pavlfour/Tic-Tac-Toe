#include <iostream>
using namespace std;

void playerMove(char *str);
int checkStep(char *str);
void printTable(char *str);

int main()
{
    char gameStatus=0;
    char str[]="---------"; //This string is the table format
    printTable(str);
    while (!gameStatus)
    {
        playerMove(str);
        gameStatus = checkStep(str);
    }
    cout<<"\n\n";
    if(gameStatus=='x' || gameStatus=='o')
        cout<<"\tThe Winner is "<<gameStatus<<"!";
    else
        cout<<"\tIt's a draw!";
    cout<<"\n\n";
}

void printTable(char *str) //with two nested for loops, we're displaying the string in a table format
{
    int j=0;
    int step=3;
    cout<<"========="<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<(char)186<<" ";
        for(;j<step;j++)
        {
            cout<<str[j]<<" ";
        }
        cout<<(char)186<<endl;
        step+=3;
    }
    cout<<"========="<<endl;
}

int checkStep(char *str)
{
    for(int i=0,j=0;j<3;j++,i+=3)
    {
        if(str[i]==str[i+1]&str[i]==str[i+2]&str[i]!='-') //this line checks the rows of the table
            return str[i];
        else if(str[j]==str[j+3]&str[j]==str[j+6]&str[j]!='-') //this for the columns as well
            return str[j];
    }
    for(int i=0;i<2;i++)
    {
        if(str[2*i]==str[4]&str[2*i]==str[8-2*i]&str[2*i]!='-') //this for the diagonal
            return str[2*i];
    }
    for(int i=0;i<9;i++)
    {
        if(str[i]=='-') //if there's still empty space in the table, the game continues
            return 0;
    }
    return 1; //if none of the above code is executed,that means it's a draw
}

void playerMove(char *str)
{
    char playerChoice;
    int positionChoice;
    cout<<"x or o (lower case): ";
    cin>>playerChoice;
    if(!(playerChoice == 'x' || playerChoice == 'o'))
    {
        cout<<"Neither x nor o inserted\n";
        return;
    }
    cout<<"Give me the location[1,...,9]: ";
    cin>>positionChoice;
    if(positionChoice<1 || positionChoice>9)
    {
        cout<<"Not in the given range\n";
        return;
    }
    switch(playerChoice)
    {
    case 'x':
        if(str[positionChoice-1]!='-')
        {
            cout<<"Position "<<positionChoice<<" is already allocated"<<endl;
            return;
        }
        else
        {
            str[positionChoice-1] = playerChoice;
            printTable(str);
        }
        break;
    case 'o':
        if(str[positionChoice-1]!='-')
        {
            cout<<"Position "<<positionChoice<<" is already allocated"<<endl;
            return;
        }
        else
        {
            str[positionChoice-1] = playerChoice;
            printTable(str);
        }
        break;
    }
}
