
#include <iostream>
#include <ctime>
using namespace std;

int countPrimes (int* p, const int s)
{
    int count = 0;
    
    for (int i = 0; i < s; i++)
    {
        int count1 = 0;
        
        for (int j = 2; j < p[i]; j++)
        {
            if (p[i]%j==0)
                count1++;
        }
        if (count1==0)
            count++;
    }
    return count;
}

int* getPrimes(int* p, const int s)
{
    int size = countPrimes(p, s);
    
    int* a = new int[size];
    
    int j = 0;
    
    for (int i = 0; i < s; i++)
    {
        int count1 = 0;
        
        for (int j = 2; j < p[i]; j++)
        {
            if (p[i]%j==0)
                count1++;
        }
        if (count1==0)
        {
            a[j]=p[i];
            j++;
        }
    }
    return a;
}

int main()
{
    srand(time(0));
    int size;
    do
    {
        cout << "Enter a positive integer array size: ";
        cin >> size;
    }while (size <= 0);

    int* A = new int[size];
    
    for (int i = 0; i < size; i++)
        A[i] = rand() % 999 + 2;
    
    cout << "The elements of the array are: ";
    for (int i = 0; i < size; i++)
        cout << A[i] << "  ";
    cout << endl;
    
    int primeCount = countPrimes(A, size);
    cout << "There are " << primeCount << " elements of the array that are prime numbers." << endl;
    
    if (primeCount > 0)
    {
        int *P = getPrimes(A, size);
        cout << "The prime number elements of the array are: ";
        for (int i = 0; i < primeCount; i++)
            cout << P[i] << "  ";
        cout << endl;
        delete[] P;
    }
    delete[] A;

    system("Pause");
    return 0;
}
