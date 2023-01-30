#pragma once
#include<iostream> 
#include <fstream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <type_traits>
using namespace std;
static int no = 1;
//utility functions
			/************************************************************************************/
string toLower(string str)
{
	for (int a = 0; a < str.length(); a++)
		if (str[a] > 'A' && str[a] < 'Z')
			str[a] = tolower(int(str[a]));
	return str;

}
template<class T> void stringtoi(string s, T& val) {

	val = 0;
	T number = 0;
	int l = s.length() - 1;
	for (int i = 0; i <= l; i++)
	{
		if (s[i] == '.') {
			number = std::stof(s.c_str());
			val = number;
			return;
		}
	}

	for (int i = 0; l >= 0; l--, i++)
		number += (pow(10.0, double(i))) * (T(s[l]) - 48);
	val = number;
	return;
}
template<>
void stringtoi(string s, string& val) {

	val = s;
}
string itos(int n) {

	string st = "";
	while (n) {  //int to string 

		st += char(n % 10) + 48;
		n = n / 10;
	}
	int l = st.length();
	char temp;
	for (int i = 0; i < l / 2; ++i) {//for inverting string 
		temp = st[i];
		st[i] = st[l - i - 1];
		st[l - i - 1] = temp;
	}
	return st;
}
template <class u> string IntTos(u n) {

	string st = "";
	while (n) {  //int to string 

		st += char(n % 10) + 48;
		n = n / 10;
	}
	int l = st.length();
	char temp;
	for (int i = 0; i < l / 2; ++i) {//for inverting string 
		temp = st[i];
		st[i] = st[l - i - 1];
		st[l - i - 1] = temp;
	}
	return st;
}
template<class u> string Itos(u val) {

	return val;

}
template<> string Itos(int val) {

	return itos(val);

}
template<> string Itos(float val) {
	std::string sVal = std::to_string(static_cast<long long>(val));
	return sVal;
}
/************************************************************************************/
//Linked List class
template <class DT> class Node {
public:
	DT value;
	Node* next;
};
template <class DT> class List {//index from 0 onwords
public:
	int count;
	Node <DT>* head;
	Node <DT>* cursor;

	List() {
		cursor = head = NULL;
		count = 0;
	}
	~List() {
		//clear();
	}
	List<DT> operator =(List<DT> list) {
		this->clear();
		for (int i = 0; i < list.count; i++) {
			this->insert(list.returnAt(i));
		}
		return *this;

	}
	void insert(const DT& newDataItem)
	{
		cursor = head;
		Node <DT>* temp = new Node<DT>;
		temp->next = NULL;
		temp->value = newDataItem;
		if (!cursor)
		{
			head = temp;
			cursor = temp;
		}
		else
		{
			while (cursor->next)
			{
				cursor = cursor->next;
			}
			cursor->next = temp;
			cursor = temp;
		}
		count++;
	}
	void insertAt(const DT& newDataItem, int index)
	{
		if (index < 0)
			cout << "Index out of Range" << endl;
		else {
			count++;
			Node<DT>* temp = new Node<DT>;
			temp->value = newDataItem;
			if (index == 0)
			{
				temp->next = head;
				head = temp;
			}

			else {
				cursor = head;
				int tempInd = 1;

				while (cursor->next && tempInd < index)
				{
					cursor = cursor->next;
					tempInd++;
				}
				if (cursor->next) {
					temp->next = cursor->next;
					cursor->next = temp;
					cursor = temp->next;

				}
				else
				{
					cout << "Index out of Range" << endl;
					count--;
				}
			}
		}
	}
	DT returnAt(int index)
	{
		if (index < 0)
			cout << "1Index out of Range" << endl;
		else {
			if (index == 0)
				return head->value;
			else {
				cursor = head->next;
				int tempInd = 1;
				while (cursor && tempInd < index)
				{
					cursor = cursor->next;
					tempInd++;
				}
				if (cursor)
					return cursor->value;
				else
					cout << "2Index out of Range" << endl;
			}
		}
	}
	void returnAt(int index, DT& obj)
	{
		if (index <= 0)
			cout << "Index out of Range" << endl;
		else {
			if (index == 1)
				obj = head->value;
			else {
				cursor = head->next;
				int tempInd = 2;
				while (cursor && tempInd < index)
				{
					cursor = cursor->next;
					tempInd++;

				}
				if (cursor) {
					obj = cursor->value;
				}
				else
					cout << "Index out of Range" << endl;
			}
		}
	}
	void remove() {
		if (cursor)
		{
			count--;
			if (cursor->next)
			{
				Node<DT>* temp = cursor->next;
				cursor->value = temp->value;
				cursor->next = temp->next;
				delete temp;
			}
			else
			{
				if (cursor != head) {
					Node<DT>* temp = head;
					while (temp->next != cursor)
						temp = temp->next;
					temp->next = NULL;
					delete cursor;
					cursor = head;
				}
				else
				{
					delete cursor;
					cursor = head = NULL;

				}
			}
		}

	}
	bool removeAt(int index)
	{
		if (index >= 0 && head)
		{
			cursor = head;
			int tempInd = 0;
			while (cursor && tempInd != index)
			{
				cursor = cursor->next;
				tempInd++;
			}
			if (cursor)
			{
				remove();
				return 1;
			}
			else
			{
				cout << "Index out of Range" << endl;
				return 0;
			}
		}
		else
		{
			cout << "Index out of Range" << endl;
			return 0;
		}

	}
	void replaceAt(const DT& newDataItem, int index)
	{
		if (index >= 0 && head)
		{
			Node <DT>* temp = head;
			int tempInd = 0;
			while (temp && tempInd != index)
			{
				temp = temp->next;
				tempInd++;

			}
			if (temp)
			{
				cursor = temp;
				cursor->value = newDataItem;
			}
			else
				cout << "Index out of Range" << endl;
		}
		else
			cout << "Index out of Range" << endl;
	}
	void clear() {
		if (head)
		{
			cursor = head;
			while (cursor)
				remove();
		}
	}
	bool isEmpty() {

		if (head) return 0;
		else return 1;
	}
	void display() {
		if (!isEmpty())
		{
			cursor = head;
			cout << "List Pointed By Key is:" << '\n';
			while (cursor) {
				cout << cursor->value << endl;
				cursor = cursor->next;
			}
		}
		else
			cout << "No Edge" << endl << endl;
	}
	bool find(DT value, int& index)
	{
		cursor = head;
		index = 0;
		while (cursor) {
			if (cursor->value == value)
				return 1;
			cursor = cursor->next;
			index++;
		}
		return 0;

	}
};
//List class ends
			/************************************************************************************/
