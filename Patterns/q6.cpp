#include <iostream>
using namespace std;

class Queue{

    public:
        int *arr;
        int qfront;
        int qrear;
        int size;

        Queue(int size) {
            this->size = size;
            arr = new int[size];
            qfront = 0;
            qrear = 0;                                                                                                                        
        }

        bool isEmpty() {
            if(qfront == qrear) {
                return true;
            }
            else {
                return false;
            }
        }
       
        void enqueue(int element) {
            if(qrear == size) {
                cout << "Queue is full" << endl;
            }
            else {
                arr[qrear] = element;
                qrear++;
            }
        }

        int dequeue() {
            if(qfront == qrear) {
                return -1;
            }
            else {
                int ans = arr[qfront];
                arr[qfront] = -1;
                qfront++;

                if(qfront == qrear) {
                    qfront = 0;
                    qrear = 0;
                }
                return ans;
            }
        }

        int front() {
            if(qfront == qrear) {
                return -1;
            }
            else {
                return arr[qfront];
            }
        }


};

int main() {
    Queue q(4);
    q.enqueue(22);
    q.enqueue(44);
    q.enqueue(88);
    q.enqueue(99);

    cout << "Front element of the queue is : " << q.front() << endl;

    cout << q.dequeue() << endl;

    cout << "Front element of the queue is : " << q.front() << endl;


    cout << q.dequeue() << endl;

    cout << "Front element of the queue is : " << q.front() << endl;

    cout << q.dequeue() << endl;

    if(q.isEmpty()) {
        cout << "queue is empty" << endl;
    }
    else {
        cout << "queue is not empty" << endl;
    }

    cout << "Front element of the queue is : " << q.front() << endl;

    cout << q.dequeue() << endl;

    if(q.isEmpty()) {
        cout << "queue is empty" << endl;
    }
    else {
        cout << "queue is not empty" << endl;
    }

    return 0;
}