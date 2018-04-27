#include "queue.h"

int main() {
    Queue<string> queue;
    
    queue.print();
    cout << "Size: " << queue.size() << endl;
    
    queue.push("Odin");
    queue.push("Thor");
    queue.push("Loki");
    
    queue.print();
    cout << "Size: " << queue.size() << endl;
    
    cout << queue.pop() << endl;
    
    queue.print();
    cout << "Size: " << queue.size() << endl;
    
    queue.pop();
    queue.pop();
    
    queue.print();
    cout << "Size: " << queue.size() << endl;
    
    queue.size();
    
    
    return 0;
}