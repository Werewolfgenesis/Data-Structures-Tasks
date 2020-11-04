#include <iostream>
#include <stack>
#include <string.h> 

int calculate(char * str)
{
    std::stack<int> nr; 
    std::stack<char> op;
    int i = strlen(str) - 1;
    
    while(i >= 0)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            int elem = str[i] - '0';
            nr.push(elem);
        }
        else
        {
            op.push(str[i]);
           if (op.top() == '(')
           {
               op.pop();
               char symbol = op.top();
               op.pop();
               op.pop();
               
               int temp = nr.top();
               nr.pop();
               int result;

               if (symbol == '+')
               {
                   result = temp + nr.top();
               }
               if (symbol == '*')
               {
                    result = temp * nr.top();
               }
               if (symbol == '/')
               {
                    result = temp / nr.top();
               }
               if (symbol == '-')
               {
                    result = temp * nr.top();
               }
               nr.pop();
               nr.push(result);
           } 
        } 
        i--;
    }
    return nr.top();
}
int main()
{
   char arr[14] = "(7+(2*(3+4)))";
   std::cout << calculate(arr);
   return 0;
}
