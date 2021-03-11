//
// Created by Or Gamliel on 08/03/2021.
//

#include "snowman.hpp"
#include <iostream>
#include <string>
#include <array>
#include <exception>
using namespace std;

//  נייצר מערכים קבועים שייצגו את כל המרכיבים האפשריים לאיש שלג - 4 אופציות לכל אחד

const array<string,4> left_arm_tops = {" ","\\"," "," "}; // כל סוגי יד שמאל עליונה
const array<string,4> left_arms = {"<"," ","/"," "}; // כל סוגי יד שמאל תחתונה
const array<string,4> right_arm_tops = {" ","/"," "," "}; // כל סוגי יד ימין עליונה
const array<string,4> right_arms = {">"," ","\\"," "}; // כל סוגי יד ימין תחתונה
const array<string,4> hats = {"_===_"," ---\n .....", "  -\n  /_\\"," ---\n (_*_)"}; //  כל סוגי הכובעים
const array<string,4> noses = {",",".","_"," "}; // כל סוגי האף האפשריים
const array<string,4> left_eyes = {".","o","O","-"}; // כל סוגי עין שמאל
const array<string,4> right_eyes = {".","o","O","-"}; // כל סוגי עין ימין
const array<string,4> torsos = {" : ", "] [","> <", "   "}; // כל סוגי פלג גוף עליון
const array<string,4> bases = {" : ", "\" \"", "___","   "}; // כל סוגי הבסיס, תחתית איש השלג

string faceBulider(array<int,8> types) // פונקציה לבניית הפנים המכילה עיניים, אף וידיים עליונות 
{
    string face = left_arm_tops[types[4]]+"("+left_eyes[types[2]]+noses[types[1]]+right_eyes[types[3]]+")"+right_arm_tops[types[5]];
    return face;
}

string bodyBulider(array<int,8> types) // פונקציה לבניית הגוף המכילה את מבנה הגוף והידיים 
{
    string body =left_arms[types[4]]+"("+torsos[types[6]]+")"+right_arms[types[5]];
    return body;
}
string baseBulider(int type) // פונקציה לבניית בסיס הגוף התחתון 
{
    string lower_part = " ("+bases[type]+ ")";
    return lower_part;
}

void validityCheck(int type)  // פונקציה לבדיקת תקינות המספר שהוכנס בפונקציה 
{
    if(type<11111111 || type>44444444) // אם חורג מגבולות המספרים האופציונליים
    {
        throw out_of_range(" the input size is not fit"); //נזרוק שגיאה מחוץ לטווח 
    }
    for (int i = 8; i > 0; --i) // הטווח תקין אך נבדוק את האחדות בכל אחד ממנו לוודא שזה בין 1-4
    {
        if(type%10<1||type%10>4) // אם נמצא ספרה קטנה מאחד או גדולה מ4
        {
            throw std::out_of_range(" the value is not fit"); 
        }
        type = type/10; // נחלק כל פעם בעשר עד שבדיקת התקינות תסתיים/תיזרק שגיאה 
    }
}

array<int,8> divideAndRule (int type) //   שיטת הפרד ומשול - נקבל  מספר כקלט ונחזיר מערך בן 8 איברים של הסוגים להמשך טיפול
{
    array<int,8> types = {}; // נאתחל מערך מספרי בגודל 8 
    for (int i = 8; i > 0; --i)  //נתחיל מאינדקס 8 ונרד למטה 
     {
        types[i-1] = type%10-1; // המערך במיקום פחות אחד (כי סופרים מאפס) שווה לספרת האחדות פחות אחד של מספר הקלט
        type = type/10; // אחרי שהכנסנו את ספרת האחדות של הקלט נקצץ אותו כל פעם בספרה עד שיסתיים
    }
    return types; // נקבל את מערך האיברים שיהיה הקלט של בניית איש השלג 
}

string snowmanBulider(array<int,8> types)
{
    
    string base = baseBulider(types[7]);  //יוצר את הסטרינג של הבסיס 
    string body = bodyBulider(types); //יוצר את מחרוזת הפלג גוף עליון
    string hat = hats[(int)types[0]];     //יוצר את מחרוזת הכובע 
    string face = faceBulider(types);     //יוצר את מחרוזת הפנים 
    return " "+hat+"\n"+face+"\n"+body+"\n"+base+" "; // נחבר בין כולם לפי הסדר מלמעלה למטה כאשר בין כל אחד נרד שורה כדי ליצור דמות
}

string ariel::snowman(int type)
{
    validityCheck(type);  // נוודא קודם שהערכים שהוזנו תקינים 
    array<int,8> types = divideAndRule(type); // נבנה מערך קלט לפונקציית הבנייה על פי המספר התקין שהוכנס
    return snowmanBulider(types); // עכשיו אפשר לבנות את איש השלג ולהחזיר מחרוזת המתארת אותו 
}
