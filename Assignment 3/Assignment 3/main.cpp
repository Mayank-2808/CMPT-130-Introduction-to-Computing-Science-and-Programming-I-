#include <iostream>
#include <ctime>
using namespace std;

int cstrlen(const char *C)
{
//Pre-condition: C is a cstring. This means it has a null character at the end
//Post-condition: returns the length of C. That is the number of printable characters in C

//PUT YOUR CODE HERE

    int index = 0;

    while(C[index] != '\0')
    index++;

    return index;
}

char* getPaddedNumber(const char *N, const int m)
{
    
//Pre-condition: N is a cstring containing only digit characters
//Post-condition: returns a new cstring that contains m zero digits followed by the digits of N

//For example, if N is "38106" and m = 4 then the function returns a new cstring "000038106"

//PUT YOUR CODE HERE
    
    int length = cstrlen(N) + m;
    
    char* A = new char[length + 1];
    
    int i = 0;
    
    for(; i < m; i++)
        A[i] = '0';
    
    for(int j = 0; j < (length-m); j++,i++)
        A[i] = N[j];
    
    A[i] = '\0';
    
    return A;
}

bool isEqualTo(const char *N1, const char *N2)
{
//Pre-condition: N1 and N2 are cstrings containing only digit characters
//Post-condition: returns true if the numeric values of N1 and N2 are equal. Returns false otherwise

//Remark: The numeric value of N1 is the non-negative integer value represented by the digits of N1
//Similarly the numeric value of N2 is the non-negative integer value represented by the digits of N2

//For example, if N1 = "000076" and N2 = "76" then isEqualTo(N1, N2) must return true

//Remark: Please note that N1 and N2 may have different lengths. Moreover there might be some zero
//    digits on the left side of N1 or N2. Thus you may need to first compute temporary padded numbers
//    using the getPaddedNumber function in order to create same length cstrings corresponding to N1
//    and N2 and then loop from left to right on the same length cstrings.
//    For example, if N1 = "000065" and N2 = "65" then it is better to first create
//    char *X1 = getPaddedNumber(N1, 0); //In this example, X1 needs no padding
//    char *X2 = getPaddedNumber(N2, 4); //In this example, X2 needs 4 zeros padding
//    and then work on X1 and X2.
//    Of course you need to delete both X1 and X2 before you return from the function in order to
//    clean up the heap memory.

//PUT YOUR CODE HERE

    int length = cstrlen(N1) > cstrlen(N2) ? cstrlen(N1) : cstrlen(N2);
    
    char* X1 = getPaddedNumber(N1, (length-cstrlen(N1)));
    char* X2 = getPaddedNumber(N2, (length-cstrlen(N2)));
    
    for(int i = 0; i < length; i++)
    {
        if(X1[i]==X2[i])
            continue;
        else
            return false;
    }
    
    delete[] X1;
    delete[] X2;
    return true;
}

bool isNotEqualTo(const char *N1, const char *N2)
{
//Pre-condition: N1 and N2 are cstrings containing only digit characters
//Post-condition: returns true if the numeric values of N1 and N2 are not equal.
//    Returns false otherwise

//Remark: See the explanation on the isEqualTo function for more details

//PUT YOUR CODE HERE

    return (!isEqualTo(N1, N2));
}