struct Duplicate {
	//public:
	int lineNo;
	string fileName;//data file reference (unn 10 files mei se)
	Duplicate(string s = "", int l = 0) {
		fileName = s;
		lineNo = l;
	}
	Duplicate operator = (const Duplicate d) {
		this->fileName = d.fileName;
		this->lineNo = d.lineNo;
		return *this;
	}
};
ostream& operator<<(ostream& obj, const Duplicate d) {
	ifstream read(d.fileName);
	if (read) {
		string line;
		for (int i = 0; i <= d.lineNo; ++i)
			getline(read, line);
		obj << line;
	}
	else obj << "Can't Open File From Duplicate" << endl;

	return obj;
}
/************************************************************************************/
template<typename T>
class ReferenceToFile {
public:
	T key;
	List<Duplicate> list;
	ReferenceToFile(string f, int l, T k) {
		key = k;
		Duplicate d;
		d.fileName = f;
		d.lineNo = l;
		list.insert(d);
	}
	ReferenceToFile(T k) {
		key = k;
	}
	ReferenceToFile() {}
	ReferenceToFile<T> operator = (ReferenceToFile<T> r) {
		this->key = r.key;
		this->list = r.list;
		return *this;
	}
	ReferenceToFile<T> operator = (T k) {
		this->key = k;
		return *this;
	}
	bool operator < (ReferenceToFile<T> r) {
		return this->key < r.key;

	}
	bool operator > (ReferenceToFile<T> r) {
		return this->key > r.key;

	}
	bool operator ==(ReferenceToFile<T> r) {
		return r.key == this->key;
	}
	bool operator >=(ReferenceToFile<T> r) {
		return this->key >= r.key;
	}
	bool operator <=(ReferenceToFile<T> r) {
		return this->key <= r.key;
	}
	bool operator < (T r) {
		return this->key < r;

	}
	bool operator > (T r) {
		return this->key > r;

	}
	bool operator ==(T r) {
		return r == this->key;
	}
	bool operator >=(T r) {
		return this->key >= r;
	}
	bool operator <=(T r) {
		return key <= key;
	}
	T operator [](int i) {
		return key;
	}

};
template<typename T>
ostream& operator<<(ostream& obj, const ReferenceToFile<T>& r) {

	for (int i = 0; i < r.list.count; ++i) {
		Duplicate temp = r.list.returnAt(i);
		ifstream file(temp.fileName);
		string line;
		if (file) {
			for (int i = 0; i <= temp.lineNo; i++)
				getline(file, line);
			obj << line;
		}
		else
			cout << "File didn't open";
	}
	return obj;
}
/************************************************************************************/
template<class T>
class BTree
{
public:
	string directory;
	int IOcount;
	class BTreeNode
	{
	public:
		ReferenceToFile<T>* keys; // An array of keys 
		string* ref;//next file references 
		BTreeNode** children; // An array of child pointers 
		int keysNow;	 // Current number of keys 
		bool leaf; // Is true when node is leaf. Otherwise false 
		int t;	 // Minimum degree (defines the range for number of keys) 
		~BTreeNode() {}
		BTreeNode(int t1, bool leaf1)
		{
			t = t1;
			leaf = leaf1;
			keys = new ReferenceToFile<T>[(2 * t) - 1];
			children = new BTreeNode * [2 * t];
			ref = new string[2 * t];
			keysNow = 0;
		}
		void writeToFile(string path, BTreeNode* r) {

			ofstream obj(path);
			if (!obj)
				cout << "Can't open file" << endl;
			else {
				obj << r->leaf << "," << r->keysNow << "," << "\n";
				int i = 0;
				for (i = 0; i < r->keysNow; i++) {
					obj << r->keys[i].key << "," << '"';
					for (int j = 0; j < r->keys[i].list.count; j++) {
						Duplicate temp = r->keys[i].list.returnAt(j);
						obj << temp.fileName << "," << temp.lineNo << ",";
					}
					obj << '"';
					if (!r->leaf)
						obj << r->ref[i] << "," << "\n";
					else
						obj << "\n";
				}
				obj << r->ref[i] << "\n";



			}
			obj.close();
		}
		void traverse(string l, BTreeNode* cursor, const string& d) {
			if (!cursor->leaf) {


				for (int i = 0; i <= cursor->keysNow; i++) {
					string l = d + "\\" + "node" + itos(no++) + ".txt";
					cursor->ref[i] = l;
					//cout << l<<endl;
					traverse(l, cursor->children[i], d);
				}


			}

			writeToFile(l, cursor);
		}
		void insertInternal(ReferenceToFile<T> k)
		{
			// Initialize index as index of rightmost element 
			int i = keysNow - 1;
			if (leaf == true)
			{

				//Find the location of new key to be inserted move all greater keys to one place ahead 
				while (i >= 0 && keys[i] >= k) //change to =>
				{
					if (keys[i] == k) {//handling duplicates
						for (int j = 0; j < k.list.count; j++)
							keys[i].list.insert(k.list.returnAt(j));
						return;
					}
					i--;
				}
				i = keysNow - 1;
				while (i >= 0 && keys[i] >= k) //change to =>
				{
					keys[i + 1] = keys[i];
					i--;
				}

				// Insert at found location 
				keys[i + 1] = k;
				keysNow++;
			}
			else //not leaf 
			{

				while (i >= 0 && keys[i] >= k) {

					if (keys[i] == k) {//handling duplicates
						for (int j = 0; j < k.list.count; j++)
							keys[i].list.insert(k.list.returnAt(j));
						return;
					}
					i--;
				}
				if (children[i + 1]->keysNow == 2 * t - 1)
				{
					// split if node is full
					splitChild(i + 1, children[i + 1]);


					if (keys[i + 1] < k)
						i++;
				}
				children[i + 1]->insertInternal(k);
			}
		}
		void splitChild(int i, BTreeNode* y)
		{

			BTreeNode* z = new BTreeNode(y->t, y->leaf);
			z->keysNow = t - 1;


			for (int j = 0; j < t - 1; j++)
				z->keys[j] = y->keys[j + t];


			if (y->leaf == false)
			{
				for (int j = 0; j < t; j++)
					z->children[j] = y->children[j + t];
			}

			// Reduce the number of keys in y 
			y->keysNow = t - 1;


			for (int j = keysNow; j >= i + 1; j--)
				children[j + 1] = children[j];


			children[i + 1] = z;


			for (int j = keysNow - 1; j >= i; j--)
				keys[j + 1] = keys[j];


			keys[i] = y->keys[t - 1];


			keysNow = keysNow + 1;
			/*string l = "node"+itos(no++)+".txt";
			writeToFile(l, keys);*/
		}
		void clear() {

			//for (int i = 0; i < 2 * t; i++);



		}
	};
	BTreeNode* root; // Pointer to root node 
	int t; // Minimum degree 
	BTree(int m)
	{
		root = NULL; t = m; directory = ""; IOcount = 0;
	}
	void CreateIndex() {//writing nodes on file
		if (root != NULL) {
			string l = directory + "\\" + "root.txt";
			root->traverse(l, root, directory);
		}
	}
	void insert(ReferenceToFile<T> k)
	{
		// If tree is empty 
		if (root == NULL)
		{
			// Allocate memory for root 
			root = new BTreeNode(t, true);
			root->keys[0] = k; // Insert key 
			root->keysNow = 1; // Update number of keys in root 
		}
		else // If tree is not empty 
		{

			if (root->keysNow == 2 * t - 1)
			{

				BTreeNode* s = new BTreeNode(t, false);

				s->children[0] = root;

				s->splitChild(0, root);

				int i = 0;
				if (s->keys[0] == k) {//handling duplicates
					for (int j = 0; j < k.list.count; j++)
						s->keys[i].list.insert(k.list.returnAt(j));
					return;
				}
				if (s->keys[0] < k) {

					i++;

				}
				s->children[i]->insertInternal(k);

				// Change root 
				root = s;
			}
			else // If root is not full, call insertInternal for root 
				root->insertInternal(k);
		}
	}
	BTreeNode* LoadNodeFromFile(string path, BTreeNode* cursor) {
		IOcount++;
		ifstream obj(path);
		if (!obj)
		{
			cout << "Can't Open File For Writing Node" << endl;
			return 0;
		}
		else {
			cursor = new BTreeNode(t, 1);
			string line;
			getline(obj, line);
			cursor->leaf = int(line[0]) - 48;//as I created so [0]  for bool value		
			string temp = "";
			for (int i = 2; i < line.length(); ++i)//keys Count
				temp += line[i];

			cursor->keysNow = stoi(temp);


			int i;
			for (i = 0; i < cursor->keysNow && obj; ++i)
			{
				getline(obj, line);//line for node
				int j = 0;
				temp = "";
				while (line[j] != ',')
				{
					temp += line[j];//key
					j++;
				}

				//				cursor->keys[i].key = stringtoi<T>(temp);
				stringtoi(temp, cursor->keys[i].key);


				temp = "";
				j += 2;//for a comma and '"'
				while (line[j] != '"')
				{
					Duplicate objT;
					while (line[j] != ',')
					{
						temp += line[j];
						j++;
					}
					objT.fileName = temp;
					j++; temp = "";
					while (line[j] != ',')
					{
						temp += line[j];
						j++;
					}

					objT.lineNo = stoi(temp);
					j++; temp = "";
					cursor->keys[i].list.insert(objT);
				}
				j++; temp = "";
				if (!(cursor->leaf))
				{
					while (line[j] != ',')
					{
						temp += line[j];//child Node string
						j++;
					}

					cursor->ref[i] = temp; temp = "";
				}
			}

			getline(obj, line);//line for node
			cursor->ref[i] = line;
			line = "";

		}

		obj.close();
		return cursor;
	}
	//--------------------------------------//
	BTreeNode* SearchNode(BTreeNode* cursor, T keyToFind, int& index, bool& ch) {
		int i = 0;
		while (cursor->keys[i] < keyToFind && i < cursor->keysNow)
			i++;
		if (i < cursor->keysNow && cursor->keys[i] == keyToFind)
		{
			//	cout << cursor->keys[i];
			//	cursor->keys[i].list.display();
			//	return 1;
			index = i;
			ch = 1;
			return cursor;
		}
		if (!(cursor->leaf))
		{
			string path = cursor->ref[i];
			if (path == "")
				return 0;
			BTreeNode* cursor = root;
			//	if (cursor != root)
				//	cursor->clear;
			cursor = LoadNodeFromFile(path, cursor);

			return SearchNode(cursor, keyToFind, index, ch);
		}
		else return 0;
	}
	template <class u> bool pointSearch(u key) {
		BTreeNode* cursor = root;

		int in = -1;
		bool ch = 0;
		cursor = SearchNode(cursor, key, in, ch);
		if (ch) {
			//		cout << 1;
			cursor->keys[in].list.display();
		}
		else cout << "Key Not Found" << endl;

		return ch;
		//if (SearchNode(cursor, key, in))
		//{
		//	cout << cursor->keys[in].key << endl;
		//	cursor->keys[in].list.display();
		//	return 1;
		//}
	}
	//---------------------------------//
	bool SearchRangeNodes(BTreeNode* cursor, T k1, T k2)
	{
		for (int i = 0; i < cursor->keysNow; ++i)
		{
			//			int i = 0;
			if (cursor->keys[i].key > k1 && cursor->keys[i].key > k2)
			{
				if (cursor->leaf)
					return 0;
				else {//both keys less than key[i],so go down 
					string path = cursor->ref[i];
					if (path != "")
					{
						BTreeNode* temp = cursor;
						temp = LoadNodeFromFile(path, temp);
						return SearchRangeNodes(temp, k1, k2);
					}

					else return 0;

				}
			}
			else if (cursor->keys[i].key >= k1)
			{	//greater than or equal to k1
				int k = 0;//counting for how many nodes we have to visit
				int j = i;
				string* tempChildrenP;//for paths of that many children
				while (j < cursor->keysNow && cursor->keys[j].key <= k2)//for counting and displaying keys in given  range
				{
					cursor->keys[j].list.display();
					++k; ++j;
				}
				if (j <= cursor->keysNow && cursor->keys[j - 1].key <= k2)
					++k;
				if (!cursor->leaf) {//children exists in that node
					tempChildrenP = new string[k];//for holding k many child paths i.e string
					for (int temp = 0; temp < k; ++temp)//copying that children to our array
						tempChildrenP[temp] = cursor->ref[i + temp];
					for (int Count = 0; Count < k; ++Count) {//visiting children of that node
						cursor->clear();//disallocating memory to cusor
						if (tempChildrenP[Count] != "") {
							cursor = LoadNodeFromFile(tempChildrenP[Count], cursor);
							SearchRangeNodes(cursor, k1, k2);
						}
					}
				}
				return 1;
			}
		}

		if (!cursor->leaf && cursor->keys[cursor->keysNow - 1] < k2) {//last element of node
			string tempChildrenP = cursor->ref[cursor->keysNow];//for holding k many child paths i.e string
			cursor->clear();//disallocating memory to cusor
			if (tempChildrenP != "") {
				cursor = LoadNodeFromFile(tempChildrenP, cursor);
				SearchRangeNodes(cursor, k1, k2);
			}
		}
		else return 0;

	}
	bool RangeQuery(T k1, T k2)
	{
		BTreeNode* cursor = root;
		return SearchRangeNodes(cursor, k1, k2);

	}
	int FieldToInt(string field)
	{
		if (toLower(field) == "id") { return 0; }
		if (toLower(field) == "year") { return 1; }
		if (toLower(field) == "deaths") { return 2; }
		if (toLower(field) == "death rate") { return 3; }
		if (toLower(field) == "cause") { return 4; }
		if (toLower(field) == "state") { return 5; }
		return -1;
	}
	template <class u> void UpdateValue(T k, string Field, u oldVal, u newVal)
	{
		int f = FieldToInt(Field);
		if (f != -1) {
			BTreeNode* cursor = root;
			bool ch = 0; int in = -1;
			cursor = SearchNode(cursor, k, in, ch);
			if (ch)
			{
				List<Duplicate> list = cursor->keys[in].list;
				if (list.count == 1) {
					char tempFileName[] = "temp.csv";
					ofstream write(tempFileName);
					ifstream read(list.returnAt(0).fileName);
					string line;
					//				char c;
					int i = 0;
					//for (; i < list.returnAt(0).lineNo; ++i)
					//{
					//	read.get(c);
					//	write << c;
					//}
					for (; i < list.returnAt(0).lineNo; ++i)
					{
						getline(read, line);
						write << line << '\n';


					}

					getline(read, line);

					if (!EditString(line, f, oldVal, newVal))
					{
						cout << "File can't be Update" << endl;
						write.close();
						read.close();

						remove(tempFileName);
						return;
					}
					write << line << '\n';
					for (; read;)
					{
						getline(read, line);
						write << line << '\n';
						//read.get(c);
						//write << c;
					}
					write.close();
					read.close();
					string F = list.returnAt(0).fileName;
					const char* path = F.c_str();
					cout << path << endl;
					remove(path);
					rename(tempFileName, path);




				}
				else {//for duplicates
					string line;
					char tempFileName[] = "temp.csv";
					ofstream write(tempFileName);
					string fileNameInDB = list.returnAt(0).fileName;
					ifstream read(fileNameInDB);
					int j = 0;
					for (int i = 0; i < list.count;)
					{
						string tempfile = list.returnAt(i).fileName;
						if (fileNameInDB != tempfile)
						{
							read.close();
							write.close();
							fileNameInDB = tempfile;
							read.open(fileNameInDB);
							write.open("temp.csv");
							j = 0;
						}
						for (; j < list.returnAt(i).lineNo; ++j)
						{
							getline(read, line);
							write << line << '\n';
						}
						getline(read, line);

						if (!EditString(line, f, oldVal, newVal))
							i++;
						else {
							write << line << '\n';
							for (; read;)
							{
								getline(read, line);
								write << line << '\n';
								//read.get(c);
								//write << c;
							}
							write.close();
							read.close();
							string F = fileNameInDB;
							const char* path = F.c_str();
							remove(path);
							rename(tempFileName, path);
							return;


						}
					}

				}

			}
			else {
				cout << "Key For Updation is incorrect." << endl;
				return;
			}
		}
		else  cout << "You have entered Invalid Field Name to Update" << endl;

	}
	template <class u>
	bool EditString(string& line, int keytype, u oldVal, u newVal) {
		string oldValS = "", newValS = "";

		oldValS = Itos(oldVal);
		newValS = Itos(newVal);
		string temp = "";
		int j = 0;
		string key = "";
		if (keytype == 0)//keytype is ID
		{
			while (line != "" && line[j] != ',')
			{
				key += line[j++];
			}
		}
		else if (keytype == 1)//keytype is year
		{
			while (line != "" && line[j] != ',')//seek to year
			{
				temp += line[j++];
			}
			temp += line[j++];

			while (line != "" && line[j] != ',') {
				key += line[j];
				j++;
			}

		}
		else if (keytype == 2)//keytype is deaths
		{
			while (line != "" && line[j] != ',')//seek to year
			{
				temp += line[j++];
			}
			temp += line[j++];
			while (line != "" && line[j] != ',')//seek to causename
			{
				temp += line[j++];
			}
			temp += line[j++];

			if (line != "" && line[j] == '"') {//if separator is ' "" '
				temp += line[j++];
				while (line != "" && line[j] != '"')//seek to causename2
				{
					temp += line[j++];
				}
				temp += line[j++];
				temp += line[j++];
			}
			else {
				while (line != "" && line[j] != ',')//seek to causename2
				{
					temp += line[j++];
				}
				temp += line[j++];
			}

			while (line != "" && line[j] != ',')//seek to state
			{
				temp += line[j++];
			}
			temp += line[j++];
			while (line != "" && line[j] != ',')
				key += line[j++];

		}
		else if (keytype == 3)//keytype is age adjusted death rate
		{
			while (line != "" && line[j] != ',')//seek to year
				temp += line[j++];
			temp += line[j++];
			while (line != "" && line[j] != ',')//seek to causename
				temp += line[j++];
			temp += line[j++];

			if (line != "" && line[j] == '"') {//if separator is ' "" '
				temp += line[j++];
				while (line != "" && line[j] != '"')//seek to causename2
					temp += line[j++];
				temp += line[j++];
				temp += line[j++];

			}
			else {
				while (line != "" && line[j] != ',')//seek to causename2
					temp += line[j++];
				temp += line[j++];
			}


			while (line != "" && line[j] != ',')//seek to state
				temp += line[j++];
			temp += line[j++];
			while (line != "" && line[j] != ',')//seek to deaths
				temp += line[j++];
			temp += line[j++];
			while (line != "" && line[j] != ',')//seek to age adjusted rate
				temp += line[j++];
			temp += line[j++];

			while (line != "" && j < line.length() && line[j] != ',')
				key += line[j++];

			//			oldValS = ftos(oldVal);
				//		newValS = ftos(newVal);
		}
		else if (keytype == 4)//keytype is cause name
		{
			while (line != "" && line[j] != ',')//seek to year
				temp += line[j++];
			temp += line[j++];
			while (line != "" && line[j] != ',')//seek to causename
				temp += line[j++];
			temp += line[j++];

			if (line != "" && line[j] == '"') {//if separator is ' "" '
				temp += line[j++];
				while (line != "" && line[j] != '"')//seek to causename2
					temp += line[j++];
				temp += line[j++];
				temp += line[j++];

			}
			else {
				while (line != "" && line[j] != ',')//seek to causename2
					temp += line[j++];
				temp += line[j++];
			}

			while (line != "" && line[j] != ',')
				key += line[j++];

		}
		else if (keytype == 5)//keytype is state
		{
			while (line != "" && line[j] != ',')//seek to year
				temp += line[j++];
			temp += line[j++];
			while (line != "" && line[j] != ',')//seek to causename
				temp += line[j++];
			temp += line[j++];

			if (line != "" && line[j] == '"') {//if separator is ' "" '
				temp += line[j++];
				while (line != "" && line[j] != '"')//seek to causename2
					temp += line[j++];
				temp += line[j++];
				temp += line[j++];

			}
			else {
				while (line != "" && line[j] != ',')//seek to causename2
					temp += line[j++];
				temp += line[j++];
			}
			while (line != "" && line[j] != ',')
				temp += line[j++];
			temp += line[j++];
			while (line != "" && line[j] != ',')
				key += line[j++];

		}
		else return 0;

		if (key != oldValS) return 0;


		temp += newValS;
		for (; j < line.length(); ++j)
			temp += line[j];

		line = temp;
		return 1;
	}
	template <class u> bool pointSearch(T key, string field, u value)
	{

		bool checkForReturn = 0;
		int f = FieldToInt(field);
		if (f != -1) {
			BTreeNode* cursor = root;
			bool ch = 0; int in = -1;
			cursor = SearchNode(cursor, key, in, ch);
			if (ch)
			{
				List<Duplicate> list = cursor->keys[in].list;
				if (list.count == 1) {
					ifstream read(list.returnAt(0).fileName);
					string line;
					//				char c;
					int i = 0;
					//for (; i < list.returnAt(0).lineNo; ++i)
					//{
					//	read.get(c);
					//	write << c;
					//}
					for (; i < list.returnAt(0).lineNo; ++i)
					{
						getline(read, line);
					}

					getline(read, line);

					if (!SearchValueWithField(line, f, value))
					{
						cout << "Key To Search Doesn't Has Any Field With That Value" << endl;
						read.close();
						//	return 0;
					}
					else {
						cout << line << endl;
						read.close();
						//return 1;
					}
				}
				else {//for duplicates
					string line;
					string fileNameInDB = list.returnAt(0).fileName;
					ifstream read(fileNameInDB);
					int j = 0;
					getline(read, line);

					for (int i = 0; i < list.count; ++i)
					{
						string tempfile = list.returnAt(i).fileName;
						if (fileNameInDB != tempfile)
						{
							read.close();
							fileNameInDB = tempfile;
							read.open(fileNameInDB);
							j = 0;
							getline(read, line);
						}
						for (; j < list.returnAt(i).lineNo; ++j)
						{
							getline(read, line);
						}

						if (SearchValueWithField(line, f, value))
						{
							cout << line << endl;
							checkForReturn = 1;
						}
					}
					read.close();
					return checkForReturn;
				}

			}
			else {
				cout << "Key To Find is incorrect." << endl;
				return 0;
			}
		}
		else {
			cout << "You have entered Invalid Field Name to Search" << endl;
			return 0;
		}
	}
	template <class u> bool SearchValueWithField(string line, int keytype, u value) {
		string oldValS = "";
		oldValS = Itos(value);
		int j = 0;
		string key = "";

		if (keytype == 0)//keytype is ID
		{
			while (line != "" && line[j] != ',')
			{
				key += line[j++];
			}

		}
		else if (keytype == 1)//keytype is year
		{
			while (line != "" && line[j] != ',')//seek to year
				j++;
			j++;

			while (line != "" && line[j] != ',') {
				key += line[j];
				j++;
			}

		}
		else if (keytype == 2)//keytype is deaths
		{
			while (line != "" && line[j] != ',')//seek to year
				j++;
			j++;
			while (line != "" && line[j] != ',')//seek to causename
				j++;
			j++;

			if (line != "" && line[j] == '"') {//if separator is ' "" '
				j++;
				while (line != "" && line[j] != '"')//seek to causename2
					j++;
				j += 2;
			}
			else {
				while (line != "" && line[j] != ',')//seek to causename2
					j++;
				j++;
			}
			while (line != "" && line[j] != ',')//seek to state
				j++;
			j++;
			while (line != "" && line[j] != ',')//seek to deaths
				j++;
			j++;
			while (line != "" && line[j] != ',')//seek to age adjusted rate
				j++;
			j++;

			while (line != "" && j < line.length() && line[j] != ',')
				key += line[j++];

		}
		else if (keytype == 3)//keytype is age adjusted death rate
		{
			while (line != "" && line[j] != ',')//seek to year
				j++;
			j++;
			while (line != "" && line[j] != ',')//seek to causename
				j++;
			j++;

			if (line != "" && line[j] == '"') {//if separator is ' "" '
				j++;
				while (line != "" && line[j] != '"')//seek to causename2
					j++;
				j += 2;
			}
			else {
				while (line != "" && line[j] != ',')//seek to causename2
					j++;
				j++;
			}


			while (line != "" && line[j] != ',')//seek to state
				j++;
			j++;
			while (line != "" && line[j] != ',')//seek to deaths
				j++;
			j++;
			while (line != "" && line[j] != ',')//seek to age adjusted rate
				j++;
			j++;

			while (line != "" && j < line.length() && line[j] != ',')
				key += line[j++];

		}
		else if (keytype == 4)//keytype is cause name
		{
			while (line != "" && line[j] != ',')//seek to year
				j++;
			j++;
			while (line != "" && line[j] != ',')//seek to causename
				j++;
			j++;

			if (line != "" && line[j] == '"') {//if separator is ' "" '
				j++;
				while (line != "" && line[j] != '"')//seek to causename2
					j++;
				j++;
				j++;

			}
			else {
				while (line != "" && line[j] != ',')//seek to causename2
					j++;
				j++;
			}

			while (line != "" && line[j] != ',')
				key += line[j++];

			//oldValS = oldVal;
			//newValS = newVal;


		}
		else if (keytype == 5)//keytype is state
		{
			while (line != "" && line[j] != ',')//seek to year
				j++;
			j++;
			while (line != "" && line[j] != ',')//seek to causename
				j++;
			j++;

			if (line != "" && line[j] == '"') {//if separator is ' "" '
				j++;
				while (line != "" && line[j] != '"')//seek to causename2
					j++;
				j++;
				j++;

			}
			else {
				while (line != "" && line[j] != ',')//seek to causename2
					j++;
				j++;
			}
			while (line != "" && line[j] != ',')
				j++;
			j++;
			while (line != "" && line[j] != ',')
				key += line[j++];
		}
		else return 0;

		if (key != oldValS) return 0;
		return 1;
	}
	template<class u> bool SearchRangeNodesWithField(BTreeNode* cursor, T k1, T k2, string field, u value)
	{
		for (int i = 0; i < cursor->keysNow; ++i)
		{
			//			int i = 0;
			if (cursor->keys[i].key > k1 && cursor->keys[i].key > k2)
			{
				if (cursor->leaf)
					return 0;
				else {//both keys less than key[i],so go down 
					string path = cursor->ref[i];
					if (path != "")
					{
						BTreeNode* temp = cursor;
						temp = LoadNodeFromFile(path, temp);
						return SearchRangeNodesWithField(temp, k1, k2, field, value);
					}

					else return 0;

				}
			}
			else if (cursor->keys[i].key >= k1)
			{	//greater than or equal to k1
				int k = 0;//counting for how many nodes we have to visit
				int j = i;
				string* tempChildrenP;//for paths of that many children
				while (j < cursor->keysNow && cursor->keys[j].key <= k2)//for counting and displaying keys in given  range
				{
					int f = FieldToInt(field);
					List<Duplicate> list = cursor->keys[j].list;
					if (list.count == 1) {
						ifstream read(list.returnAt(0).fileName);
						string line;
						//				char c;
						int i = 0;
						//for (; i < list.returnAt(0).lineNo; ++i)
						//{
						//	read.get(c);
						//	write << c;
						//}
						for (; i < list.returnAt(0).lineNo; ++i)
						{
							getline(read, line);
						}

						getline(read, line);

						if (!SearchValueWithField(line, f, value))
						{
							cout << "Key To Search Doesn't Has Any Field With That Value" << endl;
							read.close();
							return 0;
						}
						else {
							cout << line << endl;
							read.close();
							//			return 1;
						}
					}
					else {//for duplicates
						string line;
						string fileNameInDB = list.returnAt(0).fileName;
						ifstream read(fileNameInDB);
						int j = 0;
						getline(read, line);

						for (int i = 0; i < list.count; ++i)
						{
							string tempfile = list.returnAt(i).fileName;
							if (fileNameInDB != tempfile)
							{
								read.close();
								fileNameInDB = tempfile;
								read.open(fileNameInDB);
								j = 0;
								getline(read, line);
							}
							for (; j < list.returnAt(i).lineNo; ++j)
							{
								getline(read, line);
							}

							if (SearchValueWithField(line, f, value))
							{
								cout << line << endl;
							}
						}
						read.close();

					}
					++k; ++j;
				}
				if (j <= cursor->keysNow && cursor->keys[j - 1].key <= k2)
					++k;
				if (!cursor->leaf) {//children exists in that node
					tempChildrenP = new string[k];//for holding k many child paths i.e string
					for (int temp = 0; temp < k; ++temp)//copying that children to our array
						tempChildrenP[temp] = cursor->ref[i + temp];
					for (int Count = 0; Count < k; ++Count) {//visiting children of that node
						cursor->clear();//disallocating memory to cusor
						if (tempChildrenP[Count] != "") {
							cursor = LoadNodeFromFile(tempChildrenP[Count], cursor);
							SearchRangeNodesWithField(cursor, k1, k2, field, value);
						}
					}
				}
				return 1;
			}
		}

		if (!cursor->leaf && cursor->keys[cursor->keysNow - 1] < k2) {//last element of node
			string tempChildrenP = cursor->ref[cursor->keysNow];//for holding k many child paths i.e string
			cursor->clear();//disallocating memory to cusor
			if (tempChildrenP != "") {
				cursor = LoadNodeFromFile(tempChildrenP, cursor);
				SearchRangeNodes(cursor, k1, k2);
			}
		}
		else return 0;

	}
	template<class u>bool RangeQuery(T k1, T k2, string field, u value)
	{
		BTreeNode* cursor = root;
		return SearchRangeNodesWithField(cursor, k1, k2, field, value);

	}
};
//if key is integer or float
			/************************************************************************************/
