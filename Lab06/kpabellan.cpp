#include <iostream>
#include <list>
using namespace std;

int m;

int hashFunction(int key) { 
  return key % m; 
}

void insertKey(list<int> table[], int key) {
  int i = hashFunction(key);
  table[i].push_front(key);
}

void searchKey(list<int> table[], int key) {
  bool found = false;
  int listIndex = 0;
  int hashIndex = hashFunction(key);

  for (list<int>::iterator iter = table[hashIndex].begin(); iter != table[hashIndex].end(); iter++, listIndex++) {
    if (*iter == key) {
      cout << key << ":FOUND_AT" << hashIndex << ',' << listIndex << ';' << endl;
      found = true;
      break;
    }
  }

  if (!found) {
    cout << key << ":NOT_FOUND;" << endl;
  }
}

void deleteKey(list<int> table[], int key) {
  bool deleted = false;
  int listIndex = 0;
  int hashIndex = hashFunction(key);

  for (list<int>::iterator iter = table[hashIndex].begin(); iter != table[hashIndex].end(); iter++, listIndex++) {
    if (*iter == key) {
      table[listIndex].erase(iter);
      cout << key << ":DELETED;" << endl;
      deleted = true;
      break;
    }
  }

  if (!deleted) {
    cout << key << ":DELETE_FAILED;" << endl;
  }
}

void outputTable(list<int> table[]) {
  for (int i = 0; i < m; i++) {
    cout << i << ':';

    for (list<int>::iterator iter = table[i].begin(); iter != table[i].end();
         iter++) {
      cout << *iter << "->";
    }

    cout << ';' << endl;
  }
}

int main() {
  int key = ' ';
  char command = ' ';
  cin >> m;
  list<int> table[m];

  while (command != 'e') {
    cin >> command;

    if (command == 'i') {
      cin >> key;
      insertKey(table, key);
    } else if (command == 's') {
      cin >> key;
      searchKey(table, key);
    } else if (command == 'd') {
      cin >> key;
      deleteKey(table, key);
    } else if (command == 'o') {
      outputTable(table);
    } else if (command == 'e') {
      break;
    }
  }

  return 0;
}