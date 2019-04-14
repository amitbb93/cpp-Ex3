

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

    //YOUR TESTS - INSERT AS MANY AS YOU WANT
	
	PhysicalNumber aa(60, Unit::SEC);
    PhysicalNumber bb(1, Unit::MIN);
	PhysicalNumber cc(2, Unit::HOUR);
    PhysicalNumber dd(100, Unit::CM);
	PhysicalNumber ee(1000, Unit::M);
    PhysicalNumber ff(0.1, Unit::KM);
	PhysicalNumber gg(0, Unit::G);
    PhysicalNumber hh(1, Unit::KG);
	PhysicalNumber ii(2, Unit::TON);
    PhysicalNumber jj(-1, Unit::TON);
	
	//check basic output 
	testcase
    .setname("Our basic output")
    .CHECK_OUTPUT(aa, "60[sec]")
    .CHECK_OUTPUT(bb, "1[min]")
	.CHECK_OUTPUT(ff, "0.1[km]")
    .CHECK_OUTPUT(gg, "0[g]")
	.CHECK_OUTPUT(jj, "-1[ton]")
	
	//check the operators 
	.setname("Our compatible dimensions")
    .CHECK_OUTPUT(aa+bb, "120[sec]")
	.CHECK_OUTPUT(aa-cc, "-7140[sec]")
	.CHECK_OUTPUT((bb+=cc), "121[min]")
	.CHECK_OUTPUT((bb-=bb), "0[min]")
	.CHECK_OUTPUT(cc++, "2[hour]")
	.CHECK_OUTPUT(++bb, "1[min]")
	.CHECK_OUTPUT(aa--, "60[sec]")
	.CHECK_OUTPUT(--cc, "2[hour]")
	.CHECK_OUTPUT(dd+ff, "10100[cm]")
	.CHECK_OUTPUT(ee-ff, "900[m]")
	.CHECK_OUTPUT((ee+=ee), "2000[m]")
	.CHECK_OUTPUT((ee-=ff), "1900[m]")
	.CHECK_OUTPUT(dd++, "100[cm]")
	.CHECK_OUTPUT(++ee, "1901[m]")
	.CHECK_OUTPUT(ff--, "0.1[km]")
	.CHECK_OUTPUT(--dd, "100[cm]")
	.CHECK_OUTPUT(gg+hh, "1000[g]")
	.CHECK_OUTPUT(hh-hh, "0[kg]")
	.CHECK_OUTPUT((ii+=jj), "1[ton]")
	.CHECK_OUTPUT((gg-=ii), "-1e+06[g]")
	.CHECK_OUTPUT(gg++, "-1e+06[g]")
	.CHECK_OUTPUT(++ii, "2[ton]")
	.CHECK_OUTPUT(gg--, "-999999[g]")
	.CHECK_OUTPUT(--gg, "-1e+06[g]")
	
	// check Comparison operators
	.CHECK_EQUAL(aa != bb, true)
	.CHECK_EQUAL(bb < cc, true)
	.CHECK_EQUAL(dd > ee, false)
	.CHECK_EQUAL(ff >= ff, true)
	.CHECK_EQUAL(gg != hh, true)
	.CHECK_EQUAL(hh < ii, true)
	.CHECK_EQUAL(ii > gg, true)
	.CHECK_EQUAL(aa >= cc, false)
	.CHECK_EQUAL(ee == ff, false)
	.CHECK_EQUAL(aa == aa, true)
	
	//check the exceptions which causes by calcuate different unit group
	.setname("Our incompatible dimensions")
	.CHECK_THROWS(aa+dd)
    .CHECK_THROWS(bb-ee)
    .CHECK_THROWS(cc+=ff)
	.CHECK_THROWS(aa-=gg)
    .CHECK_THROWS(ee>hh)
    .CHECK_THROWS(ff<ii)
	.CHECK_THROWS(bb>=ii)
    .CHECK_THROWS(gg<dd)
    .CHECK_THROWS(cc==gg)
	.CHECK_THROWS(ee!=aa)	
	
	//check input operator
	.setname("Our basic input")
    .CHECK_OK(istringstream("1000[g]") >> jj)
    .CHECK_OUTPUT((jj += PhysicalNumber(100, Unit::G)), "1100[g]")
	.CHECK_OK(istringstream("100[hour]") >> aa)
    .CHECK_OUTPUT((aa -= PhysicalNumber(500, Unit::SEC)), "99.8611[hour]")
	.CHECK_OK(istringstream("1000[cm]") >> dd)
    .CHECK_OUTPUT((dd + PhysicalNumber(16, Unit::M)), "2600[cm]");
	
	//////////////////////////////
	
	PhysicalNumber e(0, Unit::G);
    PhysicalNumber f(100, Unit::KG);
	
	testcase
    .setname("More basic output")
	.CHECK_OUTPUT(e, "0[g]")
    .CHECK_OUTPUT(f, "100[kg]")
	
	.CHECK_EQUAL(e != f, true)
	.CHECK_EQUAL(e < f, true)
	.CHECK_EQUAL(e > f, false)
	.CHECK_EQUAL(e >= f, false)

	.setname("More compatible dimensions")
    .CHECK_OUTPUT(e+f, "100000[g]")
    .CHECK_OUTPUT((e+=f), "100000[g]")
    .CHECK_OUTPUT(e, "100000[g]")
    .CHECK_OUTPUT(f+f, "200[kg]")
    .CHECK_OUTPUT(f-f, "0[kg]")
    .CHECK_OUTPUT(f, "100[kg]")
	
	.CHECK_EQUAL(e == f, true)
	.CHECK_EQUAL(e >= f, true)

	.setname("More incompatible dimensions")
    .CHECK_OK(PhysicalNumber g(30, Unit::MIN))
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
}
