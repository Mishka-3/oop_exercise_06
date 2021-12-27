

#include <iostream>
#include "Trapezoid.h"
#include "./containers/list.h"
#include <string.h>
#include <algorithm>
#include "my_allocator.h"

using namespace std;

int main() {
    char str[10];
    containers::list<Trapezoid<int>, myal::my_allocator<Trapezoid<int>, 330>> l;
    while (true) {
        cout << "1-Add " << "2-Print " << "3-Insert " << "4-Delete " << "5-Front " << "6-End " << "7-Get " << "8-Exit" << '\n';
        std::cin >> str;
        if (strcmp(str, "1") == 0) {
            try {
                bool res = false;
                Trapezoid<int> trapezoid;
                std::cout << "coords\n";
                res=trapezoid.scan(std::cin);
                if (res)l.add(trapezoid);                
            }
            catch (std::bad_alloc& e) {
                std::cout << e.what() << std::endl;
                std::cout << "memory limit\n";
                continue;
            }
        }
        else if (strcmp(str, "4") == 0) {
            try {
                int t;
                std::cout << "index\n";
                std::cin >> t;
                l.erase(l.begin() + t);
                std::cout << "\n";
            }
            catch (std::exception& ex) {
                std::cout << ex.what() << "\n";
            }
        }
        else if (strcmp(str, "5") == 0) {
            try {
                l.front().print(std::cout);
                std::cout << "\n";
            }
            catch (std::exception& ex) {
                std::cout << ex.what() << "\n";
            }
        }if (strcmp(str, "7") == 0) {
            try {
                int r;
                std::cout << "index\n";
                std::cin >> r;
                l[r].print(std::cout);
                std::cout << "\n";
            }
            catch (std::exception& ex) {
                std::cout << ex.what() << "\n";
            }
        }
        else if (strcmp(str, "6") == 0) {
            try {
                l.End().print(std::cout);
            }
            catch (std::exception& ex) {
                std::cout << ex.what() << "\n";
            }
        }
        else if (strcmp(str, "3") == 0) {
            try {
                int r;
                bool res = false;
                std::cout << "index\n";
                std::cin >> r;
                Trapezoid<int> trapezoid;
                res = trapezoid.scan(std::cin);
                if (res)l.insert(l.begin() + r, trapezoid);
            }
            catch (std::bad_alloc& e) {
                std::cout << e.what() << std::endl;
                std::cout << "memory limit\n";
                continue;
            }
        }
        else if (strcmp(str, "2") == 0) {
            if (l.begin() != nullptr) {
                std::for_each(l.begin(), l.end(), [](Trapezoid<int> f) {f.print(std::cout); });
                std::cout << "\n";
            }
            else {
                std::cout << "Empty list!" << std::endl;
            }
        }
        else if (strcmp(str, "8") == 0) {
            return 0;     
        }
    }
    return 0;
}
