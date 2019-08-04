#include <map>
#include <list>
#include <set>
#include <algorithm>
#include <ctime>
#include <cstdlib>

// recursive function which return new set withou one subgraph for start vertex
set<int> deleteConVertices(set<int> allVertices, map<int, list<int>> graph, set<int>::iterator startVertex)
{
	// delete start vertex
	allVertices.erase(*startVertex);
	// look at all vertecies in set which connected with start vertex
	for (set<int>::iterator mapKey = allVertices.begin(); mapKey != allVertices.end();)
	{
		list<int>::iterator findIt = find(graph[*mapKey].begin(), graph[*mapKey].end(), *startVertex);
		// if we can find start vertex in set
		if (findIt != graph[*mapKey].end())
		{
			// then call recursive function which start vertex = find vertex
			allVertices = deleteConVertices(allVertices, graph, allVertices.find(*mapKey));
			// update iterrator because we can delete all vertex and sets can be == end
			mapKey = allVertices.begin();
			continue;
		}
		mapKey++;
	}
	return allVertices;
}

// function which call recursive funcion "generateRandGraph" for delete connected vertecies
int calcCountConComp(map<int, list<int>> graph)
{
	int countConComp = 0;
	set<int> allVertices;
	// Init set with vertices
	for (map<int, list<int>>::iterator mapIt = graph.begin(); mapIt != graph.end(); mapIt++)
		allVertices.insert(mapIt->first);

	// cout all vertices
	cout << "ALL VERTICES: { ";
	for (set<int>::iterator setIt = allVertices.begin(); setIt != allVertices.end(); setIt++)
		cout << *setIt << " ";
	cout << "}" << endl;

	while (allVertices.size() != 0)
	{
		// return new set without one conn subgraph
		allVertices = deleteConVertices(allVertices, graph, allVertices.begin());
		countConComp++;
	}

	return countConComp;
}

map<int, list<int>> generateRandGraph(int countVertex)
{	
	map<int, list<int>> graph;
	srand(time(0));

	// Cycle for vertex
	for (int i = 1; i <= countVertex; i++)
	{
		graph[i];
		// We generate acyclic graph. It's just that
		for (int j = i + 1; j <= countVertex; j++)
		{
			// Generate random value. If value == 1 then vertexI and vertexJ has edge, otherwise no
			int r = rand() % 2;
			if (r == 1)
			{
				// add edge
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}
}

int main()
{
	int countVertex = 0;
	cout << "Enter count vertex: "; cin >> countVertex;
	map<int, list<int>> graph = generateRandGraph(countVertex);

	cout << "[Vertex]: edge Vertex:" << endl;
	for (map<int, list<int>>::iterator mapIt = graph.begin(); mapIt != graph.end(); mapIt++)
	{
		cout << "[" << mapIt->first << "]: ";
		for (list<int>::iterator listIt = mapIt->second.begin(); listIt != mapIt->second.end(); listIt++) 
			cout << *listIt << " ";
		cout << endl;
	}

	cout << "count connected components = " << calcCountConComp(graph);

	return 0;
}
