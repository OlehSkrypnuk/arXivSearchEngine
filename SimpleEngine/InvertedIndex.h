#ifndef INVERTED_INDEX_H
#define INVERTED_INDEX_H

#include <unordered_map>
#include "DocInfo.h"
#include <string>
#include <list>

/*
 * This data structure represents the inverted index. It incapsulates a set of stemmed 
 * terms and a list of Objects called DocInfos. The list of DocInfos represents an 
 * entire postings list. Each DocInfo within the postings list represents the positional 
 * occurences of the term that occurs for that document.
 */
class InvertedIndex {
	// The hashmap that represents the entire inverted index.
	std::unordered_map<std::string, std::list<DocInfo>> _mIndex;

	// Returns the postings list for the requested term.
	// <cut and paste getPostings here>

public:
	// This method is used to check if a term exists. Instead of catching an out of 
	// bounds error everytime, we can check to avoid the expensive try/ catch overhead.
	bool hasPostings(const std::string &term);

	std::list<DocInfo> getPostings(const std::string &term); // change this to private later.
	InvertedIndex();

	// Adds an instance of the stemmed term to the document.
	// A new DocInfo is created if the term is first encountered in that document.
	void addTerm(const std::string &term, const std::string &docName, const int &pos); // maybe create a remove term?

	void printIndex();

	unsigned int getTermCount() const;
};

#endif