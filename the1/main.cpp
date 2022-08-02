//
//  main.cpp
//
//  Created by Ceren Dinç on 24.04.2022.
//

// Ceren Dinc 28220

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Stack.h"
#include "randgen.h"
#include "strutils.h"

using namespace std;

int u = 1;
int r = 2;
int d = 3;
int l = 4;

int mRow, nCol;

Stack<int> s;
Stack<int> s2;

Stack<int> ss;
Stack<int> ss2;

Stack<int> sss;
Stack<int> sss2;

Stack<int> x;
Stack<int> x2;

Stack<int> xx;
Stack<int> xx2;

Stack<int> xxx;
Stack<int> xxx2;

void popPush(Stack<int> &a, Stack<int> &a2, Stack<int> &aa, Stack<int> &aa2, int currentRow, int currentCol, bool &check)
{

    check = true; // this popPush function checks whether the cell is already visited or not.

    while (!a.isEmpty())
    {
        if (a.top() == currentRow && a2.top() == currentCol)
        {
            check = false; // if check is false it means the cell is already visited and it cannot be chosen again
            aa.push(a.top());
            aa2.push(a2.top());
            a.pop();
            a2.pop();
        }
        else
        {
            aa.push(a.top());
            aa2.push(a2.top());
            a.pop();
            a2.pop();
        }
    }
    if (a.isEmpty())
    {
        while (!aa.isEmpty())
        {
            a.push(aa.top());
            a2.push(aa2.top());
            aa.pop();
            aa2.pop();
        }
    }
}

void isUp(vector<vector<int>> vct, int currentRow, int currentCol, vector<int> &randomVec, bool check)
{
    // isUp function first checks if there is a cell exists on the up side
    if (currentRow != vct.size() - 1)
    {
        popPush(s, s2, ss, ss2, currentRow + 1, currentCol, check); // checks if this cell on the up side is already visited
        if (check == true && sss.isEmpty())
        {
            randomVec.push_back(u);
        }
        else if (check == true && !sss.isEmpty())
        { // it also checks cells that are popped while backtracking
            popPush(sss, sss2, ss, ss2, currentRow + 1, currentCol, check);
            if (check == true)
            {
                randomVec.push_back(u);
            }
        }
    }
}

void isRight(vector<vector<int>> vct, int currentRow, int currentCol, vector<int> &randomVec, bool check)
{
    // isRight function first checks if there is a cell exists on the right side
    if (currentCol != vct[0].size() - 1)
    {
        popPush(s, s2, ss, ss2, currentRow, currentCol + 1, check); // checks if this cell on the right side is already visited
        if (check == true && sss.isEmpty())
        {
            randomVec.push_back(r);
        }
        else if (check == true && !sss.isEmpty())
        { // it also checks cells that are popped while backtracking
            popPush(sss, sss2, ss, ss2, currentRow, currentCol + 1, check);
            if (check == true)
            {
                randomVec.push_back(r);
            }
        }
    }
}

void isDown(vector<vector<int>> vct, int currentRow, int currentCol, vector<int> &randomVec, bool check)
{
    // isDown function first checks if there is a cell exists on the down side
    if (currentRow != 0)
    {
        popPush(s, s2, ss, ss2, currentRow - 1, currentCol, check); // checks if this cell on the down side is already visited
        if (check == true && sss.isEmpty())
        {
            randomVec.push_back(d);
        }
        else if (check == true && !sss.isEmpty())
        { // it also checks cells that are popped while backtracking
            popPush(sss, sss2, ss, ss2, currentRow - 1, currentCol, check);
            if (check == true)
            {
                randomVec.push_back(d);
            }
        }
    }
}

void isLeft(vector<vector<int>> vct, int currentRow, int currentCol, vector<int> &randomVec, bool check)
{
    // isLeft function first checks if there is a cell exists on the left side
    if (currentCol != 0)
    {
        popPush(s, s2, ss, ss2, currentRow, currentCol - 1, check); // checks if this cell on the left side is already visited
        if (check == true && sss.isEmpty())
        {
            randomVec.push_back(l);
        }
        else if (check == true && !sss.isEmpty())
        { // it also checks cells that are popped while backtracking
            popPush(sss, sss2, ss, ss2, currentRow, currentCol - 1, check);
            if (check == true)
            {
                randomVec.push_back(l);
            }
        }
    }
}