template<typename t>
void readI(string path, int keytype, BTree <t>& b) {
	string line = "";
	//string directory;
	if (keytype == 1)
	{
		b.directory = "BTInID";
		CreateDirectoryA(b.directory.c_str(), NULL);
	}
	else if (keytype == 2) {
		b.directory = "BTInYear";
		CreateDirectoryA(b.directory.c_str(), NULL);
	}
	else if (keytype == 3) {
		b.directory = "BTInDY";
		CreateDirectoryA(b.directory.c_str(), NULL);
	}
	else if (keytype == 4) {
		b.directory = "BTInDR";
		CreateDirectoryA(b.directory.c_str(), NULL);
	}
	for (int i = 1; i <= 10; i++)
	{
		string npath = path + "0" + itos(i) + ".csv";
		ifstream file(npath);
		if (file) {
			getline(file, line);
			int lineno = 1;
			line = "";
			while (!file.eof()) {
				string key = "";
				//	lineno = file.tellg();
				getline(file, line);
				int j = 0;
				if (keytype == 1)//keytype is ID
				{
					while (line != "" && line[j] != ',')
						key += line[j++];
					j++;
				}
				else if (keytype == 2)//keytype is year
				{
					while (line != "" && line[j] != ',')//seek to year
						j++;
					j++;
					while (line != "" && line[j] != ',') {
						key += line[j];
						j++;
					}
				}
				else if (keytype == 3)//keytype is deaths
				{
					while (line != "" && line[j] != ',')//seek to year
						j++;
					j++;
					while (line != "" && line[j] != ',')//seek to causename
						j++;
					j++;

					if (line != "" && line[j] == '"') {//if separator is ' "" '
						j++;
						while (line != "" && line[j] != '"')//seek to causename2
							j++;
						j += 2;
					}
					else {
						while (line != "" && line[j] != ',')//seek to causename2
							j++;
						j++;
					}

					while (line != "" && line[j] != ',')//seek to state
						j++;
					j++;
					while (line != "" && line[j] != ',')//seek to state
						j++;
					j++;
					while (line != "" && line[j] != ',')
						key += line[j++];



				}
				else if (keytype == 4)//keytype is age adjusted death rate
				{
					while (line != "" && line[j] != ',')//seek to year
						j++;
					j++;
					while (line != "" && line[j] != ',')//seek to causename
						j++;
					j++;

					if (line != "" && line[j] == '"') {//if separator is ' "" '
						j++;
						while (line != "" && line[j] != '"')//seek to causename2
							j++;
						j += 2;
					}
					else {
						while (line != "" && line[j] != ',')//seek to causename2
							j++;
						j++;
					}


					while (line != "" && line[j] != ',')//seek to state
						j++;
					j++;
					while (line != "" && line[j] != ',')//seek to deaths
						j++;
					j++;
					while (line != "" && line[j] != ',')//seek to age adjusted rate
						j++;
					j++;

					while (line != "" && j < line.length() && line[j] != ',')
						key += line[j++];

				}
				if (key != "") {
					ReferenceToFile<t> obj(npath, lineno, stoi(key));
					b.insert(obj);
				}
				if (line != "")
					++lineno;
			}

			file.close();
		}

		else {
			cout << "DATA File didn't open" << endl;
		}
	}

}
//if type is string
void readS(string path, int keytype, BTree<string>& b) {
	// key type
	//string directory;
	ifstream file;
	string line = "";
	string key;
	if (keytype == 1) {
		b.directory = "BTInCause";
		CreateDirectoryA(b.directory.c_str(), NULL);
	}
	else if (keytype == 2) {
		b.directory = "BTInState";
		CreateDirectoryA(b.directory.c_str(), NULL);
	}

	for (int i = 1; i <= 10; i++)
	{
		string npath = path + itos(i) + ".csv";
		file.open(npath);
		if (file) {
			getline(file, line);
			int lineno = 1;

			while (!file.eof()) {
				line = "";
				getline(file, line);
				int j = 0;
				key = "";
				if (keytype == 1)//keytype is cause name
				{
					while (line != "" && line[j] != ',')//seek to year
						j++;
					j++;
					while (line != "" && line[j] != ',')//seek to causename
						j++;
					j++;

					if (line != "" && line[j] == '"') {//if separator is ' "" '
						j++;
						while (line != "" && line[j] != '"')//seek to causename2
							j++;
						j += 2;
					}
					else {
						while (line != "" && line[j] != ',')//seek to causename2
							j++;
						j++;
					}

					while (line != "" && line[j] != ',')
						key += line[j++];

				}
				else if (keytype == 2)//keytype is state
				{
					while (line != "" && line[j] != ',')//seek to year
						j++;
					j++;
					while (line != "" && line[j] != ',')//seek to causename
						j++;
					j++;

					if (line != "" && line[j] == '"') {//if separator is ' "" '
						j++;
						while (line != "" && line[j] != '"')//seek to causename2
							j++;
						j += 2;
					}
					else {
						while (line != "" && line[j] != ',')//seek to causename2
							j++;
						j++;
					}
					while (line != "" && line[j] != ',')
						j++;
					j++;
					while (line != "" && line[j] != ',')
						key += line[j++];

				}
				ReferenceToFile<string> obj(npath, lineno, key);
				b.insert(obj);
				if (line != "")
					++lineno;
			}
			file.close();
		}


		else {
			cout << "File didn't open";
		}
	}

}
