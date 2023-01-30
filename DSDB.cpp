#include"DSDB.h"
int FieldToInt(string field)
{
	if (toLower(field) == "id") { return 1; }
	if (toLower(field) == "year") { return 2; }
	if (toLower(field) == "deaths") { return 3; }
	if (toLower(field) == "death rate") { return 4; }
	if (toLower(field) == "cause name") { return 5; }
	if (toLower(field) == "state") { return 6; }
	return -1;
}

template <typename t>
void menu2(BTree<t>& bt)
{
	int opt2, typeno;
	t key1, key2;
	string field, type;
	int oldvalueInt; float oldvalueFloat; string oldvalueString;
	int newvalueInt; float newvalueFloat; string newvalueString;
	do
	{
		system("cls");
		cout << "                DSDB				\n";
		cout << "Sub - Menu 		\n";
		cout << "Enter 1 for Point Search\n";
		cout << "Enter 2 for Range Search\n";
		cout << "Enter 3 to Update Key\n";
		cout << "Enter 4 to Perform point search with Field Clause\n";
		cout << "Enter 5 to Perform range search with Field Clause\n";
		cout << "Enter -1 to go back to previous menu.\n";
		cout << "Enter 0 to exit\n";
		cin >> opt2;
		system("cls");
		switch (opt2)
		{
		case 1:
			cout << "POINT SEARCH\n";
			cout << "Enter key to point search:\n";
			cin >> key1;
			cout << "Processing..." << endl;
			bt.IOcount = 0;
			bt.pointSearch(key1);
			cout << "\nNo. of I/O operations done: " << bt.IOcount << endl;
			system("pause");
			break;
		case 2:
			cout << "RANGE SEARCH\n";
			cout << "Enter key to range search\n" << "Enter starting key: \n";
			cin >> key1;
			cout << "Enter ending key: \n";
			cin >> key2;
			cout << "Processing..." << endl;
			bt.IOcount = 0;
			bt.RangeQuery(key1, key2);
			cout << "\nNo. of I/O operations done: " << bt.IOcount << endl;
			system("pause");
			break;
		case 3:
			cout << "UPDATE VALUE\n";
			cout << "Enter key: \n";
			cin >> key1;
			cout << "Enter field: (id,year,cause,state,deaths,death rate)\n";
			cin >> field;
			typeno = FieldToInt(field);
			cout << "Enter field value: ";
			if (typeno >= 1 && typeno <= 3)
				cin >> oldvalueInt;
			else if (typeno == 4)
				cin >> oldvalueFloat;
			else if (typeno == 5 || typeno == 6)
				cin >> oldvalueString;
			cout << "Enter new value(to be changed with supposedly): ";
			if (typeno >= 1 && typeno <= 3)
				cin >> newvalueInt;
			else if (typeno == 4)
				cin >> newvalueFloat;
			else if (typeno == 5 || typeno == 6)
				cin >> newvalueString;
			cout << "\nProcessing...\n";
			bt.IOcount = 0;
			if (typeno >= 1 && typeno <= 3)
				bt.UpdateValue(key1, field, oldvalueInt, newvalueInt);
			else if (typeno == 4)
				bt.UpdateValue(key1, field, oldvalueFloat, newvalueFloat);
			else if (typeno == 5 || typeno == 6)
				bt.UpdateValue(key1, field, oldvalueString, newvalueString);
			cout << "\nNo. of I/O operations done: " << bt.IOcount << endl;
			system("pause");

			break;
		case 4:
			cout << "POINT SEARCH WITH FIELD CLAUSE\n";
			cout << "Enter key to be searched: \n";
			cin >> key1;
			cout << "Enter field: (id,year,cause,state,deaths,death rate)\n";
			cin >> field;
			typeno = FieldToInt(field);
			cout << "Enter field value: ";
			if (typeno >= 1 && typeno <= 3)
				cin >> oldvalueInt;
			else if (typeno == 4)
				cin >> oldvalueFloat;
			else if (typeno == 5 || typeno == 6)
				cin >> oldvalueString;
			cout << "\nProcessing...\n";
			bt.IOcount = 0;
			if (typeno >= 1 && typeno <= 3)
				bt.pointSearch(key1, field, oldvalueInt);
			else if (typeno == 4)
				bt.pointSearch(key1, field, oldvalueFloat);
			else if (typeno == 5 || typeno == 6)
				bt.pointSearch(key1, field, oldvalueString);
			cout << "\nNo. of I/O operations done: " << bt.IOcount << endl;
			system("pause");

			break;
		case 5:
			cout << "RANGE SEARCH WITH FIELD CLAUSE\n";
			cout << "Enter key from: \n";
			cin >> key1;
			cout << "Enter key to: \n";
			cin >> key2;
			cout << "Enter field: (id,year,cause,state,deaths,death rate)\n";
			cin >> field;
			typeno = FieldToInt(field);
			cout << "Enter Field value: ";
			if (typeno >= 1 && typeno <= 3)
				cin >> oldvalueInt;
			else if (typeno == 4)
				cin >> oldvalueFloat;
			else if (typeno == 5 || typeno == 6)
				cin >> oldvalueString;
			cout << "\nProcessing...\n";
			bt.IOcount = 0;
			if (typeno >= 1 && typeno <= 3)
				bt.RangeQuery(key1, key2, field, oldvalueInt);
			else if (typeno == 4)
				bt.RangeQuery(key1, key2, field, oldvalueFloat);
			else if (typeno == 5 || typeno == 6)
				bt.RangeQuery(key1, key2, field, oldvalueString);
			cout << "\nNo. of I/O operations done: " << bt.IOcount << endl;
			system("pause");
			break;
		case -1: return; break;
		case 0: cout << "Thank You\n"; exit(0); break;
		default: cout << "\nInvalid Option\n"; break;
		}
	} while (opt2 != 0);
}
void menu1()
{
	int opt1, opt, x, fieldno;
	int c = 0;
	const string Filename = "DeathRate_";
	BTree<int> BIn1(0);
	BTree<int> BIn2(0);
	BTree<int> BIn3(0);
	BTree<float> BFl(0);
	BTree<string> BStr1(0);
	BTree<string> BStr2(0);
	string field, datafield;
	do
	{
		system("cls");
		cout << "			WELCOME TO DSDB		\n";
		cout << "Enter 1 to Create Index \n";
		cout << "Enter 2 to Operate on existing Index\n";
		cout << "Enter 0 to Exit program.\n";
		cin >> opt1;
		//system("cls");
		switch (opt1)
		{
		case 1:
			cout << "Enter '1' for BTree or '2' for B+Tree.\n";
			cin >> opt;
			if (opt == 2)
			{
				cout << "sorry,B+ Tree coding is not done\n";
				break;
			}
				
			cout << "Enter order of tree: ";
			cin >> x;
			cout << "choose datafield to index on\t{id,year,deaths,death rate,cause name,state}\n";
			cin >> field;						
			fieldno = FieldToInt(field);		
			cout << "\nProcessing...\n";		
			if (fieldno == 1) {
				BIn1.t = x;	
				readI<int>(Filename, fieldno, BIn1);
				BIn1.CreateIndex();
				menu2<int>(BIn1);
			}
			else if (fieldno == 2) 
			{
				BIn2.t = x;
				readI<int>(Filename, fieldno, BIn2);
				BIn2.CreateIndex();
				menu2<int>(BIn2);
			}
			else if (fieldno == 3) 
			{
				BIn3.t = x;
				readI<int>(Filename, fieldno, BIn3);
				BIn3.CreateIndex();
				menu2<int>(BIn3);
			}
			else if (fieldno == 4)
			{

				BFl.t = x;
				readI<float>(Filename, fieldno, BFl);
				BFl.CreateIndex();
				menu2<float>(BFl);
			}
			else if (fieldno == 5)
			{
				BStr1.t = x;
				readS(Filename, 1, BStr1);
				BStr1.CreateIndex();
				menu2<string>(BStr1);
			}
			else if (fieldno == 6) 
			{
				BStr2.t = x;
				readS(Filename, 2, BStr2);
				BStr2.CreateIndex();
				menu2<string>(BStr2);
			}
			break;
		case 2:
			//if(BIn1.directory == "")
			cout << "Enter 1 for B and 2 for B+ Tree.\n";
			cin >> opt;
			if (opt == 2)
				break;
			cout << "Enter datafield: ";
			cin >> datafield;
			fieldno = FieldToInt(datafield);


			if (fieldno == 1) {

				if (BIn1.directory == "") {
					cout << "Indexing not done already, Press 1 to Index\n";
					cin >> c;

					if (c == 1) {
						cout << "Enter order of tree: ";
						cin >> x;
						BIn1.t = x;
						cout << "\nProcessing...\n";
						readI<int>(Filename, fieldno, BIn1);
						BIn1.CreateIndex();
					}
					else
						break;
				}
				menu2<int>(BIn1);
			}
			else if (fieldno == 2) {
				if (BIn2.directory == "") {
					cout << "Indexing not done already, Press 1 to Index\n";
					cin >> c;
					if (c == 1) {
						cout << "Enter order of tree: ";
						cin >> x;
						BIn2.t = x;
						cout << "\nProcessing...\n";
						readI<int>(Filename, fieldno, BIn2);
						BIn2.CreateIndex();
					}
					else
						break;
				}
				menu2<int>(BIn2);
			}
			else if (fieldno == 3) {

				if (BIn3.directory == "") {
					cout << "Indexing not done already, Press 1 to Index\n";
					cin >> c;
					if (c == 1) {
						cout << "Enter order of tree: ";
						cin >> x;
						BIn3.t = x;
						cout << "\nProcessing...\n";
						readI<int>(Filename, fieldno, BIn3);
						BIn3.CreateIndex();
					}
					else
						break;
				}
				menu2<int>(BIn3);
			}
			else if (fieldno == 4) {
				if (BFl.directory == "") {
					cout << "Indexing not done already, Press 1 to Index\n";
					cin >> c;
					if (c == 1) {
						cout << "Enter order of tree: ";
						cin >> x;
						BFl.t = x;
						cout << "\nProcessing...\n";
						readI<float>(Filename, fieldno, BFl);
						BFl.CreateIndex();
					}
					else
						break;
				}
				menu2<float>(BFl);
			}
			else if (fieldno == 5) {
				if (BStr1.directory == "") {
					cout << "Indexing not done already, Press 1 to Index\n";
					cin >> c;
					if (c == 1) {
						cout << "Enter order of tree: ";
						cin >> x;
						BStr1.t = x;
						cout << "\nProcessing...\n";
						readS(Filename, fieldno, BStr1);
						BStr1.CreateIndex();
					}
					else
						break;
				}
				menu2<string>(BStr1);
			}
			else if (fieldno == 6) {
				if (BStr2.directory == "") {
					cout << "Indexing not done already, Press 1 to Index\n";
					cin >> c;
					if (c == 1) {
						cout << "Enter order of tree: ";
						cin >> x;
						BStr2.t = x;
						cout << "\nProcessing...\n";
						readS(Filename, fieldno, BStr2);
						BStr2.CreateIndex();
					}
					else
						break;
				}
				menu2<string>(BStr2);
			}
			break;
		case 0:
			cout << "Thank You\n";  exit(0);
			break;
		default: cout << "\nInvalid Option\n"; break;
		}
	} while (opt1 != 0);
}
int main()
{
	menu1();
	system("pause");
	return 0;
}
