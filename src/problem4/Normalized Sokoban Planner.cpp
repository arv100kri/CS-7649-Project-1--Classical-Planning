//============================================================================
// Name        : Normalized.cpp
// Author      : Stango
// Version     :
// Copyright   : GeorgiaTech
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

typedef		long long LL;
typedef		vector<LL> VLL;

vector <string> Graph, CleanGraph;
int				Row, Column, Boxes;
map <LL, int>	StateNo;
int				MaximumPower;
vector <VLL>	State;
vector <int>	opt;
LL				inital, target;
vector <int>	Lst;
int				targetrange;
bool			getAns;
int				res = -1, dimen;

void	ParseState(int sta[], LL s)
{
	for (int i = dimen - 1; i >= 0; i --)
	{
		sta[i] = s & ((1<<MaximumPower) - 1);
		//cout << sta[i] << endl;
		s >>= MaximumPower;
	}
}

int		getStateID(LL sta) //no match found return -1
{
	map<LL,int>::iterator it = StateNo.find(sta);
	if (it != StateNo.end()) return it->second;
	else return -1;
}

int		AddStateComponent (LL sta)
{
	int		IDD = getStateID(sta);
	if (getStateID(sta) != -1) return IDD;
	int		staid = -1;
	int		a[dimen];
	ParseState(a, sta);
    for (int i = 0; i < dimen; i ++) cout << a[i] << " ";
    cout << endl;

	vector <LL>		statecomponent;
	LL	boxsta = 0;
	vector <string>	G(CleanGraph);
	for (int i = 0; i < Boxes; i ++)
	{
		G[a[2 * i]][a[2 * i + 1]] = 'B';
		boxsta <<= MaximumPower;
		boxsta |= a[2 * i];
		boxsta <<= MaximumPower;
		boxsta |= a[2 * i + 1];
	}
	boxsta <<= (2 * MaximumPower);

	int	stx = a[dimen - 2], sty = a[dimen - 1];
	bool	reach[Row][Column];
	memset(reach, 0, sizeof(reach));
	reach[stx][sty] = true;
	vector <int>	L;
	L.push_back(stx); L.push_back(sty);
	for (int head = 0; head < L.size(); head += 2)
	{
		int	curx = L[head], cury = L[head + 1];
		int	ax, bx, ay, by;
		ax = (curx > 0)?curx - 1:curx;
		bx = (curx < Row - 1)?curx + 1:curx;
		ay = (cury > 0)?cury - 1:cury;
		by = (cury < Column - 1)?cury + 1:cury;
		if (G[ax][cury] == '*' && !reach[ax][cury])
		{
			L.push_back(ax); L.push_back(cury);
			reach[ax][cury] = true;
		}
		if (G[bx][cury] == '*' && !reach[bx][cury])
		{
			L.push_back(bx); L.push_back(cury);
			reach[bx][cury] = true;
		}
		if (G[curx][ay] == '*' && !reach[curx][ay])
		{
			L.push_back(curx); L.push_back(ay);
			reach[curx][ay] = true;
		}
		if (G[curx][by] == '*' && !reach[curx][by])
		{
			L.push_back(curx); L.push_back(by);
			reach[curx][by] = true;
		}
	}

	for (int i = 0; i < Row; i ++)
		for (int j = 0; j < Column; j ++)
			if (reach[i][j])
			{
				LL	tmp = boxsta;
				tmp |= ((i << MaximumPower) | j);
				statecomponent.push_back(tmp);
			}

	//Save new State
	State.push_back(statecomponent);
	opt.push_back(-1);
	int		id = State.size() - 1;
	for (int i = 0; i < statecomponent.size(); i ++)
		StateNo[statecomponent[i]] = id;

	return id;
}


