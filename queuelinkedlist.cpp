#include <iostream>

using namespace std;

class QueueNode {
    public:
        int identifier;
        QueueNode *next;
};

class Queue {
    public:
        QueueNode *front;
};

QueueNode *createNode(int identifier) {
    QueueNode *temp = new QueueNode();
    temp->identifier = identifier;
    temp->next = NULL;
    return temp;
}

Queue *createQueue() {
    Queue *q = new Queue();
    q->front = NULL;
    return q;
}

void enQueue(Queue *q, int identifier) {
    QueueNode *temp = createNode(identifier);
    if (q->front == NULL) {
        q->front = temp;
        return;
    }

    q->front->next = temp;
}

QueueNode *deQueue(Queue *q) {
    if (q->front == NULL) {
        return NULL;
    }

    QueueNode *temp = q->front;

    q->front = temp->next;

    return temp;
}

int main() {
    Queue *q = createQueue();

    enQueue(q, 10);
    enQueue(q, 20);
    deQueue(q);
    deQueue(q);
    enQueue(q, 30);
    enQueue(q, 40);
    enQueue(q, 50);

    QueueNode *temp = deQueue(q);
    if (temp != NULL) {
        cout << temp->identifier << endl;
    }

    return 0;
}
