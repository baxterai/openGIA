/*******************************************************************************
 *
 * File Name: GIAConditionNodeClass.h
 * Author: Richard Bruce Baxter - Copyright (c) 2005-2012 Baxter AI (baxterai.com)
 * Project: General Intelligence Algorithm
 * Project Version: 1i10a 12-Apr-2012
 *
 *******************************************************************************/


#ifndef HEADER_GIA_CONDITION_NODE_CLASS
#define HEADER_GIA_CONDITION_NODE_CLASS

#include "GIAglobalDefs.h"

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <cstdlib>	//for random number generation
#include <cmath>
#include <string>
#include <vector>
using namespace std;



class GIATimeConditionNode;


#define CONDITION_NODE_NUMBER_OF_TYPES (4)
#define CONDITION_NODE_TYPE_UNDEFINED (0)
#define CONDITION_NODE_TYPE_TIME (1)
#define CONDITION_NODE_TYPE_LOCATION (2)
#define CONDITION_NODE_TYPE_REASON (3)

#define TIME_MONTH_JANUARY "January"
#define TIME_MONTH_FEBRUARY "February"
#define TIME_MONTH_MARCH "March"
#define TIME_MONTH_APRIL "April"
#define TIME_MONTH_MAY "May"
#define TIME_MONTH_JUNE "June"
#define TIME_MONTH_JULY "July"
#define TIME_MONTH_AUGUST "August"
#define TIME_MONTH_SEPTEMBER "September"
#define TIME_MONTH_OCTOBER "October"
#define TIME_MONTH_NOVEMBER "November"
#define TIME_MONTH_DECEMBER "December"
#define TIME_MONTH_NUMBER_OF_TYPES (12)

#define MONDAY (0)
#define TUESDAY (1)
#define WEDNESDAY (2)
#define THURSDAY (3)
#define FRIDAY (4)
#define SATURDAY (5)
#define SUNDAY (6)
#define TIME_DAY_OF_WEEK_UNDEFINED (7)

#define GRAMMATICAL_TENSE_UNDEFINED (0)

#define TIME_YEAR_UNDEFINED (-15000000000)	//before start of universe
#define TIME_DAY_OF_MONTH_UNDEFINED (-1)
#define TIME_MONTH_UNDEFINED (-1)	//OLD: 13th month


class GIATimeConditionNode
{
public:

	GIATimeConditionNode(void);
	~GIATimeConditionNode(void);
	
	string conditionName;
	
	//temporal coordinate system here - this needs to be replaced with a system time (or added to) 
	int tense;
	/*
	enum tense {tenseundefined=GRAMMATICAL_TENSE_UNDEFINED, present=GRAMMATICAL_TENSE_PRESENT, past=GRAMMATICAL_TENSE_PAST, future=GRAMMATICAL_TENSE_FUTURE};
	*/
	/*
	enum
	{
		tenseundefined, present, past, future 
	}tense;
	*/	
	double second;
	int hour;
	int dayOfWeek;
	/*
	enum
	{
		monday, tuesday, wednesday, thursday, friday, saturday, sunday, dayundefined
	}dayOfWeek;
	*/
	/*
	enum
	{
		january, february, march, april, may, june, july, august, september, october, november, december, monthundefined
	}month;
	*/
	int month;
	int dayOfMonth;
	long year;	//in years < 0AD is negative
	double period;	//in seconds
	long totalTimeInSeconds;
	
	bool isProgressive;
	
	int id;		//for CXL output only
	int printX;	//for CXL output only
	int printY;	//for CXL output only
};

#define TIME_DATE_DISPLAY_FORMAT_AMERICAN (1)
#define TIME_DATE_DISPLAY_FORMAT_STANDARD (2)
#define TIME_DATE_DISPLAY_FORMAT_AUSTRALIAN (3)
#define TIME_DATE_DISPLAY_FORMAT (TIME_DATE_DISPLAY_FORMAT_AUSTRALIAN)
string generateDateTimeConditionName(int dayOfMonth, int month, long year);


#endif

