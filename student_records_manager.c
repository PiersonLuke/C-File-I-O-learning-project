#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 100

int main()
{
    int classCount;
    printf("How many students are in your class? ");
    scanf("%d", &classCount);
    
    FILE *write = fopen("Students.txt", "w");
    if (write == NULL)
    {
        printf("THERE WAS AN ERROR!");
        return 1;
    }
    else
    {
        int SID;
        char name[SIZE];
        float GPA;

        for (int i = -1; i < classCount; i++) // -1 fixes leftover input
        {
            printf("Student ID: ");
            scanf("%d", &SID);
            getchar();  // consume leftover '\n'

            printf("Student name: ");
            fgets(name, SIZE, stdin);
            name[strcspn(name, "\n")] = '\0';  // remove trailing newline


            printf("Student GPA: ");
            scanf("%f", &GPA);
            fprintf(write, "%d | %s | %.2f \n-----------------------------------\n", SID, name, GPA);
        }

    }
    fclose(write);

    FILE *read = fopen("Students.txt", "r");
    if (read == 0)
    {
        printf("THERE WAS AN ERROR!");
        return 1;
    }
    else
    {
        char buffer[SIZE];
        for (int i = 0; i < classCount; i++)
        {
            fgets(buffer, SIZE, read);
            printf("%s", buffer);
        }
        fclose(read);
        return 0;
    }
}