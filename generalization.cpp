#include <stdio.h>
int gcd(int a, int b) 
{
    while (b != 0) 
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int isCoprime(int a, int b) 
{
    return gcd(a, b) == 1;
}
int main() 
{
    int a, b;
    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);

    if (!isCoprime(b, 26))
    {    
        printf("Error: 'b' must be coprime to 26 for one-to-one encryption.\n");
        return 1;
    }
    if (!isCoprime(a, 26)) 
    {
        printf("Error: 'a' must be coprime to 26 for one-to-one encryption.\n");
        return 1;
    }
    printf("Valid values of a and b for one-to-one encryption.\n");
    return 0;
}

