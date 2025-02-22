#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CALLS 100

typedef struct {
    int call_id;
    char caller_name[50];
} Call;

typedef struct {
    Call calls[MAX_CALLS];
    int front;
    int rear;
} CallQueue;

void initQueue(CallQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(CallQueue *queue) {
    return queue->front == -1;
}

int isFull(CallQueue *queue) {
    return queue->rear == MAX_CALLS - 1;
}

void addCall(CallQueue *queue, int call_id, const char *caller_name) {
    if (isFull(queue)) return;
    if (isEmpty(queue)) queue->front = 0;
    queue->rear++;
    queue->calls[queue->rear].call_id = call_id;
    strcpy(queue->calls[queue->rear].caller_name, caller_name);
    printf("New Call Added: Call %d from %s\n", call_id, caller_name);
}

void processCall(CallQueue *queue) {
    if (isEmpty(queue)) return;
    printf("Processing Call: %d from %s\n", queue->calls[queue->front].call_id, queue->calls[queue->front].caller_name);
    for (int i = queue->front; i < queue->rear; i++) {
        queue->calls[i] = queue->calls[i + 1];
    }
    queue->rear--;
    if (queue->rear < queue->front) queue->front = -1;
}

void displayRemainingCalls(CallQueue *queue) {
    if (isEmpty(queue)) {
        printf("No remaining calls in the queue.\n");
        return;
    }
    printf("Remaining Calls: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d from %s", queue->calls[i].call_id, queue->calls[i].caller_name);
        if (i < queue->rear) printf(", ");
    }
    printf("\n");
}

int main() {
    CallQueue callQueue;
    initQueue(&callQueue);

    addCall(&callQueue, 101, "Alice");
    addCall(&callQueue, 102, "Bob");

    processCall(&callQueue);
    displayRemainingCalls(&callQueue);

    processCall(&callQueue);
    displayRemainingCalls(&callQueue);

    return 0;
}
