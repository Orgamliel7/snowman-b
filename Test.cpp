/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
//
// Created by Or Gamliel on 08/03/2021.
//

 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <array>
#include <exception>
using namespace std;





// עכשיו נבדוק מקרים בהם איש השלג יעבוד כמו שצריך
TEST_CASE("some working snowmans string checks")
 {
    CHECK(snowman(11111111)==string(" _===_\n (.,.) \n<( : )>\n ( : ) "));
    CHECK(snowman(22222222)==string("  ---\n .....\n\\(o.o)/\n (] [) \n (\" \") "));
    CHECK(snowman(33333333)==string("   -\n  /_\\\n (O_O) \n/(> <)\\\n (___) "));
    CHECK(snowman(44444444)==string("  ---\n (_*_)\n (- -) \n (   ) \n (   ) "));
    CHECK(snowman(11114411)==string(" _===_\n (.,.) \n ( : ) \n ( : ) ")); // איש שלג קלאסי 
    CHECK(snowman(12344434)==string(" _===_\n (O.-) \n (> <) \n (   ) "));
    CHECK(snowman(12341234)==string(" _===_\n (O.-)/\n<(> <) \n (   ) ")); 
    //CHECK(snowman(33232124)==string(" _\n /_\ \n \(o_O) \n (] [)> \n (   ) ")); // הדוגמא השניה מקובץ הדמו
    CHECK(snowman(11112111)==string(" _===_\n\\(.,.) \n ( : )>\n ( : ) "));
    CHECK(snowman(11113111)==string(" _===_\n (.,.) \n/( : )>\n ( : ) "));
    CHECK(snowman(11114111)==string(" _===_\n (.,.) \n ( : )>\n ( : ) "));
    CHECK(snowman(11111211)==string(" _===_\n (.,.)/\n<( : ) \n ( : ) "));
    
}
// בדיקת אי שיוויון בנוסף
TEST_CASE("some working snowmans string checks - but with slightly wrong output")
 {
    CHECK(snowman(11111111)!=string(" _===_\n (.,.) \n<( : )>\n ( : ) ,"));
    CHECK(snowman(22222222)!=string("  ---\n .....\n\\(o.o)/\n (] [) \n (\" \") ,"));
    CHECK(snowman(33333333)!=string("   -\n  /_\\\n (O_O) \n/(> <)\\\n (___) ,"));
    CHECK(snowman(44444444)!=string("  ---\n (_*_)\n (- -) \n (   ) \n (   ) ,"));
    CHECK(snowman(11114411)!=string(" _===_\n (.,.) \n ( : ) \n ( : ) ,")); // איש שלג קלאסי 
    CHECK(snowman(12344434)!=string(" _===_\n (O.-) \n (> <) \n (   ) ,"));
    CHECK(snowman(12341234)!=string(" _===_\n (O.-)/\n<(> <) \n (   ) ,")); 
    CHECK(snowman(11112111)!=string(" _===_\n\\(.,.) \n ( : )>\n ( : ) ,"));
    CHECK(snowman(11113111)!=string(" _===_\n (.,.) \n/( : )>\n ( : ) ,"));
    CHECK(snowman(11114111)!=string(" _===_\n (.,.) \n ( : )>\n ( : ) ,"));
    CHECK(snowman(11111211)!=string(" _===_\n (.,.)/\n<( : ) \n ( : ),"));
    
}

TEST_CASE(" wrong numbers as input") // מספרים שלא אמורים להניב דבר כי הם לא חלק מתכנית ההדפסה
{
    CHECK_THROWS(snowman(434343434));
    CHECK_THROWS(snowman(434343334));
    CHECK_THROWS(snowman(77777777));
    CHECK_THROWS(snowman(24332535));
    CHECK_THROWS(snowman(75364969));
    CHECK_THROWS(snowman(6754435));
    CHECK_THROWS(snowman(13466575));
    CHECK_THROWS(snowman(89543445));
    CHECK_THROWS(snowman(788754345));
    CHECK_THROWS(snowman(677654536));
}

TEST_CASE ("too long input problem") // קלט ארוך מדיי, עליו צריכה להיזרק שגיאה
{

   CHECK_THROWS(snowman(1876543213));
   CHECK_THROWS(snowman(1235665766));
   CHECK_THROWS(snowman(1987654873));
   CHECK_THROWS(snowman(1456326256));
   CHECK_THROWS(snowman(1678545353));
   CHECK_THROWS(snowman(1237765323));

}
TEST_CASE("too short input problem") // קלט קצר מדיי, עליו צריכה להיזרק שגיאה
{
    CHECK_THROWS(snowman(123));
    CHECK_THROWS(snowman(6));
    CHECK_THROWS(snowman(321));
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(122));
    CHECK_THROWS(snowman(012));
    CHECK_THROWS(snowman(56));
    CHECK_THROWS(snowman(89));
}

