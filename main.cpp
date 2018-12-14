#include <iostream>
#include <fstream>
#include <locale.h>
#include "Graph.h"
#include "Node.h"
#include "FS.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	const char* inFileName = "in.txt";//argv[0];
	Graph g = Graph(inFileName);
	Graph one = Graph();
	BFS n = BFS(g);
	int i = 1;
	one.addNode(*g.begin());

	for (node_iterator it = g.begin();it != g.end();it++)
		for (node_iterator jt = g.begin(); jt != g.end(); jt++)
		{
			if (it == jt)
				continue;
			if (one.ser(*jt))
				continue;
			n.print(*it, *jt, one);
		}

	cout << "One: ";
	for (node_iterator it = g.begin(); it != g.end(); it++)
		if (one.ser(*it))
			g.removeNode(*it);

	for (node_iterator it = one.begin(); it != one.end(); it++)
		cout << (*it)->getName() << ' ';

	cout << endl << "Two: ";
	for (node_iterator it = g.begin(); it != g.end(); it++)
		cout << (*it)->getName() << ' ';
	cout << endl;

	system("pause");
	return 0;
}
