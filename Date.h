
const int SIZE=13;
const int monthArr[SIZE]={0,31,28,31,30,31,30,31,31,30,31,30,31};
class Date{

  private:
    int month;
    int day;
    int year;

  public:

    //constructors
    Date(int=1,int=1,int=1900);

    //destructor
    ~Date(){}

    //functions
    int numberOfDaysLeft();
    int numberOfDaysPassed();
    void incrementDate(int nDays);

    //setters
    void setDate(int,int,int);
    void setMonth(int);
    void setDay(int);
    void setYear(int);
    //getters
    int getMonth() const;
    int getDay()const;
    int getYear()const;
    int getDaysInMonth();

    bool isLeapYear();
};