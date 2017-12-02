/*
bTREE_test.cpp
Sam Blair, Oyedola Ajao, Sam Goering, and Easton Tuttle
Computer Science II
Homework 5 - Merkle Votes
November 27, 2017

The testing program for the Merkle voting tree.
*/

#include "stdafx.h"
#include "pMT.h"
#include <iostream>
#include <stdio.h>

using namespace std;

//int main(int argc, char **argv)
//{
//	// Test of bTREE functions.
//
//	// Initialization of binary tree.
//	bTREE binary = bTREE();
//	bTREE binaryTwo = bTREE();
//	bTREE binaryThree = bTREE();
//
//	// Insert 5 nodes into the binary tree.
//	binary.insert("Test One", 3);
//	binary.insert("Test Two", 4);
//	binary.insert("Test Three", 1);
//	binary.insert("Test Four", 3);
//	binary.insert("Test Five", 11);
//
//	// Insert the same nodes as binary to binaryTwo in order to create equal trees for comparison.
//	binaryTwo.insert("Test One", 3);
//	binaryTwo.insert("Test Two", 4);
//	binaryTwo.insert("Test Three", 1);
//	binaryTwo.insert("Test Four", 3);
//	binaryTwo.insert("Test Five", 11);
//
//	// Insert into binaryThree in order to be different than binary.
//	binaryThree.insert("Test Three", 1);
//	binaryThree.insert("Test Four", 3);
//	binaryThree.insert("Test Five", 11);
//
//	// Display the binary tree.
//	cout << "Binary\n";
//	binary.display(cout);
//	cout << "Binary Two\n";
//	binaryTwo.display(cout);
//	cout << "Binary Three\n";
//	binaryThree.display(cout);
//
//	// Attempt to find "Test One" and "Test Seven" within the tree and provide feedback whether the input was found or not.
//	if (binary.find("Test One"))
//	{
//
//		cout << "Binary tree node containing Test One has been found.\n";
//
//	}
//	else
//	{
//
//		cout << "Binary tree node containing Test One has not been found.\n";
//
//	}
//
//	if (binary.find("Test Five"))
//	{
//
//		cout << "Binary tree node containing Test Five has been found.\n";
//
//	}
//	else
//	{
//
//		cout << "Binary tree node containing Test Five has not been found.\n";
//
//	}
//
//	if (binary.find("Test Seven"))
//	{
//
//		cout << "Binary tree node containing Test Seven has been found.\n";
//
//	}
//	else
//	{
//
//		cout << "Binary tree node containing Test Seven has not been found.\n";
//
//	}
//
//	// Attempt to locate "Test One", "Test Five", and "Test Seven". Print the paths that are returned.
//	cout << binary.locate("Test One") << "\n";
//	cout << binary.locate("Test Five") << "\n";
//	cout << binary.locate("Test Seven") << "\n";
//	cout << binaryTwo.locate("Test Three") << "\n";
//
//	// Test whether two trees are equal to each other.
//
//	// Test against two equal trees.
//	if (binary.compare(binaryTwo))
//	{
//		cout << "Binary is equal to binaryTwo.\n";
//	}
//	else
//	{
//		cout << "Binary is not equal to binaryTwo.\n";
//	}
//
//	// Compare two unequal trees.
//	if (binary.compare(binaryThree))
//	{
//		cout << "Binary is equal to binaryThree.\n";
//	}
//	else
//	{
//		cout << "Binary is not equal to binaryThree.\n";
//	}
//
//	// Test the dataInserted function (counts the number of leaves in a tree.)
//	cout << "Binary contains: " << binary.dataInserted() << " leaves.\n";
//	cout << "BinaryThree contains: " << binaryThree.dataInserted() << " leaves.\n";
//
//	// Test the numberOfNodes function.
//	cout << "Binary contains: " << binary.numberOfNodes() << " nodes.\n";
//	cout << "BinaryThree contains: " << binaryThree.numberOfNodes() << " nodes.\n";
//}