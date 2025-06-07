#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

/*I have created a software App for vaccine reservation centre. This App used provide a reservation for vaccination to the customer.
used by the file handling
admin can record the customer counts and read the all customer details at a time.
I have used multiple inheritance and
function overloading polymorphism method*/

class Vaccination_centre //super class 1
{
protected:
    int token_no,counts;
    string time,date,admin_password;

public:
    string name,address,NIC,sex,District,MOH_area,Grama_Niladari_area,P_number;
    int age,verification_age,password,num;
    long int contact_number;

    void details_of_centre();
    void details_of_centre(int counts);
    void details_of_centre(string);

    void names_of_centre();
    void read_user_detail();

    int setAdmin_password()
    {
        cout<<"Admin Password: ";cin>>admin_password;
        if(admin_password=="abc123")
        {
            return 1;
        }
        return -1;
    }

    void setVaccination_card()
      {
       cout<<"\nEnter the Available Token No: \n";
       cin>>token_no;
       cout<<"Enter the Available Time: \n";
       cin>>time;
       cout<<"Enter the Available Date: \n";
       cin>>date;
       }

    void showVaccination_card()
    {
       cout<<"-----------------------------------------------------------------\n";
       cout<<"\t\tVaccination Appointment Card\n";
       cout<<"Token No: "<<token_no<<endl;
       cout<<"Time: "<<time<<endl;
       cout<<"Date: "<<date<<endl;
       cout<<"\n^^Please Wear a Mask and be on time to the Vaccination centre^^\n";
       cout<<"------------------------------------------------------------------\n";
    }

    void choose_options()
    {
        cout<<"\n\nPress 1 for view the Available Vaccination Centres\n";
        cout<<"Press 2 for Register to the App\n";
        cout<<"Press 3 for Register to the Vaccination\n";
        cout<<"Press 4 for Admin user (Unauthorized access denied)\n";
        cout<<"Press 5 for View All customer details (Unauthorized access denied)\n";
        cout<<"Press 0 for Exit from the App\n";
    }

};

void Vaccination_centre::details_of_centre()
{
    cout<<"====================================================================================================\n";
    cout<<"\t\t\t\t***WELCOME TO COVID VACCINATION CENTRE APP***\n";
    cout<<"\t\tWe are the leading Online registering vaccination App in Sri lanka\n";
    cout<<"\t\tNo fees required\n";
    cout<<"\t\tPlease fill your details and consult from the doctors\n";
    cout<<"\t\tWe will provide the token number and the Online vaccination card to you\n";
    cout<<"\t\t\t\t\t~~~Thanks for choosing us~~~\n";
    cout<<"\t\t\t\t\t***(C)DCSD201P-010-Prakash***\n";
    cout<<"====================================================================================================\n";
}

void Vaccination_centre::details_of_centre(string P_number)
{
    cout<<"\t\t\t\t\t   Contact us: "<<P_number;
}

void Vaccination_centre::details_of_centre(int counts)
{
    this->counts=counts;
    cout<<"Enter the record of the eligible customer count: \n";cin>>counts;
    counts=counts+counts;
    cout<<"Total counts: "<<counts;
}

void Vaccination_centre::names_of_centre()
{
    cout<<"====================================================================================================\n\n";
    cout<<" Number\t\tVaccine\t\t\tVaccine\t\t\t\tAvailable\tAvailable\n";
    cout<<"Of Centre\tName\t\t\tLocation\t\t\tQuantity\tDate\n\n";
    cout<<"  1\t\tSinopharm\t\tWiharamaha devi park\t\t20000\t\t10 Sept 2021\n";
    cout<<"  2\t\tPfizer-BioNTech\t\tArmy Hospital Nawala\t\t2000\t\t30 Sept 2021\n";
    cout<<"  3\t\tModerna\t\t\tGeneral Hospital Colombo\t10000\t\t02 Oct 2021\n";
    cout<<"  4\t\tCoronaVac\t\tAsiri Hospital\t\t\t3000\t\t15 Oct 2021\n";
    cout<<"  5\t\tSputnik V\t\tPredeshiya Sabava Colombo\t8000\t\t02 Nov 2021\n";
    cout<<"====================================================================================================\n";
}

