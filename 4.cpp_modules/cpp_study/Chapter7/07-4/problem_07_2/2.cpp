#include <iostream>

class Book
{
    private:
        char *title;
        char *isbn;
        int price;
    public:
    //Book (char *t, char *i, int p)
    //  :   price(p), title(t), isbn(i); 이런식으로 하면 안됨,,,
        Book (char *t, char *i, int p)
            :  price(p)
        {
            title = new char[strlen(t) + 1];
            isbn = new char[strlen(i) + 1];
            strcpy(title, t);
            strcpy(isbn, i);
        }
        void ShowBookInfo()
        {
            std::cout << "제목 : " << title << std::endl; 
            std::cout << "ISBN : " << isbn << std::endl;
            std::cout << "가격 : " << price << std::endl;
        }
        ~Book()
        {
            delete []title;
            delete []isbn;
        }
        
};

class EBook : public Book
{
    private:
        char *DRMKey;
    public:
        EBook(char *title, char *isbn, int p, char *drm)
            : Book(title, isbn, p)
        {
            DRMKey = new char[strlen(drm) + 1];
            strcpy(DRMKey, drm);
        }
        void ShowEBookInfo()
        {
            ShowBookInfo();
            std::cout << "인증키 : " << DRMKey << std::endl;
        }
        ~EBook()
        {
            delete[] DRMKey;
        }
};

int main()
{
    Book book("좋은 c++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    std::cout << std::endl;

    EBook ebook("좋은 c++ ebook", "555-12345-890-1", 10000, "fdx9wfdsagaw");
    ebook.ShowEBookInfo();
    return 0;
}