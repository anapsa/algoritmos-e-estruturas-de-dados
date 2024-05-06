#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;
int found = 0;
void printTab(int rows, int width, vector<vector<char>> tab) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<width; j++) 
            cout << tab[i][j]; 
            
        cout << endl; 
    }
    cout << endl; 
}
bool findTreasure(pair<int, int> curr, pair<int, int> begin, pair<int, int> treasure, vector<vector<char>> &tab, int rows,
                  int width, int* life, vector<vector<int>> visited) {
  if (curr.first < 0 || curr.first >= width)
    return false;
  if (curr.second < 0 || curr.second >= rows)
    return false;
  if (tab[curr.first][curr.second] == '#')
    return false;
    if ((tab[curr.first][curr.second] == 'A' ||tab[curr.first][curr.second] == 'P') && found == 0)
        return false;
    if ((tab[curr.first][curr.second] == 'B') && found == 1)
        return false;
    
    if (tab[curr.first][curr.second] == 's')
     (*life)--;
    
    if (tab[curr.first][curr.second] == 'P' && found == 1) {
        (*life)--;
    }
    
    if ((*life) < 0)
        return false;
    //printar o tabuleiro para rastrear
    char aux = tab[curr.first][curr.second]; 
    tab[curr.first][curr.second] = 'C';
    //printTab(rows, width, tab); 
    tab[curr.first][curr.second] = aux;
    if (tab[curr.first][curr.second] == 'x')
        found = 1;
    if (tab[curr.first][curr.second] == '@' && found == 1)
        return true;
    // não teve vida suficiente pra voltar
    if(found == 0 && tab[curr.first][curr.second] != 's' && tab[curr.first][curr.second] != '@') tab[curr.first][curr.second] = 'A';
    if(found == 0 && tab[curr.first][curr.second] == 's') tab[curr.first][curr.second] = 'P'; 
    if(found == 1) tab[curr.first][curr.second] = 'B'; 
    int prX = 0, prY = 0; 
    if(curr.first < treasure.first && found == 0) {
        prX = 1;
    }
    if(curr.second < treasure.second && found == 0) {
        prY = 1;
    }
    if(curr.first < begin.first && found == 1) {
        prX = 1;
    }
    if(curr.second < begin.second && found == 1) {
        prY = 1;
    }
  
    visited[curr.first][curr.second] = 1; 
    int priority = 0; 
    if(found == 0 && prX == 0) {
        if(curr.first + 1 < rows) {
            if(tab[curr.first+1][curr.second] == 'x') {
                priority = 1; 
            }
        } 
    }
    if(found == 0 && prX == 1 || priority == 0) {
        if(curr.first - 1 >= 0) {
            if(tab[curr.first-1][curr.second] == 'x') {
                priority = 4; 
            }
        } 
    }
    if(found == 0 && prY == 0 || priority == 0) {
        if(curr.second + 1 < width) {
            if(tab[curr.first][curr.second+1] == 'x') {
                priority = 2; 
            }
        }
    }
    if(found == 0 && prY == 1) {
        if(curr.second - 1 >= 0) {
            if(tab[curr.first][curr.second-1] == 'x') {
                priority = 3;  
            }
        }
    } 
    if(priority == 0 && found == 0) {
        if(prX == 1) {
            if(curr.first + 1 < rows) {
                if(tab[curr.first+1][curr.second] == '.') {
                    priority = 1;  
                }
            } 
        }
        if(prY == 1) {
            if(curr.second + 1 < width) {
                if(tab[curr.first][curr.second+1] == '.') {
                    priority = 2;
                }
            }
        }
        if(prY==0 || priority == 0) {
            if(curr.second - 1 >= 0) {
                if(tab[curr.first][curr.second-1] == '.') {
                    priority = 3; 
                }
            }
        }
        if(prX == 0 || priority == 0){
            if(curr.first - 1 >= 0) {
                if(tab[curr.first-1][curr.second] == '.') {
                    priority = 4;  
                }
            } 
        }
    }   
    if(found == 1) {
        if(prX == 1) {
            if(curr.first + 1 < rows) {
                if(tab[curr.first+1][curr.second] == '.' || tab[curr.first+1][curr.second] == 'A') {
                    priority = 1; 
                }
            } 
        }
        if(prY == 1) {
           
            if(curr.second + 1 < width) {
                if(tab[curr.first][curr.second+1] == '.' || tab[curr.first][curr.second+1] == 'A') {
                    priority = 2; 
                }
            }
        }
        if(prY == 0 || priority == 0) {
            if(curr.second - 1 >= 0) {
                if(tab[curr.first][curr.second-1] == '.' || tab[curr.first][curr.second-1] == 'A') {
                    priority = 3; 
                }
            }
        }
        if(prX == 0 || priority == 0) {
            if(curr.first - 1 >= 0) {
                if(tab[curr.first-1][curr.second] == '.' || tab[curr.first-1][curr.second] == 'A') {
                    priority = 4;  
                }
            }
        }
    }
    if(found == 1) {
        if(curr.first + 1 < rows) {
            if(tab[curr.first+1][curr.second] == '@') {
                priority = 1; 
            }
        } 
        
        if(curr.second + 1 < width) {
            if(tab[curr.first][curr.second+1] == '@') {
                priority = 2; 
            }
        }
        if(curr.second - 1 >= 0) {
            if(tab[curr.first][curr.second-1] == '@') {
                priority = 3;  
            }
        }
        if(curr.first - 1 >= 0) {
            if(tab[curr.first-1][curr.second] == '@') {
                priority = 4; 
            }
        } 
    } 
   
    if(priority == 0 || priority == 1) {
        if (findTreasure(make_pair(curr.first + 1, curr.second), begin, treasure, tab, rows, width,
                         life, visited) == true && (*life) >= 0) {
          return true;
        }
    }
    if(priority == 0 || priority == 2) {
        if (findTreasure(make_pair(curr.first, curr.second+1), begin, treasure, tab, rows, width,
                         life, visited) == true && (*life) >= 0) {
          return true;
        }
    }
    if(priority == 0 || priority == 4) {
        if (findTreasure(make_pair(curr.first-1, curr.second), begin, treasure, tab, rows, width,
                         life, visited) == true && (*life) >= 0) {
          return true;
        }
    }
    if(priority == 0 || priority == 3) {
        if (findTreasure(make_pair(curr.first, curr.second - 1), begin, treasure, tab, rows, width,
                         life, visited) == true && (*life) >= 0) {
          return true;
        }
    }
    
  return false;
}

int main() {
  int rows, width, life;
  cin >> rows >> width >> life;
  int *aux;
  aux = (int *) malloc(sizeof(int));
  (*aux) = life; 
  pair<int, int> treasure, begin;
  vector<vector<char>> tab(rows, vector<char>(width, 0));
  vector<vector<int>> visited(rows, vector<int>(width, 0));

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < width; j++) {
      cin >> tab[i][j];

      if (tab[i][j] == '@') {
        begin.first = i;
        begin.second = j;
      }
      if (tab[i][j] == 'x') {
        treasure.first = i;
        treasure.second = j;
      }
    }
  }
  bool ans;
  ans = findTreasure(begin, begin, treasure, tab, rows, width, aux, visited);
    //cout << (*aux); 
  if (ans) {
    cout << "SUCCESS";
  } else
    cout << "IMPOSSIBLE";
    free(aux); 

  return 0;
}
