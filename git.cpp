#include"git.h"
#include<fstream>
#include<string>
#include<iostream>

using namespace std;

//---------------------------------------------!!--GIT--!!---------------------------------------------//


		//----------------------------------GIT HASH FUNCTION----------------------------------//
int Git::hashFunction(string username, int size) const
{
	int totalSum = 0;
	for (int i = 0; i < username.length(); i++)  
	{
		totalSum += int(username[i]);     //Calculating Hash Value
	}
	int hashValue = totalSum % size;
	while (accounts[hashValue].username != " ")
	{
		hashValue++;
		if (hashValue == size)            //Wrapping Arround
		{
			hashValue = 0;
		}
	}
	return hashValue;
}


		//----------------------------------GIT LOGIN----------------------------------//
bool Git::CheckLogin(string user, string pass)
{
//-------------------Loading Accounts-------------------//
	int count;
	ifstream in;
	in.open("Count.txt");
	in >> count;
	in.close();

	accounts->totalAccounts = count * 2;
	accounts = new Account[count * 2];

	for (int i = 0; i < count * 2; i++)
	{
		accounts[i].username = " ";
	}

	in.open("Users.txt");

	int index;
	string userr, passs;
	for (int i = 0; i < count; i++)
	{
		in >> userr >> passs;
		index = hashFunction(user, count * 2);
		accounts[index].username = userr;
		accounts[index].password = passs;
	}
//-------------------Loading Accounts------------------//


//---------------------Hash Search--------------------//
	int totalSum = 0;
	for (int i = 0; i < user.length(); i++)
	{
		totalSum += int(user[i]);							//Calculating Hash Value
	}
	int hashValue = totalSum % (count*2);
	while (accounts[hashValue].username != " " && accounts[hashValue].username != user)
	{
		if (hashValue == accounts->totalAccounts)            //Wrapping Arround
		{
			hashValue = 0;
		}
		hashValue++;
	}
	if (accounts[hashValue].username == user && accounts[hashValue].password == pass)
	{
		return true;  //Return True if user is allowed to SignIn
	}
	return false;     //Return False if user is not allowed to SignIn

//---------------------Hash Search--------------------//
}


//---------------------------------------------!!--ACCOUNT--!!---------------------------------------------//

int Account::totalAccounts = 0;

		//----------------------------------Account Register----------------------------------//
bool Account::regsiter(string username, string password)
{
	Repos rp;
	ifstream in;
	bool valid;
	in.open("Users.txt");
	
	string usrr, pss;
	while (!in.eof())				//Check if User is Already Registered or not
	{
		in >> usrr >> pss;
		if (username == usrr)
		{
			valid = false;
		}
	}
	in.close();
	valid = true;

	if (valid)
	{
		ofstream out;
		out.open("Users.txt", ios::app);
		out << username << endl << password << endl;
		out.close();

		int count;
		ifstream in;
		in.open("Count.txt");
		in >> count;
		in.close();

		out.open("Count.txt");
		count++;
		out << count;
		out.close();

		rp.addToRepo(username);     //add user to repo file

		return true;
	}
	return false;
}


//---------------------------------------------!!--REPOS--!!---------------------------------------------//

		//----------------------------------Repos Tree----------------------------------//
void Repos::Tree(string x)
{
	if (x == "load")			//Load Tree
	{
		ifstream in;
		in.open("Repositories.txt");

		int users, repos, files;
		string str;
		in >> users;
		node = new Node;
		node->childs = new Node[users];
		node->ch = users;

		for (int i = 0; i < users; i++)
		{
			in >> str;
			node->childs[i].data = str;
			in >> repos;
			node->childs[i].childs = new Node[repos];
			node->childs[i].ch = repos;
			for (int j = 0; j < repos; j++)
			{
				in >> str;
				node->childs[i].childs[j].data = str;
				in >> files;
				node->childs[i].childs[j].childs = new Node[files];
				node->childs[i].childs[j].ch = files;
				for (int k = 0; k < files; k++)
				{
					in >> str;
					node->childs[i].childs[j].childs[k].data = str;
				}
			}
		}
		in.close();
	}
	else if (x == "unload")			//UnLoad Tree
	{
		ofstream out;
		out.open("Repositories.txt");
		out << node->ch << endl;

		for (int i = 0; i < node->ch; i++)
		{
			out << node->childs[i].data << endl;
			out << node->childs[i].ch << endl;
			for (int j = 0; j < node->childs[i].ch; j++)
			{
				out << node->childs[i].childs[j].data << endl;
				out << node->childs[i].childs[j].ch << endl;
				for (int k = 0; k < node->childs[i].childs[j].ch; k++)
				{
					out << node->childs[i].childs[j].childs[k].data << endl;
				}
			}
		}
	}
}

		//-----------------------Repos Add user to repo file-----------------------//
