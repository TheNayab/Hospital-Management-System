#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

struct doctor
{
  string doctor_id;
  string password;
  string doctor_name;
  string doctor_address;
  long long doctor_mobile_no;
  int doctor_age;
  string doctor_qualification;
  string doctor_specialization;
  int doctor_experience;
  string doctor_city;
  string doctor_slot;
  string doctor_slot1;
  string doctor_slot2;
  doctor *ptr;
};

class Doctor
{
  struct doctor *start;
  struct doctor *current;
  struct doctor *next;

public:
  Doctor()
  {
    start = NULL;
    current = NULL;
    next = NULL;
  }

  void create()
  {
    if (start == NULL)
    {
      start = new doctor;
      string doctor_id;
      string password;
      string doctor_name;
      string doctor_address;
      long long doctor_mobile_no;
      int doctor_age;
      string doctor_qualification;
      string doctor_specialization;
      int doctor_experience;
      string doctor_city;
      string doctor_slot;
      string doctor_slot1;
      string doctor_slot2;
      string id;
    L1:
    iid:
    v:
      int countid = 0;
      cout << "ENTER DOCTOR ID : ";
      getline(cin, doctor_id);

      for (int i = 0; i < doctor_id.length(); i++)
      {
        if (!isdigit(doctor_id[i]))
        {
          countid++;
        }
      }
      if (doctor_id == "0" || doctor_id == "00" || doctor_id == "000")
      {
        cout << "\nEnter greater than 0\n";
        goto v;
      }
      if (countid != 0)
      {
        cout << "\n\t\t\t PLEASE ENTER THE RIGHT ID : \n";
        goto iid;
      }
      ifstream in;
      in.open("doctor_detail.txt", ios::in);
      while (in >> id)
      {

        if (id == doctor_id)
        {
          cout << "THIS ID IS ALREADY ASSIGNED PLEASE TRY OTHER ONE : \n";
          goto L1;
        }
      }
      in.close();
    N:
      int count = 0;
      cout << "ENTER DOCTOR NAME : ";
      getline(cin, doctor_name);

      for (int i = 0; i < doctor_name.length(); i++)
      {
        if (isdigit(doctor_name[i]))
        {
          count++;
        }
      }
      if (count != 0)
      {
        cout << "\n\t\t\t PLEASE ENTER THE RIGHT NAME : \n";
        goto N;
      }
      cout << "ENTER PASSWORD THAT YOU WANT TO ASSIGN THE DOCTOR : ";
      getline(cin, password);

      ofstream out1;
      out1.open("doctoruserids.txt", ios::app | ios::out);

      out1 << "\t\t*************************************************************\n";
      out1 << "\t\t                        DOCTOR ACCOUNT                      \n";
      out1 << "\t\t*************************************************************\n";
      out1 << "ID :\t" << doctor_id << "\n"
           << "PASSWORD :\t" << password << "\n";
      out1.close();

      cout << "ENTER DOCTOR ADDRESS : ";
      getline(cin, doctor_address);
    ph:
    mob:
      cout << "ENTER DOCTOR MOBILE NUMBER : ";
      while (!(cin >> doctor_mobile_no))
      {
        cin.clear();
        cin.ignore(123, '\n');
        cout << "\n\t\t\tENTER THE VALID MOBILE NUMBER ... \n";
        goto ph;
      }
      if (doctor_mobile_no < 10000000000)
      {
        cout << "\n\t\t\tPLEASE ENTER THE RIGHT MOBILE NUMBER ...\n";
        goto mob;
      }
      cin.ignore();
    e:
    aged:
      cout << "ENTER DOCTOR AGE : ";
      while (!(cin >> doctor_age))
      {
        cin.clear();
        cin.ignore(123, '\n');
        cout << "\n\t\t\tENTER THE VALID AGE ... \n";
        goto e;
      }
      if (doctor_age <= 0 || doctor_age > 140)
      {
        cout << "\n\t\t\tPLEASE ENTER THE RIGHT AGE ...\n";
        goto aged;
      }
      cin.ignore();

    qua:
      int counta = 0;
      cout << "ENTER DOCTOR QUALIFICATION : ";
      getline(cin, doctor_qualification);
      for (int i = 0; i < doctor_qualification.length(); i++)
      {
        if (isdigit(doctor_qualification[i]))
        {
          counta++;
        }
      }
      if (counta != 0)
      {
        cout << "\n\t\t\t PLEASE ENTER THE RIGHT QUALIFICATION : \n";
        goto qua;
      }
    spe:
      int countaq = 0;
      cout << "ENTER DOCTOR SPECIALIZATION : ";
      getline(cin, doctor_specialization);
      for (int i = 0; i < doctor_specialization.length(); i++)
      {
        if (isdigit(doctor_specialization[i]))
        {
          countaq++;
        }
      }
      if (countaq != 0)
      {
        cout << "\n\t\t\t PLEASE ENTER THE RIGHT SPECIFICATION : \n";
        goto spe;
      }

    ecp:
    exp:
      cout << "ENTER DOCTOR EXPERIENCE YEARS : ";
      while (!(cin >> doctor_experience))
      {
        cin.clear();
        cin.ignore(123, '\n');
        cout << "\n\t\t\tENTER THE VALID EXPERIENCE YEARS ... \n";
        goto exp;
      }
      if (doctor_experience > 35)
      {
        cout << "\n\t\t\tPLEASE ENTER THE RIGHT MOBILE NUMBER ...\n";
        goto ecp;
      }
      cin.ignore();

    ci:
      int countc = 0;
      cout << "ENTER DOCTOR CITY : ";
      getline(cin, doctor_city);
      for (int i = 0; i < doctor_city.length(); i++)
      {
        if (isdigit(doctor_city[i]))
        {
          countc++;
        }
      }
      if (countc != 0)
      {
        cout << "\n\t\t\t PLEASE ENTER THE RIGHT CITY : \n";
        goto ci;
      }
      cout << "ENTER DOCTOR AVAILABILITY SLOT 1 : ";
      getline(cin, doctor_slot);
      cout << "ENTER DOCTOR AVAILABILITY SLOTS 2: ";
      getline(cin, doctor_slot1);
      cout << "ENTER DOCTOR AVAILABILITY SLOTS 3: ";
      getline(cin, doctor_slot2);
      ofstream out2;
      out2.open("Doctorsname.txt", ios::app | ios::out);
      out2 << "\t\t\t*************************************************************\n";
      out2 << "\t\t\t                         DOCTOR                           \n";
      out2 << "\t\t\t*************************************************************\n";
      out2 << "ID :\t" << doctor_id << "\n"
           << "NAME :\t" << doctor_name << "\n"
           << "SPECIALIZATION :\t" << doctor_specialization << "\n"
           << "SLOT - 1 :\t" << doctor_slot << "\n"
           << "SLOT - 2 :\t" << doctor_slot1 << "\n"
           << "SLOT - 3 :\t" << doctor_slot2 << "\n";

      out2.close();
      start->doctor_id = doctor_id;
      start->password = password;
      start->doctor_name = doctor_name;
      start->doctor_address = doctor_address;
      start->doctor_mobile_no = doctor_mobile_no;
      start->doctor_age = doctor_age;
      start->doctor_qualification = doctor_qualification;
      start->doctor_specialization = doctor_specialization;
      start->doctor_experience = doctor_experience;
      start->doctor_city = doctor_city;
      start->doctor_slot = doctor_slot;
      start->doctor_slot1 = doctor_slot1;
      start->doctor_slot2 = doctor_slot2;

      start->ptr = NULL;
      current = start;
      ofstream out;
      out.open("doctor_detail.txt", ios::app | ios::out);
      out << "\t\t\t\t\t\t\t**********************************************************************************\n";
      out << "\t\t\t\t\t\t\t*                                                                                *\n";
      out << "\t\t\t\t\t\t\t*                               DOCTORS  DETAIL                                 *\n";
      out << "\t\t\t\t\t\t\t*                                                                                *\n";
      out << "\t\t\t\t\t\t\t**********************************************************************************\n";
      out << "ID :\t" << doctor_id << "\n"
          << "PASSWORD :\t" << password << "\n"
          << "NAME :\t" << doctor_name << "\n"
          << "ADDRESS :\t" << doctor_address << "\n"
          << "MOBILE NUMBER :\t" << doctor_mobile_no << "\n"
          << "AGE :\t" << doctor_age << "\n"
          << "QUALIFICATION :\t" << doctor_qualification << "\n"
          << "SPECIALIZATION :\t" << doctor_specialization << "\n"
          << "EXPERIENCE :\t" << doctor_experience << "\n"
          << "CITY :\t" << doctor_city << "\n"
          << "SLOT-1 :\t" << doctor_slot << "\n"
          << "SLOT-2 :\t" << doctor_slot1 << "\n"
          << "SLOT-3 :\t" << doctor_slot2 << "\n";

      out.close();
    }

    else
    {
      next = new doctor;
      string doctor_id;
      string password;
      string doctor_name;
      string doctor_address;
      long long doctor_mobile_no;
      int doctor_age;
      string doctor_qualification;
      string doctor_specialization;
      int doctor_experience;
      string doctor_city;
      string doctor_slot;
      string doctor_slot1;
      string doctor_slot2;
      string id;
      int counta = 0;
    L2:
    a:
    vm:
      int countid2 = 0;
      cout << "ENTER DOCTOR ID : ";
      getline(cin, doctor_id);

      for (int i = 0; i < doctor_id.length(); i++)
      {
        if (!isdigit(doctor_id[i]))
        {
          countid2++;
        }
      }
      if (doctor_id == "0" || doctor_id == "00" || doctor_id == "000")
      {
        cout << "\nEnter greater than 0\n";
        goto vm;
      }
      if (countid2 != 0)
      {
        cout << "\n\t\t\t PLEASE ENTER THE RIGHT NAME............... \n";
        goto a;
      }
      ifstream in;
      in.open("doctor_detail.txt", ios::in);
      while (in >> id)
      {

        if (id == doctor_id)
        {
          cout << "\n\t\t\t\tTHIS ID IS ALREADY ASSIGNED PLEASE TRY OTHER ONE : \n";
          goto L2;
        }
      }
      in.close();
    M:

      int count = 0;
      cout << "ENTER DOCTOR NAME : ";
      getline(cin, doctor_name);

      for (int i = 0; i < doctor_name.length(); i++)
      {
        if (isdigit(doctor_name[i]))
        {
          count++;
        }
      }
      if (count != 0)
      {
        cout << "\n\t\t\t PLEASE ENTER THE RIGHT NAME : \n";
        goto M;
      }
      cout << "ENTER PASSWORD THAT YOU WANT TO ASSIGN THE DOCTOR : ";
      getline(cin, password);
      ofstream out1;
      out1.open("doctoruserids.txt", ios::app | ios::out);

      out1 << "\t\t*************************************************************\n";
      out1 << "\t\t                        DOCTOR ACCOUNT                      \n";
      out1 << "\t\t*************************************************************\n";
      out1 << "ID :\t" << doctor_id << "\n"
           << "PASSWORD :\t" << password << "\n";
      out1.close();
      cout << "ENTER DOCTOR ADDRESS : ";
      getline(cin, doctor_address);
    e1:
    mob1:
      cout << "ENTER DOCTOR MOBILE NUMBER : ";
      while (!(cin >> doctor_mobile_no))
      {
        cin.clear();
        cin.ignore(123, '\n');
        cout << "\n\t\t\tENTER THE VALID MOBILE NUMBER ... \n";
        goto e1;
      }
      if (doctor_mobile_no < 10000000000)
      {
        cout << "\n\t\t\tPLEASE ENTER THE RIGHT MOBILE NUMBER ...\n";
        goto mob1;
      }
      cin.ignore();
    f:
    agede:
      cout << "ENTER DOCTOR AGE : ";
      while (!(cin >> doctor_age))
      {
        cin.clear();
        cin.ignore(123, '\n');
        cout << "\n\t\t\tENTER THE VALID AGE ... \n";
        goto f;
      }
      if (doctor_age <= 0 || doctor_age > 140)
      {
        cout << "\t\t\tPLEASE ENTER THE RIGHT AGE ...\nF";
        goto agede;
      }
      cin.ignore();
    qual:
      int countaa = 0;
      cout << "ENTER DOCTOR QUALIFICATION : ";
      getline(cin, doctor_qualification);
      for (int i = 0; i < doctor_qualification.length(); i++)
      {
        if (isdigit(doctor_qualification[i]))
        {
          countaa++;
        }
      }
      if (countaa != 0)
      {
        cout << "\n\t\t\t PLEASE ENTER THE RIGHT QUALIFICATION : \n";
        goto qual;
      }
    spec:
      int countaq = 0;
      cout << "ENTER DOCTOR SPECIALIZATION : ";
      getline(cin, doctor_specialization);
      for (int i = 0; i < doctor_specialization.length(); i++)
      {
        if (isdigit(doctor_specialization[i]))
        {
          countaq++;
        }
      }
      if (countaq != 0)
      {
        cout << "\t\t\t PLEASE ENTER THE RIGHT SPECIFICATION : \n";
        goto spec;
      }
    ecp1:
    exp1:
      cout << "ENTER DOCTOR EXPERIENCE YEARS : ";
      while (!(cin >> doctor_experience))
      {
        cin.clear();
        cin.ignore(123, '\n');
        cout << "\n\t\t\tENTER THE VALID EXPERIENCE YEARS ... \n";
        goto exp1;
      }
      if (doctor_experience > 35)
      {
        cout << "\n\t\t\tPLEASE ENTER THE RIGHT MOBILE NUMBER ...\n";
        goto ecp1;
      }
      cin.ignore();

    cii:
      int countc = 0;
      cout << "ENTER DOCTOR CITY : ";
      getline(cin, doctor_city);
      for (int i = 0; i < doctor_city.length(); i++)
      {
        if (isdigit(doctor_city[i]))
        {
          countc++;
        }
      }
      if (countc != 0)
      {
        cout << "\n\t\t\t PLEASE ENTER THE RIGHT CITY : \n";
        goto cii;
      }
      cout << "ENTER DOCTOR SLOT-1 : ";
      getline(cin, doctor_slot);
      cout << "ENTER DOCTOR SLOT-2 : ";
      getline(cin, doctor_slot1);
      cout << "ENTER DOCTOR SLOT-3 : ";
      getline(cin, doctor_slot2);
      ofstream out2;
      out2.open("Doctorsname.txt", ios::app | ios::out);
      out2 << "\t\t\t*************************************************************\n";
      out2 << "\t\t\t                         DOCTOR                           \n";
      out2 << "\t\t\t*************************************************************\n";
      out2 << "ID :\t" << doctor_id << "\n"
           << "NAME :\t" << doctor_name << "\n"
           << "SPECIALIZATION :\t" << doctor_specialization << "\n"
           << "SLOT - 1 :\t" << doctor_slot << "\n"
           << "SLOT - 2 :\t" << doctor_slot1 << "\n"
           << "SLOT - 3 :\t" << doctor_slot2 << "\n";

      out2.close();
      next->doctor_id = doctor_id;
      next->password = password;
      next->doctor_name = doctor_name;
      next->doctor_address = doctor_address;
      next->doctor_mobile_no = doctor_mobile_no;
      next->doctor_age = doctor_age;
      next->doctor_qualification = doctor_qualification;
      next->doctor_specialization = doctor_specialization;
      next->doctor_experience = doctor_experience;
      next->doctor_city = doctor_city;
      next->doctor_slot = doctor_slot;
      next->doctor_slot1 = doctor_slot1;
      next->doctor_slot2 = doctor_slot2;
      next->ptr = NULL;
      current->ptr = next;
      current = next;
      ofstream out;
      out.open("doctor_detail.txt", ios::app | ios::out);
      out << "\t\t\t\t\t\t\t**********************************************************************************\n";
      out << "\t\t\t\t\t\t\t*                                                                                *\n";
      out << "\t\t\t\t\t\t\t*                               DOCTORS  DETAIL                                 *\n";
      out << "\t\t\t\t\t\t\t*                                                                                *\n";
      out << "\t\t\t\t\t\t\t**********************************************************************************\n";
      out << "ID :\t" << doctor_id << "\n"
          << "PASSWORD :\t" << password << "\n"
          << "NAME :\t" << doctor_name << "\n"
          << "ADDRESS :\t" << doctor_address << "\n"
          << "MOBILE NUMBER :\t" << doctor_mobile_no << "\n"
          << "AGE :\t" << doctor_age << "\n"
          << "QUALIFICATION :\t" << doctor_qualification << "\n"
          << "SPECIALIZATION :\t" << doctor_specialization << "\n"
          << "EXPERIENCE :\t" << doctor_experience << "\n"
          << "CITY :\t" << doctor_city << "\n"
          << "SLOT-1 :\t" << doctor_slot << "\n"
          << "SLOT-2 :\t" << doctor_slot1 << "\n"
          << "SLOT-3 :\t" << doctor_slot2 << "\n";
      out.close();
    }
  }

