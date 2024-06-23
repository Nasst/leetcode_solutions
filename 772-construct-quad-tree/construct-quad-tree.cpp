#include <vector>

// Definition for a QuadTree node.
// class Node
// {
// public:
//     bool val;
//     bool isLeaf;
//     Node *topLeft;
//     Node *topRight;
//     Node *bottomLeft;
//     Node *bottomRight;

//     Node()
//     {
//         val = false;
//         isLeaf = false;
//         topLeft = NULL;
//         topRight = NULL;
//         bottomLeft = NULL;
//         bottomRight = NULL;
//     }

//     Node(bool _val, bool _isLeaf)
//     {
//         val = _val;
//         isLeaf = _isLeaf;
//         topLeft = NULL;
//         topRight = NULL;
//         bottomLeft = NULL;
//         bottomRight = NULL;
//     }

//     Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
//     {
//         val = _val;
//         isLeaf = _isLeaf;
//         topLeft = _topLeft;
//         topRight = _topRight;
//         bottomLeft = _bottomLeft;
//         bottomRight = _bottomRight;
//     }
// };

struct SquareCoords
{
    int startRow;
    int startColumn;
    int length;

    SquareCoords(int _startRow, int _startColumn, int _length)
    {
        startRow = _startRow;
        startColumn = _startColumn;
        length = _length;
    }
};

class Solution
{
public:
    Node *constructAux(std::vector<std::vector<int>> &grid, SquareCoords coords)
    {
        auto thereIs0 = false;
        auto thereIs1 = false;
        auto flag = false;
        for (auto i = coords.startRow; i < coords.startRow + coords.length; i++)
        {
            for (auto j = coords.startColumn; j < coords.startColumn + coords.length; j++)
            {
                thereIs0 = thereIs0 || grid[i][j] == 0;
                thereIs1 = thereIs1 || grid[i][j] == 1;
                if (thereIs0 && thereIs1)
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }
        if (!flag)
        {
            return new Node(thereIs1, true);
        }
        else
        {
            auto halfLength = coords.length / 2;
            auto topLeft = constructAux(grid, SquareCoords(coords.startRow, coords.startColumn, halfLength));
            auto topRight = constructAux(grid, SquareCoords(coords.startRow, coords.startColumn + halfLength, halfLength));
            auto bottomLeft = constructAux(grid, SquareCoords(coords.startRow + halfLength, coords.startColumn, halfLength));
            auto bottomRight = constructAux(
                grid, SquareCoords(coords.startRow + halfLength, coords.startColumn + halfLength, halfLength));
            return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
        }
    }

    Node *construct(std::vector<std::vector<int>> &grid)
    {
        return constructAux(grid, SquareCoords(0, 0, grid.size()));
    }
};