#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "hwlib.hpp"

#include "verzameling.hpp"

TEST_CASE("Print de verzameling naar de terminal") {
	verzameling a;
	std::stringstream s;
	s << a;
	REQUIRE(s.str() == "");
}

TEST_CASE("Add getallen; standaard toevoegen") {
	verzameling a;
	a.add(2);
	a.add(5);
	a.add(7);
	std::stringstream s;
	s << a;
	REQUIRE(s.str() == "2,5,7");
}

TEST_CASE("Add getallen; al bestaande waarden") {
	verzameling a;
	a.add(2);
	a.add(5);
	a.add(2);
	std::stringstream s;
	s << a;
	REQUIRE(s.str() == "2,5");
}

TEST_CASE("remove getallen; bestaande waarden") {
	verzameling a;
	a.add(2);
	a.add(5);
	a.add(7);
	a.remove(5);
	std::stringstream s;
	s << a;
	REQUIRE(s.str() == "2,7");
}

TEST_CASE("remove getallen; niet bestaande waarden") {
	verzameling a;
	a.add(2);
	a.add(5);
	a.add(7);
	a.remove(3);
	std::stringstream s;
	s << a;
	REQUIRE(s.str() == "2,5,7");
}

TEST_CASE("contains getallen; bestaande waarden") {
	verzameling a;
	a.add(2);
	a.add(5);
	a.add(7);
	bool f = a.contains(5);
	REQUIRE(f);
}

TEST_CASE("contains getallen; niet bestaande waarden") {
	verzameling a;
	a.add(2);
	a.add(5);
	a.add(7);
	bool f = a.contains(3);
	REQUIRE(!f);
}