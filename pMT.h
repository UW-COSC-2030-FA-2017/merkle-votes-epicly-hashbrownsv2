/*
pMT.h
Sam Blair, Oyedola Ajao, Sam Goering, and Easton Tuttle
Computer Science II
Homework 5 - Merkle Votes
November 8, 2017
Interfaces of the pMT class.
*/

#pragma once

#include "bTREE.h"
#include <string>

using namespace std;

class pMT
{
private:
	//Variables 
	int selectedHash;
	bTREE myMerkle;
	int ops = 0;
	bool found = false;

	//Basic Hash Functions only related to data
	string hash_SamB(string);
	string hash_SamG(string);
	string hash_Dola(string);
	string hash_Easton(string);

	//Hash Functions involving the tree

	void treeHash_SamG(treeNode* subtree);
	void treeHash_Easton(treeNode* subtree);
	void treeHash_SamB(treeNode* subtree);
	void treeHash_Dola(treeNode* subtree);
	void findHashH(treeNode* subtree, string mhash);
	string path;
public:
	pMT(int);
	~pMT();

	void hash(treeNode* subtree);

	//Locate functions
	string locateDataH(string input);
	string locateDataH1(string input);
	string locateDataH2(string input);
	string locateDataH3(string input);
	string locate(string);
	void locateData(treeNode* subtree, string vote, string path);
	void locateData1(treeNode* subtree, string vote, string path);
	void locateData3(treeNode* subtree, string vote, string path);
	void locateData2(treeNode* subtree, string vote, string path);
	//Accessor Function
	bTREE accessbTREE() { return myMerkle; }

	//Insert and find functions
	int insert(string, int);
	int find(string);
	int find(string vote, int time, int hashSelect);
	int findHash(string);

};
