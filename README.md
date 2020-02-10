#### In this Lab assignment, you will implement an instruction-level simulator for a single cycle MIPS processor in C++ step by step. The simulator supports a subset of the MIPS instruction set and can model the execution of each instruction.
Your processor must deal with two types of hazards.
1. RAW Hazards: RAW hazards are dealt with using either only forwarding (if possible) or,
if not, using stalling + forwarding. You must follow the mechanisms described in Lecture
to deal RAW hazards.
2. Control Flow Hazards: You will assume that branch conditions are resolved in the
ID/RF stage of the pipeline. Your processor deals with beq instructions as follows:
a. Branches are always assumed to be NOT TAKEN. That is, when a beq is fetched
in the IF stage, the PC is speculatively updated as PC+4.
b. Branch conditions are resolved in the ID/RF stage. To make your life easier,
will ensure that every beq instruction has no RAW dependency with its
previous two instructions. In other words, you do NOT have to deal with
RAW hazards for branches!
c. Two operations are performed in the ID/RF stage: (i) Read_data1 and
Read_data2 are compared to determine the branch outcome; (ii) the effective
branch address is computed.
d. If the branch is NOT TAKEN, execution proceeds normally. However, if the
branch is TAKEN, the speculatively fetched instruction from PC+4 is quashed in
its ID/RF stage using the nop bit and the next instruction is fetched from the
effective branch address. Execution now proceeds normally.

#### 
