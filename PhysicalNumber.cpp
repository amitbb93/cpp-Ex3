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

PhysicalNumber::PhysicalNumber(const PhysicalNumber &pn) : PhysicalNumber(pn.value, pn.unit) {}

/**
* Destrustor
*/
PhysicalNumber::~PhysicalNumber(){}

//// operator "+" ////

/**
* Operator "+" is an Onry number
*/
PhysicalNumber &PhysicalNumber::operator+()
{
	if(this->value<0)this->value=-this->value;
	return *this;
}
/**
* Operator "+" takes the number and combin them together
*/
PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& pn) 
{
	int a = checkUnit(*this);
	int b = checkUnit(pn);
	if(abs(a-b)>2)throw runtime_error("Units do not match");
	double result = value + whichConvert(a,b,pn.value);
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
* Operator "+=" takes the number and rise him up by the number himself 
*/
PhysicalNumber &PhysicalNumber::operator+=(const PhysicalNumber& pn)
{
	PhysicalNumber temp(*this + pn);
    this->value = temp.value;
    return *this;
}

//// operator "-" ////

/**
* Operator "-" is an Onry number
*/
PhysicalNumber &PhysicalNumber::operator-()
{
	this->value = -this->value;
    return *this;
}

/**
* Operator "-" takes the numbers and subtract them 
*/
PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& pn) 
{
    int a = checkUnit(*this);
	int b = checkUnit(pn);
	if(abs(a-b)>2)throw runtime_error("Units do not match");
	double result = value - whichConvert(a,b,pn.value);
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
* Operator "--" decreases the number by a specific integer
*/      
PhysicalNumber PhysicalNumber::operator--(int number)
{
    PhysicalNumber temp(*this);
    value--;
    return temp;
}

/**
* Operator "-=" decreases the number by himself
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
*/ 
bool PhysicalNumber::operator ==(const  PhysicalNumber& pn)
{
    int a = checkUnit(*this);
	int b = checkUnit(pn);
	if(abs(a-b)>2)throw runtime_error("Units do not match");
    double result = whichConvert(a,b,pn.value);
    return this->value == result;
}

/**
* Operator "!=" a boolean operator which return true if the numbers arent equal
*/ 
bool PhysicalNumber::operator !=(const  PhysicalNumber& pn)
{
    int a = checkUnit(*this);
	int b = checkUnit(pn);
	if(abs(a-b)>2)throw runtime_error("Units do not match");
    double result = whichConvert(a,b,pn.value);
    return this->value != result;
}

/**
* Operator "<=" a boolean operator which returns true if a<=b (a and b are PhysicalNumber)
*/ 
bool PhysicalNumber::operator <=(const  PhysicalNumber& pn) 
{
	int a = checkUnit(*this);
	int b = checkUnit(pn);
	if(abs(a-b)>2)throw runtime_error("Units do not match");
    double result = whichConvert(a,b,pn.value);
    return this->value <= result;
}

/**
* Operator ">=" a boolean operator which returns true if a>=b (a and b are PhysicalNumber)
*/ 
bool PhysicalNumber::operator >=(const  PhysicalNumber& pn)
{
	int a = checkUnit(*this);
	int b = checkUnit(pn);
	if(abs(a-b)>2)throw runtime_error("Units do not match");
    double result = whichConvert(a,b,pn.value);
    return this->value >= result;
}

/**
* Operator "<" a boolean operator which returns true if a<b (a and b are PhysicalNumber)
*/ 
bool PhysicalNumber::operator <(const  PhysicalNumber& pn) 
{
    int a = checkUnit(*this);
	int b = checkUnit(pn);
	if(abs(a-b)>2)throw runtime_error("Units do not match");
    double result = whichConvert(a,b,pn.value);
    return this->value < result;
}

/**
* Operator ">" a boolean operator which returns true if a>b (a and b are PhysicalNumber)
*/ 
bool PhysicalNumber::operator >(const  PhysicalNumber& pn)
{
    int a = checkUnit(*this);
	int b = checkUnit(pn);
	if(abs(a-b)>2)throw runtime_error("Units do not match");
    double result = whichConvert(a,b,pn.value);
    return this->value > result;
}       
       
/**
* Operator "<<" pn boolean operator that acts like "cin"
*/ 
ostream& ariel::operator<<(ostream& os,const PhysicalNumber& pn)
{
	os.precision(11);
	os << pn.value << "[" << Units[pn.unit] << "]";
    return os;
}

/**
* Operator "<<" pn boolean operator that acts like "cout"
*/ 
istream& ariel::operator>>(istream& is, PhysicalNumber& pn)
{
	ios::pos_type startPosition = is.tellg();
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
			case 0:{un = Unit::SEC;flag=1;break;}
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

inline double PhysicalNumber::whichConvert(int a, int b, double val){
	switch(a){
		case 0: return convetSECMINHOUR(a, b, val);
		case 1: return convetSECMINHOUR(a, b, val);
		case 2: return convetSECMINHOUR(a, b, val);
		case 10: return convetCMMKM(a, b, val);
		case 11: return convetCMMKM(a, b, val);
		case 12: return convetCMMKM(a, b, val);
		case 20: return convetGKGTON(a, b, val);
		case 21: return convetGKGTON(a, b, val);
		case 22: return convetGKGTON(a, b, val);
	}
	return -1;
}

inline double PhysicalNumber::convetSECMINHOUR(int a, int b, double val) {
	switch(a){
	case 0:{
		switch(b){
		case 1: return val*60;
		case 2: return val*3600;
		default: return val;
		}
	}		
	case 1:{
		switch(b){
		case 0: return val/60;
		case 2: return val*60;
		default: return val;
		}
	}
	case 2:{
		switch(b){
		case 0: return val/3600;
		case 1: return val/60;
		default: return val;
		}
	}
	}
	return -1;
}

inline double PhysicalNumber::convetCMMKM(int a, int b, double val) {
	switch(a){
	case 10:{
		switch(b){
		case 11: return val*100;
		case 12: return val*100000;
		default: return val;
		}
	}		
	case 11:{
		switch(b){
		case 10: return val/100;
		case 12: return val*1000;
		default: return val;
		}
	}
	case 12:{
		switch(b){
		case 10: return val/100000;
		case 11: return val/1000;
		default: return val;
		}
	}
	}
	return -1;
}

inline double PhysicalNumber::convetGKGTON(int a, int b, double val) {
	switch(a){
	case 20:{
		switch(b){
		case 21: return val*1000;
		case 22: return val*1000000;
		default: return val;
		}
	}		
	case 21:{
		switch(b){
		case 20: return val/1000;
		case 22: return val*1000;
		default: return val;
		}
	}
	case 22:{
		switch(b){
		case 20: return val/1000000;
		case 21: return val/1000;
		default: return val;
		}
	}
	}
	return -1;
}
