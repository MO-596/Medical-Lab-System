#ifndef MEDICALLAB_H
#define MEDICALLAB_H
#include "Patient.h"
#include "Test.h"
template<typename M>
class MedicalLab
{
  public:
    template<typename T>
    friend ostream &operator<< (ostream &,const MedicalLab<T>&);

    MedicalLab();
    MedicalLab(const MedicalLab&);

    // Memeber Functions
    void addTest(Test<M>&);
    void addPatient(Patient<M>&);
    void assignTestToPatient(const M&, const M&);
    void viewPatientTests(M&) const;
    void deletePatient(const M&);
    bool saveDataToFile(const string&);
    bool loadDataFromFile(const string&);

   // Verifier Functions
    bool doesPatientExist(const M&) const;
    bool doesTestExist(const M&) const;

  private:
    std::map<M, Patient<M>> patients;  // Maps patient ID to Patient objects
    std::map<M, Test<M>> tests;       // Maps test ID to Test objects
    std::vector<std::pair<M,M>> testAssign; // Tracks patient-test assignment

};
#endif
