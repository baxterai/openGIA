/*******************************************************************************
 *
 * This file is part of BAIPROJECT.
 *
 * BAIPROJECT is licensed under the GNU Affero General Public License
 * version 3, as published by the Free Software Foundation. The use of
 * intermediary programs or interfaces including file i/o is considered
 * remote network interaction. This does not imply such arrangements
 * do not constitute derivative works.
 *
 * BAIPROJECT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License version 3 for more details
 * (a copy is included in the LICENSE file that accompanied this code).
 *
 * You should have received a copy of the GNU Affero General Public License
 * version 3 along with BAIPROJECT.  If not, see <http://www.gnu.org/licenses/>
 * for a copy of the AGPLv3 License.
 *
 *******************************************************************************/

/*******************************************************************************
 *
 * File Name: GIAsentenceClass.cpp
 * Author: Richard Bruce Baxter - Copyright (c) 2005-2017 Baxter AI (baxterai.com)
 * Project: General Intelligence Algorithm
 * Project Version: 3d5a 11-August-2017
 * Requirements: requires text parsed by NLP Parser (eg Relex; available in .CFF format <relations>)
 *
 *******************************************************************************/


#include "GIAsentenceClass.hpp"


#ifdef GIA_STANFORD_CORENLP


GIAstanfordCoreNLPmention::GIAstanfordCoreNLPmention(void)
{
	representative = false;
	sentence = INT_DEFAULT_VALUE;
	start = INT_DEFAULT_VALUE;
	end = INT_DEFAULT_VALUE;
	head = INT_DEFAULT_VALUE;

	next = NULL;
}

GIAstanfordCoreNLPmention::~GIAstanfordCoreNLPmention(void)
{
	if(next != NULL)
	{
		delete next;
	}
}

GIAstanfordCoreNLPcoreference::GIAstanfordCoreNLPcoreference(void)
{
	firstMentionInList = new GIAstanfordCoreNLPmention();

	next = NULL;
}

GIAstanfordCoreNLPcoreference::~GIAstanfordCoreNLPcoreference(void)
{
	if(firstMentionInList != NULL)
	{
		delete firstMentionInList;
	}

	if(next != NULL)
	{
		delete next;
	}
}
#endif

//#ifdef GIA_ADVANCED_REFERENCING
//these classes are only used by GIA_ADVANCED_REFERENCING:
GIAMention::GIAMention(void)
{
	representative = false;
	idActiveList = INT_DEFAULT_VALUE;
	entityIndex = INT_DEFAULT_VALUE;	//ie, "head"
	entityName = "";
	intrasentenceReference = false;		//only applies to representative/source mentions (specifies whether reference source is contained within current sentence)

	next = NULL;
}

GIAMention::~GIAMention(void)
{
	if(next != NULL)
	{
		delete next;
	}
}

GIAcoreference::GIAcoreference(void)
{
	firstMentionInList = new GIAMention();

	next = NULL;
}

GIAcoreference::~GIAcoreference(void)
{
	if(firstMentionInList != NULL)
	{
		delete firstMentionInList;
	}

	if(next != NULL)
	{
		delete next;
	}
}
//#endif






GIArelation::GIArelation(void)
{
	relationType = "";
	relationTypeIndex = INT_DEFAULT_VALUE;
	relationDependent = "";
	relationDependentIndex = INT_DEFAULT_VALUE;
	relationGovernor = "";
	relationGovernorIndex = INT_DEFAULT_VALUE;
	#ifdef GIA_STANFORD_PARSER_AND_CORENLP_VERSION_2015_04_20_OR_GREATER
	relationGovernorRevertedToOfficialLRPTemp = false;
	relationDependentRevertedToOfficialLRPTemp = false;
	#endif

	#ifdef GIA_PREPROCESSOR_MULTIWORD_REDUCTION_NORMALISE_INVERSE_PREPOSITIONS
	relationTypeNonInversed = "";
	relationTypeIndexNonInversed = INT_DEFAULT_VALUE;
	#endif

	disabled = false;
	//#ifdef GIA_GENERIC_DEPENDENCY_RELATION_INTERPRETATION_LINK
	disabledDuringLink = false;
	//#endif

	#ifdef GIA_RELEX
	subjObjRelationAlreadyAdded = false;
	#endif

	#ifdef GIA_STANFORD_CORENLP
	prepositionCombinationAlreadyCreatedTemp = false;
	#endif

	auxiliaryIndicatesDifferentReferenceSet = false;
	rcmodIndicatesSameReferenceSet = false;

	#ifdef GIA_SEMANTIC_PARSER
	sameReferenceSet = false;
	#ifdef GIA_SEMANTIC_PARSER_SUPPORT_QUERIES
	corpusSpecialRelationGovernorIsQuery = "";
	corpusSpecialRelationDependentIsQuery = "";
	#endif
	#endif

	#ifdef GIA_PREPROCESSOR_MULTIWORD_REDUCTION_NORMALISE_PREPOSITIONS
	inverseRelation = false;
	#ifdef GIA_PREPROCESSOR_MULTIWORD_REDUCTION_NORMALISE_INVERSE_PREPOSITIONS
	inverseRelationSingle = false;
	#endif
	#ifdef GIA_PREPROCESSOR_MULTIWORD_REDUCTION_NORMALISE_TWOWAY_PREPOSITIONS
	relationTwoWay = false;
	#ifdef GIA_PREPROCESSOR_MULTIWORD_REDUCTION_NORMALISE_TWOWAY_PREPOSITIONS_DUAL_CONDITION_LINKS_ENABLED
	inverseRelationTwoWay = false;
	#endif
	#endif
	#endif

	next = NULL;
}

