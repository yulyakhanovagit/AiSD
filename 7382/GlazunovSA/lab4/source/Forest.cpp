#include "Forest.h"

template<typename H>
Forest<H>::Forest()
{
}

template<typename H>
Forest<H>::~Forest()
{
}
template<typename H>
void Forest<H>::GetForest()
{
	cout <<"Forest:"<< forest_text << endl;
}
template<typename H>
void Forest<H>::SetForest()
{
	cout << "Enter the forest:" << endl;
	getline(cin,forest_text);
}
template<typename H>
void Forest<H>::CreateForest()
{
	for (int i=0;i<ArrayBinTree.size();i++) 
	{
		forest.push_back(Bin_tree<H>((string)ArrayBinTree[i]));
	}
}

template<typename H>
void Forest<H>::SeparationForestByBinTree()
{
	string cur;
	int size = 0;
	for (int i=0;i<forest_text.size();i++)
	{
		if (i == forest_text.size() - 1 && forest_text[i] == ')')
		{
			cur.insert(cur.end(), forest_text[i]);
			ArrayBinTree.push_back(cur);
			break;
		}
		if(forest_text[i]=='('&&i!=0)
			if(forest_text[i-1]==')')
				{
				
				ArrayBinTree.push_back(cur);
				cur.clear();
				cur.insert(cur.end(), forest_text[i]);
				continue;
				}
		cur.insert(cur.end(),forest_text[i]);
	}
}

template<typename H>
void Forest<H>::ShowBinTrees()
{
	int i = 0, size = ArrayBinTree.size();
	while(i<size)
	{
		cout << ArrayBinTree.back() << endl;
		ArrayBinTree.pop_back();
		i++;
	}
}

template<typename H>
void Forest<H>::PrintForest()
{
	int i = 0, size = forest.size();
	while (i < size)
	{
		forest.back().print(forest.back().root,0);
		forest.pop_back();
		i++;
	}
}

template<typename H>
void Forest<H>::PrintElementsByWidth()
{
	int height = 1;
	int pad = 0;
	int count = MaxHeight();
	for (int i = 0;i < count;i++)
	{
		for (int j = 0;j < forest_text.size();j++)
		{
			if (forest_text[j] == '(')
			{
				pad++;
				continue;
			}
			if (forest_text[j] == ')')
			{
				pad--;
				continue;
			}
			if (pad == height)
			{
				cout << forest_text[j] << "  ";
			}

		}
		cout << endl;
		height++;
		pad=0;
	}
}

template<typename H>
int Forest<H>::MaxHeight()
{
	int height = 0,maxheight=0;
	for(int i=0;i<forest_text.size();i++)
	{
		if (forest_text[i] == '(')
			height++;
		if (forest_text[i] == ')')
			height--;
		if (height > maxheight)
			maxheight = height;
	}
	return maxheight;
}

template<typename H>
bool Forest<H>::IsCorrectForest()
{
	int brackets = 0;
	if (forest_text[0] != '(' ) {
		return false;
	}
	for (int i = 0;i < forest_text.size();i++)
	{
		if (brackets < 0)
		{
			cout << "NOT correct forest" << endl;
			return false;
		}
		if (forest_text[i] == '(')
		{
			if (i) 
			{
				if (forest_text[i-1]==')') 
				{
					if (brackets)
					{
						cout << "2";
						return false;
					}
				}
			}
			brackets++;
			continue;
		}
		if (forest_text[i] == ')')
		{
			brackets--;
			continue;
		}
	}
	if (brackets)
		return false;

	return true;;
}

template<typename H>
void Forest<H>::ConvertFromForestToBin()
{
	string newbin;
	for (int i = 0; i < forest_text.size();i++)
	{
		if (forest_text[i] == '('&&i)
			if (forest_text[i - 1] == ')')
			{
				newbin.erase(i-1, 1);
				continue;
			}
		newbin+=forest_text[i];
	}
	BinLikeForest=new Bin_tree<H>(newbin);
}

