//Chinmay Satpanthi
//CSCI 580
//Assignment 01

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

// 0 1 2
// 3 4 5
// 6 7 8

using namespace std;

//Print function to print out the sequence and nodes and max level
void printSeq(vector<vector<string> > children, int totalNodes, int depth)
{
    string s;
    for (unsigned int i = 0; i < children.size(); i++)
    {
        s = children[i][0];
    }
    for (unsigned int j = 0; j < 3; j++)
    {
        int u = j * 3;
        int stop = (j + 1) * 3;
        for (; u < stop; u++)
            cout << " " << s[u];
        cout << endl;
    }
    cout << endl;

    cout << "Total nodes: " << totalNodes << ", max depth is: " << depth << endl;
}
// Solving puzzle using BFS
void BFS(string initial, string goal)
{
    //maps
    map<string, int> states;
    map<string, int>::iterator it;

    //finding the blank index
    int blank_index = 0;
    for (unsigned int i = 0; i < initial.length(); i++)
    {
        if (initial[i] == '-')
        {
            blank_index = i;
            break;
        }
    }

    queue<int> Q; //initial queue
    Q.push(blank_index);

    //childred double vector for final chain
    vector<vector<string> > children;
    int node_count = 1;
    int prev_index = -1;

    //runs till solution found
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        int top = u - 3;
        int left = u - 1;
        int right = u + 1;
        int bottom = u + 3;

        //TOP MOVE//
        if (top >= 0 && top != prev_index)
        {

            string new_child = initial;
            swap(new_child[u], new_child[top]);
            if (new_child == goal)
            {
                printSeq(children, node_count, states.size());
                break;
            }
            it = states.find(new_child);
            if (it == states.end())
            {
                initial = new_child;
                node_count++;
                Q.push(top);
            }
        }

        //LEFT MOVE//
        if (left >= 0 && u % 3 != 0 && left != prev_index)
        {

            string new_child = initial;
            swap(new_child[u], new_child[left]);
            if (new_child == goal)
            {
                printSeq(children, node_count, states.size());
                break;
            }
            it = states.find(new_child);
            if (it == states.end())
            {
                initial = new_child;
                node_count++;
                Q.push(left);
            }
        }

        //RIGHT MOVE//
        if (right <= 8 && u % 3 != 2 && right != prev_index)
        {
            string new_child = initial;
            swap(new_child[u], new_child[right]);
            if (new_child == goal)
            {
                printSeq(children, node_count, states.size());
                break;
            }
            it = states.find(new_child);
            if (it == states.end())
            {
                initial = new_child;
                node_count++;
                Q.push(right);
            }
        }

        //BOTTOM MOVE//
        if (bottom <= 8 && bottom != prev_index)
        {
            string new_child = initial;
            swap(new_child[u], new_child[bottom]);
            if (new_child == goal)
            {
                printSeq(children, node_count, states.size());
                break;
            }
            it = states.find(new_child);
            if (it == states.end())
            {
                initial = new_child;
                node_count++;
                Q.push(bottom);
            }
        }
    }
}

