/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);

    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
	.CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]");

    // YOUR TESTS - INSERT AS MANY AS YOU WANT
	
	PhysicalNumber e(0, Unit::G);
    PhysicalNumber f(100, Unit::KG);
	
	
	testcase
    .setname("More basic output")
	.CHECK_OUTPUT(e, "0[g]")
    .CHECK_OUTPUT(f, "100[kg]")
	
	.setname("More compatible dimensions")
    .CHECK_OUTPUT(e+f, "1000[g]")
    .CHECK_OUTPUT((e+=f), "1000[g]")
    .CHECK_OUTPUT(e, "1000[g]")
    .CHECK_OUTPUT(f+f, "200[kg]")
    .CHECK_OUTPUT(f-f, "0[kg]")
    .CHECK_OUTPUT(f, "100[kg]")

	.setname("More incompatible dimensions")
    .CHECK_THROWS(PhysicalNumber g(30, Unit::MIN))
	.CHECK_THROWS(e+a)
    .CHECK_THROWS(e+b)
    .CHECK_THROWS(f+c)
    .CHECK_THROWS(f+d)
	
	.setname("More basic input")
    .CHECK_OK(istringstream("1000[g]") >> e)
    .CHECK_OUTPUT((f += PhysicalNumber(100, Unit::G)), "100.1[kg]")
	
    .print(cout, /*show_grade=*/false);
    grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
	
	/*
	- בדיקות של יחידה עם אותה יחידה ועם יחידות שונות
	-בדיקות קלטים גבוהים אולי לעבור ל )UNSIGH)
	- בדיקות על הכנסת מספר שלילי
	- בדיקות על הכנסת מספר שלילי
	*/
}
