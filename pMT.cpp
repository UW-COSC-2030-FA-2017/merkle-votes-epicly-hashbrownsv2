/*
 *pMT.cpp
 *Sam Blair, Oyedola Ajao, Sam Goering, and Easton Tuttle
 *Computer Science II
 *Homework 5 - Merkle Votes
 *December 1, 2017

 *The definitions of the pMT class.
*/

#include "stdafx.h"
#include "pMT.h"

using std::to_string;

pMT::pMT(int hashSelect)
/*
 * Constructor for merkel tree and initalizes]\
 * the hash to be used
 */
{
	if (hashSelect != 1 && hashSelect != 2 && hashSelect != 3 && hashSelect != 4)
	{
		selectedHash = 1;
	}
	else { selectedHash = hashSelect; }
}


pMT::~pMT()
/*
 * Destructor for merkel tree
 */
{
}

int pMT::insert(string vote, int time)
/**
 * Inserts a new node with thr given timestamp
 * and returns the number of operations needed
 * to insert.
 */

{
	myMerkle.resetCount();
	myMerkle.insert(vote, time);
	hash(myMerkle.getNode());
	return myMerkle.gotCount();
}

int pMT::find(string)
{
	return 0;
}

int pMT::find(string vote, int time, int hashSelect)
/**
 * @brief given a vote, timestamp, and hash function, does this vote exist in the tree?
 * @param vote, a string
 * @param time, an int
 * @param hashSelect, an int corresponding to the hash functions _1, _2, and _3
 * @return 0 if not found, else number of opperations required to find the matching vote
 */
{
	myMerkle.resetCount();
	if (myMerkle.find(vote)){
		return myMerkle.gotCount();
	}
	else{
		return 0;
	}
	return 0;
}

int pMT::findHash(string mhash)
/**
 * Takes in and finds an already hashed values
 * and the number of operations needed to do so.
 */
{
	found = false;
	ops = 0;
	findHashH(myMerkle.getNode(), mhash);
	if (found == true)
	{
		return ops;
	}
	return 0;
}

void pMT::findHashH(treeNode* subtree, string mhash)
/**
 * Helper function that iterates through the tree
 * to find the hashed value it was passed
 */
{
	if (subtree->data == mhash)
	{
		ops++;
		found = true;
		return;
	}
	if (subtree->left != NULL) 
	{
		ops++;
		findHashH(subtree->left, mhash); //Recurse down the left
	}
	if (subtree->right != NULL)
	{
		ops++;
		findHashH(subtree->right, mhash);  //Recurse down the right
	}
}

/*
 * ---------------------------------------------------------------------------------------
 * Locate Functions
 *
 * locateData moves through the tree in postorder until the value is found, and
 * and the path it took to get there in terms of "L" and "R". 
 *
 * locateData checks to see if the data can be found using the find() function, if 
 * it is found then locateData function.
 *
 * Each locateData and locateDataH function corresponds to one of the hash functions.
 * Below is what hash function was used in each locate function:
 *
 * locateDataH & locateData --> hash_SamB
 * locateDataH1 & locateData1 --> hash_SamG
 * locateDataH1 & locateData2 --> hash_Easton
 * locateDataH1 & locateData3 --> hash_Dola
 *
 * Individual locates are needed for each hash function becasue the selectedHash
 * is predetermined in the constructor.
 * ---------------------------------------------------------------------------------------
 */

string pMT::locate(string input)
{
	if (selectedHash == 1)
	{
	return	locateDataH(input);
	}
	else if (selectedHash == 2)
	{
	return	locateDataH1(input);
	}
	else if (selectedHash == 3)
	{
		return locateDataH2(input);
	}
	else
	{
	return	locateDataH3(input);
	}
	
}

string pMT::locateDataH(string input)
{
	path = "- ";
	if (find(input))
	{
		locateData(myMerkle.getNode(), input, path);
		return path;
	}
	else
	{
		return "Input not located.";
	}
}

void pMT::locateData(treeNode* subtree, string vote, string pathway)
{
	if (hash_SamB(subtree->data) == hash_SamB(vote))
	{
		path = pathway;
		return;
	}

	if (subtree->left != NULL)
	{
		locateData(subtree->left, vote, pathway + "L ");
	}

	if (subtree->right != NULL)
	{
		locateData(subtree->right, vote, pathway + "R ");
	}
}

string pMT::locateDataH1(string input)
{
	path = "- ";
	if (find(input))
	{
		locateData1(myMerkle.getNode(), input, path);
		return path;
	}
	else
	{
		return "Input not located.";
	}
}

void pMT::locateData1(treeNode* subtree, string vote, string pathway)
{
	if (hash_SamG(subtree->data) == hash_SamB(vote))
	{
		path = pathway;
		return;
	}

	if (subtree->left != NULL)
	{
		locateData(subtree->left, vote, pathway + "L ");
	}

	if (subtree->right != NULL)
	{
		locateData(subtree->right, vote, pathway + "R ");
	}
}

string pMT::locateDataH2(string input)
{
	path = "- ";
	if (find(input))
	{
		locateData2(myMerkle.getNode(), input, path);
		return path;
	}
	else
	{
		return "Input not located.";
	}
}

