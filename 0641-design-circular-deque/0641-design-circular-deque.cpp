class MyCircularDeque {
    vector<int> dq;
    int front, rear, size, cap;

public:
    MyCircularDeque(int k) {
        dq.resize(k);
        front = 0;
        rear = -1;
        size = 0;
        cap = k;
    }

    bool insertFront(int value) {
        if (isFull()) return false;

        front = (front - 1 + cap) % cap;

        if (size == 0)
            rear = front;

        dq[front] = value;
        size++;

        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;

        rear = (rear + 1) % cap;

        if (size == 0)
            front = rear;

        dq[rear] = value;
        size++;

        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;

        front = (front + 1) % cap;
        size--;

        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;

        rear = (rear - 1 + cap) % cap;
        size--;

        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return dq[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return dq[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == cap;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna