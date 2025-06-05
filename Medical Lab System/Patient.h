#ifndef PATIENT_H
#define PATIENT_H
#include "Person.h"
template<typename PA>
class Patient:public Person<PA>
{
  public:
    template<typename T>
    friend istream &operator>> (istream &,Patient<T>&);

    template<typename T>
    friend ostream &operator<< (ostream &,const Patient<T>&);

    // Memeber Functions
    Patient();
    Patient(const PA&, const string&, const PA&);
    Patient(const Patient&);

    void setAge(const PA&);
    PA getAge() const;

    // Verifier Functions
    int IDChecker(int&);
    string NameChecker(string&);
    int ageChecker(int&);

  private:
    PA Age;
};
#endif
