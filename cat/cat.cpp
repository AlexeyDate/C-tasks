#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    ifstream file;
    stringstream ss;
    string in_buf;
    string flag;
    string path;
    string out_buf;

    setlocale(LC_ALL, "");
    cout << "Simulation of utility cat" << endl;
    getline(cin, in_buf);
    
    ss.str(in_buf);
    ss >> in_buf >> flag >> path;

    if (in_buf == "cat")
    {
        file.open(path);
        if (file.is_open())
        {
            if (flag == "-A" || flag == "--show-all")
            {
                while (getline(file, out_buf))
                {
                    cout << out_buf << endl;
                }
            }
            else
            {
                cout << "Error, wrong key" << endl;
                return -1;
            }          
        }
        else
        {
            cout << "Error, acces denied" << endl;
            return -1;
        }
    }
    else
    {
        cout << "Error, wrong format" << endl;
        return -1;
    } 

    return 0;
}


