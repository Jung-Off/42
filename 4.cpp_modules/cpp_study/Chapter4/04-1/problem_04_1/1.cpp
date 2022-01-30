
#include <iostream>
using namespace std;

class FruitSeller
{
    private:
        int APPLE_PRICE;
        int numOfApples;
        int myMoney;
    public:
        void InitMembers(int price, int num, int money)
        {
            APPLE_PRICE = price;
            numOfApples = num;
            myMoney = money;
        }
        int SaleApples(int money)
        {
            if (money < 0)
            {
                std::cout << "적당하지 않은 금액 입력" << std::endl;
                return 0;
            }
            int num = money / APPLE_PRICE;
            numOfApples -= num;
            myMoney += money;
            return num;
        }
        void ShowSalesResult() const
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
        void InitMembers(int money)
        {
            numOfApples = 0;
            myMoney = money;
        }
        bool BuyApples(FruitSeller &seller, int money)
        {
            if (money < 0)
            {
                std::cout << "적당하지 않은 금액 입력" << std::endl;
                return false;
            }
            numOfApples += seller.SaleApples(money);
            myMoney -= money;
            return true;
        }
        void ShowBuyResult() const
        {
            cout << "현재 잔액 : " << myMoney << endl; 
            cout << "사과 개수 : " << numOfApples << endl << endl;;
        }
};

int main()
{
    FruitSeller seller;
    seller.InitMembers(1000, 20, 0);

    FruitBuyer buyer;
    buyer.InitMembers(5000);
    if (buyer.BuyApples(seller, -2000))
        std::cout << "그 돈으로는 살 수 없습니다" << std::endl;

    if(buyer.BuyApples(seller, 2000))
        std::cout << "그 돈으로는 살 수 없습니다" << std::endl;

    cout << "과일 판매자의 현황 " << endl;
    seller.ShowSalesResult();

    cout << "과일 구매자의 현황 " << endl;
    buyer.ShowBuyResult();
}