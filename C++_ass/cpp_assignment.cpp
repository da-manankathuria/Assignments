#include<bits/stdc++.h>
#include <getopt.h>
using namespace std;

int flag[]={0,0,0,0};
string in="";
string op="";

string upper(string s)
{
    for(int i=0;i<s.length();i++)
    {
        s[i]=toupper(s[i]);
    }
    return s;
}

string fupper(string s)
{
    s[0]=toupper(s[0]);
    return s;
}

string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

void trim(vector<string>&s){

    for(int i=0;i<s.size();i++)
    {
        s[i]=removeSpaces(s[i]);
    }
}

void ProcessArgs(int argc, char** argv)
{
    const char* const short_opts = "a:b:cdef";
    const option long_opts[] = {
            {"input_file", required_argument, nullptr, 'a'},
            {"output_file", required_argument, nullptr, 'b'},
            {"nickname", no_argument, nullptr, 'c'},
            {"matchcode", no_argument, nullptr, 'd'},
            {"uppercase", no_argument, nullptr, 'e'},
            {"titlecase", no_argument, nullptr, 'f'},            
            {nullptr, no_argument, nullptr, 0}
    };

    while (true)
    {
        const auto opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);

        if (-1 == opt)
            break;

        switch (opt)
        {
        case 'a':
            in=optarg;
            break;

        case 'b':
            op=optarg;
            break;

        case 'c':
            flag[0]=1;
            break;

        case 'd':
            flag[1]=1;
            break;

        case 'e': 
            flag[2]=1;
            break;
        case 'f': 
            flag[3]=1;
            break;
        default:
            break;
        }
    }
}


