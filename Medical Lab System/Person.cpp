#include "Person.h"
template<typename P>
Person<P>::Person()
: Id(0), name("")
{
  // empty
}

//////////////////////////////////////////

template<typename P>
Person<P>::Person(const P& id, const string& name)
:Id(id), name(name)
{
 // empty
}

//////////////////////////////////////////

template<typename P>
Person<P>::Person(const Person& deepCopyPerson)
:Id(deepCopyPerson.Id), name(deepCopyPerson.name)
{
  //empty
}

//////////////////////////////////////////

template<typename P>
void Person<P>::setPersonName(const string& name)
{
  this->name = name;
}

//////////////////////////////////////////

template<typename P>
string Person<P>::getPersonName() const
{
  return name;
}

//////////////////////////////////////////

template<typename P>
void Person<P>::setPersonID(const P& Id)
{
  this->Id = Id;
}

//////////////////////////////////////////

template<typename P>
P Person<P>::getPersonID() const
{
  return Id;
}
