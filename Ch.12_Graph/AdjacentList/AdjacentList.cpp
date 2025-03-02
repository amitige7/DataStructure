#include <iostream>
#include <cassert>

#include "C:\Users\amiti\source\repos\shared\shared\stack.h"
#include "C:\Users\amiti\source\repos\shared\shared\queue.h"

using namespace std;

template<typename T>
class AdjListGraph // Adjacent List Graph
{
public:
	struct Vertex
	{
		T item = T();
	};

	struct Node
	{
		//Vertex* vertex = nullptr;
		int vertex = -1; // vertex�� index
		Node* next = nullptr;
	};

	AdjListGraph(int max_vertices)
	{
		max_vertices_ = max_vertices; // capacity

		vertices_ = new Vertex[max_vertices_];
		list_ = new Node * [max_vertices_];
		for (int i = 0; i < max_vertices_; i++)
			list_[i] = nullptr;

		n_ = 0;
	}

	~AdjListGraph()
	{
		delete[] vertices_;
		delete[] list_;

		if (visited_)
			delete[] visited_;
	}

	void InsertVertex(T item)
	{
		vertices_[n_].item = item;
		n_++;
	}

	// LinkedList�� �߰��ϴ� ����
	void InsertEdge(int u, int v) // ���⼭ u, v�� �ε���
	{
		assert(u < n_ && v < n_);

		Node* temp = new Node{ v, list_[u] };
		list_[u] = temp;
	}

	int Capacity()
	{
		return max_vertices_;
	}

	void Print()
	{
		for (int v = 0; v < n_; v++)
		{
			cout << vertices_[v].item << " : ";

			Node* current = list_[v];
			while (current)
			{
				cout << vertices_[current->vertex].item << " ";
				current = current->next;
			}
			cout << endl;
		}

		cout << endl;
	}

	void DepthFirstTraversal()
	{
		ResetVisited();

		DepthFirstTraversal(0);

		cout << endl;
	}

	void DepthFirstTraversal(int v) // ���ȣ��
	{
		
		visited_[v] = true;
		cout << vertices_[v].item << " ";

		Node* current = list_[v];
		// TODO:
		while (current)
		{
			//
			//
			//
			//
		}

	}

	void IterDFT() //���ȣ�� X
	{
		ResetVisited();
		int v = 0;
		Stack<int> s;
		s.Push(v);
		visited_[v] = true;
		// TODO:
		while (!s.IsEmpty())
		{
			//
			//
			
			Node* current = list_[v];
			while (current)
			{
				//
				//
				//
				//
				current = current->next;
			}
		}
		cout << "Stack: ";
		s.Print();
	}

	void BreadthFirstTraversal()
	{
		int v = 0;

		Queue<int> q;
		ResetVisited();
		visited_[v] = true;
		q.Enqueue(v);
		// TODO:

		while (!q.IsEmpty())
		{
			v = q.Front();
			q.Dequeue();

			cout << vertices_[v].item << " ";

			Node* current = list_[v];
			while (current)
			{
				//
				//
				//
				//
			}
			current = current->next;
		}
		cout << "Queue: ";
		q.Print();
		cout << endl;
	}

	void ResetVisited()
	{
		if (!visited_)
			visited_ = new bool[max_vertices_];
		for (int i = 0; i < max_vertices_; i++) visited_[i] = false; // �ʱ�ȭ
	}

private:
	Vertex* vertices_ = nullptr;
	Node** list_ = nullptr;
	int n_ = 0;					// size
	int max_vertices_ = 0;		// capacity

	bool* visited_ = nullptr;
};

int main()
{
	AdjListGraph<int> g(7);

	for (int i = 0; i < g.Capacity(); i++)
		g.InsertVertex(i);

	g.InsertEdge(0, 2);	g.InsertEdge(2, 0);
	g.InsertEdge(0, 1);	g.InsertEdge(1, 0);
	g.InsertEdge(1, 4);	g.InsertEdge(4, 1);
	g.InsertEdge(1, 3);	g.InsertEdge(3, 1);
	g.InsertEdge(2, 4);	g.InsertEdge(4, 2);
	g.InsertEdge(3, 6);	g.InsertEdge(6, 3);
	g.InsertEdge(4, 6);	g.InsertEdge(6, 4);
	g.InsertEdge(5, 6);	g.InsertEdge(6, 5);

	g.Print();

	g.DepthFirstTraversal();
	cout << endl;

	g.IterDFT();

	g.BreadthFirstTraversal();

	return 0;
}