  void deletion()
  {
    if (start == NULL)
    {
      cout << "Linked list is under flow\n";
    }
    else if (start->ptr == NULL)
    {
      free(start);
    }
    else
    {
      start = start->ptr;
    }

    string id;
    string garbage;
    string garbage1;
    string garbage2;
    string garbage3;
    string garbage4;
    string doctor_id;
    string password;
    string doctor_name;
    string doctor_address;
    string doctor_mobile_no;
    string doctor_age;
    string doctor_qualification;
    string doctor_specialization;
    string doctor_experience;
    string doctor_city;
    string doctor_slot;
    string doctor_slot1;
    string doctor_slot2;
    string id2;
    string name;
    string specilization;
    string slot;
    string slot1;
    string slot2;
    string gar1;
    string gar2;
    string gar3;
    ifstream in;
    ofstream out;
    ifstream in2;
    ofstream out2;

    out.open("doctor_detail1.txt", ios::out | ios::app);
    in.open("doctor_detail.txt", ios::in);
    out2.open("Doctorsname1.txt", ios::out | ios::app);
    in2.open("Doctorsname.txt", ios::in);
    getline(in2, gar1);
    getline(in2, gar2);
    getline(in2, gar3);
    getline(in2, id2);
    getline(in2, name);
    getline(in2, specilization);
    getline(in2, slot);
    getline(in2, slot1);
    getline(in2, slot2);
    while (!in2.eof())
    {
      cout << gar1 << "\n"
           << gar2 << "\n"
           << gar3 << "\n"
           << id2 << "\n"
           << name << "\n"
           << specilization << "\n";

      getline(in2, gar1);
      getline(in2, gar2);
      getline(in2, gar3);
      getline(in2, id2);
      getline(in2, name);
      getline(in2, specilization);
      getline(in2, slot);
      getline(in2, slot1);
      getline(in2, slot2);
    }
    in2.close();

    cout << "\t\tENTER THE ID OF DOCTOR THAT YOU WANT TO DELETE : ";
    cin >> id;

    string gari;
    string gari2;
    string gari3;
    string gari4;
    string gari5;
    ifstream in101;
    ofstream out101;
    in101.open("doctoruserids.txt", ios::in);
    out101.open("doctoruserids1.txt", ios::app | ios::out);
    getline(in101, gari);
    getline(in101, gari2);
    getline(in101, gari3);
    getline(in101, gari4);
    getline(in101, gari5);
    while (!in101.eof())
    {
      if (gari4 == "ID :\t" + id)
      {
      }
      else
      {

        out101 << gari << "\n"
               << gari2 << "\n"
               << gari3 << "\n"
               << gari4 << "\n"
               << gari5 << "\n";
      }
      getline(in101, gari);
      getline(in101, gari2);
      getline(in101, gari3);
      getline(in101, gari4);
      getline(in101, gari5);
    }
    in101.close();
    out101.close();
    remove("doctoruserids.txt");
    rename("doctoruserids1.txt", "doctoruserids.txt");
    in2.open("Doctorsname.txt", ios::in);
    getline(in2, gar1);
    getline(in2, gar2);
    getline(in2, gar3);
    getline(in2, id2);
    getline(in2, name);
    getline(in2, specilization);
    getline(in2, slot);
    getline(in2, slot1);
    getline(in2, slot2);
    while (!in2.eof())
    {

      if (id2 == "ID :\t" + id)
      {
      }
      else
      {
        out2 << gar1 << "\n"
             << gar2 << "\n"
             << gar3 << "\n"
             << id2 << "\n"
             << name << "\n"
             << specilization << "\n"
             << slot << "\n"
             << slot1 << "\n"
             << slot2 << "\n";
      }
      getline(in2, gar1);
      getline(in2, gar2);
      getline(in2, gar3);
      getline(in2, id2);
      getline(in2, name);
      getline(in2, specilization);
      getline(in2, slot);
      getline(in2, slot1);
      getline(in2, slot2);
    }
    in2.close();
    out2.close();
    remove("Doctorsname.txt");
    rename("Doctorsname1.txt", "Doctorsname.txt");
    getline(in, garbage);
    getline(in, garbage1);
    getline(in, garbage2);
    getline(in, garbage3);
    getline(in, garbage4);
    getline(in, doctor_id);
    getline(in, password);
    getline(in, doctor_name);
    getline(in, doctor_address);
    getline(in, doctor_mobile_no);
    getline(in, doctor_age);
    getline(in, doctor_qualification);
    getline(in, doctor_specialization);
    getline(in, doctor_experience);
    getline(in, doctor_city);
    getline(in, doctor_slot);
    getline(in, doctor_slot1);
    getline(in, doctor_slot2);

    while (!in.eof())
    {

      if (doctor_id == "ID :\t" + id)
      {
        cout << "\n\n\n\t\t\t\t\tFOLLOWING PATEINT RECORD IS SUCCESSFULLY DELETED... \n\n\n\n";
        cout << garbage << "\n"
             << garbage1 << "\n"
             << garbage2 << "\n"
             << garbage3 << "\n"
             << garbage4 << "\n"
             << "\t\t\t" << doctor_id << "\n"
             << "\t\t\t" << password << "\n"
             << "\t\t\t" << doctor_name << "\n"
             << "\t\t\t" << doctor_address << "\n"
             << "\t\t\t" << doctor_mobile_no << "\n"
             << "\t\t\t" << doctor_age << "\n"
             << "\t\t\t" << doctor_qualification << "\n"
             << "\t\t\t" << doctor_specialization << "\n"
             << "\t\t\t" << doctor_experience << "\n"
             << "\t\t\t" << doctor_city << "\n"
             << "\t\t\t" << doctor_slot << "\n"
             << "\t\t\t" << doctor_slot1 << "\n"
             << "\t\t\t" << doctor_slot2 << "\n";
      }
      else
      {
        out << garbage << "\n"
            << garbage1 << "\n"
            << garbage2 << "\n"
            << garbage3 << "\n"
            << garbage4 << "\n"
            << doctor_id << "\n"
            << password << "\n"
            << doctor_name << "\n"
            << doctor_address << "\n"
            << doctor_mobile_no << "\n"
            << doctor_age << "\n"
            << doctor_qualification << "\n"
            << doctor_specialization << "\n"
            << doctor_experience << "\n"
            << doctor_city << "\n"
            << doctor_slot << "\n"
            << doctor_slot1 << "\n"
            << doctor_slot2 << "\n";
      }
      getline(in, garbage);
      getline(in, garbage1);
      getline(in, garbage2);
      getline(in, garbage3);
      getline(in, garbage4);
      getline(in, doctor_id);
      getline(in, password);
      getline(in, doctor_name);
      getline(in, doctor_address);
      getline(in, doctor_mobile_no);
      getline(in, doctor_age);
      getline(in, doctor_qualification);
      getline(in, doctor_specialization);
      getline(in, doctor_experience);
      getline(in, doctor_city);
      getline(in, doctor_slot);
      getline(in, doctor_slot1);
      getline(in, doctor_slot2);
    }
    in.close();
    out.close();
    remove("doctor_detail.txt");
    rename("doctor_detail1.txt", "doctor_detail.txt");
  }
  void update()
  {
    string id;
    string namee;
    string garbage;
    string garbage1;
    string garbage2;
    string garbage3;
    string garbage4;
    string doctor_id;
    string password;
    string doctor_name;
    string doctor_address;
    string doctor_mobile_no;
    string doctor_age;
    string doctor_qualification;
    string doctor_specialization;
    string doctor_experience;
    string doctor_city;
    string doctor_slot;
    string doctor_slot1;
    string doctor_slot2;
    string id2;
    string name;
    string specilization;
    string slot;
    string slot1;
    string slot2;
    string gar1;
    string gar2;
    string gar3;
    ifstream in;
    ofstream out;
    ifstream in2;
    ofstream out2;
  right:
    out.open("doctor_detail1.txt", ios::out | ios::app);
    in.open("doctor_detail.txt", ios::in);
    out2.open("Doctorsname1.txt", ios::out | ios::app);
    in2.open("Doctorsname.txt", ios::in);
    getline(in2, gar1);
    getline(in2, gar2);
    getline(in2, gar3);
    getline(in2, id2);
    getline(in2, name);
    getline(in2, specilization);
    getline(in2, slot);
    getline(in2, slot1);
    getline(in2, slot2);
    while (!in2.eof())
    {
      cout << gar1 << "\n"
           << gar2 << "\n"
           << gar3 << "\n"
           << id2 << "\n"
           << name << "\n"
           << specilization << "\n";

      getline(in2, gar1);
      getline(in2, gar2);
      getline(in2, gar3);
      getline(in2, id2);
      getline(in2, name);
      getline(in2, specilization);
      getline(in2, slot);
      getline(in2, slot1);
      getline(in2, slot2);
    }
    in2.close();

    cout << "\t\tENTER THE ID AND NAME OF THE DOCTOR THAT YOU WANT TO UPDATE : \n";
    cout << "\t\t\tENTER THE ID OF THE DOCTOR : ";
    getline(cin, id);
    cout << "\t\t\tENTER THE NAME OF THE DOCTOR : ";
    getline(cin, namee);
    ifstream in56;
    in56.open("Doctorsname.txt", ios::in);
    getline(in56, gar1);
    getline(in56, gar2);
    getline(in56, gar3);
    getline(in56, id2);
    getline(in56, name);
    getline(in56, specilization);
    getline(in56, slot);
    getline(in56, slot1);
    getline(in56, slot2);
    int countee = 0;
    while (!in56.eof())
    {

      if (id2 == "ID :\t" + id && name == "NAME :\t" + namee)
      {
        countee++;
      }

      getline(in56, gar1);
      getline(in56, gar2);
      getline(in56, gar3);
      getline(in56, id2);
      getline(in56, name);
      getline(in56, specilization);
      getline(in56, slot);
      getline(in56, slot1);
      getline(in56, slot2);
    }
    if (countee == 0)
    {
      system("cls");
      cout << "\t\t\tSORRY THIS RECORD IS NOT FOUND ...\n\t\tPLEASE ENTER THE RIGHT ONE\n";
      goto right;
    }
    in56.close();
    cout << "\t\t\tENTER THE UPDATED DETAIL OF DOCTOR ...\n";

    string neaddress;
    string nespec;
    string nemobile_no;
    string nequalification;
    string necity;
    string neslot;
    string neslot1;
    string neslot2;

    cout << "ENTER THE UPDATED ADDRESS OF THE DOCTOR :  ";
    getline(cin, neaddress);
  pmc3:
    int countmc = 0;
    cout << "ENTER THE UPDATED MOBILE NUMBER OF THE DOCTOR : ";
    getline(cin, nemobile_no);

    for (int i = 0; i < nemobile_no.length(); i++)
    {
      if (!isdigit(nemobile_no[i]))
      {
        countmc++;
      }
    }
    if (countmc != 0)
    {
      cout << "\t\t\t PLEASE ENTER THE RIGHT ADDRESS : \n";
      goto pmc3;
    }

  pmc31:
    int countmc1 = 0;
    cout << "ENTER THE UPDATED QUALIFICATION OF THE DOCTOR : ";
    getline(cin, nequalification);

    for (int i = 0; i < nequalification.length(); i++)
    {
      if (isdigit(nequalification[i]))
      {
        countmc1++;
      }
    }
    if (countmc1 != 0)
    {
      cout << "\t\t\t PLEASE ENTER THE RIGHT QUALIFICATION : \n";
      goto pmc31;
    }
  pmc32:
    int countmc2 = 0;
    cout << "ENTER THE UPDATED SPECILIZATION OF THE DOCTOR : ";
    getline(cin, nespec);

    for (int i = 0; i < nespec.length(); i++)
    {
      if (isdigit(nespec[i]))
      {
        countmc2++;
      }
    }
    if (countmc2 != 0)
    {
      cout << "\t\t\t PLEASE ENTER THE RIGHT SPECLIZATION OF THE DOCTOR : \n";
      goto pmc32;
    }
  pmc33:
    int countmc3 = 0;
    cout << "ENTER THE UPDATED CITY OF THE DOCTOR : ";
    getline(cin, necity);

    for (int i = 0; i < necity.length(); i++)
    {
      if (isdigit(necity[i]))
      {
        countmc3++;
      }
    }
    if (countmc3 != 0)
    {
      cout << "\t\t\t PLEASE ENTER THE RIGHT SPECLIZATION OF THE DOCTOR : \n";
      goto pmc33;
    }
    cout << "ENTER THE UPDATED SLOTS OF THE DOCTOR ";
    getline(cin, neslot);
    cout << "ENTER THE UPDATED SLOTS OF THE DOCTOR: ";
    getline(cin, neslot1);
    cout << "ENTER THE UPDATED SLOTS OF THE DOCTOR ";
    getline(cin, neslot2);
    in2.open("Doctorsname.txt", ios::in);
    getline(in2, gar1);
    getline(in2, gar2);
    getline(in2, gar3);
    getline(in2, id2);
    getline(in2, name);
    getline(in2, specilization);
    getline(in2, slot);
    getline(in2, slot1);
    getline(in2, slot2);
    while (!in2.eof())
    {

      if (id2 == "ID :\t" + id && name == "NAME :\t" + namee)
      {

        out2 << gar1 << "\n"
             << gar2 << "\n"
             << gar3 << "\n"
             << id2 << "\n"
             << name << "\n"
             << "SPECIALIZATION :\t" << nespec << "\n"
             << "SLOT - 1 :\t" << neslot << "\n"
             << "SLOT - 2 :\t" << neslot1 << "\n"
             << "SLOT - 3 :\t" << neslot2 << "\n";
      }
      else
      {
        out2 << gar1 << "\n"
             << gar2 << "\n"
             << gar3 << "\n"
             << id2 << "\n"
             << name << "\n"
             << specilization << "\n"
             << slot << "\n"
             << slot1 << "\n"
             << slot2 << "\n";
      }
      getline(in2, gar1);
      getline(in2, gar2);
      getline(in2, gar3);
      getline(in2, id2);
      getline(in2, name);
      getline(in2, specilization);
      getline(in2, slot);
      getline(in2, slot1);
      getline(in2, slot2);
    }
    in2.close();
    out2.close();
    remove("Doctorsname.txt");
    rename("Doctorsname1.txt", "Doctorsname.txt");
    getline(in, garbage);
    getline(in, garbage1);
    getline(in, garbage2);
    getline(in, garbage3);
    getline(in, garbage4);
    getline(in, doctor_id);
    getline(in, password);
    getline(in, doctor_name);
    getline(in, doctor_address);
    getline(in, doctor_mobile_no);
    getline(in, doctor_age);
    getline(in, doctor_qualification);
    getline(in, doctor_specialization);
    getline(in, doctor_experience);
    getline(in, doctor_city);
    getline(in, doctor_slot);
    getline(in, doctor_slot1);
    getline(in, doctor_slot2);

    while (!in.eof())
    {

      if (doctor_id == "ID :\t" + id && doctor_name == "NAME :\t" + namee)
      {
        cout << "\n\n\n\t\t\t\t\tFOLLOWING PATEINT RECORD IS SUCCESSFULLY UPDATED... \n\n\n\n";

        out << garbage << "\n"
            << garbage1 << "\n"
            << garbage2 << "\n"
            << garbage3 << "\n"
            << garbage4 << "\n"
            << doctor_id << "\n"
            << password << "\n"
            << doctor_name << "\n"
            << "ADDRESS :\t" << neaddress << "\n"
            << "MOBILE NUMBER :\t" << nemobile_no << "\n"
            << doctor_age << "\n"
            << "QUALIFICATION :\t" << nequalification << "\n"
            << "SPECIALIZATION :\t" << nespec << "\n"
            << doctor_experience << "\n"
            << "CITY :\t" << necity << "\n"
            << "SLOT-1 :\t" << neslot << "\n"
            << "SLOT-2 :\t" << neslot1 << "\n"
            << "SLOT-3 :\t" << neslot2 << "\n";

        cout << garbage << "\n"
             << garbage1 << "\n"
             << garbage2 << "\n"
             << garbage3 << "\n"
             << garbage4 << "\n"
             << "\t\t\t" << doctor_id << "\n"
             << "\t\t\t" << password << "\n"
             << "\t\t\t" << doctor_name << "\n"
             << "\t\t\t" << doctor_address << "\n"
             << "\t\t\t" << doctor_mobile_no << "\n"
             << "\t\t\t" << doctor_age << "\n"
             << "\t\t\t" << doctor_qualification << "\n"
             << "\t\t\t" << doctor_specialization << "\n"
             << "\t\t\t" << doctor_experience << "\n"
             << "\t\t\t" << doctor_city << "\n"
             << "\t\t\t" << doctor_slot << "\n"
             << "\t\t\t" << doctor_slot1 << "\n"
             << "\t\t\t" << doctor_slot2 << "\n";
      }
      else
      {
        out << garbage << "\n"
            << garbage1 << "\n"
            << garbage2 << "\n"
            << garbage3 << "\n"
            << garbage4 << "\n"
            << doctor_id << "\n"
            << password << "\n"
            << doctor_name << "\n"
            << doctor_address << "\n"
            << doctor_mobile_no << "\n"
            << doctor_age << "\n"
            << doctor_qualification << "\n"
            << doctor_specialization << "\n"
            << doctor_experience << "\n"
            << doctor_city << "\n"
            << doctor_slot << "\n"
            << doctor_slot1 << "\n"
            << doctor_slot2 << "\n";
      }
      getline(in, garbage);
      getline(in, garbage1);
      getline(in, garbage2);
      getline(in, garbage3);
      getline(in, garbage4);
      getline(in, doctor_id);
      getline(in, password);
      getline(in, doctor_name);
      getline(in, doctor_address);
      getline(in, doctor_mobile_no);
      getline(in, doctor_age);
      getline(in, doctor_qualification);
      getline(in, doctor_specialization);
      getline(in, doctor_experience);
      getline(in, doctor_city);
      getline(in, doctor_slot);
      getline(in, doctor_slot1);
      getline(in, doctor_slot2);
    }
    in.close();
    out.close();
    remove("doctor_detail.txt");
    rename("doctor_detail1.txt", "doctor_detail.txt");
    // quite:
  }

