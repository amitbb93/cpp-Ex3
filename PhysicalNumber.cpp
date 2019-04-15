//https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=vs-2019
# include <iostream>
# include "PhysicalNumber.h"
# include "Unit.h"
# include <cstdlib>
# include <string>
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
* Copy Construstor
*/
PhysicalNumber::PhysicalNumber(const PhysicalNumber &pn) : PhysicalNumber(pn.value, pn.unit) {}


//// operator "+" ////

/**
* Operator "+" 
*/
PhysicalNumber &PhysicalNumber::operator+()
{
	if(this->value<0)this->value=-this->value;
	return *this;
}
/**
* Operator "+" takes the number and combin them together
* pn - is a const PhysicalNumber
* thisUnit - is the number of the "this" unit
* pnUnit - is the number of the pn unit
* result - is the sum of this value and pn's value
* return a new PhysicalNumber after the calculation
*/
PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& pn) 
{
	int thisUnit = checkUnit(*this);
	int pnUnit = checkUnit(pn);
	if(abs(thisUnit-pnUnit)>2)throw runtime_error("Units do not match");
	double result = value + whichConvert(thisUnit,pnUnit,pn.value);
	return PhysicalNumber(result,unit);
}

/**
* Operator "++" takes the number and rise him up
*/
PhysicalNumber &PhysicalNumber::operator++()
{
    value++;
    return *this;
}

/**
* Operator "++" takes the number and rise him up by specific integer
*/
PhysicalNumber PhysicalNumber::operator++(int number)
{
    PhysicalNumber temp(*this);
    value++;
    return temp;
}
/**
* Operator "+=" takes the number and rise him up by the number himself. it uses the "+" operator above
*/
PhysicalNumber &PhysicalNumber::operator+=(const PhysicalNumber& pn)
{
	PhysicalNumber temp(*this + pn);
    this->value = temp.value;
    return *this;
}

//// operator "-" ////

/**
* Operator "-"
*/
PhysicalNumber &PhysicalNumber::operator-()
{
	this->value = -this->value;
    return *this;
}

/**
* Operator "-" takes the numbers and subtract them 
* pn - is a const PhysicalNumber
* thisUnit - is the number of the "this" unit
* pnUnit - is the number of the pn unit
* result - is the substract between this value and pn's value
* return a new PhysicalNumber after the calculation
*/
PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& pn) 
{
    int thisUnit = checkUnit(*this);
	int pnUnit = checkUnit(pn);
	if(abs(thisUnit-pnUnit)>2)throw runtime_error("Units do not match");
	double result = value - whichConvert(thisUnit,pnUnit,pn.value);
	return PhysicalNumber(result,unit);
}

/**
* Operator "--" decreases the number 
*/
PhysicalNumber &PhysicalNumber::operator--()
{
    value--;
    return *this;
} 

/**
* Operator "--" decreases the number by a specific integer.
*/      
PhysicalNumber PhysicalNumber::operator--(int number)
{
    PhysicalNumber temp(*this);
    value--;
    return temp;
}

/**
* Operator "-=" decreases the number by himself. by using the "-" operator above.
*/ 
PhysicalNumber &PhysicalNumber::operator-=(const PhysicalNumber& pn)
{
    PhysicalNumber temp(*this - pn);
    value = temp.value;
    return *this;
}       
   
   
//// Comparison operators ////

/**
* Operator "=" a boolean operator which return true if the a==b (a and b are PhysicalNumber)
* pn - is a const PhysicalNumber
* thisUnit - is the number of the "this" unit
* pnUnit - is the number of the pn unit
* result - is pn's value by "this" unit
*/ 
bool PhysicalNumber::operator ==(const  PhysicalNumber& pn)
{
    int thisUnit = checkUnit(*this);
	int pnUnit = checkUnit(pn);
	if(abs(thisUnit-pnUnit)>2)throw runtime_error("Units do not match");
    double result = whichConvert(thisUnit,pnUnit,pn.value);
    return this->value == result;
}

