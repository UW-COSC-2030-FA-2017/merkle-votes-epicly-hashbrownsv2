/*
vote.cpp
Sam Blair, Oyedola Ajao, Sam Goering, and Easton Tuttle
Computer Science II
Homework 5 - Merkle Votes
December 1, 2017
Driver file for merkel tree
*/

#include "stdafx.h"
#include "pMT.h"
#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
	//Declaration of needed variables
	ifstream compFile;
	ifstream voteFile;
	string fileName;
	string choice;
	string vote;
	int time;

	// Get file name from the user.
	cout << "Please enter the name of the voting file: ";
	getline(cin, fileName);
	voteFile.open(fileName);

	// If the file name is invalid, loop until valid.
	while (voteFile.fail())
	{
		cout << "The file could not be opened. Please check the spelling of the file name and ensure the file exists.\n\n";
		cout << "Please enter the name of the voting file: ";
		getline(cin, fileName);
		voteFile.open(fileName);
	}

	// Ask the user to select a hash function.
	cout << "Please select a hash function to use:\n";
	cout << "1. Sam Blair's hash\n";
	cout << "2. Sam Goering's hash\n";
	cout << "3. Oyedola Ajao's hash\n";
	cout << "4. Easton Tuttle's hash\n";

	// Get the user's input and pass it into the merkle tree constructor.
	int hashChoice(0);
	getline(cin, choice);
	if (choice == "1") { hashChoice = 1; }
	else if (choice == "2") { hashChoice = 2; }
	else if (choice == "3") { hashChoice = 3; }
	else if (choice == "4") { hashChoice = 4; }
	else {
		hashChoice = 1;
		cout << "Invalid input, Hash set to 1" << endl;
	}
	pMT merkleTree = pMT(hashChoice);
	pMT compTree = pMT(hashChoice); //Make the compare tree's hash the same as the origial

	// While not at the end of the file, insert each vote into the tree
	// and display the merkle tree
	while (!voteFile.eof())
	{
		voteFile >> vote >> time;
		merkleTree.insert(vote, time);
	}
	merkleTree.accessbTREE().display(cout);

	//Ask the user if they want to compare the first merkel tree
	// to another tree and the file name
	cout << "Do you want to compare another tree? (Y/N)" << endl;
	getline(cin, choice);

	//if wanting to compare take in a file and if not a file ask user again
	if (choice == "Y" || choice == "y")
	{
		cout << "Please enter the name of the voting file: ";
		getline(cin, fileName);
		compFile.open(fileName);

		while (compFile.fail())
		{
			cout << "The file could not be opened. Please check the spelling of " <<
				"the file name and ensure the file exists.\n\n";
			cout << "Please enter the name of the voting file: ";
			getline(cin, fileName);
			compFile.open(fileName);
		}
		//Build a new merkel tree 
		while (!compFile.eof())
		{
			compFile >> vote >> time;
			compTree.insert(vote, time);
		}
		//Compare: if they are the same output equal statement
		if (merkleTree.accessbTREE().compare(compTree.accessbTREE()))
		{
			cout << "The files are the same" << endl;
		}
		//Compare: if the are not the same output not equal statment
		else
		{
			cout << "The trees are not the same" << endl;
		}
		compFile.close();
	}
	//If N was inputed exit program
	else
	{
		cout << "Your answer was no. Please have a nice day!" << endl;
	}
	voteFile.close();

	//return 0 is after commented testing functions

	//Different test for the functions
	//-------------------------------------------------------------

	//// Test of pMT functions.
	//pMT merkleOne =  pMT(1);
	//pMT merkleTwo = pMT(2);

	//// Insert five tree nodes into the merkleOne tree.
	//merkleOne.insert("Test One", 3);
	//merkleOne.insert("Test Two", 4);
	//merkleOne.insert("Test Three", 1);
	//merkleOne.insert("Test Four", 3);
	//merkleOne.insert("Test Five", 11);

	//// Display the tree before and after hashed.
	//cout << "Merkle One\n";
	//merkleOne.accessbTREE().display(cout);
	//merkleOne.hash(merkleOne.accessbTREE().getNode());
	//cout << "\n\nMerkle One\n";
	//merkleOne.accessbTREE().display(cout);
	//cout << "\n\nMerkle Two\n";
	//merkleTwo.accessbTREE().display(cout);
	//merkleTwo.hash(merkleTwo.accessbTREE().getNode());
	//cout << "\n\nMerkle Two\n";
	//merkleTwo.accessbTREE().display(cout);

	//Hash Brown Recipe

	//// If findHash returns 1 or 0, print out found for 1 or not found for 0.
	//// Test findHash on a hash in the tree.
	//if (merkleOne.findHash("170564485") > 0)
	//{
	//	cout << "The hash has been found." << endl;
	//}
	//else
	//{
	//	cout << "The hash has not been found." << endl;
	//}
	//
	//// Test findHash on a hash in the tree.
	//if (merkleOne.findHash("12900930") > 0)
	//{
	//	cout << "The hash has been found." << endl;
	//}
	//else
	//{
	//	cout << "The hash has not been found." << endl;
	//}

	//Ingredients:
	//	-two potatoes
	//	- three table spoons of of butter
	//	- one pinch of cyan pepper
	//	- one pinch of paprika, or more whatever you feel
	//	- salt and pepper, once again however much you want
	//// Test findHash on a hash not in the tree.

	//if (merkleOne.findHash("t") > 0)
	//{
	//	cout << "The hash has been found." << endl;
	//}
	//else
	//{
	//	cout << "The hash has not been found." << endl;
	//}
	//// Insert returns the number of operations taken to insert into a tree.
	//cout << "\nNumber of operations to insert into a tree of five nodes: " << merkleOne.insert("Operations", 100);
	//cout << "\nNumber of operations to insert to an empty tree: " << merkleOne.insert("Operations", 56) << "\n";
	/*
	Cooking Directions:
	1.)Shred potatoes into a large bowl filled with cold water.
	Stir until water is cloudy, drain, and cover potatoes again with fresh cold water.
	Stir again to dissolve excess starch.
	Drain potatoes well, pat dry with paper towels, and squeeze out any excess moisture.

	2.)Heat clarified butter in a large non-stick pan over medium heat.
	Sprinkle shredded potatoes into the hot butter and season
	with salt, black pepper, cayenne pepper, and paprika.

	3.)Cook potatoes until a brown crust forms on the bottom, about 5 minutes.
	Continue to cook and stir until potatoes are browned all over, about 5 more minutes.

	4.) Serve with ketcup aka totmato sauce
	*/
	return 0;
}