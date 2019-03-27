#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include<windows.h>
#include<bits/stdc++.h>
using namespace std;

template <typename T>
T get_input(const string &strQuery);
string get_username();
string get_password();
void save_user(const string &username, const string &password);
void login();
void register_user();
void main_menu();

template <typename T>
T get_input(const string &strQuery)
{
    cout << strQuery << "\n> ";
    T out = T();
    while (!(cin >> out))
    {
        cin.clear();
        cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
        cout << "\t\t\t\t\tError!" "\n";
    }
    return out;
}
string get_password()
{
    string password1 = get_input <string> ("\t\t\tPlease enter your password.");
    string password2 = get_input <string> ("\t\t\tPlease re-enter your password.");

    while (password1 != password2)
    {
        cout << "\t\t\t\t\tError! Passwords do not match." "\n";
        password1 = get_input <string>("\t\t\tPlease enter your password.");
        password2 = get_input <string>("\t\t\tPlease re-enter your password.");
    }
    return password1;
}
string get_username()
{
    string username = get_input <string>("\t\t\tPlease enter a Username.");
    cout << "\t\t\tUsername: " << username << "\t\t";

    while (get_input <int>("\t\t\tIf you wish to confirm your Username please enter 1.") != 1)
    {
        username = get_input <string>("\t\t\tPlease enter a Username.");
        cout << "\t\t\tUsername: " << username << "\t\t";
    }
    return username;
}
void login()
{
    string line = " ";
    ifstream readFile("userandpassword.txt");
    string UserName;
    string Password;
    string _UserName;
    string _Password;
    cout << "\t\t\tEnter UserName: ";
    cin >> UserName;
    cout << "\t\t\tEnter Password: ";
    cin >> Password;
    bool found = false;

    while (getline(readFile,line))
    {
        stringstream iss(line);
        iss >> _UserName >> _Password;
        if (UserName == _UserName && Password == _Password)
        {
            cout<<"\t\t\t\t\t\t";

            for(int i=0;i<5;i++)
            {
                cout<<".";
                Sleep(100);
            }
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout << "\t\t\t\t\tLogin Successful!"<< endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\t\t\t\t\tInvalid Username And Password"<< endl;
        cout<<"\t\t\t\tTo Register press 1 and for trying Logging again press 2"<<endl;
        int choice;
        cout<<"\t\t\t\t\t";
        A:
        cin>>choice;
        switch(choice)
        {
            case 1:
                register_user();
                break;
            case 2:
                login();
                break;
            default:
            cout<<"Wrong input. Please choose again.\n>";
            goto A;
        }
    }

}
void main_menu()
{
    int choice = get_input <int>("\n\n\n\n\n\n\n"
        "\t\t\t\tHello, Would you like to Log in or Register?" "\n"
        "\t\t\t\t[1] Login" "\n"
        "\t\t\t\t[2] Register" "\n"
        "\t\t\t\t[3] Exit");
    B:
    switch (choice)
    {
        case 1:
            login();
            break;
        case 2:
            register_user();
            cout<<"\t\t\t\t\t\t";
            for(int i=0;i<5;i++)
            {
                cout<<".";
                Sleep(100);
            }
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout <<"\t\t\t\t\tRegistered Successfully!"<< endl;
            break;
        case 3:
            exit(0);
            break;
        default:
            cout<<"Wrong input. Please enter your choice again.\n>";
            cin>>choice;
            goto B;
    }
}
void register_user()
{
    string username = get_username();
    string password = get_password();
    save_user(username, password);
}
void save_user(const string &username, const string &password)
{
    ofstream myfile;
    myfile.open ("userandpassword.txt",ios::app);
    myfile << username<< " "<< password;
    myfile<<'\n';
    myfile.close();
}
void Welcome_window()
{
    cout<<"\t\t\t\t\t\tWelcome to our Travel Agency\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\tThe Agency is managed by: \n\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t\tVeenit Kumar\n\n";
    cout<<"\t\t\t\t\t\t\t\tHarshal Tyagi\n\n";
    cout<<"\t\t\t\t\t\t\t\tAyush Tiwari\n\n";

}
class Pair
{
    public:
        string destination;
        float dist;
        int condition;
        Pair(string dest, float weight,int cond=1)
        {
            destination=dest;
            dist=weight;
            condition=cond;
        }
};
class Graph
{
    int V;
    map<string, list< Pair > > adjList;
    public:
        Graph(int v)
        {
            V=v;
        }
        void addEdge(string src, string dest,float wt,int condition)
        {
            Pair p (dest,wt,condition);
            Pair k (src,wt,condition);
            adjList[src].push_back(p);
            adjList[dest].push_back(k);
        }
        void print()
        {
            /*to print the source and destination the place is connected to*/
            for(auto it=adjList.begin();it!=adjList.end();it++)
            {
                cout<<"\t\t\t"<<(it)->first<<"-->\t\t";
                for(auto lit=((it)->second).begin();lit!=((it)->second).end();lit++)
                {
                   cout<<(lit)->destination<<", ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
        void Validate_input(string &src,string &des)
        {
            if(( adjList.find(src) == adjList.end() ))
            {
                cout<<"\t\t\t\tSource Could Not be Found, Renter\n";
                string src1;
                cin>>src1;
                src=src1;
            }
            if(( adjList.find(des) == adjList.end() ))
            {
                cout<<"\t\t\t\tDestination Could Not be Found, Renter\n";
                string des1;
                cin>>des1;
                des=des1;
            }
        }
};
int main()
{
    Welcome_window();
    Sleep(6000);
    system("cls");
    Graph g(75);
    main_menu();
    Sleep(2000);
    system("cls");
    string line = " ";
    ifstream readFile("Distance-From-City.txt");
    string source;
    string destination;
    string distance;
    string condition;
    while (getline(readFile,line))
    {
        stringstream iss(line);
        iss >> source >> destination >> distance >> condition;
        float D= strtof((distance).c_str(),0);
        int C= atoi((condition).c_str());
        g.addEdge(source,destination,D,C);
    }
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    for(int i=0;i<10;i++)
    {
        cout<<"\t\t\t\t\t\t\t\t";
        for(int k=9-i;k>=0;k--)
            cout<<" ";
        for(int j=1;j<=i;j++)
        {
            cout<<"*"<<" ";
            Sleep(50);
        }
        cout<<endl;
    }
    system("cls");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"-----------------------THE LIST OF CITIES THAT THE AGENCY MANAGES ARE---------------------------";
    Sleep(1000);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    g.print();
    cout<<"\t\t\tEnter the City from the list above:\t";
    string src;
    cin>>src;
    cin.ignore();
    cout<<"\t\t\tEnter Your Destination:\t";
    string dest;
    cin>>dest;
    g.Validate_input(src,dest);
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    for(int i=0;i<10;i++)
    {
        cout<<"\t\t\t\t\t\t\t\t";
        for(int k=9-i;k>=0;k--)
            cout<<" ";
        for(int j=1;j<=i;j++)
        {
            cout<<"*"<<" ";
            Sleep(50);
        }
        cout<<endl;
    }
    system("cls");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    return 0;
}
