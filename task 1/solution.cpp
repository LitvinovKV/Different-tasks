int findMinMoves(int startX, int startY, int endX, int endY, int** table, int lengthTable) 
{
	// Init adjacency matrix for one step
	int lengthMatrix = lengthTable * lengthTable;
	bool** matrix = new bool*[lengthMatrix];
	for (int i = 0; i < lengthTable * lengthTable; i++)
	{
		// calc [i][j] it table
		int tableI = i / lengthTable;
		int tableJ = i % lengthTable;
		matrix[i] = new bool[lengthMatrix];
		for (int j = 0; j < lengthMatrix; j++)
			matrix[i][j] = false;
		// if point has value = 1 that we can't go to another point from it
		if (table[tableI][tableJ] == 1)
			continue;
		else {
			// check in table right values at table[tableI][tableJ]
			if (tableJ < lengthTable)
			{
				for (int tj = tableJ + 1; tj < lengthTable; tj++)
				{
					if (table[tableI][tj] == 1)
						break;
					matrix[i][tableI * lengthTable + tj] = true;
				}
			}
			// check in table left values at table[tableI][tableJ]
			if (tableJ > 0)
			{
				for (int tj = tableJ - 1; tj >= 0; tj--)
				{
					if (table[tableI][tj] == 1)
						break;
					matrix[i][tableI * lengthTable + tj] = true;
				}
			}
			// check in table above values at table[tableI][tableJ]
			if (tableI > 0)
			{
				for (int ti = tableI - 1; ti >= 0; ti--)
				{
					if (table[ti][tableJ] == 1)
						break;
					matrix[i][ti * lengthTable + tableJ] = true;
				}
			}
			// check in table under values at table[tableI][tableJ]
			if (tableI < lengthTable)
			{
				for (int ti = tableI + 1; ti < lengthTable; ti++)
				{
					if (table[ti][tableJ] == 1)
						break;
					matrix[i][ti * lengthTable + tableJ] = true;
				}
			}
		}
	}

	/*
	* matrix with one step MUL matrix with one step = matrix with two step
	* matrix with two step MUL matrix with two step = matrix with three step
	* ...
	* We must mul all raws with matrix[i][endPoint], because we need just way for endPoint
	* MUL matrices while row point start values != false and column point end values != false OR
	* if [pointStart][pointEnd] == true then the count of multiply is the answer
	*/
	int startPoint = startX * 3 + startY;
	int endPoint = endX * 3 + endY;
	int countMUL = 1;
	while (true)
	{
		countMUL++;
		for (int i = 0; i < lengthMatrix; i++)
		{
			bool result = false;
			for (int k = 0; k < lengthMatrix; k++)
			{
				result |= matrix[i][k] & matrix[k][endPoint];
			}
			matrix[i][endPoint] = result;
		}

		// if we find way, then return countMUL is our answer
		if (matrix[startPoint][endPoint] == true)
			break;

		// check for possible reachability of points
		// if we can't find any way from start point then return -1
		bool checkStartRow = false;
		for (int j = 0; j < lengthMatrix; j++)
			checkStartRow |= matrix[startPoint][j];
		if (checkStartRow == false)
		{
			countMUL = -1;
			break;
		}

		// if we can't find any way to end point then return -1
		bool checkEndColumn = false;
		for (int i = 0; i < lengthMatrix; i++)
			checkEndColumn |= matrix[i][endPoint];
		if (checkEndColumn == false)
		{
			countMUL = -1;
			break;
		}
	}

	for (int i = 0; i < lengthMatrix; i++)
		delete[] matrix[i];
	delete[] matrix;

	return countMUL;
}

int main()
{
	// Init data
	int S = 0;
	cout << "Enter grid size: "; cin >> S;
	int** table = new int*[S];
	cout << "Enter table:" << endl;
	for (int i = 0; i < S; i++) 
	{
		table[i] = new int[S];
		for (int j = 0; j < S; j++) 
			cin >> table[i][j];
		cout << endl;
	}

	int startX = 0, startY = 0, endX = 0, endY = 0;
	cout << "Enter start position by X:"; cin >> startX;
	cout << "Enter start position by Y:"; cin >> startY;
	cout << "Enter end position by X:"; cin >> endX;
	cout << "Enter end position by Y:"; cin >> endY;

	// if we in start cant find way from start pos or to end pos then return -1
	if (table[startX][startY == 1] || table[endX][endY] == 1)
		cout << "Count of moves = -1" << endl;
	else
			cout << "Count of moves = " << findMinMoves(startX, startY, endX, endY, table, S) << endl;

	for (int i = 0; i < S; i++)
		delete[] table[i];
	delete[] table;

	return 0;
}