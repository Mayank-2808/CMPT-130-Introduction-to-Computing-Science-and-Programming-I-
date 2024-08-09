#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string getUnsignedBinaryRepresentationString(int x, const int L)
{
    //Pre-condition: x >= 0 and L > 0
    //Post-condition: the unsigned binary representation of x in L bit pattern is returned as a C++ string data type
    //Assume that the pre-condition is satisfied
    
    //PUT YOUR CODE HERE
    
    string s;
    string num;
    
    for(int i = 0; i < L; i++)
    {
        int n = (x/(pow(2,i)));
        
        n = n%2;
        
        if (n==0)
            num = "0";
        if (n==1)
            num = "1";
        
        s = num + s;
    }
    return s;
}
int getUnsignedBinaryDecimalValue(string s)
{
    //Pre-condition: s is non-empty and stores '0's and '1's characters
    //Post-condition: The decimal number value of the unsigned binary bits stored in s is returned
    //Assume that the pre-condition is satisfied
    
    //PUT YOUR CODE HERE
    
    int L = int (s.length());
    int num = 0;
    
    for(int i = 0,p = L-1; i<L; i++, p--)
    {
        int n;
        
        if(s[i]=='0')
            n = 0;
        if(s[i]=='1')
            n = 1;
        
        num += n*(pow(2,p));
    }
    return num;
}
string getSignAndMagnitudeBinaryRepresentationString(int x, const int L)
{
    //Pre-condition: x is any integer and L > 1
    //Post-condition: the sign and magnitude representation of x in L bit pattern is returned as a C++ string data type
    //Assume that the pre-condition is satisfied
    
    //PUT YOUR CODE HERE
    
    string s;
    string num;
    int a = abs(x);
    
    for(int i = 0; i < L-1; i++)
    {
        int n = (a/(pow(2,i)));
        
        n = n%2;
        
        if (n==0)
            num = "0";
        if (n==1)
            num = "1";
        
        s = num + s;
    }
    string p = "0";
    string n = "1";
    
    if (x < 0)
        s = n + s;
    if (x >= 0)
        s = p + s;
    
    return s;
}
int getSignAndMagnitudeBinaryDecimalValue(string s)
{
    //Pre-condition: s.length() > 1 and stores '0's and '1's characters
    //Post-condition: The decimal number value of the sign and magnitude binary bits stored in s is returned
    //Assume that the pre-condition is satisfied
    
    //PUT YOUR CODE HERE
    
    int L = int (s.length());
    int num = 0;
    
    for(int i = 1,p = L-2; i<L; i++, p--)
    {
        int n;
        
        if(s[i]=='0')
            n = 0;
        if(s[i]=='1')
            n = 1;
        
        num += n*(pow(2,p));
    }
    
    if (s[0] == '1')
        num = -1*num;
    
    return num;
}
string getBinarySumString(string s1, string s2)
{
    //Pre-condition: s1 and s2 are non-empty, have equal lengths, and store '0's and '1's characters
    //Post-condition: The binary sum of the bits in s1 and s2 is returned as a C++ string data type with the same length as s1 and s2
    //Assume that the pre-condition is satisfied
    
    //PUT YOUR CODE HERE
    
    string s;
    int L = int (s1.length());
    int carry = 0;
    
    for(int i = L-1; i >= 0; i--)
    {
    
                if(s1[i]=='1' && s2[i]=='1' && carry == 0)
                {
                    s = '0' + s;
                    carry = 1;
                }
                
                else if(s1[i]=='1' && s2[i]=='1' && carry == 1)
                {
                    s = '1' + s;
                    carry = 1;
                }
                
                else if(s1[i]=='1' && s2[i]=='0' && carry == 1)
                {
                    s = '0' + s;
                    carry = 1;
                }
                
                else if(s1[i]=='1' && s2[i]=='0' && carry == 0)
                {
                    s = '1' + s;
                    carry = 0;
                }
                
                else if(s1[i]=='0' && s2[i]=='1' && carry == 1)
                {
                    s = '0' + s;
                    carry = 1;
                }
                
                else if(s1[i]=='0' && s2[i]=='1' && carry == 0)
                {
                    s = '1' + s;
                    carry = 0;
                }
                
                else if(s1[i]=='0' && s2[i]=='0' && carry==1)
                {
                    s = '1' + s;
                    carry = 0;
                }
                
                else if(s1[i]=='0' && s2[i]=='0' && carry==0)
                {
                    s = '0' + s;
                    carry = 0;
                }
            }
    return s;
}
string getTwosComplementBinaryRepresentationString(int x, const int L)
{
    //Pre-condition: x is any integer and L > 0
    //Post-condition: the two's complement binary representation of x in L bit pattern is returned as a C++ string data type
    //Assume that the pre-condition is satisfied
    
    //PUT YOUR CODE HERE
    
    string s;
    string num;
    
    if(x>=0)
    {
        for(int i = 0; i < L; i++)
        {
            int n = (x/(pow(2,i)));
            
            n = n%2;
            
            if (n==0)
                num = "0";
            if (n==1)
                num = "1";
            
            s = num + s;
        }
    }
    
    else
    {
        int a = abs(x);
        
        for(int i = 0; i < L; i++)
        {
            int n = (a/(pow(2,i)));
            
            n = n%2;
            
            if (n==0)
                num = "1";
            if (n==1)
                num = "0";
            
            s = num + s;
        }
        
        int carry = 1;
        for (int i = L-1; i >= 0; i--)
        {
            if (s[i] =='1' && carry == 1)
            {
                s[i] = '0';
                carry = 1;
            }
            
            else if (s[i] == '0' && carry == 1)
            {
                s[i] = '1';
                carry = 0;
            }
        }
    }
    return s;
}
int getTwosComplementBinaryDecimalValue(string s)
{
    //Pre-condition: s is non-empty and stores '0's and '1's characters
    //Post-condition: The decimal number value of the two's complement binary bits stored in s is returned
    //Assume that the pre-condition is satisfied
    
    //PUT YOUR CODE HERE
    
    int num = 0;
    int L = int (s.length());
    
    if (s[0]=='0')
    {
        for(int i = 0,p = L-1; i<L; i++, p--)
        {
            int n;
            
            if(s[i]=='0')
                n = 0;
            if(s[i]=='1')
                n = 1;
            
            num += n*(pow(2,p));
        }
    }
    
    else
    {
        for(int i = 0; i < L; i++)
        {
            if (s[i]=='0')
                s[i]='1';
            
            else if (s[i]=='1')
                s[i]='0';
        }
        
        int carry = 1;
       
        for (int i = L-1; i >= 0; i--)
        {
            if (s[i] =='1' && carry == 1)
            {
                s[i] = '0';
                carry = 1;
            }
            
            else if (s[i] == '0' && carry == 1)
            {
                s[i] = '1';
                carry = 0;
            }
        }
        
        for(int i = 0,p = L-1; i<L; i++, p--)
        {
            int n;
            
            if(s[i]=='0')
                n = 0;
            if(s[i]=='1')
                n = 1;
            
            num += n*(pow(2,p));
        }
        num = -1*num;
    }
    return num;
}
int selectComputation()
{
    cout << "Select your computation" << endl;
    cout << "   1. Unsigned Binary Representation Computation" << endl;
    cout << "   2. Sign and Magnitude Representation Computation" << endl;
    cout << "   3. Two's Complement Representation Computation" << endl;
    cout << "   4. Exit Program" << endl;
    int selection;
    cout << "Enter your selection (1, 2, 3, or 4): ";
    cin >> selection;
    while (selection != 1 && selection != 2 && selection != 3 && selection != 4)
    {
        cout << "Please enter a correct choice: ";
        cin >> selection;
    }
    return selection;
}
int main()
{
    cout << "This program demonstrates numeric information representation using" << endl;
    cout << " *** Unsigned Binary Representation" << endl;
    cout << " *** Sign and Magnitude Binary Representation" << endl;
    cout << " *** Two's Complement Binary Representation" << endl << endl;
    cout << "In addition, the program demonstrates" << endl;
    cout << " *** Two's complement binary addition, and" << endl;
    cout << " *** Conversion from two's complement to decimal." << endl << endl;
    do
    {
        int selection = selectComputation();
        if (selection == 1)
        {
            int bit_pattern_size, num;
            cout << endl << "Enter a positive integer for the bit pattern size: ";
            cin >> bit_pattern_size;
            while (bit_pattern_size <= 0)
            {
                cout << "You must enter a positive integer. Enter again please: ";
                cin >> bit_pattern_size;
            }
            cout << "Enter a non-negative integer: ";
            cin >> num;
            while (num < 0)
            {
                cout << "You must enter a non-negative integer. Enter again please: ";
                cin >> num;
            }
            string s = getUnsignedBinaryRepresentationString(num, bit_pattern_size);
            cout << "The unsigned binary representation of " << num << " in " << bit_pattern_size << " bit is " << s << endl;
            int value = getUnsignedBinaryDecimalValue(s);
            cout << "This unsigned binary represents the decimal number " << value << endl;
            if (value == num)
                cout << "This is a correct result." << endl;
            else
                cout << "This is not correct result because our bit pattern is too small to store the given decimal number." << endl;
            cout << endl;
        }
        else if (selection == 2)
        {
            int bit_pattern_size, num;
            cout << endl << "Enter a positive integer greater than 1 for the bit pattern size: ";
            cin >> bit_pattern_size;
            while (bit_pattern_size <= 1)
            {
                cout << "You must enter a positive integer greater than 1. Enter again please: ";
                cin >> bit_pattern_size;
            }
            cout << "Enter an integer: ";
            cin >> num;
            string s = getSignAndMagnitudeBinaryRepresentationString(num, bit_pattern_size);
            cout << "The sign and magnitude binary representation of " << num << " in " << bit_pattern_size << " bit is " << s << endl;
            int value = getSignAndMagnitudeBinaryDecimalValue(s);
            cout << "This sign and magnitude binary represents the decimal number " << value << endl;
            if (value == num)
                cout << "This is a correct result." << endl;
            else
                cout << "This is not correct result because our bit pattern is too small to store the given decimal number." << endl;
            cout << endl;
        }
        else if (selection == 3)
        {
            int bit_pattern_size, num1, num2;
            cout << endl << "Enter a positive integer for the bit pattern size: ";
            cin >> bit_pattern_size;
            while (bit_pattern_size <= 0)
            {
                cout << "You must enter a positive integer. Enter again please: ";
                cin >> bit_pattern_size;
            }
            cout << "Enter an integer: ";
            cin >> num1;
            string s1 = getTwosComplementBinaryRepresentationString(num1, bit_pattern_size);
            cout << "The two's complement binary representation of " << num1 << " in " << bit_pattern_size << " bit is " << s1 << endl;
            cout << endl;
            cout << "Enter a second integer: ";
            cin >> num2;
            string s2 = getTwosComplementBinaryRepresentationString(num2, bit_pattern_size);
            cout << "The two's complement binary representation of " << num2 << " in " << bit_pattern_size << " bit is " << s2 << endl;
            cout << endl;
            string s3 = getBinarySumString(s1, s2);
            cout << "The binary sum of " << s1 << " and " << s2 << " is " << s3 << endl;
            int sum = getTwosComplementBinaryDecimalValue(s3);
            cout << "The sum of " << num1 << " and " << num2 << " is " << num1+num2 << " and the integer value of the binary sum is " << sum << endl;
            if (sum == num1 + num2)
                cout << "This is a correct result." << endl;
            else
                cout << "This is not correct result because our bit pattern is too small to store the sum." << endl;
        }
        else
            break;
        system("Pause");
        cout << endl << endl;
    }while (true);
    
    system("Pause");
    return 0;
}
