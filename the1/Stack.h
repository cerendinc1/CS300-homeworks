
//
// Ceren Dinc.

#include <iostream>
#include <string>
using namespace std;

template <class Object>
class Stack
{
public:
    Stack()
    {
        topOfStack = NULL;
    }

    ~Stack()
    {
        makeEmpty();
    }

    bool isEmpty() const
    {
        return topOfStack == NULL;
    }

    void makeEmpty()
    {
        while (!isEmpty())
            pop();
    }

    void pop()
    {
        if (!isEmpty())
        {
            ListNode *oldTop = topOfStack;
            topOfStack = topOfStack->next;
            delete oldTop;
        }
    }

    void push(const Object &x)
    {
        topOfStack = new ListNode(x, topOfStack);
    }

    const Object &top() const
    {
        if (!isEmpty())
        {
            return topOfStack->element;
        }
        return topOfStack->element;
    }

private:
    struct ListNode
    {
        Object element;
        ListNode *next;
        ListNode(const Object &theElement, ListNode *n = NULL)
            : element(theElement), next(n) {}
    };

    ListNode *topOfStack;
};
