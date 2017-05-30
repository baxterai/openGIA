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
 * File Name: GIAsemanticParserOperations.hpp
 * Author: Richard Bruce Baxter - Copyright (c) 2005-2017 Baxter AI (baxterai.com)
 * Project: General Intelligence Algorithm
 * Project Version: 3b4a 28-May-2017
 * Requirements: requires text parsed by GIA2 Parser (Modified Stanford Parser format)
 *
 *******************************************************************************/


#ifndef HEADER_GIA_SEMANTIC_PARSER_OPERATIONS
#define HEADER_GIA_SEMANTIC_PARSER_OPERATIONS

#include "GIAglobalDefs.hpp"
#include "GIAtranslatorDefs.hpp"
#include "GIAsemanticParserDatabase.hpp"
#include "GIAtranslatorOperations.hpp"

#ifdef GIA_SEMANTIC_PARSER_WRITE_SEMANTIC_RELATIONS

class GIAsemanticParserOperationsClass
{
	private: GIAsemanticParserDatabaseClass GIAsemanticParserDatabase;
	private: SHAREDvarsClass SHAREDvars;
	public: void GIA2nonHeuristicImplementationGenerateExperiencesForConnectionistNetworkTrain(const GIAtranslatorVariablesClass* translatorVariables, int connectionType, int entityIndex1, int entityIndex2, bool sameReferenceSet);
	public: void GIA2nonHeuristicImplementationGenerateExperiencesForConnectionistNetworkTrainSpecial(const GIAtranslatorVariablesClass* translatorVariables, const bool linkPreestablishedReferencesGIA);
		private: void generateGIA2semanticDependencyRelation(constEffective GIAentityNode** GIAentityNodeArray, int connectionType, int entityIndex1, int entityIndex2, bool sameReferenceSet, const string* GIA2semanticDependencyRelationText, GIArelation* GIA2semanticDependencyRelation);
	#ifdef GIA_SEMANTIC_PARSER_WRITE_SEMANTIC_RELATIONS_UNOPTIMISED_TEXT_CORPUS
			public: string generateGIA2semanticDependencyRelationText(const string entityName1, const string entityName2, const string semanticRelation, const int entityIndex1, const int entityIndex2, const bool sameReferenceSet);
				private: string createSameReferenceSetRecord(const bool sameReferenceSet);
	#ifndef GIA_SEMANTIC_PARSER_WRITE_SEMANTIC_RELATIONS_UNOPTIMISED_TEXT_CORPUS_OLD
	public: string generateSemanticParserCorpusSemanticRelationsText(const GIArelation* firstSemanticRelationInList);
	#endif
	#endif
	public: void determineGIAconnectionistNetworkPOStypeNames(GIAfeature* firstFeatureInList, const int NLPfeatureParser);
		private: void determineGIAconnectionistNetworkPOStypeNameStanford(GIAfeature* currentFeatureInSentence);
		private: void determineGIAconnectionistNetworkPOStypeNameRelex(GIAfeature* currentFeatureInSentence);
	#ifdef GIA_SEMANTIC_PARSER_SUBSETS
	#ifdef GIA_SEMANTIC_PARSER_SUBSETS_OPTIMISE_BASED_ON_CONJUNCTIONS
	public: GIAfeature* generateOptimisedFeatureSubsetBasedOnContextualConjunctions(GIAfeature* firstFeatureInSentenceSubset, const int centralWord, bool* optimisedBasedOnContextualConjunctions);
	#endif
	#ifdef GIA_SEMANTIC_PARSER_SUBSETS_OPTIMISED_DATABASE
	public: int calculateFirstWordInTupleIndexRelative(const int firstWordInTupleIndex, const int firstWordInSentenceSubsetIndex);
	#endif
	#endif

};

#endif


#endif
