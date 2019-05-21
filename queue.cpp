#include <iostream>

using namespace std;

class Queue {
    public:
        int begin, end, length;

        unsigned capacity;
        int *data;
};

Queue *createQueue(unsigned capacity) {
    Queue *myqueue = new Queue();
    myqueue->capacity = capacity;
    myqueue->begin = myqueue->length = 0;
    myqueue->end = capacity - 1;
    myqueue->data = new int[(myqueue->capacity * sizeof(int))];
    return myqueue;
}

int isFull(Queue *queue) {
    return (queue->length == queue->capacity);
}

int isEmpty(Queue *queue) {
    return (queue->length == 0);
}

void enqueue(Queue *queue, int data) {
    if (isFull(queue)) return;

    queue->end = (queue->end + 1) % queue->capacity;
    queue->data[queue->end] = data;
    queue->length = queue->length + 1;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    int data = queue-> data[queue->begin];
    queue->begin = (queue->begin + 1) % queue->capacity;
    queue->length = queue->length - 1;
    return data;
}

int front(Queue *queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    return queue->data[queue->begin];
}

int end(Queue *queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    return queue->data[queue->end];
}

int main() {
    Queue *myqueue = createQueue(700);

    enqueue(myqueue, 11);
    enqueue(myqueue, 12);
    enqueue(myqueue, 13);
    enqueue(myqueue, 14);

    cout << dequeue(myqueue) << endl;

    cout << front(myqueue) << endl;
    cout << end(myqueue) << endl;

    return 0;
}
