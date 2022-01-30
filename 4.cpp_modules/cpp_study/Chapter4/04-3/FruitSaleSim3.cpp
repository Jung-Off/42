#include <iostream>
using namespace std;

class FruitSeller
{
    private:
        const int APPLE_PRICE;
        int numOfApples;
        int myMoney;
    public:
        // void InitMembers(int price, int num, int money)
        // {
        //     APPLE_PRICE = price;
        //     numOfApples = num;
        //     myMoney = money;
        // }
        FruitSeller(int price, int num, int money)
            : APPLE_PRICE(price), numOfApples(num), myMoney(money)
            {}
        // {
        //     APPLE_PRICE = price;
        //     numOfApples = num;
        //     myMoney = money;        
        // }
        int SaleApples(int money)
        {
            int num = money / APPLE_PRICE;
            numOfApples -= num;
            myMoney += money;
            return num;
        }
        void ShowSalesResult()
        {
            cout << "남은 사과 : " << numOfApples << endl;
            cout << "판매 수익 : " << myMoney << endl << endl;
        }
};

class FruitBuyer
{
    private:
        int numOfApples;
        int myMoney;
    public:
        // void InitMembers(int money)
        // {
        //     numOfApples = 0;
        //     myMoney = money;
        // }
        FruitBuyer(int money)
            : numOfApples(0), myMoney(money)
            {}
        // {
        //     numOfApples = 0;
        //     myMoney = money;
        // }
        void BuyApples(FruitSeller &seller, int money)
        {
            numOfApples += seller.SaleApples(money);
            myMoney -= money;
        }
        void ShowBuyResult()
        {
            cout << "현재 잔액 : " << myMoney << endl; 
            cout << "사과 개수 : " << numOfApples << endl << endl;;
        }
};

int main()
{
    FruitSeller seller(1000, 20, 0);

    FruitBuyer buyer(5000);
    buyer.BuyApples(seller, 2000);

    cout << "과일 판매자의 현황 " << endl;
    seller.ShowSalesResult();

    cout << "과일 구매자의 현황 " << endl;
    buyer.ShowBuyResult();
}