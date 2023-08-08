// Roll: 2107073
// Name: Md. Rubayet Nabil
// Project: HOSPITAL MANAGEMENT SYSTEM

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class HospitalManager;
/*CLASS-01-ACCESS*/
class Access
{
    string pass73 = "073";
    string pass100 = "100";
    string pass50 = "050";
public:
    int check(string pass)
    {
        if (pass == pass73){
            return 73;
        }
        else if(pass == pass100){
            return 100;
        }
        else if (pass == pass50){
            return 50;
        }
        else return 0;
    }
};
/*CLASS-02-DOCTOR*/
class Doctor
{
    string name,speciality;
    int id,age;
    char gender;
public:
    Doctor(){}
    Doctor(string name,int age,char gender,string speciality,int id)
    {
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->speciality = speciality;
        this->id=id;
    }
    void display()
    {
        cout<<":::::::::::::::::::::::::::::::::::"<<endl;
        cout<<"Name         : "<<name<<endl;
        cout<<"Age          : "<<age<<endl;
        cout<<"Gender       : "<<gender<<endl;
        cout<<"Speciality   : "<<speciality<<endl;
        cout<<"ID No        : "<<id<<endl;
        cout<<":::::::::::::::::::::::::::::::::::"<<endl;
    }
    friend void assign_doctor(HospitalManager &obj,string khoj);
};
/*CLASS-03-PATIENT*/
class Patient
{
    string name,problem;
    int age,bedno,contact;
    char gender;
public:
    Patient(){}
    Patient(string name,int age,char gender,string problem,int contact,int bedno)
    {
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->problem = problem;
        this->contact = contact;
        this->bedno = bedno;
    }
    void display()
    {
        cout<<":::::::::::::::::::::::::::::::::::"<<endl;
        cout<<"Name         : "<<name<<endl;
        cout<<"Age          : "<<age<<endl;
        cout<<"Gender       : "<<gender<<endl;
        cout<<"Problem      : "<<problem<<endl;
        cout<<"Contact No   : "<<contact<<endl;
        cout<<"Bed No       : "<<bedno<<endl;
        cout<<":::::::::::::::::::::::::::::::::::"<<endl;

    }
    friend void search_patient(HospitalManager &obj,string khoj);
    friend void search_patient(HospitalManager &obj,int srch_contact);
};
/*GLOBAL VARIABLE*/
int doctorID = 100;
int patientbedno = 100;
/*CLASS-04-HOSPITAL MANAGER*/
class HospitalManager
{
    vector <Doctor> darr;
    vector <Patient> parr;
    int totald,totalp;
public:
    HospitalManager()
    {
        totald = 0;
        totalp = 0;
    }
    void add_new_doctor(string name,int age,char gender,string speciality)
    {
        Doctor tmp;
        tmp = Doctor(name,age,gender,speciality,++doctorID);
        darr.push_back(tmp);
        totald++;
        cout <<"Doctor Added !"<<endl;
    }
    void add_new_patient(string name,int age,char gender,string problem,int contact)
    {
        Patient tmp;
        tmp = Patient(name,age,gender,problem,contact,++patientbedno);
        parr.push_back(tmp);
        totalp++;
        cout <<"Patient Added !"<<endl;
    }
    void display_all_doctor()
    {
        if(totald){
            cout<<"Total doctor("<<totald<<")"<<endl;
            for(int i = 0 ; i < totald ; i++){
                darr[i].display();
                cout << endl;
            }
        }
        else
        {
            cout << "There is no Doctor yet"<<endl;
        }
    }
    void display_all_patient()
    {
        if(totalp){
            cout<<"Total patient("<<totalp<<")"<<endl;
            for(int i = 0 ; i < totalp ; i++){
                parr[i].display();
                cout << endl;
        }
        }
        else
        {
            cout << "There is no patient yet"<<endl;
        }
    }
    int return_total_patient(){
        return totalp;
    }
    int return_total_dotcor(){
        return totald;
    }
    friend void assign_doctor(HospitalManager &obj,string khoj);
    friend void search_patient(HospitalManager &obj,string khoj);
    friend void search_patient(HospitalManager &obj,int srch_contact);
};
/*SEARCH FUNCTION TO SEARCH SUBSTRING*/
int string_in_string(string s1, string s2)
{
    int M = s1.size();
    int N = s2.size();
    for (int i = 0; i <= N - M; i++)
    {
        int j;
        for (j = 0; j < M; j++)
        {
            if (s2[i + j] != s1[j])
            {
                break;
            }
        }
        if (j == M)
            return i;
    }
    return -1;
}

void assign_doctor(HospitalManager &obj,string khoj)
{
    int flag=-5;
    system("cls");
    for (int i = 0; i < obj.totald; i++)
    {
        flag = string_in_string(khoj,obj.darr[i].speciality);
        if (flag!=-1)
        {
            cout<<"You can consult with him/her :-"<<endl;
            obj.darr[i].display();
            break;
        }
        else
        {
            flag=-5;
        }
    }
    if (flag==-5)
    {
        cout<<"No doctor found for this problem"<<endl;
    }
}


