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
#include <sstream>

using namespace std;

typedef		long long LL;
typedef		vector<LL> VLL;

vector <string> Graph, CleanGraph;
int				Row, Column, Boxes;
map <LL, int>	StateNo;
int				MaximumPower;
vector <VLL>	State;
vector <int>	opt;
vector <LL>	previousState;
LL				inital, target;
vector <int>	Lst;
int				targetrange, AnsID;
bool			getAns;
int				res = -1, dimen, manres= -1;
stringstream	ss;
vector <string>	routine;

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

	/*if (sta == 140800827524) {
    for (int i = 0; i < dimen; i ++) cout << a[i] << " ";
    cout << endl;
	}*/

	vector <LL>		statecomponent;
	LL	boxsta = 0;
	vector <string>	G(CleanGraph);
	for (int i = 0; i < Boxes; i ++)
	{
		G[a[2 * i]][a[2 * i + 1]] = 'B';
		//if (sta == 140800827524) cout << a[2 * i] << " " << a[2 * i + 1] << endl;
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
				/*
				if (sta == 140800827524)
					{
						ParseState(a, tmp); for (int i = 0; i < dimen; i ++) cout << a[i] << " ";
					    cout << endl;
					}
				*/
			}

	//Save new State
	State.push_back(statecomponent);
	opt.push_back(-1);
	previousState.push_back(-1);
	int		id = State.size() - 1;
	for (int i = 0; i < statecomponent.size(); i ++)
		StateNo[statecomponent[i]] = id;

	return id;
}


void init(char *input, char *output)
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
	//cout << "Inital" << endl;
	AddStateComponent(inital);
	opt[0] = 0;
	previousState[0] = 0;

	LL tmptar = target;

	for (int i = 0; i < Row; i ++)
		for (int j = 0; j < Column; j ++)
			if(Graph[i][j] != 'D' && Graph[i][j] != 'W') {
				target <<= MaximumPower;
				target |= i;
				target <<= MaximumPower;
				target |= j;
				//cout << "Target" << endl;
				int		pp = AddStateComponent (target);
				target = tmptar;
			}

	targetrange = State.size();
}


void	bfs()
{
	//cout << "Search Begin" << endl;
	getAns = false;
	res = -1;

	Lst.clear();
	Lst.push_back(0);

	for (int head = 0; head < Lst.size(); head ++)
	{
		int		curnode = Lst[head];
		//cout << "Node : " << curnode << endl;
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



					//cout << "Next Sta" << endl;
					int		nextid = getStateID(nextsta);
					if (nextid < targetrange && nextid > 0)
					{
						//cout << "Accomplished: " << nextid << endl;
						opt[nextid] = opt[curnode] + 1;
						previousState[nextid] = curnode;
						res = opt[nextid];
						AnsID = nextid;
						getAns = true;
						return;
					}
					else if (nextid == -1)
					{
						//cout << PersonX << " " << PersonY << " " << curnode << endl;
						int		newid = AddStateComponent(nextsta);
						if (newid == 4)
						{
							ParseState(a, nextsta);
							//for (int i = 0; i < dimen; i ++) cout << a[i] << " ";
							//cout << endl;
							//cout << "---" << nextsta << endl;
						}
						previousState[previousState.size() - 1] = curnode;
						//cout << "New State ID: " << newid << endl;
						opt[newid] = opt[curnode] + 1;
						//if (newid == 342) cout << Lst.
						Lst.push_back(newid);

					}
					G[PersonX + 2 * direc[j][0]][PersonY + 2 * direc[j][1]] = '*';
					G[PersonX + direc[j][0]][PersonY + direc[j][1]] = 'B';
					G[PersonX][PersonY] = '*';
				}
		}
	}
}

void	printState(int ID, int& step)
{
	if (ID == 0) {
		//ss << step << endl;
		step ++;
		for (int i = 0; i < Row; i ++) {
			//ss << Graph[i] << endl;
			routine.push_back(Graph[i]);
		}

		return;
	}
	//cout << ID << " " << previousState[ID] << endl;
	printState(previousState[ID], step);
	//ss << step << endl;
	int		curnode = ID;
	LL		curstate = State[ID][0];
	vector <string>	G(CleanGraph);
	int		a[dimen];
	ParseState(a, curstate);
	for (int i = 0; i < Boxes; i ++)
		G[a[2 * i]][a[2 * i + 1]] = 'B';
	for (int i = 0; i < Row; i ++) routine.push_back(G[i]);;
	step ++;
	return;
}


void	printAns()
{
	if (!getAns) { cout << "No Solution!" << endl; return; }
	//cout << "Total Step : " << res << endl;
	int		sp = 0;
	printState(AnsID, sp);
}

