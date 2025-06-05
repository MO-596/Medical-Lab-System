#include "MedicalLab.h"
template<typename M>
MedicalLab<M>::MedicalLab()
{
  // empty
}

/////////////////////////////
template<typename M>
MedicalLab<M>::MedicalLab(const MedicalLab& deepCopyLab)
: patients(deepCopyLab.patients), tests(deepCopyLab.tests), testAssign(deepCopyLab.testAssign)
{
  // Deeps copy patients
  for (const auto& [id, patient] : deepCopyLab.patients)
  {
    patients[id] = Patient<M>(patient); // Calls the Patient copy constructor
  }

  // Deeps copy tests
  for (const auto& [id, test] : deepCopyLab.tests)
  {
    tests[id] = Test<M>(test); // Calls the Test copy constructor
  }

  // Copy test assignments (pairs one)
  testAssign = deepCopyLab.testAssign; // std::vector handles copying of its elements
}

/////////////////////////////
template<typename M>
void MedicalLab<M>::addTest(Test<M>& test)
{
  if(doesTestExist(test.getTestId()))
  {
    cout << "Error: Test Id " << test.getTestId() << "already exists." << endl;
    return;
  }

  tests[test.getTestId()] = test; // Adds test to the test map
  cout << "Test ID " << test.getTestId() << " added successfully." << endl;
}

/////////////////////////////
template<typename M>
void MedicalLab<M>::addPatient(Patient<M>& patient)
{
  if(doesPatientExist(patient.getPersonID()))
  {
    cout << "Error: Patients Id " << patient.getPersonID() << "already exists." << endl;
    return;
  }

  patients[patient.getPersonID()] = patient; // Adds test to the test map
  cout << "Test ID " << patient.getPersonID() << " added successfully." << endl;
}

/////////////////////////////
template<typename M>
void MedicalLab<M>::assignTestToPatient(const M& patientID, const M& testID)
{
    testAssign.emplace_back(patientID, testID); // Add the assignment to the vector
    cout << "Test Id " << testID << " assigned to Patient Id " << patientID << "." << endl;
}

/////////////////////////////
template<typename M>
void MedicalLab<M>::viewPatientTests(M& patientID) const
{
  // Display patient information
/*
  const auto& patient = patients.at(patientID);
  cout << "Patient Information:\n" << patient << endl;
*/
  // Safely access patient information
  auto patientIt = patients.find(patientID);
  if (patientIt != patients.end())
  {
    const auto& patient = patientIt->second;
    cout << "Patient Information:\n" << patient << endl;
  }
  cout << "<----------------------------------------->" << endl;

  bool foundID = false;
  cout << "Finding Tests for Patient with the ID:" << patientID << endl;

  for(const auto &assign : testAssign)
  {
    if(assign.first == patientID)
    {
      foundID = true;
      const auto &test = tests.at(assign.second); // Fetchs the Test object
      cout << test << endl;
    }

  }

  if(!foundID)
  {
    cout << "No Tests found to Patient with the ID: " << patientID << endl;
  }


}

/////////////////////////////
template<typename M>
void MedicalLab<M>::deletePatient(const M& patientID)
{
  if(!doesPatientExist(patientID))
  {
    cout << "Error: Patients Id " << patientID << " does not exist." << endl;
    return;
  }

  // Removes the patient from the patients map variables
  patients.erase(patientID);

  // Remove all assignments for the patient ID
  testAssign.erase(remove_if(testAssign.begin(), testAssign.end(),[patientID](const pair<M, M> &testAssign)
  {
    return testAssign.first == patientID;
  }),testAssign.end());

  cout << "Patient ID: " << patientID << " and their assignments have been deleted." << endl;
}

/////////////////////////////
template<typename M>
bool MedicalLab<M>::saveDataToFile(const string& filename)
{
  fstream outputFile(filename,ios::out | ios::app);
  if(outputFile.is_open())
  {

   // Saves the patients info
   outputFile << patients.size() << endl; // Number of patients
   for (const auto& [id, patient] : patients)
   {
     outputFile << id << " " << patient.getPersonName() << " " << patient.getAge() << endl;
   }

   // Saves the test info
   outputFile << tests.size() << endl; // Number of tests
   for (const auto& [id, test] : tests)
   {
     outputFile << id << " " << test.getTestName() << " " << test.getTestCost() << endl;
   }

   // Saves the test assignments
   outputFile << testAssign.size() << endl; // Number of assignments
   for (const auto& assignment : testAssign)
   {
       outputFile << assignment.first << " " << assignment.second << endl; // PatientID TestID
   }

   outputFile.close();
   return true;
  }
  else
  {
   cerr << "File couldn't be opened" << endl;
   return false;
  }
}

/////////////////////////////
template<typename M>
bool MedicalLab<M>::loadDataFromFile(const string& filename)
{
  fstream inputFile(filename,ios::in);
  if(inputFile.is_open())
  {
     // Loads Patients info
     size_t patientCount;
     inputFile >> patientCount;

     for(size_t i = 0; i < patientCount; i++)
     {
       M id, age;
       string name;
       inputFile >> id >> name >> age;
       patients[id] = Patient<M>(id,name,age);
     }

    // Loads Test info
    size_t testCount;
    inputFile >> testCount;

    for (size_t i = 0; i < testCount; i++)
    {
       M id;
       string testName;
       double cost;
       inputFile >> id >> testName >> cost;
       tests[id] = Test<M>(id, testName, cost); // Create and add test
     }

    // Loads test assignemnt info
    size_t assignmentCount;
    inputFile >> assignmentCount;

    for (size_t i = 0; i < assignmentCount; i++)
    {
        M patientID, testID;
        inputFile >> patientID >> testID;
        testAssign.emplace_back(patientID, testID); // Adds test assignment
    }
   inputFile.close();
   return true;
  }
  else
  {
   cerr << "File couldn't be opened" << endl;
   return false;
  }

}

/////////////////////////////
template<typename M>
bool MedicalLab<M>::doesPatientExist(const M& patient_id) const
{
  return patients.find(patient_id) != patients.end();
}

/////////////////////////////
template<typename M>
bool MedicalLab<M>::doesTestExist(const M& test_id) const
{
  return tests.find(test_id) != tests.end();
}

/////////////////////////////
