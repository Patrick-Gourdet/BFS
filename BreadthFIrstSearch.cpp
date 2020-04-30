#include <iostream>
#include <map>
#include <queue>
#include <vector>


bool no_nodes(std::queue<int> *not_seen)
{
	if (!not_seen->empty()) return true;
	return false;
}
template<typename T>
std::vector<T> find_all_nodes(std::vector<std::vector<T>>*graph, std::map<T, bool>* seen,T current_node)
{

	std::vector<int> adjacent;
	if ((*seen)[current_node]) return adjacent;
		
	for (int i = 0; i < graph->at(current_node).size();i++)
	{
		if(graph->at(current_node).at(i) !=0 && !(*seen)[current_node])
		adjacent.push_back(i);
	}
	std::cout << "Node" << " " << current_node << "\n";
	(*seen)[current_node] = true;
	return adjacent;
}
template<typename T>
void build_graph(std::vector<std::vector<T>>* graph, std::map<T,bool> *seen,T i,T j)
{
	graph->at(i).at(j) = 1;
	(*seen)[i] = false;
}
int main()
{
	//int graph[8][8] = { 0 };
	std::vector<std::vector<int>> graph1(8, std::vector<int>(8, 0));
	
	std::queue<int> not_seen;
	std::map<int,bool> seen;

	not_seen.push(0);
	std::vector<int> edges = { 0,1,0,4,1,5,1,4,2,4,2,1,3,5,3,7,4,6,5,7};
	for(auto i {0};i + 2 < edges.size();i += 2)
	{
		build_graph(&graph1, &seen, edges[i ],edges[i + 2]);
	}
	
	while(no_nodes(&not_seen))
	{
		for (auto i : find_all_nodes(&graph1, &seen, not_seen.front()))
		{
			not_seen.push(i);
		}
		not_seen.pop();
	}
	for(auto i: seen)
	{
		auto res = i.second ? i.first : -1; 
		std::cout << "" << res;
	}
	return 0;
}
