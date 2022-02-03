#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

class Animal
{
    char id[6];
    char name[20];
    int lifeTime;
    int isKingdom;
    char species[30];
    char characteristic[50];

    friend std::ostream &operator<<(std::ostream &out, const Animal &animal);
    friend std::istream &operator>>(std::istream &in, Animal &animal);

public:
    void modifyAnimal()
    {
        cout << "\nAnimal ID: " << id;
        cout << "\nName: ";
        cin.ignore();
        cin.getline(name, 20, '\n');
        cout << "\nAnimal Life Time: ";
        cin >> lifeTime;
        cout << "\nIs Kindom: ";
        cin >> isKingdom;
        cout << "\nSpecific: ";
        cin.ignore();
        cin.getline(species, 30, '\n');
        cout << "\nCharacteristic: ";
        cin.getline(characteristic, 50, '\n');
    }

    char *returnID()
    {
        return id;
    }

    void displayAnimal()
    {
        cout << setw(6) << left << id
             << " | " << setw(20) << left << name
             << " | " << setw(9) << left << lifeTime
             << " | " << setw(10) << left << isKingdom
             << " | " << setw(30) << left << species
             << " | " << setw(50) << left << characteristic
             << " | " << endl;
    }
};

istream &operator>>(istream &in, Animal &animal)
{
    
    cout << "\nNew Animal Entry......\n";
    cout << "\nEnter Animal Id: ";
    in >> animal.id;
    
    cout << "\nName: ";
    in.ignore();
    in.getline(animal.name, 20, '\n');
    cout << "\nAnimal Life Time: ";
    in >> animal.lifeTime;
    cout << "\nIs Kindom: ";
    in >> animal.isKingdom;
    cout << "\nSpecific: ";
    in.ignore();
    in.getline(animal.species, 30, '\n');
    cout << "\nCharacteristic: ";
    in.getline(animal.characteristic, 50, '\n');
    cout << "\n\nAnimal Record Created Successfull..";
    return in;
}

ostream &operator<<(ostream &out, const Animal &animal)
{

    out << "==================================================================================================================================================\n";
    out << setw(6) << left << "Id"
        << " | " << setw(20) << left << "Name"
        << " | " << setw(9) << left << "Life Time"
        << " | " << setw(10) << left << "Is Kingdom"
        << " | " << setw(30) << left << "Species"
        << " | " << setw(50) << left << "Characteristic"
        << " | " << endl;
    out << "==================================================================================================================================================\n";
    string d = animal.isKingdom == 0 ? "No" : "Yes";
    out << setw(6) << left << animal.id
        << " | " << setw(20) << left << animal.name
        << " | " << setw(9) << left << animal.lifeTime
        << " | " << setw(10) << left << d
        << " | " << setw(30) << left << animal.species
        << " | " << setw(50) << left << animal.characteristic
        << " | " << endl;

    return out;
}

fstream fp, fp1;

class VertebrateAnimal : public Animal
{
    Animal animal;

public:
    void writeVertebrateAnimal()
    {
        char ch;
        fp.open("vertebrate.dat", ios::out | ios::app);
        cin >> animal;
        fp.write((char *)&animal, sizeof(Animal));
        fp.close();
    }

    void displayVerebrateSpecificAnimal(char n[])
    {
        cout << "\nAnimal Details....\n";
        int flag = 0;
        fp.open("vertebrate.dat", ios::in);
        while (fp.read((char *)&animal, sizeof(Animal)))
        {
            if (strcmpi(animal.returnID(), n) == 0)
            {
                cout << animal;
                flag = 1;
            }
        }
        fp.close();
        if (flag == 0)
            cout << "\n\nAnimal does not exist.";
    }

    void modifyVerebrateAnimal()
    {
        char n[6];
        int found = 0;
        cout << "\n\n Modify Animal Recorded Section.....";
        cout << "\n\nEnter the animal ID of the Animal: ";
        cin >> n;
        fp.open("vertebrate.dat", ios::out | ios::in);
        while (fp.read((char *)&animal, sizeof(Animal)) && found == 0)
        {
            if (strcmpi(animal.returnID(), n) == 0)
            {
                cout << animal;
                cout << "\nEnter The New Details of Animal\n";
                animal.modifyAnimal();
                long long unsigned int pos = -1 * sizeof(animal);
                fp.seekp(pos, ios::cur);
                fp.write((char *)&animal, sizeof(Animal));
                cout << "\n\n\t Record Updated...";
                found = 1;
            }
        }
        fp.close();
        if (found == 0)
            cout << "\n\nRecord Not Found";
    }

