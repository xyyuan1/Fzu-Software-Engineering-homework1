#include<bits/stdc++.h>
using namespace std;
/*Define class program*/
class program
{
public:
    string name;//Keyword
    int number; //Keywords' numbers
    void Search_name(string);//the function of searching keywords
    void Print_number();
    void Switch_search(int);
    void Case_count(int);
    void Ifelse_search(int);
    void Ifelse_judge();
};
/*Define the keyword array*/
program p[32] = { "auto", 0,"break",0,"case",0,"char",0,"const", 0,"continue",0,"default",0,"do", 0,
                 "double",0,"else",0,"enum",0,"float",0,"for",0,"goto",0,"if",0,"int",0,
                 "long",0,"register",0, "while", 0,"reuturn",0,"short",0,"signed",0,"sizeof",0,"static", 0,
                 "struct",0,"switch",0,"typedef",0,"union",0,"unsigned",0,"void", 0 ,"volatile",0,"while", 0 };
/*declare variables and functions*/
/*advanced requirements*/
int switch_number = 0;
int case_number[50] = {0};
/*further requirements*/
int ifelse_number = 0;
bool If_flg = false, Else_flg = false;
int Stack[101] = {0}; //define ifelse's stack
int top = 0; //stack's top
int flg = 0;//"else if"'s flag
/*final requirements*/
int ifelseifelse_number = 0;

void Case_count(int);
void Switch_search(int i)
{
    if (i == 25)//switch
    {
        switch_number++;
    }
    Case_count(i);
}
void Case_count(int i)
{
    if (i == 2)//case
    {
        case_number[switch_number]++;//case_number+1 in this switch structure
    }
}
void Ifelse_search(int i)
{
    if (i == 14)
    {
        If_flg = true;
    }
    if (i == 9)
    {
        Else_flg = true;
    }
}
void Ifelse_judge()
{
    if (If_flg == true && Else_flg == false)//only "if" in the line
    {
        flg = 0;
        ifelse_number++;
        Stack[top] = 1; //push if
        top++;
    }
    if (If_flg == false && Else_flg == true)//only "else" in the line
    {

        top--;
        Stack[top] = 0; //pop if
    }
    if (If_flg == true && Else_flg == true)//only "else if" in the line
    {
        if (flg == 0)
        {
            ifelse_number--;
            ifelseifelse_number++;
            flg = true;
        }
    }
    If_flg = false;
    Else_flg = false;
}
/*output the results*/
void Print_number()
{
    int level;
    cin >> level;
    int sum;//total num
    for (int i = 0; i < 32; i++)
    {
        if (p[i].number != 0)
        {
            sum += p[i].number;
        }
    }
    cout << "total num: " << sum << endl;
    if (level > 1)//level = 2
    {
        bool Case_flag = false;
        cout << "switch num: " << switch_number << endl;
        cout << "case num: ";
        for (int i = 0; i < 50; i++)
        {
            if (case_number[i] != 0)
            {
                cout << case_number[i] << " ";
                Case_flag = true;
            }
        }
        if (Case_flag == false)
        {
            cout << "0";
        }
        cout << endl;
    }
    if (level > 2)//level = 3
    {
        cout << "if-else num: " << ifelse_number << endl;
    }
    if (level > 3)//level = 4
    {
        cout << "if-elseif-else num: " << ifelseifelse_number << endl;
    }
}

void Search_name(string str)
{
    for (int i = 0; i < 32; i++)
    {
        if (str.find(p[i].name) != -1)
        {
            p[i].number++;
            Switch_search(i);
            Ifelse_search(i);
        }
    }
}

int main()
{
    string file_name;
    /* input file address*/
    cin >> file_name;
    ifstream in(file_name.c_str());//read the file (example：./test.c)./
    string str;
    if (in.is_open())
    {
        while (!in.eof())//file -> str
        {
            getline(in, str); //search by lines
            Search_name(str);
            Ifelse_judge();
        }
    }
    else
    {
        cout << "Error opening " << file_name << " for input" << endl;
        return -1;
    }
    /*output the results*/
    Print_number();
    return 0;
}
