RIP_7649_Project1
=================

Classical Planning Assignment - 1
==================================

1. Luis Gustavo Souza Silva (luisgustavo.silva@gatech.edu)
2. Arvind Krishnaa Jagannathan (arvind.krishnaa@gatech.edu)
3. Zhengyi (Stango) Hu	(zhengyihu@gatech.edu)
4. Zheng (James) Yong (zyong6@gatech.edu)

Directory Structure
===================
1. The top level directory contains the files for the Report.
	* Tex files containing the write-up of the Project.
	* _images_ is the folder which contains any image we used in the report.
2. All source code and plans generated is in the __src__ folder
	* Solutions to each problem is present in their respective directories
	* _problem2_ : Binaries and PDDL representation of the 3 disk Towers of Hanoi problem
	* _problem3_ : Binaries and PDDL representation of the 4 Sokoban problems
	* _problem4_ : Our implementation of the planner
		* "Normalized Sokoban Planner.cpp" - C++ implementation of a planner using BFS
		* "sokoban" - The executable from the C++ file
		* .in files - Input map file for each of the Sokoban problems
		* .out files - Plan maps for each of the Sokoban problems
	* _problem5_ : Binaries and PDDL representation of 6, 10 disk Towers of Hanoi problem
		* "getHanoiNPDDL.py" - A python script to generate PDDL representation for the general N-disk Towers of Hanoi problem
	* _resources_ : Plans generated by the various planners
		* "Hanoi Plans"
			* Plans generated by FF and Blackbox for the 3 disk Towers of Hanoi Problem
			* Plans generated by FF for 6, 10 disk Towers of Hanoi Problem
		* "Sokoban Plans" : Plans generated by FF for the Part-I Sokoban Problem
		* "Our_Planner_Solutions" : Plans generated by our planner for the Part-II Sokoban Problem

Running the program
====================
```cd``` into the corresponding directory and follow these instructions:

1. To run the planners for 3-disk Towers of Hanoi problem (__problem2__)
	* Blackbox: ```././blackbox -o hanoi-domain.pddl -f hanoi-3.pddl```
	* FF: ```./ff -o hanoi-domain.pddl -f hanoi-3.pddl```
2. To run the planners for 6, 10-disk Towers of Hanoi problem (__problem5__)
	* FF: 
		```./ff -o hanoi-domain.pddl -f hanoi-6.pddl```
		```./ff -o hanoi-domain.pddl -f hanoi-10.pddl```
	* Blackbox: Does not produce output for these
3. To run the planners for the Sokoban planner (__problem3__)
	* FF:
		```./ff -o sokobanDomain.pddl -f prob2-1.pddl```
		```./ff -o sokobanDomain.pddl -f prob2-2.pddl```
		```./ff -o sokobanDomain.pddl -f prob2-3.pddl```
		```./ff -o sokobanDomain.pddl -f sokobanChallenge.pddl```
4. To run our planner (__problem4__), there are two steps:
	* Compile the C++ file 
		* ```g++ "Normalized Sokoban Planner.cpp" -o sokoban```
	* Run the executable with an input map, specifying the output file where the plan needs to be written
		* ```./sokoban sokoban-2-1.in sokoban-2-1.out```


Participation
=============

**Luis Gustavo Souza Silva**

1. Created the PDDL for sokoban domain definition and for the problems and answers related to Project Part-I Sokoban Planner. 
2. Also, settled up the enviroment to run Blackbox and FF's planner on Windows machines.
	* All planners are tested to be working on my box

**Zhengyi Hu**:
Problem 4: Project Part-II Sokoban Plannner

1. State space compression
2. Develop a efficiently HASH function
3. Implement the algorithm

**Zheng Yong**:
Problem 4: Project Part-II Sokoban Planner

1. Branch optimization
2. Implement the algorithm
3. Answer to 4.3 - 4.4 problem.

**Arvind Krishnaa Jagannathan**:

1. Problem 2: Towers of Hanoi (3 disks) - Defined domain and PDDL for initial state and goal state
2. Problem 5: Towers of Hanoi (N disks) - Defined the states for the problem with 6 and 10 disks.
	* Wrote a python script to generate the PDDL for a N disk towers of hanoi problem
3. Problem 4: Project PartII Sokoban Planner
	* Domain description for the 4 problems
	* Answer to 4.1 - 4.2 problem
4. Miscellaneous
	* Setup Blackbox and FF on Linux box
	* Performed analysis of the computation metrics (time, space etc.,) wherever required.
	* All planners are tested to be working on my box

Useful Links
=============
1. [Blackbox Download Site](http://www.cs.rochester.edu/~kautz/satplan/blackbox/blackbox-download.html)
2. [FF Download Site](http://fai.cs.uni-saarland.de/hoffmann/ff/FF-v2.3.tgz) 
