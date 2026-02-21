#include <cstdlib>
int main() {
    // answer: program isn't correct
    // 100th element should be at index 99
    int* data = (int*) malloc(100 * sizeof(int));
    data[100] = 0;
    return 0;
}
