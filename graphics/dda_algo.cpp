#include<iostream>
#include<cmath>
using namespace std;

void drawLine(int x1, int y1, int x2, int y2){
  float dx = (float)(x2-x1);
  float dy = (float)(y2-y1);
  float steps = (fabs(dx) >= fabs(dy)) ? fabs(dx) : fabs(dy);

  dx = dx / steps;
  dy = dy / steps;

  float x = (float)x1;
  float y = (float)y1;

  char grid[50][50] = {0};

  for(int i = 0; i <= steps; i++){
    int px = (int)(x+0.5);
    int py = (int)(y+0.5);

    if(px >= 0 && px < 50 && py >= 0 && py < 50){
      grid[py][px] = '*';
    }
    x += dx;
    y += dy;
  }

  for(int i = 0; i < 50; i++){
    for(int j = 0; j < 50; j++){
      cout<< grid[i][j]<<" ";
    }
    cout<<endl;
  }
}

int main(){
  int x1 = 2, y1 = 4, x2 = 8, y2 = 10;
  drawLine(x1, y1, x2, y2);
  return 0;
}