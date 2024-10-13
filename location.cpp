#include <iostream>
#include <map>
#include <list>
#include <string>
#include <limits>

using namespace std;

class Graph {
private:
    /*in this we are pairing a city with another city and mention distance between themfor distance we are using int and those citys we mentioned string.
    the name of the map is adjacency list in short form adjlist.The main perpose is to store the graph in adjlist format
    each city has a list of neighboring cities*/ 
    map<string, list<pair<string, float>>> adjList;

public:
    //now we are creating a Undirected graph 
    void addEdge(const string& city1, const string& city2, float distance) {
        adjList[city1].push_back(make_pair(city2, distance));
        adjList[city2].push_back(make_pair(city1, distance));
    }

    void displayGraph() {
        for (const auto& city : adjList) {
            cout << city.first << ": ";
            for (const auto& neighbor : city.second) {
                cout <<neighbor.first << ", " << neighbor.second << " km";
            }
            cout << endl;
        }
    }

    int getDistance(const string& city1, const string& city2) {
        for (const auto& neighbor : adjList[city1]) {
            if (neighbor.first == city2) {
                return neighbor.second;
            }
        }
        return -1;
    }

    void createGraph() {
        addEdge("Guntur", "Vijayawada", 34.8);
        addEdge("Guntur", "Mangalagiri", 21.5);
        addEdge("Guntur", "Nerukonda", 25.2);
        addEdge("Guntur", "Tenali", 27.6);
        addEdge("Guntur", "Sattenapalli", 35.4);
        addEdge("Guntur", "Eluru", 94.7);
        addEdge("Guntur", "Bapatla", 53.9);
        addEdge("Guntur", "Chirala", 65.5);
        addEdge("Guntur", "Amaravathi", 37.8);
        
        addEdge("Vijayawada", "Mangalagiri", 15.2);
        addEdge("Vijayawada", "Nerukonda", 26.6);
        addEdge("Vijayawada", "Tenali", 35.2);
        addEdge("Vijayawada", "Sattenapalli", 76.9);
        addEdge("Vijayawada", "Eluru", 59.3);
        addEdge("Vijayawada", "Bapatla", 84.8);
        addEdge("Vijayawada", "Chirala", 100.6);
        addEdge("Vijayawada", "Amaravathi", 18.8);
        
        addEdge("Mangalagiri", "Nerukonda", 10.2);
        addEdge("Mangalagiri", "Tenali", 26.9);
        addEdge("Mangalagiri", "Sattenapalli", 61.8);
        addEdge("Mangalagiri", "Eluru", 72.7);
        addEdge("Mangalagiri", "Bapatla", 69.8);
        addEdge("Mangalagiri", "Chirala", 86.7);
        addEdge("Mangalagiri", "Amaravathi", 13.7);
        
        addEdge("Nerukonda", "Tenali", 36.8);
        addEdge("Nerukonda", "Sattenapalli", 50.8);
        addEdge("Nerukonda", "Eluru", 83.4);
        addEdge("Nerukonda", "Bapatla", 73.5);
        addEdge("Nerukonda", "Chirala", 91.6);
        addEdge("Nerukonda", "Amaravathi", 9.6);
        
        addEdge("Tenali", "Sattenapalli", 61.4);
        addEdge("Tenali", "Eluru", 96.7);
        addEdge("Tenali", "Bapatla", 49.7);
        addEdge("Tenali", "Chirala", 66.3);
        addEdge("Tenali", "Amaravathi", 40.7);
        
        addEdge("Sattenapalli", "Eluru", 135.0);
        addEdge("Sattenapalli", "Bapatla", 86.7);
        addEdge("Sattenapalli", "Chirala", 82.7);
        addEdge("Sattenapalli", "Amaravathi", 61.6);
        
        addEdge("Eluru", "Bapatla", 140.0);
        addEdge("Eluru", "Chirala", 158.0);
        addEdge("Eluru", "Amaravathi", 77.5);
        
        addEdge("Bapatla", "Chirala", 16.9);
        addEdge("Bapatla", "Amaravathi", 84.0);
        
        addEdge("Chirala", "Amaravathi", 97.3);
    }
};
class distance_calculation{
    public:
    
};

int main() {
    Graph g;
    int dis;

    g.createGraph();

    string city1, city2;

    cout << "Your current location:"<<endl;
    cout << "Guntur\nVijayawada\nMangalagiri\nNerukonde\nTenali\nSattenapalli\nEluru\nBapatla\nChirala\nAmaravathi\n";
    cout << "Enter your current Location: ";
    cin >> city1;

    for (const string& city : {"Guntur", "Vijayawada", "Mangalagiri", "Nerukonda", "Tenali","Sattenapalli", "Eluru", "Bapatla", "Chirala", "Amaravathi"}) {
        if (city != city1) {
            cout << city<<endl;
        }
    }
    cout << "Enter your Drop choice: ";
    cin >> city2;

    int distance = g.getDistance(city1, city2);
    if (distance != -1) {
        cout << "The distance between " << city1 << " and " << city2 << " is " << distance << " km.\n";
    } else {
        cout << "There is no direct connection between " << city1 << " and " << city2 << ".\n";
    }
    return 0;
}