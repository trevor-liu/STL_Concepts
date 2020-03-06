#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;


struct StudentRecord
{
	string name;
	int id;
	int grade;

	// overload the operator to check if the id is the same, since the id is used for hashing
	bool operator ==(const StudentRecord &obj) const
	{
		if (id == obj.id)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

// Overload the function hash which takes in StudentRecord struct and hash the student id instead
template<>
struct hash<StudentRecord>
{
	size_t operator()(const StudentRecord &obj) const
	{
		return hash<int>()(obj.id);
	}
};

int main()
{
	
	unordered_set<StudentRecord> table;

	// this is used for retriving studentrecord from student's id
	unordered_map<int, StudentRecord> studentIDmap;

	bool Stop_searching = false;
	string n;
	int i, g;
	StudentRecord student;

	while(!Stop_searching) 
	{
		// Read in the action that the user wants to make
		char action;
		cin >> action;
		if (action == 'I')
		{
			// Inserting new student into the table
			cin >> n >> i >> g;
			student = {n, i , g};

			// if the studentID wasn't in the table (hence not in the studentIDmap), insert the student, otherwise print error.
			if (studentIDmap.find(i) == studentIDmap.end())
			{
				table.insert(student);
				studentIDmap[i] = student;
			}
			else
			{
				cout << "Error: Cannot insert duplicate ID" << endl;
			}

		}
		else if (action == 'R')
		{
			// removing student using student's id
			cin >> i;

			// if the student ID is in the table, remove it.
			if (studentIDmap.find(i) != studentIDmap.end())
			{
				// return the student's StudentRecord
				student = studentIDmap.find(i)->second;
				
				// erase student's studentrecord, remove both from ID to record map, and from the table
				table.erase(student);
				studentIDmap.erase(i);
			}
			else
			{
				cout << "Error: Cannot remove non-existent ID" << endl;
			}
			
		}
		else if (action == 'Q')
		{
			char test;
			cin >> test;

			// find student record from name
			if (test == 'n')
			{
				string testname;
				bool foundname = false;
				cin >> testname;
				// iterate through table to find the name and print the studentrecord
				for (auto j : table)
				{
					if (j.name == testname)
					{
						foundname = true;
						cout << "Name: " << j.name << ", ID: " << j.id << ", Grade: " << j.grade << endl;
					}
				}
				if (foundname == false)
				{
					cout << "Error: No matches found" << endl;
				}
			}
			// find student record from ID
			else if (test == 'i')
			{
				int testid;
				bool foundid = false;
				cin >> testid;
				for (auto j : table)
				{
					if (j.id == testid)
					{
						foundid = true;
						cout << "Name: " << j.name << ", ID: " << j.id << ", Grade: " << j.grade << endl;
					}
				}
				if (foundid == false)
				{
					cout << "Error: No matches found" << endl;
				}	
			}
			// find student record from grade
			else
			{
				int testgrade;
				bool foundgrade = false;
				cin >> testgrade;
				for (auto j : table)
				{
					if (j.grade == testgrade)
					{
						foundgrade = true;
						cout << "Name: " << j.name << ", ID: " << j.id << ", Grade: " << j.grade << endl;
					}
				}
				if (foundgrade == false)
				{
					cout << "Error: No matches found" << endl;
				}
			}
			
		}
		else if (action == 'S')
		{
			// stop the program
			Stop_searching = true;
		}
	}



	return 0;
}