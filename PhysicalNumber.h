#include <iostream>
#include "Unit.h"
using std::istream,std::ostream,std::istringstream;
namespace ariel
{
	class PhysicalNumber
	{
    public:
	Unit unit;
    double value;
	PhysicalNumber(double value,Unit unit);
    ~PhysicalNumber();
    
	// operator "+"
	PhysicalNumber operator+();
	PhysicalNumber operator+(const PhysicalNumber pn);
    const PhysicalNumber operator++();
	PhysicalNumber operator++(int number);
	const PhysicalNumber operator+=(const PhysicalNumber pn);

	// operator "-"
	PhysicalNumber operator-();
	PhysicalNumber operator-(const PhysicalNumber pn);
	const PhysicalNumber operator--();
	PhysicalNumber operator--(int number);
	const PhysicalNumber operator-=(const PhysicalNumber pn);
	
	// Comparison operators
	const PhysicalNumber operator=(const PhysicalNumber pn); 
	bool operator ==(const  PhysicalNumber  pn);
    bool operator !=(const  PhysicalNumber  pn);
    bool operator <=(const  PhysicalNumber  pn);
    bool operator >=(const  PhysicalNumber  pn);  
    bool operator <(const  PhysicalNumber  pn);
    bool operator >(const  PhysicalNumber  pn);
	
	
	friend ostream& operator<<(ostream& os, const PhysicalNumber& pn);
    friend istream& operator>>(istream& is, PhysicalNumber& pn);
   };
 };