#include <iostream>
#include <limits.h>

int main() {

    int n;
    std::cin >> n;
   
    int heights[100];
    int min_height = INT_MAX, max_height = INT_MIN;
    int min_height_index = 0, max_height_index = 99;

    for (int i = 0; i < n; i++)
    {
        std::cin >> heights[i];
        if (heights[i] <= min_height)
        {
            min_height = heights[i];
            min_height_index = i;
        }
		if (heights[i] > max_height)
        {
            max_height = heights[i];
            max_height_index = i;
        }
    }

    if (max_height_index > min_height_index)
    {
        std::cout << max_height_index + n - min_height_index - 2;
    } else if (max_height_index < min_height_index)
    {
        std::cout << max_height_index + n - min_height_index - 1;
    } else {
        std::cout << 0;
    }

    return 0;
}