GIArelation::~GIArelation(void)
{
	if(next != NULL)
	{
		delete next;
	}

}

GIAfeature::GIAfeature(void)
{
	entityIndex = 0;
	word = "";
	lemma = "";
	#ifdef GIA_PREPROCESSOR_MULTIWORD_REDUCTION
	wordWithLRPforNLPonly = "";
	#endif
	#ifdef GIA_PREPROCESSOR_MULTIWORD_REDUCTION
	featureRevertedToOfficialLRPTemp = "";
	#endif

	#ifdef GIA_RELEX
	type = "";
	grammar = "";
	#endif

	NER = FEATURE_NER_UNDEFINED;
	#ifdef GIA_STANFORD_CORENLP
	CharacterOffsetBegin = INT_DEFAULT_VALUE;
	CharacterOffsetEnd = INT_DEFAULT_VALUE;
	stanfordPOS = "";
	NormalizedNER = "";
	Timex = "";
	#endif

	//derived variables:
	grammaticalIsDateOrTime = false;
	grammaticalTense = GRAMMATICAL_TENSE_UNDEFINED;
	for(int q=0; q<GRAMMATICAL_TENSE_MODIFIER_NUMBER_OF_TYPES;q++)
	{
		grammaticalTenseModifierArray[q] = false;
	}
	grammaticalNumber = GRAMMATICAL_NUMBER_UNDEFINED;
	grammaticalIsDefinite = false;
	grammaticalIsIndefinitePlural = false;
	grammaticalIsProperNoun = false;
	grammaticalGender = GRAMMATICAL_GENDER_UNDEFINED;
	grammaticalIsPronoun = false;
	grammaticalWordType = GRAMMATICAL_WORD_TYPE_UNDEFINED;
	#ifdef GIA_PREDETERMINERS
	grammaticalPredeterminer = GRAMMATICAL_PREDETERMINER_UNDEFINED;
	#endif
	previousWordInSentenceIsTo = false;

	#ifndef GIA_GENERIC_DEPENDENCY_RELATION_INTERPRETATION_SUBSTANCES
	alreadyAssignedSubstancesBasedOnDeterminatesOfDefinitionEntitiesTemp = false;		//#ifdef GIA_DEFINE_SUBSTANCES_BASED_UPON_DETERMINATES_OF_DEFINITION_ENTITIES
	mustSetIsConceptBasedOnApposRelation = false;
	isPronounReference = false;
	#endif

	entityDisabled = false;

	#ifdef GIA_SEMANTIC_PARSER
	GIAsemanticParserPOStype = 0;	//ie GIA_SEMANTIC_PARSER_POS_TYPE_UNDEFINED
	#endif

	#ifdef GIA_FEATURE_POS_TAG_NN_ONLY_MARK_AS_SINGULAR_WITH_DETERMINER
	determinerPotentiallySingularDetected = false;
	#endif

	next = NULL;
	previous = NULL;
}

GIAfeature::~GIAfeature(void)
{
	if(next != NULL)
	{
		delete next;
	}

}


