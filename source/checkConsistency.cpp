#include"checkConsistency.h"
bool ArePair(char opening, char closing)     
{
    if (opening == '<' && closing == '>') return true;
    else return false;
   
}
bool AreTagsBalanced(string exp)            
{
    stack<char>  S;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '<')
            S.push(exp[i]);
        else if (exp[i] == '>')
        {
            if (S.empty() || !ArePair(S.top(), exp[i]))
                return false;
            else
                S.pop();
        }
    }
    return S.empty() ? true : false;
}

int main()
{
    /*string expression;
    cout << "Enter an expression:  "; 
    cin >> expression;
    if (AreTagsBalanced(expression))
        cout << "Consistent\n";
    else
        cout << "Not Consistent\n";*/
    
}

