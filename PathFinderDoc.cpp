/*PathFinder:                                                                                                ~Nitin Rohit 

This is a simple code which illustrates how the algorithm to find the path to exit works. I have added a simulation using ASCII 
characters which shows how the route is found. The path used may not be the most efficient one but it finds a way if its there.*/

//Include the necessary header files
#include<iostream>
#include<unistd.h>

using namespace std;

//Size of the grid which the maze will be created 
//The user can change the values according to the required map size
const int m=6,n=6;

int found=1;

//function to create a copy of the given array
void clone(int (*map)[n],int (*mapc)[n])
{
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    mapc[i][j]=map[i][j];
}

//function to display the map each time to create a simulation 
void display(int (*mapc)[n],int x,int y)
{
    system("cls");
    for(int i=0;i<m;i++)
    {
        cout<<"|";
        for(int j=0;j<n;j++)
        {
            if(i==x && j==y)
            cout<<":|";

            else if(mapc[i][j])
                 cout<<" |";
                 else
                 cout<<"X|";
        }
        cout<<endl;
    }
    usleep(1000000);
}

//Recerssive function to find the path using a simple rule to go in all direction until the exit is found
int route(int i,int j,int (*map)[n],int (*mapc)[n])
{
    if(found)
    display(mapc,i,j);

    if(i==(m-1) && j==(n-1))
    {
        cout<<"YOU HAVE REACHED THE END!!";
        found=0;
        return 0;
    }
    
    map[i][j]=0;

    if(map[i-1][j] && i>0)
    route(i-1,j,map,mapc);

    if(map[i][j+1] && j<n)
    route(i,j+1,map,mapc);

    if(map[i+1][j] && i<m)
    route(i+1,j,map,mapc);

    if(map[i][j-1] && j>0)
    route(i,j-1,map,mapc);

    return 0;

}

//function to get the map values from the user
void getValue(int (*map)[n])
{
    cout<<"Enter the values:"<<endl;
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    cin>>map[i][j];
}

//Then just execute the made functions in the main function
int main()
{
    int map[m][n],mapc[m][n];
    getValue(map);
    clone(map,mapc);
    route(0,0,map,mapc);

    return 0;
}