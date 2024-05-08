#include"git.h"       //Header File
#include<fstream>
#include<string>
#include<iostream>

using namespace std;

int main()
{
	string user, pass, repoName, fileName;
	int val, val2;
	Account account;    //Account Class Variable
	Git git{};          //Git Class Variable
	Repos repos{};      //Repos Class Variable
	bool log = false;
	do
	{
		system("cls");
		cout << "\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl;
		cout << "\t\t\t\t     !!--Welcome to Git Simulator--!!" << endl;
		cout << "\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl << endl << endl << endl;

		cout << "==> Please Select an Option: " << endl << endl;
		cout << "====> 1.  SIGNUP" << endl;
		cout << "====> 2.  SIGNIN" << endl;
		cout << "====> 3.  EXIT" << endl;

		cout << "\nEnter:    ";
		cin >> val;
		system("pause");
		system("cls");

		if (val == 1)
		{
			cout << endl << endl << "==> Enter Username : \n====> ";
			cin >> user;
			cout << endl << endl <<"==> Enter Password : \n====> ";
			cin >> pass;
			cout << endl;
			if (account.regsiter(user, pass))
			{
				cout << "\n\n\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl;
				cout << "\t\t\t\t      !!--SUCCESSFULLY SIGNEDUP--!!" << endl;
				cout << "\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl << endl;
			}
			else
			{
				cout << "\n\n\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl;
				cout << "\t\t\t\t         !!--INVALID USERNAME--!!" << endl;
				cout << "\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl << endl;
			}
			system("pause");
		}
		else if (val == 2)
		{
			cout << endl << endl << "==> Enter Username : \n====> ";
			cin >> user;
			cout << endl << endl << "==> Enter Password : \n====> ";
			cin >> pass;
			cout << endl;
			log = git.CheckLogin(user, pass);
			if (log)
			{
				cout << "\n\n\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl;
				cout << "\t\t\t\t       !!--SUCCESSFULLY SIGNEDIN--!!" << endl;
				cout << "\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl << endl;
			}
			else
			{
				cout << "\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl;
				cout << "\t\t\t\t    !!--INVALID USERNAME/PASSWORD--!!" << endl;
				cout << "\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl << endl;
			}
			system("pause");
		}
		if (log)
		{
			do
			{
				system("cls");
				cout << "\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl;
				cout << "\t\t\t\t           !!--Git Simulator--!!" << endl;
				cout << "\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl << endl << endl << endl;
				cout << "\n\n==> Please Select an Option:" << endl << endl;
				cout << "====> 1.  Create Repository" << endl;
				cout << "====> 2.  Remove Repository" << endl;
				cout << "====> 3.  Create File in Repository" << endl;
				cout << "====> 4.  Remove File from Repository" << endl;
				cout << "====> 5.  Search a Repository" << endl;
				cout << "====> 6.  Search a File in Repository" << endl;
				cout << "====> 7.  Commit in Repository" << endl;
				cout << "\nEnter:    ";
				cin >> val2;
				cout << endl << endl;
				system("pause");
				system("cls");

				cout << "\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl;
				cout << "\t\t\t\t           !!--Git Simulator--!!" << endl;
				cout << "\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl << endl << endl << endl;

				cout << "==> Enter Repo Name:\n====> ";
				cin >> repoName;

				if (val2 == 1)
				{
					repos.Repo(user, repoName, "add");
					cout << "\n\n\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl;
					cout << "\t\t\t\t       !!--REPOSITORY ADDED--!!" << endl;
					cout << "\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl << endl;
				}
				else if (val2 == 2)
				{
					if (repos.Repo(user, repoName, "delete"))
					{
						cout << "\n\n\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl;
						cout << "\t\t\t\t       !!--REPOSITORY DELETED--!!" << endl;
						cout << "\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl << endl;
					}
					else
					{
						cout << "\n\n\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl;
						cout << "\t\t\t\t     !!--REPOSITORY NOT DELETED--!!" << endl;
						cout << "\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl << endl;
					}
				}
				else if (val2 == 3)
				{
					cout << endl << endl << "==> Enter File Name:\n====> ";
					cin >> fileName;
					repos.File(user, repoName, fileName, "add");
					cout << "\n\n\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl;
					cout << "\t\t\t\t         !!--FILE ADDED--!!" << endl;
					cout << "\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl << endl;
				}
				else if (val2 == 4)
				{
					cout << endl << endl << "==> Enter File Name:\n====> ";
					cin >> fileName;
					if (repos.File(user, repoName, fileName, "delete"))
					{
						cout << "\n\n\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl;
						cout << "\t\t\t\t       !!--FILE DELETED--!!" << endl;
						cout << "\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl << endl;
					}
					else
					{
						cout << "\n\n\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl;
						cout << "\t\t\t\t        !!--FILE NOT DELETED--!!" << endl;
						cout << "\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl << endl;
					}
				}
				else if (val2 == 5)
				{
					if (!repos.Repo(" ", repoName, "searchRepoDetails"))
					{
						cout << "\n\n\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl;
						cout << "\t\t\t\t       !!--REPOSITORY NOT FOUND--!!" << endl;
						cout << "\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl << endl;
					}
				}
				else if (val2 == 6)
				{
					cout << endl << endl << "==> Enter File Name:\n====> ";
					cin >> fileName;
					if (!repos.File(" ", repoName, fileName, "searchRepoDetails"))
					{
						cout << "\n\n\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl;
						cout << "\t\t\t\t       !!--File NOT FOUND--!!" << endl;
						cout << "\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl << endl;
					}
					else
					{
						cout << "\n\n\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl;
						cout << "\t\t\t\t       !!--File FOUND--!!" << endl;
						cout << "\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl << endl;
					}
				}
				else if (val2 == 7)
				{
					repos.Repo(" ", repoName,"commit");
					cout << "\n\n\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl;
					cout << "\t\t\t\t     !!--REPOSITORY COMMITED--!!" << endl;
					cout << "\t\t\t\t<=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=>" << endl << endl;
				}
				cout << endl;
				system("pause");
			} while (val2);
		}
	} while (val != 3);

	system("pause");
	return 0;
}