bool isGreaterThan(const char *N1, const char *N2)
{
//Pre-condition: N1 and N2 are cstrings containing only digit characters
//Post-condition: returns true if the numeric value of N1 is greater than the numeric value of N2
//                    Returns false otherwise

//Remark: The numeric value of N1 is the non-negative integer value represented by the digits of N1
//Similarly the numeric value of N2 is the non-negative integer value represented by the digits of N2

//For example, if N1 = "76527384" and N2 = 390142" then isGreaterThan(N1, N2) must return true

//Remark: Please note that N1 and N2 may have different lengths. Moreover there might be some zero
//    digits on the left side of N1 or N2. Thus you may need to first compute temporary padded numbers
//    using the getPaddedNumber function in order to create same length cstrings corresponding to N1
//    and N2 and then loop from left to right on the same length cstrings.
//    For example, if N1 = "000065" and N2 = "234" then it is better to first create
//    char *X1 = getPaddedNumber(N1, 0); //In this example, X1 needs no padding
//    char *X2 = getPaddedNumber(N2, 3); //In this example, X2 needs 3 zeros padding
//    and then work on X1 and X2.
//    Of course you need to delete both X1 and X2 before you return from the function in order to
//    clean up the heap memory.

//PUT YOUR CODE HERE

    int length = cstrlen(N1) > cstrlen(N2) ? cstrlen(N1) : cstrlen(N2);
    
    char* X1 = getPaddedNumber(N1, (length-cstrlen(N1)));
    char* X2 = getPaddedNumber(N2, (length-cstrlen(N2)));
    
    for(int i = 0; i < length; i++)
    {
        if(X1[i]==X2[i])
            continue;
        else if(X1[i] > X2[i])
        {
            delete[] X1;
            delete[] X2;
            return true;
        }
        else if(X1[i] < X2[i])
        {
            delete[] X1;
            delete[] X2;
            return false;
        }
    }
    
    delete[] X1;
    delete[] X2;
    return false;
}
bool isGreaterThanOrEqualTo(const char *N1, const char *N2)
{
//Pre-condition: N1 and N2 are cstrings containing only digit characters
//Post-condition: returns true if the numeric value of N1 is greater than or equal to that of N2
//                    Returns false otherwise

//Remark: The numeric value of N1 is the non-negative integer value represented by the digits of N1
//Similarly the numeric value of N2 is the non-negative integer value represented by the digits of N2

//Remark: See the explanation on the isGreaterThan function for more details

//PUT YOUR CODE HERE

    int length = cstrlen(N1) > cstrlen(N2) ? cstrlen(N1) : cstrlen(N2);
    
    char* X1 = getPaddedNumber(N1, (length-cstrlen(N1)));
    char* X2 = getPaddedNumber(N2, (length-cstrlen(N2)));
    
    for(int i = 0; i < length; i++)
    {
        if(X1[i]==X2[i])
            continue;
        else if(X1[i] > X2[i])
        {
            delete[] X1;
            delete[] X2;
            return true;
        }
        else if(X1[i] < X2[i])
        {
            delete[] X1;
            delete[] X2;
            return false;
        }
    }
    
    delete[] X1;
    delete[] X2;
    return true;
}

bool isLessThan(const char *N1, const char *N2)
{
//Pre-condition: N1 and N2 are cstrings containing only digit characters
//Post-condition: returns true if the numeric value of N1 is less than the numeric value of N2
//                    Returns false otherwise

//Remark: The numeric value of N1 is the non-negative integer value represented by the digits of N1
//Similarly the numeric value of N2 is the non-negative integer value represented by the digits of N2

//Remark: See the explanation on the isGreaterThan function for more details

//PUT YOUR CODE HERE

    return (!isGreaterThan(N1, N2) && !isEqualTo(N1, N2));
}

bool isLessThanOrEqualTo(const char *N1, const char *N2)
{
//Pre-condition: N1 and N2 are cstrings containing only digit characters
//Post-condition: returns true if the numeric value of N1 is less than or equal to that of N2
//                    Returns false otherwise

//Remark: The numeric value of N1 is the non-negative integer value represented by the digits of N1
//Similarly the numeric value of N2 is the non-negative integer value represented by the digits of N2

//Remark: See the explanation on the isGreaterThan function for more details

//PUT YOUR CODE HERE

    int length = cstrlen(N1) > cstrlen(N2) ? cstrlen(N1) : cstrlen(N2);
    
    char* X1 = getPaddedNumber(N1, (length-cstrlen(N1)));
    char* X2 = getPaddedNumber(N2, (length-cstrlen(N2)));
    
    for(int i = 0; i < length; i++)
    {
        if(X1[i]==X2[i])
            continue;
        else if(X1[i] > X2[i])
        {
            delete[] X1;
            delete[] X2;
            return false;
        }
        else if(X1[i] < X2[i])
        {
            delete[] X1;
            delete[] X2;
            return true;
        }
    }
    
    delete[] X1;
    delete[] X2;
    return true;
}

