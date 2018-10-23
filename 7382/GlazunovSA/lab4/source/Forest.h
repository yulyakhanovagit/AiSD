#pragma once
#include "Bin_tree.cpp"
#include <vector>
template<typename H>
class Forest
{
public:
	Forest();
	~Forest();
	void GetForest();
	void SetForest();
	void CreateForest();
	void SeparationForestByBinTree();
	void ShowBinTrees();
	void PrintForest();
	void PrintElementsByWidth();
	int MaxHeight();
	bool IsCorrectForest();
	void ConvertFromForestToBin();
	Bin_tree<H>*BinLikeForest;
private:
	string forest_text;
	vector<string>  ArrayBinTree;
	vector< Bin_tree<H> > forest;
};


