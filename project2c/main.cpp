#include "queue.h"
#include "stack.h"

int main() {
    Stack<string> stack;
    
    stack.print();
    cout << "Size: " << stack.size() << endl;
    
    stack.push("Odin");
    stack.push("Thor");
    stack.push("Loki");
    
    stack.print();
    cout << "Size: " << stack.size() << endl;
    
    cout << stack.pop() << endl;
    
    stack.print();
    cout << "Size: " << stack.size() << endl;
    
    stack.pop();
    stack.pop();
    
    stack.print();
    cout << "Size: " << stack.size() << endl;
    
    
    return 0;
}