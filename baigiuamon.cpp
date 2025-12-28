#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Employee {   //class employee Dung de luu thong tin cua 1 nhan vien
private:
    int id;             // Ma nhan vien
    string name;        // Ten nhan vien
    float salary;       // Luong

public:
    Employee() {  // Ham tao khong tham so
        id = 0;
        name = ""; //"" bieu thi chuoi dang rong
        salary = 0;
    }

    Employee(int id, string name, float salary) { // Ham tao co tham so
        this->id = id;
        this->name = name;
        this->salary = salary;
    }

    void input(int id) {
        this->id = id; //nhan ma tu ben ngoai, bat dau tu 3001

        cin.ignore(); // Xoa bo nho dem
        cout << "Nhap ten nhan vien: ";
        getline(cin, name);

        cout << "Nhap luong nhan vien: ";
        cin >> salary;
    }
    
    void printInfo() {
        cout << "ID: " << id
             << " - Ten: " << name
             << " - Luong: " << salary << endl;
    }

    // Ham lay ma nhan vien
    int getId() {
        return id;
    }

    // Ham cap nhat luong
    void setSalary(float salary) {
        this->salary = salary;
    }
};

// Lop employeeManager: Dung de quan ly danh sach nhan vien
class EmployeeManager {     // Lop employeeManager: Dung de quan ly danh sach nhan vien
private:
    vector<Employee> list;  // Danh sach nhan vien
    int nextId;             // Ma nhan vien tu dong tang

public:
    EmployeeManager() {
        nextId = 3001;      // khoi tao ma nhan vien bat dau tu 3001
    }

    void addEmployee() {
        Employee emp;

        emp.input(nextId);  // Goi ham input va truyen ma nhan vien tu dong

        list.push_back(emp);   // Them nhan vien vao danh sach

        nextId++;              // Tang ma nhan vien cho lan them tiep theo

        cout << "Them nhan vien thanh cong!\n";
    }


    void showAll() {
        if (list.empty()) {
            cout << "Danh sach nhan vien rong!\n";
            return;
        }

        cout << "===== DANH SACH NHAN VIEN =====\n";
        for (int i = 0; i < list.size(); i++) {
            list[i].printInfo();
        }
    }

    void updateSalaryById() {
    	if (list.empty()) {
            cout << "Danh sach nhan vien rong!\n";
            return;
        }

        int id;
        float newSalary;
        bool found = false;

        cout << "Nhap ma nhan vien can cap nhat: ";
        cin >> id;

        for (int i = 0; i < list.size(); i++) {   // Duyet danh sach de tim nhan vien
            if (list[i].getId() == id) {
                cout << "Nhap luong moi: ";
                cin >> newSalary;

                list[i].setSalary(newSalary);
                cout << "Cap nhat luong thanh cong!\n";
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Khong tim thay nhan vien co ma: " << id << endl;
        }
    }

    void deleteById() {
    	if (list.empty()) {
            cout << "Danh sach nhan vien rong!\n";
            return;
        }

        int id;
        bool found = false;

        cout << "Nhap ma nhan vien can xoa: ";
        cin >> id;

        for (int i = 0; i < list.size(); i++) {    // Duyet danh sach de tim vi tri can xoa
            if (list[i].getId() == id) {
                list.erase(list.begin() + i);
                cout << "Xoa nhan vien thanh cong!\n";
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Khong tim thay nhan vien co ma: " << id << endl;
        }
    }

    void menu() {
        int choice;

        do {
            cout << "\n--------- MENU --------\n";
            cout << "1. Them nhan vien\n";
            cout << "2. Hien thi danh sach\n";
            cout << "3. Cap nhat luong\n";
            cout << "4. Xoa nhan vien\n";
            cout << "5. Thoat\n";
            cout << "------------------------\n";
            cout << "Nhap lua chon: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addEmployee();
                    break;
                case 2:
                    showAll();
                    break;
                case 3:
                    updateSalaryById();
                    break;
                case 4:
                    deleteById();
                    break;
                case 5:
                    cout << "Thoat chuong trinh!\n";
                    break;
                default:
                    cout << "Lua chon khong hop le! Vui long nhap lai.\n";
            }

        } while (choice != 5);
    }
};

int main() {
    EmployeeManager manager;
    manager.menu();
    return 0;
}