GIAsentence::GIAsentence(void)
{
	#ifdef GIA_RELEX
	sentenceText = "";
	constituentsText = "";
	featuresText = "";
	relationsText = "";
	linksText = "";
	#endif

	sentenceIndex = GIA_SENTENCE_INDEX_UNDEFINED;
	#ifdef GIA_STANFORD_CORENLP
	firstCoreferenceInList = new GIAstanfordCoreNLPcoreference();
	#endif

	numberOfWordsInSentence = 0;

	firstRelationInList = new GIArelation();	//auto constructor execution added 23 Feb 2012
	firstFeatureInList = new GIAfeature();	//auto constructor execution added 23 Feb 2012
	#ifdef GIA_PREPROCESSOR_RECORD_REFERENCES
	firstRelationInListOriginal = new GIArelation();
	firstFeatureInListOriginal = new GIAfeature();
	#endif
	
	next = NULL;
	previous = NULL;

	isQuestion = false;

	semanticParserSuccessful = false;

	relationshipEntityArtificialIndexCurrent = 0;
}

GIAsentence::~GIAsentence(void)
{
	if(firstRelationInList != NULL)
	{
		delete firstRelationInList;
	}

	if(firstFeatureInList != NULL)	//added 23 Feb 2012
	{
		delete firstFeatureInList;
	}

	#ifdef GIA_STANFORD_CORENLP
	if(firstCoreferenceInList != NULL)	//added 21 Sept 2012
	{
		delete firstCoreferenceInList;
	}
	#endif

	if(next != NULL)
	{
		delete next;
	}

}


GIAparagraph::GIAparagraph(void)
{
	firstSentenceInList = new GIAsentence();

	next = NULL;
	previous = NULL;
}

GIAparagraph::~GIAparagraph(void)
{
	if(firstSentenceInList != NULL)
	{
		delete firstSentenceInList;
	}

	if(next != NULL)
	{
		delete next;
	}
}


void GIAsentenceClassClass::backupOriginalNLPsentenceContent(GIAsentence* firstSentenceInList)
{	
	GIAsentence* currentSentenceInList = firstSentenceInList;
	while(currentSentenceInList->next != NULL)
	{
		copyRelations(currentSentenceInList->firstRelationInList, currentSentenceInList->firstRelationInListOriginal);
		copyFeatures(currentSentenceInList->firstFeatureInList, currentSentenceInList->firstFeatureInListOriginal);
		
		currentSentenceInList = currentSentenceInList->next;
	}
}

void GIAsentenceClassClass::copySentences(GIAsentence* firstSentenceInListToCopy, GIAsentence* firstSentenceInList)
{
	GIAsentence* currentSentenceToCopy = firstSentenceInListToCopy;
	GIAsentence* currentSentence = firstSentenceInList;
	while(currentSentenceToCopy->next != NULL)
	{
		this->copySentence(currentSentenceToCopy, currentSentence);
		
		GIAsentence* newSentence = new GIAsentence();
		currentSentence->next = newSentence;

		currentSentenceToCopy = currentSentenceToCopy->next;
		currentSentence = currentSentence->next;
	}
}

void GIAsentenceClassClass::copySentence(GIAsentence* sentenceToCopy, GIAsentence* newSentence)
{
	*newSentence = *sentenceToCopy;
	
	#ifdef GIA_STANFORD_CORENLP
	newSentence->firstCoreferenceInList = new GIAstanfordCoreNLPcoreference();
	this->copyStanfordCoreferences(sentenceToCopy->firstCoreferenceInList, newSentence->firstCoreferenceInList);	//changed 21 Sept 2012
	#endif

	newSentence->firstRelationInList = new GIArelation();
	this->copyRelations(sentenceToCopy->firstRelationInList, newSentence->firstRelationInList);
	newSentence->firstFeatureInList = new GIAfeature();
	this->copyFeatures(sentenceToCopy->firstFeatureInList, newSentence->firstFeatureInList);
	
	#ifdef GIA_PREPROCESSOR_RECORD_REFERENCES
	newSentence->firstRelationInListOriginal = new GIArelation();
	this->copyRelations(sentenceToCopy->firstRelationInListOriginal, newSentence->firstRelationInListOriginal);
	newSentence->firstFeatureInListOriginal = new GIAfeature();
	this->copyFeatures(sentenceToCopy->firstFeatureInListOriginal, newSentence->firstFeatureInListOriginal);
	#endif
	
	newSentence->next = NULL;
	newSentence->previous = NULL;
}

void GIAsentenceClassClass::copyRelations(GIArelation* firstRelationInListToCopy, GIArelation* firstRelationInList)
{
	GIArelation* currentRelationToCopy = firstRelationInListToCopy;
	GIArelation* currentRelation = firstRelationInList;
	while(currentRelationToCopy->next != NULL)
	{
		*currentRelation = *currentRelationToCopy;

		GIArelation* newRelation = new GIArelation();
		currentRelation->next = newRelation;

		currentRelationToCopy = currentRelationToCopy->next;
		currentRelation = currentRelation->next;
	}
}