void pMT::locateData2(treeNode* subtree, string vote, string pathway)
{
	if (hash_Easton(subtree->data) == hash_SamB(vote))
	{
		path = pathway;
		return;
	}

	if (subtree->left != NULL)
	{
		locateData(subtree->left, vote, pathway + "L ");
	}

	if (subtree->right != NULL)
	{
		locateData(subtree->right, vote, pathway + "R ");
	}
}

string pMT::locateDataH3(string input)
{
	path = "- ";
	if (find(input))
	{
		locateData3(myMerkle.getNode(), input, path);
		return path;
	}
	else
	{
		return "Input not located.";
	}
}

void pMT::locateData3(treeNode* subtree, string vote, string pathway)
{
	if (hash_Dola(subtree->data) == hash_SamB(vote))
	{
		path = pathway;
		return;
	}

	if (subtree->left != NULL)
	{
		locateData(subtree->left, vote, pathway + "L ");
	}

	if (subtree->right != NULL)
	{
		locateData(subtree->right, vote, pathway + "R ");
	}
}

/*
 * ---------------------------------------------------------------------------------------
 * Hashing Functions (Hashbrowns)
 * 
 * """""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
 * hash()
 * """""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
 * Looks at the selectedHash variable and choses what treeHash function to use
 *
 * """""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
 * treeHash()
 * """""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
 *
 * Moves through the tree in postorder until it reaches a parent node, then
 * the children nodes are hashed together i.e:
 * if c and hash(b) are children then the data of the parent = hash(c + hash(b)) 
 * note: hash(b) is just a data value.
 * 
 * There is one treeHash for every hash function, in each function the hashed used
 * is indicated like: treeHash_HashFunction. This is needed because the selectedHash
 * is set in the constructor and cannot be changed.
 * 
 * """""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
 * hash_Names()
 * """""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
 * 
 * Each hash function was written by each group member and each are based off of
 * previously used hash functions. What each one is based off of is in the functions
 *
 * ---------------------------------------------------------------------------------------
 */
void pMT::hash(treeNode* subtree)
{
	if (selectedHash == 1)
	{
		treeHash_SamB(subtree);
	}
	else if (selectedHash == 2)
	{
		treeHash_Easton(subtree);
	}
	else if (selectedHash == 3)
	{
		treeHash_Dola(subtree);
	}
	else
	{
		treeHash_SamG(subtree);
	}
}


void pMT::treeHash_SamG(treeNode* subtree)
{
	if(subtree->left != NULL && subtree->right != NULL)
	{
		treeHash_SamG(subtree->left);
		treeHash_SamG(subtree->right);
		subtree->data = hash_SamG(subtree->left->data + subtree->right->data);
	}
}
void pMT::treeHash_Easton(treeNode* subtree)
{
	if (subtree->left != NULL && subtree->right != NULL)
	{
		treeHash_Easton(subtree->left);
		treeHash_Easton(subtree->right);
		subtree->data = hash_Easton(subtree->left->data + subtree->right->data);
	}
}
void pMT::treeHash_SamB(treeNode* subtree)
{
	if (subtree->left != NULL && subtree->right != NULL)
	{
		treeHash_SamB(subtree->left);
		treeHash_SamB(subtree->right);
		subtree->data = hash_SamB(subtree->left->data + subtree->right->data);
	}
}
void pMT::treeHash_Dola(treeNode* subtree)
{
	if (subtree->left != NULL && subtree->right != NULL)
	{
		treeHash_Dola(subtree->left);
		treeHash_Dola(subtree->right);
		subtree->data = hash_Dola(subtree->left->data + subtree->right->data);
	}
}

string pMT::hash_SamB(string key)
//I used the ELF function from the previous lab.
// The main choice for this one was for christmas spirit
{

	unsigned int hash = 0;
	unsigned int x = 0;

	for (std::size_t i = 0; i < key.length(); i++)
	{
		hash = (hash << 4) + key[i];
		if ((x = hash & 0xF0000000L) != 0)
		{
			hash ^= (x >> 24);
		}
		hash &= ~x;
	}

	string stringHash = to_string(hash);
	return stringHash;
}

string pMT::hash_SamG(string key)
/**
 * Wrote on own
 */
{
	int seed(78498);
	int hash(0);
	for (int i = 0; i < key.size(); i++) {
		int temp = key[i] * seed;
		hash = (hash ^ (temp << 2) ^ (temp >> 15));
	}
	string sHash = to_string(hash);
	return sHash;
}

string pMT::hash_Dola(string key)
/**
 * Based on SDBM hash
 */
{
	    int hash = 0;
		int i = 0;
		int len = key.length();

		for (i = 0; i < len; i++)

		{
			hash = (key[i]) + (hash << 6) + (hash << 16) - hash;
		}

		string NEWHash = to_string(hash);
		return NEWHash;
}

string pMT::hash_Easton(string key)
/*
 *Adaptation of the FNVHash to return a hash as a string data type.
 */
{
	   int prime = 0x811C9DC5;
	   int hash = 0;

	   for(std::size_t i = 0; i < key.length(); i++)
	   {
	      hash *= prime;
	      hash ^= key[i];
	   }

	   string stringHash = to_string(hash);
	   return stringHash;
}