  void search()
  {
    string id;
    string garbage;
    string garbage1;
    string garbage2;
    string garbage3;
    string garbage4;
    string doctor_id;
    string password;
    string doctor_name;
    string doctor_address;
    string doctor_mobile_no;
    string doctor_age;
    string doctor_qualification;
    string doctor_specialization;
    string doctor_experience;
    string doctor_city;
    string doctor_slot;
    string doctor_slot1;
    string doctor_slot2;
    string name;
    cout << "\t\tENTER THE ID OF DOCTOR THAT YOU WANT TO SEARCH : ";
    getline(cin, id);
    cout << "\t\tENTER THE NAME OF DOCTOR THAT YOU WANT TO SEARCH : ";
    getline(cin, name);

    ifstream in;
    in.open("doctor_detail.txt", ios::in);
    getline(in, garbage);
    getline(in, garbage1);
    getline(in, garbage2);
    getline(in, garbage3);
    getline(in, garbage4);
    getline(in, doctor_id);
    getline(in, password);
    getline(in, doctor_name);
    getline(in, doctor_address);
    getline(in, doctor_mobile_no);
    getline(in, doctor_age);
    getline(in, doctor_qualification);
    getline(in, doctor_specialization);
    getline(in, doctor_experience);
    getline(in, doctor_city);
    getline(in, doctor_slot);
    getline(in, doctor_slot1);
    getline(in, doctor_slot2);
    while (!in.eof())
    {

      if (doctor_id == "ID :\t" + id && doctor_name == "NAME :\t" + name)
      {
        system("cls");
        cout << garbage << "\n"
             << garbage1 << "\n"
             << garbage2 << "\n"
             << garbage3 << "\n"
             << garbage4 << "\n"
             << "\t\t\t" << doctor_id << "\n"
             << "\t\t\t" << password << "\n"
             << "\t\t\t" << doctor_name << "\n"
             << "\t\t\t" << doctor_address << "\n"
             << "\t\t\t" << doctor_mobile_no << "\n"
             << "\t\t\t" << doctor_age << "\n"
             << "\t\t\t" << doctor_qualification << "\n"
             << "\t\t\t" << doctor_specialization << "\n"
             << "\t\t\t" << doctor_experience << "\n"
             << "\t\t\t" << doctor_city << "\n"
             << "\t\t\t" << doctor_slot << "\n"
             << "\t\t\t" << doctor_slot1 << "\n"
             << "\t\t\t" << doctor_slot2 << "\n";
        goto exit;
      }
      else
      {
        system("cls");
        cout << "\n\n\n\n\t\t\t\t\t\tSORRY THIS doctor IS NOT EXIST ...!\n";
      }

      getline(in, garbage);
      getline(in, garbage1);
      getline(in, garbage2);
      getline(in, garbage3);
      getline(in, garbage4);
      getline(in, doctor_id);
      getline(in, password);
      getline(in, doctor_name);
      getline(in, doctor_address);
      getline(in, doctor_mobile_no);
      getline(in, doctor_age);
      getline(in, doctor_qualification);
      getline(in, doctor_specialization);
      getline(in, doctor_experience);
      getline(in, doctor_city);
      getline(in, doctor_slot);
      getline(in, doctor_slot1);
      getline(in, doctor_slot2);
    }
  exit:
    in.close();
  }
};

// ...................................................................................................BILL DETAIL
class Bill
{
public:
  void bill()
  {

    string garbage;
    string garbage1;
    string garbage2;
    string garbage3;
    string garbage4;
    string patient_id;
    string password;
    string patient_name;
    string patient_address;
    string patient_mobile_no;
    string patient_age;
    string patient_disease;
    string patient_room;
    string patient_condition;
    string patient_admit_date;
    string patient_room_charge;
    string patient_medicine_charge;
    string patient_bed;
    string id;
    string id1;
    cin.ignore();
  L1:
    cout << "\t\t\tENTER THE ID OF THE PATIENT : ";
    getline(cin, id);
    ifstream in1;
    in1.open("bill.txt", ios::in);
    while (in1 >> id1)
    {

      if (id1 == id)
      {
        cout << "BILL OF THIS PATIENT ALREADY CALCULATED... : \n";
        goto L1;
      }
    }
    in1.close();
    ifstream in;

    in.open("patient_detail.txt", ios::in);
    getline(in, garbage);
    getline(in, garbage1);
    getline(in, garbage2);
    getline(in, garbage3);
    getline(in, garbage4);
    getline(in, patient_id);
    getline(in, password);
    getline(in, patient_name);
    getline(in, patient_address);
    getline(in, patient_mobile_no);
    getline(in, patient_age);
    getline(in, patient_disease);
    getline(in, patient_room);
    getline(in, patient_condition);
    getline(in, patient_admit_date);
    getline(in, patient_room_charge);
    getline(in, patient_medicine_charge);
    getline(in, patient_bed);
    while (!in.eof())
    {

      if (patient_id == "ID :\t" + id)
      {

        ofstream out;

        out.open("bill.txt", ios::out | ios::app);
        out << "\t\t\t\t\t\t\t**********************************************************************************\n";
        out << "\t\t\t\t\t\t\t*                                                                                *\n";
        out << "\t\t\t\t\t\t\t*                               BILL  DETAIL                                     *\n";
        out << "\t\t\t\t\t\t\t*                                                                                *\n";
        out << "\t\t\t\t\t\t\t**********************************************************************************\n";
        out << "\t\t\t" << patient_id << "\n";
        out << "\t\t\t" << patient_name << "\n";
        out << "\t\t\t" << patient_room_charge << "\n";
        out << "\t\t\t" << patient_medicine_charge << "\n";
        out.close();
        out.open("patient_detail.txt", ios::out | ios::app);
        cout << "\t\t\t\t\t\t\t**********************************************************************************\n";
        cout << "\t\t\t\t\t\t\t*                                                                                *\n";
        cout << "\t\t\t\t\t\t\t*                               BILL  DETAIL                                     *\n";
        cout << "\t\t\t\t\t\t\t*                                                                                *\n";
        cout << "\t\t\t\t\t\t\t**********************************************************************************\n";
        cout << "\t" << patient_room_charge << "\n";
        cout << "\t" << patient_medicine_charge << "\n";
      }
      getline(in, garbage);
      getline(in, garbage1);
      getline(in, garbage2);
      getline(in, garbage3);
      getline(in, garbage4);
      getline(in, patient_id);
      getline(in, password);
      getline(in, patient_name);
      getline(in, patient_address);
      getline(in, patient_mobile_no);
      getline(in, patient_age);
      getline(in, patient_disease);
      getline(in, patient_room);
      getline(in, patient_condition);
      getline(in, patient_admit_date);
      getline(in, patient_room_charge);
      getline(in, patient_medicine_charge);
      getline(in, patient_bed);
    }

    in.close();
  }
};
// ...............................................................................................PATIENT DETAIL
struct patient
{
  string patient_id;
  string password;
  string patient_name;
  string patient_address;
  long long patient_mobile_no;
  int patient_age;
  string patient_disease;
  int patient_room;
  string patient_condition;
  string patient_admit_date;
  string patient_room_charge;
  string patient_medicine_charge;
  int patient_bed;
  patient *ptr;
};
class Patient
{
  struct patient *start;
  struct patient *current;
  struct patient *next;

public:
  Patient()
  {
    start = NULL;
    current = NULL;
    next = NULL;
  }

