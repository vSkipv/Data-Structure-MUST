#include <iostream>
#include <string>
//#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* next;
};
node* top = NULL;

void push(int val)
{
	node* newnode = new node;
	newnode->next = top;
	newnode->data = val;
	top = newnode;
}

void pop()
{
	if (top == NULL)
	{
		cout << "stack is empty\n";
	}
	else
	{
		cout << "the element popped is : " << top->data << "\n";
		top = top->next;
	}
}

 int evaluatePostfix(string expr)

 {
     for (int i = 0; i < expr.length(); i++)
     {

         if (isdigit(expr[i]))
            {

             push(expr[i] - '0');
            }

         else
            {

             int val1 = top->data;

             pop();

             int val2 = top->data;

             pop();

             switch (expr[i])
                 {

                 case '+': push(val2 + val1); break;

                 case '-': push(val2 - val1); break;

                 case '*': push(val2 * val1); break;

                 case '/': push(val2/val1);   break;

                 case '^': push(val2^val1);   break;
                 }
            }
        }

        cout <<endl;
        return top->data;
 }



int main()
 {
    string expr ;
    getline(cin, expr);
    int Result = evaluatePostfix(expr);
    cout << "Results = " << Result << endl;
    return 0;
 }


