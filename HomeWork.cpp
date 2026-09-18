#include <iostream>
#include <fstream>

using namespace std;

class Abonent {
private:
    char* fullName = nullptr;
    char* homePhone = nullptr;
    char* workPhone = nullptr;
    char* mobilePhone = nullptr;
    char* additionalInfo = nullptr;

public:
    Abonent() {
        SetFullName("Unknown");
        SetHomePhone("No phone");
        SetWorkPhone("No phone");
        SetMobilePhone("No phone");
        SetAdditionalInfo("No information");
    }

    Abonent(const char* name, const char* home, const char* work, const char* mobile, const char* info) : fullName(nullptr),
        homePhone(nullptr),
        workPhone(nullptr),
        mobilePhone(nullptr),
        additionalInfo(nullptr)
    {
        SetFullName(name);
        SetHomePhone(home);
        SetWorkPhone(work);
        SetMobilePhone(mobile);
        SetAdditionalInfo(info);
    }

    ~Abonent() {
        delete[] fullName;
        delete[] homePhone;
        delete[] workPhone;
        delete[] mobilePhone;
        delete[] additionalInfo;
    }

    void SetFullName(const char* name) {
        if (fullName != nullptr)
            delete[] fullName;

        fullName = new char[strlen(name) + 1];
        strcpy_s(fullName, strlen(name) + 1, name);
    }

    void SetHomePhone(const char* phone) {
        if (homePhone != nullptr)
            delete[] homePhone;

        homePhone = new char[strlen(phone) + 1];
        strcpy_s(homePhone, strlen(phone) + 1, phone);
    }

    void SetWorkPhone(const char* phone) {
        if (workPhone != nullptr)
            delete[] workPhone;

        workPhone = new char[strlen(phone) + 1];
        strcpy_s(workPhone, strlen(phone) + 1, phone);
    }

    void SetMobilePhone(const char* phone) {
        if (mobilePhone != nullptr)
            delete[] mobilePhone;

        mobilePhone = new char[strlen(phone) + 1];
        strcpy_s(mobilePhone, strlen(phone) + 1, phone);
    }

    void SetAdditionalInfo(const char* info) {
        if (additionalInfo != nullptr)
            delete[] additionalInfo;

        additionalInfo = new char[strlen(info) + 1];
        strcpy_s(additionalInfo, strlen(info) + 1, info);
    }

    const char* GetFullName() {
        return fullName;
    }

    const char* GetHomePhone() {
        return homePhone;
    }

    const char* GetWorkPhone() {
        return workPhone;
    }

    const char* GetMobilePhone() {
        return mobilePhone;
    }

    const char* GetAdditionalInfo() {
        return additionalInfo;
    }

    void ShowInfo() {
        cout << "F.I.O.: " << fullName << endl;
        cout << "Home phone: " << homePhone << endl;
        cout << "Work phone: " << workPhone << endl;
        cout << "Mobile phone: " << mobilePhone << endl;
        cout << "Additional information: " << additionalInfo << endl;
    }

    void SaveToFile(ofstream& file) {
        file << fullName << endl;
        file << homePhone << endl;
        file << workPhone << endl;
        file << mobilePhone << endl;
        file << additionalInfo << endl;
    }

    void LoadFromFile(ifstream& file) {
        char buffer[1000];

        file.getline(buffer, 1000);
        SetFullName(buffer);

        file.getline(buffer, 1000);
        SetHomePhone(buffer);

        file.getline(buffer, 1000);
        SetWorkPhone(buffer);

        file.getline(buffer, 1000);
        SetMobilePhone(buffer);

        file.getline(buffer, 1000);
        SetAdditionalInfo(buffer);
    }
};


class PhoneBook {
private:
    Abonent* abonents = nullptr;
    int abonentsCount = 0;

public:
    PhoneBook() : abonents(nullptr), abonentsCount(0) {
    }

    ~PhoneBook() {
        delete[] abonents;
    }