void	init(char *input, char *output)
{
	freopen (input, "r", stdin);
	freopen (output, "w", stdout);

	cin >> Row >> Column >> Boxes;
    dimen = Boxes * 2 + 2;
	for (int i = 0; i < Row; i ++) {
		string	tmp;
		cin >> tmp;
		Graph.push_back(tmp);
	}

	// Count MaximunPower (for state the whole map)
	int		tmp = max(Row, Column), tmp2 = 1;
	MaximumPower = 1;
	for (; tmp2 < tmp; MaximumPower ++, tmp2 *= 2);
    //cout << MaximumPower << endl;

	// Get the inital state and target state

	inital = 0; target = 0;

	int	PersonX, PersonY;
	for (int i = 0; i < Row; i ++)
	{
		CleanGraph.push_back(Graph[i]);
		for (int j = 0; j < Column; j ++)
		{
			if (Graph[i][j] == 'B') {
				inital <<= MaximumPower;
				inital |= i;
				inital <<= MaximumPower;
				inital |= j;
				CleanGraph[i][j] = '*';
			}

			if (Graph[i][j] == 'D') {
				target <<= MaximumPower;
				target |= i;
				target <<= MaximumPower;
				target |= j;
				CleanGraph[i][j] = '*';
			}

			if (Graph[i][j] == 'M') {
				PersonX = i;
				PersonY = j;
				CleanGraph[i][j] = '*';
			}
		}
	}

	inital <<= MaximumPower;
	inital |= PersonX;
	inital <<= MaximumPower;
	inital |= PersonY;
	cout << "Inital" << endl;
	AddStateComponent(inital);
	opt[0] = 0;

	LL tmptar = target;

	for (int i = 0; i < Row; i ++)
		for (int j = 0; j < Column; j ++)
			if(Graph[i][j] != 'D' && Graph[i][j] != 'W') {
				target <<= MaximumPower;
				target |= i;
				target <<= MaximumPower;
				target |= j;
				cout << "Target" << endl;
				int		pp = AddStateComponent (target);
				target = tmptar;
			}

	targetrange = State.size();
}


void	bfs()
{
	cout << "Search Begin" << endl;
	getAns = false;
	res = -1;

	Lst.clear();
	Lst.push_back(0);

	for (int head = 0; head < Lst.size(); head ++)
	{
		int		curnode = Lst[head];
		cout << "Node : " << curnode << endl;
		int		sz = State[curnode].size();

		vector <string>	G(CleanGraph);
		int		a[dimen];
		ParseState(a, State[curnode][0]);
		for (int i = 0; i < Boxes; i ++) G[a[2 * i]][a[2 * i + 1]] = 'B';

		for (int i = 0; i < sz; i ++)
		{
			int		curstate = State[curnode][i];
			int		PersonX, PersonY;
			PersonY = curstate & ((1 << MaximumPower) - 1);
			curstate >>= MaximumPower;
			PersonX = curstate & ((1 << MaximumPower) - 1);
			curstate <<= MaximumPower;

			int		direc[4][2] = {{1, 0},{0, 1},{-1, 0},{0, -1}};
			for (int j = 0; j < 4; j ++)
				if (G[PersonX + direc[j][0]][PersonY + direc[j][1]] == 'B' &&
                    G[PersonX + 2 * direc[j][0]][PersonY + 2 * direc[j][1]] == '*')
				{
					G[PersonX + 2 * direc[j][0]][PersonY + 2 * direc[j][1]] = 'B';
					G[PersonX + direc[j][0]][PersonY + direc[j][1]] = 'M';
					G[PersonX][PersonY] = '*';
					LL	nextsta = 0;
					int		pp, qq;
					for (int lv1 = 0; lv1 < Row; lv1 ++)
						for (int lv2 = 0; lv2 < Column; lv2 ++)
                            if (G[lv1][lv2] == 'B')
                            {
                                nextsta <<= MaximumPower;
                                nextsta |= lv1;
                                nextsta <<= MaximumPower;
                                nextsta |= lv2;
                            } else if (G[lv1][lv2] == 'M') {
                                pp = lv1;
                                qq = lv2;
                            }
					nextsta <<= MaximumPower;
					nextsta |= pp;
					nextsta <<= MaximumPower;
					nextsta |= qq;
					cout << "Next Sta" << endl;
					int		nextid = getStateID(nextsta);
					if (nextid < targetrange && nextid > 0)
					{
						cout << "Accomplished: " << nextid << endl;
						opt[nextid] = opt[curnode] + 1;
						res = opt[nextid];
						getAns = true;
						return;
					}
					else if (nextid == -1)
					{
						int		newid = AddStateComponent(nextsta);
						cout << "New State ID: " << newid << endl;
						opt[newid] = opt[curnode] + 1;
						Lst.push_back(newid);
					}
					G[PersonX + 2 * direc[j][0]][PersonY + 2 * direc[j][1]] = '*';
					G[PersonX + direc[j][0]][PersonY + direc[j][1]] = 'B';
					G[PersonX][PersonY] = '*';
				}
		}
	}
}


int		main(int argc, char **argv)
{
	if (argc < 3) {
		cout<<"Usage: sokoban <input_file> <output_file>"<<endl;
		exit(1);
	}
	init (argv[1], argv[2]);
	bfs  ();
	cout << "ans : " << res << endl;
	return 0;
}
