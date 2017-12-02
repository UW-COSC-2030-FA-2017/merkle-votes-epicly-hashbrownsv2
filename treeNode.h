/*
treeNode.h
Sam Blair, Oyedola Ajao, and Easton Tuttle
Computer Science II
Homework 5 - Merkle Votes
December 1, 2017

The treeNode structure.
*/

#pragma once
#ifndef TREENODE_H
#define TREENODE_H

#include <string>

using std::string;

// Nodes of the tree which hold a pseudo-time stamp (integer, non-unique,)
// a 128-bit data component (string of 32 characters,)
// have 2 pointers to type node, and be differentiable
// if a leaf or not.
struct treeNode
{
	int time;
	string data;
	treeNode *left;
	treeNode *right;
	bool isLeaf = true;

	// Default constructor which sets all values to a "zero or null" state.
	treeNode()
	{
		time = 0;
		data = "";
		left = NULL;
		right = NULL;
		isLeaf = true;
	}

	// Constructor which sets the data to the paramater passed in.
	treeNode(string newData)
	{
		time = 0;
		data = newData;
		left = NULL;
		right = NULL;
		isLeaf = true;
	}

	// Constructor which sets the data to the paramaters passed in.
	treeNode(string newData, int newTime)
	{
		time = newTime;
		data = newData;
		left = NULL;
		right = NULL;
		isLeaf = true;
	}
	//Mutator function to set data
	void set_data(string new_data, int new_time, bool new_leaf)
	{
		data = new_data;
		time = new_time;
		isLeaf = new_leaf;
	}
};

#endif