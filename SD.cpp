#include <iostream>
#include <stack>
#include <cstring> 

//task 1 first solution
bool isValid(const char * str)
{
    int counter1 = 0, counter2 = 0, counter3 = 0;
    for (size_t i = 0; i < strlen(str); i++)
    {
        if(str[i] == '(')
        {
            counter1 += 1;
            size_t j = i;
            while (str[j])
            {
                if (str[j] == ')')
                {
                    counter1 += 1;
                }
                j++;
            }
        }
        else if(str[i] == '[')
        {
             counter2 += 1;
            size_t j = i;
            while (str[j])
            {
                if (str[j] == ']')
                {
                    counter2 += 1;
                }
                j++;
            }
        }
        else if(str[i] == '{')
        {
            counter3 += 1;
            size_t j = i;
            while (str[j])
            {
                if (str[j] == '}')
                {
                    counter3 += 1;
                }
                j++;
            }
        }
    }
    if (counter1 % 2 == 0 && counter2 % 2 == 0 && counter3 % 2 == 0)
    {
        return true;
    }
    return false;
    
}
//task 1 second solution
bool isValid2(const char * str)
{
    std::stack<char> mystack;
    for (size_t i = 0; str[i]; i++)
    {
        if(str[i] == '(')
        {
            mystack.push('(');
            for (size_t j = i; str[j]; j++)
            {
                if (str[j] == ')')
                {
                    mystack.pop();
                    break;
                } 
            }   
        }
        else if(str[i] == '[')
        {
            mystack.push('[');
            for (size_t j = i; str[j]; j++)
            {
                if (str[j] == ']')
                {
                    mystack.pop();
                    break;
                }
            }
        }
        else if(str[i] == '{')
        {
            mystack.push('{');
            for (size_t j = i; str[j]; j++)
            {
                if (str[j] == '}')
                {
                    mystack.pop();
                    break;
                }
            }
        }
    }
    if (mystack.empty())
    {
        return true;
    }
    return false;
}
int main()
{
   std::cout << std::boolalpha << isValid2("()([])[{}]([{}])"); // true
}
