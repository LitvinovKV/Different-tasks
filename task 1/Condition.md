There is a grid with S rows and S columns. Blocked cells are marked as ‘1’ and free cells are marked as ‘0’. You need to get from initial cell with coordinates (inX; inY) to target cell with coordinates (tgX; tgY). It is possible to move only by X and Y axes.
One move means any number of steps without changing of direction. 
Write a program to determine the minimum number of moves to get to the target cell.
Example:
0 0 0
1 1 0
0 0 0
Minimum number of moves from (0;0) (upper left corner) to (2;0) (bottom left corner) requires three moves: (0;0) -> (0;2) -> (2;2) -> (2;0)
Output: minimum number of moves or -1 if there is no way
