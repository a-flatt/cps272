#include "queue.h"
#include "stack.h"
#include <fstream>
#include <sstream>

int firstFunction ()
{
    Stack<char> stringone;
    Queue<char> stringtwo;
    bool match = true;
    char str;
    string somestr;
    
    cout << "Input a string: ";
    cin >> somestr;
    stringstream iss(somestr);

    while (iss.get(str)){
        if (str == '#') break;
        stringone.push(str);
    }
    while (iss.get(str)){
        stringtwo.push(str);
    }
    
    while (!(stringone.empty() || stringtwo.empty())){
        if (stringone.length() != stringtwo.length()){
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
    
    (match) ? 
        cout << somestr << " matches the pattern." << "\n"
        : 
        cout << somestr << " does not match the pattern." << "\n";
}

void multibaseOutput (int d_num, int b_num, Stack<int> rems)
{
    if (d_num == 0){
        while (!rems.empty()){
            int num = rems.top();
            if (num >= 0 && num <= 9)
                cout << (char)(num + '0');
            else
                cout << (char)(num - 10 + 'A');
            rems.pop();
        }
    cout << '\n';
    return;  
    }

    int x = d_num % b_num;
    rems.push(x);

    multibaseOutput(d_num/b_num, b_num, rems);
}

int secondFunction ()
{
    bool run = true;

    while (run) {
        
        Stack<int> remainders;
        int decimal = -1;
        while (decimal < 0) {
            cout << "Please input a non-negative number: ";
            cin >> decimal;
        }

        int base = 1;
        while ((base < 2 || base > 16) && base != 0) {
            cout << "Input a base between 2 and 16: ";
            cin >> base;
        }

        if (decimal == 0 && base == 0) {
            run = false;
        } 
        else {
            cout << "\n";
            cout << decimal << " base " << base << " is ";
            multibaseOutput(decimal, base, remainders);
        }
    } 
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

bool balanced (string str)
{
    char _str;
    Stack<char> left_parents;
    Stack<char> right_parents;
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

int thirdFunction ()
{
    string file_name, line;
    char _str;

    cout << "Please enter a file name: ";
    cin >> file_name;
    ifstream in_file(file_name); 

    while (getline(in_file, line)){
        bool b = balanced(line);
        cout << "The symbols: " << line << " are ";
        b ? cout << "balanced." : cout << "not balanced.";
        cout << "\n";
    }
}

int main ()
{
    bool quit = false;
    int choice;

    while (!quit){
        cout << "Please select from the following functions: " << "\n";
        cout << "1. Pattern Match" << "\n";
        cout << "2. Decimal to Base Conversion" << "\n";
        cout << "3. Balanced Parentheses" << "\n";
        cout << "4. Quit" << "\n";
        cout << "Choice: "; cin >> choice;

        switch (choice){
            case 1: firstFunction(); break;
            case 2: secondFunction(); break;
            case 3: thirdFunction(); break;
            case 4: quit = true; break;
        }
        cout << "\n";
    }
    cout << "The program has been exited." << endl;
}