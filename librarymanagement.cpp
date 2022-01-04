#include<iostream>
#include<fstream>
#include<windows.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<conio.h>
#include<iomanip>
using namespace std;

//A short project based on library Management system

int verify();
string input(string);
int value;
int count=3;

int loading(){
  cout<<"\n\t\t\t\t  You have to insert book and student record\n";
  cout<<"\n\n\t\t\t\t\tPlease wait while loading\n";

  char a=177, b=219;
  cout<<"\t\t\t\t\t";
  for (int i=0;i<=30;i++)
  cout<<a;
  cout<<"\r";
  cout<<"\t\t\t\t\t";
  for (int i=0;i<=30;i++)
  {
   cout<<b;
   Sleep(100);
  }
  system("cls");
  return 0;
}


class book{
public:
  char title[30];
  char author[30];
  int bno;
//--------------------------
  void getData();
  void showBook();
  void showAll();
  void saveBook();
  void searchBook(char*);
  void updateBook(char*);
  void deleteBook(char*);

  int retbno(){
    return bno;
  }
};

void book::getData(){
  cin.ignore();
  cout<<"\nenter book title : ";
  cin.getline(title,30);
  cout<<"enter author name : ";
  cin.getline(author,30);
  cout<<"book no : ";
  cin>>bno;
}

void book::showBook(){

  cout<<"\t"<<setw(30)<<left<<title<<"\t"<<setw(30)<<left<<author<<" "<<bno;
  cout<<"\n";
}

void book::saveBook(){
  fstream fout;
  fout.open("filebook.txt",ios::app|ios::binary);
  fout.write((char*)this,sizeof(*this));
  fout.close();
}

void book::showAll(){
  fstream fin;
  fin.open("filebook.txt",ios::in|ios::binary);
  if(!fin){
    cout<<"\nfile not found!";
    return ;
  }
  else{
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof()){
      showBook();
      fin.read((char*)this,sizeof(*this));
    }
  }

  fin.close();
}

void book::searchBook(char*data){
  fstream fin;
  fin.open("filebook.txt",ios::in|ios::binary);
  if(!fin){
    cout<<"\nfile not found!";
    return ;
  }
  else{
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof()){
      if(!strcmp(data,title))
      showBook();
      fin.read((char*)this,sizeof(*this));
    }
  }
  fin.close();
}

void book::deleteBook(char* data){
  fstream fin,fout;
  fin.open("filebook.txt",ios::in|ios::binary);
  if(!fin){
    cout<<"\nfile not found!";
    return ;
  }
  else{
    fin.read((char*)this,sizeof(*this));
    fout.open("tempfile6.txt",ios::out|ios::binary);
    while(!fin.eof()){
      if(strcmp(data,title))
      fout.write((char*)this,sizeof(*this));
      fin.read((char*)this,sizeof(*this));
    }
    fout.close();
    fin.close();
    remove("filebook.txt");
    rename("tempfile6.txt","filebook.txt");
  }
}

void book::updateBook(char*data){
  int value;
  fstream file;
  file.open("filebook.txt",ios::in|ios::out|ios::ate|ios::binary);

  if(!file){
  cout<<"\nFile not found";
  return ;
  }
  else {
  file.seekg(0);
  file.read((char*)this,sizeof(*this));
  while(!file.eof()){
    if(!strcmp(data,title)){
      getData();
      file.seekp(file.tellp()-sizeof(*this));
      file.write((char*)this,sizeof(*this));
       }
    file.read((char*)this,sizeof(*this));
     }
    }
   file.close();
}

//______________________________________________________________________________
//______________________________________________________________________________

class student{
public:
  char name[30];
  int admno;
  int stbno;
  int limit;
//-----------------------
student(){
  limit=0;
}
void getData();
void showData();
void showAll();
void saveData();
void searchData(int);
void updateData(int);
void deleteData(int);

int retadmno(){
    return admno;
}

int retstbno(){
    return stbno;
}

int retlimit(){
    return limit;
}

void addlimit(){
      limit=1;
}

void resetlimit(){
     limit=0;
}

void getstbno(int t){
    stbno=t;
}

};

void student::getData(){
  cin.ignore();
  cout<<"\nenter name of student : ";
  cin.getline(name,30);
  cout<<"\nenter admission no of student : ";
  cin>>admno;
  limit=0;
  stbno=0;
}

void student::showData(){
  cout<<"\t"<<setw(30)<<left<<name<<"\t"<<setw(10)<<left<<admno<<"\n";
}

void student::showAll(){
  fstream fin;
  fin.open("fileStudent.txt",ios::in|ios::binary);
  if(!fin){
    cout<<"\nfile not found!";
    return ;
  }
  else{
  fin.read((char*)this,sizeof(*this));
  while(!fin.eof()){
    showData();
    fin.read((char*)this,sizeof(*this));
  }
}
fin.close();
}