    void AddAbonent(const char* name, const char* home, const char* work, const char* mobile, const char* info) {
        Abonent* temp = new Abonent[abonentsCount + 1];

        for (int i = 0; i < abonentsCount; i++) {
            temp[i].SetFullName(abonents[i].GetFullName());
            temp[i].SetHomePhone(abonents[i].GetHomePhone());
            temp[i].SetWorkPhone(abonents[i].GetWorkPhone());
            temp[i].SetMobilePhone(abonents[i].GetMobilePhone());
            temp[i].SetAdditionalInfo(abonents[i].GetAdditionalInfo());
        }

        temp[abonentsCount].SetFullName(name);
        temp[abonentsCount].SetHomePhone(home);
        temp[abonentsCount].SetWorkPhone(work);
        temp[abonentsCount].SetMobilePhone(mobile);
        temp[abonentsCount].SetAdditionalInfo(info);

        delete[] abonents;

        abonents = temp;
        abonentsCount++;
    }

    void DeleteAbonent(int number) {
        if (number < 0 || number >= abonentsCount)
            return;

        Abonent* temp = new Abonent[abonentsCount - 1];

        for (int i = 0, j = 0; i < abonentsCount; i++) {
            if (i != number) {
                temp[j].SetFullName(abonents[i].GetFullName());
                temp[j].SetHomePhone(abonents[i].GetHomePhone());
                temp[j].SetWorkPhone(abonents[i].GetWorkPhone());
                temp[j].SetMobilePhone(abonents[i].GetMobilePhone());
                temp[j].SetAdditionalInfo(abonents[i].GetAdditionalInfo());

                j++;
            }
        }

        delete[] abonents;

        abonents = temp;
        abonentsCount--;
    }

    void SearchAbonent(const char* name) {
        bool found = false;

        for (int i = 0; i < abonentsCount; i++) {
            if (strcmp(abonents[i].GetFullName(), name) == 0) {
                cout << "\nAbonent found:\n";
                abonents[i].ShowInfo();
                found = true;
            }
        }

        if (!found)
            cout << "Abonent not found." << endl;
    }

    void ShowAll() {
        if (abonentsCount == 0) {
            cout << "Phone book is empty." << endl;
            return;
        }

        for (int i = 0; i < abonentsCount; i++) {
            cout << "\n------------------------\n";
            cout << "Abonent #" << i + 1 << endl;
            abonents[i].ShowInfo();
        }

        cout << "------------------------\n";
    }

    void SaveToFile(const char* fileName) {
        ofstream file(fileName);

        if (!file) {
            cout << "Error opening file." << endl;
            return;
        }

        file << abonentsCount << endl;

        for (int i = 0; i < abonentsCount; i++) {
            abonents[i].SaveToFile(file);
        }

        file.close();

        cout << "Phone book saved." << endl;
    }

    void LoadFromFile(const char* fileName) {
        ifstream file(fileName);

        if (!file) {
            cout << "Error opening file." << endl;
            return;
        }

        int count;
        file >> count;
        file.ignore();

        delete[] abonents;

        abonents = nullptr;
        abonentsCount = 0;

        for (int i = 0; i < count; i++) {
            Abonent temp;

            temp.LoadFromFile(file);

            AddAbonent(
                temp.GetFullName(),
                temp.GetHomePhone(),
                temp.GetWorkPhone(),
                temp.GetMobilePhone(),
                temp.GetAdditionalInfo()
            );
        }

        file.close();

        cout << "Phone book loaded." << endl;
    }
};


int main() {
    PhoneBook phoneBook;

    phoneBook.AddAbonent(
        "Vadim Kozakow",
        "048-123-45-67",
        "048-222-33-44",
        "067-123-45-67",
        "Friend"
    );

    phoneBook.AddAbonent(
        "Ivan Petrenko",
        "048-555-11-22",
        "048-555-33-44",
        "093-555-66-77",
        "Work colleague"
    );

    phoneBook.AddAbonent(
        "Anna C++",
        "048-777-11-22",
        "048-777-33-44",
        "050-777-66-88",
        "University"
    );

    phoneBook.ShowAll();

    cout << "\nSearch:\n";
    phoneBook.SearchAbonent("Ivan Petrenko");

    cout << "\nAfter delete:\n";
    phoneBook.DeleteAbonent(1);
    phoneBook.ShowAll();

    cout << "\nSave:\n";
    phoneBook.SaveToFile("phonebook.txt");

    cout << "\nLoad:\n";

    PhoneBook newPhoneBook;

    newPhoneBook.LoadFromFile("phonebook.txt");
    newPhoneBook.ShowAll();

}