#include <iostream>
#include <string>
#include <map>
using namespace std;
map <string, int > commands;
int my_stack[10001];
int my_stack_size = 0;
enum Command
{
    COMMAND_PUSH,
    COMMAND_POP,
    COMMAND_SIZE,
    COMMAND_EMPTY,
    COMMAND_TOP
};
void init() {
    commands["push"] = COMMAND_PUSH;
    commands["pop"] = COMMAND_POP;
    commands["size"] = COMMAND_SIZE;
    commands["empty"] = COMMAND_EMPTY;
    commands["top"] = COMMAND_TOP;
}

int main(void) {
    init();
    string command;
    int command_num, num;

    cin >> command_num;
    for(int i=0; i<command_num; i++) {
        cin >> command;
        switch(commands[command]) {
        case COMMAND_PUSH:
            cin >> num;
            my_stack[my_stack_size++] = num;
            break;
        case COMMAND_POP:
            my_stack_size > 0 ? 
                (cout << my_stack[--my_stack_size] << "\n") : (cout << "-1\n");
            break;
        case COMMAND_SIZE:
            cout << my_stack_size << "\n";
            break;
        case COMMAND_EMPTY:
            my_stack_size == 0 ? (cout << "1\n") : (cout <<"0\n");
            break;
        case COMMAND_TOP:
            my_stack_size > 0 ? 
                (cout<<my_stack[my_stack_size-1] << "\n") : (cout << "-1\n");
            break;
        }
    }
    return 0;
}