void student::saveData(){
  fstream fout;
  fout.open("fileStudent.txt",ios::app|ios::binary);
  fout.write((char*)this,sizeof(*this));
  fout.close();
}

void student::searchData(int data){
  fstream fin;
  fin.open("fileStudent.txt",ios::in|ios::binary);
  if(!fin){
    cout<<"\nfile not found!";
    return ;
  }
  else{
  fin.read((char*)this,sizeof(*this));
  while(!fin.eof()){
    if(data==admno)
    showData();
    fin.read((char*)this,sizeof(*this));
  }
}
fin.close();
}

void student::updateData(int data){
  int value;
  fstream file;
  file.open("fileStudent.txt",ios::in|ios::out|ios::ate|ios::binary);
  if(!file){
  cout<<"\nFile not found";
  return ;
  }
  else {
  file.seekg(0);
  file.read((char*)this,sizeof(*this));
  while(!file.eof()){
    if(data==admno){
      getData();
      file.seekp(file.tellp()-sizeof(*this));
      file.write((char*)this,sizeof(*this));
       }
    file.read((char*)this,sizeof(*this));
     }
    }
   file.close();
}

void student::deleteData(int data){
  fstream fin,fout;
  fin.open("fileStudent.txt",ios::in|ios::binary);
  if(!fin){
    cout<<"\nfile not found!";
    return ;
  }
  else{
    fin.read((char*)this,sizeof(*this));
    fout.open("tempfile7.txt",ios::out|ios::binary);
    // fout.write("tempfile7.txt",ios::out|ios::binary);
    while(!fin.eof()){
      if(!(data==admno))
      fout.write((char*)this,sizeof(*this));
      fin.read((char*)this,sizeof(*this));
    }
  fin.close();
  fout.close();
  }
  remove("fileStudent.txt");
  rename("tempfile7.txt","fileStudent.txt");
}
//----------------------------------------------------------------------
//______________________________________________________________________

fstream fp,fp1;
book b;
student s;
//______________________________________________________________________
//----------------------------------------------------------------------
void book_issue(){
int sn,bn;
int found=0,flag=0;

cout<<"\nBOOK ISSUE ...\n=============";
cout<<"\nEnter student's admission no.";
cin>>sn;

fp.open("fileStudent.txt",ios::in|ios::out);
fp1.open("filebook.txt",ios::in|ios::out);
// fp.read((char*)&s,sizeof(student));
while((fp.read((char*)&s,sizeof(student))) && found==0){
  if(s.retadmno()==sn){
found=1;
  if(s.retlimit()==0){
cout<<"\nEnter the book no. ";
  cin>>bn;
while(fp1.read((char*)&b,sizeof(book))&& flag==0){

  if(b.retbno()==bn){
b.showBook();
flag=1;
s.addlimit();
s.getstbno(b.retbno());

int pos=-1*sizeof(s);

fp.seekp(pos,ios::cur);
fp.write((char*)&s,sizeof(student));
cout<<"\nBook issued successfully\n";
  }
 }
if(flag==0)
cout<<"Book number does not exist";
 }
else
cout<<"You have not returned the last book ";
  }
  fp.read((char*)&s,sizeof(student));
 }
if(found==0)
cout<<"Student record not exist...";
    // getch();
fp.close();
fp1.close();
}

//_____________________________________________________________________________
//_____________________________________________________________________________
void deposit_book() {
  int sn,bn;
  int found=0,flag=0,day,fine;
  // clrscr();

  cout<<"\n BOOK DEPOSIT ...";
  cout<<"\n Enter The student admission no.";
  cin>>sn;
  fp.open("fileStudent.txt",ios::in|ios::out);
  fp1.open("filebook.txt",ios::in|ios::out);

  while(fp.read((char*)&s,sizeof(student)) && found==0) {

  if(s.retadmno()==sn) {
  found=1;
   if(s.retlimit()==1) {
    while(fp1.read((char*)&b,sizeof(book))&& flag==0) {
  if(b.retbno()==s.retstbno()) {
  b.showBook();
  flag=1;
  s.resetlimit();
  int pos=-1*sizeof(s);
  fp.seekp(pos,ios::cur);
  fp.write((char*)&s,sizeof(student));
  }
  else if (flag==0)
  cout<<"Book no does not exist";
 }
 cout<<"\nBook deposited successfully";

}


else
cout<<"\nNo book is issued..please check!!";

  }

  }

if(found==0)
cout<<"Student record not exist...";
getch();
fp.close();
fp1.close();
}