void search_patient(HospitalManager &obj,string khoj)
{
    system("cls");
    int flag=-5;
    for (int i = 0; i < obj.totalp; i++)
    {
        flag = string_in_string(khoj,obj.parr[i].name);
        if (flag!=-1)
        {
            cout<<"This is what i've found :-"<<endl;
            obj.parr[i].display();
        }
        else
        {
            flag=-5;
        }
    }
    if (flag==-5)
    {
        cout<<"No patient found with this name"<<endl;
    }
}

void search_patient(HospitalManager &obj,int srch_contact)
{
    system("cls");
    int flag=-5;
    for (int i = 0; i < obj.totalp; i++)
    {
        if (obj.parr[i].contact==srch_contact)
        {
            cout<<"This is what i've found :-"<<endl;
            obj.parr[i].display();
            flag = 1;
        }
    }
    if (flag==-5)
    {
        cout<<"No patient found with this id"<<endl;
    }
}

int main()
{
    int choice;
    HospitalManager obj1;
    int manager;
    /*LOOP FOR PASSWORD CHECK*/
    do
    {
        start:
        system("cls");
        cout<<"Enter Password(050,073,100): ";
        string entered_pass;
        cin>>entered_pass;
        Access password;
        if(password.check(entered_pass)){
            if (password.check(entered_pass)==73)
            {
                cout<<"Welcome Nabil73"<<endl;
            }
            else if (password.check(entered_pass)==100)
            {
                cout<<"Welcome Soykot100"<<endl;
            }
            else if (password.check(entered_pass)==50)
            {
                cout<<"Welcome Nayeem50"<<endl;
            }
            system("pause");
            goto mainmenu;
        }
        else
        {
            cout<<"You haved entered a wrong password"<<endl;
            cout<<"Please try again:- "<<endl;
            getchar();
            system("pause");
            goto start;
        }
    } while (1);
    /*MAIN PROGRAM LOOP*/
    do
    {
        mainmenu:
        system("cls");
        cout <<"///////////////////////////////////////"<<endl;
        cout <<":::::::::::::  Main Menu  :::::::::::::"<<endl;
        cout <<"///////////////////////////////////////"<<endl;
        cout <<"Welcome to Hospital Management System"<<endl;
        cout <<"Choose any of the options below :-"<<endl;
        cout<< "1. Add a new doctor."<<endl;
        cout<< "2. Add a new patient."<<endl;
        cout <<"3. Display all doctor information."<< endl;
        cout <<"4. Display all patient information."<< endl;
        cout <<"5. Search doctor with speciality."<< endl;
        cout <<"6. Search patient."<< endl;
        cout <<"0. Exit!"<<endl;
        cout <<"Enter your choice : ";
        cin>>choice;
        string na,spe,prob,khoj;
        switch (choice)
        {
        case 1:
            int age_doc;
            char gender_doc;
            getchar();
            cout<<"Enter Doctor name: ";
            getline(cin,na);
            cout<<"Enter age: ";
            cin>>age_doc;
            getchar();
            cout<<"Enter gender(M/F): ";
            cin>>gender_doc;
            getchar();
            cout<<"Enter specialiy: ";
            getline(cin,spe);
            obj1.add_new_doctor(na,age_doc,gender_doc,spe);
            system("pause");
            break;
        case 2:
            int age_ptnt,contact_ptnt;
            char gender_ptnt;
            getchar();
            cout<<"Enter Patient name: ";
            getline(cin,na);
            cout<<"Enter age: ";
            cin>>age_ptnt;
            getchar();
            cout<<"Enter gender(M/F): ";
            cin>>gender_ptnt;
            getchar();
            cout<<"Enter Problem: ";
            getline(cin,prob);
            cout<<"Contact Number: ";
            cin>>contact_ptnt;
            obj1.add_new_patient(na,age_ptnt,gender_ptnt,prob,contact_ptnt);
            system("pause");
            break;
        case 3:
            system("cls");
            obj1.display_all_doctor();
            system("pause");
            break;
        case 4:
            system("cls");
            obj1.display_all_patient();
            system("pause");
            break;
        case 5:
            cout << "Enter speciality: ";
            cin >> khoj;
            assign_doctor(obj1,khoj);
            system("pause");
            break;
        case 6:
            system("cls");
            cout << "1. Search with name: "<<endl;
            cout << "2. Search with contact: "<<endl;
            cout <<"Enter your choice : ";
            cin>>choice;
            if (choice==1)
            {
                cout << "Enter patient name: ";
                cin >> khoj;
                search_patient(obj1,khoj);
                system("pause");
                break;
            }
            else if (choice==2)
            {
                int srch_contact;
                cout << "Enter contact number: ";
                cin>>srch_contact;
                search_patient(obj1,srch_contact);
                system("pause");
                break;
            }
            else break;
        case 0:
            system("cls");
            cout<<"Thank you for using H.M.S"<<endl;
            exit(0);
        default:
            break;
        }
    } while (1);

    return 0;
}