void Repos::addToRepo(string user)    //Adds a user registered to repo file
{
	ifstream in;
	in.open("Repositories.txt");

	int users, repos, files;
	string str;
	in >> users;
	node = new Node;
	node->childs = new Node[users];
	node->ch = users;

	for (int i = 0; i < users; i++)
	{
		in >> str;
		node->childs[i].data = str;
		in >> repos;
		node->childs[i].childs = new Node[repos];
		node->childs[i].ch = repos;
		for (int j = 0; j < repos; j++)
		{
			in >> str;
			node->childs[i].childs[j].data = str;
			in >> files;
			node->childs[i].childs[j].childs = new Node[files];
			node->childs[i].childs[j].ch = files;
			for (int k = 0; k < files; k++)
			{
				in >> str;
				node->childs[i].childs[j].childs[k].data = str;
			}
		}
	}
	in.close();

	ofstream out;
	out.open("Repositories.txt");
	out << node->ch+1 << endl;

	for (int i = 0; i < node->ch; i++)
	{
		out << node->childs[i].data << endl;
		out << node->childs[i].ch << endl;
		for (int j = 0; j < node->childs[i].ch; j++)
		{
			out << node->childs[i].childs[j].data << endl;
			out << node->childs[i].childs[j].ch << endl;
			for (int k = 0; k < node->childs[i].childs[j].ch; k++)
			{
				out << node->childs[i].childs[j].childs[k].data << endl;
			}
		}
	}

	out << user << endl << 0 << endl;
}

		//-----------------------Repos Add/Del/Search/Commit/Search_Repo_Details Repo-----------------------//
bool Repos::Repo(string user, string repoName, string x)
{
	Tree("load");
	if (x == "add")			//Add Repo
	{
		ifstream in;
		in.open("Repositories.txt");

		int users, repos, files;
		string str;
		in >> users;
		node = new Node;
		node->childs = new Node[users];
		node->ch = users;

		for (int i = 0; i < users; i++)
		{
			in >> str;
			node->childs[i].data = str;
			in >> repos;
			if (str == user)
			{
				repos++;
			}
			node->childs[i].childs = new Node[repos];
			node->childs[i].ch = repos;
			for (int j = 0; j < repos; j++)
			{
				if (node->childs[i].data == user && j == repos - 1)
				{
					node->childs[i].childs[j].data = repoName;
					node->childs[i].childs[j].ch = 0;
				}
				else
				{
					in >> str;
					node->childs[i].childs[j].data = str;
					in >> files;
					node->childs[i].childs[j].childs = new Node[files];
					node->childs[i].childs[j].ch = files;
					for (int k = 0; k < files; k++)
					{
						in >> str;
						node->childs[i].childs[j].childs[k].data = str;
					}
				}
			}
		}
		in.close();
		Tree("unload");
		return true;
	}
	else if (x == "delete")			//Delete Repo
	{
		Tree("load");

		if (!Repo(user, repoName, "search"))
		{
			return false;
		}

		ofstream out;
		out.open("Repositories.txt");
		out << node->ch << endl;

		for (int i = 0; i < node->ch; i++)
		{
			out << node->childs[i].data << endl;
			if (node->childs[i].data == user)
			{
				out << node->childs[i].ch - 1 << endl;
			}
			else
			{
				out << node->childs[i].ch << endl;
			}
			for (int j = 0; j < node->childs[i].ch; j++)
			{
				if (node->childs[i].data != user && node->childs[i].childs[j].data != repoName)
				{
					out << node->childs[i].childs[j].data << endl;
					out << node->childs[i].childs[j].ch << endl;
					for (int k = 0; k < node->childs[i].childs[j].ch; k++)
					{
						out << node->childs[i].childs[j].childs[k].data << endl;
					}
				}
			}
		}
		return true;
	}
	else if (x == "search")			//Search Repo
	{
		bool flag = false;
		for (int i = 0; i < node->ch; i++)
		{
			for (int j = 0; j < node->childs[i].ch; j++)
			{
				if (node->childs[i].data != user)
				{
					break;
				}
				else if (node->childs[i].data == user && node->childs[i].childs[j].data == repoName)
				{
					return true;
				}
			}
		}
		return false;
	}
	else if (x == "commit")			//Commit Repo
	{
		Tree("load");
		for (int i = 0; i < node->ch; i++)
		{
			for (int j = 0; j < node->childs[i].ch; j++)
			{
				if (node->childs[i].childs[j].data == repoName)
				{
					node->childs[i].childs[j].comits++;
				}
			}
		}
	}
	else if (x == "searchRepoDetails")			//Search Repo Details
	{
		Tree("load");
		bool flag = false;
		for (int i = 0; i < node->ch; i++)
		{
			for (int j = 0; j < node->childs[i].ch; j++)
			{
				if (node->childs[i].childs[j].data == repoName)
				{
					cout << "\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl;
					cout << "\t\t\t==> User        :  " << node->childs[i].data << endl;
					cout << "\t\t\t==> Repo Name   :  " << node->childs[i].childs[j].data << endl;
					cout << "\t\t\t==> Total Files :  " << node->childs[i].childs[j].ch << endl;
					cout << "\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl << endl;
					return true;
				}
			}
		}
		return false;
	}
}

