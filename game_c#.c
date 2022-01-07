//c# is used here
using System;
using System.Collections.Generic;

namespace ConnectFourWinner
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[,]  matrix = new int[,] {
                { 0, 0, 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0, 0, 0},
                { 0, 0, 0, 0, 0, 0, 1},
                { 0, 0, 0, 0, 0, 1, 0},
                { 0, 0, 0, 0, 1, 0, 0},
                { 0, 0, 0, 1, 0, 0, 0}
            };
            PrintMatrix(matrix);
            int winner = WinnerCalc(matrix, 5, 3);
            Console.WriteLine("the winner is: " + winner);
        }

        //standar rows is 6, and columns is 7
        public static void PrintMatrix(int[,] matrix)
        {
            int rows = matrix.GetLength(0);
            int columns = matrix.GetLength(1);
            for (int r = 0; r < rows; r++)
            {
                string str = "";
                for (int c = 0; c < columns; c++)
                {
                    str += "   " + matrix[r, c];
                }
                Console.WriteLine(str);
            }
        }

        /// <summary>
        /// WinnerCalc check if blue or red win the game.
        /// </summary>
        /// <returns>Return 1 if 1 win and 2 if 2 win and -1 if no one win.</returns>
        /// <param name="matrix">2d array</param>
        /// <param name="lastRow">The row number.</param>
        /// <param name="lastColumn">The column number.</param>
        public static int WinnerCalc(int[,] matrix, int lastRow, int lastColumn)
        {
            int lastValue = matrix[lastRow, lastColumn];
            Console.WriteLine("drop in row: " + (lastRow) + " and column: " + (lastColumn) + " , the value is: " + lastValue);
            int rows = matrix.GetLength(0); //6
            int columns = matrix.GetLength(1); //7
            Console.WriteLine("number of rows is " + rows + ", and number of colums is " + columns);

            int numToWin = 4;
            int winner = -1;//is now one win tha game
            int match;

            match = 0;
            //check Horizontal
            for (int c = 0; c < columns; c++)
            {
                int currentValue = matrix[lastRow, c];
                if (currentValue == lastValue)
                    match++;
                else match = 0;
                if(match == numToWin)
                {
                    winner = lastValue;
                    break;
                }
            }
            if (winner != -1)
            {
                Console.WriteLine("win Horizontal !");
                return winner;
            }

            match = 0;
            //check Vertical
            for (int r = 0; r < rows; r++)
            {
                int currentValue = matrix[r, lastColumn];
                if (currentValue == lastValue)
                    match++;
                else match = 0;
                if (match == numToWin)
                {
                    winner = lastValue;
                    break;
                }
            }
            if (winner != -1)
            {
                Console.WriteLine("win Vertical !");
                return winner;
            }

            //check diagonal top-left to bottom-right - include middle
            match = 0;
            for (int r = 0; r <= rows - 4; r++)
            {
                int rowPosition = r;
                for (int column = 0; column < columns && rowPosition < rows; column++)
                {
                    int currentValue = matrix[rowPosition, column];
                    if (currentValue == lastValue)
                        match++;
                    else match = 0;
                    if (match == numToWin)
                    {
                        winner = lastValue;
                        break;
                    }
                    rowPosition++;
                }
                if (winner != -1) break;
            }
            if (winner != -1)
            {
                Console.WriteLine("win Diagonal Top left! - include middle");
                return winner;
            }

            //check diagonal top-left to bottom-right - after middle
            match = 0;
            for (int c = 1; c <= columns - 4; c++)
            {
                int columnPosition = c;
                for (int row = 0; row < rows && columnPosition < columns; row++)
                {
                    int currentValue = matrix[row, columnPosition];
                    if (currentValue == lastValue)
                        match++;
                    else match = 0;
                    if (match == numToWin)
                    {
                        winner = lastValue;
                        break;
                    }
                    columnPosition++;
                }
                if (winner != -1) break;
            }
            if (winner != -1)
            {
                Console.WriteLine("win Diagonal Top left! - after middle");
                return winner;
            }


            //check diagonal bottom-left to top-right - include middle
            match = 0;
            for (int r = rows - 1; r >= rows - 4; r--)
            {
                int rowPosition = r;
                for (int column = 0; column < columns && rowPosition < rows && rowPosition >= 0; column++)
                {
                    int currentValue = matrix[rowPosition, column];
                    if (currentValue == lastValue)
                        match++;
                    else match = 0;
                    if (match == numToWin)
                    {
                        winner = lastValue;
                        break;
                    }
                    rowPosition--;
                }
                if (winner != -1) break;
            }
            if (winner != -1)
            {
                Console.WriteLine("win Diagonal Bottom left! - include middle");
                return winner;
            }


            //check diagonal bottom-left to top-right - after middle
            match = 0;
            for (int c = 1; c < columns; c++)
            {
                int columnPosition = c;
                for (int row = rows - 1; row < rows && columnPosition < columns && columnPosition >= 1; row--)
                {
                    int currentValue = matrix[row, columnPosition];
                    if (currentValue == lastValue)
                        match++;
                    else match = 0;
                    if (match == numToWin)
                    {
                        winner = lastValue;
                        break;
                    }
                    columnPosition++;
                }
                if (winner != -1) break;
            }
            if (winner != -1)
            {
                Console.WriteLine("win Diagonal Bottom left! - after middle");
                return winner;
            }



            return winner; // no winner return -1
        }

    }
}