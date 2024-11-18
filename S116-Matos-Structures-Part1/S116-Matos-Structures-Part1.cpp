// S116-Matos-Structures-Part1.cpp 
/*
Using the following myPeople.txt file
Beatriz Elena, be@gmail.com, 29
Maya Simone, ms@gmail.com, 7
Eden Cecilia, ec@gmail.com, 5
Sage Azul, sa@depaul.edu, 22
Mila, m@hotmail.com, 63
Hilda, h@hotmail.com, 93
*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//Structures -------------------------------------
struct Person {
    string name;
    string email;
    int    age;
};


//Prototypes -------------------------------------
void experiment01();
void experiment02();
void experiment03();
void printPerson(Person  p);
void printPerson(Person* p);
void sortDatabase(vector<Person>& db);

int main()
{
    //experiment01();
    //experiment02();
    experiment03();
    cout << "\nAll done!\n";
}

//User-defined functions ----------------------------
void experiment03()
{
    ifstream mypeople("c:/temp/myPeople.txt");
    if (!mypeople) {
        cout << "ERROR - file not found\n";
        exit(1);
    }

    string n, e, a;
    vector<Person> db;

    while (getline(mypeople, n, ',')) {
        getline(mypeople, e, ',');
        getline(mypeople, a);

        cout << n << "\t" << e << "\t" << a << endl;

        int aint = stoi(a);
        Person p{ n, e, aint };
        db.push_back(p);
    }
    mypeople.close();

    cout << "\nShowing myPeople database\n";
    for (Person p : db) {
        printPerson(p);
    }

    //Oldest and Youngest person in the database
    int ageOldest = db[0].age;  
    int posOldest = 0;
    int ageYoungest = db[0].age;
    int posYoungest = 0;

    for (int i = 1; i < db.size(); i++)
    {
        Person p = db[i];

        if (p.age > ageOldest) {
            ageOldest = p.age;
            posOldest = i;
        }

        if (p.age < ageYoungest) {
            ageYoungest = p.age;
            posYoungest = i;
        }

    }
    cout << "\nOldest person: ";
    printPerson(db[posOldest]);

    cout << "\nYoungest person: ";
    printPerson(db[posYoungest]);

    sortDatabase(db);

    //Two youngest people
    cout << "\nThree Youngest people: ";
    printPerson(db[0]);
    printPerson(db[1]);
    printPerson(db[2]);
}

void sortDatabase(vector<Person>& db)
{
    for (int i = db.size() -1 ; i >0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (db[j].age > db[j + 1].age) {
                Person temp = db[j];
                db[j] = db[j + 1];
                db[j + 1] = temp;
            }
        }
    }
}






void experiment02()
{
    Person* p1 = new Person;
    p1->name = "Bart Simpson";
    p1->email = "bs@gmail.com";
    p1->age = 10;

    Person* p2 = new Person({ "Lisa Simpson", "ls@gmail.com", 8 });

    cout << "\nCall function accepting an instane of Person\n";
    printPerson(*p1);
    printPerson(*p2);

    cout << "\nCall function accepting a pointer to a Person object\n";
    printPerson(p1);
    printPerson(p2);

    delete p1, p2;
}





//--------------------------------------------------
void experiment01()
{
    //Create Static instances of Person Objects (Records)
    Person p1;
    p1.name = "Bart Simpson";
    p1.email = "bs@gmail.com";
    p1.age = 10;

    Person p2{ "Lisa Simpson", "ls@gmail.com", 8 };
    Person p3 = { "Homer Simpson", "hs@gmail.com", 39 };

    printPerson(p1);
    printPerson(p2);

    cout << "\nDatabase\n";
    vector<Person> db({ p1, p2, p3 });
    
    for (Person p : db) {
        printPerson(p);
    }

}
//------------------------------------------------------
void printPerson(Person p)
{
    cout << "Name: " << p.name
        << " Email: " << p.email
        << " Age: " << p.age << endl;
}

void printPerson(Person* p)
{
    cout << "Adress: " << p 
        << " Name: " << p->name
        << " Email: " << p->email
        << " Age: " << p->age << endl;
}