void	ManMovementPrint()
{
	//for (int i = 0; i < routine.size(); i ++) cout << routine[i] << endl;
	int		curstep = 0, totstep = 0;
	int		perx, pery;
	vector <string>	G(Row), G2(Row);
	for (int i = 0; i < Row; i ++) G[i] = routine[curstep * Row + i];

	cout << "Step: 0" << endl;
	for (int i = 0; i < Row; i ++) cout << G[i] << endl;

	for (int i = 0; i < Row; i ++)
		for (int j = 0; j < Column; j ++)
			if (G[i][j] == 'M')
			{
				perx = i;
				pery = j;
				G[i][j] = '*';
				break;
			}
	//cout << "Yes" << endl;
	//for (int i = 0; i < Row; i ++) cout << G[i] << endl;

	for (curstep = 1; curstep <= res; curstep ++)
	{
		int		manx, many, nowx, nowy;
		for (int i = 0; i < Row; i ++) G2[i] = routine[Row * curstep + i];
		for (int i = 0; i < Row; i ++)
			for (int j = 0; j < Column; j ++)
			{
				if (G[i][j] == 'B' && G2[i][j] != 'B')
				{
					manx = i;
					many = j;
				}
				if (G2[i][j] == 'B' && G[i][j] != 'B')
				{
					nowx = i;
					nowy = j;
				}
			}
		int		direx, direy;
		direx = nowx - manx;
		direy = nowy - many;
		int		fx = manx - direx;
		int		fy = many - direy;

		int		reach[Row][Column];
		for (int i = 0; i < Row; i ++)
			for (int j = 0; j < Column; j ++)
				reach[i][j] = -1;

		reach[perx][pery] = 0;
		vector <int>	L;
		L.push_back(perx); L.push_back(pery);
		int		DOWN = 1, UP = 2, LEFT = 3, RIGHT = 4;
		for (int head = 0; head < L.size(); head += 2)
		{
			int	curx = L[head], cury = L[head + 1];
			int	ax, bx, ay, by;
			ax = (curx > 0)?curx - 1:curx;
			bx = (curx < Row - 1)?curx + 1:curx;
			ay = (cury > 0)?cury - 1:cury;
			by = (cury < Column - 1)?cury + 1:cury;
			if (G[ax][cury] == '*' && reach[ax][cury] == -1)
			{
				L.push_back(ax); L.push_back(cury);
				reach[ax][cury] = DOWN;
			}
			if (G[bx][cury] == '*' && reach[bx][cury] == -1)
			{
				L.push_back(bx); L.push_back(cury);
				reach[bx][cury] = UP;
			}
			if (G[curx][ay] == '*' && reach[curx][ay] == -1)
			{
				L.push_back(curx); L.push_back(ay);
				reach[curx][ay] = LEFT;
			}
			if (G[curx][by] == '*' && reach[curx][by] == -1)
			{
				L.push_back(curx); L.push_back(by);
				reach[curx][by] = RIGHT;
			}
		}

		L.clear();
		L.push_back(fx); L.push_back(fy);
		for (int head = 0; head < L.size(); head += 2)
		{
			int		curx = L[head], cury = L[head + 1];
			int		direc = reach[curx][cury];
			//cout << curx << " " << cury << " " << direc << endl;
			if (direc == 0) break;
			else if (direc == DOWN) {
				L.push_back(curx + 1); L.push_back(cury);
			}
			else if (direc == UP) {
				L.push_back(curx - 1); L.push_back(cury);
			} else
			if (direc == LEFT) {
							L.push_back(curx); L.push_back(cury + 1);
						} else
							if (direc == RIGHT) {
											L.push_back(curx); L.push_back(cury - 1);
										}
		}

		for (int tail = L.size() - 4; tail >= 0; tail -= 2)
		{
			int		curx = L[tail], cury = L[tail + 1];
			G[curx][cury] = 'M';
			cout << "Step: " << ++ totstep << endl;
			for (int i = 0; i < Row; i ++) cout << G[i] << endl;
			G[curx][cury] = '*';
		}

		G[manx][many] = 'M';
		G[nowx][nowy] = 'B';
		cout << "Step: " << ++ totstep << endl;
		for (int i = 0; i < Row; i ++) cout << G[i] << endl;
		G[manx][many] = '*';
		perx = manx; pery = many;
	}

	manres = totstep;
}

int	main(int argc, char **argv)
{
	if (argc < 3) {
		cout<<"Usage: sokoban <input_file> <output_file>"<<endl;
		exit(1);
	}
	init(argv[1], argv[2]);
	bfs  ();

	cout << "The number of states explored: " << State.size() << endl;
	cout << "The number of box movements: " << res << endl;

	cout << "-------------------------------" << endl;
	//cout << "ans : " << res << endl;
	ss.clear();
	routine.clear();
	printAns();
	//cout << "Yes" << endl;

	ManMovementPrint();
	cout << "-------------------------------" << endl;
	cout << "The number of man movements: " << manres << endl;

	return 0;
}
