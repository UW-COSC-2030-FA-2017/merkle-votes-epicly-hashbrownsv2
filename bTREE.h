/*
bTREE.h
Sam Blair, Oyedola Ajao, Sam Goering, and Easton Tuttle
Computer Science II
Homework 5 - Merkle Votes
December 1, 2017
Interfaces of the bTREE class.
*/

#pragma once
#include <string>
#include "treeNode.h"
using namespace std;

class bTREE
{
private:
	//Variables for bTREE
	treeNode* tree;
	int count = 0;
	int root = 0;
	bool found = false;
	bool iCri = true;
	string path;

	//Helper functions 
	int insertH(treeNode* subtree, string data, int time);
	void findH(treeNode* subtree, string data);
	void locateH(treeNode* subtree, string data, string path);
	void compareH(treeNode* comparisontree, treeNode* subtree);
	int numberOfNodesH(treeNode * subtree);
public:
	bTREE();
	~bTREE();
	//Basic accseor functions
	int gotCount() { return count; }
	void resetCount() { count = 0; }
	int numberOfNodes();
	treeNode* getNode() { return tree; }

	//Mutator methods
	bool compare(bTREE comparison);
	bool insert(string data, int time);
	bool find(string data);
	string locate(string data);

	//Overloaded opeerators
	friend bool operator==(const bTREE& lhs, const bTREE& rhs);
	friend bool operator!=(const bTREE& lhs, const bTREE& rhs);
	
	//Display Functions
	void display(std::ostream& outfile);
	void displayLeft(std::ostream & outfile, treeNode* subtree, std::string prefix);
	void displayRight(std::ostream & outfile, treeNode* subtree, std::string prefix);
};


