#include "ufset.h"

int main() {
    ElemType things[] = {
        "apple",     // 0
        "cat",       // 1
        "dog",       // 2
        "egg",       // 3
        "fish",      // 4
        "elephant",  // 5
        "banana",    // 6
        "car",       // 7
        "book",      // 8
        "pen",       // 9
        "pear",      // 10
    };
    UFSTree t;
    InitUFS(t, things, 11);
    PrintUFS(t);

    // 合并集合
    Union(t, 0, 6);   // apple和banana
    Union(t, 1, 2);   // cat和dog
    Union(t, 1, 5);   // cat和elephant
    Union(t, 2, 4);   // dog和fish
    Union(t, 6, 10);  // banana和pear
    PrintUFS(t);

    return 0;
}