char* sum(const char *N1, const char *N2)
{
//Pre-condition: N1 and N2 are cstrings containing only digit characters
//Post-condition: returns the sum of the numeric values N1 and N2 as a cstring

//Remark: The numeric value of N1 is the non-negative integer value represented by the digits of N1
//Similarly the numeric value of N2 is the non-negative integer value represented by the digits of N2

//For example, if N1 = "76527384" and N2 = "390142" then sum(N1, N2) must return the cstring "76917526"

//Remark: Please note that N1 and N2 may have different lengths. Moreover there might be some zero
//    digits on the left side of N1 or N2. Thus you may need to first compute temporary padded numbers
//    using the getPaddedNumber function in order to create same length cstrings corresponding to N1
//    and N2 and then loop from right to left on the same length cstrings.
//    For example, if N1 = "000065" and N2 = "234" then it is better to first create
//    char *X1 = getPaddedNumber(N1, 0); //In this example, X1 needs no padding
//    char *X2 = getPaddedNumber(N2, 3); //In this example, X2 needs 3 zeros padding
//    and then work on X1 and X2 looping from right to left.
//    Of course you need to delete both X1 and X2 before you return from the function in order to
//    clean up the heap memory.

//Remark: The returned value of this function may have some zeros on the left but not more zeros
//    than found in N1 or N2. For example if N1 = "00000654" and N2 = "00543" then the returned
//    value can have upto a maximum of five zeros or less but not more. This means your returned
//    value can be "000001197" or "00001197" or "0001197" or "001197" or "01197" or "1197". They
//    are all fine. However if neither N1 nor N2 has any zeros on the left then your answer also
//    must NOT have any zeros on the left. Thus if N1 = "654" and N2 = "543" then your returned
//    value must be "1197" (that is no zeros on the left).

//PUT YOUR CODE HERE
    
    int length = cstrlen(N1) > cstrlen(N2) ? cstrlen(N1) : cstrlen(N2);
    
    char* X1 = getPaddedNumber(N1, (length-cstrlen(N1)));
    char* X2 = getPaddedNumber(N2, (length-cstrlen(N2)));
    
    int carry = 0;
    char* sum = new char[length+2];
    
    int j = length;
    
    for(int i = (length-1); i >= 0; i--)
    {
        int a = X1[i] + X2[i] - 48 + carry;
        
        if((X1[i] + X2[i]) + carry > 105)
            carry = 1;
        else
            carry = 0;
        
        if ( a > 57)
            a = a - 10;
        
        sum[j] = a;
        j--;
    }
    
    sum[0] = carry + 48;
    sum[length + 1] = '\0';
    
    int i = 0;
    
    while(sum[i]==48)
        i++;
    
    char* sum1 = new char[length + 2 - i];
    
    for(int c = 0; i < length + 2; i++,c++)
        sum1[c] = sum[i];
    
    delete[] X1;
    delete[] X2;
    delete[] sum;
    return sum1;
}

char* multiply(const char *N, const char digit)
{
//Pre-condition: N is a cstring containing only digit characters and digit is a digit character
//Post-condition: returns the product of the numeric values of N and digit as a cstring

//Remark: The numeric value of N is the non-negative integer value represented by the digits of N
//    and the numeric value of digit is the non-negative one digit integer represented by digit

//For example, if N = "76527384" and digit = '3' then multiply(N, digit) must return
//the cstring "229582152"

//Remark: The returned value of this function may have some zeros on the left but not more zeros
//    than found in N. For example if N = "00000654" and digit = "5" then the returned value
//    can have upto a maximum of five zeros or less but not more. This means your returned
//    value can be "000003270" or "00003270" or "0003270" or "003270" or "03270" or "3270". They
//    are all fine. However if N does not have any zeros on the left then your answer also
//    must NOT have any zeros on the left. Thus if N = "654" and digit = "5" then your returned
//    value must be "3270" (that is no zeros on the left).

//PUT YOUR CODE HERE
    
    char* product = new char[cstrlen(N) + 1];
    
    if (digit==48)
    {
        product[0] = '0';
        product[1] = '\0';
        
        return product;
    }
    
    for ( int i = 0; i < cstrlen(N);i++)
        product[i] = '0';
    
    product[cstrlen(N)] = '\0';
    
    for(int i = 0; i < digit-48; i++)
    {
        product = sum(product, N);
    }
    
    return product;
}

char* multiply(const char *N1, const char *N2)
{
//Pre-condition: N1 and N2 are cstrings containing only digit characters
//Post-condition: returns the product of the numeric values N1 and N2 as a cstring

//Remark: The numeric value of N1 is the non-negative integer value represented by the digits of N1
//Similarly the numeric value of N2 is the non-negative integer value represented by the digits of N2

//For example, if N1 = "76527384" and N2 = "390142" then multiply(N1, N2) must return
//    the cstring "29856546648528"

//This function is implemented for you. It makes use of the multiply by digit function.
//In order to understand the logic in this function you need to remember
//        567  N1
//      x 321  N2
//     ------
//        567
//      11340
// + 170100
//    --------
//which is equal to 567 + 11340 + 170100 = 182007
    int len2 = cstrlen(N2);
    char *ans = new char[2];
    ans[0] = '0';
    ans[1] = '\0';
    int count = 0;
    for (int i = len2-1; i >= 0; i--)
    {
        char *temp1 = multiply(N1, N2[i]);
        //Put as many as count zeros on the right side of temp1
        int len = cstrlen(temp1);
        char *temp2 = new char[len + count + 1];
        for (int i = 0; i < len; i++)
            temp2[i] = temp1[i];
        for (int i = 0; i < count; i++)
            temp2[len+i] = '0';
        temp2[len + count] = '\0';
        //Compute the sum of ans and temp2
        char *temp3 = sum(ans, temp2);
        //Delete heap memory no more needed
        delete[] temp1;
        delete[] temp2;
        delete[] ans;
        //Assign ans the value of temp3
        ans = temp3;
        //Increment count
        count++;
    }
    return ans;
}

