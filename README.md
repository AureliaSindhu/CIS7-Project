# CIS7-Project
This project solves a case of determining the shortest and cheapest path in a given scenario. 

**Written by: CSS**
Members: 
1. Aurelia Sindhunirmala
2. Aurelisa Sindhunirmala
3. Brittany Chan
   
**General Description**
The provided C++ program implements Dijkstra's algorithm to find the shortest paths and minimum cost in a weighted graph. The graph represents a set of cities (Riverside, Moreno, Perris, Hemet) connected by edges with associated weights. The program uses an adjacency list data structure to represent the graph and includes functions for adding edges, printing the adjacency list, finding the minimum distance vertex, and performing Dijkstra's algorithm. The main function initializes the graph, fills it with edge data, prints the adjacency list, and then calculates and displays the shortest paths and minimum cost for each city.

**Given Scenario - Case #1:**
A solar marketing specialist travels from Riverside to Moreno Valley, then to Perris and Hemet to market solar packages to homeowners. The travel route is shown below:
{"Perris", "Riverside", 24}, {"Perris","Moreno", 18}, {"Perris", "Hemet", 30}, {"Riverside", "Perris", 24}, {"Riverside", "Moreno", 16}, {"Riverside", "Hemet", 33}, {"Hemet", "Riverside", 33}, {"Hemet", "Moreno", 26}, {"Hemet", "Perris", 30}};

1. If the marketing specialist begins the trip from home in Riverside, determine the variations of the trip to the noted cities that he must take to market the solar products.
2. Determine the shortest path and the most low-cost trips for the marketing specialist.
3. Create a C++ program to provide the representation of the trips, low-cost and shortest paths, including matrices, and adjacencies.

**Programming Approaches**
1. Graph Representation: The graph is represented using an adjacency list, where each node contains information about the source, weight, and destination.
2. Dijkstra's Algorithm: The program implements Dijkstra's algorithm to find the shortest paths from a source node to all other nodes in the graph.
3. Modular Design: The code is structured using a class (Graph) to encapsulate related functions, providing a modular and organized approach to graph operations.
4. Dynamic Memory Allocation: Dynamic memory allocation is used to create new nodes for the adjacency list.

**How the program works**
The program will automatically output the shortest distance from one node to another with the given information in the scenario. To change the output, there is a modification need to be made in the code itself. 