void GIAsentenceClassClass::copyFeatures(GIAfeature* firstFeatureInListToCopy, GIAfeature* firstFeatureInList)
{
	GIAfeature* currentFeatureToCopy = firstFeatureInListToCopy;
	GIAfeature* currentFeature = firstFeatureInList;
	while(currentFeatureToCopy->next != NULL)
	{
		*currentFeature = *currentFeatureToCopy;
		
		GIAfeature* newFeature = new GIAfeature();
		newFeature->previous = currentFeature;
		currentFeature->next = newFeature;

		currentFeatureToCopy = currentFeatureToCopy->next;
		currentFeature = currentFeature->next;
	}
}


#ifdef GIA_STANFORD_CORENLP
void GIAsentenceClassClass::copyStanfordCoreferences(GIAstanfordCoreNLPcoreference* firstCoreferenceInListToCopy, GIAstanfordCoreNLPcoreference* firstCoreferenceInList)
{
	GIAstanfordCoreNLPcoreference* currentCoreferenceInListToCopy = firstCoreferenceInListToCopy;
	GIAstanfordCoreNLPcoreference* currentCoreferenceInList = firstCoreferenceInList;
	while(currentCoreferenceInListToCopy->next != NULL)
	{
		currentCoreferenceInList->firstMentionInList = new GIAstanfordCoreNLPmention();
		this->copyStanfordMention(currentCoreferenceInListToCopy->firstMentionInList, currentCoreferenceInList->firstMentionInList);

		GIAstanfordCoreNLPcoreference* newCoreference = new GIAstanfordCoreNLPcoreference();
		currentCoreferenceInList->next = newCoreference;

		currentCoreferenceInListToCopy = currentCoreferenceInListToCopy->next;
		currentCoreferenceInList = currentCoreferenceInList->next;
	}
}

void GIAsentenceClassClass::copyStanfordMention(GIAstanfordCoreNLPmention* firstMentionInListToCopy, GIAstanfordCoreNLPmention* firstMentionInList)
{
	GIAstanfordCoreNLPmention* currentMentionInListToCopy = firstMentionInListToCopy;
	GIAstanfordCoreNLPmention* currentMentionInList = firstMentionInList;
	while(currentMentionInListToCopy->next != NULL)
	{
		*currentMentionInList = *currentMentionInListToCopy;

		GIAstanfordCoreNLPmention* newMention = new GIAstanfordCoreNLPmention();
		currentMentionInList->next = newMention;

		currentMentionInListToCopy = currentMentionInListToCopy->next;
		currentMentionInList = currentMentionInList->next;
	}
}

int GIAsentenceClassClass::calculateNumberOfWordsInSentence(const GIAfeature* firstFeatureInList)
{
	int numberOfWordsInSentence = 0;
	const GIAfeature* currentFeatureInList = firstFeatureInList;
	while(currentFeatureInList->next != NULL)
	{
		numberOfWordsInSentence++;
		currentFeatureInList = currentFeatureInList->next;
	}
	return numberOfWordsInSentence;
}

#endif



int GIAsentenceClassClass::getMinIndexOfDynamicallyGeneratedEntity(GIAsentence* currentSentenceInList) 
{
	int minIndexOfDynamicallyGeneratedEntity = currentSentenceInList->numberOfWordsInSentence + GIA_NLP_START_ENTITY_INDEX;		//OLD: FEATURE_INDEX_MIN_OF_DYNAMICALLY_GENERATED_ENTITY
	return minIndexOfDynamicallyGeneratedEntity;	
}

int GIAsentenceClassClass::getMaxIndexOfDynamicallyGeneratedEntity(GIAsentence* currentSentenceInList) 
{
	int maxIndexOfDynamicallyGeneratedEntity = getMinIndexOfDynamicallyGeneratedEntity(currentSentenceInList) + MAX_NUMBER_OF_SPECIAL_WORDS_PER_SENTENCE;
	return maxIndexOfDynamicallyGeneratedEntity;
}

bool GIAsentenceClassClass::relationIndexIsNormal(int relationIndex) 
{
	//this function is designed to support the creation of semantic dependency relations with special governor/dependent feature indices (<GIA_NLP_START_ENTITY_INDEX, e.g. -2, -1, 0)
	bool relationIndexIsNormal = false;
	if(relationIndex >= GIA_NLP_START_ENTITY_INDEX)	//OLD: (currentRelation->relationDependentIndex > FEATURE_INDEX_MIN_OF_DYNAMICALLY_GENERATED_ENTITY)
	{
		relationIndexIsNormal = true;
	}
	return relationIndexIsNormal;
}