  void create()
  {
    if (start == NULL)
    {
      start = new patient;
      string patient_id;
      string password;
      string patient_name;
      string patient_address;
      long long patient_mobile_no;
      int patient_age;
      string patient_disease;
      int patient_room;
      string patient_condition;
      string patient_admit_date;
      string patient_room_charge;
      string patient_medicine_charge;
      int patient_bed;
      string id;
    L1:
    pid:
    v22:
      int countpid = 0;
      cout << "ENTER PATIENT ID : ";
      getline(cin, patient_id);

      for (int i = 0; i < patient_id.length(); i++)
      {
        if (!isdigit(patient_id[i]))
        {
          countpid++;
        }
      }
      if (patient_id == "0" || patient_id == "00" || patient_id == "000")
      {
        cout << "\nEnter greater than 0\n";
        goto v22;
      }
      if (countpid != 0)
      {
        cout << "\n\t\t\t PLEASE ENTER THE RIGHT ID : \n";
        goto pid;
      }
      ifstream in;
      in.open("patient_detail.txt", ios::in);
      while (in >> id)
      {

        if (id == patient_id)
        {
          cout << "\n\t\t\tTHIS ID IS ALREADY ASSIGNED PLEASE TRY OTHER ONE : \n";
          goto L1;
        }
      }
      in.close();
    N:
      int count = 0;
      cout << "ENTER PATIENT NAME : ";
      getline(cin, patient_name);

      for (int i = 0; i < patient_name.length(); i++)
      {
        if (isdigit(patient_name[i]))
        {
          count++;
        }
      }
      if (count != 0)
      {
        cout << "\n\t\t\t PLEASE ENTER THE RIGHT NAME : \n";
        goto N;
      }
      cout << "ENTER PASSWORD THAT YOU WANT TO ASSIGN THE PATIENT : ";
      getline(cin, password);

      ofstream out1;
      out1.open("patientuserids.txt", ios::app | ios::out);

      out1 << "\t\t*************************************************************\n";
      out1 << "\t\t                        PATIENT ACCOUNT                      \n";
      out1 << "\t\t*************************************************************\n";
      out1 << "ID :\t" << patient_id << "\n"
           << "PASSWORD :\t" << password << "\n";
      out1.close();

      cout << "ENTER PATIENT ADDRESS : ";
      getline(cin, patient_address);
    ph:
    mb:
      cout << "ENTER PATIENT MOBILE NUMBER : ";
      while (!(cin >> patient_mobile_no))
      {
        cin.clear();
        cin.ignore(123, '\n');
        cout << "\t\t\tENTER THE VALID PATIENT MOBILE NUMBER ... \n";
        goto mb;
      }
      if (patient_mobile_no < 10000000000)
      {
        cout << "\n\t\t\tPLEASE ENTER THE RIGHT MOBILE NUMBER ...\n";
        goto ph;
      }
      cin.ignore();
      ofstream out2;
      out2.open("Patientsname.txt", ios::app | ios::out);
      out2 << "\t\t\t*************************************************************\n";
      out2 << "\t\t\t                         PATIENT                           \n";
      out2 << "\t\t\t*************************************************************\n";
      out2 << "ID :\t" << patient_id << "\n"
           << "NAME :\t" << patient_name << "\n"
           << "MOBILE NUMBER :\t" << patient_mobile_no << "\n";

      out2.close();
    e:
    aged:
      cout << "ENTER PATIENT AGE : ";
      while (!(cin >> patient_age))
      {
        cin.clear();
        cin.ignore(123, '\n');
        cout << "\n\t\t\tENTER THE VALID PATIENT AGE ... \n";
        goto e;
      }
      if (patient_age <= 0 || patient_age > 140)
      {
        cout << "\n\t\t\tPLEASE ENTER THE RIGHT AGE ...\n";
        goto aged;
      }
      cin.ignore();
    pde:
      int countde = 0;
      cout << "ENTER  PATIENT DISEASE : ";
      getline(cin, patient_disease);

      for (int i = 0; i < patient_disease.length(); i++)
      {
        if (isdigit(patient_disease[i]))
        {
          countde++;
        }
      }
      if (countde != 0)
      {
        cout << "\n\t\t\t PLEASE ENTER THE RIGHT PATEINT DISEASE : \n";
        goto pde;
      }
    rm1:
    rn:
      cout << "ENTER PATIENT ROOM NUMBER : ";
      while (!(cin >> patient_room))
      {
        cin.clear();
        cin.ignore(123, '\n');
        cout << "\n\t\t\tENTER THE VALID PATIENT ROOM NUMBER ... \n";
        goto rn;
      }
      if (patient_room > 50)
      {
        cout << "\n\t\t\t PLEASE ASSIGN RIGHT ROOM \n\t\tTOTAL ROOMS ARE 50\n";
        goto rm1;
      }
      cin.ignore();
    con:
      int countcon = 0;

      cout << "ENTER PATIENT CONDITION : ";
      getline(cin, patient_condition);

      for (int i = 0; i < patient_condition.length(); i++)
      {
        if (isdigit(patient_condition[i]))
        {
          countcon++;
        }
      }
      if (countcon != 0)
      {
        cout << "\n\t\t\t PLEASE ENTER THE RIGHT CONDITION OF THE PATIENT : \n";
        goto con;
      }
      cout << "ENTER PATIENT'S ADMIT DATE : ";
      getline(cin, patient_admit_date);
    prc:
      int countrc = 0;
      cout << "ENTER PATIENT ROOM CHARGE : ";
      getline(cin, patient_room_charge);

      for (int i = 0; i < patient_room_charge.length(); i++)
      {
        if (!isdigit(patient_room_charge[i]))
        {
          countrc++;
        }
      }
      if (countrc != 0)
      {
        cout << "\n\t\t\t PLEASE ENTER THE RIGHT ROOM CHARGE : \n";
        goto prc;
      }
    pmc:
      int countmc = 0;
      cout << "ENTER PATIENT MEDICINE CHARGE : ";
      getline(cin, patient_medicine_charge);

      for (int i = 0; i < patient_medicine_charge.length(); i++)
      {
        if (!isdigit(patient_medicine_charge[i]))
        {
          countmc++;
        }
      }
      if (countmc != 0)
      {
        cout << "\n\t\t\t PLEASE ENTER THE RIGHT ROOM CHARGE : \n";
        goto pmc;
      }
    rm22:
    rn2:
      cout << "ENTER PATIENT BED NUMBER : ";
      while (!(cin >> patient_bed))
      {
        cin.clear();
        cin.ignore(123, '\n');
        cout << "\n\t\t\tENTER THE VALID PATIENT BED NUMBER ... \n";
        goto rn2;
      }
      if (patient_bed > 100)
      {
        cout << "\n\t\t\t PLEASE ASSIGN RIGHT BED \n\t\tTOTAL ROOMS ARE 100\n";
        goto rm22;
      }
      cin.ignore();
      start->patient_id = patient_id;
      start->password = password;
      start->patient_name = patient_name;
      start->patient_address = patient_address;
      start->patient_mobile_no = patient_mobile_no;
      start->patient_age = patient_age;
      start->patient_disease = patient_disease;
      start->patient_room = patient_room;
      start->patient_condition = patient_condition;
      start->patient_admit_date = patient_admit_date;
      start->patient_room_charge = patient_room_charge;
      start->patient_medicine_charge = patient_medicine_charge;
      start->patient_bed = patient_bed;
      start->ptr = NULL;
      current = start;
      ofstream out;
      out.open("patient_detail.txt", ios::app | ios::out);
      out << "\t\t\t\t\t\t\t**********************************************************************************\n";
      out << "\t\t\t\t\t\t\t*                                                                                *\n";
      out << "\t\t\t\t\t\t\t*                               PATIENTS  DETAIL                                 *\n";
      out << "\t\t\t\t\t\t\t*                                                                                *\n";
      out << "\t\t\t\t\t\t\t**********************************************************************************\n";
      out << "ID :\t" << patient_id << "\n"
          << "PASSWORD :\t" << password << "\n"
          << "NAME :\t" << patient_name << "\n"
          << "ADDRESS :\t" << patient_address << "\n"
          << "MOBILE NUMBER :\t" << patient_mobile_no << "\n"
          << "AGE :\t" << patient_age << "\n"
          << "DISEASE :\t" << patient_disease << "\n"
          << "ROOM :\t" << patient_room << "\n"
          << "CONDITION :\t" << patient_condition << "\n"
          << "ADMIT DATE :\t" << patient_admit_date << "\n"
          << "ROOM CHARGE :\t" << patient_room_charge << "\n"
          << "MEDICINE CHARGE :\t" << patient_medicine_charge << "\n"
          << "BED :\t" << patient_bed << "\n";

      out.close();
    }
    else
    {
      next = new patient;
      string patient_id;
      string password;
      string patient_name;
      string patient_address;
      long long patient_mobile_no;
      int patient_age;
      string patient_disease;
      int patient_room;
      string patient_condition;
      string patient_admit_date;
      string patient_room_charge;
      string patient_medicine_charge;
      int patient_bed;
      string id;
    L2:
    pid2:
    vbb:
      int countpid = 0;
      cout << "ENTER PATIENT ID : ";
      getline(cin, patient_id);

      for (int i = 0; i < patient_id.length(); i++)
      {
        if (!isdigit(patient_id[i]))
        {
          countpid++;
        }
      }
      if (patient_id == "0" || patient_id == "00" || patient_id == "000")
      {
        cout << "\nEnter greater than 0\n";
        goto vbb;
      }
      if (countpid != 0)
      {
        cout << "\n\t\t\t PLEASE ENTER THE RIGHT ID : \n";
        goto pid2;
      }
      ifstream in;
      in.open("patient_detail.txt", ios::in);
      while (in >> id)
      {

        if (id == patient_id)
        {
          cout << "T\n\t\t\tHIS ID IS ALREADY ASSIGNED PLEASE TRY OTHER ONE : \n";
          goto L2;
        }
      }
      in.close();
    M:
      int count = 0;
      cout << "ENTER PATIENT NAME : ";
      getline(cin, patient_name);

      for (int i = 0; i < patient_name.length(); i++)
      {
        if (isdigit(patient_name[i]))
        {
          count++;
        }
      }
      if (count != 0)
      {
        cout << "\n\t\t\t PLEASE ENTER THE RIGHT NAME : \n";
        goto M;
      }
      cout << "ENTER PASSWORD THAT YOU WANT TO ASSIGN THE PATIENT : ";
      getline(cin, password);
      ofstream out1;
      out1.open("patientuserids.txt", ios::app | ios::out);

      out1 << "\t\t*************************************************************\n";
      out1 << "\t\t                        PATIENT ACCOUNT                      \n";
      out1 << "\t\t*************************************************************\n";
      out1 << "ID :\t" << patient_id << "\n"
           << "PASSWORD :\t" << password << "\n";
      out1.close();
      cout << "ENTER PATIENT ADDRESS : ";
      getline(cin, patient_address);
    ph1:
    mb1:
      cout << "ENTER PATIENT MOBILE NUMBER : ";
      while (!(cin >> patient_mobile_no))
      {
        cin.clear();
        cin.ignore(123, '\n');
        cout << "\n\t\t\tENTER THE VALID PATIENT MOBILE NUMBER ... \n";
        goto mb1;
      }
      if (patient_mobile_no < 10000000000)
      {
        cout << "\n\t\t\tPLEASE ENTER THE RIGHT MOBILE NUMBER ...\n";
        goto ph1;
      }
      cin.ignore();
      ofstream out2;
      out2.open("Patientsname.txt", ios::app | ios::out);
      out2 << "\t\t\t*************************************************************\n";
      out2 << "\t\t\t                         PATIENT                           \n";
      out2 << "\t\t\t*************************************************************\n";
      out2 << "ID :\t" << patient_id << "\n"
           << "NAME :\t" << patient_name << "\n"
           << "MOBILE NUMBER :\t" << patient_mobile_no << "\n";
      out2.close();
    e2:
    aged2:
      cout << "ENTER PATIENT AGE : ";
      while (!(cin >> patient_age))
      {
        cin.clear();
        cin.ignore(123, '\n');
        cout << "\n\t\t\tENTER THE VALID PATIENT ... \n";
        goto e2;
      }
      if (patient_age <= 0 || patient_age > 140)
      {
        cout << "\n\t\t\tPLEASE ENTER THE RIGHT AGE ...";
        goto aged2;
      }
      cin.ignore();
    pde2:
      int countde = 0;
      cout << "ENTER PATIENT PATIENT DISEASE : ";
      getline(cin, patient_disease);

      for (int i = 0; i < patient_disease.length(); i++)
      {
        if (isdigit(patient_disease[i]))
        {
          countde++;
        }
      }
      if (countde != 0)
      {
        cout << "\n\t\t\t PLEASE ENTER THE RIGHT PATEINT DISEASE : \n";
        goto pde2;
      }

    rm33:
    rn3:
      cout << "ENTER PATIENT ROOM NUMBER : ";
      while (!(cin >> patient_room))
      {
        cin.clear();
        cin.ignore(123, '\n');
        cout << "\n\t\t\tENTER THE VALID PATIENT ROOM NUMBER ... \n";
        goto rn3;
      }
      if (patient_room > 50)
      {
        cout << "\n\t\t\t PLEASE ASSIGN RIGHT ROOM \n\t\tTOTAL ROOMS ARE 50\n";
        goto rm33;
      }
      cin.ignore();
    con2:
      int countcon = 0;

      cout << "ENTER PATIENT CONDITION : ";
      getline(cin, patient_condition);

      for (int i = 0; i < patient_condition.length(); i++)
      {
        if (isdigit(patient_condition[i]))
        {
          countcon++;
        }
      }
      if (countcon != 0)
      {
        cout << "\n\t\t\t PLEASE ENTER THE RIGHT CONDITION OF THE PATIENT : \n";
        goto con2;
      }
      cout << "ENTER PATIENT'S ADMIT DATE : ";
      getline(cin, patient_admit_date);
    prc2:
      int countrc = 0;
      cout << "ENTER PATIENT ROOM CHARGE : ";
      getline(cin, patient_room_charge);

      for (int i = 0; i < patient_room_charge.length(); i++)
      {
        if (!isdigit(patient_room_charge[i]))
        {
          countrc++;
        }
      }
      if (countrc != 0)
      {
        cout << "\n\t\t\t PLEASE ENTER THE RIGHT ROOM CHARGE : \n";
        goto prc2;
      }
    pmc2:
      int countmc = 0;
      cout << "ENTER PATIENT MEDICINE CHARGE : ";
      getline(cin, patient_medicine_charge);

      for (int i = 0; i < patient_medicine_charge.length(); i++)
      {
        if (!isdigit(patient_medicine_charge[i]))
        {
          countmc++;
        }
      }
      if (countmc != 0)
      {
        cout << "\n\t\t\t PLEASE ENTER THE RIGHT MEDICINE CHARGE : \n";
        goto pmc2;
      }
    rm44:
    rn4:
      cout << "ENTER PATIENT BED NUMBER : ";
      while (!(cin >> patient_room))
      {
        cin.clear();
        cin.ignore(123, '\n');
        cout << "\n\t\t\tENTER THE VALID PATIENT BED NUMBER ... \n";
        goto rn4;
      }
      if (patient_room > 100)
      {
        cout << "\n\t\t\t PLEASE ASSIGN RIGHT BED \n\t\tTOTAL BED ARE 100\n";
        goto rm44;
      }
      cin.ignore();
      next->patient_id = patient_id;
      next->password = password;
      next->patient_name = patient_name;
      next->patient_address = patient_address;
      next->patient_mobile_no = patient_mobile_no;
      next->patient_age = patient_age;
      next->patient_disease = patient_disease;
      next->patient_room = patient_room;
      next->patient_condition = patient_condition;
      next->patient_admit_date = patient_admit_date;
      start->patient_room_charge = patient_room_charge;
      next->patient_medicine_charge = patient_medicine_charge;
      next->patient_bed = patient_bed;
      next->ptr = NULL;
      current->ptr = next;
      current = next;
      ofstream out;
      out.open("patient_detail.txt", ios::app | ios::out);
      out << "\t\t\t\t\t\t\t**********************************************************************************\n";
      out << "\t\t\t\t\t\t\t*                                                                                *\n";
      out << "\t\t\t\t\t\t\t*                               PATIENTS  DETAIL                                 *\n";
      out << "\t\t\t\t\t\t\t*                                                                                *\n";
      out << "\t\t\t\t\t\t\t**********************************************************************************\n";
      out << "ID :\t" << patient_id << "\n"
          << "PASSWORD :\t" << password << "\n"
          << "NAME :\t" << patient_name << "\n"
          << "ADDRESS :\t" << patient_address << "\n"
          << "MOBILE NUMBER :\t" << patient_mobile_no << "\n"
          << "AGE :\t" << patient_age << "\n"
          << "DISEASE :\t" << patient_disease << "\n"
          << "ROOM :\t" << patient_room << "\n"
          << "CONDITION :\t" << patient_condition << "\n"
          << "ADMIT DATE :\t" << patient_admit_date << "\n"
          << "ROOM CHARGE :\t" << patient_room_charge << "\n"
          << "MEDICINE CHARGE :\t" << patient_medicine_charge << "\n"
          << "BED :\t" << patient_bed << "\n";
      out.close();
    }
  }
  void update()
  {
    string id;
    string garbage;
    string garbage1;
    string garbage2;
    string garbage3;
    string garbage4;
    string patient_id;
    string password;
    string patient_name;
    string patient_address;
    string patient_mobile_no;
    string patient_age;
    string patient_disease;
    string patient_room;
    string patient_condition;
    string patient_admit_date;
    string patient_room_charge;
    string patient_medicine_charge;
    string patient_bed;

    string id2;
    string name;
    string specilization;
    string gar1;
    string gar2;
    string gar3;
    ifstream in2;
    ofstream out2;
    ifstream in;
    ofstream out;
  right:
    out.open("patient_detail1.txt", ios::out | ios::app);
    in.open("patient_detail.txt", ios::in);
    in2.open("Patientsname.txt", ios::in);
    getline(in2, gar1);
    getline(in2, gar2);
    getline(in2, gar3);
    getline(in2, id2);
    getline(in2, name);
    getline(in2, specilization);
    while (!in2.eof())
    {
      cout << gar1 << "\n"
           << gar2 << "\n"
           << gar3 << "\n"
           << id2 << "\n"
           << name << "\n"
           << specilization << "\n";

      getline(in2, gar1);
      getline(in2, gar2);
      getline(in2, gar3);
      getline(in2, id2);
      getline(in2, name);
      getline(in2, specilization);
    }
    in2.close();

    int count = 0;
    string namee;
    cout << "\t\tENTER THE ID AND NAME OF THE PATIENT THAT YOU WANT TO UPDATE : \n";
    cout << "\t\t\tENTER THE ID OF THE PATIENT: ";
    getline(cin, id);
    cout << "ENTER THE NAME OF THE PATIENT : ";
    getline(cin, namee);
    ifstream in56;
    in56.open("Patientsname.txt", ios::in);
    getline(in56, gar1);
    getline(in56, gar2);
    getline(in56, gar3);
    getline(in56, id2);
    getline(in56, name);
    getline(in56, specilization);
    int countee = 0;
    while (!in56.eof())
    {

      if (id2 == "ID :\t" + id && name == "NAME :\t" + namee)
      {
        countee++;
      }

      getline(in56, gar1);
      getline(in56, gar2);
      getline(in56, gar3);
      getline(in56, id2);
      getline(in56, name);
      getline(in56, specilization);
    }
    if (countee == 0)
    {
      system("cls");
      cout << "\t\t\tSORRY THIS RECORD IS NOT FOUND ...\n\t\tPLEASE ENTER THE RIGHT ONE\n";
      goto right;
    }
    in56.close();
    cout << "\t\t\tENTER THE UPDATED DETAIL OF DOCTOR ...\n";

    string neaddress;
    string nespec;
    string nemobile_no;
    string neroom;
    string necity;
    string necondition;
    string nerc;
    string nemc;
    string nebd;

    cout << "ENTER THE UPDATED ADDRESS OF THE PATIENT :  ";
    getline(cin, neaddress);
  pmc3:
    int countmc = 0;
    cout << "ENTER THE UPDATED MOBILE NUMBER OF THE PATIENT : ";
    getline(cin, nemobile_no);

    for (int i = 0; i < nemobile_no.length(); i++)
    {
      if (!isdigit(nemobile_no[i]))
      {
        countmc++;
      }
    }
    if (countmc != 0)
    {
      cout << "\t\t\t PLEASE ENTER THE RIGHT  MOBILE NUMBER OF PATIENT : \n";
      goto pmc3;
    }

  pmc31:
    int countmc1 = 0;
    cout << "ENTER THE UPDATED ROOM OF THE PATIENT : ";
    getline(cin, neroom);

    for (int i = 0; i < neroom.length(); i++)
    {
      if (!isdigit(neroom[i]))
      {
        countmc1++;
      }
    }
    if (countmc1 != 0)
    {
      cout << "\t\t\t PLEASE ENTER THE RIGHT ROOM : \n";
      goto pmc31;
    }
  pmc32:
    int countmc2 = 0;
    cout << "ENTER THE UPDATED CONDITION OF THE PATIENT : ";
    getline(cin, necondition);

    for (int i = 0; i < necondition.length(); i++)
    {
      if (isdigit(necondition[i]))
      {
        countmc2++;
      }
    }
    if (countmc2 != 0)
    {
      cout << "\t\t\t PLEASE ENTER THE RIGHT CONDITION OF THE PATIENT : \n";
      goto pmc32;
    }
  pmc33:
    int countmc3 = 0;
    cout << "ENTER THE UPDATED ROOM CHARGES OF THE PATIENT : ";
    getline(cin, nerc);

    for (int i = 0; i < nerc.length(); i++)
    {
      if (!isdigit(nerc[i]))
      {
        countmc3++;
      }
    }
    if (countmc3 != 0)
    {
      cout << "\t\t\t PLEASE ENTER THE RIGHT ROOM CHARGES OF THE PATIENT : \n";
      goto pmc33;
    }
  pmc43:
    int countmc4 = 0;
    cout << "ENTER THE UPDATED MEDICINE CHARGES OF THE PATIENT : ";
    getline(cin, nemc);

    for (int i = 0; i < nemc.length(); i++)
    {
      if (!isdigit(nemc[i]))
      {
        countmc4++;
      }
    }
    if (countmc4 != 0)
    {
      cout << "\t\t\t PLEASE ENTER THE RIGHT MEDICINE CHARGES OF THE PATIENT : \n";
      goto pmc43;
    }
  pmc44:
    int countmc5 = 0;
    cout << "ENTER THE UPDATED BED NUMBER OF THE PATIENT : ";
    getline(cin, nebd);

    for (int i = 0; i < nebd.length(); i++)
    {
      if (!isdigit(nebd[i]))
      {
        countmc5++;
      }
    }
    if (countmc5 != 0)
    {
      cout << "\t\t\t PLEASE ENTER THE RIGHT BED NUMBER OF THE PATIENT : \n";
      goto pmc44;
    }
    out2.open("Patientsname1.txt", ios::out | ios::app);
    in2.open("Patientsname.txt", ios::in);
    getline(in2, gar1);
    getline(in2, gar2);
    getline(in2, gar3);
    getline(in2, id2);
    getline(in2, name);
    getline(in2, specilization);
    while (!in2.eof())
    {

      if (id2 == "ID :\t" + id)
      {
        out2 << gar1 << "\n"
             << gar2 << "\n"
             << gar3 << "\n"
             << id2 << "\n"
             << name << "\n"
             << "MOBILE NUMBER :\t" << nemobile_no << "\n";
      }
      else
      {
        out2 << gar1 << "\n"
             << gar2 << "\n"
             << gar3 << "\n"
             << id2 << "\n"
             << name << "\n"
             << specilization << "\n";
      }
      getline(in2, gar1);
      getline(in2, gar2);
      getline(in2, gar3);
      getline(in2, id2);
      getline(in2, name);
      getline(in2, specilization);
    }
    in2.close();
    out2.close();
    remove("Patientsname.txt");
    rename("Patientsname1.txt", "Patientsname.txt");

    getline(in, garbage);
    getline(in, garbage1);
    getline(in, garbage2);
    getline(in, garbage3);
    getline(in, garbage4);
    getline(in, patient_id);
    getline(in, password);
    getline(in, patient_name);
    getline(in, patient_address);
    getline(in, patient_mobile_no);
    getline(in, patient_age);
    getline(in, patient_disease);
    getline(in, patient_room);
    getline(in, patient_condition);
    getline(in, patient_admit_date);
    getline(in, patient_room_charge);
    getline(in, patient_medicine_charge);
    getline(in, patient_bed);
    while (!in.eof())
    {

      if (patient_id == "ID :\t" + id)
      {
        out << garbage << "\n"
            << garbage1 << "\n"
            << garbage2 << "\n"
            << garbage3 << "\n"
            << garbage4 << "\n"
            << patient_id << "\n"
            << password << "\n"
            << patient_name << "\n"
            << "ADDRESS :\t" << neaddress << "\n"
            << "MOBILE NUMBER :\t" << nemobile_no << "\n"
            << patient_age << "\n"
            << patient_disease << "\n"
            << "ROOM :\t" << neroom << "\n"
            << "CONDITION :\t" << necondition << "\n"
            << patient_admit_date << "\n"
            << "ROOM CHARGES :\t" << nerc << "\n"
            << "MEDICINE CHARGES :\t" << nemc << "\n"
            << "BED NJUMBER :\t" << nebd << "\n";
        cout << "\n\n\n\t\t\t\t\tFOLLOWING PATEINT RECORD IS SUCCESSFULLY DELETED... \n\n\n\n";
        cout << garbage << "\n"
             << garbage1 << "\n"
             << garbage2 << "\n"
             << garbage3 << "\n"
             << garbage4 << "\n"
             << "\t\t\t" << patient_id << "\n"
             << "\t\t\t" << password << "\n"
             << "\t\t\t" << patient_name << "\n"
             << "\t\t\t" << patient_address << "\n"
             << "\t\t\t" << patient_mobile_no << "\n"
             << "\t\t\t" << patient_age << "\n"
             << "\t\t\t" << patient_disease << "\n"
             << "\t\t\t" << patient_room << "\n"
             << "\t\t\t" << patient_condition << "\n"
             << "\t\t\t" << patient_admit_date << "\n"
             << "\t\t\t" << patient_room_charge << "\n"
             << "\t\t\t" << patient_medicine_charge << "\n"
             << "\t\t\t" << patient_bed << "\n";
      }
      else
      {
        out << garbage << "\n"
            << garbage1 << "\n"
            << garbage2 << "\n"
            << garbage3 << "\n"
            << garbage4 << "\n"
            << patient_id << "\n"
            << password << "\n"
            << patient_name << "\n"
            << patient_address << "\n"
            << patient_mobile_no << "\n"
            << patient_age << "\n"
            << patient_disease << "\n"
            << patient_room << "\n"
            << patient_condition << "\n"
            << patient_admit_date << "\n"
            << patient_room_charge << "\n"
            << patient_medicine_charge << "\n"
            << patient_bed << "\n";
      }
      getline(in, garbage);
      getline(in, garbage1);
      getline(in, garbage2);
      getline(in, garbage3);
      getline(in, garbage4);
      getline(in, patient_id);
      getline(in, password);
      getline(in, patient_name);
      getline(in, patient_address);
      getline(in, patient_mobile_no);
      getline(in, patient_age);
      getline(in, patient_disease);
      getline(in, patient_room);
      getline(in, patient_condition);
      getline(in, patient_admit_date);
      getline(in, patient_room_charge);
      getline(in, patient_medicine_charge);
      getline(in, patient_bed);
    }
    in.close();
    out.close();
    remove("patient_detail.txt");
    rename("patient_detail1.txt", "patient_detail.txt");
  }