//_____________________________________________________________________________

int menu(int o,int n){
  char ch[30];
  loading();
  while(1){
    cout<<"\n\n\t\t\t\t\t\tC++ Library Management System\n\t\t\t\t\t\t\tusing C++\n";
    cout<<"\t\t\t\t   ____________________________________________________\n";
    cout<<"\t\t\t\t   ____________________________________________________\n\n";
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
  cout<<"\n1) Book Data\n2) Student Data\n3) Exit\n";
  cout<<"select any option : ";
  cin>>o;
  switch(o){
    case 1: {
      cout<<"\n1) Show all Book\n2) Search Book\n3) Insert Data\n4) Update Data\n5) Delete Book\n6) Exit\n";
      cout<<"enter any option : ";
      cin>>o;
      switch(o){
        case 1: cout<<"\n\t"<<"Title"<<"\t\t\t "<<"\t  Author"<<"\t\t  "<<" Book No"<<"\n";
                cout<<"\t"<<"_______"<<"\t\t\t "<<"\t_________"<<"\t\t  "<<"_________"<<"\n\n";
                b.showAll();
                cout<<"\npress any key to continue ";
                getch();

        break;
        case 2: cout<<"\nenter book title you want to search : ";
                cin.ignore();
                cin.getline(ch,30);
                b.searchBook(ch);
                cout<<"\npress any key to continue ";
                getch();

        break;
        case 3: b.getData();
                b.saveBook();
                cout<<"\npress any key to continue";
                getch();
        break;
        case 4: cout<<"\nenter book title you want to update : ";
                char ch2[30];
                cin.ignore();
                cin.getline(ch2,30);
                b.updateBook(ch2);
        break;
        case 5: cout<<"enter book title : ";
                char ch3[30];
                cin.ignore();
                cin.getline(ch2,30);
                b.deleteBook(ch2);
        break;
        case 6: break;
        break;
        default: cout<<"invalide option!";
      }

    }
    break;
    case 2:  if(verify()){
      cout<<"\n";
      cout<<"\n1) Show all Student list\n2) Search Student\n3) Insert student data\n4) Update student data\n5) Delete Student data\n6) Issue Book\n7) Deposit Book\n8) Exit";
      cout<<"\nselect any option : ";
      cin>>o;
      switch(o){
        case 1: cout<<"\n\tStudent name"<<"   \t\t"<<"student admission number \n";
                cout<<"\t_____________"<<"  \t\t"<<"_______________________\n\n";
                s.showAll();
                cout<<"\npress any key to continue ";
                getch();
        break;
        case 2: cout<<"enter student Admission number : ";
                cin>>n;
                s.searchData(n);
                cout<<"\npress any key to continue";
                getch();

        break;
        case 3: s.getData();
                s.saveData();
                cout<<"\npress any key to continue";
                getch();
        break;
        case 4: cout<<"\nenter student admission number : ";
                cin>>n;
                s.updateData(n);
                cout<<"\npress any key to continue";
                getch();

        break;
        case 5: cout<<"\nenter student admission number : ";
                cin>>n;
                s.deleteData(n);
                cout<<"\npress any key to continue";
                getch();

        break;
        case 6: book_issue();
                cout<<"\npress any key to continue";
                getch();
        break;
        case 7: deposit_book();
                cout<<"\npress any key to continue";
                getch();
        break;
        case 8: break;
        break;
        default: cout<<"\ninvalide option!";
                  getch();
      }
    }
    else{
    cout<<"access denied!";
    return 1;
    }
    break;

    case 3: exit(1);
    break;
    default: cout<<"invalide option!";
  }
  system("cls");
 }
}


int main(){

  int o,n;
  // system("Color 05");

  menu(o,n);

 return 0;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int verify(){
  int value=0;
  string password1={"souravgupta@.com"};
  int i=59;
 //to check password------------
  while(count>=1){
    string password2;
    password2=input(password2);
    count--;
    if(!password1.compare(password2))
    {
      cout<<"\nCorrect Password";
      value= 1;
      return value;
    }
    else
      cout<<"\nincorrect password entered!";
      cout<<" "<<count<<" attempts remaining";
      //end of loop----
      value=0;
  }
return value;
}

//______________________________________________________________________________
//______________________________________________________________________________
string input(string password2)
{
char c;
cout<<"\nenter your password : ";
while(c!=13){
 c=getch();
 if(c==32){
 continue;
          }
else if(c==8){
  c='\0';
  password2=password2.erase(password2.length()-1);
  cout<<"\b"<<" "<<"\b";
     }

else {
  password2.push_back(c);
  cout<<"*";
     }
  }
password2=password2.erase(password2.length()-1);
return password2;
}