class Doctor //super class 2
{
 public:
     int method;
     string diagnose;
     void Doctor_names()
     {
       {
         cout<<"Doctor please Enter the Vaccination centre Number customer entered: \n";
         cin>>method;

         switch(method)
         {
         case 1:
            cout<<"\nHi I am DR KEERTHI ABAYAJEEWA"<<endl;
            break;
         case 2:
            cout<<"\nHi I am DR ASHAN ABEYEWARDENE"<<endl;
            break;
         case 3:
            cout<<"\nHi I am MS WARUNI BANDARA"<<endl;
            break;
         case 4:
            cout<<"\nHi I am DR CHAMEERA BANDARA"<<endl;
            break;
         case 5:
            cout<<"\nHi I am DR MEENA RADHAKRISHNAN"<<endl;
            break;
         default:
            break;
         }
     }
     }
     void doctor_check();
};

void Doctor::doctor_check()
{
  cout<<"Do you have any alergic or heart disease or other disease (Yes/No) ?";
}

class eligiblity_person:public Vaccination_centre,public Doctor //two super classes are inherited by one sub class
{
public:

    void user_name()
    {
        cout<<"Enter Username: ";cin>>name;
        cout<<"Enter Password: ";cin>>password;
        cout<<"\nAccount registered successfully\n";
    }
    void insertUserDetails()
    {
       {
       fstream a;
       a.open("User_detail.txt",ios::app); //file operation - file open process
       cout<<"Enter your name : ";cin>>name;
       cout<<"Enter National Identity Card Number : ";cin>>NIC;
       cout<<"Enter Sex : ";cin>>sex;
       cout<<"Enter Address : ";cin>>address;
       cout<<"Enter Contact Number : ";cin>>contact_number;
       cout<<"Enter District :";cin>>District;
       cout<<"Enter MOH Area : ";cin>>MOH_area;
       cout<<"\nConsult a doctor to checkup your health\n";
       cout<<"Enter Your Selected Vaccination centre Number: \n";cin>>num;

       a<<setw(10)<<name<<endl;
       a<<setw(13)<<NIC<<endl;
       a<<setw(10)<<sex<<endl;
       a<<setw(10)<<age<<endl;
       a<<setw(10)<<address<<endl;
       a<<setw(10)<<contact_number<<endl;
       a<<setw(10)<<District<<endl;
       a<<setw(10)<<MOH_area<<endl;
       a.close();
}

}
    void checkup(){
    cout<<"\nYour Answer: ";cin>>diagnose;}
};

void Vaccination_centre::read_user_detail() //file operation - for read the file
    {
        fstream b;
        b.open("User_detail.txt",ios::in);
        while(b)
        {
            b>>name>>NIC>>sex>>age>>address>>contact_number>>District>>MOH_area;
            if(b.eof())
            {
                break;
            }
            cout<<name<<"\t"<<NIC<<"\t"<<sex<<"\t"<<age<<"\t"<<address<<"\t"<<contact_number
            <<"\t"<<District<<"\t"<<MOH_area<<endl;
        }
    }

int main()
{
    Vaccination_centre V; //object
    Doctor D;             //object
    eligiblity_person E;  //object
    int counts;
    V.details_of_centre();
    V.details_of_centre("0115678324");
    int option=-1;
    V.choose_options();
    while(option!=0)
    {
       cout<<"\n\n-------Press : ";
       cin>>option;
       if(option==1)
        {
            V.names_of_centre();
        }
       else if(option==2)
        {
            E.user_name();
        }


        else if(option==3)
        {
       int age; cout<<"Enter your age for verification : ";
       cin>>age;
       if (age<=18)
       {
           cout<<"\n!!!You are not eligible to vaccination!!!\n";
       }
       else
       {
       E.insertUserDetails();
       D.Doctor_names();
       D.doctor_check();
       E.checkup();
       string diagnose;
       cout<<"\nCustomer Health result: ";
       cin>>diagnose;
       if(diagnose=="Good")
       {
         cout<<"\n***This person eligible to get the vaccine***\n";
         V.setVaccination_card();
         V.showVaccination_card();
       }
       else
        {
          cout<<"\nYou are not eligible to get the vaccine. Please check your illness";
        }
       }

       }
    else if(option==0)
    {
        break;
    }
    else if(option==4)
    {
        if (V.setAdmin_password()==1)
        {
            V.details_of_centre(counts); //admin user to record the customer counts
        }
        else
        {
            cout<<"Incorrect password!";
        }

    }
    else if(option==5)
    {
        if (V.setAdmin_password()==1)
        {
            V.read_user_detail(); //Admin user to read the customer details
        }
        else
        {
            cout<<"Incorrect password!";
        }
    }
    else
        {
            cout<<"\nYour input is invalid!. Check the option and Try again\n\n";
        }
    }

    return 0;
}
