#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int Random(int n)
{
    srand(time(NULL));
    return rand()%n;
}

void Fullname(char c)
{
    if(c == 's')
    {
        printf("Choosen 'Snake'\n\n");
    }
    else if(c == 'w')
    {
        printf("Choosen 'Water'\n\n");
    }
    else if(c == 'g')
    {
        printf("Choosen 'Gun'\n\n");
    }
    else
    {
        printf("Error!..you choose invalid character\n");
    }

}

int compResult(char you, char cpu)
{
    if(you == cpu)
    {
        return 0;
    }
    else if(you == 's' && cpu == 'w')
    {
        return 1;
    }
    else if(you == 'w' && cpu == 's')
    {
        return -1;
    }
    else if(you == 's' && cpu == 'g')
    {
        return -1;
    }
    else if(you == 'g' && cpu == 's')
    {
        return 1;
    }
    else if(you == 'w' && cpu == 'g')
    {
        return 1;
    }
    else if(you == 'g' && cpu == 'w')
    {
        return -1;
    }
}

int main()
{
    char you, cpu,n;
    int player_score = 0, cpu_score = 0;
    for(int i = 0; i < 3; i++)
    {
        printf("Round no.%d\n",i+1);
        printf("Yours turn...\n");
        printf("Enter 's' for snake, 'w' for water and 'g' for gun\n");
        scanf("%c",&you);
        getchar();
        Fullname(you);

        printf("CPU turns...\n");
        n = Random(100);
        if(n<33)
        {
            cpu = 's';
        }
        else if(n>33 && n<66)
        {
            cpu = 'w';
        }
        else
        {
            cpu = 'g';
        }
        Fullname(cpu);

        int result = compResult(you, cpu);
        if(result == 0)
        {
            printf("Its a draw!\n");
        }
        else if(result == 1)
        {
            player_score+=1;
            printf("You got it!\n");
        }
        else
        {
            cpu_score+=1;
            printf("CPU got it!\n");
        }
        printf("Your score:%d\nCPU score:%d\n\n",player_score, cpu_score);
    }

    if(player_score == cpu_score)
    {
        printf("Match draw.\n");
    }
    else if(player_score > cpu_score)
    {
        printf("You win.\n");
    }
    else
    {
        printf("You lose.\n");
    }


    return 0;
}
