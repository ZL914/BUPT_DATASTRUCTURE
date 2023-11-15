#include <stdio.h>
#define MAX 100
typedef int SELemType;
struct stack
{
    SELemType arr[MAX];
    int top;
};
typedef struct stack stack;

// ³õÊ¼»¯Õ»
void creat_stack(stack *s)
{
    s->top = -1;
}
// ÅÐ¿Õ
int empty_stack(stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}
// Òç³ö
int over_stack(stack *s)
{
    if (s->top >= MAX)
        return 1;
    else
        return 0;
}
// Ñ¹Èë
void push_stack(stack *s, int data)
{
    if (over_stack(s))
        printf("?????¨²\n");
    else
    {
        s->top++;
        s->arr[s->top] = data;
    }
}
// µ¯³ö
void pop_stack(stack *s)
{
    int e;
    if (empty_stack(s))
    {
        printf("??????\n");
    }
    else
    {
        s->top--;
        e = s->arr[s->top];
    }
}
// Êä³ö
void output_stack(stack *s)
{
    int i = s->top;
    for (i = s->top; i >= 0; i--)
    {
        printf("%d  ", s->arr[i]);
    }
}
// Õ»¶¥ÔªËØ
int getdata_stack(stack *s)
{
    int data = s->arr[s->top];
    return data;
}

int main()
{
    stack s;
    creat_stack(&s);
    printf("???????\n");
    int e;
    for (s.top = 0; s.top < MAX; s.top++)
    {
        scanf("%d", &e);
        push_stack(&s, e);
    }
    printf("?????%d\n", getdata_stack(&s));
    pop_stack(&s);
    printf("?????%d\n", getdata_stack(&s));
    output_stack(&s);
    return 0;
}
