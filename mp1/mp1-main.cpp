#include <iostream>
#include <stack>
#include <queue>
#include <sstream>
#include <fstream>

using namespace std;

void firstFunction ()
{
    stack<char> stringone;
    queue<char> stringtwo;
    bool match = true;
    char str;
    string somestr = "ABC#GBAA";
    stringstream iss(somestr);

    while (iss.get(str)){
        if (str == '#') break;
        cout << str << endl;
        stringone.push(str);
    }
    while (iss.get(str)){
        cout << str << endl;
        stringtwo.push(str);
    }
    
    while (!(stringone.empty() || stringtwo.empty())){
        if (stringone.size() != stringtwo.size()){
            match = false;
            break;
        }
        else if (stringone.top() != stringtwo.front()){
            match = false;
            break;
        }
        else{
            stringone.pop();
            stringtwo.pop();
        }
    }
    
    cout << boolalpha << match << endl;
}

bool match(char o_parent, char c_parent)
{
	if(o_parent =='(' && c_parent ==')')
	    return true;
	else if(o_parent =='{' && c_parent =='}')
	    return true;
	else if(o_parent =='[' && c_parent ==']')
		return true;
	else
		return false;
}

bool thirdFunctionHelper (string str)
{
    char _str;
    stack<char> left_parents;
    stack<char> right_parents;
    bool par_match = true;
    
    stringstream _iss(str);
    
    while (_iss.get(_str)){
        if (_str == '(' || _str == '{' || _str == '['){
            left_parents.push(_str);
            continue;
        }
        else if (_str == ')' || _str == '}' || _str == ']'){
            if (!(match(left_parents.top(), _str)) || left_parents.empty()){
                return false;
            }
            else{
                left_parents.pop();
            }
        }
    }
    return par_match;
}

void thirdFunction ()
{
    string file_name, line;
    char _str;
    ifstream in_file("balance.txt"); 

    // cout << "Please enter a file name: ";
    // cin >> file_name;

    while (getline(in_file, line)){
        // stringstream _iss(line);
        // thirdFunctionHelper(line);
        cout << boolalpha << thirdFunctionHelper(line) << endl;
    }
}

int main ()
{
    // firstFunction();
    thirdFunction();
}
