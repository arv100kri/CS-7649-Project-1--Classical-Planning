import sys
N = 3 #By default
if len(sys.argv) == 2:
    if int(sys.argv[1]) <= 0:
        print "N must be greater than 1"
        exit(-1)
    else:
        N = int(sys.argv[1])
else:
    print "Usage: 'python getHanoidNPDDL.py <N>"

# Define
statement = "(define (problem hanoi-{0})\n".format(N)

# Use existing hanoi-domain.pddl
statement += "  (:domain hanoi-domain)\n"

# Initialize the objects being used in the domain
# There are always only 3 poles...Disks will be from D1...DN
disks = ""
for i in range(1,N+1):
    disks += "d%i "%i
statement += "  (:objects p1 p2 p3 %s)\n" % disks

# Initial state
initial_state = ""
for i in range(1,N+1):
    initial_state += "    (smaller d{0} p1)(smaller d{0} p2)(smaller d{0} p3)\n".format(i)

initial_state += "\n"
for i in range(1,N+1):
    initial_state += "    "
    for j in range(i+1,N+1):
        initial_state += "(smaller d%i d%i)" % (i,j)
    initial_state += "\n"

# The two other poles and smallest disk is clear
initial_state += "    (clear p1)(clear p2)(clear d1)\n    "
# All the disks
for i in range(1,N+1):
    initial_state += "(disk d%i)"%i
initial_state += "\n    "

# Smaller disk is on the larger disk
for i in range(1,N):
    initial_state += "(on d%i d%i)" % (i,i+1)

# Largest disk is on the pole
initial_state += "(on d%i p3)\n" % N

statement += "  (:init \n%s  )\n" % initial_state

# Goal
goal = ""
for i in range(1,N):
    goal += "(on d%i d%i)" % (i,i+1)
goal += "(on d%i p1)" % N

statement += "  (:goal \n    (and %s )\n  )" % goal
statement += "\n)"

# Write output
file_name = 'hanoi-{0}.pddl'.format(N)
f = open(file_name, 'w')
f.write(statement);
f.close();
