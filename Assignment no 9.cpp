
#include<iostream>
#include<fstream>
using namespace std;

typedef struct EMP_REC
 {
 char name[10];
 int emp_id;
 int salary;
 }Rec;

typedef struct INDEX_REC
  {
  int emp_id;
  int position;
  }Ind_Rec;

class Employee
{

 Rec Records;
 Ind_Rec Ind_Records;
 public:
  void Create();
  void Display();
  void Search();
};

void Employee::Create()
{
 char ch='y';
 ofstream seqfile;
 ofstream indexfile;
 int i=0;
 indexfile.open("IND.DAT",ios::out|ios::binary);
 seqfile.open("EMP.DAT",ios::out|ios::binary);
 do
 {
  cout<<"\n Enter Name: ";
  cin>>Records.name;
  cout<<"\n Enter Emp_ID: ";
  cin>>Records.emp_id;
  cout<<"\n Enter Salary: ";
  cin>>Records.salary;
  cout<<Records.name<<" "<<Records.emp_id<<" "<<Records.salary;

  seqfile.write((char*)&Records,sizeof(Records));

  Ind_Records.emp_id=Records.emp_id;
  Ind_Records.position=i;
  indexfile.write((char*)&Ind_Records,sizeof(Ind_Records));
  cout<<Ind_Records.emp_id<<" "<<Ind_Records.position;
  i++;
  cout<<"\nDo you want to add more records?";
  cin>>ch;
  }while(ch=='y');
  seqfile.close();
  indexfile.close();
}

void Employee::Display()
{
 ifstream seqfile;
 ifstream indexfile;

 seqfile.open("EMP.DAT",ios::in|ios::binary);
 indexfile.open("IND.DAT",ios::in|ios::binary);
 cout<<"\n The Contents of file are ..."<<endl;
 int i=0;
 while(indexfile.read((char *)&Ind_Records,sizeof(Ind_Records)))
 {
	 cout<<"insidewhile";
   i=Ind_Records.position*sizeof(Rec);//getting pos from index file

   cout<<"i:"<<i<<endl;
   seqfile.seekg(i,ios::beg);//seeking record of that pos from seq.file
   seqfile.read((char *)&Records,sizeof(Records));//reading record
   if(Records.emp_id!=-1)//if rec. is not deleted logically
   {   //then display it
   cout<<"\nName: "<<Records.name<<flush;
   cout<<"\nEmp_ID: "<<Records.emp_id;
   cout<<"\nSalary: "<<Records.salary;
   cout<<"\n";
    }

 }
 seqfile.close();
 indexfile.close();
}
void Employee::Search()
{
 fstream seqfile;
 fstream indexfile;
 int id,pos,offset;
 cout<<"\n Enter the Emp_ID for searching the record ";
 cin>>id;
 indexfile.open("IND.DAT",ios::in|ios::binary);
 pos=-1;
 //reading index file to obtain the index of desired record
 while(indexfile.read((char *)&Ind_Records,sizeof(Ind_Records)))
 {
  if(id==Ind_Records.emp_id)//desired record found
  {
   pos=Ind_Records.position;//seeking the position
   break;
  }
 }
  if(pos==-1)
  {
  cout<<"\n Record is not present in the file";
  return;
  }
//calculate offset using position obtained from ind. file
  offset=pos*sizeof(Records);
  seqfile.open("EMP.DAT",ios::in|ios::binary);
//seeking the record from seq. file using calculated offset
  seqfile.seekg(offset,ios::beg);//seeking for reading purpose
  seqfile.read((char *)&Records,sizeof(Records));
  if(Records.emp_id==-1)
  {
  cout<<"\n Record is not present in the file";
  return;
  }
  else //emp_id=desired record’s id
  {
  cout<<"\n The Record is present in the file and it is...";
  cout<<"\n Name: "<<Records.name;
  cout<<"\n Emp_ID: "<<Records.emp_id;
  cout<<"\n Salary: "<<Records.salary;
  }
  seqfile.close();
  indexfile.close();
}

int main()
{
 Employee e;
 e.Create();
 e.Display();
 e.Search();
return 0;
}
