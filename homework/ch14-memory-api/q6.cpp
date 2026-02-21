#include <cstdlib>
#include <iostream>

int main() {
    int* data = (int*) malloc(100 * sizeof(int));
    data[0] = 5;
    std::cout << data[0] << '\n';

    free(data + 50);

    std::cout << data[0] << '\n';
    return 0;
}
