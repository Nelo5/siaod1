#include <iostream>
using namespace std;

void delFirstMethod(int *x, int& n, int key) {
    int i = 0;
    while (i < n) 
    {
        if (x[i] == key) 
        {
            for (int j = i; j < n - 1; j++) 
            {
                x[j] = x[j + 1];
            }
            n--;
        }
        else 
        {
            i++;
        }
    }
}

void delOtherMethod(int* x, int& n, int key) {
    int j = 0;
    for (int i = 0; i < n; i++) 
    {
        x[j] = x[i];
        if (x[i] != key) { j++; }
    }
    n = j;
}

void printArray(int* x,int n) {
    for (int i = 0; i < n; i++) 
    {
        cout << x[i] << " ";
    }
}

void randomArray(int* x,int n) 
{
    for (int i = 0;i<n;i++) 
    {
        x[i] = rand()%INT_MAX;
    }
}

int MaxAboveMain(int** x, int n)
{
    int max_i = x[0][1];
    for (int i = 0; i < n-1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (x[i][j] > max_i) 
            {
                max_i = x[i][j];
            }
        }
    }
    return max_i;
}



int main()
{
    srand(time(0));
    int n = 4;
    int n1 = 5;
    int m = 5;
    int key = 2;
    int* x = new int[n] {1,2,4,2};
    int** matrix = new int* [n1];
    for (int i = 0; i < n1; i++) {
        matrix[i] = new int[m];
    }
    randomArray(x, n);
    //delOtherMethod(x, n, key);
    delFirstMethod(x, n, key);
    printArray(x,n);
    cout <<endl<< n;
    MaxAboveMain(matrix,n);
    delete []x;
}

