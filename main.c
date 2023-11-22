#include <stdio.h>
#include <stdlib.h>
typedef int StackEntry;
//////////////////////////////////////////////////////
typedef struct stacknode{
    StackEntry entry;
    struct stacknode *next;
}StackNode;
/////////////////////////////////////////////////////
typedef struct stack{
    StackNode *top;
    int Size;
}Stack;
////////////////////////////////////////////////////
void CreateStack(Stack *ps)
{
    ps->top=NULL;
    ps->Size=0;
}
///////////////////////////////////////////////////
void Push(StackEntry e,Stack *ps)
{
    StackNode *pn=(StackNode *) malloc(sizeof (StackNode));
    pn->entry=e;
    pn->next=ps->top;
    ps->top=pn;
    ps->Size++;
}
//////////////////////////////////////////////////
 void Pop(StackEntry *pe,Stack *ps)
{
    *pe=ps->top->entry;
    StackNode *pn=ps->top;
    ps->top=ps->top->next;
    free(pn);
    ps->Size--;
}
/////////////////////////////////////////////////////
int StackEmpty(Stack*ps)
{
    return ps->top==NULL;
    ps->Size=0;
}
/////////////////////////////////////////////////////
int StackFull(Stack*ps)
{
    return 0;
}
////////////////////////////////////////////////////
void ClearStack(Stack *ps)
{
    StackNode *pn=ps->top;
    while (pn) {
        pn = pn->next;
        free(ps->top);
        ps->top = pn;
    }
}
////////////////////////////////////////////////////
void TraverseStack(Stack*ps,void(*pf)(StackEntry))
{
    StackNode *pn=ps->top;
    while (pn)
    {
        (*pf)(pn->entry);
        pn=pn->next;
    }
}
///////////////////////////////////////////////////
int StackSize(Stack *ps)
{
    return ps->Size;
}
//////////////////////////////////////////////////
int main() {
    printf("Hello, World!\n");
    return 0;
}
