//
// Created by Or Gamliel on 08/03/2021.
//
#include <string>
#include <array>
#include "snowman.hpp"
#include <iostream>
#include <exception>
using namespace std;
using namespace ariel;

//יצירת קבועים בכדי שלא ייזרקו אזהרות
const int MAXIMUM = 44444444;
const int MINIMUM = 11111111;
const int TEN = 10;
const int TOPINT = 4;
const int LESSINT = 1;
const int Eight = 8;
const int HAT = 0;
const int NOSE = 1;
const int LEFT_EYE = 2;
const int RIGHT_EYE = 3;
const int LEFT_ARM = 4;
const int RIGHT_ARM = 5;
const int TORSO = 6;
const int BASE = 7;

//  נייצר מערכים קבועים שייצגו את כל המרכיבים האפשריים לאיש שלג - 4 אופציות לכל אחד
const array<string, TOPINT> right_arms = { ">"," ","\\"," " };
const array<string, TOPINT> torsos = { " : ", "] [","> <", "   " };
const array<string, TOPINT> hats = { " _===_","  ___\n .....", "   _\n  /_\\","  ___\n (_*_)" };
const array<string, TOPINT> noses = { ",",".","_"," " };
const array<string, TOPINT> eyes = { ".","o","O","-" };
const array<string, TOPINT> left_arm_tops = { " ","\\"," "," " };
const array<string, TOPINT> left_arms = { "<"," ","/"," " };
const array<string, TOPINT> right_arm_tops = { " ","/"," "," " };
const array<string, TOPINT> bases = { " : ", "\" \"", "___","   " };



string faceBulider(array<int, Eight> types) // פונקציה לבניית הפנים המכילה עיניים, אף וידיים עליונות
{
    string face = left_arm_tops.at(types.at(LEFT_ARM)) + "(" + eyes.at(types.at(LEFT_EYE)) + noses.at(types.at(NOSE)) + eyes.at(types.at(RIGHT_EYE)) + ")" + right_arm_tops.at(types.at(RIGHT_ARM));
    return face;
}
string bodyBulider(array<int, Eight> types) // פונקציה לבניית הגוף המכילה את מבנה הגוף והידיים
{
    string body = left_arms.at(types.at(LEFT_ARM)) + "(" + torsos.at(types.at(TORSO)) + ")" + right_arms.at(types.at(RIGHT_ARM));
    return body;
}

string baseBulider(int type) // פונקציה לבניית בסיס הגוף התחתון
{
    string lower_part = "(" + bases.at(type) + ")";
    return lower_part;
}

void validityCheck(int type) // פונקציה לבדיקת תקינות המספר שהוכנס בפונקציה
 {
    if (type > MAXIMUM || type < MINIMUM)  // אם חורג מגבולות המספרים האופציונליים
    {
        throw out_of_range("the input size is not fit"); //נזרוק שגיאה מחוץ לטווח
    }
    for (int i = Eight; i > 0; --i)  // הטווח תקין אך נבדוק את האחדות בכל אחד ממנו לוודא שזה בין 1-4
    {
        if (type % TEN < LESSINT || type % TEN>TOPINT)  // אם נמצא ספרה קטנה מאחד או גדולה מ4
        {
            throw out_of_range("the value is not fit");
        }
        type = type / TEN; // נחלק כל פעם בעשר עד שבדיקת התקינות תסתיים או שתיזרק שגיאה
    }
}

array<int, Eight> divideAndRule(int type)  //   שיטת הפרד ומשול - נקבל  מספר כקלט ונחזיר מערך בן 8 איברים של הסוגים להמשך טיפול
{
    array<int, Eight> types = {}; // נאתחל מערך מספרי בגודל 8
    for (int i = Eight; i > 0; --i) //נתחיל מאינדקס 8 ונרד למטה
     {
        types.at(i - LESSINT) = type % TEN - LESSINT;  // המערך במיקום פחות אחד (כי סופרים מאפס) שווה לספרת האחדות פחות אחד של מספר הקלט
        type = type / TEN; // אחרי שהכנסנו את ספרת האחדות של הקלט נקצץ אותו כל פעם בספרה עד שיסתיים
     }
    return types; // נקבל את מערך האיברים שיהיה הקלט של בניית איש השלג
}

string snowmanBulider(array<int, Eight> types)
{
    string base = baseBulider(types.at(BASE)); //יוצר את הסטרינג של הבסיס
    string body = bodyBulider(types); //יוצר את מחרוזת הפלג גוף עליון
    string hat = hats.at(types.at(HAT)); //יוצר את מחרוזת הכובע
    string face = faceBulider(types); //יוצר את מחרוזת הפנים
    return hat + "\n" + face + "\n" + body + "\n " + base + "\n";
}

string ariel::snowman(int type)
{
    validityCheck(type); // נוודא קודם שהערכים שהוזנו תקינים
    array<int, Eight> types = divideAndRule(type); // נבנה מערך קלט לפונקציית הבנייה על פי המספר התקין שהוכנס
    return snowmanBulider(types); // עכשיו אפשר לבנות את איש השלג ולהחזיר מחרוזת המתארת אותו
}

