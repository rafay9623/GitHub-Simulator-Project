#ifndef GIT_H
#define GIT_H

#include<iostream>
#include<string>

using namespace std;

//-------------------------------------------ACCOUNT-------------------------------------------//
class Account
{
private:
	string username, password;
	static int totalAccounts;
	friend class Git;
public:
	bool regsiter(string username, string password);
};


//-------------------------------------------GIT-------------------------------------------//
class Git
{
private:
	Account* accounts;
	int hashFunction(string username, int size) const;
public:
	bool CheckLogin(string user, string pass);
};


//-------------------------------------------NODE-------------------------------------------//
class Node
{
public:
	string data;
	int ch;
	Node* childs;
	int comits;
	Node():comits(0){}
};


//-------------------------------------------REPOS-------------------------------------------//
class Repos
{
private:
	Node* node;
	void Tree(string x);  //For Load and Unload Tree
public:
	void addToRepo(string user);
	bool Repo(string user, string repoName, string x); //Add/Del/Search/Commit/Search_Repo_Details
	bool File(string user, string repoName, string fileName, string x);	//Add/Del/Search File
};

#endif // !GIT_H
