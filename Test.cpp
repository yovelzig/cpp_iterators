#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <stdexcept>

using namespace ariel;
using namespace std;
// Test case for adding elements to the MagicalContainer

TEST_CASE("Add and remove checks") {
    MagicalContainer container;    
        container.addElement(17);
        CHECK(container.size() == 1);
        container.addElement(2);
        container.addElement(25);
        CHECK(container.size() == 3);
        CHECK_NOTHROW(container.removeElement(17));
        CHECK(container.size() == 2);
        CHECK_THROWS(container.removeElement(25));
        CHECK(container.size() == 1);
}
TEST_CASE("check empty container") {
    MagicalContainer container;
    MagicalContainer container2;
    MagicalContainer container3;
     MagicalContainer::AscendingIterator it(container);
       MagicalContainer::SideCrossIterator it2(container2);
       MagicalContainer::PrimeIterator it3(container3);
         CHECK(it == it.end());
         CHECK(it2 == it2.end());
         CHECK(it3 == it3.end());
}

// Test case for removing elements from the MagicalContainer

TEST_CASE("AscendingIterator") {
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);

        MagicalContainer::AscendingIterator it(container);
        MagicalContainer::AscendingIterator it2(container);
        CHECK((it == it2));
        CHECK_FALSE((it != it2));
        CHECK_FALSE((it > it2));
        CHECK_FALSE((it < it2));
        CHECK(*it == 2);
        ++it;
        CHECK_FALSE((it == it2));
        CHECK((it != it2));
        CHECK((it > it2));
        CHECK_FALSE((it < it2));
        CHECK(*it2 == 2);
        ++it2;
        CHECK((it == it2));
        CHECK_FALSE((it != it2));
        CHECK_FALSE((it > it2));
        CHECK_FALSE((it < it2));
        CHECK(*it == 3);
        ++it;
        CHECK(*it == 9);
        ++it;
        CHECK(*it == 17);
        ++it;
        CHECK(*it == 25);
        ++it;
        CHECK(it == it.end());   
}
 TEST_CASE("SideCrossIterator") {
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
        MagicalContainer::SideCrossIterator it(container);
        MagicalContainer::SideCrossIterator it2(container);
        CHECK((it == it2));
        CHECK_FALSE((it != it2));
        CHECK_FALSE((it > it2));
        CHECK_FALSE((it < it2));
        CHECK(*it == 2);
        ++it;
        CHECK_FALSE((it == it2));
        CHECK((it != it2));
        CHECK((it > it2));
        CHECK_FALSE((it < it2));
        CHECK(*it2 == 2);
        ++it2;
        CHECK((it == it2));
        CHECK_FALSE((it != it2));
        CHECK_FALSE((it > it2));
        CHECK_FALSE((it < it2));
        CHECK(*it == 25);
        ++it;
        CHECK(*it == 3);
        ++it;
        CHECK(*it == 17);
        ++it;
        CHECK(*it == 9);
        ++it;
        CHECK(it == it.end());
    
}

// Test case for the PrimeIterator
TEST_CASE("PrimeIterator") {
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);

    SUBCASE("Iterating over elements") {
        MagicalContainer::PrimeIterator it(container);
        MagicalContainer::PrimeIterator it2(container);
         CHECK((it == it2));
        CHECK_FALSE((it != it2));
        CHECK_FALSE((it > it2));
        CHECK_FALSE((it < it2));
        CHECK(*it == 2);
        ++it;
        CHECK_FALSE((it == it2));
        CHECK((it != it2));
        CHECK((it > it2));
        CHECK_FALSE((it < it2));
        CHECK(*it2 == 2);
        ++it2;
        CHECK((it == it2));
        CHECK_FALSE((it != it2));
        CHECK_FALSE((it > it2));
        CHECK_FALSE((it < it2));
        CHECK(*it == 3);
        ++it;
        CHECK(*it == 17);
        ++it;
        CHECK(it == it.end());
    }
}
TEST_CASE("check empty container") {
    MagicalContainer container;
     MagicalContainer::AscendingIterator it(container);
       MagicalContainer::SideCrossIterator it2(container);
       MagicalContainer::PrimeIterator it3(container);
         CHECK(it == it.end());
         CHECK(it2 == it2.end());
         CHECK(it3 == it3.end());
}
