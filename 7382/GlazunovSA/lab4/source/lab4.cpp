//#include "pch.h"
#include <iostream>
///#include "Bin_tree.cpp"
#include "Forest.cpp"

int main()
{
	Forest<char> f;
	f.SetForest();
	f.GetForest();
	if (!f.IsCorrectForest()) { cout << "wrong input" << endl;return 0; }
	f.SeparationForestByBinTree();
	f.CreateForest();
	f.ConvertFromForestToBin();
	cout << "Natural presentation of forest by bin. tree :" << endl;
	f.BinLikeForest->print(f.BinLikeForest->root,0);
	cout << "_____________________________________________________________" << endl;
	cout << "forest:" << endl;
	f.PrintForest();
	cout << "forest by width:" << endl;
	f.PrintElementsByWidth();
	return 0;
}
