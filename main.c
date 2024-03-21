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
    printf("Task added");
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

            strcpy(tasks[length].task, task);

            printf("The task was updated successfully");

        }else{
            printf("Memory allocation failed !\n");
        }

    }else{
        printf("Invalid Index\n");
    }
};

int main()
{
    printf("************Options************\n");
    printf("***1. Add a Task***\n");
    printf("***2. List all tasks***\n");
    printf("***3. List all task***\n");
    printf("***4. Edit task***\n");
    printf("***5. Delete task***\n");
    printf("***6. Exit***\n");
    return 0;
}
