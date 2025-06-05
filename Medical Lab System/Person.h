#ifndef PERSON_H
#define PERSON_H
#include "MenuHeader.h"
template<typename P>
class Person
{
  public:
    Person();
    Person(const Person&);
    Person(const P&, const string&);

    void setPersonName(const string&);
    string getPersonName() const;

    void setPersonID(const P&);
    P getPersonID() const;

  private:
    string name;
    P Id;
};
#endif
