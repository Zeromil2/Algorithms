#include "iostream"
#include "stdlib.h"
using namespace std;

struct link{
    int element;
    struct link* next;
};

typedef struct link Link;

Link* create_link(int it, Link* nextval){
    Link* n = (Link*) malloc(sizeof(Link));
    n -> element = it;
    n -> next = nextval;
    return n;
}

Link* create_link(Link* nextval){
    Link* n = (Link*) malloc(sizeof(Link));
    n -> next = nextval;
    return n;
}

typedef struct {
    Link* top;
    int size;
}Stack;

Stack* create_stack(){
    Stack* s = (Stack*) malloc(sizeof(Stack));
    s -> top = NULL;
    s -> size = 0;
    return s;
}

void push(Stack* s, int it){
    s -> top = create_link(it, s -> top);
    s -> size++;
}

int pop(Stack* s){
    if (s -> top != NULL){
        int it = s -> top -> element;
        s -> top = s -> top -> next;
        s -> size--;
        return it;
    }
}

int main(){

    Stack* stack = create_stack();
    string comando = " ";
    while (comando != "EOF"){
        cin >> comando;
        if (comando != "EOF"){
            int numero = stoi (comando);
            push(stack, numero);
        }
        int resultado = 0;
        while (comando != "EOF" and comando != "END"){
            cin >> comando;
            if (comando != "END" and comando != "-" and comando != "+" and comando != "*"){
                int numero = stoi (comando);
                push(stack, numero);
            }
            int n1, n2;
            if (comando == "+"){
                n1 = pop(stack);
                n2 = pop(stack);
                resultado = n1 + n2;
                push(stack, resultado);
            } else if (comando == "*"){
                n1 = pop(stack);
                n2 = pop(stack);
                resultado = n1 * n2;
                push(stack, resultado);
            } else if (comando == "-"){
                n1 = pop(stack);
                n2 = pop(stack);
                resultado = n2 - n1;
                push(stack, resultado);
            }
        }
        if (comando != "EOF") cout << resultado << '\n';
    }
    return 0;
}