  void deletion()
  {
    if (start == NULL)
    {
      cout << "Linked list is under flow\n";
    }
    else if (start->ptr == NULL)
    {
      free(start);
    }
    else
    {
      start = start->ptr;
    }
    string id;
    string garbage;
    string garbage1;
    string garbage2;
    string garbage3;
    string garbage4;
    string patient_id;
    string password;
    string patient_name;
    string patient_address;
    string patient_mobile_no;
    string patient_age;
    string patient_disease;
    string patient_room;
    string patient_condition;
    string patient_admit_date;
    string patient_room_charge;
    string patient_medicine_charge;
    string patient_bed;

    string id2;
    string name;
    string specilization;
    string gar1;
    string gar2;
    string gar3;
    ifstream in2;
    ofstream out2;
    ifstream in;
    ofstream out;
    out.open("patient_detail1.txt", ios::out | ios::app);
    in.open("patient_detail.txt", ios::in);
    out2.open("Patientsname1.txt", ios::out | ios::app);
    in2.open("Patientsname.txt", ios::in);
    getline(in2, gar1);
    getline(in2, gar2);
    getline(in2, gar3);
    getline(in2, id2);
    getline(in2, name);
    getline(in2, specilization);
    while (!in2.eof())
    {
      cout << gar1 << "\n"
           << gar2 << "\n"
           << gar3 << "\n"
           << id2 << "\n"
           << name << "\n"
           << specilization << "\n";

      getline(in2, gar1);
      getline(in2, gar2);
      getline(in2, gar3);
      getline(in2, id2);
      getline(in2, name);
      getline(in2, specilization);
    }
    in2.close();

    int count = 0;
    cout << "\t\tENTER THE ID OF PATIENT THAT YOU WANT TO DELETE : ";
    cin >> id;
    string gari;
    string gari2;
    string gari3;
    string gari4;
    string gari5;
    ifstream in101;
    ofstream out101;
    in101.open("patientuserids.txt", ios::in);
    out101.open("patientuserids1.txt", ios::app | ios::out);
    getline(in101, gari);
    getline(in101, gari2);
    getline(in101, gari3);
    getline(in101, gari4);
    getline(in101, gari5);
    while (!in101.eof())
    {
      if (gari4 == "ID :\t" + id)
      {
      }
      else
      {

        out101 << gari << "\n"
               << gari2 << "\n"
               << gari3 << "\n"
               << gari4 << "\n"
               << gari5 << "\n";
      }
      getline(in101, gari);
      getline(in101, gari2);
      getline(in101, gari3);
      getline(in101, gari4);
      getline(in101, gari5);
    }
    in101.close();
    out101.close();
    remove("patientuserids.txt");
    rename("patientuserids1.txt", "patientuserids.txt");

    in2.open("Patientsname.txt", ios::in);
    getline(in2, gar1);
    getline(in2, gar2);
    getline(in2, gar3);
    getline(in2, id2);
    getline(in2, name);
    getline(in2, specilization);
    while (!in2.eof())
    {

      if (id2 == "ID :\t" + id)
      {
        count == 1;
      }
      else
      {
        out2 << gar1 << "\n"
             << gar2 << "\n"
             << gar3 << "\n"
             << id2 << "\n"
             << name << "\n"
             << specilization << "\n";
      }
      getline(in2, gar1);
      getline(in2, gar2);
      getline(in2, gar3);
      getline(in2, id2);
      getline(in2, name);
      getline(in2, specilization);
    }

    if (count == 0)
    {
      cout << "\n\t\t\tTHIS PATIENT IS NOT FOUND ...\n";
    }

    in2.close();
    out2.close();
    remove("Patientsname.txt");
    rename("Patientsname1.txt", "Patientsname.txt");

    getline(in, garbage);
    getline(in, garbage1);
    getline(in, garbage2);
    getline(in, garbage3);
    getline(in, garbage4);
    getline(in, patient_id);
    getline(in, password);
    getline(in, patient_name);
    getline(in, patient_address);
    getline(in, patient_mobile_no);
    getline(in, patient_age);
    getline(in, patient_disease);
    getline(in, patient_room);
    getline(in, patient_condition);
    getline(in, patient_admit_date);
    getline(in, patient_room_charge);
    getline(in, patient_medicine_charge);
    getline(in, patient_bed);
    while (!in.eof())
    {

      if (patient_id == "ID :\t" + id)
      {
        cout << "\n\n\n\t\t\t\t\tFOLLOWING PATEINT RECORD IS SUCCESSFULLY DELETED... \n\n\n\n";
        cout << garbage << "\n"
             << garbage1 << "\n"
             << garbage2 << "\n"
             << garbage3 << "\n"
             << garbage4 << "\n"
             << "\t\t\t" << patient_id << "\n"
             << "\t\t\t" << password << "\n"
             << "\t\t\t" << patient_name << "\n"
             << "\t\t\t" << patient_address << "\n"
             << "\t\t\t" << patient_mobile_no << "\n"
             << "\t\t\t" << patient_age << "\n"
             << "\t\t\t" << patient_disease << "\n"
             << "\t\t\t" << patient_room << "\n"
             << "\t\t\t" << patient_condition << "\n"
             << "\t\t\t" << patient_admit_date << "\n"
             << "\t\t\t" << patient_room_charge << "\n"
             << "\t\t\t" << patient_medicine_charge << "\n"
             << "\t\t\t" << patient_bed << "\n";
      }
      else
      {
        out << garbage << "\n"
            << garbage1 << "\n"
            << garbage2 << "\n"
            << garbage3 << "\n"
            << garbage4 << "\n"
            << patient_id << "\n"
            << password << "\n"
            << patient_name << "\n"
            << patient_address << "\n"
            << patient_mobile_no << "\n"
            << patient_age << "\n"
            << patient_disease << "\n"
            << patient_room << "\n"
            << patient_condition << "\n"
            << patient_admit_date << "\n"
            << patient_room_charge << "\n"
            << patient_medicine_charge << "\n"
            << patient_bed << "\n";
      }
      getline(in, garbage);
      getline(in, garbage1);
      getline(in, garbage2);
      getline(in, garbage3);
      getline(in, garbage4);
      getline(in, patient_id);
      getline(in, password);
      getline(in, patient_name);
      getline(in, patient_address);
      getline(in, patient_mobile_no);
      getline(in, patient_age);
      getline(in, patient_disease);
      getline(in, patient_room);
      getline(in, patient_condition);
      getline(in, patient_admit_date);
      getline(in, patient_room_charge);
      getline(in, patient_medicine_charge);
      getline(in, patient_bed);
    }
    in.close();
    out.close();
    remove("patient_detail.txt");
    rename("patient_detail1.txt", "patient_detail.txt");
  }

