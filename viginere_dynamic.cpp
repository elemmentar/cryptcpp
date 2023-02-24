#include <iostream> 
#include <iterator> 
#include <string.h>
#include <string>
#include <sstream>
#include <time.h>
#include <fstream>

using namespace std; 
int seed=time(NULL);


void Encr(char *encrypt_name, char *message, char *key){
    string repeat;
    string msg; msg+=message;
    string k;k+=key;
    int rezt=msg.length()%k.length();
    
    
    
    for(int i=0;i<rezt+1;++i){ 
        repeat+=k;} 
    repeat.erase(repeat.size() - (repeat.size()-msg.size())); 
    
    
    
    string encrypt;
    for (int i = 0; i < msg.length(); ++i){
        char add = (msg[i] + repeat[i]+seed) %26+'A';
        encrypt+=add;}
        
        
        
    cout<<"seed:"<<seed<<endl;
    cout<<"Concatinate key: "<<repeat<<endl;    
    cout<<"Encrypt: "<<encrypt<<endl;
    
    
    
    ofstream fout;
    fout.open("in.txt");
    if(!fout.is_open()){
        cout<<"error";
    }
    else{
        fout<<seed<<"\n";}
}

void Dcsr(char *encrypt_name, char *message, char *key){
    
    char ch;
    string newseed;
    
    ifstream fin;
    fin.open("in.txt");
    if(!fin.is_open()){
        cout<<"error";
    }
    else{
        
        
        while(fin.get(ch)){
            
            newseed+=ch; 
        }
        
    }
    fin.close();
    

    
    stringstream num(newseed);
    int newseed2;
    num>>newseed2;
    string repeat;
    string msg; msg+=message;
    string k;k+=key;
    int rezt=msg.length()%k.length();
    
    
    
    for(int i=0;i<rezt+1;++i){ 
        repeat+=k;} 
    repeat.erase(repeat.size() - (repeat.size()-msg.size())); 
    
    
    
    string decrypt;
    for (int i = 0; i < msg.length(); ++i){
        char add = (msg[i] - repeat[i]- (newseed2 % 26))%26+26+'A';
        
         if( (msg[i] - repeat[i]- (newseed2 % 26))%26+26>25){
            add=add-26;
        }
        
        decrypt+=add;
    }
    
    
    
    cout<<"seed: "<<newseed2<<"\n";
    cout<<"Concatinate key: "<<repeat<<endl;
    cout<<"Decrypt: "<<decrypt<<endl;
}




int main(int argc , char *argv[]) 
{   
    char *prog_name=argv[0];
    char *encrypt_name=argv[1];
    char *message=argv[2]; 
    char *key = argv[3]; 
    
    
    
    if(argc==1){
        cout<<"no option and message";
    }
    if(argc==2){
        cout<<"no option or message";
    }
    if(argc==4){
        if(!strcmp(argv[1],"-Evgm")){
            Encr(encrypt_name,message,key);
        }
        if(!strcmp(argv[1],"-Dvgm")){
            Dcsr(encrypt_name,message,key);
        }
    }
    
    else{
        cout<<"too many argumenst";
    }
    
    
  
  
    
    return 0; 
}
//viginere-dynamic