//https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=vs-2019
# include <iostream>
# include "PhysicalNumber.h"
# include "Unit.h"
using namespace std;
using namespace ariel;

/**
* Construstor
*/
PhysicalNumber::PhysicalNumber(double value,Unit unit)
{
    this->value=value;
    this->unit=unit;
}

/**
* Destrustor
*/
PhysicalNumber::~PhysicalNumber(){}


//// operator "+" ////

/**
* Operator "+" is an Onry number
*/
PhysicalNumber PhysicalNumber::operator+()
{
	return *this;
}
/**
* Operator "+" takes the number and combin them together
*/
PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber pn) 
{
		/*PhysicalNumber temp(*this); 
        temp.value = real + obj.real; 
        temp.imag = imag + obj.imag; 
        return temp; */
		return pn;
}

/**
* Operator "++" takes the number and rise him up
*/
const PhysicalNumber PhysicalNumber::operator++()
{
    value++;
    return *this;
}

/**
* Operator "++" takes the number and rise him up by specific integer
*/
PhysicalNumber PhysicalNumber::operator++(int number)
{
	//PhysicalNumber temp(*this);
    //valuse++;
    //return temp;
    return *this;
}
/**
* Operator "+=" takes the number and rise him up by the number himself 
*/
const PhysicalNumber PhysicalNumber::operator+=(const PhysicalNumber pn)
{
    return pn;
}

//// operator "-" ////

/**
* Operator "-" is an Onry number
*/
PhysicalNumber PhysicalNumber::operator-()
{
    return *this;
}

/**
* Operator "-" takes the numbers and subtract them 
*/
PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber pn) 
{
    return pn;
}

/**
* Operator "--" decreases the number 
*/
 const PhysicalNumber PhysicalNumber::operator--()
{
    value--;
    return *this;
} 

/**
* Operator "--" decreases the number by a specific integer
*/      
PhysicalNumber PhysicalNumber::operator--(int number)
{
    //PhysicalNumber temp(*this);
    //value--;
    //return temp;
    return *this;
}

/**
* Operator "-=" decreases the number by himself
*/ 
const PhysicalNumber PhysicalNumber::operator-=(const PhysicalNumber pn)
{
    return pn;
}       
   
   
//// Comparison operators ////

/**
* Operator "=" equalization operator
*/ 
const PhysicalNumber PhysicalNumber::operator=(const PhysicalNumber pn) 
{
    return pn;
}

/**
* Operator "=" a boolean operator which return true if the a==b (a and b are PhysicalNumber)
*/ 
bool PhysicalNumber::operator ==(const  PhysicalNumber  pn) 
{
    return true;
}

/**
* Operator "!=" a boolean operator which return true if the numbers arent equal
*/ 
bool PhysicalNumber::operator !=(const  PhysicalNumber  pn)
{
    return true;
}

/**
* Operator "<=" a boolean operator which returns true if a<=b (a and b are PhysicalNumber)
*/ 
bool PhysicalNumber::operator <=(const  PhysicalNumber  pn) 
{
	return true;
}

/**
* Operator ">=" a boolean operator which returns true if a>=b (a and b are PhysicalNumber)
*/ 
bool PhysicalNumber::operator >=(const  PhysicalNumber  pn)
{
	return true;
}

/**
* Operator "<" a boolean operator which returns true if a<b (a and b are PhysicalNumber)
*/ 
bool PhysicalNumber::operator <(const  PhysicalNumber  pn) 
{
    return true;
}

/**
* Operator ">" a boolean operator which returns true if a>b (a and b are PhysicalNumber)
*/ 
bool PhysicalNumber::operator >(const  PhysicalNumber  pn)
{
    return true;
}       
       
/**
* Operator "<<" a boolean operator that acts like "cin"
*/ 
ostream& ariel::operator<<(ostream& os, const PhysicalNumber& pn)
{
    return os;
}

/**
* Operator "<<" a boolean operator that acts like "cout"
*/ 
istream& ariel::operator>>(istream& is, PhysicalNumber& pn)
{
	return is;
}      