  void search()
  {
    string id;
    string garbage;
    string garbage1;
    string garbage2;
    string garbage3;
    string garbage4;
    string patient_id;
    string password;
    string patient_name;
    string patient_address;
    string patient_mobile_no;
    string patient_age;
    string patient_disease;
    string patient_room;
    string patient_condition;
    string patient_admit_date;
    string patient_room_charge;
    string patient_medicine_charge;
    string patient_bed;
    string name;
    cout << "\t\tENTER THE ID OF PATIENT THAT YOU WANT TO SEARCH : ";
    getline(cin, id);
    cout << "\t\tENTER THE NAME OF PATIENT THAT YOU WANT TO SEARCH : ";
    getline(cin, name);

    ifstream in;
    in.open("patient_detail.txt", ios::in);
    getline(in, garbage);
    getline(in, garbage1);
    getline(in, garbage2);
    getline(in, garbage3);
    getline(in, garbage4);
    getline(in, patient_id);
    getline(in, password);
    getline(in, patient_name);
    getline(in, patient_address);
    getline(in, patient_mobile_no);
    getline(in, patient_age);
    getline(in, patient_disease);
    getline(in, patient_room);
    getline(in, patient_condition);
    getline(in, patient_admit_date);
    getline(in, patient_room_charge);
    getline(in, patient_medicine_charge);
    getline(in, patient_bed);
    while (!in.eof())
    {

      if (patient_id == "ID :\t" + id && patient_name == "NAME :\t" + name)
      {
        system("cls");
        cout << garbage << "\n"
             << garbage1 << "\n"
             << garbage2 << "\n"
             << garbage3 << "\n"
             << garbage4 << "\n"
             << "\t\t\t" << patient_id << "\n"
             << "\t\t\t" << password << "\n"
             << "\t\t\t" << patient_name << "\n"
             << "\t\t\t" << patient_address << "\n"
             << "\t\t\t" << patient_mobile_no << "\n"
             << "\t\t\t" << patient_age << "\n"
             << "\t\t\t" << patient_disease << "\n"
             << "\t\t\t" << patient_room << "\n"
             << "\t\t\t" << patient_condition << "\n"
             << "\t\t\t" << patient_admit_date << "\n"
             << "\t\t\t" << patient_room_charge << "\n"
             << "\t\t\t" << patient_medicine_charge << "\n"
             << "\t\t\t" << patient_bed << "\n";
        goto exit;
      }
      else
      {
        system("cls");
        cout << "\n\n\n\n\t\t\t\t\t\tSORRY THIS PATIENT IS NOT EXIST ...!\n";
      }

      getline(in, garbage);
      getline(in, garbage1);
      getline(in, garbage2);
      getline(in, garbage3);
      getline(in, garbage4);
      getline(in, patient_id);
      getline(in, password);
      getline(in, patient_name);
      getline(in, patient_address);
      getline(in, patient_mobile_no);
      getline(in, patient_age);
      getline(in, patient_disease);
      getline(in, patient_room);
      getline(in, patient_condition);
      getline(in, patient_admit_date);
      getline(in, patient_room_charge);
      getline(in, patient_medicine_charge);
      getline(in, patient_bed);
    }
  exit:
    in.close();
  }
};

