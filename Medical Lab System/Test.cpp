#include "Test.h"
template<typename T>
Test<T>::Test()
: testId(0), testName(""), testCost(0.0)
{
  // empty here, setting the default in the constructor
}

/////////////////////////////

template<typename T>
Test<T>::Test(const T& id, const string& name, const double& cost)
: testId(id), testName(name), testCost(cost)
{

}
/////////////////////////////

template<typename T>
Test<T>::Test(const Test& deepCopyTest)
: testId(deepCopyTest.testId), testName(deepCopyTest.testName), testCost(deepCopyTest.testCost)
{

}

/////////////////////////////

template<typename T>
void Test<T>::setTestID(const T& testId)
{
  this->testId = testId;
}

/////////////////////////////
template<typename T>
T Test<T>::getTestId() const
{
  return testId;
}

/////////////////////////////
template<typename T>
void Test<T>::setTestName(const string& testName)
{
  this->testName = testName;
}

/////////////////////////////
template<typename T>
string Test<T>::getTestName() const
{
  return testName;
}

/////////////////////////////
template<typename T>
void Test<T>::setTestCost(const double& testCost)
{
 this->testCost = testCost;
}

/////////////////////////////
template<typename T>
double Test<T>::getTestCost() const
{
  return testCost;
}

/////////////////////////////
template<typename T>
int Test<T>::IDChecker(int& id)
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
template<typename T>
string Test<T>::NameChecker(string& name)
{
  while (name.empty() || !std::all_of(name.begin(), name.end(), [](char c){return std::isalpha(c) || std::isspace(c);}))
  {
   cout << "Invalid name. Only letters and spaces are allowed. Try again: ";
   std::getline(cin, name);
  }
 return name;
}

/////////////////////////////
template<typename T>
double Test<T>::priceCheck(double& price)
{
  // Validates the input
  while((price < 0.00) || (price > 10000.00) || cin.fail())
  {
    cin.clear();//clears the last input to avoid it repeating
    cin.ignore(numeric_limits <streamsize> ::max(), '\n');//ignores anything that isnt a number
    cout << "Price needs to be in the form of an 00.00, Try again" << endl;
    cin >> price;
  }
 return price;
}

/////////////////////////////
template<typename T>
istream &operator>> (istream &input, Test<T>& test_input)
{
  string test_name;
  T test_id;
  double test_cost;

  std::cout << "Please enter Test ID: ";
  input >> test_id;
  test_id = test_input.IDChecker(test_id);


  std::cout << "\nPlease enter Test Name: ";
  input >> test_name;
  test_name = test_input.NameChecker(test_name);

  std::cout << "\nPlease enter Test Cost: ";
  input >> test_cost;
  test_cost = test_input.priceCheck(test_cost);

  test_input.setTestID(test_id);
  test_input.setTestName(test_name);
  test_input.setTestCost(test_cost);

 return input;
}

/////////////////////////////
template<typename T>
ostream &operator<< (ostream &output, const Test<T>& test_output)
{
  output << "Test ID: " << test_output.getTestId()
	 << ", Test Name: " << test_output.getTestName()
	 << ", Test Cost: $" << test_output.getTestCost() << endl;
 return output;
}
