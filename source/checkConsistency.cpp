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
    string expression;
    cout << "Enter an expression:  "; 
    cin >> expression;
    if (AreTagsBalanced(expression))
        cout << "Consistent\n";
    else
        cout << "Not Consistent\n";
}

/*#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

vector<string> getHtmlTags() {                                      //receives a string of html tags and divide them by "<, >"
    vector<string> tags;                                            //vector of html tags
    while (cin) {                                                   //reads the whole input
        string line;
        getline(cin, line);
        int pos = 0;                                                //current scanning position
        int ts = line.find("<", pos);                                //scans from the current scanning position
        while (ts != string::npos) {                                  //repeat until end of string
            int te = line.find(">", ts + 1);                          //scans for the end of a tag (<)
            tags.push_back(line.substr(ts, te - ts + 1));                //save tag to the vector
            pos = te + 1;                                           //repositioning
            ts = line.find("<", pos);
        }
    }
    return tags;                                                    //return vector of tags
}


bool isHtmlMatched(const vector<string>& tags) {                    //checks if the html tags are correctly matched
    stack<string> S;                                            //implememted stack from above for opening tags
    typedef vector<string>::const_iterator Iter;                    //iterate through vector

    for (Iter p = tags.begin(); p != tags.end(); ++p) {
        if (p->at(1) != '/')                                        //is it the opening tag?
            S.push(*p);                                             //push to the stack
        else {
            if (S.empty()) return false;                            //there is nothing to match
            string open = S.top().substr(1);                        //opening tag excluding '<'
            string close = p->substr(2);                            //closing tag excluding '>'
            if (open.compare(close) != 0) return false;             //exception for fail to match
            else S.pop();                                           //pop matched element

        }
    }
    if (S.empty()) return true;                                     //everything has matched correctly - Correct
    else return false;                                              //some did not match correctly - Incorrect
}

int main() {

    int rep;                                                        //decides the number of trial
    cin >> rep;

    for (int i = 1; i <= rep; i++) {                                    //loop up to the decided trial
        if (isHtmlMatched(getHtmlTags()))
            cout << "Consistent" << endl;
        else cout << "Not Consistent" << endl;
    }
}*/
/*#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Returns true is the string is balanced
bool isBalanced(string s)
{
    int i;
    char c;
    int n = s.length();
    stack<char> t;

    for (i = 0; i < n; i++)
    {
        c = s.at(i);

        if (t.empty())
        {
            t.push(c);
        }
        else if (t.top() == '<' && c == '>')
        {
            t.pop();
        }
        else
            t.push(c);
    }

    if (t.empty())
        return true;
    else
        return false;
}

int main()
{
    //initializing string to be checked for
    string s1 = "<SAD><SAD>";

    bool b1 = isBalanced(s1);

    if (b1)
    {
        cout << "The string " << s1 << " is Consistent.\n\n";
    }
    else
    {
        cout << "The string " << s1 << " is not Consistent.\n\n";
    }

    return 0;
}*/


#/*include<iostream>
#include<stack>
using namespace std;
bool checkConsistency(string expr) {     //check if the expression is Consistent or Not.
    stack<char> s;
    char ch;
    for (int i = 0; i < expr.length(); i++) {    //for each character in the expression, check conditions
        if (expr[i] == '<') {    //when it is opening bracket, push into  stack
            s.push(expr[i]);
            continue;
        }
        if (s.empty())    //stack cannot be empty as it is not opening bracket, there must be closing     bracket
            return false;
        switch (expr[i]) {
        case '>':    //for closing parenthesis, pop it and check for braces and square brackets
            ch = s.top();
            s.pop();
            if (ch == ' ')
                return false;
            break;
        }
    }
    return (s.empty()); //when stack is empty, return true
}
int main() { 
    string expr = "<tag>sad</tag>";                    //<</>
    if (checkConsistency(expr)) 
        cout << "Consistent";
    else
        cout << "Not Consistent";
}*/
/*switch (expr[i]) {
case '>':    //for closing parenthesis, pop it and check for braces and square brackets
    ch = s.top();
    s.pop();
    if (ch == ' ')
        return false;
    break;
}*/