    void deleteVerebrateAnimal()
    {
        char n[6];
        cout << "\n\n\n\tDelete Animal.......";
        cout << "\n\nEnter the Animal ID of the Book you Want ti delete: ";
        cin >> n;
        fp.open("vertebrate.dat", ios::out | ios::in);
        fstream fp2;
        fp2.open("temp.dat", ios::out);
        fp.seekg(0, ios::beg);
        while (fp.read((char *)&animal, sizeof(Animal)))
        {
            if (strcmpi(animal.returnID(), n) != 0)
            {
                fp2.write((char *)&animal, sizeof(Animal));
            }
        }
        fp2.close();
        fp.close();
        remove("vertebrate.dat");
        rename("temp.dat", "vertebrate.dat");
        cout << "\n\n\tRecord Deleted...";
    }

    void displayVerbrateAllAnimal()
    {
        fp.open("vertebrate.dat", ios::in);
        if (!fp)
        {
            cout << "Error !!! File could not be OPEN";
            return;
        }
        cout << "\n\n\t\t Animal List\n\n";
        cout << "==================================================================================================================================================\n";
        cout << setw(6) << left << "Id"
             << " | " << setw(20) << left << "Name"
             << " | " << setw(9) << left << "Life Time"
             << " | " << setw(10) << left << "Is Kingdom"
             << " | " << setw(30) << left << "Species"
             << " | " << setw(50) << left << "Characteristic"
             << " | " << endl;
        cout << "==================================================================================================================================================\n";
        while (fp.read((char *)&animal, sizeof(Animal)))
        {
            animal.displayAnimal();
        }
        fp.close();
    }
};
class InVertebrateAnimal : public Animal
{
    Animal animal;

public:
    void writeInVertebrateAnimal()
    {
        char ch;
        fp.open("invertebrate.dat", ios::out | ios::app);
        cin >> animal;
        fp.write((char *)&animal, sizeof(Animal));
        fp.close();
    }

    void displayInVerebrateSpecificAnimal(char n[])
    {
        cout << "\nAnimal Details....\n";
        int flag = 0;
        fp.open("invertebrate.dat", ios::in);
        while (fp.read((char *)&animal, sizeof(Animal)))
        {
            if (strcmpi(animal.returnID(), n) == 0)
            {
                cout << animal;
                flag = 1;
            }
        }
        fp.close();
        if (flag == 0)
            cout << "\n\nAnimal does not exist.";
    }

    void modifyInVerebrateAnimal()
    {
        char n[6];
        int found = 0;
        cout << "\n\n Modify Animal Recorded Section.....";
        cout << "\n\nEnter the animal ID of the Animal: ";
        cin >> n;
        fp.open("invertebrate.dat", ios::out | ios::in);
        while (fp.read((char *)&animal, sizeof(Animal)) && found == 0)
        {
            if (strcmpi(animal.returnID(), n) == 0)
            {
                cout << animal;
                cout << "\nEnter The New Details of Animal\n";
                animal.modifyAnimal();
                long long unsigned int pos = -1 * sizeof(animal);
                fp.seekp(pos, ios::cur);
                fp.write((char *)&animal, sizeof(Animal));
                cout << "\n\n\t Record Updated...";
                found = 1;
            }
        }
        fp.close();
        if (found == 0)
            cout << "\n\nRecord Not Found";
    }

    void deleteInVerebrateAnimal()
    {
        char n[6];
        cout << "\n\n\n\tDelete Animal.......";
        cout << "\n\nEnter the Animal ID of the Book you Want ti delete: ";
        cin >> n;
        fp.open("invertebrate.dat", ios::out | ios::in);
        fstream fp2;
        fp2.open("temp.dat", ios::out);
        fp.seekg(0, ios::beg);
        while (fp.read((char *)&animal, sizeof(Animal)))
        {
            if (strcmpi(animal.returnID(), n) != 0)
            {
                fp2.write((char *)&animal, sizeof(Animal));
            }
        }
        fp2.close();
        fp.close();
        remove("invertebrate.dat");
        rename("temp.dat", "invertebrate.dat");
        cout << "\n\n\tRecord Deleted...";
    }

