#include "matrix.cpp"         // inkludera din headerfil h�r

struct start_pos{
  int row;
  int col;
};
Matrix solve(Matrix & m,const char ** maze);
Matrix solve(const char ** maze);
bool help_solve(Matrix & m,int row, int col, int start_r, int start_c) ;
start_pos find(Matrix & m);
  
static bool goal = false;
int main()
{
    const char *small[] =
	{"#####################",
	 "      # # #   # # # #",
	 "##### #     # #   # #",
	 "#     ##### # # #   #",
	 "### # #   # #   # # #",
	 "# # # # # # ####### #",
	 "#   #   #   #       #",
	 "## ############ #####",
	 "#   #                ",
	 "#####################",
	 0};
    
    const char *medium[] =
	{"# #######################################",
	 "# #                   #     #   #     # #",
	 "# # ### ############# # # ### # # ### # #",
	 "# #   #     #   #   #   #     # #   # # #",
	 "# ### # ### # # # # ##### ####### # # # #",
	 "#   # # # #   #   #     #   #   # # # # #",
	 "### # # # # ########### ##### # ### # # #",
	 "#   # #   #   # #             # #   # # #",
	 "# # # ####### # # ############# # ### # #",
	 "# # #     #   # #             # #   # # #",
	 "# ### ### # ### ############# # ### # # #",
	 "#   #   # #   #   #     #   # # #   # # #",
	 "### ##### ### ### # # ### # # # # ### # #",
	 "#   #     # # #     #     # # # # # #   #",
	 "# ### ##### # # ############# # # # # ###",
	 "#     #     # #               # # # #   #",
	 "####### ##### ################### # # ###",
	 "#         #   #     #             # #   #",
	 "# ####### # ### # # # ############# ### #",
	 "#       #       # #               #     #",
	 "####################################### #",
	 0};

    const char *large[] =
	{"# ###############################################################################",
	 "# #         # #     #       #         #       #   #     #     #   #             #",
	 "# ### ##### # # ### # ##### # ##### # # ### ### # # ### ##### # # # # ##### #####",
	 "#   # #   # # # # #   #     # #   # #   # #   # # # # #     # # #   # #   # #   #",
	 "# # # # # # # # # ### # ##### # # # ##### # # # # # # # ### # # ##### # # ### # #",
	 "# #   # #     # # #   #     #   # # #   #   #   # # # # # #   #     #   # #   # #",
	 "####### ####### # # ### ######### ### ####### ### # # # # # # ##### ##### # ### #",
	 "#   #   #     # # # # #         #   #   #     #   # #   #   #   # #     #   #   #",
	 "# # # ### ### # # # # # ####### ### ### # # ### ##### ######### # # ### ##### ###",
	 "# #   #   # #   #   # # #     #   # #   # #   #     # #   #   #   # # # #   #   #",
	 "# ##### ### # ####### # ##### # # # # ### ######### # ### # # ##### # # # # # ###",
	 "#     #     #   #     #     # # #   #     #   #   # #   # # #       # # # # #   #",
	 "# ##### # ##### # ######### # ####### ##### # ### # # # # # ######### # ### # # #",
	 "#   #   # #   #     #     #   #     #     # #   # # # #   #   #       #     # # #",
	 "### # ### # ####### # ### ##### ### ##### # ### # # # ######### # ########### # #",
	 "#   # # #       # #   #       #   #     # # # #     # #         #   #     #   # #",
	 "# ### # ####### # ##### ######### ##### ### # # ##### # ######### # # ##### # # #",
	 "# #   #   #     #       #   #     #   #     # # #   # # #     #   # #   #   # # #",
	 "# # ##### # ############# ### ### # # ####### # # # # # ### # # ### ### # ##### #",
	 "#   #   # #             #   #   # # # #   #   #   # # # #   # #   # #   # #   # #",
	 "##### # # ######### ### ### ### ### # # # # ####### # # # ##### # # # ### # # # #",
	 "#   # #           #   #   #   #     #   # #   #       # # #     # # #   # # #   #",
	 "# ### ########### ### # ### ### ######### # # ######### # # ##### ### # # # #####",
	 "# #   #     #   # #   #   #   # #     #   # #   #     # #   # #   #   # # # #   #",
	 "# # ### ### # # # # ##### ### # # ### # ####### # # # # ##### # ### # # # # # ###",
	 "# # #     #   #   # #   #     # # #   #         # # # #       #   # # # # #     #",
	 "# # # ### ########### # # ##### # ######### ##### # ### ######### # ### # ##### #",
	 "#   #   # #       #   #   #     #         #       #     #   #     #   # # #     #",
	 "####### # # ##### # ##################### ########### ### # # ####### # # # #####",
	 "#     # # # #   #   #     #     #   #   # #     #   # #   # # #       # # #     #",
	 "# ### # ### # ####### # # # ### ### # # # # # # # # # # ##### # # ####### #######",
	 "# # #       # #       # #   #   #   # # #   # # # # # # #     # #   # #   #     #",
	 "# # # ####### # ####### ##### ### ### # ##### # # # ### # ### # # # # # ### ### #",
	 "#   # #     # #       # #   #   #     #   # # #   #     #   #   # #   #     # # #",
	 "##### # ### # ####### ### # # ########### # # # ### ####### ####### ######### # #",
	 "#   #     #         #   # # #       #   # # # # # #   #     #     #   #   #   # #",
	 "# ### # ########### ### # # ####### # # # # # # # # # # ##### ### ### # # # ### #",
	 "# #   # #   #   #     #   #       #   #     # # # # #   #     #   # # # #     # #",
	 "# # ##### ### # ########### ############# ### # # ####### ##### ### # ### # # # #",
	 "# #     #   # #     #   #   #     #     #   # # #       # #     #   #     # #   #",
	 "# ### # ### # ##### # # # ### ### # ### ##### # # ##### # # ##### ######### #####",
	 "#   # #   # # #     # #   #   #   #   #       # #     #   #   #   #   #     #   #",
	 "### ##### # # ####### # ### ### ##### ########### ### ####### # ### # ####### # #",
	 "#     #   # #       # #   # #   #   #           # #   #       #   # #       # # #",
	 "### # # ### ####### # ### # # ### # ########### ### ####### ### # # ####### # # #",
	 "#   # # #   #   #   #   #   #   # #   #             #     #   # # #   #   # # # #",
	 "# ##### # # # # # ##### # ##### ### # ############### ### ##### # ### # # # ### #",
	 "#         # # # # #     # #   # #   #         #     #   #       # #   # # #   # #",
	 "# ##### ### # # # # ####### # # # ##### ##### # ##### # ######### # ### # ### # #",
	 "# #   #   #   # # #     #   # # # #   # # #   #   #   # # #   #   # #   #   #   #",
	 "# # # ######### # ##### # ### # # # # # # # # ### # # # # # ### # ### ##### # ###",
	 "# # #   #     # #     # #   # #     # #   # #     # # # # #   # #   #     #     #",
	 "### # # # ### # ##### # # # ######### ##### ####### # # # ### # ### ########### #",
	 "#   # #   #   #   #   # # #         # #   #   # #   # #   # #   #       #   #   #",
	 "# ##### ####### # # ### # ######### # # # ### # # ####### # # ### ####### # # ###",
	 "# #   # #     # # #   # #   #   # # # # #   #   # #     # # #   #         # #   #",
	 "# # # # # ### # ### # # ### # # # # # # # ### ### # ##### # # # ########### ### #",
	 "#   # #   # #   #   # # # # # #   #   # # #   #   #     #   # #   #   #   #     #",
	 "##### ##### # ### ### # # # # # ####### # # ### ####### ##### ### # # # #########",
	 "#           #       #     #   #         # #           #         #   #           #",
	 "############################################################################### #",
	 0};

    // anv�nd matrisklassen f�r att l�sa matriserna ovan!
  
    solve(small);
    solve(medium);
    solve(large);
    return 0; 
}

