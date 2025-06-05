#ifndef TEST_H
#define TEST_H
#include "MenuHeader.h"
template<typename T>
class Test
{
  public:
    template<typename O>
    friend istream &operator>> (istream &,Test<O>&);

    template<typename O>
    friend istream &operator<< (istream &, const Test<O>&);

    Test();
    Test(const T&, const string&, const double&);
    Test(const Test&);

    // Memeber Functions
    void setTestID(const T&);
    T getTestId() const;

    void setTestName(const string&);
    string getTestName() const;

    void setTestCost(const double&);
    double getTestCost() const;

    // Verifier Functions
    int IDChecker(int&);
    string NameChecker(string&);
    double priceCheck(double&);

  private:
    T testId;
    string testName;
    double testCost;
};
#endif
