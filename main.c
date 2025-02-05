#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX_TASKS 100
#define DESCRIPTION_LENGTH 100

typedef struct {
    int id;
    char title[DESCRIPTION_LENGTH];
    int status;
} Task;

//Array of structs to hold list of tasks
Task taskList[MAX_TASKS];
int taskCount = 0; //Keep track of tasks. C does not have a built-in method to check length of arrays

void displayTasks(Task *task_list, int task_count);
void main_menu();
void add_task();
int inputValid();
void changeStatus();

int inputValid()
{
    char buffer[50];
    int userInput = 0;
    while (1)
    {
        if(fgets(buffer, sizeof(buffer), stdin) != NULL){
            if(sscanf(buffer, "%d", userInput) == 1){
                return userInput;
            }else{
                puts("Invalid input. Try again");
            }
        }
    }
    
}

void add_task()
{
    char userInput[DESCRIPTION_LENGTH];
    
    printf("\nEnter task: \n");
    fgets(userInput, sizeof(userInput), stdin);

    //Remove trailing newline character
    size_t len = strlen(userInput);
    if(len > 0 && userInput[len - 1] == '\n'){
        userInput[len - 1] = '\0';
    }

    // Add task to list
    taskList[taskCount].id = taskCount + 1; //increase id num
    strncpy(taskList[taskCount].title, userInput, DESCRIPTION_LENGTH);
    taskList[taskCount].status = 0; //Default. 'Not complete status'
    printf("'%s' had been added", userInput);
    taskCount++;

}



void displayTasks(Task *task_list, int task_count)
{
    printf("\nCurrent Tasks\n");
    if(task_count == 0){
        printf("Task list empty\n");
        return;
    }

    for(int i = 0;  i < task_count; i++){
        printf("%d) %s: %s", 
        task_list[i].id, 
        task_list[i].title,
        task_list[i].status ? "Completed" : "Not Completed");
    }
}

void changeStatus()
{
    puts("Choose task to update: ");
    displayTasks(taskList, taskCount);

}


int main()
{
    main_menu();
    
    return 0;
}

void main_menu()
{
    int userInput = 0;
    while(1)
    {
        printf("\n1)Display tasks\n");
        printf("2) Add task\n");
        userInput = inputValid();

        if(userInput == 1){
            displayTasks(taskList, taskCount);
            break;
        }
        else if(userInput == 2){
            add_task();
            break;
        }else if(userInput == 3){
            changeStatus();
            break;
        }

    }
}