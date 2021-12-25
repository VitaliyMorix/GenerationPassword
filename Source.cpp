#include<iostream>
#include<ctime>
using namespace std;

int getRandomNumber(const int&, const int&);
void rand_pas(int&);
template <typename T> inline void fun(T& numLoc, const string& str);

int main()
{
    setlocale(LC_ALL, "ASCII");
    while (true)
    {
        int num = 0;
        cout << "Enter number symbols in password: ";
        int valueNumberSim = 0;
        fun(valueNumberSim, "Enter correct number (1-yes, 2-no): ");
        rand_pas(valueNumberSim);

        cout << "\nRepeat? (1-yes, 2-no): ";
        while (true) 
        {
            fun(num, "Enter correct number (1-yes, 2-no): ");
            if (num == 2 || num == 1 ) break;
            cout << "Enter correct number (1-yes, 2-no): ";
        }

        if (num == 2) break;
    }
}

int getRandomNumber(const int& min, const int& max)
// ���������� ��������� ����� ����� ���������� min � max.
// ��������������, ��� ������� srand() ��� ��������
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // ���������� ������������ ��������� ����� � ����� ���������
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void rand_pas(int& valueNumberSim)
//������� ���������� ������
{
    srand(time(0));
    int specialChar[13]{ 33,35,36,37,38,43,45,47,58,59,61,63,64 };      //����������� ������� (��.��� �������� � ������� ASCII)
    char* pas_char = new char[valueNumberSim];      //������ �������� (��� ������)
    int* pas_int = new int[valueNumberSim];     //������ ����� ��������, �������� � ������
    for (int i = 0; i < valueNumberSim; i++) { pas_int[i] = 0; }
    for (int i = 0; i < valueNumberSim; i++)
        //� ����� ���������� ������. ������� ���������� ���� ([1..9],[a..z],[A..Z],[����_�������])
        //����� � ����� ���������� ��������� ������
    {
        int a = 1 + rand() % 4;
        switch (a)
        {
        case 1:
            pas_int[i] = getRandomNumber(48, 57);
            break;
        case 2:
            //pas_int[i] = 65 + rand() % 90;
            pas_int[i] = getRandomNumber(65, 90);
            break;
        case 3:
            //pas_int[i] = 97 + rand() % 122;
            pas_int[i] = getRandomNumber(97, 122);
            break;
        case 4:
            int a = rand() % 12;
            pas_int[i] = specialChar[a];
        }
    }
    cout << "Your password: ";      //����� ������ �� �����
    for (int i = 0; i < valueNumberSim; i++)
    {
        char pas = static_cast<char>(pas_int[i]);
        cout << pas;
    }
    delete[] pas_int;
    delete[] pas_char;
}

template <typename T>
inline void fun(T& numLoc, const string& str)
{
    //if(int num lock)
    while (!(cin >> numLoc))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << str;
    }
}
