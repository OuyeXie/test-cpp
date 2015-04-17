//============================================================================
// Name        : Main.cpp
// Author      : Yicheng Ye
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
using namespace std;

int solve(int total, int interval) {
	list<int> listC;
	list<int>::iterator i;
	for (int i = 0; i < total + 1; i++) {
		listC.push_back(i + 1);
	}
	i = listC.begin();
	while (listC.size() > 1) {
		for (;;) {
			list<int>::iterator j = i, k = --listC.end();
			int dist = distance(i, k);
			int offset = interval - dist - 1;
			int offsetMod = offset % (listC.size() - 1);

			//cout << "ID " << *i << " is dead. " << dist << " " << offset << " "
			//		<< offset % (listC.size() - 1) << "---";
			list<int>::iterator l = listC.begin();
			//for (; l != listC.end(); ++l) {
				//cout << *l << " ";
			//}
			if (dist < interval) {
				i = listC.begin();
				if (listC.size() - 2 < offset) {
					advance(i, offsetMod);
				} else {
					advance(i, offset);
				}
				//cout << "---" << (distance(i, j) == listC.size()) << endl;
				if (distance(i, j) == listC.size() || distance(i, j) == 0){
					advance(i, 1);
				}
				listC.erase(j);
				break;
			} else {
				advance(i, interval);
				if (distance(i, j) == listC.size() || distance(i, j) == 0){
					advance(i, 1);
				}
				listC.erase(j);
			}
		}
	}
	cout << "alive: " << listC.front();
	cout << endl;
	return listC.front();
}

void partition(int n, int max, list<int> p, int flag) {
	if (flag == 1) {
		p.push_back(max);
	}
	if (n == 0) {
		while (p.size() > 0) {
			cout << p.front() << " ";
			p.pop_front();
		}
		cout << endl;
		return;
	} else if (max == 0) {
		return;
	} else if (n < 0) {
		return;
	}
	partition(n - max, max, p, 1);
	partition(n, max - 1, p, 0);
}

void partition(int n) {
	list<int> p;
	partition(n, n, p, 0);
}

int main() {
	solve(40, 3);
	partition(8);
}
