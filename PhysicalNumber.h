#include <iostream>
#include <string>
#include "Unit.h"
#define size 9
using namespace std;
using std::istream,std::ostream,std::istringstream;
namespace ariel
{
	static string const Units[] = {"sec", "min", "hour", "cm", "m", "km", "g", "kg", "ton"};
	
	class PhysicalNumber
	{
    public:
	Unit unit;
    double value;
	PhysicalNumber(double value,Unit unit);
	PhysicalNumber(const PhysicalNumber &pn);
    
	// operator "+"
	PhysicalNumber& operator+();
	PhysicalNumber operator+(const PhysicalNumber& pn);
    PhysicalNumber& operator++();
	PhysicalNumber operator++(int number);
	PhysicalNumber& operator+=(const PhysicalNumber& pn);

	// operator "-"
	PhysicalNumber& operator-();
	PhysicalNumber operator-(const PhysicalNumber& pn);
	PhysicalNumber& operator--();
	PhysicalNumber operator--(int number);
	PhysicalNumber& operator-=(const PhysicalNumber& pn);
	
	// Comparison operators
	bool operator ==(const  PhysicalNumber&  pn);
    bool operator !=(const  PhysicalNumber&  pn);
    bool operator <=(const  PhysicalNumber&  pn);
    bool operator >=(const  PhysicalNumber&  pn);  
    bool operator <(const  PhysicalNumber&  pn);
    bool operator >(const  PhysicalNumber&  pn);
	
	
	friend ostream& operator<<(ostream& os,const PhysicalNumber& pn);
    friend istream& operator>>(istream& is, PhysicalNumber& pn);
	
	inline int checkUnit(const PhysicalNumber &pn);
	inline double whichConvert(int thisUnit, int pnUnit, double val);
	inline double convetSECMINHOUR(int thisUnit, int pnUnit, double val);
	inline double convetCMMKM(int thisUnit, int pnUnit, double val);
	inline double convetGKGTON(int thisUnit, int pnUnit, double val);
   };
 };