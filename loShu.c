#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int M = 3;
const int N = 3;

int checkLoShu(int [M][N]);

int main()
{

    int noLoShu[][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int loShu[][3] = {{4,9,2},{3,5,7},{8,1,6}}; 
    if(checkLoShu(noLoShu))
        printf("1. it is Lo Shu \n");
    else
        printf("1. it is not Lo shu\n");
    if(checkLoShu(loShu))
        printf("2. it is Lo Shu \n");
    else
        printf("2. it is not Lo shu\n");

    time_t t;
    // Init random number generator
    srand((unsigned) time(&t));

    
    int loShuOrNo = 0;
    int attempt = 0;
    int test [3][3];
    do
    {
        // create 2d array with random int
        for(int row = 0; row < 3; row++)
        {
            for(int col = 0; col < 3; col++)
            {
                test[row][col] = rand()%10;
            }
        }
        // check if it is Lo Shu 
        loShuOrNo = checkLoShu(test);
        attempt++;
    } while (loShuOrNo == 0);
    
    // print attempts
    printf("Total number of sqaures generated and tested before success: ");
    printf("%d\n",attempt);
    // print the sqaure
    for(int row = 0; row < 3; row++)
    {
        printf("[ ");
        for(int col = 0; col < 3; col++)
        {
            printf("%d ",test[row][col]);
        }
        printf("]");
        printf("\n");
    }
    
    
    
    
    return 0;
}

int checkLoShu(int arr[M][N])
{
    int check = 0;
    int checking = 0;
    // check if rows, columns, and diagonal is add up to 15
    if(arr[0][0]+arr[0][1]+arr[0][2] == 15 &&
       arr[1][0]+arr[1][1]+arr[1][2] == 15 &&
       arr[2][0]+arr[2][1]+arr[2][2] == 15 &&
       arr[0][0]+arr[1][0]+arr[2][0] == 15 &&
       arr[0][1]+arr[1][1]+arr[2][1] == 15 &&
       arr[0][2]+arr[1][2]+arr[2][2] == 15 &&
       arr[0][0]+arr[1][1]+arr[2][2] == 15 &&
       arr[0][2]+arr[1][1]+arr[2][0] == 15
       )
       checking = 0;
    else
        checking = checking + 1;
    // 1d array 
    int sorted[] = {0,0,0,0,0,0,0,0,0};
    int count = 0;
    for (int row = 0; row < 3;  row++)
    {
        for(int col = 0; col < 3; col++)
        {
            sorted[count] = arr[row][col];
            count = count + 1;
        }
    }
    // check if any elements are less than 0 or greater than 10
    for (int index = 0; index < 9; index++)
    {
        if(sorted[index] > 10 || sorted[index] < 0)
            checking = checking + 1;
    }
    // check if there is duplicates
    for (int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(i != j && sorted[i] == sorted[j])
                checking = checking + 1;
        }
    }

    if(checking == 0)
        check = 1;
    else
        check = 0;


    return check;
}