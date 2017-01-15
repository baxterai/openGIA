/*******************************************************************************
 *
 * File Name: GIATranslator.h
 * Author: Richard Bruce Baxter - Copyright (c) 2005-2012 Baxter AI (baxterai.com)
 * Project: General Intelligence Algorithm
 * Project Version: 1l4d 02-June-2012
 * Requirements: requires text parsed by NLP Parser (eg Relex; available in .CFF format <relations>)
 * Description: Converts relation objects into GIA network nodes (of type entity, action, condition etc) in GIA network/tree
 *
 *******************************************************************************/


#ifndef HEADER_GIA_TRANSLATOR
#define HEADER_GIA_TRANSLATOR




#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <cstdlib>	//for random number generation
#include <cmath>
#include <string>
#include <vector>
using namespace std;


#include "GIAglobalDefs.h"					
#include "GIASentenceClass.h"
#include "GIAEntityNodeClass.h"
#include "GIAEntityConnectionClass.h"
#include "GIAConditionNodeClass.h"
#ifdef USE_CE
	#include "CEClaimClass.h"
#endif



void initialiseGIATranslatorForTexualContext();
#ifdef GIA_USE_RELEX_UPDATE_ADD_PARAGRAPH_TAGS
void convertParagraphSentenceRelationsIntoGIAnetworkNodes(unordered_map<string, GIAEntityNode*> *entityNodesActiveListConcepts, unordered_map<long, GIATimeConditionNode*> *timeConditionNodesActiveList, Paragraph * firstParagraphInList, int NLPfeatureParser, int NLPdependencyRelationsType, bool NLPassumePreCollapsedStanfordRelations, bool readFromDatabase);
#endif
	#ifdef USE_CE
	void convertSentenceListRelationsIntoGIAnetworkNodesBasedUponClaimHeirachy(unordered_map<string, GIAEntityNode*> *entityNodesActiveListConcepts, unordered_map<long, GIATimeConditionNode*> *timeConditionNodesActiveList, Sentence * firstSentenceInList, CEClaim * firstClaimInHeirachy, vector<CEClaim*> * claimsList, int NLPfeatureParser, int NLPdependencyRelationsType, bool NLPassumePreCollapsedStanfordRelations, bool readFromDatabase);
	#endif
	void convertSentenceListRelationsIntoGIAnetworkNodes(unordered_map<string, GIAEntityNode*> *entityNodesActiveListConcepts, unordered_map<long, GIATimeConditionNode*> *timeConditionNodesActiveList, Sentence * firstSentenceInList, int NLPfeatureParser, int NLPdependencyRelationsType, bool NLPassumePreCollapsedStanfordRelations, bool readFromDatabase);
		#ifdef GIA_USE_ADVANCED_REFERENCING
		void convertSentenceRelationsIntoGIAnetworkNodes(unordered_map<string, GIAEntityNode*> *entityNodesActiveListConcepts, unordered_map<long, GIATimeConditionNode*> *timeConditionNodesActiveList, Sentence * firstSentenceInList, Sentence * currentSentenceInList, vector<GIAEntityNode*> *sentenceConceptEntityNodesList, int NLPfeatureParser, int NLPdependencyRelationsType, bool NLPassumePreCollapsedStanfordRelations, bool linkPreestablishedReferencesGIA,  GIACoreference * firstGIACoreferenceInList);
		#else
		void convertSentenceRelationsIntoGIAnetworkNodes(unordered_map<string, GIAEntityNode*> *entityNodesActiveListConcepts, unordered_map<long, GIATimeConditionNode*> *timeConditionNodesActiveList, Sentence * firstSentenceInList, Sentence * currentSentenceInList, vector<GIAEntityNode*> *sentenceConceptEntityNodesList, int NLPfeatureParser, int NLPdependencyRelationsType, bool NLPassumePreCollapsedStanfordRelations);		
		#endif


	//?property to property relationship - these they in actual fact represent different levels of detail in information to property to action / action to action nodes - direct property to property relationships are missing the action/connectivity information


#endif