bool isOver(Stack<int> &s, Stack<int> &s2, Stack<int> &ss, Stack<int> &ss2, Stack<int> &sss, Stack<int> &sss2, int mRow, int nCol)
{
    // checks whether both cells are visited
    int count = 0;

    while (!s.isEmpty())
    {
        ss.push(s.top());
        s.pop();
        count++;
    }
    if (s.isEmpty())
    {
        while (!ss.isEmpty())
        {
            s.push(ss.top());
            ss.pop();
        }
    }

    while (!sss.isEmpty())
    {
        ss.push(sss.top());
        sss.pop();
        count++;
    }

    if (sss.isEmpty())
    {
        while (!ss.isEmpty())
        {
            sss.push(ss.top());
            ss.pop();
        }
    }
    if (count == mRow * nCol)
    {
        return false;
    }
    return true;
}

bool popPush3(Stack<int> &x, Stack<int> &x2, Stack<int> &xx, Stack<int> &xx2, Stack<int> &xxx, Stack<int> &xxx2, int currX, int currY, bool &check, bool &check2)
{
    // function checks whether the cekk in the parameter is already visited (just like popPush function)

    while (!x.isEmpty())
    {
        if (x.top() == currX && x2.top() == currY)
        {
            check = false;
            xx.push(x.top());
            xx2.push(x2.top());
            x.pop();
            x2.pop();
        }
        else
        {
            xx.push(x.top());
            xx2.push(x2.top());
            x.pop();
            x2.pop();
        }
    }
    while (!xx.isEmpty())
    {
        x.push(xx.top());
        x2.push(xx2.top());
        xx.pop();
        xx2.pop();
    }

    while (!xxx.isEmpty())
    {
        if (xxx.top() == currX && xxx2.top() == currY)
        {
            check2 = false;
            xx.push(xxx.top());
            xx2.push(xxx2.top());
            xxx.pop();
            xxx2.pop();
        }
        else
        {
            xx.push(xxx.top());
            xx2.push(xxx2.top());
            xxx.pop();
            xxx2.pop();
        }
    }
    while (!xx.isEmpty())
    {
        xxx.push(xx.top());
        xxx2.push(xx2.top());
        xx.pop();
        xx2.pop();
    }

    if (check == false || check2 == false)
    {
        return false;
    }
    else if (check == false && check2 == false)
    {
        return false;
    }
    return true;
}

