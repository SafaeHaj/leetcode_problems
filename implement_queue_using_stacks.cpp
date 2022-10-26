#include <iostream>
#include <vector>

using namespace std;

class MyQueue {
    int front;
    int size;
    vector<int> q;
    vector<int> temp_q;

public: 
    MyQueue() {
        front = -1;
        size = 0;
        q.reserve(20);
        temp_q.reserve(20);
    }
    
    void push(int x) {      
        if( size == 0) {
            q.push_back(x);
            front = x;
        }
        
        else {
            int i = size - 1;
            int j = -1;
            int temp;

            while (i >= 0) {
                temp = q.at(i--);
                temp_q.push_back(temp);
                q.pop_back();
                j++;
            }
            q.push_back(x);

            while(j >= 0) {
                temp = temp_q.at(j--);
                q.push_back(temp);
                temp_q.pop_back();
            }

        }
        size++;        
    }
    
    int pop() {
        int temp = front; 
        
        if (size == 1)
            front = -1;
        else
            front = q.at(size - 2);

        q.pop_back();
        size--;

        return temp;
    }
    
    int peek() {
        return front;
    }
    
    bool empty() {
       return (size == 0); 
    }

    ~MyQueue() {
        front = -1;
        size = 0;
        q.clear();
        q.shrink_to_fit();
        temp_q.shrink_to_fit();
    }
};

int main() {
    MyQueue q = MyQueue();

    for(int i = 1; i < 6; i++) {q.push(i);}

    while(!q.empty()) {cout << q.pop() << endl;}
}