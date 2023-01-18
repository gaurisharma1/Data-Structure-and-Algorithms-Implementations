#include <iostream>
using namespace std;
int main()
{


    //int a[] = {2,4,6,8};
    //int a[4] = {3,5,7,9};


    //2D array//
    //for both in stack.....
    int a[2][3] = {{2,1,4},{4,5,6}};
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    //for row in stack and columns in heap.....
    int *b[3];
    b[0] = new int[3];
    b[1] = new int[5];
    b[2] = new int[7];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }


    //for row and columns both in heap.....
    int **c;
    c = new int*[4];//for rows in heap
    c[0] = new int[3];//for columns in heap
    c[1] = new int[3];//""
    c[2] = new int[3];//""
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }


}