void findPath(vector<string> ioVec, int entryCol, int entryRow, int exitCol, int exitRow, int count)
{
    // function for finding a path
    ofstream temp2;
    string filename2 = "maze_" + itoa(count) + "_path_" + itoa(entryCol) + "_" + itoa(entryRow) + "_" + itoa(exitCol) + "_" + itoa(exitRow) + "_.txt";
    temp2.open(filename2);

    RandGen(rndm);

    vector<int> rndmVec;

    x.push(entryCol);
    x2.push(entryRow);

    int currX = entryCol; // currX is x axis
    int currY = entryRow; // currY is y axis

    bool find = false;

    while (find == false)
    {
        bool check = true;
        bool check2 = true;

        while (rndmVec.size() != 0)
        {
            rndmVec.pop_back();
        }

        for (int i = 0; i < ioVec.size(); ++i)
        { // searching for paths without walls
            int idx = ioVec[i].find("l");
            if (ioVec[i].substr(0, idx - 1) == "x=" + itoa(currX) + " y=" + itoa(currY))
            {
                int uu = ioVec[i].find("u") + 2;
                int rr = ioVec[i].find("r") + 2;
                int dd = ioVec[i].find("d") + 2;
                int ll = ioVec[i].find("l") + 2;

                // below: if statements are collecting unvisited cells for the path
                if (ioVec[i][uu] == '0' && (currY + 1) != nCol)
                {
                    check = true;
                    check2 = true;
                    if (popPush3(x, x2, xx, xx2, xxx, xxx2, currX, currY + 1, check, check2) == true)
                    {
                        rndmVec.push_back(1);
                    }
                }
                if (ioVec[i][rr] == '0' && (currX + 1) != mRow)
                {
                    check = true;
                    check2 = true;
                    if (popPush3(x, x2, xx, xx2, xxx, xxx2, currX + 1, currY, check, check2) == true)
                    {
                        rndmVec.push_back(2);
                    }
                }
                if (ioVec[i][dd] == '0' && (currY - 1) != -1)
                {
                    check = true;
                    check2 = true;
                    if (popPush3(x, x2, xx, xx2, xxx, xxx2, currX, currY - 1, check, check2) == true)
                    {
                        rndmVec.push_back(3);
                    }
                }
                if (ioVec[i][ll] == '0' && (currX - 1) != -1)
                {
                    check = true;
                    check2 = true;
                    if (popPush3(x, x2, xx, xx2, xxx, xxx2, currX - 1, currY, check, check2) == true)
                    {
                        rndmVec.push_back(4);
                    }
                }
                if (rndmVec.size() != 0)
                {
                    int randomWay = rndm.RandInt(0, rndmVec.size() - 1);
                    // below: updating current cells of the path according to randomly chosen cell
                    if (rndmVec[randomWay] == 1)
                    {
                        currY++;
                    }
                    else if (rndmVec[randomWay] == 2)
                    {
                        currX++;
                    }
                    else if (rndmVec[randomWay] == 3)
                    {
                        currY--;
                    }
                    else if (rndmVec[randomWay] == 4)
                    {
                        currX--;
                    }
                    x.push(currX); // pushing current cells of the path to stacks
                    x2.push(currY);
                }
                else
                { // backtrack operation just like i did while generating mazes
                    xxx.push(x.top());
                    xxx2.push(x2.top());
                    x.pop();
                    x2.pop();

                    currY = x2.top();
                    currX = x.top();
                }
                break;
            }
        }

        if (x.top() == exitCol && x2.top() == exitRow)
        { // find is true if exit points are found
            find = true;
        }
    }

    Stack<int> xs;
    Stack<int> xs2;

    while (!x.isEmpty())
    {
        xs.push(x.top());
        xs2.push(x2.top());
        x.pop();
        x2.pop();
    }
    while (!xs.isEmpty())
    {
        temp2 << xs.top() << " " << xs2.top() << endl; // writing coordinates of the path to a txt file
        xs.pop();
        xs2.pop();
    }
}

