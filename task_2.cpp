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
    std::ofstream fn;
    char arr[128];
    std::string line;
    fn.open("task2.txt");
    fn << "(7+(2*(3+4)))/n";
    fn.close();

    std::ifstream file("task2.txt");
    while (getline(file, line))
    {
        strcpy(arr,line.c_str());
    }
    file.close();

    fn.open("task2.txt");
    fn << "result is " << calculate(arr);
    return 0;
}
