/*******************************************************************************
 *
 * File Name: GIAwordnet.h
 * Author: Richard Bruce Baxter - Copyright (c) 2005-2012 Baxter AI (baxterai.com)
 * Project: General Intelligence Algorithm
 * Project Version: 1l1a 15-May-2012
 * Requirements: requires wordnet libraries to be installed
 * Description: searches wordnet database and parses wordnet output
 *
 *******************************************************************************/


#ifndef HEADER_GIA_WORDNET
#define HEADER_GIA_WORDNET

#include "GIAglobalDefs.h"
#include "wn.h"

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <cstdlib>	//for random number generation
#include <cmath>
#include <string>
using namespace std;

#define MAX_CHARACTERS_OF_WORD_IN_GIA_INPUT_DATA 150 //max characters of some word in input data. includes '\0' at end of a string
#define MAX_CHARACTERS_OF_WORDNET_FINDTHEINFO_OUTPUT (10000)
#define MAX_CHARACTERS_OF_WORDNET_FINDTHEINFO_OUTPUT_LINE (1000)
#define MAX_CHARACTERS_OF_WORDNET_FINDTHEINFO_OUTPUT_NUMBER_OF_SENSES (10)	//supports e^10 senses
#define WORDNET_FINDTHEINFO_OUTPUT_MAX_NUMBER_SYNONYMS (100)

#define WORDNET_DATA_ENTRY_POINTERS_INDICATING_SIMILAR_SYNSETS_NUMBER_OF_TYPES (1)
static int wordnetDataEntryPointersIndicatingSimilarSynsetsArray[WORDNET_DATA_ENTRY_POINTERS_INDICATING_SIMILAR_SYNSETS_NUMBER_OF_TYPES] = {SIMPTR};

//#define CURRENTSYNSET (99)

#ifdef WORDNET_SEARCH_RELATED_SYNSETS
	#define WORDNET_DATA_ENTRY_POINTERS_INDICATING_RELATED_SYNSETS_NUMBER_OF_TYPES (2)
	static int wordnetDataEntryPointersIndicatingRelatedSynsetsArray[WORDNET_DATA_ENTRY_POINTERS_INDICATING_RELATED_SYNSETS_NUMBER_OF_TYPES] = {SIMPTR, HYPOPTR};
#else
	#define WORDNET_DATA_ENTRY_POINTERS_INDICATING_RELATED_SYNSETS_NUMBER_OF_TYPES (0)
	static int wordnetDataEntryPointersIndicatingRelatedSynsetsArray[WORDNET_DATA_ENTRY_POINTERS_INDICATING_RELATED_SYNSETS_NUMBER_OF_TYPES] = {};
#endif
#define CURRENTSYNSETPOINTERINDEX (WORDNET_DATA_ENTRY_POINTERS_INDICATING_RELATED_SYNSETS_NUMBER_OF_TYPES)

void initialiseWordNet();

bool checkIfWordIsContainedWithinOtherWordsSynsetsOrViceVersa(string * word, string * otherWord, int wordNetPOS);
	bool checkIfWordIsContainedWithinAnotherWordsSynsets(string * word, string * otherWord, int wordNetPOS);
SynsetPtr findMostPopularSynsets(string * word, bool * wordIsFound, int wordNetPOS);
		SynsetPtr findSynsets(string * word, bool * wordIsFound, int wordNetPOS, int similarityType);
		SynsetPtr checkIfSynsetListContainsSynonymousEntityNamesAndRecordMostPopularSynset(SynsetPtr firstSenseInList, int wordNetPOS, int * maximumNumberOfTags, bool * entityNamesAreSynonymous, string * word, string * otherWord, bool compareEntityNames);	


	
void findSynonymsOLD(string word, bool * wordIsFound, string listOfSynonyms[], int wordNetPOS);
bool recordUntilCharacterOrEscapeCharacterOLD(int charIndex, char * output, int * newCharIndex, char * lineString, char characterToRecordUntil, char escapeCharacter);

#endif