start_pos find(Matrix & m){
  start_pos p;
  for(size_t i=0 ; i < m.cols; ++i){
    if(m[0][i]==' '){
      p.row=0;
      p.col=i;
      return p; 
    }
  }
  for(size_t i=0 ; i < m.cols; ++i){
    if(m[m.rows-1][i]==' '){
      p.row=m.rows-1;
      p.col=i;
      return p; 
    }
  }
  
  for(size_t i=1 ; i < m.rows-1; ++i){
    if(m[i][0]==' '){
      p.row=i;
      p.col=0;
      return p; 
    }
  }

  for(size_t i=1 ; i < m.rows-1; ++i){
    if(m[i][m.rows-1]==' '){
      p.row=i;
      p.col=m.cols-1;
      return p; 
    }
  }

  
}


Matrix solve(const char ** maze){
  goal = false;
  const char * tmp = *maze;
  int cols(0);
  while(*tmp!='\0'){
    ++cols;
    ++tmp;
  }
  
  const char ** tmp2 = maze; 
  int rows(0);    
  while(*tmp2 != 0){
    ++tmp2;
    ++rows;
  }
  
  Matrix m(rows,cols);
  
  for(size_t i=0;i<m.rows;++i){
    for(size_t j=0;j<m.cols;++j){
      m[i][j]=maze[i][j];
    }
  }
  
  
  //get start
  /*
   int start_row;
   int start_col;
  for(size_t i=0;i<m.rows;++i){
    if(m[i][0] == ' '){
      m[i][0] = 'S';
      break;
    }else if(m[i][m.cols-1] == ' '){
      m[i][(m.cols-1)] = 'S';
      break;
    }
  }
  */
  
  start_pos x = find(m);
  
  help_solve(m,x.row,x.col,x.row,x.col);
  
  char temp[m.rows][m.cols]; 
  for(size_t i=0;i<m.rows;++i){
    for(size_t j=0;j<m.cols;++j){
      temp[i][j]=m[i][j];
      std::cout << temp[i][j];   
    }
    std::cout <<  std::endl;      
  }
  
  return m;
}

bool help_solve(Matrix & m, int row, int col, int start_r, int start_c){
  if((row == 0 ||
      row == m.rows-1 ||
      col == 0 ||
      col == m.cols-1) && 
     col!= start_c && 
     row!=start_r){
    m[row][col] = 'G';
    goal = true;
    return true;
    
  }else{
  
  if((row-1 > 0)&&
     (m[row-1][col] == ' ') && !goal){
    m[row-1][col] = '.';
    help_solve(m,row-1,col,start_r,start_c);
    if(!goal){
      m[row-1][col] = ' ';
    }
  }
  if(((row+1)<m.rows)&&
     (m[row+1][col] == ' ') && !goal){
    m[row+1][col] = '.';
    help_solve(m,row+1,col,start_r,start_c);
    if(!goal){
      m[row+1][col] = ' ';  
    }
  }
  if((col-1 > 0)&&
     (m[row][col-1] == ' ')&& !goal){
    m[row][col-1] = '.';
    help_solve(m,row,col-1,start_r,start_c);
    if(!goal){
      m[row][col-1]=' ';
    }
  }
  
  if((col+1 < m.cols)&&
     (m[row][col+1] == ' ') && !goal){
    m[row][col+1] = '.';
    help_solve(m,row,col+1,start_r,start_c);
    if(!goal){
      m[row][col+1]=' ';
    }
  }
  }
  return false;
}