int main(int argc, char** argv)
{

    ProcessArgs(argc, argv);
   
    fstream new_file;
    vector<string>fname;
    vector<string>lname;
    vector<string>mname;
    vector<string>nname;
    vector<string>house_no;
    vector<string>streetaddr;
    vector<string>city;
    vector<string>state;
    vector<string>zip;
    vector<char> bytes;
    vector<string>lines;
    vector<string>matchcodes;
    char byte = 0;

    string filename=in;
   

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    while (input_file.get(byte)) {
        bytes.push_back(byte);
    }
    
    int total_row = bytes.size()/116;
    int start=0;
    int end= 116;

    for (int i=0;i<total_row;i++) 
    {
        string x="";
        for(int j=start;j<end;j++)
        {
            x.push_back(bytes[j]);
        }
        start=end+1;
        end=start+116;
       lines.push_back(x);
    }


    for(int i=0;i<lines.size();i++)
    {
       
        string my_line=lines[i];

        lname.push_back(my_line.substr(0,15));
        fname.push_back(my_line.substr(15,15));
        mname.push_back(my_line.substr(30,15));
        nname.push_back(my_line.substr(45,10));
        house_no.push_back(my_line.substr(55,5));
        streetaddr.push_back(my_line.substr(60,20));
        city.push_back(my_line.substr(80,15));
        state.push_back(my_line.substr(95,15));
        zip.push_back(my_line.substr(110,6));

    }

    cout << endl;        
    trim(fname);trim(lname);
    trim(house_no);trim(streetaddr);trim(zip);
    trim(city);trim(state);
    trim(mname);trim(nname);

  

    if(op == "envelope")
    {
        cout<<" ENVELOP FORMAT "<<endl;

        for(int i=0;i<fname.size();i++)
        {
            if(flag[3]==1)
            {
                if(flag[1]==1)
            {
                string matchcode="";
                matchcode.push_back((streetaddr[i])[0]);
                matchcode.push_back((fname[i])[0]);
                matchcode = matchcode + zip[i];
                cout<<fupper(matchcode)<<" ";
            }
            if(flag[0]==1)
            cout<<fupper(nname[i])<<" ";
            else
            cout<<fupper(fname[i])<<" "<<fupper(lname[i])<<" ,";
            cout<<endl<<fupper(house_no[i])<<" "<<fupper(streetaddr[i])<<" ,";
            cout<<endl<<fupper(city[i])<<" ,"<<fupper(state[i])<<" "<<fupper(zip[i])<<" ,";
            cout<<endl<<endl;
            }

            else if(flag[2]==1)
            {
                if(flag[1]==1)
            {
                string matchcode="";
                matchcode.push_back((streetaddr[i])[0]);
                matchcode.push_back((fname[i])[0]);
                matchcode = matchcode + zip[i];
                cout<<upper(matchcode)<<" ";
            }
            if(flag[0]==1)
            cout<<upper(nname[i])<<" ";
            else
            cout<<upper(fname[i])<<" "<<lname[i]<<" ,";
            cout<<endl<<upper(house_no[i])<<" "<<upper(streetaddr[i])<<" ,";
            cout<<endl<<upper(city[i])<<" ,"<<upper(state[i])<<" "<<upper(zip[i])<<" ,";
            cout<<endl<<endl;
            }
            else{
                    if(flag[1]==1)
            {
                string matchcode="";
                matchcode.push_back((streetaddr[i])[0]);
                matchcode.push_back((fname[i])[0]);
                matchcode = matchcode + zip[i];
                cout<<matchcode<<" ";
            }
            if(flag[0]==1)
            cout<<nname[i]<<" ";
            else
            cout<<fname[i]<<" "<<lname[i]<<" ,";
            cout<<endl<<house_no[i]<<" "<<streetaddr[i]<<" ,";
            cout<<endl<<city[i]<<" ,"<<state[i]<<" "<<zip[i]<<" ,";
            cout<<endl<<endl;
            }

            
        }
    }
    
    else if(op=="fixed")
    {

         cout<<" FIXED FORMAT"<<endl;
        for(int i=0;i<fname.size();i++)
        {
            if(flag[3]==1)
            {
                if(flag[1]==1)
            {
                string matchcode="";
                matchcode.push_back((streetaddr[i])[0]);
                matchcode.push_back((fname[i])[0]);
                matchcode = matchcode + zip[i];
                cout<<fupper(matchcode)<<" ";
            }
            //std::setw (10)
            if(flag[0]==1)
            cout<<fupper(nname[i])<<std::setw (10-nname[i].length());
            else
            cout<<fupper(fname[i])<<" "<<fupper(lname[i])<<" "<<std::setw (30-2-fname[i].length()-lname[i].length());
            cout<<fupper(house_no[i])<<" "<<fupper(streetaddr[i])<<" "<<std::setw (25-2-house_no[i].length()-streetaddr[i].length());
            cout<<fupper(city[i])<<" "<<fupper(state[i])<<" "<<fupper(zip[i])<<" "<<std::setw (36-3-state[i].length()-city[i].length()-zip[i].length());
            cout<<endl<<endl;
            }
            else if(flag[2]==1)
            {
                if(flag[1]==1)
            {
                string matchcode="";
                matchcode.push_back((streetaddr[i])[0]);
                matchcode.push_back((fname[i])[0]);
                matchcode = matchcode + zip[i];
                cout<<upper(matchcode)<<" ";
            }
            //std::setw (10)
            if(flag[0]==1)
            cout<<upper(nname[i])<<std::setw (10-nname[i].length());
            else
            cout<<upper(fname[i])<<" "<<upper(lname[i])<<" "<<std::setw (30-2-fname[i].length()-lname[i].length());
            cout<<upper(house_no[i])<<" "<<upper(streetaddr[i])<<" "<<std::setw (25-2-house_no[i].length()-streetaddr[i].length());
            cout<<upper(city[i])<<" "<<upper(state[i])<<" "<<upper(zip[i])<<" "<<std::setw (36-3-state[i].length()-city[i].length()-zip[i].length());
            cout<<endl<<endl;
            }
            else{
                if(flag[1]==1)
                {
                    string matchcode="";
                    matchcode.push_back((streetaddr[i])[0]);
                    matchcode.push_back((fname[i])[0]);
                    matchcode = matchcode + zip[i];
                    cout<<matchcode<<" ";
                }
            //std::setw (10)
            if(flag[0]==1)
            cout<<nname[i]<<std::setw (10-nname[i].length());
            else
            cout<<fname[i]<<" "<<lname[i]<<" "<<std::setw (30-2-fname[i].length()-lname[i].length());
            cout<<house_no[i]<<" "<<streetaddr[i]<<" "<<std::setw (25-2-house_no[i].length()-streetaddr[i].length());
            cout<<city[i]<<" "<<state[i]<<" "<<zip[i]<<" "<<std::setw (36-3-state[i].length()-city[i].length()-zip[i].length());
            cout<<endl<<endl;
            }

            
        }
    }

   
else if(op=="fixedcsv")
{
    cout<<" FIXED FORMAT WITH CSV"<<endl;

    // "name,address1,address2"
    for(int i=0;i<fname.size();i++)
    {
        if(flag[3]==1)
        {
             if(flag[1]==1)
            {
                string matchcode="";
                matchcode.push_back((streetaddr[i])[0]);
                matchcode.push_back((fname[i])[0]);
                matchcode = matchcode + zip[i];
                cout<<fupper(matchcode)<<" ";
            }
        if(flag[0]==1)
        cout<<fupper(nname[i])<<" ";
        else
        cout<<fupper(fname[i])<<" "<<fupper(lname[i])<<" ,";
        cout<<fupper(house_no[i])<<" "<<fupper(streetaddr[i])<<" ,";
        cout<<fupper(city[i])<<" ,"<<fupper(state[i])<<" "<<fupper(zip[i])<<" ,";
        cout<<endl<<endl;
        }
        else if(flag[2]==1)
        {
            if(flag[1]==1)
            {
                string matchcode="";
                matchcode.push_back((streetaddr[i])[0]);
                matchcode.push_back((fname[i])[0]);
                matchcode = matchcode + zip[i];
                cout<<upper(matchcode)<<" ";
            }
        if(flag[0]==1)
        cout<<upper(nname[i])<<" ";
        else
        cout<<upper(fname[i])<<" "<<upper(lname[i])<<" ,";
        cout<<upper(house_no[i])<<" "<<upper(streetaddr[i])<<" ,";
        cout<<upper(city[i])<<" ,"<<upper(state[i])<<" "<<upper(zip[i])<<" ,";
        cout<<endl<<endl;
        }
        else
        {
            if(flag[1]==1)
            {
                string matchcode="";
                matchcode.push_back((streetaddr[i])[0]);
                matchcode.push_back((fname[i])[0]);
                matchcode = matchcode + zip[i];
                cout<<matchcode<<" ";
            }
        if(flag[0]==1)
        cout<<nname[i]<<" ";
        else
        cout<<fname[i]<<" "<<lname[i]<<" ,";
        cout<<house_no[i]<<" "<<streetaddr[i]<<" ,";
        cout<<city[i]<<" ,"<<state[i]<<" "<<zip[i]<<" ,";
        cout<<endl<<endl;
        }


         
    }


}
    
    
    input_file.close();
    return 0;
       
} 