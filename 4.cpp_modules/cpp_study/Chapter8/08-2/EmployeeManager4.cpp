#include <iostream>
using namespace std;

class Employee
{
    private:
        char name[100];
    public:
        Employee(char *name)
        {
            strcpy(this->name, name);
        }
        void ShowYourName() const
        {
            cout << "name: " << name  << endl;
        }
        virtual int GetPay() const
        {
            return 0;
        }
        virtual void ShowSalaryInfo() const
        {}
};

class TemporaryWorker : public Employee
{
    private:
        int workTime;   //이 달에 일한 시간의 합
        int payPerHour; //시간당 급여
    public:
        TemporaryWorker(char* name, int pay)
            :   Employee(name), workTime(0), payPerHour(pay)
        {}
        void AddWorkTime(int time)  //일한 시간의 추가
        {
            workTime += time;
        }
        int GetPay() const // 이 달의 급여
        {
            return workTime * payPerHour;
        }
        void ShowSalaryInfo() const
        {
            ShowYourName();
            cout << "salary : " << GetPay() << endl << endl;
        }
};

class PermannentWorker : public Employee
{
    private:
        int salary;     //매달 지불해야 하는 급여액
    public:
        PermannentWorker(char* name, int money)
            : Employee(name), salary(money)
        {}
        int GetPay() const
        {
            return salary;
        }
        void ShowSalaryInfo() const{
            ShowYourName();
            cout << "salary: " << GetPay() << endl << endl;
        }
};

class SalesWorker : public PermannentWorker
{
    private:
        int salesResult;    //월 판매 실적
        double bonusRatio;  //상여금 비율
    public:
        SalesWorker(char *name, int money, double ratio)
            : PermannentWorker(name, money), salesResult(0), bonusRatio(ratio)
        {}
        void AddSaleesResult(int value)
        {
            salesResult += value;
        }
        int GetPay() const
        {
                //permannetWorker의 getPay
            return PermannentWorker::GetPay() + (int)(salesResult * bonusRatio);
        }
        void ShowSalaryInfo() const
        {
            ShowYourName();
            cout << "salary: " << GetPay() << endl << endl; //SalesWorker의 GetPay함수가 호출됨
        }
};

class EmployeeHandler
{
    private:
        Employee* empList[50];
        int empNum;
    public:
        EmployeeHandler() : empNum(0)
        {}
        void AddEmployee(Employee* emp)
        {
            empList[empNum++] = emp;
        }
        void ShowAllSalartInfo() const
        {
            for(int i = 0; i < empNum; i++)
                empList[i]->ShowSalaryInfo();
        }
        void ShowTotalSalary() const
        {
            int sum = 0;
            for (int i = 0; i < empNum; i++)
                sum += empList[i]->GetPay();
            cout << "salary sum: " << sum << endl;
        }
        ~EmployeeHandler()
        {
            for (int i = 0; i < empNum; i++)
                delete empList[i];
        }
};

int main()
{
    //  직원 관리를 목적으로 설계된 컨트롤 클래스의 객체 생성
    EmployeeHandler handler;

    // 정규직 직원 등록
    handler.AddEmployee(new PermannentWorker("Kim", 1000));
    handler.AddEmployee(new PermannentWorker("LEE", 1500));
    
    // 임시직 등록
    TemporaryWorker *alba = new TemporaryWorker("Jung", 700);
    alba->AddWorkTime(5);   //  5시간 일한 결과 등록
    handler.AddEmployee(alba);

    //영업직 등록
    SalesWorker *seller = new SalesWorker("Hong", 1000, 0.1);
    seller->AddSaleesResult(7000); // 영업 실적
    handler.AddEmployee(seller);

    //이번 달에 지불해야 할 급여의 정보
    handler.ShowAllSalartInfo();

    //이번 달에 지불해야 할 급여의 총합
    handler.ShowTotalSalary();
    return 0;
}