    void displayInVerbrateAllAnimal()
    {
        fp.open("invertebrate.dat", ios::in);
        if (!fp)
        {
            cout << "Error !!! File could not be OPEN";
            return;
        }
        cout << "\n\n\t\t Animal List\n\n";
        cout << "==================================================================================================================================================\n";
        cout << setw(6) << left << "Id"
             << " | " << setw(20) << left << "Name"
             << " | " << setw(9) << left << "Life Time"
             << " | " << setw(10) << left << "Is Kingdom"
             << " | " << setw(30) << left << "Species"
             << " | " << setw(50) << left << "Characteristic"
             << " | " << endl;
        cout << "==================================================================================================================================================\n";
        while (fp.read((char *)&animal, sizeof(Animal)))
        {
            animal.displayAnimal();
        }
        fp.close();
    }
};

void intro()
{

    cout << "Animal CLassification" << endl;
    cout << "\n\nMADE BY : Md.Sumon Hossain";
    cout << "\n\nUniversity : Dhaka University & Engineering Technology";
}

void admin_menu_verebrate()
{

    int ch2;
    VertebrateAnimal vertebrateAnimal;

    cout << "\n\n\n\tVertebrate Animal MENU";
    cout << "\n\n\t1.CREATE Animal RECORD";
    cout << "\n\n\t2.DISPLAY ALL Animal RECORD";
    cout << "\n\n\t3.DISPLAY SPECIFIC Animal RECORD ";
    cout << "\n\n\t4.MODIFY Animal RECORD";
    cout << "\n\n\t5.DELETE Animal RECORD";
    cout << "\n\n\t6.BACK TO MAIN MENU";
    cout << "\n\n\tPlease Enter Your Choice (1-6) ";
    cin >> ch2;
    switch (ch2)
    {
    case 1:
        vertebrateAnimal.writeVertebrateAnimal();
        break;
    case 2:
        vertebrateAnimal.displayVerbrateAllAnimal();

        break;
    case 3:
        char id[6];

        cout << "\n\n\tPlease Enter The Animal ID: ";
        cin >> id;
        vertebrateAnimal.displayVerebrateSpecificAnimal(id);
        break;
    case 4:
        vertebrateAnimal.modifyVerebrateAnimal();
        break;
    case 5:
        vertebrateAnimal.deleteVerebrateAnimal();
        break;
    case 6:
        return;
    default:
        cout << "\a";
    }
    admin_menu_verebrate();
}

void admin_menu_inverebrate()
{

    int ch2;
    InVertebrateAnimal inVertebrateAnimal;

    cout << "\n\n\n\tInVertebrate Animal MENU";
    cout << "\n\n\t1.CREATE Animal RECORD";
    cout << "\n\n\t2.DISPLAY ALL Animal RECORD";
    cout << "\n\n\t3.DISPLAY SPECIFIC Animal RECORD ";
    cout << "\n\n\t4.MODIFY Animal RECORD";
    cout << "\n\n\t5.DELETE Animal RECORD";
    cout << "\n\n\t6.BACK TO MAIN MENU";
    cout << "\n\n\tPlease Enter Your Choice (1-6) ";
    cin >> ch2;
    switch (ch2)
    {
    case 1:
        inVertebrateAnimal.writeInVertebrateAnimal();
        break;
    case 2:
        inVertebrateAnimal.displayInVerbrateAllAnimal();

        break;
    case 3:
        char id[6];

        cout << "\n\n\tPlease Enter The Animal ID: ";
        cin >> id;
        inVertebrateAnimal.displayInVerebrateSpecificAnimal(id);
        break;
    case 4:
        inVertebrateAnimal.modifyInVerebrateAnimal();
        break;
    case 5:
        inVertebrateAnimal.deleteInVerebrateAnimal();
        break;
    case 6:
        return;
    default:
        cout << "\a";
    }
    admin_menu_inverebrate();
}

int main()
{
    char ch;
    intro();
    do
    {

        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t01. Verebrate Animal";
        cout << "\n\n\t02. InVerebrate Animal";
        cout << "\n\n\t03. EXIT";
        cout << "\n\n\tPlease Select Your Option (1-3) ";
        ch = getche();
        switch (ch)
        {
        case '1':
            admin_menu_verebrate();
            break;
        case '2':
            admin_menu_inverebrate();
            break;
        case '3':
            exit(0);
        default:
            cout << "\a";
        }
    } while (ch != '3');
    return 0;
}