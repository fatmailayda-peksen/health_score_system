#include<stdio.h>
int CalculateHealthScore(float sleep, float water, int step, int mood)
{
    int sleep_score, step_score, water_score, mood_score;
    
    //sleep_score
    if (sleep >= 7 && sleep <= 9)
    {
        sleep_score = 30;
    }
    else if ((sleep >= 5 && sleep <= 6.9) || (sleep >= 9 && sleep <= 11) )
    {
        sleep_score = 20;
    }
    else
    {
        sleep_score = 10;
    }

    //step_score
    if (step >= 8000)
    {
        step_score = 30;
    }
    else if (step <= 5000)
    {
        step_score = 10;
    }
    else
    {
        step_score = 20;
    }

    //water_score
    if (water >= 2.0)
    {
        water_score = 20;
    }
    else if (water <= 1.0)
    {
        water_score = 5;
    }
    else
    {
        water_score = 10;
    }

    //mood_score
    switch (mood)
    {
    case 1 :
        mood_score =20;
        break;
    case 2 :
        mood_score =10;
        break;
    case 3 :
        mood_score =5;
        break;
    case 4 :
        mood_score =0;
        break;
  
    default:
        break;
    }
    int daily_score = sleep_score + step_score + water_score + mood_score;

    return daily_score;
}

void giveFeedback(int score)
{
    if (score>=80)
    {
        printf("Excellent Day!\n\n");
    }
    else if(score<=79 && score>=60)
    {
        printf("Good day, keep going.\n\n");
    }
    else if(score<=59 && score>=40)
    {
        printf("Average day, try to improve.\n\n");
    }
    else
    {
        printf("Unhealthy day, be careful.\n\n");
    }
}


int main ()
{
    float water, sleep;
    float total_score = 0;
    int step, mood;
    int day=1;
    int best_score = 0;
    int best_day = 0;
    int worst_score = 100;
    int worst_day = 0;

    while(day<=3)
    {
        printf("--- Day %d ---\n", day);
        printf("Steps walked: ");
        scanf("%d", &step);
        do
        {
            printf("Hours of sleep (0-24): ");
            scanf("%f", &sleep);
            if(sleep < 0 || sleep > 24)
            {
                printf("Invalid sleep hours. Please enter a value between 0-24.\n");
            }
        }
        while(sleep < 0 || sleep > 24);
        
        printf("Water intake (liters): ");
        scanf("%f", &water);
        
        do
        {
            printf("Mood level (1 = Happy, 2 = Normal, 3 = Stressed, 4 = Sad): ");
            scanf("%d", &mood);
            if(mood < 1 || mood > 4)
            {
                printf("Invalid mood. Please enter a value between 1-4.\n");
            }
        }
        while(mood < 1 || mood > 4);
    
        int score = CalculateHealthScore(sleep, water, step, mood);
        printf("Score for Day %d: %d\n", day, score);

        giveFeedback(score);
        
        if(score > best_score)
        {
            best_score = score;
            best_day = day;
        }
        
         if(score < worst_score)
        {
            worst_score = score;
            worst_day = day;
        }
        total_score = total_score + score;
        day++;
    }
    printf("\n---SUMMARY---\n");
    float average_score = total_score / 3;
    printf("Average Score: %.2f\n", average_score);
    printf("Best Day: Day %d with score %d\n", best_day, best_score);
    printf("Worst Day: Day %d with score %d", worst_day, worst_score);

    return 0;
}