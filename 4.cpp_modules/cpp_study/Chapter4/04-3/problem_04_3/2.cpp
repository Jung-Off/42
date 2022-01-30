#include <iostream>
using namespace std;

namespace COMP_POS
{
    enum
    {
        CLERK,
        SENIOR,
        ASSIST,
        MANAGER
    };

    void ShowPositionInfo(int pos)
    {
        switch (pos)
        {
            case CLERK:
                cout << "사원" << endl;
                break;
            case SENIOR:
                cout << "주임" << endl;
                break;
            case ASSIST:
                cout << "대리" << endl;
                break;
            case MANAGER:
                cout << "과장" << endl;
                break;
        }
    }
}

class NameCard
{
    private:
        char *_name;
        char *_company;
        char *_phone;
        int _rate;
    public:
        NameCard(char *name, char *com, char *num, int rate);
        ~NameCard();
        void ShowNameCardInfo();
};

NameCard::NameCard(char *name, char *com, char *num, int rate)
    :   _rate(rate)
{
    // int n_len = strlen(name) + 1;
    // char *n = new char[n_len];
    // strcpy(n, name);
    // _name = n;

    // int c_len = strlen(com) + 1;
    // char *c = new char[c_len];
    // strcpy(c, com);
    // _company = c;

    // int num_len = strlen(num) + 1;
    // char *nu = new char[num_len];
    // strcpy(nu, num);
    // _phone = nu;

    _name = new char[strlen(name) + 1];
    strcpy(_name, name);

    _company = new char[strlen(com) + 1];
    strcpy(_company, com);

    _phone = new char[strlen(num) + 1];
    strcpy(_phone, num);
}

void NameCard::ShowNameCardInfo()
{
    cout << "이름 : " << _name << endl;
    cout << "회사 : " << _company << endl;
    cout << "전화번호 : " << _phone << endl;
    cout << "직급 : " ; COMP_POS::ShowPositionInfo(_rate);
    cout << endl;
    // if (_rate == 0)
    //     cout << "사원" << endl;
    // else if (_rate == 1)
    //     cout << "주임" << endl;
    // else if (_rate == 2)
    //     cout << "대리" << endl;
    // else
    //     cout << "과장" << endl;
    // cout << endl;
}

NameCard::~NameCard()
{
    std::cout << "delete" << endl;
    delete []_name;
    delete []_company;
    delete []_phone;
}

int main()
{
    NameCard manClerk("Lee", "ABCeng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);

    manClerk.ShowNameCardInfo();
    manSENIOR.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
}