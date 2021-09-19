#include<bits/stdc++.h>
#include<fstream>
using namespace std;
/*Define program class*/
class program
{
    public:
        string name;//Keyword
        int number; //Keywords' numbers
    	void Search_name(string str);//the function of searching keywords
        void Print_number();
};
/*Define the keyword array*/
program p[32] = {"auto", 0,"break",0,"case",0,"char",0,"const", 0,"continue",0,"default",0,"do", 0,
                 "double",0,"else",0,"enum",0,"float",0,"for",0,"goto",0,"if",0,"int",0,
                 "long",0,"register",0, "while", 0,"reuturn",0,"short",0,"signed",0,"sizeof",0,"static", 0,
                 "struct",0,"switch",0,"typedef",0,"union",0,"unsigned",0,"void", 0 ,"volatile",0,"while", 0};
string str;
/*declare variables and functions*/
/*advanced requirements*/
int switch_number=0;
int case_number[50]={0};
/*further requirements*/
int ifelse_number=0;
int If_flg=0, Else_flg=0;
int Stack[101]={0}; //define ifelse's stack
int top=0; //stack's top
int flg=0;//"else if"'s flag
/*final requirements*/
int ifelseifelse_number=0;//记录if_elseif_else结构数量

void Switch_search(int i)
{
    if (i==25)//switch
    {
        switch_number++;
    }
    else if (i==2)//case
    {
        case_number[switch_number]++;//case_number+1 in this switch structure
    }
}
void Ifelse_search(int i)
{
    if (i==14)
    {
        If_flg = 1;
    }
    if (i==9)
    {
        Else_flg = 1;
    }
}
void Ifelse_judge()
{
    if (If_flg==1 && Else_flg==0)//only "if" in the line
    {
        flg=0;
        ifelse_number++;
        Stack[top] = 1; //表示if入栈
        top++;
    }
    if (If_flg==0 && Else_flg==1)//only "else" in the line
    {
    	
        	top--;
        	Stack[top] = 0; //if出栈
    }
    if (If_flg==1 && Else_flg==1)//only "else if" in the line
    {
        if (flg==0)
        {
        	ifelse_number--;
        	if (str.find("}") == -1)
        	{
        		ifelseifelse_number++;
        	}	
        	flg = 1;
        }
    }
    If_flg = 0;
    Else_flg = 0;
}
/*output the results*/ 
void Print_number()
{
    int level;
    cin >> level;
    int sum;//total num
    for (int i = 0; i < 32; i++)
    {
        if (p[i].number!=0)
        { 
            sum += p[i].number;
        }
    }
    cout << "total num: " << sum << endl;
    if (level > 1)
    {
    	bool Case_flag = false;
        cout << "switch num: " << switch_number << endl;
        cout << "case num: ";
        for (int i = 0; i < 50; i++)
        {
            if (case_number[i]!=0)
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
    if (level > 2)
    {
        cout << "if-else num: " << ifelse_number << endl;
    }
    if (level > 3)
    {
        cout << "if-elseif-else num: " << ifelseifelse_number << endl;
    }
}

void Search_name(string str)
{
    for(int i=0; i<32; i++)
    {
        if(str.find(p[i].name)!=-1)
        {
            p[i].number++;
            Switch_search(i);
            Ifelse_search(i);
        }
    }
    Ifelse_judge();
}

int main()
{
	string str;
    ifstream in("./test if_else.txt");//read the file(.txt)
    if (in.is_open())
    {
        while (!in.eof())
        {
            getline(in,str); //search by lines
            Search_name(str);
        }      
    }
    /*output the results*/
    Print_number();
    return 0;
}