int main()
{

    int kMaze, pathMaze, entryCol, entryRow, exitCol, exitRow;
    int count = 0;

    cout << "Enter the number of mazes: "; // user inputs
    cin >> kMaze;
    cout << "Enter the number of rows and columns (M and N): ";
    cin >> mRow >> nCol;
    cout << "All mazes are generated." << endl;
    cout << "Enter a maze ID between 1 to " << kMaze << " inclusive to find a path: ";
    cin >> pathMaze;
    cout << "Enter x and y coordinates of the entry points (x,y) or (column,row): ";
    cin >> entryCol >> entryRow;
    cout << "Enter x and y coordinates of the exit points (x,y) or (column,row): ";
    cin >> exitCol >> exitRow;

    while (count != kMaze)
    { // it generates mazes up to kMaze

        while (!s.isEmpty())
        { // emptying stacks when switching to new maze
            s.pop();
            s2.pop();
        }
        while (!ss.isEmpty())
        {
            ss.pop();
            ss2.pop();
        }
        while (!sss.isEmpty())
        {
            sss.pop();
            sss2.pop();
        }

        int currentRow, currentCol, randomCell;
        bool move = true;
        bool check = true;
        string ioLine;

        ofstream temp;                                        // creating txt files for mazes
        string filename = "maze_" + itoa(count + 1) + ".txt"; // name of the txt file according to number of the current maze
        temp.open(filename);

        RandGen(rnd);

        vector<vector<int>> mazeVec(mRow, vector<int>(nCol)); // 2d vector which has mRow rows & nCol columns
        vector<int> randomVec;                                // vector that stores empty cells to go

        vector<string> ioVec; // vector that stores final stack's information

        currentRow = 0;
        currentCol = 0;

        string strRow = itoa(currentRow);
        string strCol = itoa(currentCol);

        string ioLine2 = "x=" + strCol + " y=" + strRow;

        s.push(currentRow);
        s2.push(currentCol);

        ioLine = "x=0 y=0 l=1 r=1 u=1 d=1";

        ioVec.push_back(ioLine);

        while (move == true)
        { // when move is true it means there are empty cells to visit

            while (randomVec.size() != 0)
            {
                randomVec.pop_back();
            }
            isUp(mazeVec, currentRow, currentCol, randomVec, check);    // checks cell above
            isRight(mazeVec, currentRow, currentCol, randomVec, check); // checks the cell on the right
            isDown(mazeVec, currentRow, currentCol, randomVec, check);  // checks the cell below
            isLeft(mazeVec, currentRow, currentCol, randomVec, check);  // checks the cell on the left
            if (randomVec.size() != 0)
            { // if an empty cell to go has been found

                int randomNum = rnd.RandInt(0, randomVec.size() - 1);
                randomCell = randomVec[randomNum]; // randomly chooses one of the cells that can be visited

                strRow = itoa(currentRow);
                strCol = itoa(currentCol);

                ioLine2 = "x=" + strCol + " y=" + strRow;

                for (int i = 0; i < ioVec.size(); ++i)
                { // Updates the walls of previously written cells
                    int idx = ioVec[i].find("l");
                    if (ioVec[i].substr(0, idx - 1) == ioLine2)
                    {
                        if (randomCell == 1)
                        { // randomCell getting 1 updates the cell above
                            int u = ioVec[i].find("u");
                            ioVec[i].at(u + 2) = '0';
                        }
                        else if (randomCell == 2)
                        { // randomCell getting 2 updates the cell on the right
                            int r = ioVec[i].find("r");
                            ioVec[i].at(r + 2) = '0';
                        }
                        else if (randomCell == 3)
                        { // randomCell getting 3 updates the cell below
                            int d = ioVec[i].find("d");
                            ioVec[i].at(d + 2) = '0';
                        }
                        else if (randomCell == 4)
                        { // randomCell getting 4 updates the cell on the left
                            int l = ioVec[i].find("l");
                            ioVec[i].at(l + 2) = '0';
                        }
                    }
                }

                if (randomCell == 1)
                { // increases current row
                    currentRow++;
                    strRow = itoa(currentRow);
                    string ioLine2 = "x=" + strCol + " y=" + strRow + " l=1 r=1 u=1 d=0";
                    ioVec.push_back(ioLine2);
                }
                else if (randomCell == 2)
                { // increases current column
                    currentCol++;
                    strCol = itoa(currentCol);
                    string ioLine2 = "x=" + strCol + " y=" + strRow + " l=0 r=1 u=1 d=1";
                    ioVec.push_back(ioLine2);
                }
                else if (randomCell == 3)
                { // decreases current row
                    currentRow--;
                    strRow = itoa(currentRow);
                    string ioLine2 = "x=" + strCol + " y=" + strRow + " l=1 r=1 u=0 d=1";
                    ioVec.push_back(ioLine2);
                }
                else if (randomCell == 4)
                { // decreases current column
                    currentCol--;
                    strCol = itoa(currentCol);
                    string ioLine2 = "x=" + strCol + " y=" + strRow + " l=1 r=0 u=1 d=1";
                    ioVec.push_back(ioLine2);
                }

                s.push(currentRow);  // pushing the new row
                s2.push(currentCol); // pushing the new column
            }
            else
            {

                if (!isOver(s, s2, ss, ss2, sss, sss2, mRow, nCol))
                { // checks whether all cells are visited or not

                    move = false;
                }
                else
                {
                    // backtracking operations --> top of the main stack changes and popped cells are stored in another stacks
                    sss.push(s.top());
                    sss2.push(s2.top());
                    s.pop();
                    s2.pop();

                    currentRow = s.top(); // updating new current row and column after backtrack
                    currentCol = s2.top();
                }
            }
        }

        temp << mRow << " " << nCol << endl;
        for (int i = 0; i < ioVec.size(); ++i)
        { // writing to txt files
            temp << ioVec[i] << endl;
        }

        count++;

        if (count == pathMaze)
        { // finding a path for the chosen maze
            findPath(ioVec, entryCol, entryRow, exitCol, exitRow, count);
        }
    }

    return 0;
}
