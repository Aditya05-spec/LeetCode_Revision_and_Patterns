#include <iostream>
using namespace std;

class Stack{
    
    public:
        int *arr;
        int top;
        int size;

        Stack(int size) {
            this->size = size;
            arr = new int[size];
            top = -1;
        }

        void push(int element) {
            if(size-top > 1) {
                top++;
                arr[top] = element;
            }
            else {
                cout << "Stack is overflow" << endl;
            }
        }

        void pop() {
            if(top >= 0) {
                top--;
            }
            else {
                cout << "Stack is underflow" << endl;
            }
        }

        bool isEmpty() {
            if(top == -1) {
                cout << "Stack is empty" << endl;
                return true;
            }
            else {
                cout << "Stack is not empty" << endl;
                return false;
            }
        }

        int peek() {
            if(top >= 0) {
                return arr[top];
            }
            else {
                cout << "Stack is empty" << endl;
                return -1;
            }
        }
};

int main() {
    Stack st(5);

    st.push(22);
    st.push(43);
    st.push(44);
    st.push(22);
    st.push(43);
    st.push(44);

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    st.pop();

    if(st.isEmpty()) {
        cout << "stack is not empty : " << endl;
    }

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    return 0;
}