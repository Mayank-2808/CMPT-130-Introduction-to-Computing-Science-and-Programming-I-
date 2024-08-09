#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

void rotateLeft (char* X)
{
    char a = X[0];
    int len = strlen(X);
    
    for(int i = 0; i < (len-1); i++)
        X[i] = X[i+1];
    
    X[len-1] = a;
}

void rotateRight (char* X)
{
    int len = strlen(X);
    char a = X[len-1];
    
    for(int i = (len-1); i > 0;i--)
        X[i] = X[i-1];
    
    X[0] = a;
}

void rotate_cstring(char* X, const int i)
{
    if(i >= 0)
    {
        for(int j = 0; j < i; j++)
            rotateLeft(X);
    }
    else
    {
        int a = abs(i);
        for(int j = 0; j < a ; j++)
            rotateRight(X);
    }
}

char* get_random_cstring()
{
    int len = rand() % 10 + 10;
    char* C = new char[len+1];
    for (int i = 0; i < len; i++)
        C[i] = rand() % 26 + 'a';
    C[len] = '\0';
    return C;
}
int main()
{
    srand(time(0));
    char *C = get_random_cstring();
    cout << "We have constructed the cstring " << C << endl;
    for (int i = 0; i < 10; i++)
    {
        int m = rand() % 21 + -10;
        if (m >= 0)
        {
            cout << "\tRotating the cstring " << C << " by " << m << " positions to the left, we get ";
            rotate_cstring(C, m);
            cout << C << endl;
        }
        else
        {
            cout << "\tRotating the cstring " << C << " by " << abs(m) << " positions to the right, we get ";
            rotate_cstring(C, m);
            cout << C << endl;
        }
    }
    delete[] C;
    
    system("Pause");
    return 0;
}
