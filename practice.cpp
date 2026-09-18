//#include <iostream>
//
//class Student {
//private:
//    char* name = nullptr;
//
//public:
//    Student() {
//        SetName("Unknown");
//    }
//
//    Student(const char* n) {
//        SetName(n);
//    }
//
//    ~Student() {
//        delete[] name;
//    }
//
//    void SetName(const char* n) {
//        if (name != nullptr)
//            delete[] name;
//
//        name = new char[strlen(n) + 1];
//        strcpy_s(name, strlen(n) + 1, n);
//    }
//
//    const char* GetName() {
//        return name;
//    }
//};
//
//
//class Group {
//private:
//    char* groupName = nullptr;
//    Student* students = nullptr;
//    int studentsCount = 0;
//
//public:
//    Group() {
//        SetName("No group");
//    }
//
//    Group(const char* n) {
//        SetName(n);
//    }
//
//    ~Group() {
//        delete[] groupName;
//        delete[] students;
//    }
//
//    void SetName(const char* n) {
//        if (groupName != nullptr)
//            delete[] groupName;
//
//        groupName = new char[strlen(n) + 1];
//        strcpy_s(groupName, strlen(n) + 1, n);
//    }
//
//    const char* GetName() {
//        return groupName;
//    }
//
//    void AddStudent(const char* name) {
//        Student* temp = new Student[studentsCount + 1];
//
//        for (int i = 0; i < studentsCount; i++) {
//            temp[i].SetName(students[i].GetName());
//        }
//
//        temp[studentsCount].SetName(name);
//
//        delete[] students;
//        students = temp;
//
//        studentsCount++;
//    }
//
//    void DeleteStudent(int number) {
//        if (number < 0 || number >= studentsCount)
//            return;
//
//        Student* temp = new Student[studentsCount - 1];
//
//        for (int i = 0, j = 0; i < studentsCount; i++) {
//            if (i != number) {
//                temp[j].SetName(students[i].GetName());
//                j++;
//            }
//        }
//
//        delete[] students;
//        students = temp;
//
//        studentsCount--;
//    }
//
//    void ShowInfo() {
//        std::cout << "Group: " << groupName << std::endl;
//
//        for (int i = 0; i < studentsCount; i++) {
//            std::cout << i + 1 << ". "
//                << students[i].GetName() << std::endl;
//        }
//    }
//};
//
//
//int main() {
//    Group group("P56");
//
//    group.AddStudent("Mr.babuin");
//    group.AddStudent("CoolName");
//    group.AddStudent("koleks");
//
//    group.ShowInfo();
//
//    group.DeleteStudent(1);
//
//    std::cout << "\nAfter delete:\n";
//
//    group.ShowInfo();
//
//}