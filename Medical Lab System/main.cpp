#include "MedicalLab.cpp"
#include "Test.cpp"
#include "Patient.cpp"
#include "Person.cpp"
//displays
void WelcomeFunction();
void MenuDisplay();

//user input validation
int validInput(int&);
int InputValidation(int&);
bool patientExists(const int&, MedicalLab<int>*);

// user processes
bool process(int, Patient<int>*, Test<int>*, MedicalLab<int>*);

int main()
{
  bool Repeat = true;
  int choice = 0;

  Patient<int> *patient = new Patient<int>();
  Test<int> *test = new Test<int>();
  MedicalLab<int> *med = new MedicalLab<int>();
  WelcomeFunction();
  do
  {
     MenuDisplay();
     cout << "Enter your choice: " << endl;
     cin >> choice;
     choice = validInput(choice);
     Repeat = process(choice, patient, test, med);
  }while(Repeat);

}

///////////////////////////////////////////////////////////////

void WelcomeFunction()
{
        cout << "Welcome to the Medical Lab App" << endl;
        cout << "Here's the Main Menu, please choose one of the following: " << endl;
	cout << "Owned by Melvin" << endl;
}

///////////////////////////////////////////////////////////////

void MenuDisplay()
{
        cout << "\n=============== Medical Lab Management System =============== " << endl;
        cout << "1. Add Test " << endl;
        cout << "2. Add Patient" << endl;
        cout << "3. Assign Test To Patient" << endl;
        cout << "4. View Patient Information" << endl;
        cout << "5. Delete Patient from record" << endl;
        cout << "6. Save data to a file" << endl;
	cout << "7. Load data from file" << endl;
	cout << "8. Exit" << endl;
}

///////////////////////////////////////////////////////////////

int validInput(int& choice)
{
  while((choice < 1) || (choice > 8) || cin.fail())
  {
    cin.clear();//clears the last input to avoid it repeating
    cin.ignore(numeric_limits <streamsize> ::max(), '\n');//ignores anything that isnt a number
    cout << "Invalid Input, Try again" << endl;
    cin >> choice;
  }
  return choice;
}

///////////////////////////////////////////////////////////////

bool process(int choice,Patient<int>* patient, Test<int>* test, MedicalLab<int>* med)
{
  bool Repeat = true;
  enum Choices{
    TEST = 1,PATIENT, ASSIGN, VIEW, DELETE,SAVE,LOAD,EXIT
  };

  switch(choice)
  {
    case TEST:
      cout << "You have chosen to added a new test..." << endl;
      cin >> *test;
      med->addTest(*test);

      cout << "\n";
      break;

    case PATIENT:
      cout << "You have chosen to added a new patient..." << endl;
      cin >> *patient;
      med->addPatient(*patient);

      cout << "\n";
      break;

    case ASSIGN:
      int test_input, patient_input;
      cout << "You have chosen to assign a test to a patient..." << endl;
      cout << "Enter Patient ID: ";

      cin >> patient_input;
      patient_input = InputValidation(patient_input);

      patientExists(patient_input, med);

      // Input Test ID
      cout << "Enter Test ID: ";

      cin >> test_input;
      test_input = InputValidation(test_input);

      if (!med->doesTestExist(test_input))
      {
          cout << "Error: Test ID " << test_input << " does not exist." << endl;
          break;
      }

      // Assign the test to the patient
      med->assignTestToPatient(patient_input, test_input);
      cout << "Test ID " << test_input << " successfully assigned to Patient ID " << patient_input << "." << endl;

      cout << "\n";
      break;

    case VIEW:
      int patient_input_view;
      cout << "You have chosen to view a patient's info..." << endl;
      cout << "Enter Patient ID: ";

      cin >> patient_input_view;
      patient_input_view = InputValidation(patient_input_view);

      patientExists(patient_input_view, med);

      med->viewPatientTests(patient_input_view);

      cout << "\n";
      break;

    case DELETE:
      int patient_input_delete;
      cout << "You have chosen to delete a patient from record..." << endl;
      cout << "Enter Patient ID: ";

      cin >> patient_input_delete;
      patient_input_delete = InputValidation(patient_input_delete);

      patientExists(patient_input_delete, med);

      med->deletePatient(patient_input_delete);

      cout << "\n";
      break;

    case SAVE:
      cout << "You have chosen to save to a file..." << endl;
      med->saveDataToFile("PatientsInfo.txt");

      cout << "\n";
      break;

    case LOAD:
      cout << "You have chosen to load from a file..." << endl;
      med->loadDataFromFile("PatientsInfo.txt");

      cout << "\n";
      break;

    case EXIT:
      cout << "Exiting, Thank you for you for using the app!" << endl;
      cout << "\n------------------------\n";
      Repeat = false;
  }
 return Repeat;
}

////////////////////////////////////

int InputValidation(int& value)
{
 char ch;
  while((cin.fail()) || (value < 1) || (value > 300))
  {
    cin.clear();//clears the last input to avoid it repeating
    cin.ignore(numeric_limits <streamsize> ::max(), '\n');//ignores anything that isnt a number
    cout << "Input needs to be a integer, Try again" << endl;
    cin >> value;
  }
 return value;
}

////////////////////////////////////

bool patientExists(const int& id, MedicalLab<int>* med)
{
  if (!med->doesPatientExist(id))
  {
    cout << "Error: Patient ID " << id << " does not exist." << endl;
    return false; // If patient doesn't exist
  }
 return true; // PAtient exists
}
