#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> dynamic;

    void dynamicAux(std::vector<std::vector<int>> &books, int start, int shelfWidth)
    {
        auto book = books[start];
        auto booksWidth = book[0];
        auto booksHeight = book[1];
        auto minShelfHeight = booksHeight + dynamic[start + 1];
        for (auto i = start + 1; i < books.size(); i++)
        {
            auto newBook = books[i];
            auto newBookWidth = newBook[0];
            auto newBookHeight = newBook[1];
            if (newBookWidth + booksWidth <= shelfWidth)
            {
                booksWidth += newBookWidth;
                booksHeight = std::max(booksHeight, newBookHeight);
                auto currentShelfHeiht = booksHeight + dynamic[i + 1];
                minShelfHeight = std::min(minShelfHeight, currentShelfHeiht);
            }
            else
            {
                break;
            }
        }
        dynamic[start] = minShelfHeight;
    }

    int minHeightShelves(std::vector<std::vector<int>> &books, int shelfWidth)
    {
        dynamic = std::vector<int>(books.size() + 1, -1);
        dynamic[books.size()] = 0;
        for(auto i = static_cast<int>(books.size()) - 1; i >= 0; i--) {
            dynamicAux(books, i, shelfWidth);
        }
        return dynamic[0];
    }
};