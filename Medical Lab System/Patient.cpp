#include "Patient.h"
template<typename PA>
Patient<PA>::Patient()
:Person<PA>(), Age(0)
{

}

/////////////////////////////
template<typename PA>
Patient<PA>::Patient(const PA& id, const string& name, const PA& age)
:Person<PA>(id,name),Age(age)
{
  // empty
}

/////////////////////////////
template<typename PA>
Patient<PA>::Patient(const Patient& deepCopyPatient)
:Person<PA>(deepCopyPatient), Age(deepCopyPatient.Age)
{
  // empty
}

/////////////////////////////
template<typename PA>
void Patient<PA>::setAge(const PA& Age)
{
  this->Age = Age;
}

/////////////////////////////
template<typename PA>
PA Patient<PA>::getAge() const
{
  return Age;
}

/////////////////////////////
template<typename PA>
int Patient<PA>::IDChecker(int& id)
{
  // Validates the input
  while((id < 1) || (id > 300) || cin.fail())
  {
    cin.clear();//clears the last input to avoid it repeating
    cin.ignore(numeric_limits <streamsize> ::max(), '\n');//ignores anything that isnt a number
    cout << "ID needs to be in the form of an integer, Try again" << endl;
    cin >> id;
  }
 return id;
}

/////////////////////////////
template<typename PA>
string Patient<PA>::NameChecker(string& name)
{
  while (name.empty() || !std::all_of(name.begin(), name.end(), [](char c){return std::isalpha(c) || std::isspace(c);}))
  {
   cout << "Invalid name. Only letters and spaces are allowed. Try again: ";
   std::getline(cin, name);
  }
 return name;
}

/////////////////////////////
template<typename PA>
int Patient<PA>::ageChecker(int& age)
{
  // Validates the input
  while((age < 1) || (age > 115) || cin.fail())
  {
    cin.clear();//clears the last input to avoid it repeating
    cin.ignore(numeric_limits <streamsize> ::max(), '\n');//ignores anything that isnt a number
    cout << "Age needs to be in the form of an integer, Try again" << endl;
    cin >> age;
  }
 return age;
}

/////////////////////////////
template<typename PA>
istream &operator>> (istream &input, Patient<PA>& patient_input)
{
  string name;
  PA id, age;

  std::cout << "Please enter ID Number: ";
  input >> id;
  id = patient_input.IDChecker(id);


  std::cout << "\nPlease enter Patient Name: ";
  input >> name;
  name =  patient_input.NameChecker(name);

  std::cout << "Please enter Patient Age: ";
  input >> age;
  age =  patient_input.ageChecker(age);

  patient_input.setPersonID(id);
  patient_input.setPersonName(name);
  patient_input.setAge(age);

  return input;
}

/////////////////////////////
template<typename PA>
ostream &operator<< (ostream &output, const Patient<PA>& patient_output)
{
  output << "Patient ID: " << patient_output.getPersonID()
         << ", Patient Name: " << patient_output.getPersonName()
         << ", Patient Age: " << patient_output.getAge() << endl;
 return output;
}
