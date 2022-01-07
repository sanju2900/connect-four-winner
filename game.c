
/*Return values: 1 for Player 1, 2 for Player 2 and 0 for a tie.
// '-' represents an empty tile, 'X' Player 1, 'O' Player 2
#include <stddef.h>*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int connect4(char *game[], size_t columns, size_t lines)
{
    int winner = -1;
    for (size_t l = 0; l < lines; l++)
    {
        for (size_t c = 0; c < columns; c++)
        {
            char player = game[l][c];
            if (player == '-')
                continue;
            if (c + 3 < columns && player == game[l][c + 1]
                && player == game[l][c + 2] && player == game[l][c + 3])
                winner = winner < 0 ? player : 0;
            if (l + 3 < lines && player == game[l + 1][c]
                && player == game[l + 2][c] && player == game[l + 3][c])
                winner = winner < 0 ? player : 0;
            if (c + 3 < columns && l + 3 < lines && player == game[l + 1][c + 1]
                && player == game[l + 2][c + 2] && player == game[l + 3][c + 3])
                winner = winner < 0 ? player : 0;
            if (c >= 3 && l + 3 < lines && player == game[l + 1][c - 1]
                && player == game[l + 2][c - 2] && player == game[l + 3][c - 3])
                winner = winner < 0 ? player : 0;
        }
    }
    if (winner < 1)
        return 0;
    else
        return winner == 88 ? 1 : 2;
}

int main()
{
    int points[6][7] = {  { 0, 0, 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0, 0, 1},
                { 0, 0, 0, 0, 0, 1, 0},
                { 0, 0, 0, 0, 1, 0, 0},
                { 0, 0, 0, 1, 0, 0, 0}
                    };
   
    cout<<connect4(points);

    return 0;
}