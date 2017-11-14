# code_sample

Word Puzzle Problem

The goal of this code is to find all words within a grid of letters, in any direction. 

Program Details:
    Input grids: First line of the input grid file is the number of rows, and the second line of the input grid 
    is the number of columns. The third line is the grid data, with no spaces. All input grids are stored in the 
    data directory. 
    
    Dictionary files (data/words.txt, data/words2.txt): The dictionary file contains one word per line. Words 
    from the dictionary file are stored in a hash table via wordPuzzle.cpp. All dictionary files are stored in
    the data directory (words.txt, words2.txt)
    
    Timing: Timer routines allow to show how long is takes to find all valid words in a grid, after the hash 
    table is built initially. 
    
    Valid words: Program only reports words with three or more letters, and words are case sensitive. 
    
    Duplicates: If a word occurs more than once in a grid, then each instance is treated as a separate word. 
    

Execution: 
    After running makefile, a single exection is done as follows: 
        ./a.out <dictionary_file> <grid_file>
        
        An example execution would be: 
            ./a.out data/words2.txt data/300x300.grid.txt
            
    There is also a shell script which calculates the average time for 5 runs on a certain dictionary and grid. This can be executed by: 
        ./averagetime.sh
    And then entering the dictionary file and grid file (such as data/words2.txt and data/300x300.grid.txt). 
    The time output of the shell script is in milliseconds. 
    
    
Some of the optimizations that I implemented are described in optimizations.txt.
