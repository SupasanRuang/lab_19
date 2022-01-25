#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string &filename,vector<string> &names,vector<int> &scores,vector<char> &grades){
    ifstream listfile;
    listfile.open(filename);
    string copyline ;
    int p,q,r,sum=0;
    while (getline(listfile,copyline)){
        sum=0;
        char who[100];
        sscanf(copyline.c_str(),"%[^:]: %d %d %d",who,&p,&q,&r);
        string nametext (who);
        names.push_back(nametext);
        sum=p+q+r;
        scores.push_back(sum);
        grades.push_back(score2grade(sum));
    }
    listfile.close();
}

void getCommand(string &command,string &key){     
    cout<<"Please input your command: ";
    string copyline;
    char textcom1[100],textcom2[100];
    getline(cin,copyline);
    sscanf(copyline.c_str(),"%s %[^\n]", textcom1, textcom2);
    string textcom3(textcom1),textcom4(textcom2);
    command=textcom3;
    key=textcom4;
}

void searchName(vector<string> &names1,vector<int> &scores,vector<char> &grades,string key){
    
    cout<<"---------------------------------"<<endl;
    bool ch=false;
    string temp1=key,temp2;
    for(int i=0;i<26;i++)
    {
        temp2=toUpperStr(names1[i]);
       
        if(!temp1.compare(temp2))
        {
            cout<<names1[i]<<"'s score = "<<scores[i]<<"\n";
            cout<<names1[i]<<"'s grade = "<<grades[i]<<"\n";
            ch=true;
        }
        
    }
    if(!ch)
        {
            cout<<"Cannot found."<<endl;
        }
    cout<<"---------------------------------"<<endl;
}


void searchGrade( vector<string> &names2, vector<int> &scores, vector<char> &grades, string key){
     cout<<"---------------------------------"<<endl;
    bool ch=false;
    for(int i=0;i<26;i++)
    {
        if(key[0]==grades[i])
        {
            cout<<names2[i]<<" ("<<scores[i]<<")\n";
            ch=true;
        }
    }
    if(!ch)
        {
            cout<<"Cannot found."<<endl;
        }
    
    cout<<"---------------------------------"<<endl;
    
}

int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}