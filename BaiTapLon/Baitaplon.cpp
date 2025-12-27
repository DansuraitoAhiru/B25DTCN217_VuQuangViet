#include <iostream> // Thu vien nhap xuat (cin, cout)
#include <vector>     // Thu vien vector (mang dong)
#include <string>     // Thu vien string

using namespace std;


//   Lop cha, dung cho ke thua va sa hinh
class Manager {
public:
    virtual void display() = 0;
    virtual void add() = 0;
    virtual void remove() = 0;
    virtual void update() = 0;
};

// Nhap chuoi bat buoc khong duoc rong hoac toan dau cach
void inputNotEmpty(string &s, string message) {
    bool onlySpace;

    do {
        cout << message;
        getline(cin, s); // getline de nhan ca dong (ke ca space)

        // Kiem tra chuoi co chi toan dau cach hay khong
        onlySpace = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                onlySpace = false;
                break;
            }
        }

        if (s.length() == 0 || onlySpace) {
            cout << "LOI: Khong duoc de trong hoac chi nhap dau cach!\n";
        }

    } while (s.length() == 0 || onlySpace);
}

// Kiem tra chuoi chi chua so
bool isNumber(string s) {
    if (s.length() == 0) return false;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

// Kiem tra ngay sinh dd/MM/yyyy
bool isValidDate(string s) {
    if (s.length() != 10) return false;  // Do dai phai la 10
    if (s[2] != '/' || s[5] != '/') return false;  // Vi tri bat buoc la dau '/'

    for (int i = 0; i < s.length(); i++) {
        if (i == 2 || i == 5) continue;
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}


//   quan ly lop hoc, dung ke thua manager
class ClassRoomManager : public Manager {
private:
    struct ClassRoom {
        string id; // ma lop
        string name;    // ten lop
        string major;   // chuyen nganh
        string type;    // CNTT / Ngoai ngu
    };

    vector<ClassRoom> list;     // Vector chua danh sach lop hoc

public:
    void display() {
        if (list.empty()) {
            cout << "Danh sach lop trong!\n";
            return;
        }

        for (int i = 0; i < list.size(); i++) {  // Duyet tung lop trong vector
            cout << list[i].id << " | "
                 << list[i].name << " | "
                 << list[i].major << " | "
                 << list[i].type << endl;
        }
    }

    void add() {
        ClassRoom c;  // Tao bien lop tam


        inputNotEmpty(c.id, "Nhap ma lop: ");
        inputNotEmpty(c.name, "Nhap ten lop: ");
        inputNotEmpty(c.major, "Nhap chuyen nganh: ");

        do {
            cout << "Nhap phan loai (CNTT / Ngoai ngu): ";
            getline(cin, c.type);

            if (c.type.length() == 0)
                cout << "LOI: Khong duoc de trong!\n";
            else if (c.type != "CNTT" && c.type != "Ngoai ngu")
                cout << "LOI: Chi duoc nhap CNTT hoac Ngoai ngu!\n";

        } while (c.type.length() == 0 ||
                (c.type != "CNTT" && c.type != "Ngoai ngu"));

        list.push_back(c);  // Dua lop vao vector
        cout << "Them lop thanh cong!\n";
    }

    void remove() {
        string id;
        inputNotEmpty(id, "Nhap ma lop can xoa: ");

        for (int i = 0; i < list.size(); i++) {
            if (list[i].id == id) {
                list.erase(list.begin() + i); // Xoa lop
                cout << "Xoa lop thanh cong!\n";
                return;
            }
        }
        cout << "Khong tim thay lop!\n";
    }

    void update() {
    string id;
    inputNotEmpty(id, "Nhap ma lop can cap nhat: ");

    for (int i = 0; i < list.size(); i++) {
        if (list[i].id == id) {

            cout << "Nhap lai thong tin lop:\n";

            inputNotEmpty(list[i].name, "Nhap ten lop moi: ");
            inputNotEmpty(list[i].major, "Nhap chuyen nganh moi: ");

            do {
                cout << "Nhap phan loai (CNTT / Ngoai ngu): ";
                getline(cin, list[i].type);

                if (list[i].type.length() == 0)
                    cout << "Khong duoc de trong!\n";
                else if (list[i].type != "CNTT" && list[i].type != "Ngoai ngu")
                    cout << "Chi duoc nhap CNTT hoac Ngoai ngu!\n";

            } while (list[i].type.length() == 0 ||
                    (list[i].type != "CNTT" && list[i].type != "Ngoai ngu"));

            cout << "Cap nhat lop thanh cong!\n";
            return;
        }
    }

    cout << "Khong tim thay lop!\n";
    }
};


//   Quan ly sinh vien, dung ke thua manager
class StudentManager : public Manager {
private:
    struct Student {
        string id;
        string name;
        string birth;
        string email;
        string phone;
    };

    vector<Student> list;

public:
    void display() {
        if (list.empty()) {
            cout << "Danh sach sinh vien trong!\n";
            return;
        }

        for (int i = 0; i < list.size(); i++) {
            cout << list[i].id << " | "
                 << list[i].name << " | "
                 << list[i].birth << " | "
                 << list[i].email << " | "
                 << list[i].phone << endl;
        }
    }

    void add() {
        Student s;

        inputNotEmpty(s.id, "Nhap ma sinh vien: ");
        inputNotEmpty(s.name, "Nhap ten sinh vien: ");

        do {
            cout << "Nhap ngay sinh (dd/MM/yyyy): ";
            getline(cin, s.birth);

            if (s.birth.length() == 0)
                cout << "LOI: Khong duoc de trong!\n";
            else if (!isValidDate(s.birth))
                cout << "LOI: Sai dinh dang dd/MM/yyyy!\n";

        } while (s.birth.length() == 0 || !isValidDate(s.birth));

        inputNotEmpty(s.email, "Nhap email: ");

        do {
            cout << "Nhap so dien thoai: ";
            getline(cin, s.phone);

            if (s.phone.length() == 0)
                cout << "LOI: Khong duoc de trong!\n";
            else if (!isNumber(s.phone))
                cout << "LOI: So dien thoai chi duoc chua so!\n";

        } while (s.phone.length() == 0 || !isNumber(s.phone));

        list.push_back(s);
        cout << "Them sinh vien thanh cong!\n";
    }

    void remove() {
        string id;
        inputNotEmpty(id, "Nhap ma sinh vien can xoa: ");

        for (int i = 0; i < list.size(); i++) {
            if (list[i].id == id) {
                list.erase(list.begin() + i);
                cout << "Xoa sinh vien thanh cong!\n";
                return;
            }
        }
        cout << "Khong tim thay sinh vien!\n";
    }

    void update() {
    string id;
    inputNotEmpty(id, "Nhap ma sinh vien can cap nhat: ");

    for (int i = 0; i < list.size(); i++) {
        if (list[i].id == id) {

            cout << "Nhap lai thong tin sinh vien:\n";

            inputNotEmpty(list[i].name, "Nhap ten moi: ");

            do {
                cout << "Nhap ngay sinh moi (dd/MM/yyyy): ";
                getline(cin, list[i].birth);

                if (list[i].birth.length() == 0)
                    cout << "Khong duoc de trong!\n";
                else if (!isValidDate(list[i].birth))
                    cout << "Sai dinh dang dd/MM/yyyy!\n";

            } while (list[i].birth.length() == 0 || !isValidDate(list[i].birth));

            inputNotEmpty(list[i].email, "Nhap email moi: ");

            do {
                cout << "Nhap so dien thoai moi: ";
                getline(cin, list[i].phone);

                if (list[i].phone.length() == 0)
                    cout << "Khong duoc de trong!\n";
                else if (!isNumber(list[i].phone))
                    cout << "So dien thoai chi chua so!\n";

            } while (list[i].phone.length() == 0 || !isNumber(list[i].phone));

            cout << "Cap nhat sinh vien thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay sinh vien!\n";
    }
};

int main() {
    ClassRoomManager classMng; // doi tuong quan ly lop
    StudentManager studentMng;   // doi tuong quan ly sinh vien

    Manager* manager = NULL; // con tro lop cha

    int choice;

    do {
        cout << "\n===== MENU TONG =====\n";
        cout << "1. Quan ly lop hoc\n";
        cout << "2. Quan ly sinh vien\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: manager = &classMng; break;
        case 2: manager = &studentMng; break;
        case 0:
            cout << "Ket thuc chuong trinh!Sayonara!\n";
            return 0;
        default:
            cout << "Lua chon khong hop le!\n";
            continue;
        }

        int choose;
        do {
            cout << "\n1. Hien thi\n2. Them moi\n3. Xoa\n4. Cap nhat\n0. Quay lai\n";
            cout << "Chon: ";
            cin >> choose;
            cin.ignore();

            switch (choose) {
            case 1: manager->display(); break;
            case 2: manager->add(); break;
            case 3: manager->remove(); break;
            case 4: manager->update(); break;
            case 0: break;
            default: cout << "Lua chon khong hop le!\n";
            }
        } while (choose != 0);

    } while (true);
}