char* divide(const char *N1, const char *N2)
{
//Pre-condition: N1 and N2 are cstrings containing only digit characters
//Post-condition: returns the quotient of numeric value N1 divided by N2 as a cstring
//    The division operation is integer division

//Remark: The numeric value of N1 is the non-negative integer value represented by the digits of N1
//Similarly the numeric value of N2 is the non-negative integer value represented by the digits of N2

//For example, if N1 = "76527384" and N2 = "390142" then multiply(N1, N2) must return
//    the cstring "196"

//For the sake of easy computation, we will use incremental iteration to compute the quotient
//    This will be a very slow algorithm but it is alright for CMPT 130 level

//This function is implemented for you
    char *q = new char[2];
    q[0] = '0';
    q[1] = '\0';
    if (isEqualTo(N2, "0"))
    {
        cout << "ERROR! Division by zero. Returning zero result." << endl;
        return q;
    }
    else
    {
        while (true)
        {
            char *temp1 = sum(q, "1");
            char *temp2 = multiply(N2, temp1);
            if (isLessThanOrEqualTo(temp2, N1))
            {
                delete[] temp2;
                delete[] q;
                q = temp1;
            }
            else
            {
                delete[] temp1;
                delete[] temp2;
                break;
            }
        }
        return q;
    }
}

char* getRandomNumber()
{
//Pre-condition: None
//Post-condition: returns a cstring containing digit characters only
    int len = 10 + rand() % 5;
    char *N = new char[len + 1];
    for (int i = 0; i < len; i++)
        N[i] = rand() % 10 + '0';
    N[len] = '\0';
    return N;
}

int main()
{
    srand(time(0));
    //Perform several tests
    char *N1, *N2;
    for (int i = 0; i < 10; i++)
    {
        cout << "Test #" << i+1 << endl;
        //Generate two random numbers
        N1 = getRandomNumber();
        N2 = getRandomNumber();

        //Print the numbers N1 and N2
        cout << "N1 = " << N1 << endl;
        cout << "N2 = " << N2 << endl;

        //Test the cstrlen function
        cout << "The length of " << N1 << " is " << cstrlen(N1) << endl;

        //Test the getPaddedNumber function
        int m = rand() % 5;
        char *pN = getPaddedNumber(N1, m);
        cout << N1 << " padded with " << m << " zeros gives " << pN << endl;
        delete[] pN;

        //Test the isEqualTo function
        if (isEqualTo(N1, N2))
            cout << N1 << " and " << N2 << " are equal." << endl;
        else
            cout << N1 << " and " << N2 << " are not equal." << endl;

        //Test the isNotEqualTo function
        if (isNotEqualTo(N1, N2))
            cout << N1 << " and " << N2 << " are not equal." << endl;
        else
            cout << N1 << " and " << N2 << " are equal." << endl;

        //Test the isGreaterThan function
        if (isGreaterThan(N1, N2))
            cout << N1 << " is greater than " << N2 << endl;
        else
            cout << N1 << " is not greater than " << N2 << endl;

        //Test the isGreaterThanOrEqualTo function
        if (isGreaterThanOrEqualTo(N1, N2))
            cout << N1 << " is greater than or equal to " << N2 << endl;
        else
            cout << N1 << " is not greater than or equal to " << N2 << endl;

        //Test the isLessThan function
        if (isLessThan(N1, N2))
            cout << N1 << " is less than " << N2 << endl;
        else
            cout << N1 << " is not less than " << N2 << endl;

        //Test the isLessThanOrEqualTo function
        if (isLessThanOrEqualTo(N1, N2))
            cout << N1 << " is less than or equal to " << N2 << endl;
        else
            cout << N1 << " is not less than or equal to " << N2 << endl;

        //Test the sum function
        char *s = sum(N1, N2);
        cout << "The sum of " << N1 << " and " << N2 << " is " << s << endl;
        delete[] s;

        //Test the multiply by a digit function
        char digit = rand() % 10 + '0';
        char *p = multiply(N1, digit);
        cout << "The product of " << N1 << " and " << digit << " is " << p << endl;
        delete[] p;

        //Test the multiply function
        p = multiply(N1, N2);
        cout << "The product of " << N1 << " and " << N2 << " is " << p << endl;
        delete[] p;

        //Test the divide function
        char *q = divide(N1, N2);
        cout << "Dividing " << N1 << " by " << N2 << " gives " << q << endl;
        delete[] q;

        delete[] N1;
        delete[] N2;
        cout << "=================================================" << endl;
    }
    system("Pause");
    return 0;
}
