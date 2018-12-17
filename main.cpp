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
	/* 
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
	cout << endl;*/

	while (g.sizeG() != 0)
	{
		node_iterator it = g.begin();
		one.addNode(*it);
		for (node_iterator jt = g.begin(); jt != g.end(); jt++)
		{
			if (it == jt)
				continue;
			if (one.ser(*jt))
				continue;
			n.print(*it, *jt, one);
		}

		for (node_iterator kt = g.begin(); kt != g.end(); kt++)
			if (one.ser(*kt))
				g.removeNode(*kt);

		//cout << "Graph " << i << ": ";
		
		char name = i + '0';
		const char* shablon = ".txt";
		char* outFileName = new char[5];

		outFileName[0] = name;
		for (int j = 1; j < 5; j++)
		{
			outFileName[j] = *shablon;
			shablon++;
		}

		ofstream fout(outFileName);
		for (node_iterator kt = one.begin(); kt != one.end(); kt++)
			fout << (*kt)->getName() << ' ';
		
		fout.close();

		one.kill();
		i++;
	}

	system("pause");
	return 0;
}
