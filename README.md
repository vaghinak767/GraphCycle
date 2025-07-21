# Graph Longest Cycle Finder

This C++ program reads a graph from an input file and attempts to find the longest cycle in the graph.

## Description

The program consists of two main classes:
- `Kogh`: Represents an edge in the graph (with x and y coordinates)
- `Graf`: Represents a graph with vertices and edges, containing methods to find the longest cycle

## Features

- Reads graph data from "input.txt" file
- Implements graph representation using vectors
- Provides recursive methods to find cycles in the graph
- Tracks and returns the longest cycle found
- Includes operator overloading for easy output of graph elements

## File Structure

- `main.cpp`: Contains all the implementation
- `input.txt`: Input file containing graph data (expected format described below)

## Input File Format

The input file should contain:
1. First line: any header line (ignored in current implementation)
2. Second line: graph edges in the format "1 2 2 3 3 4" etc.
This means that 1 vertice is neighbor with 2, 2 with 3, 3 with 4, and etc.