//----------------------------------Repos Add/Delete/Search File----------------------------------//
bool Repos::File(string user, string repoName, string fileName, string x)
{
	if (x == "add")
	{
		ifstream in;
		in.open("Repositories.txt");

		int users, repos, files;
		string str;
		in >> users;
		node = new Node;
		node->childs = new Node[users];
		node->ch = users;

		for (int i = 0; i < users; i++)
		{
			in >> str;
			node->childs[i].data = str;
			in >> repos;
			node->childs[i].childs = new Node[repos];
			node->childs[i].ch = repos;
			for (int j = 0; j < repos; j++)
			{
				in >> str;
				node->childs[i].childs[j].data = str;
				in >> files;
				if (node->childs[i].data == user && node->childs[i].childs[j].data == repoName)
				{
					files++;
				}
				node->childs[i].childs[j].childs = new Node[files];
				node->childs[i].childs[j].ch = files;
				for (int k = 0; k < files; k++)
				{
					if (node->childs[i].data == user && node->childs[i].childs[j].data == repoName && k == files - 1)
					{
						node->childs[i].childs[j].childs[k].data = fileName;
					}
					else
					{
						in >> str;
						node->childs[i].childs[j].childs[k].data = str;
					}
				}
			}
		}
		in.close();
		Tree("unload");
	}
	else if (x == "delete")
	{
		Tree("load");

		if (!File(user, repoName, fileName, "search"))
		{
			return false;
		}

		ofstream out;
		out.open("Repositories.txt");

		out << node->ch << endl;
		for (int i = 0; i < node->ch; i++)
		{
			out << node->childs[i].data << endl;
			out << node->childs[i].ch << endl;
			for (int j = 0; j < node->childs[i].ch; j++)
			{
				out << node->childs[i].childs[j].data << endl;
				if (node->childs[i].data == user && node->childs[i].childs[j].data == repoName)
				{
					out << node->childs[i].childs[j].ch - 1 << endl;
				}
				else
				{
					out << node->childs[i].childs[j].ch << endl;
				}
				for (int k = 0; k < node->childs[i].childs[j].ch; k++)
				{
					if (node->childs[i].data == user && node->childs[i].childs[j].data == repoName && node->childs[i].childs[j].childs[k].data == fileName)
					{}
					else
					{
						out << node->childs[i].childs[j].childs[k].data << endl;
					}
				}
			}
		}
		return true;
	}
	else if (x == "search")
	{
		for (int i = 0; i < node->ch; i++)
		{
			for (int j = 0; j < node->childs[i].ch; j++)
			{
				for (int k = 0; k < node->childs[i].childs[j].ch; k++)
				{
					if (node->childs[i].data != user || node->childs[i].childs[j].data != repoName)
					{
						break;
					}
					else if (node->childs[i].data == user && node->childs[i].childs[j].data == repoName && node->childs[i].childs[j].childs[k].data == fileName)
					{
						return true;
					}
				}
			}
		}
		return false;
	}
}