/**
* Operator "!=" a boolean operator which return true if the numbers arent equal
* pn - is a const PhysicalNumber
* thisUnit - is the number of the "this" unit
* pnUnit - is the number of the pn unit
* result - is pn's value by "this" unit
*/ 
bool PhysicalNumber::operator !=(const  PhysicalNumber& pn)
{
    int thisUnit = checkUnit(*this);
	int pnUnit = checkUnit(pn);
	if(abs(thisUnit-pnUnit)>2)throw runtime_error("Units do not match");
    double result = whichConvert(thisUnit,pnUnit,pn.value);
    return this->value != result;
}

/**
* Operator "<=" a boolean operator which returns true if a<=b (a and b are PhysicalNumber)
* pn - is a const PhysicalNumber
* thisUnit - is the number of the "this" unit
* pnUnit - is the number of the pn unit
* result - is pn's value by "this" unit
*/ 
bool PhysicalNumber::operator <=(const  PhysicalNumber& pn) 
{
	int thisUnit = checkUnit(*this);
	int pnUnit = checkUnit(pn);
	if(abs(thisUnit-pnUnit)>2)throw runtime_error("Units do not match");
    double result = whichConvert(thisUnit,pnUnit,pn.value);
    return this->value <= result;
}

/**
* Operator ">=" a boolean operator which returns true if a>=b (a and b are PhysicalNumber)
* pn - is a const PhysicalNumber
* thisUnit - is the number of the "this" unit
* pnUnit - is the number of the pn unit
* result - is pn's value by "this" unit
*/ 
bool PhysicalNumber::operator >=(const  PhysicalNumber& pn)
{
	int thisUnit = checkUnit(*this);
	int pnUnit = checkUnit(pn);
	if(abs(thisUnit-pnUnit)>2)throw runtime_error("Units do not match");
    double result = whichConvert(thisUnit,pnUnit,pn.value);
    return this->value >= result;
}

/**
* Operator "<" a boolean operator which returns true if a<b (a and b are PhysicalNumber)
* pn - is a const PhysicalNumber
* thisUnit - is the number of the "this" unit
* pnUnit - is the number of the pn unit
* result - is pn's value by "this" unit
*/ 
bool PhysicalNumber::operator <(const  PhysicalNumber& pn) 
{
    int thisUnit = checkUnit(*this);
	int pnUnit = checkUnit(pn);
	if(abs(thisUnit-pnUnit)>2)throw runtime_error("Units do not match");
    double result = whichConvert(thisUnit,pnUnit,pn.value);
    return this->value < result;
}

/**
* Operator ">" a boolean operator which returns true if a>b (a and b are PhysicalNumber)
* pn - is a const PhysicalNumber
* thisUnit - is the number of the "this" unit
* pnUnit - is the number of the pn unit
* result - is pn's value by "this" unit
*/ 
bool PhysicalNumber::operator >(const  PhysicalNumber& pn)
{
    int thisUnit = checkUnit(*this);
	int pnUnit = checkUnit(pn);
	if(abs(thisUnit-pnUnit)>2)throw runtime_error("Units do not match");
    double result = whichConvert(thisUnit,pnUnit,pn.value);
    return this->value > result;
}       
       
/**
* Operator "<<" pn boolean operator that acts like "cin". it takes the name of the unit from "units" string array 
*/ 
ostream& ariel::operator<<(ostream& os,const PhysicalNumber& pn)
{
	//os.precision(11);
	os << pn.value << "[" << Units[pn.unit] << "]";
    return os;
}

/**
* Operator "<<" pn boolean operator that acts like "cout".
* This function takes the input and convert it to string,split the string by "value" and "unit".
* flag = 1-if the unit exist, 0-unreal unit 
* val = the value of the input converting to double from string 
* str = the full string from is 
* group = the unit of the input before convertion
* un = the unit of the input after convertion
*/ 
istream& ariel::operator>>(istream& is, PhysicalNumber& pn)
{
	int i = 0, j = 0, flag = 0;
	double val = 0;
	Unit un;
	string str, group;
	getline(is,str);
	if(!((str.at(0)>=48)&&(str.at(0)<=57))) return is;
	if(str.at(str.length()-1) != ']') return is;
	while((str.at(i) != '[') && i < str.length()){
		if(((str.at(i)>=48)&&(str.at(i)<=57))||(str.at(i)==46))i++;
		else return is;
	}
	val =  stod(str.substr(0,i),nullptr);
	group = str.substr(i+1,str.length());
	group = group.substr(0,group.length()-1);
	pn.value = val;
	for(j=0; j<=9; j++){
		if(!(group.compare(Units[j]))){
			switch(j){
			case 0: {un = Unit::SEC;flag=1;break;}
			case 1: {un = Unit::MIN;flag=1;break;}
			case 2: {un = Unit::HOUR;flag=1;break;};
			case 3: {un = Unit::CM;flag=1;break;}
			case 4: {un = Unit::M;flag=1;break;}
			case 5: {un = Unit::KM;flag=1;break;}
			case 6: {un = Unit::G;flag=1;break;}
			case 7: {un = Unit::KG;flag=1;break;}
			case 8: {un = Unit::TON;flag=1;break;}
			}
			j=10;
		}
	}
	if(flag==1)pn = PhysicalNumber (val, un);
    return is;
}