//Depth First Seach Function
void DFS(string initial, string goal)
{
    //maps to store values
    map<string, int> states;
    map<string, int>::iterator it;

    int blank_index = 0;
    for (unsigned int i = 0; i < initial.length(); i++)
    {
        if (initial[i] == '-')
        {
            blank_index = i;
            break;
        }
    }

    queue<int> Q; //initial queue
    Q.push(blank_index);

    //vector to store strings
    vector<vector<string> > children;
    int node_count = 1;
    int prev_index = -1;

    //DFS through the puzzle points
    for (unsigned int i = 0; i < 9; i++)
    {
        int u = Q.front();
        Q.pop();
        int top = u - 3;
        int left = u - 1;
        int right = u + 1;
        int bottom = u + 3;

        //TOP MOVE//
        if (top >= 0 && top != prev_index)
        {

            string new_child = initial;
            swap(new_child[u], new_child[top]);
            if (new_child == goal)
            {
                printSeq(children, node_count, states.size());
                break;
            }
            it = states.find(new_child);
            if (it == states.end())
            {
                initial = new_child;
                node_count++;
                Q.push(top);
            }
            //LEFT MOVE//
            if (left >= 0 && u % 3 != 0 && left != prev_index)
            {

                string new_child = initial;
                swap(new_child[u], new_child[left]);
                if (new_child == goal)
                {
                    printSeq(children, node_count, states.size());
                    break;
                }
                it = states.find(new_child);
                if (it == states.end())
                {
                    initial = new_child;
                    node_count++;
                    Q.push(left);
                }

                //RIGHT MOVE/
                if (right <= 8 && u % 3 != 2 && right != prev_index)
                {
                    string new_child = initial;
                    swap(new_child[u], new_child[right]);
                    if (new_child == goal)
                    {
                        printSeq(children, node_count, states.size());
                        break;
                    }
                    it = states.find(new_child);
                    if (it == states.end())
                    {
                        initial = new_child;
                        node_count++;
                        Q.push(right);
                    }
                    //BOTTOM MOVE//
                    if (bottom <= 8 && bottom != prev_index)
                    {
                        string new_child = initial;
                        swap(new_child[u], new_child[bottom]);
                        if (new_child == goal)
                        {
                            printSeq(children, node_count, states.size());
                            break;
                        }
                        it = states.find(new_child);
                        if (it == states.end())
                        {
                            initial = new_child;
                            node_count++;
                            Q.push(bottom);
                        }
                    }
                }
            }
        }
    }
}

//Manhattan Function
void Manhattan(string initial, string goal)
{
    //map to store values
    map<string, int> states;
    map<string, int>::iterator it;

    int blank_index = 0;
    for (unsigned int i = 0; i < initial.length(); i++)
    {
        if (initial[i] == '-')
        {
            blank_index = i;
            break;
        }
    }

    queue<int> Q; //initial queue
    Q.push(blank_index);

    vector<vector<string> > children;
    int node_count = 1;
    int prev_index = -1;

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        int top = u - 3;
        int left = u - 1;
        int right = u + 1;
        int bottom = u + 3;

        //TOP//
        if (top >= 0 && top != prev_index)
        {

            string new_child = initial;
            swap(new_child[u], new_child[top]);
            if (new_child == goal)
            {
                printSeq(children, node_count, states.size());
                break;
            }
            it = states.find(new_child);
            if (it == states.end())
            {
                initial = new_child;
                node_count++;
                Q.push(top);
            }
        }

        //LEFT//
        if (left >= 0 && u % 3 != 0 && left != prev_index)
        {

            string new_child = initial;
            swap(new_child[u], new_child[left]);
            if (new_child == goal)
            {
                printSeq(children, node_count, states.size());
                break;
            }
            it = states.find(new_child);
            if (it == states.end())
            {
                initial = new_child;
                node_count++;
                Q.push(left);
            }
        }

        //RIGHT//
        if (right <= 8 && u % 3 != 2 && right != prev_index)
        {
            string new_child = initial;
            swap(new_child[u], new_child[right]);
            if (new_child == goal)
            {
                printSeq(children, node_count, states.size());
                break;
            }
            it = states.find(new_child);
            if (it == states.end())
            {
                initial = new_child;
                node_count++;
                Q.push(right);
            }
        }

        //BOTTOM//
        if (bottom <= 8 && bottom != prev_index)
        {
            string new_child = initial;
            swap(new_child[u], new_child[bottom]);
            if (new_child == goal)
            {
                printSeq(children, node_count, states.size());
                break;
            }
            it = states.find(new_child);
            if (it == states.end())
            {
                initial = new_child;
                node_count++;
                Q.push(bottom);
            }
        }
    }
}

//Main function
int main()
{
    string initial_state = "";
    string goal_state = "";
    string command = "";

    cin >> initial_state; //stores the initial state
    cin >> goal_state;    //stores the goal state
    cin >> command;       //stores the command

    if (command == "bfs") //runs the BFS function
    {
        BFS(initial_state, goal_state);
    }
    if (command == "dfs") //runs the DFS function
    {
        DFS(initial_state, goal_state);
    }
    if (command == "star") //runs the Manhattan function
    {
        Manhattan(initial_state, goal_state);
    }

    return 0;
}
