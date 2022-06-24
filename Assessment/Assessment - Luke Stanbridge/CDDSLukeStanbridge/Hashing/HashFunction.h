#pragma once
#include <iostream>
#include <list>
#include <cstring>
#include <unordered_map>
#include "raylib.h"
using namespace std;

class HashTable
{
private:
	static const int buckets = 20;
	
	struct typeOfHashy
	{
		string type;
		Texture2D pngFile;
		typeOfHashy* next;
	};
	typeOfHashy* HashyTable[buckets];

public:
	HashTable();
	int hashFunction(string key); // hash function
	void insert(string type, Texture2D pngFile); // insert into hash table
	void draw(); // draw function to show what entries are in the table
	void print(); // print function to show what is in each individual bucket
	void get(string type); // get 
};