class Login : public Patient, public Doctor, public Bill
{
public:
  void login()
  {
    int count = 0;
    string garbage;
    string garbage1;
    string garbage2;
    string garbage3;
    string garbage4;
    string patient_id;
    string patient_password;
    string patient_name;
    string patient_address;
    string patient_mobile_no;
    string patient_age;
    string patient_disease;
    string patient_room;
    string patient_condition;
    string patient_admit_date;
    string patient_room_charge;
    string patient_medicine_charge;
    string patient_bed;
    string doctor_id;
    string doctor_password;
    string doctor_name;
    string doctor_address;
    string doctor_mobile_no;
    string doctor_age;
    string doctor_qualification;
    string doctor_specialization;
    string doctor_experience;
    string doctor_city;
    string userid, password, id, pass;

    int choice;
    // system("cls");
  ph:
    cout << "\n\n\n\n";
    cout << "\t\t\t|    Enter --> 1 for LOGIN as a --> ADMIN                    |\n";
    cout << "\t\t\t|    Enter --> 2 for LOGIN as a --> PATIENT                  |\n";
    cout << "\t\t\t|    Enter --> 3 for LOGIN as a --> DOCTOR                   |\n";
    cout << "\t\t\t-------------------------------------------------------------------Enter choice. --> ";

    while (!(cin >> choice))
    {
      cin.clear();
      cin.ignore(123, '\n');
      cout << "\n\t\t\tENTER THE VALID  NUMBER ... \n";
      goto ph;
    }

    cin.ignore();
    if (choice == 1)
    {
      system("cls");
      cout << "\t\tPLEASE ENTER THE USERNAME AND PASSWORD :\n";
      cout << "\t\t\tUSERNAME ";
      cin >> userid;
      cout << "\t\t\tPASSWORD ";
      int ch;
      ch = getch();
      while (ch != 13)
      {
        if (ch == 27)
        {
          password.pop_back();
        }
        password.push_back(ch);
        cout << "*";
        ch = getch();
      }

      ifstream in;
      in.open("userids.txt");
      while (in >> id >> pass)
      {

        if (id == userid && pass == password)
        {
          count = 1;
          system("cls");
        }
      }
      in.close();
    }
    else if (choice == 2)
    {
      system("cls");
      cout << "\t\tPLEASE ENTER THE USERNAME AND PASSWORD :\n";
      cout << "\t\t\tUSERNAME ";
      cin >> userid;
      cout << "\t\t\tPASSWORD ";
      int ch;
      ch = getch();
      while (ch != 13)
      {

        password.push_back(ch);
        cout << "*";
        ch = getch();
      }
      ifstream in;
      in.open("patientuserids.txt");
      string gari1;
      string gari2;
      string gari3;
      string gari4;
      string gari5;
      getline(in, gari1);
      getline(in, gari2);
      getline(in, gari3);
      getline(in, gari4);
      getline(in, gari5);
      while (!in.eof())
      {

        if (gari4 == "ID :\t" + userid && gari5 == "PASSWORD :\t" + password)
        {
          count = 2;
          system("cls");
        }
        getline(in, gari1);
        getline(in, gari2);
        getline(in, gari3);
        getline(in, gari4);
        getline(in, gari5);
      }
      in.close();
    }
    else if (choice == 3)
    {
      system("cls");
      cout << "\t\tPLEASE ENTER THE USERNAME AND PASSWORD :\n";
      cout << "\t\t\tUSERNAME ";
      cin >> userid;
      cout << "\t\t\tPASSWORD ";
      int ch;
      ch = getch();
      while (ch != 13)
      {
        password.push_back(ch);
        cout << "*";
        ch = getch();
      }
      ifstream in;
      in.open("doctoruserids.txt");
      string gari1;
      string gari2;
      string gari3;
      string gari4;
      string gari5;
      getline(in, gari1);
      getline(in, gari2);
      getline(in, gari3);
      getline(in, gari4);
      getline(in, gari5);
      while (!in.eof())
      {

        if (gari4 == "ID :\t" + userid && gari5 == "PASSWORD :\t" + password)
        {
          count = 3;
          system("cls");
        }
        getline(in, gari1);
        getline(in, gari2);
        getline(in, gari3);
        getline(in, gari4);
        getline(in, gari5);
      }
      in.close();
    }

    if (count == 1)
    {
    p:
      int choiced;
      do
      {
        cout << "\n\n\n\n\n\n\n\n\n\n";
        cout << "|    Enter --> 1 for enter into PATIENT FILE.                |\n";
        cout << "|    Enter --> 2 for enter into DOCTOR FILE.                 |\n";
        cout << "|    Enter --> 3 for calculate the bill of specific patient.     |\n";
        cout << "|    Enter --> 4 for exit.                                       |\n";
        cout << "--------------------------------------------------------------------------Enter choice. --> ";
        while (!(cin >> choiced))
        {
          cin.clear();
          cin.ignore(123, '\n');
          cout << "\n\t\t\tENTER THE VALID  NUMBER ... \n";
          goto p;
        }
        if (choiced == 1)
        {

          int choice;
          do
          {
            cout << "\n\n\n\n";
            cout << "\t\t\t ________________________________________________________________________________" << endl;
            cout << "\t\t\t|--------------------------------------------------------------------------------|\n";
            cout << "\t\t\t|                                                                                |\n";
            cout << "\t\t\t|                                                                                |\n";
            cout << "\t\t\t|                                 ALL ABOUT PATIENTS                             |\n";
            cout << "\t\t\t|                                                                                |\n";
            cout << "\t\t\t|                                                                                |\n";
            cout << "\t\t\t|________________________________________________________________________________|\n";
            cout << "\t\t\t|________________________________________________________________________________|\n\n\n";
          pwe:
          jum:
            cout << "|    Enter --> 1 for Adding patient.                    |\n";
            cout << "|    Enter --> 2 for search patient detail.             |\n";
            cout << "|    Enter --> 3 for deletion.                          |\n";
            cout << "|    Enter --> 4 for updation.                          |\n";
            cout << "|    Enter --> 5 for exit.                              |\n";
            cout << "--------------------------------------------------------Enter choice. --> ";
            while (!(cin >> choice))
            {
              cin.clear();
              cin.ignore(123, '\n');
              cout << "\n\t\t\tENTER THE VALID  NUMBER ... \n";
              goto pwe;
            }
            cin.ignore();
            switch (choice)
            {
            case 1:

              Patient::create();

              break;
            case 2:
              Patient::search();
              break;
            case 3:
              Patient::deletion();
              break;
            case 4:
              Patient::update();
              break;
            case 5:
              cout << "\n\n\n\n\t\t\t\t\t ****** T H A N K S ******n\n";
              break;
            default:
              cout << "\n\n\t\tYOU ENTER WRONG NUMBER SO PLEASE ENTER RIGHT NUMBER ........ : \n\n";
              goto jum;
            }
          } while (choice != 5);
        }
        if (choiced == 2)
        {

          int docchoice;
          do
          {
            cout << "\n\n\n\n";
            cout << "\t\t\t ________________________________________________________________________________" << endl;
            cout << "\t\t\t|--------------------------------------------------------------------------------|\n";
            cout << "\t\t\t|                                                                                |\n";
            cout << "\t\t\t|                                                                                |\n";
            cout << "\t\t\t|                                 ALL ABOUT DOCTORS                              |\n";
            cout << "\t\t\t|                                                                                |\n";
            cout << "\t\t\t|                                                                                |\n";
            cout << "\t\t\t|________________________________________________________________________________|\n";
            cout << "\t\t\t|________________________________________________________________________________|\n";
          paa:
          jum2:
            cout << "|    Enter --> 1 for Adding doctor.                    |\n";
            cout << "|    Enter --> 2 for search doctor detail.             |\n";
            cout << "|    Enter --> 3 for deletion.                         |\n";
            cout << "|    Enter --> 4 for updation.                         |\n";
            cout << "|    Enter --> 5 for exit.                             |\n";
            cout << "--------------------------------------------------------Enter choice. --> ";
            while (!(cin >> docchoice))
            {
              cin.clear();
              cin.ignore(123, '\n');
              cout << "\n\t\t\tENTER THE VALID  NUMBER ... \n";
              goto paa;
            }
            cin.ignore();
            switch (docchoice)
            {
            case 1:

              Doctor::create();

              break;
            case 2:
              Doctor::search();
              break;
            case 3:
              Doctor::deletion();
              break;
            case 4:
              Doctor::update();
              break;
            case 5:
              cout << "\n\n\t\t ******   T H A N K S   ******\n\n";
              break;
            default:
              cout << "\n\n\t\tYOU ENTER WRONG NUMBER SO PLEASE ENTER RIGHT NUMBER ........ : \n\n";
              goto jum2;
            }
          } while (docchoice != 5);
        }
        if (choiced == 3)
        {
          Bill::bill();
        }
        if (choiced == 4)
        {
          cout << "\n\n\n\n\t\t\t\t\t ***********   THANKS   **********\n\n";
        }
      } while (choiced != 4);
    }
    else if (count == 2)
    {

      ifstream in;

      in.open("patient_detail.txt", ios::in);
      getline(in, garbage);
      getline(in, garbage1);
      getline(in, garbage2);
      getline(in, garbage3);
      getline(in, garbage4);
      getline(in, patient_id);
      getline(in, patient_password);
      getline(in, patient_name);
      getline(in, patient_address);
      getline(in, patient_mobile_no);
      getline(in, patient_age);
      getline(in, patient_disease);
      getline(in, patient_room);
      getline(in, patient_condition);
      getline(in, patient_admit_date);
      getline(in, patient_room_charge);
      getline(in, patient_medicine_charge);
      getline(in, patient_bed);
      while (!in.eof())
      {

        if (patient_id == "ID :\t" + userid && patient_password == "PASSWORD :\t" + password)
        {

          cout << garbage << "\n"
               << garbage1 << "\n"
               << garbage2 << "\n"
               << garbage3 << "\n"
               << garbage4 << "\n"
               << "\t\t\t" << patient_id << "\n"
               << "\t\t\t" << patient_password << "\n"
               << "\t\t\t" << patient_name << "\n"
               << "\t\t\t" << patient_address << "\n"
               << "\t\t\t" << patient_mobile_no << "\n"
               << "\t\t\t" << patient_age << "\n"
               << "\t\t\t" << patient_disease << "\n"
               << "\t\t\t" << patient_room << "\n"
               << "\t\t\t" << patient_condition << "\n"
               << "\t\t\t" << patient_admit_date << "\n"
               << "\t\t\t" << patient_room_charge << "\n"
               << "\t\t\t" << patient_medicine_charge << "\n"
               << "\t\t\t" << patient_bed << "\n";
        }
        getline(in, garbage);
        getline(in, garbage1);
        getline(in, garbage2);
        getline(in, garbage3);
        getline(in, garbage4);
        getline(in, patient_id);
        getline(in, patient_password);
        getline(in, patient_name);
        getline(in, patient_address);
        getline(in, patient_mobile_no);
        getline(in, patient_age);
        getline(in, patient_disease);
        getline(in, patient_room);
        getline(in, patient_condition);
        getline(in, patient_admit_date);
        getline(in, patient_room_charge);
        getline(in, patient_medicine_charge);
        getline(in, patient_bed);
      }
      in.close();
    higher:
      string gar1;
      string gar2;
      string gar3;
      string id2;
      string name;
      string specilization;
      string slot;
      string slot1;
      string slot2;

      int dnotfound = 0;
      ifstream in1;

      in1.open("Doctorsname.txt", ios::in);

      getline(in1, gar1);
      getline(in1, gar2);
      getline(in1, gar3);
      getline(in1, id2);
      getline(in1, name);
      getline(in1, specilization);
      getline(in1, slot);
      getline(in1, slot1);
      getline(in1, slot2);
      cout << "\t\tAVAILABLE DOCTORS ARE...: \n\n";
      while (!in1.eof())
      {
        cout << gar1 << "\n"
             << gar2 << "\n"
             << gar3 << "\n"
             << id2 << "\n"
             << name << "\n"
             << specilization << "\n"
             << "\t\t**************************\n"
             << "\t\t*SLOTS OF THIS DOCTOR ARE*\n"
             << "\t\t**************************\n"
             << "\t\t" << slot << "\n"
             << "\t\t" << slot1 << "\n"
             << "\t\t" << slot2 << "\n";

        getline(in1, gar1);
        getline(in1, gar2);
        getline(in1, gar3);
        getline(in1, id2);
        getline(in1, name);
        getline(in1, specilization);
        getline(in1, slot);
        getline(in1, slot1);
        getline(in1, slot2);
      }
      in1.close();
    F1:
      ifstream in2;
      in2.open("Doctorsname.txt", ios::in);
      string thisid;
      string thisname;
      cout << "\tEnter the ID of DOCTOR : ";
      cin >> thisid;
      cout << "\tEnter the NAME of DOCTOR : ";
      cin >> thisname;
      string aposlot;
      cout << "Enter the appointment slot: ";
      cin >> aposlot;
      getline(in2, gar1);
      getline(in2, gar2);
      getline(in2, gar3);
      getline(in2, id2);
      getline(in2, name);
      getline(in2, specilization);
      getline(in2, slot);
      getline(in2, slot1);
      getline(in2, slot2);
      int count = 0;
      while (!in2.eof())
      {
        if (id2 == "ID :\t" + thisid && name == "NAME :\t" + thisname && (slot == "SLOT - 1 :\t" + aposlot || slot1 == "SLOT - 2 :\t" + aposlot || slot2 == "SLOT - 3 :\t" + aposlot))
        {

          string agar;
          string agar1;
          string agar2;
          string did;
          string dname;
          string dspec;
          string dappo;
          string agar3;
          string pid;
          string ppassword;
          string pname;
          string paddress;
          string pmoblie;
          string page;
          string pdisease;
          string proom;
          string pcondition;
          string pdate;
          string rcharge;
          string mcharge;
          string pbed;
          ifstream in90;
          in90.open("appointment.txt", ios::in);
          getline(in90, agar);
          getline(in90, agar1);
          getline(in90, agar2);
          getline(in90, did);
          getline(in90, dname);
          getline(in90, dspec);
          getline(in90, dappo);
          getline(in90, agar3);
          getline(in90, pid);
          getline(in90, ppassword);
          getline(in90, pname);
          getline(in90, paddress);
          getline(in90, pmoblie);
          getline(in90, page);
          getline(in90, pdisease);
          getline(in90, proom);
          getline(in90, pcondition);
          getline(in90, pdate);
          getline(in90, rcharge);
          getline(in90, mcharge);
          getline(in90, pbed);
          while (!in90.eof())
          {
            if (did == "DOCTOR ID :	" + thisid && dname == "DOCTOR NAME :	" + thisname && dappo == "APPOINTMENT SLOT : " + aposlot)
            {
              cout << "\t\t\tPLEASE SELECT OTHER SLOTS THIS IS ALREADY BOOKED\n";
              goto F1;
            }
            else
            {
              dnotfound = 1;
            }
            getline(in90, agar);
            getline(in90, agar1);
            getline(in90, agar2);
            getline(in90, did);
            getline(in90, dname);
            getline(in90, dspec);
            getline(in90, dappo);
            getline(in90, agar3);
            getline(in90, pid);
            getline(in90, ppassword);
            getline(in90, pname);
            getline(in90, paddress);
            getline(in90, pmoblie);
            getline(in90, page);
            getline(in90, pdisease);
            getline(in90, proom);
            getline(in90, pcondition);
            getline(in90, pdate);
            getline(in90, rcharge);
            getline(in90, mcharge);
            getline(in90, pbed);
          }
          in90.close();
          if (dnotfound == 1)
          {

            count = 1;
            ofstream out11;
            out11.open("appointment.txt", ios::app | ios::out);
            out11 << "\t\t\t*************************************************************\n"
                  << "\t\t\t*                      APPOINTMENT                          *\n"
                  << "\t\t\t*************************************************************\n"
                  << "DOCTOR " << id2 << "\n"
                  << "DOCTOR " << name << "\n"
                  << "DOCTOR " << specilization << "\n";
            out11.close();
          }
        }

        getline(in2, gar1);
        getline(in2, gar2);
        getline(in2, gar3);
        getline(in2, id2);
        getline(in2, name);
        getline(in2, specilization);
        getline(in2, slot);
        getline(in2, slot1);
        getline(in2, slot2);
      }
      in2.close();

      if (count == 1)
      {

        string garbage;
        string garbage1;
        string garbage2;
        string garbage3;
        string garbage4;
        string patient_id;
        string password;
        string patient_name;
        string patient_address;
        string patient_mobile_no;
        string patient_age;
        string patient_disease;
        string patient_room;
        string patient_condition;
        string patient_admit_date;
        string patient_room_charge;
        string patient_medicine_charge;
        string patient_bed;

        string gar1;
        string gar2;
        string gar3;
        string id2;
        string name;
        string specilization;
        int counte = 0;

        ifstream in3;
        ofstream out3;
        out3.open("Patientsname1.txt", ios::out | ios::app);
        in3.open("Patientsname.txt", ios::in);
        getline(in3, gar1);
        getline(in3, gar2);
        getline(in3, gar3);
        getline(in3, id2);
        getline(in3, name);
        getline(in3, specilization);
        while (!in3.eof())
        {

          if (id2 == "ID :\t" + userid)
          {
            counte = 1;
          }
          else
          {
            out3 << gar1 << "\n"
                 << gar2 << "\n"
                 << gar3 << "\n"
                 << id2 << "\n"
                 << name << "\n"
                 << specilization << "\n";
          }
          getline(in3, gar1);
          getline(in3, gar2);
          getline(in3, gar3);
          getline(in3, id2);
          getline(in3, name);
          getline(in3, specilization);
        }
        if (counte == 0)
        {
          cout << "THIS PATIENT IS NOT FOUND ";
        }
        in3.close();
        out3.close();
        remove("Patientsname.txt");
        rename("Patientsname1.txt", "Patientsname.txt");

        ifstream in;
        ofstream out;
        out.open("patient_detail1.txt", ios::out | ios::app);
        in.open("patient_detail.txt", ios::in);

        getline(in, garbage);
        getline(in, garbage1);
        getline(in, garbage2);
        getline(in, garbage3);
        getline(in, garbage4);
        getline(in, patient_id);
        getline(in, password);
        getline(in, patient_name);
        getline(in, patient_address);
        getline(in, patient_mobile_no);
        getline(in, patient_age);
        getline(in, patient_disease);
        getline(in, patient_room);
        getline(in, patient_condition);
        getline(in, patient_admit_date);
        getline(in, patient_room_charge);
        getline(in, patient_medicine_charge);
        getline(in, patient_bed);
        while (!in.eof())
        {

          if (patient_id == "ID :\t" + userid)
          {
            ofstream out11;
            out11.open("appointment.txt", ios::app | ios::out);
            out11 << "APPOINTMENT SLOT : " << aposlot << "\n"
                  << "*****************PATIENT**********************\n"
                  << "PATIENT " << patient_id << "\n"
                  << "PATIENT " << password << "\n"
                  << "PATIENT " << patient_name << "\n"
                  << "PATIENT " << patient_address << "\n"
                  << "PATIENT " << patient_mobile_no << "\n"
                  << "PATIENT " << patient_age << "\n"
                  << "PATIENT " << patient_disease << "\n"
                  << "PATIENT " << patient_room << "\n"
                  << "PATIENT " << patient_condition << "\n"
                  << "PATIENT " << patient_admit_date << "\n"
                  << "PATIENT " << patient_room_charge << "\n"
                  << "PATIENT " << patient_medicine_charge << "\n"
                  << "PATIENT " << patient_bed << "\n";
            out11.close();
            cout << "\n\n\n\t\t\t\t\tFOLLOWING PATEINT RECORD IS SUCCESSFULLY APPOINTED... \n\n\n\n";
            cout << garbage << "\n"
                 << garbage1 << "\n"
                 << garbage2 << "\n"
                 << garbage3 << "\n"
                 << garbage4 << "\n"
                 << "\t\t\t" << patient_id << "\n"
                 << "\t\t\t" << password << "\n"
                 << "\t\t\t" << patient_name << "\n"
                 << "\t\t\t" << patient_address << "\n"
                 << "\t\t\t" << patient_mobile_no << "\n"
                 << "\t\t\t" << patient_age << "\n"
                 << "\t\t\t" << patient_disease << "\n"
                 << "\t\t\t" << patient_room << "\n"
                 << "\t\t\t" << patient_condition << "\n"
                 << "\t\t\t" << patient_admit_date << "\n"
                 << "\t\t\t" << patient_room_charge << "\n"
                 << "\t\t\t" << patient_medicine_charge << "\n"
                 << "\t\t\t" << patient_bed << "\n";
          }
          else
          {
            out << garbage << "\n"
                << garbage1 << "\n"
                << garbage2 << "\n"
                << garbage3 << "\n"
                << garbage4 << "\n"
                << patient_id << "\n"
                << password << "\n"
                << patient_name << "\n"
                << patient_address << "\n"
                << patient_mobile_no << "\n"
                << patient_age << "\n"
                << patient_disease << "\n"
                << patient_room << "\n"
                << patient_condition << "\n"
                << patient_admit_date << "\n"
                << patient_room_charge << "\n"
                << patient_medicine_charge << "\n"
                << patient_bed << "\n";
          }
          getline(in, garbage);
          getline(in, garbage1);
          getline(in, garbage2);
          getline(in, garbage3);
          getline(in, garbage4);
          getline(in, patient_id);
          getline(in, password);
          getline(in, patient_name);
          getline(in, patient_address);
          getline(in, patient_mobile_no);
          getline(in, patient_age);
          getline(in, patient_disease);
          getline(in, patient_room);
          getline(in, patient_condition);
          getline(in, patient_admit_date);
          getline(in, patient_room_charge);
          getline(in, patient_medicine_charge);
          getline(in, patient_bed);
        }
        in.close();
        out.close();
        remove("patient_detail.txt");
        rename("patient_detail1.txt", "patient_detail.txt");
      }
      else
      {
        cout << "\n\nSORRY THIS RECORD OF DOCTOR IS NOT FOUND...!";
        goto higher;
      }

      login();
    }
    else if (count == 3)
    {
      string garbage;
      string garbage1;
      string garbage2;
      string garbage3;
      string garbage4;
      string doctor_id;
      string doctor_password;
      string doctor_name;
      string doctor_address;
      string doctor_mobile_no;
      string doctor_age;
      string doctor_qualification;
      string doctor_specialization;
      string doctor_experience;
      string doctor_city;
      string doctor_slot;
      string doctor_slot1;
      string doctor_slot2;
      ifstream in45;
      in45.open("doctor_detail.txt", ios::in);
      getline(in45, garbage);
      getline(in45, garbage1);
      getline(in45, garbage2);
      getline(in45, garbage3);
      getline(in45, garbage4);
      getline(in45, doctor_id);
      getline(in45, doctor_password);
      getline(in45, doctor_name);
      getline(in45, doctor_address);
      getline(in45, doctor_mobile_no);
      getline(in45, doctor_age);
      getline(in45, doctor_qualification);
      getline(in45, doctor_specialization);
      getline(in45, doctor_experience);
      getline(in45, doctor_city);
      getline(in45, doctor_slot);
      getline(in45, doctor_slot1);
      getline(in45, doctor_slot2);
      while (!in45.eof())
      {

        if (doctor_id == "ID :\t" + userid && doctor_password == "PASSWORD :\t" + password)
        {

          cout << garbage << "\n"
               << garbage1 << "\n"
               << garbage2 << "\n"
               << garbage3 << "\n"
               << garbage4 << "\n"
               << "\t\t\t" << doctor_id << "\n"
               << "\t\t\t" << doctor_password << "\n"
               << "\t\t\t" << doctor_name << "\n"
               << "\t\t\t" << doctor_address << "\n"
               << "\t\t\t" << doctor_mobile_no << "\n"
               << "\t\t\t" << doctor_age << "\n"
               << "\t\t\t" << doctor_qualification << "\n"
               << "\t\t\t" << doctor_specialization << "\n"
               << "\t\t\t" << doctor_experience << "\n"
               << "\t\t\t" << doctor_city << "\n"
               << "\t\t\t" << doctor_slot << "\n"
               << "\t\t\t" << doctor_slot1 << "\n"
               << "\t\t\t" << doctor_slot2 << "\n";
        }
        getline(in45, garbage);
        getline(in45, garbage1);
        getline(in45, garbage2);
        getline(in45, garbage3);
        getline(in45, garbage4);
        getline(in45, doctor_id);
        getline(in45, doctor_password);
        getline(in45, doctor_name);
        getline(in45, doctor_address);
        getline(in45, doctor_mobile_no);
        getline(in45, doctor_age);
        getline(in45, doctor_qualification);
        getline(in45, doctor_specialization);
        getline(in45, doctor_experience);
        getline(in45, doctor_city);
        getline(in45, doctor_slot);
        getline(in45, doctor_slot1);
        getline(in45, doctor_slot2);
      }
      in45.close();
      string gar1;
      string gar2;
      string gar3;
      string id2;
      string name;
      string specilization;
      string slot;
      string slot1;
      string slot2;
      string agar;
      string agar1;
      string agar2;
      string did;
      string dname;
      string dspec;
      string dappo;
      string agar3;
      string pid;
      string ppassword;
      string pname;
      string paddress;
      string pmoblie;
      string page;
      string pdisease;
      string proom;
      string pcondition;
      string pdate;
      string rcharge;
      string mcharge;
      string pbed;
      ifstream in66;
      in66.open("appointment.txt", ios::in);
      getline(in66, agar);
      getline(in66, agar1);
      getline(in66, agar2);
      getline(in66, did);
      getline(in66, dname);
      getline(in66, dspec);
      getline(in66, dappo);
      getline(in66, agar3);
      getline(in66, pid);
      getline(in66, ppassword);
      getline(in66, pname);
      getline(in66, paddress);
      getline(in66, pmoblie);
      getline(in66, page);
      getline(in66, pdisease);
      getline(in66, proom);
      getline(in66, pcondition);
      getline(in66, pdate);
      getline(in66, rcharge);
      getline(in66, mcharge);
      getline(in66, pbed);

      while (!in66.eof())
      {
        if (did == "DOCTOR ID :	" + userid)
        {
          cout << agar << "\n"
               << agar1 << "\n"
               << agar2 << "\n"
               << pid << "\n"
               << pname << "\n"
               << paddress << "\n"
               << pmoblie << "\n"
               << page << "\n"
               << pdisease << "\n"
               << proom << "\n"
               << pcondition << "\n"
               << pdate << "\n"
               << pbed << "\n";
        }

        getline(in66, agar);
        getline(in66, agar1);
        getline(in66, agar2);
        getline(in66, did);
        getline(in66, dname);
        getline(in66, dspec);
        getline(in66, dappo);
        getline(in66, agar3);
        getline(in66, pid);
        getline(in66, ppassword);
        getline(in66, pname);
        getline(in66, paddress);
        getline(in66, pmoblie);
        getline(in66, page);
        getline(in66, pdisease);
        getline(in66, proom);
        getline(in66, pcondition);
        getline(in66, pdate);
        getline(in66, rcharge);
        getline(in66, mcharge);
        getline(in66, pbed);
      }

      login();
    }

    else
    {
      cout << "LOGIN ERROR \n please cheak your username or password\n";
      login();
    }
  }
  void registeration()
  {
    string ruserid;
    char rpassword[50];
  START:
    system("cls");
    cout << "\t\t\t ENTER THE USERNAME : ";
    cin >> ruserid;
    cout << "\t\t\t ENTER THE PASSWORD : ";
    int i;
    char a;
    for (i = 0;;)
    {
      a = getch();
      if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
      {
        rpassword[i] = a;
        ++i;
        cout << "*";
      }
      if (a == '\b' && i >= 1)
      {
        cout << "\b \b";
        --i;
      }
      if (a == '\r')
      {
        rpassword[i] = '\0';
        break;
      }
    }
    if (i <= 5)
    {
      cout << "Minimum 6 digit character are requird\nEnter Again ";
      getch();
      goto START;
    }

    ofstream out;
    out.open("userids.txt", ios::app | ios::out);

    out << "\t\t*************************************************************\n";
    out << "\t\tUSERNAME\t\t\t\t\tPASSWORD\n";
    out << "\t\t*************************************************************\n\n";

    out << "\t\t" << ruserid << "\t\t\t" << rpassword << "\n\n";
    system("cls");
    cout << "\t\t\tregistration is successfully: \n";
    out.close();
  }
  void forget()
  {
    int option;
    system("cls");
    cout << "\t\t\t Did you forget the password? " << endl;
    cout << "Enter --> 1 to search your id by username : " << endl;
    cout << "Enter --> 2 to go back to main menu : " << endl;
    cout << "--------------------------------------------------- Enter your choice. --> ";
    cin >> option;
    switch (option)
    {
    case 1:
    {
      int count = 0;
      string suserid, sid, spass;
      cout << "\t\t\tEnter the username which you remember : ";
      cin >> suserid;
      ifstream in;
      in.open("userids.txt");

      while (in >> sid >> spass)
      {
        if (sid == suserid)
        {
          count = 1;
        }
      }
      in.close();
      if (count == 1)
      {
        cout << "your account is found .\n";
        cout << "your password is : " << spass;
      }
      else
      {
        cout << "your account is not found.";
      }
    }
    break;
    default:
      cout << "wrong choice please try again...!" << endl;
      forget();
    }
  }
};