/**
* This function returns what unit is the specific PhysicalNumber
* pn - is a const PhysicalNumber
*/
inline int PhysicalNumber::checkUnit(const PhysicalNumber &pn) {
	//SEC,MIN,HOUR,CM,M,KM,G,KG,TON   
   switch (pn.unit)
    {
    case SEC: return 0;
    case MIN: return 1;
	case HOUR: return 2;
    case CM: return 10;
	case M: return 11;
    case KM: return 12;
	case G: return 20;
    case KG: return 21;
	case TON: return 22;
	
	}
}

/**
* This function checks which convertion is needed by units and sent to the currect function 
* thisUnit - is the number of the "this" unit
* pnUnit - is the number of the pn unit
* val - is the value of pn 
*/
inline double PhysicalNumber::whichConvert(int thisUnit, int pnUnit, double val){
	switch(thisUnit){
		case 0: case 1: case 2: return convetSECMINHOUR(thisUnit, pnUnit, val);
		case 10: case 11: case 12: return convetCMMKM(thisUnit, pnUnit, val);
		case 20: case 21: case 22: return convetGKGTON(thisUnit, pnUnit, val);
	}
	return -1;
}

/**
* This function convert to/from SEC/MIN/HOUR 
* thisUnit - is the number of the "this" unit
* pnUnit - is the number of the pn unit
* val - is the value of pn 
*/
inline double PhysicalNumber::convetSECMINHOUR(int thisUnit, int pnUnit, double val) {
	switch(thisUnit){
	case 0:{
		switch(pnUnit){
		case 1: return val*60;
		case 2: return val*3600;
		default: return val;
		}
	}		
	case 1:{
		switch(pnUnit){
		case 0: return val/60;
		case 2: return val*60;
		default: return val;
		}
	}
	case 2:{
		switch(pnUnit){
		case 0: return val/3600;
		case 1: return val/60;
		default: return val;
		}
	}
	}
	return -1;
}

/**
* This function convert to/from CM/M/KM 
* thisUnit - is the number of the "this" unit
* pnUnit - is the number of the pn unit
* val - is the value of pn 
*/
inline double PhysicalNumber::convetCMMKM(int thisUnit, int pnUnit, double val) {
	switch(thisUnit){
	case 10:{
		switch(pnUnit){
		case 11: return val*100;
		case 12: return val*100000;
		default: return val;
		}
	}		
	case 11:{
		switch(pnUnit){
		case 10: return val/100;
		case 12: return val*1000;
		default: return val;
		}
	}
	case 12:{
		switch(pnUnit){
		case 10: return val/100000;
		case 11: return val/1000;
		default: return val;
		}
	}
	}
	return -1;
}

/**
* This function convert to/from G/KG/TON  
* thisUnit - is the number of the "this" unit
* pnUnit - is the number of the pn unit
* val - is the value of pn 
*/
inline double PhysicalNumber::convetGKGTON(int thisUnit, int pnUnit, double val) {
	switch(thisUnit){
	case 20:{
		switch(pnUnit){
		case 21: return val*1000;
		case 22: return val*1000000;
		default: return val;
		}
	}		
	case 21:{
		switch(pnUnit){
		case 20: return val/1000;
		case 22: return val*1000;
		default: return val;
		}
	}
	case 22:{
		switch(pnUnit){
		case 20: return val/1000000;
		case 21: return val/1000;
		default: return val;
		}
	}
	}
	return -1;
}
