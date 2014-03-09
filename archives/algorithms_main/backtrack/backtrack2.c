/*
 * backtracking ultimate pseudo code:
 *
 * bool solve(Node n){
 *  if n is a leaf node
 *      if n is a goal node
 *          return true
 *      else return false
 *  else
 *      for each child c of n
 *          try choice c
 *          if solve(c) succeeds
 *              return true;
 *          unmake choice c
 *
 *      return false;
 * }
 *
 *
 * sample problems
 * cindys puzzle
 * 8 queens
 * string permuation
 * subset
 * maze
 * sudozku
 * */


/* 8Queens psuedo code
 *
 * int grid[8][8];
 *
 * bool solveQueens(int cols){
 *  if(cols >= 8){
 *      return true;
 *  }
 *  else{
 *      for each rows i
 *          if(placeAllowed(i,cols))
     *          placeQueen(i,cols);
     *          if( solveQueen(col + 1)) return true;
     *          removeQueen(i,cols);
 *
 *      return false;
 *  }
 * }
 *
 *bool placeAllowed(int rows, int cols){
    if grid contains NA vals at grid[rows][cols] return false;
    else return true;
 }
 void placeQueen(int rows, int cols){
    mark grid with NA:
        grid[rows][cols] = NA;
        for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                if(inBounds(rows-i,cols)) grid[rows-i][cols] = NA;
                if(inBounds(rows-i,cols+j))grid[rows-i][cols+j] = NA;
                if(inBounds(rows+i,cols)) grid[rows+i][cols] = NA;
                if(inBounds(rows+i, cols-j))grid[rows+i][cols-j] = NA;
                if(inBounds(rows,cols-j))grid[rows][cols-j] = NA;
                if(inBounds(rows-i, cols-j))grid[rows-i][cols-j]= NA;
            }
        }
 }
 *
 * void removeQueen(int rows, int cols){
 *  grid[rows][cols] = 0;
        for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                if(inBounds(rows-i,cols)) grid[rows-i][cols] = NA;
                if(inBounds(rows-i,cols+j))grid[rows-i][cols+j] = NA;
                if(inBounds(rows+i,cols)) grid[rows+i][cols] = NA;
                if(inBounds(rows+i, cols-j))grid[rows+i][cols-j] = NA;
                if(inBounds(rows,cols-j))grid[rows][cols-j] = NA;
                if(inBounds(rows-i, cols-j))grid[rows-i][cols-j]= NA;
            }
        }
 *
 * }
 * */