int main()
{
  system("cls");
  cout << "\t\t****************************************************************************************************************\n";
  cout << "\t\t****************   *****************   ***********                 ************                *  **************\n";
  cout << "\t\t****************   *****************   **********   *************   *********    ***************  **************\n";
  cout << "\t\t****************   *****************   **********   *************   *********   ****              **************\n";
  cout << "\t\t****************   *****************   **********   *************   *********   ****              **************\n";
  cout << "\t\t****************   *****************   **********   *************   *********   ****              **************\n";
  cout << "\t\t****************   *****************   **********   *************   *********   ****************  **************\n";
  cout << "\t\t****************   *****************   **********   *************   *********   ******       ***  **************\n";
  cout << "\t\t****************   *****************   **********   *************   *********   ********+    ***  **************\n";
  cout << "\t\t****************                       ***********                 ************              ***  **************\n";
  cout << "\t\t***************************************************************************************************  ***********\n\n\n";
  // system("cls");
  Login lo;
  int choice;
  do
  {
    // system("cls");
  ph:

    cout << "\n\t\t\t ________________________________________________________________________________" << endl;
    cout << "\t\t\t|--------------------------------------------------------------------------------|\n";
    cout << "\t\t\t|                                                                                |\n";
    cout << "\t\t\t|                                                                                |\n";
    cout << "\t\t\t|                           PLEASE FIRST LOGIN YOUR ACCOUNT                      |\n";
    cout << "\t\t\t|                                                                                |\n";
    cout << "\t\t\t|                                                                                |\n";
    cout << "\t\t\t|________________________________________________________________________________|\n";
    cout << "\t\t\t|_______________________________________MENU_____________________________________|\n";

    cout << "                                                                                      \n\n";
    cout << "|  Enter --> 1 for LOGIN                       |\n";
    cout << "|  Enter --> 2 for REGISTRATION                |\n";
    cout << "|  Enter --> 3 for FORGOTTEN PASSWORD          |\n";
    cout << "--------------------------------------------------------------------Enter your choice. -->";

    while (!(cin >> choice))
    {
      cin.clear();
      cin.ignore(123, '\n');
      cout << "\n\t\t\tENTER THE VALID  NUMBER ... \n";
      goto ph;
    }

    cin.ignore();
    switch (choice)
    {

    case 1:
      lo.login();
      break;
    case 2:
      lo.registeration();
      break;
    case 3:
      lo.forget();
      break;

    default:
      system("cls");
      cout << "\t\t\tSelect from the option given below "
      main();
    }
  } while (choice != 4);

  return 0;
}