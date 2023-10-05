#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {

private:
    
    int start = 0, end = 0, curSize = 0, SIZE = 0;
    vector<int> myQueue;
    
public:
    
    MyCircularQueue(int k) {
        myQueue.resize(k);
        SIZE = k;
    }
    
    bool enQueue(int value) {
        if(curSize == SIZE)
            return false;
        
        myQueue[end] = value;
        end = (end + 1) % SIZE;
        curSize += 1;
    
        return true;
    }
    
    bool deQueue() {
        
        if (curSize == 0)
            return false;

        start = (start + 1) % SIZE;
        curSize -= 1;

        return true;
    }
    
    int Front() {        
        return isEmpty()? -1 : myQueue[start];
    }
    
    int Rear() {
        
        if(isEmpty())
            return -1;            

        if(end == 0)
            return myQueue[SIZE - 1];
        else
            return myQueue[end - 1];
    }
    
    bool isEmpty() {
        return curSize == 0;
    }
    
    bool isFull() {
        return curSize == SIZE;
    }
    
};


int main(){
    MyCircularQueue CircularQueue(3);
    CircularQueue.enQueue(2);
    cout << CircularQueue.Front();
}