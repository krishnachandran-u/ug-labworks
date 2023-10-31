/*
    author: https://codeforces.com/profile/krishnachandran
    text editor: NVIM v0.9.1
    compiler: GNU G++20 11.2.0 (64 bit,  winlibs)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define max(a, b) (a > b)? a: b;
#define min(a, b) (a < b)? a: b;

struct S{
    int *a;
    int top, cp;
};

void init(struct S* s){
    s->a = NULL; 
    s->top = -1;
    s->cp = 0;
}

void push(struct S* s, int x){
    s->top++;
    if(s->top + 1 > s->cp){
        s->cp = max(1, s->cp << 1);
        int *p = (int*)malloc(sizeof(int)*s->cp);
        for(int i = 0; i < s->top; i++){
            p[i] = s->a[i];
        }
        free(s->a);
        s->a = p;
    }
    s->a[s->top] = x; 
    printf("[successful] pushed %d\n", x);
    return;
}

void pop(struct S* s){
    if(s->top == -1){
        printf("[underflow] can't pop\n");
        return;
    }
    printf("[successful] popped %d\n", s->a[s->top]); 
    s->top--;
    if(s->top + 1 <= (s->cp >> 1)){
        s->cp >>= 1;
        s->a = (int*) realloc(s->a, sizeof(int)*s->cp);
    }
}

void disp(struct S* s){
    for(int i = 0; i <= s->top; i++){
        printf("%d  ", s->a[i]);
    }
    printf("\n");
    return;
}

int main(){
    struct S s; 
    init(&s);
    
    push(&s, 1);
    disp(&s);
    push(&s, 2);
    disp(&s);
    push(&s, 3);
    disp(&s);
    push(&s, 4);
    disp(&s);
    push(&s, 5);
    disp(&s);

    pop(&s);
    disp(&s);
    pop(&s);
    disp(&s);
    pop(&s);
    disp(&s);   
    pop(&s);
    disp(&s);
    pop(&s);
    disp(&s);
    pop(&s);
    disp(&s);
    pop(&s);
    disp(&s);

    push(&s, 1);
    disp(&s);
    push(&s, 2);
    disp(&s);
    
    pop(&s);
    disp(&s);
    pop(&s);
    disp(&s);
    pop(&s);
    disp(&s);   
    pop(&s);
    disp(&s);
    pop(&s);
    disp(&s);

    return 0;
}
