#include <iostream>
#include <string>

using namespace std;

int main() 
{
    int n, result = 0;
    cin >> n;
    string polyhedron;
    for (int i = 0; i < n; ++i) {
        cin >> polyhedron;
        if (polyhedron == "Tetrahedron") {
            result += 4;
        } else if (polyhedron == "Cube") {
            result += 6;
        } else if (polyhedron == "Octahedron") {
            result += 8;
        } else if (polyhedron == "Dodecahedron") {
            result += 12;
        } else if (polyhedron == "Icosahedron") {
            result += 20;
        }
    }
    cout << result << '\n';

    return 0;
}