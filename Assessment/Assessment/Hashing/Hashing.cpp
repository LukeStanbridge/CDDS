#include "Hashing.h"
#include <iostream>
#include<list>
#include<cstring>
#include <sstream>
using namespace std;

HashTable::HashTable()
{
	for (int i = 0; i < buckets; i++) // populate hash table
	{
		HashyTable[i] = new typeOfHashy;
		HashyTable[i]->type = "empty";
		HashyTable[i]->pngFile;
		HashyTable[i]->next = NULL;
	}
}

int HashTable::hashFunction(string key) // function to index the key
{
	int hash = 0;
	int index;
	
	for (int i = 0; i < key.length(); i++)
	{
		hash = hash + (int)key[i];
	}

	index = hash % buckets; // index the key 
	return index;
}

void HashTable::insert(string type, Texture2D pngFile)
{
	int hashValue = hashFunction(type); // need hashed value to correspond to the key

	// insert data into hash table if spot is empty
	if (HashyTable[hashValue]->type == "empty")
	{
		HashyTable[hashValue]->type = type;
		HashyTable[hashValue]->pngFile = pngFile;
	}
	// if spot in hash table is full then move to next available spot
	else
	{
		typeOfHashy* Ptr = HashyTable[hashValue];
		typeOfHashy* n = new typeOfHashy;
		n->type = type;
		n->pngFile = pngFile;
		n->next = NULL;
		while (Ptr->next != NULL)
		{
			Ptr = Ptr->next;
		}
		Ptr->next = n;
	}
}

void HashTable::draw()
{
	const char* tmp;

	int widthPos = 400;
	int heightPos = 200;

	for (int i = 0; i < buckets; i++)
	{
		// Draw everything stored in the hash table that isn't empty
		if (HashyTable[i]->type != "empty")
		{
			tmp = HashyTable[i]->type.c_str(); // stores key as const char
			DrawText(tmp, widthPos + 30, 170, 20, RED);
			DrawTexture(HashyTable[i]->pngFile, widthPos, heightPos, WHITE);
			widthPos += 200; // stagger output
		}
	}
}

void HashTable::print()
{
	const char* tmp;
	int counter = 0; // counter for labeling

	int widthPos = 150;
	int heightPos = 100;

	DrawText("[All buckets in hash table]", 70, 70, 20, RED);

	// search through all buckets in hash table
	for (int i = 0; i < buckets; i++)
	{
		// print list of the hash table
		if (HashyTable[i] != NULL)
		{
			string number = to_string(counter); // convert count to string
			tmp = HashyTable[i]->type.c_str(); // stores as const char
			DrawText(number.c_str(), widthPos, heightPos, 20, RED);
			DrawText(tmp, widthPos + 30, heightPos, 20, RED);
			heightPos += 30; // stagger the text
			counter++;
		}
	}
}

void HashTable::get(string type) 
{
	const char* tmp;
	int hashValue = hashFunction(type); // get hash value through key
	tmp = HashyTable[hashValue]->type.c_str(); // convert string to const char for drawing text

	// Draw output for raylib
	DrawText("[Using the get function]", 340, 400, 20, RED);
	DrawText(tmp, 435, 430, 20, RED);
	DrawTexture(HashyTable[hashValue]->pngFile, 400, 460, WHITE);
}