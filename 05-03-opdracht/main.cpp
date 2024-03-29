#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <string>

#include "verzameling.hpp"

TEST_CASE("Print de lege verzameling naar de terminal") {
	verzameling<10, char> a;
	std::stringstream s;
	s << a;
	REQUIRE(s.str() == "");
}

TEST_CASE("Print de verzameling met chars naar de terminal") {
	verzameling<3, char> a;
	a.add('a');
	a.add('b');
	std::stringstream s;
	s << a;
	REQUIRE(s.str() == "a,b");
}

TEST_CASE("Add getallen; standaard toevoegen") {
	verzameling<3, int> a;
	a.add(2);
	a.add(5);
	a.add(7);
	std::stringstream s;
	s << a;
	REQUIRE(s.str() == "2,5,7");
}

TEST_CASE("Add getallen") {
	verzameling<3, int> a;
	a.add(2);
	a.add(5);
	a.add(2);
	std::stringstream s;
	s << a;
	REQUIRE(s.str() == "2,5");
}

TEST_CASE("remove getallen") {
	verzameling<10, int> a;
	a.add(2);
	a.add(5);
	a.add(7);
	a.remove(5);
	std::stringstream s;
	s << a;
	REQUIRE(s.str() == "2,7");
}

TEST_CASE("remove char") {
	verzameling<10, char> a;
	a.add('a');
	a.add('b');
	a.add('c');
	a.remove('b');
	std::stringstream s;
	s << a;
	REQUIRE(s.str() == "a,c");
}

TEST_CASE("remove niet bestaand getallen") {
	verzameling<10, int> a;
	a.add(2);
	a.add(5);
	a.add(7);
	a.remove(3);
	std::stringstream s;
	s << a;
	REQUIRE(s.str() == "2,5,7");
}

TEST_CASE("check bestaan int") {
	verzameling<10, int> a;
	a.add(2);
	a.add(5);
	a.add(7);
	bool x = a.contains(5);
	REQUIRE(x);
}

TEST_CASE("check bestaan char") {
	verzameling<10, char> a;
	a.add('a');
	a.add('b');
	a.add('c');
	bool x = a.contains('b');
	REQUIRE(x);
}

TEST_CASE("check niet bestaan int") {
	verzameling<10, int> a;
	a.add(2);
	a.add(5);
	a.add(7);
	bool x = a.contains(3);
	REQUIRE(!x);
}

TEST_CASE("max test; ints") {
	verzameling<10, int> a;
	a.add(2);
	a.add(5);
	a.add(7);
	int f = a.max();
	REQUIRE(f == 7);
}

TEST_CASE("max test; chars") {
	verzameling<10, char> a;
	a.add('a');
	a.add('c');
	a.add('b');
	char f = a.max();
	std::stringstream s;
	s << f;
	REQUIRE(s.str() == "c");
}