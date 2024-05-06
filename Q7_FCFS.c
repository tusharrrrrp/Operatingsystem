// Q07. Implement a program for disk scheduling algorithm – FCFS

#include <stdio.h>
#include <stdlib.h>
// #include<conio.h>

int main()
{
    int n, i, head, current, seek_time = 0;
    // clrscr();

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the initial position of the head: ");
    scanf("%d", &head);

    printf("Enter the requests: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &current);
        printf("%d -> ", current);
        seek_time += abs(current - head);
        head = current;
    }
    printf("\nTotal seek time: %d\n", seek_time);

    // getch();
    return 0;
}

/*Output:
Enter the number of requests: 8
Enter the initial position of the head: 50
Enter the requests: 176 79 34 60 92 11 41 114
50 -> 176 -> 79 -> 34 -> 60 -> 92 -> 11 -> 41 -> 114 -> 
Total seek time: 510

176 79 34 60 92 11 41 114
*/