#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_DESC_LENGTH 100
#define DATE_LENGTH 11

typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
    char description[MAX_DESC_LENGTH];
    int priority;
    char due_date[DATE_LENGTH];
    int completed;
} Task;

Task tasks[MAX_TASKS];
int num_tasks = 0;

void display_menu() {
    printf("\nTask Manager Menu\n");
    printf("1. Add Task\n");
    printf("2. Delete Task\n");
    printf("3. Mark Task as Completed\n");
    printf("4. Display All Tasks\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void add_task() {
    if (num_tasks >= MAX_TASKS) {
        printf("Task manager is full!\n");
        return;
    }
    Task new_task;
    printf("Enter task title: ");
    scanf("%s", new_task.title);
    printf("Enter task description: ");
    scanf("%s", new_task.description);
    printf("Enter task priority (1-5): ");
    scanf("%d", &new_task.priority);
    printf("Enter due date (YYYY-MM-DD): ");
    scanf("%s", new_task.due_date);
    new_task.completed = 0;
    new_task.id = num_tasks + 1;
    tasks[num_tasks++] = new_task;
    printf("Task added successfully!\n");
}

void delete_task() {
    int task_id;
    printf("Enter task ID to delete: ");
    scanf("%d", &task_id);
    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].id == task_id) {
            for (int j = i; j < num_tasks - 1; j++) {
                tasks[j] = tasks[j + 1];
            }
            num_tasks--;
            printf("Task deleted successfully!\n");
            return;
        }
    }
    printf("Task with ID %d not found!\n", task_id);
}

void mark_completed() {
    int task_id;
    printf("Enter task ID to mark as completed: ");
    scanf("%d", &task_id);
    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].id == task_id) {
            tasks[i].completed = 1;
            printf("Task marked as completed!\n");
            return;
        }
    }
    printf("Task with ID %d not found!\n", task_id);
}

void display_tasks() {
    printf("\nAll Tasks:\n");
    printf("ID | Title | Description | Priority | Due Date | Completed\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d | %s | %s | %d | %s | %s\n", tasks[i].id, tasks[i].title, tasks[i].description, tasks[i].priority, tasks[i].due_date, tasks[i].completed ? "Yes" : "No");
    }
}

int main() {
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                delete_task();
                break;
            case 3:
                mark_completed();
                break;
            case 4:
                display_tasks();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

