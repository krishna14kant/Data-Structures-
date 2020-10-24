//Perfect number, a positive integer that is equal to the sum of its proper divisors. The smallest perfect number is 6, which is the sum of 1, 2, and 3. Other perfect numbers are 28, 496, and 8,128.
//A program to check whether a number is perfect or not.

int perfect(int n)
{
    int sum = 0;
    for(int i = 1; i < n; i++)
    {
        if(n % i == 0)     //Checking proper divisors of given integer
            sum = sum + i;
    }
    if(sum == n)
        printf("Perfect");
    else
        printf("Not Perfect");
}

void main()
{
    int n;
    //Get the number to check
    scanf("%d",&n);
    perfect(n);
}
