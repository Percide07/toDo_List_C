#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *task;
    int completed;
} Task ;
Task *tasks = NULL;
int length = 0;

void addTask(const char *task){
    tasks = (Task *)realloc(tasks, (length +1) * sizeof(Task));
    tasks[length].task = (char * )malloc(strlen(task) + 1);
    tasks[length].completed = 0;

    strcpy(tasks[length].task, task);

    length++;
    printf("Task added \n");
};

void listTasks(){
    char stat;

    for (int i = 0; i < length; i++){
        if(tasks[i].completed == 1){
            stat = 'd';
        }else {
            stat = 'n';
        }
        printf("%d. %s [%c]\n", i+1, tasks[i].task, stat );
    }
};

void markCompleted( int index ){
    if (index <= length &&  index >= 0){
        tasks[index - 1].completed = 1;
        printf("The Task you marked are completed \n");
    }else {
        printf("Invalid Index\n");
    }
};

void deleteTask(int index){
    if(index <= length && index > 0){
        index = index - 1;

        free(tasks[index].task);

        for(int i = index; i < length - 1; i++){
            tasks[i]= tasks[i+1];
        }

        length--;

        tasks = (Task *)realloc(tasks, (length * sizeof(Task)));

    }else{
        printf("Invalid Index\n");
    }
};
void editTaskt(int index, const char* task){
    if(index <= length && index > 0){
        index = index - 1;

        char *taskEdit = (char *)realloc(tasks[index].task, strlen(task) + 1);

        if (taskEdit!=NULL){
            tasks[index].task = taskEdit;

            strcpy(tasks[index].task, task);

            printf("The task was updated successfully \n");

        }else{
            printf("Memory allocation failed !\n");
        }

    }else{
        printf("Invalid Index\n");
    }
};

int main()
{
    int choice;
    int run = 1;
    int indexInput;
    char taskInput[100];
    printf("************Options************\n");
    printf("***1. Add a Task***\n");
    printf("***2. List all tasks***\n");
    printf("***3. Mark as completed***\n");
    printf("***4. Edit task***\n");
    printf("***5. Delete task***\n");
    printf("***6. Exit***\n");

    while(run){

        printf("Enter your choice (1,2,3,4,5,6): ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter task : \n");
                getchar();
                fgets(taskInput, sizeof(taskInput), stdin);
                taskInput[strcspn(taskInput, "\n" )] = '\0';
                addTask(taskInput);
                break;
            case 2:
                listTasks();
                break;
            case 3:
                printf("Enter index: \n");
                scanf("%d", &indexInput);
                markCompleted(indexInput);
                break;
            case 4:
                printf("Enter index: \n");
                scanf("%d", &indexInput);
                getchar();
                fgets(taskInput, sizeof(taskInput), stdin);
                taskInput[strcspn(taskInput, "\n" )] = '\0';
                editTaskt(indexInput, taskInput);
                break;
            case 5:
                printf("Enter index: \n");
                scanf("%d", &indexInput);

                deleteTask(indexInput);

                break;
            case 6:
                run = 0;
                break;
            default:
                printf("Invalid choice \n");
                break;

        }

    }
    return 0;
}

