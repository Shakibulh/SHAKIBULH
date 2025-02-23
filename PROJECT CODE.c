#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int arr[5555][5555];
int subFunction(int num)
{
    int row,colum;
    srand(time(0));
    for ( row=1; row<=num; row++ )
    {
        for ( colum=1; colum<=num; colum++ )
        {
            arr[row][colum]= rand()%2;
        }
    }
    return 0;
}
int main_function()
{
    time_t t1,t2;
    double ti;
    t1=clock();
    int num;
    int degree, row, colum;
    printf("\n Enter the number of Vertices : ");
    scanf("%d",&num);
    subFunction(num);
    for( row=1; row<=num; row++ )
    {
        for( colum=1; colum<=num; colum++ )
        {
            arr[colum][row]=arr[row][colum];
        }
    }
    printf("\n Vertex \tDegree \n");
    int total=0;
    for ( row = 1; row <= num ; row++ )
    {
        degree = 0;
        for ( colum = 1 ; colum <= num ; colum++ )
        {
            if ( arr[row][colum] == 1 )
            {
                degree++;
                total++;
                if( row == colum )
                {
                    degree++;
                    total++;
                }
            }
        }
        printf("%5d\t\t%d\n",row,degree);
    }
    printf("Total Degree is: %d\n",total);
    int edge=0;
    for( row=1; row<=num; row++ )
    {
        for( colum=1; colum<=num; colum++ )
        {
            if( colum <= row )
            {
                edge =edge+ arr[row][colum];
            }
        }
    }
    printf("Sum of lower triangular adjacency matrix / Edge = %d\n\n", edge);
    if( edge*2 == total )
    {
        printf("Handshaking theorem is working\n");
    }
    else
    {
        printf("Handshaking theorem is not working\n");
    }
    t2 = clock();
    ti = ((((double)t2 - (double)t1))/CLOCKS_PER_SEC)*1000;
    printf("Time is: %lf ms\n",ti);
    return;
}
void main()
{
    printf("\n A graph by using Adjacency Matrix  ");
    printf("\n Undirected Graph :\n");
    main_function();
    return 0;
}
