#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct{
    char scacchiera[8][8][4];}configurazioni;//scacchiera[x][y][3] è variabile nascosta che identifica pedina
//inizializzazione funzioni

int verifica_inchiodatura_assolutabianco (char scacchiera[8][8][4], int x, int y){
int X, Y;
X= x; Y= y;
switch(scacchiera[x][y][3]){
  case 'P': for(x= x+1; x<8; x++){//destra sinistra
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='r'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x+1, y= y+1; x<8&&y<8; x++, y++){//diagonale  crescente
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x+1][y+1][3]=='b'||scacchiera[x+1][y+1][3]=='q'){//minaccia a destra (non mangiabile)
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>0&&y>0; x--, y--){
                     if(scacchiera[x-1][y-1][3]=='b'||scacchiera[x-1][y-1][3]=='q'){//minaccia a sinistra (non mangiabile)
                        return 1;}
                     if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x-1, y= y+1; x>-1&&y<8; x--, y++){//diagonale  decrescente
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x-1][y+1][3]=='b'||scacchiera[x-1][y+1][3]=='q'){//minaccia a destra (non mangiabile)
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<7&&y>0; x++, y--){
                     if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){//minaccia a dinistra (non mangiabile)
                        return 1;}
                     if(scacchiera[x+1][y-1][3]!='b'&&scacchiera[x+1][y-1][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            if(scacchiera[X][Y+1][3]!='f'&&(x+1>7||(scacchiera[X+1][Y+1][3]!='p'&&scacchiera[X+1][Y+1][3]!='h'&&scacchiera[X+1][Y+1][3]!='b'&&
               scacchiera[X+1][Y+1][3]!='q'&&scacchiera[X+1][Y+1][3]!='t'&&scacchiera[X+1][Y+1][3]!='r'))&&
              (x-1<0||(scacchiera[X-1][Y+1][3]!='p'&&scacchiera[X-1][Y+1][3]!='h'&&scacchiera[X-1][Y+1][3]!='b'&&
               scacchiera[X-1][Y+1][3]!='q'&&scacchiera[X-1][Y+1][3]!='t'&&scacchiera[X-1][Y+1][3]!='r'))){//avanzata impedita+nulla da attaccare
                return 1;}
            return 0;

  case 'H': for(x= x+1; x<8; x++){//destra sinistra
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='r'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(y= y+1; y<8; y++){//su giu
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='r'){//minaccia a destra
                  x= X; y= Y;
                  for(y= y-1; y>-1; y--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(y= y-1; y>-1; y--){
                     if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x+1, y= y+1; x<8&&y<8; x++, y++){//diagonale  crescente
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){//minaccia a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x-1, y= y+1; x>-1&&y<8; x--, y++){//diagonale  decrescente
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;//ostruzioni
            if((x+1>7||y+2>7||scacchiera[x+1][y+2][3]=='P'||scacchiera[x+1][y+2][3]=='H'||scacchiera[x+1][y+2][3]=='B'||scacchiera[x+1][y+2][3]=='Q'||
                scacchiera[x+1][y+2][3]=='D'||scacchiera[x+1][y+2][3]=='K'||scacchiera[x+1][y+2][3]=='T'||scacchiera[x+1][y+2][3]=='R')&&
               (x-1<0||y+2>7||scacchiera[x-1][y+2][3]=='P'||scacchiera[x-1][y+2][3]=='H'||scacchiera[x-1][y+2][3]=='B'||scacchiera[x-1][y+2][3]=='Q'||
                scacchiera[x-1][y+2][3]=='D'||scacchiera[x-1][y+2][3]=='K'||scacchiera[x-1][y+2][3]=='T'||scacchiera[x-1][y+2][3]=='R')&&
               (x+1>7||y-2<0||scacchiera[x+1][y-2][3]=='P'||scacchiera[x+1][y-2][3]=='H'||scacchiera[x+1][y-2][3]=='B'||scacchiera[x+1][y-2][3]=='Q'||
                scacchiera[x+1][y-2][3]=='D'||scacchiera[x+1][y-2][3]=='K'||scacchiera[x+1][y-2][3]=='T'||scacchiera[x+1][y-2][3]=='R')&&
               (x-1<0||y-2<0||scacchiera[x-1][y-2][3]=='P'||scacchiera[x-1][y-2][3]=='H'||scacchiera[x-1][y-2][3]=='B'||scacchiera[x-1][y-2][3]=='Q'||
                scacchiera[x-1][y-2][3]=='D'||scacchiera[x-1][y-2][3]=='K'||scacchiera[x-1][y-2][3]=='T'||scacchiera[x-1][y-2][3]=='R')&&
               (x+2>7||y+1>7||scacchiera[x+2][y+1][3]=='P'||scacchiera[x+2][y+1][3]=='H'||scacchiera[x+2][y+1][3]=='B'||scacchiera[x+2][y+1][3]=='Q'||
                scacchiera[x+2][y+1][3]=='D'||scacchiera[x+2][y+1][3]=='K'||scacchiera[x+2][y+1][3]=='T'||scacchiera[x+2][y+1][3]=='R')&&
               (x-2<0||y+1>7||scacchiera[x-2][y+1][3]=='P'||scacchiera[x-2][y+1][3]=='H'||scacchiera[x-2][y+1][3]=='B'||scacchiera[x-2][y+1][3]=='Q'||
                scacchiera[x-2][y+1][3]=='D'||scacchiera[x-2][y+1][3]=='K'||scacchiera[x-2][y+1][3]=='T'||scacchiera[x-2][y+1][3]=='R')&&
               (x+2>7||y-1<0||scacchiera[x+2][y-1][3]=='P'||scacchiera[x+2][y-1][3]=='H'||scacchiera[x+2][y-1][3]=='B'||scacchiera[x+2][y-1][3]=='Q'||
                scacchiera[x+2][y-1][3]=='D'||scacchiera[x+2][y-1][3]=='K'||scacchiera[x+2][y-1][3]=='T'||scacchiera[x+2][y-1][3]=='R')&&
               (x-2<0||y-1<0||scacchiera[x-2][y-1][3]=='P'||scacchiera[x-2][y-1][3]=='H'||scacchiera[x-2][y-1][3]=='B'||scacchiera[x-2][y-1][3]=='Q'||
                scacchiera[x-2][y-1][3]=='D'||scacchiera[x-2][y-1][3]=='K'||scacchiera[x-2][y-1][3]=='T'||scacchiera[x-2][y-1][3]=='R')){
            return 1;}
            return 0;

  case 'B': for(x= x+1; x<8; x++){//destra sinistra
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='r'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(y= y+1; y<8; y++){//su giu
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='r'){//minaccia a destra
                  x= X; y= Y;
                  for(y= y-1; y>-1; y--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(y= y-1; y>-1; y--){
                     if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            if((x+1>7||y+1>7||scacchiera[x+1][y+1][3]=='P'||scacchiera[x+1][y+1][3]=='H'||scacchiera[x+1][y+1][3]=='B'||scacchiera[x+1][y+1][3]=='Q'||
                scacchiera[x+1][y+1][3]=='D'||scacchiera[x+1][y+1][3]=='K'||scacchiera[x+1][y+1][3]=='T'||scacchiera[x+1][y+1][3]=='R')&&
               (x-1<0||y+1>7||scacchiera[x-1][y+1][3]=='P'||scacchiera[x-1][y+1][3]=='H'||scacchiera[x-1][y+1][3]=='B'||scacchiera[x-1][y+1][3]=='Q'||
                scacchiera[x-1][y+1][3]=='D'||scacchiera[x-1][y+1][3]=='K'||scacchiera[x-1][y+1][3]=='T'||scacchiera[x-1][y+1][3]=='R')&&
               (x+1>7||y-1<0||scacchiera[x+1][y-1][3]=='P'||scacchiera[x+1][y-1][3]=='H'||scacchiera[x+1][y-1][3]=='B'||scacchiera[x+1][y-1][3]=='Q'||
                scacchiera[x+1][y-1][3]=='D'||scacchiera[x+1][y-1][3]=='K'||scacchiera[x+1][y-1][3]=='T'||scacchiera[x+1][y-1][3]=='R')&&
               (x-1<0||y-1<0||scacchiera[x-1][y-1][3]=='P'||scacchiera[x-1][y-1][3]=='H'||scacchiera[x-1][y-1][3]=='B'||scacchiera[x-1][y-1][3]=='Q'||
                scacchiera[x-1][y-1][3]=='D'||scacchiera[x-1][y-1][3]=='K'||scacchiera[x-1][y-1][3]=='T'||scacchiera[x-1][y-1][3]=='R')){
                return 1;}
            return 0;

  case 'R':
  case 'T': for(x= x+1, y= y+1; x<8&&y<8; x++, y++){//diagonale  crescente
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){//minaccia a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x-1, y= y+1; x>-1&&y<8; x--, y++){//diagonale  decrescente
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            if((x+1>7||scacchiera[x+1][y][3]=='P'||scacchiera[x+1][y][3]=='H'||scacchiera[x+1][y][3]=='B'||scacchiera[x+1][y][3]=='Q'||
                scacchiera[x+1][y][3]=='D'||scacchiera[x+1][y][3]=='K'||scacchiera[x+1][y][3]=='T'||scacchiera[x+1][y][3]=='R')&&
               (x-1<0||scacchiera[x-1][y][3]=='P'||scacchiera[x-1][y][3]=='H'||scacchiera[x-1][y][3]=='B'||scacchiera[x-1][y][3]=='Q'||
                scacchiera[x-1][y][3]=='D'||scacchiera[x-1][y][3]=='K'||scacchiera[x-1][y][3]=='T'||scacchiera[x-1][y][3]=='R')&&
               (y+1>7||scacchiera[x][y+1][3]=='P'||scacchiera[x][y+1][3]=='H'||scacchiera[x][y+1][3]=='B'||scacchiera[x][y+1][3]=='Q'||
                scacchiera[x][y+1][3]=='D'||scacchiera[x][y+1][3]=='K'||scacchiera[x][y+1][3]=='T'||scacchiera[x][y+1][3]=='R')&&
               (y-1<0||scacchiera[x][y-1][3]=='P'||scacchiera[x][y-1][3]=='H'||scacchiera[x][y-1][3]=='B'||scacchiera[x][y-1][3]=='Q'||
                scacchiera[x][y-1][3]=='D'||scacchiera[x][y-1][3]=='K'||scacchiera[x][y-1][3]=='T'||scacchiera[x][y-1][3]=='R')){
                return 1;}
            return 0;

case 'Q': if((x+1>7||scacchiera[x+1][y][3]=='P'||scacchiera[x+1][y][3]=='H'||scacchiera[x+1][y][3]=='B'||scacchiera[x+1][y][3]=='Q'||
                scacchiera[x+1][y][3]=='D'||scacchiera[x+1][y][3]=='K'||scacchiera[x+1][y][3]=='T'||scacchiera[x+1][y][3]=='R')&&
               (x-1<0||scacchiera[x-1][y][3]=='P'||scacchiera[x-1][y][3]=='H'||scacchiera[x-1][y][3]=='B'||scacchiera[x-1][y][3]=='Q'||
                scacchiera[x-1][y][3]=='D'||scacchiera[x-1][y][3]=='K'||scacchiera[x-1][y][3]=='T'||scacchiera[x-1][y][3]=='R')&&
               (y+1>7||scacchiera[x][y+1][3]=='P'||scacchiera[x][y+1][3]=='H'||scacchiera[x][y+1][3]=='B'||scacchiera[x][y+1][3]=='Q'||
                scacchiera[x][y+1][3]=='D'||scacchiera[x][y+1][3]=='K'||scacchiera[x][y+1][3]=='T'||scacchiera[x][y+1][3]=='R')&&
               (y-1<0||scacchiera[x][y-1][3]=='P'||scacchiera[x][y-1][3]=='H'||scacchiera[x][y-1][3]=='B'||scacchiera[x][y-1][3]=='Q'||
                scacchiera[x][y-1][3]=='D'||scacchiera[x][y-1][3]=='K'||scacchiera[x][y-1][3]=='T'||scacchiera[x][y-1][3]=='R')&&
               (x+1>7||y+1>7||scacchiera[x+1][y+1][3]=='P'||scacchiera[x+1][y+1][3]=='H'||scacchiera[x+1][y+1][3]=='B'||scacchiera[x+1][y+1][3]=='Q'||
                scacchiera[x+1][y+1][3]=='D'||scacchiera[x+1][y+1][3]=='K'||scacchiera[x+1][y+1][3]=='T'||scacchiera[x+1][y+1][3]=='R')&&
               (x-1<0||y-1<0||scacchiera[x-1][y-1][3]=='P'||scacchiera[x-1][y-1][3]=='H'||scacchiera[x-1][y-1][3]=='B'||scacchiera[x-1][y-1][3]=='Q'||
                scacchiera[x-1][y-1][3]=='D'||scacchiera[x-1][y-1][3]=='K'||scacchiera[x-1][y-1][3]=='T'||scacchiera[x-1][y-1][3]=='R')&&
               (x+1>7||y-1<0||scacchiera[x+1][y-1][3]=='P'||scacchiera[x+1][y-1][3]=='H'||scacchiera[x+1][y-1][3]=='B'||scacchiera[x+1][y-1][3]=='Q'||
                scacchiera[x+1][y-1][3]=='D'||scacchiera[x+1][y-1][3]=='K'||scacchiera[x+1][y-1][3]=='T'||scacchiera[x+1][y-1][3]=='R')&&
               (x-1<0||y+1>7||scacchiera[x-1][y+1][3]=='P'||scacchiera[x-1][y+1][3]=='H'||scacchiera[x-1][y+1][3]=='B'||scacchiera[x-1][y+1][3]=='Q'||
                scacchiera[x-1][y+1][3]=='D'||scacchiera[x-1][y+1][3]=='K'||scacchiera[x-1][y+1][3]=='T'||scacchiera[x-1][y+1][3]=='R')){
                return 1;}
            return 0;


  default: return 1;}}

int verifica_inchiodatura_assolutanero (char scacchiera[8][8][4], int x, int y){
int X, Y;
X= x; Y= y;
switch(scacchiera[x][y][3]){
  case 'p': for(x= x+1; x<8; x++){//destra sinistra
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='R'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='Q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x+1, y= y+1; x<8&&y<8; x++, y++){//diagonale  crescente
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x+1][y+1][3]=='B'||scacchiera[x+1][y+1][3]=='Q'){//minaccia a destra (non mangiabile)
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>0&&y>0; x--, y--){
                     if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}
                     if(scacchiera[x-1][y-1][3]=='B'||scacchiera[x-1][y-1][3]=='Q'){//minaccia a sinistra (non mangiabile)
                        return 1;}}
                  break;}}
            x= X; y= Y;
            for(x= x-1, y= y+1; x>-1&&y<8; x--, y++){//diagonale  decrescente
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x-1][y+1][3]=='B'||scacchiera[x-1][y+1][3]=='Q'){//minaccia a destra (non mangiabile)
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<7&&y>0; x++, y--){
                     if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}
                     if(scacchiera[x+1][y-1][3]=='B'||scacchiera[x+1][y-1][3]=='Q'){//minaccia a dinistra (non mangiabile)
                        return 1;}}
                  break;}}
            x= X; y= Y;
            if(scacchiera[X][Y-1][3]!='f'&&(x+1>7||(scacchiera[X+1][Y-1][3]!='P'&&scacchiera[X+1][Y-1][3]!='H'&&scacchiera[X+1][Y-1][3]!='B'&&
               scacchiera[X+1][Y-1][3]!='Q'&&scacchiera[X+1][Y-1][3]!='T'&&scacchiera[X+1][Y-1][3]!='R'))&&
              (x-1<0||(scacchiera[X-1][Y-1][3]!='P'&&scacchiera[X-1][Y-1][3]!='H'&&scacchiera[X-1][Y-1][3]!='B'&&
               scacchiera[X-1][Y-1][3]!='Q'&&scacchiera[X-1][Y-1][3]!='T'&&scacchiera[X-1][Y-1][3]!='R'))){//avanzata impedita+nulla da attaccare
                return 1;}
            return 0;

  case 'h': for(x= x+1; x<8; x++){//destra sinistra
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='R'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='Q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(y= y+1; y<8; y++){//su giù
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='R'){//minaccia a destra
                  x= X; y= Y;
                  for(y= y-1; y>-1; y--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(y= y-1; y>-1; y--){
                     if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='Q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x+1, y= y+1; x<8&&y<8; x++, y++){//diagonale  crescente
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x-1, y= y+1; x>-1&&y<8; x--, y++){//diagonale  decrescente
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            if((x+1>7||y+2>7||scacchiera[x+1][y+2][3]=='p'||scacchiera[x+1][y+2][3]=='h'||scacchiera[x+1][y+2][3]=='b'||scacchiera[x+1][y+2][3]=='q'||
                scacchiera[x+1][y+2][3]=='d'||scacchiera[x+1][y+2][3]=='k'||scacchiera[x+1][y+2][3]=='t'||scacchiera[x+1][y+2][3]=='r')&&
               (x-1<0||y+2>7||scacchiera[x-1][y+2][3]=='p'||scacchiera[x-1][y+2][3]=='h'||scacchiera[x-1][y+2][3]=='b'||scacchiera[x-1][y+2][3]=='q'||
                scacchiera[x-1][y+2][3]=='d'||scacchiera[x-1][y+2][3]=='k'||scacchiera[x-1][y+2][3]=='t'||scacchiera[x-1][y+2][3]=='r')&&
               (x+1>7||y-2<0||scacchiera[x+1][y-2][3]=='p'||scacchiera[x+1][y-2][3]=='h'||scacchiera[x+1][y-2][3]=='b'||scacchiera[x+1][y-2][3]=='q'||
                scacchiera[x+1][y-2][3]=='d'||scacchiera[x+1][y-2][3]=='k'||scacchiera[x+1][y-2][3]=='t'||scacchiera[x+1][y-2][3]=='r')&&
               (x-1<0||y-2<0||scacchiera[x-1][y-2][3]=='p'||scacchiera[x-1][y-2][3]=='h'||scacchiera[x-1][y-2][3]=='b'||scacchiera[x-1][y-2][3]=='q'||
                scacchiera[x-1][y-2][3]=='d'||scacchiera[x-1][y-2][3]=='k'||scacchiera[x-1][y-2][3]=='t'||scacchiera[x-1][y-2][3]=='r')&&
               (x+2>7||y+1>7||scacchiera[x+2][y+1][3]=='p'||scacchiera[x+2][y+1][3]=='h'||scacchiera[x+2][y+1][3]=='b'||scacchiera[x+2][y+1][3]=='q'||
                scacchiera[x+2][y+1][3]=='d'||scacchiera[x+2][y+1][3]=='k'||scacchiera[x+2][y+1][3]=='t'||scacchiera[x+2][y+1][3]=='r')&&
               (x-2<0||y+1>7||scacchiera[x-2][y+1][3]=='p'||scacchiera[x-2][y+1][3]=='h'||scacchiera[x-2][y+1][3]=='b'||scacchiera[x-2][y+1][3]=='q'||
                scacchiera[x-2][y+1][3]=='d'||scacchiera[x-2][y+1][3]=='k'||scacchiera[x-2][y+1][3]=='t'||scacchiera[x-2][y+1][3]=='r')&&
               (x+2>7||y-1<0||scacchiera[x+2][y-1][3]=='p'||scacchiera[x+2][y-1][3]=='h'||scacchiera[x+2][y-1][3]=='b'||scacchiera[x+2][y-1][3]=='q'||
                scacchiera[x+2][y-1][3]=='d'||scacchiera[x+2][y-1][3]=='k'||scacchiera[x+2][y-1][3]=='t'||scacchiera[x+2][y-1][3]=='r')&&
               (x-2<0||y-1<0||scacchiera[x-2][y-1][3]=='p'||scacchiera[x-2][y-1][3]=='h'||scacchiera[x-2][y-1][3]=='b'||scacchiera[x-2][y-1][3]=='q'||
                scacchiera[x-2][y-1][3]=='d'||scacchiera[x-2][y-1][3]=='k'||scacchiera[x-2][y-1][3]=='t'||scacchiera[x-2][y-1][3]=='r')){
            return 1;}
            return 0;

  case 'b': for(x= x+1; x<8; x++){//destra sinistra
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='R'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='Q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(y= y+1; y<8; y++){//su giù
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='R'){//minaccia a destra
                  x= X; y= Y;
                  for(y= y-1; y<-1; y--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(y= y-1; y>-1; y--){
                     if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='Q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            if((x+1>7||y+1>7||scacchiera[x+1][y+1][3]=='p'||scacchiera[x+1][y+1][3]=='h'||scacchiera[x+1][y+1][3]=='b'||scacchiera[x+1][y+1][3]=='q'||
                scacchiera[x+1][y+1][3]=='d'||scacchiera[x+1][y+1][3]=='k'||scacchiera[x+1][y+1][3]=='t'||scacchiera[x+1][y+1][3]=='r')&&
               (x-1<0||y+1>7||scacchiera[x-1][y+1][3]=='p'||scacchiera[x-1][y+1][3]=='h'||scacchiera[x-1][y+1][3]=='b'||scacchiera[x-1][y+1][3]=='q'||
                scacchiera[x-1][y+1][3]=='d'||scacchiera[x-1][y+1][3]=='k'||scacchiera[x-1][y+1][3]=='t'||scacchiera[x-1][y+1][3]=='r')&&
               (x+1>7||y-1<0||scacchiera[x+1][y-1][3]=='p'||scacchiera[x+1][y-1][3]=='h'||scacchiera[x+1][y-1][3]=='b'||scacchiera[x+1][y-1][3]=='q'||
                scacchiera[x+1][y-1][3]=='d'||scacchiera[x+1][y-1][3]=='k'||scacchiera[x+1][y-1][3]=='t'||scacchiera[x+1][y-1][3]=='r')&&
               (x-1<0||y-1<0||scacchiera[x-1][y-1][3]=='p'||scacchiera[x-1][y-1][3]=='h'||scacchiera[x-1][y-1][3]=='b'||scacchiera[x-1][y-1][3]=='q'||
                scacchiera[x-1][y-1][3]=='d'||scacchiera[x-1][y-1][3]=='k'||scacchiera[x-1][y-1][3]=='t'||scacchiera[x-1][y-1][3]=='r')){
                return 1;}
            return 0;

  case 'r':
  case 't': for(x= x+1, y= y+1; x<8&&y<8; x++, y++){//diagonale  crescente
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x-1, y= y+1; x>-1&&y<8; x--, y++){//diagonale  decrescente
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            if((x+1>7||scacchiera[x+1][y][3]=='p'||scacchiera[x+1][y][3]=='h'||scacchiera[x+1][y][3]=='b'||scacchiera[x+1][y][3]=='q'||
                scacchiera[x+1][y][3]=='d'||scacchiera[x+1][y][3]=='k'||scacchiera[x+1][y][3]=='t'||scacchiera[x+1][y][3]=='r')&&
               (x-1<0||scacchiera[x-1][y][3]=='p'||scacchiera[x-1][y][3]=='h'||scacchiera[x-1][y][3]=='b'||scacchiera[x-1][y][3]=='q'||
                scacchiera[x-1][y][3]=='d'||scacchiera[x-1][y][3]=='k'||scacchiera[x-1][y][3]=='t'||scacchiera[x-1][y][3]=='r')&&
               (y+1>7||scacchiera[x][y+1][3]=='p'||scacchiera[x][y+1][3]=='h'||scacchiera[x][y+1][3]=='b'||scacchiera[x][y+1][3]=='q'||
                scacchiera[x][y+1][3]=='d'||scacchiera[x][y+1][3]=='k'||scacchiera[x][y+1][3]=='t'||scacchiera[x][y+1][3]=='r')&&
               (y-1<0||scacchiera[x][y-1][3]=='p'||scacchiera[x][y-1][3]=='h'||scacchiera[x][y-1][3]=='b'||scacchiera[x][y-1][3]=='q'||
                scacchiera[x][y-1][3]=='d'||scacchiera[x][y-1][3]=='k'||scacchiera[x][y-1][3]=='t'||scacchiera[x][y-1][3]=='r')){
                return 1;}
            return 0;

 case 'q': if((x+1>7||scacchiera[x+1][y][3]=='p'||scacchiera[x+1][y][3]=='h'||scacchiera[x+1][y][3]=='b'||scacchiera[x+1][y][3]=='q'||
                scacchiera[x+1][y][3]=='d'||scacchiera[x+1][y][3]=='k'||scacchiera[x+1][y][3]=='t'||scacchiera[x+1][y][3]=='r')&&
               (x-1<0||scacchiera[x-1][y][3]=='p'||scacchiera[x-1][y][3]=='h'||scacchiera[x-1][y][3]=='b'||scacchiera[x-1][y][3]=='q'||
                scacchiera[x-1][y][3]=='d'||scacchiera[x-1][y][3]=='k'||scacchiera[x-1][y][3]=='t'||scacchiera[x-1][y][3]=='r')&&
               (y+1>7||scacchiera[x][y+1][3]=='p'||scacchiera[x][y+1][3]=='h'||scacchiera[x][y+1][3]=='b'||scacchiera[x][y+1][3]=='q'||
                scacchiera[x][y+1][3]=='d'||scacchiera[x][y+1][3]=='k'||scacchiera[x][y+1][3]=='t'||scacchiera[x][y+1][3]=='r')&&
               (y-1<0||scacchiera[x][y-1][3]=='p'||scacchiera[x][y-1][3]=='h'||scacchiera[x][y-1][3]=='b'||scacchiera[x][y-1][3]=='q'||
                scacchiera[x][y-1][3]=='d'||scacchiera[x][y-1][3]=='k'||scacchiera[x][y-1][3]=='t'||scacchiera[x][y-1][3]=='r')&&
               (x+1>7||y+1>7||scacchiera[x+1][y+1][3]=='p'||scacchiera[x+1][y+1][3]=='h'||scacchiera[x+1][y+1][3]=='b'||scacchiera[x+1][y+1][3]=='q'||
                scacchiera[x+1][y+1][3]=='d'||scacchiera[x+1][y+1][3]=='k'||scacchiera[x+1][y+1][3]=='t'||scacchiera[x+1][y+1][3]=='r')&&
               (x-1<0||y-1<0||scacchiera[x-1][y-1][3]=='p'||scacchiera[x-1][y-1][3]=='h'||scacchiera[x-1][y-1][3]=='b'||scacchiera[x-1][y-1][3]=='q'||
                scacchiera[x-1][y-1][3]=='d'||scacchiera[x-1][y-1][3]=='k'||scacchiera[x-1][y-1][3]=='t'||scacchiera[x-1][y-1][3]=='r')&&
               (x+1>7||y-1<0||scacchiera[x+1][y-1][3]=='p'||scacchiera[x+1][y-1][3]=='h'||scacchiera[x+1][y-1][3]=='b'||scacchiera[x+1][y-1][3]=='q'||
                scacchiera[x+1][y-1][3]=='d'||scacchiera[x+1][y-1][3]=='k'||scacchiera[x+1][y-1][3]=='t'||scacchiera[x+1][y-1][3]=='r')&&
               (x-1<0||y+1>7||scacchiera[x-1][y+1][3]=='p'||scacchiera[x-1][y+1][3]=='h'||scacchiera[x-1][y+1][3]=='b'||scacchiera[x-1][y+1][3]=='q'||
                scacchiera[x-1][y+1][3]=='d'||scacchiera[x-1][y+1][3]=='k'||scacchiera[x-1][y+1][3]=='t'||scacchiera[x-1][y+1][3]=='r')){
                return 1;}
            return 0;

 default: return 1;}}

int verifica_inchiodatura_semplicebianco (char scacchiera[8][8][4], int x, int y){
int X, Y;
X= x; Y= y;
switch(scacchiera[x][y][3]){
  case 'P': for(x= x+1; x<8; x++){//destra sinistra
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='r'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(y= y+1; y<8; y++){//su giu
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='r'){//minaccia a destra
                  x= X; y= Y;
                  for(y= y-1; y>-1; y--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(y= y-1; y>-1; y--){
                     if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x+1, y= y+1; x<8&&y<8; x++, y++){//diagonale  crescente
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x+1][y+1][3]=='b'||scacchiera[x+1][y+1][3]=='q'){//minaccia a destra (non mangiabile)
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>0&&y>0; x--, y--){
                     if(scacchiera[x-1][y-1][3]=='b'||scacchiera[x-1][y-1][3]=='q'){//minaccia a sinistra (non mangiabile)
                        return 1;}
                     if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x-1, y= y+1; x>-1&&y<8; x--, y++){//diagonale  decrescente
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x-1][y+1][3]=='b'||scacchiera[x-1][y+1][3]=='q'){//minaccia a destra (non mangiabile)
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<7&&y>0; x++, y--){
                     if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){//minaccia a dinistra (non mangiabile)
                        return 1;}
                     if(scacchiera[x+1][y-1][3]!='b'&&scacchiera[x+1][y-1][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            return 0;

  case 'H': for(x= x+1; x<8; x++){//destra sinistra
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='r'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(y= y+1; y<8; y++){//su giu
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='r'){//minaccia a destra
                  x= X; y= Y;
                  for(y= y-1; y>-1; y--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(y= y-1; y>-1; y--){
                     if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x+1, y= y+1; x<8&&y<8; x++, y++){//diagonale  crescente
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){//minaccia a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x-1, y= y+1; x>-1&&y<8; x--, y++){//diagonale  decrescente
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            return 0;

  case 'B': for(x= x+1; x<8; x++){//destra sinistra
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='r'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(y= y+1; y<8; y++){//su giu
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='r'){//minaccia a destra
                  x= X; y= Y;
                  for(y= y-1; y>-1; y--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(y= y-1; y>-1; y--){
                     if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x+1, y= y+1; x<8&&y<8; x++, y++){//diagonale  crescente
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x+1][y+1][3]=='b'||scacchiera[x+1][y+1][3]=='q'){//minaccia a destra (non mangiabile)
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>0&&y>0; x--, y--){
                     if(scacchiera[x-1][y-1][3]=='b'||scacchiera[x-1][y-1][3]=='q'){//minaccia a sinistra (non mangiabile)
                        return 1;}
                     if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x-1, y= y+1; x>-1&&y<8; x--, y++){//diagonale  decrescente
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x-1][y+1][3]=='b'||scacchiera[x-1][y+1][3]=='q'){//minaccia a destra (non mangiabile)
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<7&&y>0; x++, y--){
                     if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){//minaccia a dinistra (non mangiabile)
                        return 1;}
                     if(scacchiera[x+1][y-1][3]!='b'&&scacchiera[x+1][y-1][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            return 0;

  case 'R':
  case 'T': for(x= x+1; x<8; x++){//destra sinistra
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='r'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(y= y+1; y<8; y++){//su giu
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='r'){//minaccia a destra
                  x= X; y= Y;
                  for(y= y-1; y>-1; y--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(y= y-1; y>-1; y--){
                     if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x+1, y= y+1; x<8&&y<8; x++, y++){//diagonale  crescente
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){//minaccia a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x-1, y= y+1; x>-1&&y<8; x--, y++){//diagonale  decrescente
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            return 0;

case 'Q':   for(x= x+1; x<8; x++){//destra sinistra
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='r'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(y= y+1; y<8; y++){//su giu
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='r'){//minaccia a destra
                  x= X; y= Y;
                  for(y= y-1; y>-1; y--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(y= y-1; y>-1; y--){
                     if(scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x+1, y= y+1; x<8&&y<8; x++, y++){//diagonale  crescente
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){//minaccia a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x-1, y= y+1; x>-1&&y<8; x--, y++){//diagonale  decrescente
               if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='D'||scacchiera[x][y][3]=='K'){//re a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            return 0;

default: return 1;}}

int verifica_inchiodatura_semplicenero (char scacchiera[8][8][4], int x, int y){
int X, Y;
X= x; Y= y;
switch(scacchiera[x][y][3]){
  case 'p': for(x= x+1; x<8; x++){//destra sinistra
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='R'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='Q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(y= y+1; y<8; y++){//su giù
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='R'){//minaccia a destra
                  x= X; y= Y;
                  for(y= y-1; y>-1; y--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(y= y-1; y>-1; y--){
                     if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='Q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x+1, y= y+1; x<8&&y<8; x++, y++){//diagonale  crescente
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x-1, y= y+1; x>-1&&y<8; x--, y++){//diagonale  decrescente
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            return 0;

  case 'h': for(x= x+1; x<8; x++){//destra sinistra
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='R'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='Q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(y= y+1; y<8; y++){//su giù
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='R'){//minaccia a destra
                  x= X; y= Y;
                  for(y= y-1; y>-1; y--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(y= y-1; y>-1; y--){
                     if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='Q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x+1, y= y+1; x<8&&y<8; x++, y++){//diagonale  crescente
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x-1, y= y+1; x>-1&&y<8; x--, y++){//diagonale  decrescente
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            return 0;

  case 'b': for(x= x+1; x<8; x++){//destra sinistra
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='R'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='Q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(y= y+1; y<8; y++){//su giù
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='R'){//minaccia a destra
                  x= X; y= Y;
                  for(y= y-1; y>-1; y--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(y= y-1; y>-1; y--){
                     if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='Q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x+1, y= y+1; x<8&&y<8; x++, y++){//diagonale  crescente
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x-1, y= y+1; x>-1&&y<8; x--, y++){//diagonale  decrescente
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            return 0;

  case 'r':
  case 't': for(x= x+1; x<8; x++){//destra sinistra
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='R'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='Q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(y= y+1; y<8; y++){//su giù
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='R'){//minaccia a destra
                  x= X; y= Y;
                  for(y= y-1; y>-1; y--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(y= y-1; y>-1; y--){
                     if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='Q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x+1, y= y+1; x<8&&y<8; x++, y++){//diagonale  crescente
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x-1, y= y+1; x>-1&&y<8; x--, y++){//diagonale  decrescente
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            return 0;

 case 'q':  for(x= x+1; x<8; x++){//destra sinistra
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='R'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(x= x-1; x>-1; x--){
                     if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='Q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(y= y+1; y<8; y++){//su giù
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='R'){//minaccia a destra
                  x= X; y= Y;
                  for(y= y-1; y>-1; y--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(y= y-1; y>-1; y--){
                     if(scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='Q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x+1, y= y+1; x<8&&y<8; x++, y++){//diagonale  crescente
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){
                     if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            x= X; y= Y;
            for(x= x-1, y= y+1; x>-1&&y<8; x--, y++){//diagonale  decrescente
               if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                  break;}//ostacolo
               if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a sinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//ostacolo
                        break;}}
                  break;}
               if(scacchiera[x][y][3]=='d'||scacchiera[x][y][3]=='k'){//re a destra
                  x= X; y= Y;
                  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){
                     if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){//minaccia a dinistra
                        return 1;}
                     if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
                        break;}}
                  break;}}
            return 0;

 default: return 1;}}

int verifica_visione_casellabianca (char scacchiera[8][8][4], int x, int y){
int X, Y;
  X= x; Y= y;
  if(x+1<8&&y+1<8&&(scacchiera[x+1][y+1][3]=='p'||scacchiera[x+1][y+1][3]=='k'||scacchiera[x+1][y+1][3]=='d')){//pedoni e re
            return 1;}
  if(x-1>-1&&y+1<8&&(scacchiera[x-1][y+1][3]=='p'||scacchiera[x-1][y+1][3]=='k'||scacchiera[x-1][y+1][3]=='d')){
            return 1;}
  if(x+1<8&&y-1>-1&&(scacchiera[x+1][y-1][3]=='k'||scacchiera[x+1][y-1][3]=='d')){
            return 1;}
  if(x-1>-1&&y-1>-1&&(scacchiera[x-1][y-1][3]=='k'||scacchiera[x-1][y-1][3]=='d')){
            return 1;}
  if(x+1<8&&(scacchiera[x+1][y][3]=='k'||scacchiera[x+1][y][3]=='d')){
            return 1;}
  if(x-1>-1&&(scacchiera[x-1][y][3]=='k'||scacchiera[x-1][y][3]=='d')){
            return 1;}
  if(y+1<8&&(scacchiera[x][y+1][3]=='k'||scacchiera[x][y+1][3]=='d')){
            return 1;}
  if(y-1>-1&&(scacchiera[x][y-1][3]=='k'||scacchiera[x][y-1][3]=='d')){
            return 1;}
//cavallo
  if((scacchiera[x+1][y+2][3]=='h'&&x+1<8&&y+2<8)||(scacchiera[x-1][y+2][3]=='h'&&x-1>-1&&y+2<8)||
       (scacchiera[x+1][y-2][3]=='h'&&x+1<8&&y-2>-1)||(scacchiera[x-1][y-2][3]=='h'&&x-1>-1&&y-2>-1)||
       (scacchiera[x+2][y+1][3]=='h'&&x+2<8&&y+1<8)||(scacchiera[x-2][y+1][3]=='h'&&x-2>-1&&y+1<8)||
       (scacchiera[x+2][y-1][3]=='h'&&x+2<8&&y-1>-1)||(scacchiera[x-2][y-1][3]=='h'&&x-2>-1&&y-1>-1)){
            return 1;}
  for(x=x-1; x>-1; x--){//sinistra
        if(scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'){
            return 1;}
        if(scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x=x+1; x<8; x++){//destra
        if(scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'){
            return 1;}
        if(scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(y=y+1; y<8; y++){//su
        if(scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'){
            return 1;}
        if(scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'){
           x= X; y= Y; break;}}
  x= X; y= Y;
  for(y=y-1; y>-1; y--){//giu
        if(scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'){
            return 1;}
        if(scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){//diagonale sinistra giu
        if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){
            return 1;}
        if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){//diagonale destra giu
        if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){
            return 1;}
        if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x+1, y= y+1; x<8&&y<8; x++, y++){//diagonale destra su
        if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){
            return 1;}
        if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x-1, y= y+1; x>-1&&y<8; x--, y++){//diagonale sinistra su
        if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){
            return 1;}
        if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='D'&&scacchiera[x][y][3]!='K'){
            x= X; y= Y; break;}}
return 0;}

int verifica_visione_casellanera (char scacchiera[8][8][4], int x, int y){
int X, Y;
  X= x; Y= y;
  if(x+1<8&&y-1>-1&&(scacchiera[x+1][y-1][3]=='P'||scacchiera[x+1][y-1][3]=='K'||scacchiera[x+1][y-1][3]=='D')){//pedoni e re
            return 1;}
  if(x-1>-1&&y-1>-1&&(scacchiera[x-1][y-1][3]=='P'||scacchiera[x-1][y-1][3]=='K'||scacchiera[x-1][y-1][3]=='D')){
            return 1;}
  if(x+1<8&&y+1<8&&(scacchiera[x+1][y+1][3]=='K'||scacchiera[x+1][y+1][3]=='D')){
            return 1;}
  if(x-1>-1&&y+1<8&&(scacchiera[x-1][y+1][3]=='K'||scacchiera[x-1][y+1][3]=='D')){
            return 1;}
  if(x+1<8&&(scacchiera[x+1][y][3]=='K'||scacchiera[x+1][y][3]=='D')){
            return 1;}
  if(x-1>-1&&(scacchiera[x-1][y][3]=='K'||scacchiera[x-1][y][3]=='D')){
            return 1;}
  if(y+1<8&&(scacchiera[x][y+1][3]=='K'||scacchiera[x][y+1][3]=='D')){
            return 1;}
  if(y-1>-1&&(scacchiera[x][y-1][3]=='K'||scacchiera[x][y-1][3]=='D')){
            return 1;}
//cavallo
  if((scacchiera[x+1][y+2][3]=='H'&&x+1<8&&y+2<8)||(scacchiera[x-1][y+2][3]=='H'&&x-1>-1&&y+2<8)||
       (scacchiera[x+1][y-2][3]=='H'&&x+1<8&&y-2>-1)||(scacchiera[x-1][y-2][3]=='H'&&x-1>-1&&y-2>-1)||
       (scacchiera[x+2][y+1][3]=='H'&&x+2<8&&y+1<8)||(scacchiera[x-2][y+1][3]=='H'&&x-2>-1&&y+1<8)||
       (scacchiera[x+2][y-1][3]=='H'&&x+2<8&&y-1>-1)||(scacchiera[x-2][y-1][3]=='H'&&x-2>-1&&y-1>-1)){
            return 1;}
  for(x=x-1; x>-1; x--){//sinistra
        if(scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'){
            return 1;}
        if(scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x=x+1; x<8; x++){//destra
        if(scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'){
            return 1;}
        if(scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(y=y+1; y<8; y++){//su
        if(scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'){
            return 1;}
        if(scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='E'){
           x= X; y= Y; break;}}
  x= X; y= Y;
  for(y=y-1; y>-1; y--){//giu
        if(scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'){
            return 1;}
        if(scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){//diagonale sinistra giu
        if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){
            return 1;}
        if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){//diagonale destra giu
        if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){
            return 1;}
        if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x+1, y= y+1; x<8&&y<8; x++, y++){//diagonale destra su
        if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){
            return 1;}
        if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x-1, y= y+1; x>-1&&y<8; x--, y++){//diagonale sinistra su
        if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){
            return 1;}
        if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='d'&&scacchiera[x][y][3]!='k'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
return 0;}

int verifica_visione_pedinabiancascacco (char scacchiera[8][8][4], int x, int y){
int X, Y, xb, yb;
  X= x; Y= y;//pedoni
  if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//casella non vuota
  if(x+1<8&&y+1<8&&(scacchiera[x+1][y+1][3]=='p')){
            xb= x+1; yb= y+1;
            if(!verifica_inchiodatura_semplicenero(scacchiera, xb, yb)){
                return 1;}}

  if(x-1>-1&&y+1<8&&(scacchiera[x-1][y+1][3]=='p')){
            xb= x-1; yb= y+1;
            if(!verifica_inchiodatura_semplicenero(scacchiera, xb, yb)){
               return 1;}}}

  if(scacchiera[x][y][3]=='f'||scacchiera[x][y][3]=='e'||scacchiera[x][y][3]=='E'){//casella vuota (ci possono avanzare pedoni)
            if(y+1<8&&(scacchiera[x][y+1][3]=='p')){
            xb= x; yb= y+1;
            if(!verifica_inchiodatura_semplicenero(scacchiera, xb, yb)){
                return 1;}}}
//cavallo
  if(scacchiera[x+1][y+2][3]=='h'&&x+1<8&&y+2<8){
    xb= x+1; yb= y+2;
            if(!verifica_inchiodatura_semplicenero(scacchiera, xb, yb)){
                return 1;}}

  if(scacchiera[x-1][y+2][3]=='h'&&x-1>-1&&y+2<8){
    xb= x-1; yb= y+2;
            if(!verifica_inchiodatura_semplicenero(scacchiera, xb, yb)){
                return 1;}}

  if(scacchiera[x+1][y-2][3]=='h'&&x+1<8&&y-2>-1){
    xb= x+1; yb= y-2;
            if(!verifica_inchiodatura_semplicenero(scacchiera, xb, yb)){
                return 1;}}

  if(scacchiera[x-1][y-2][3]=='h'&&x-1>-1&&y-2>-1){
    xb= x-1; yb= y-2;
            if(!verifica_inchiodatura_semplicenero(scacchiera, xb, yb)){
                return 1;}}

  if(scacchiera[x+2][y+1][3]=='h'&&x+2<8&&y+1<8){
    xb= x+2; yb= y+1;
            if(!verifica_inchiodatura_semplicenero(scacchiera, xb, yb)){
                return 1;}}

  if(scacchiera[x-2][y+1][3]=='h'&&x-2>-1&&y+1<8){
    xb= x-2; yb= y+1;
            if(!verifica_inchiodatura_semplicenero(scacchiera, xb, yb)){
                return 1;}}

  if(scacchiera[x+2][y-1][3]=='h'&&x+2<8&&y-1>-1){
    xb= x+2; yb= y-1;
            if(!verifica_inchiodatura_semplicenero(scacchiera, xb, yb)){
                return 1;}}

  if(scacchiera[x-2][y-1][3]=='h'&&x-2>-1&&y-1>-1){
    xb= x-2; yb= y-1;
            if(!verifica_inchiodatura_semplicenero(scacchiera, xb, yb)){
                return 1;}}

  for(x=x-1; x>-1; x--){//sinistra
        if(scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'){
             xb= x; yb= y;
            if(!verifica_inchiodatura_semplicenero(scacchiera, xb, yb)){
                return 1;} break;}
        if(scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x=x+1; x<8; x++){//destra
        if(scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'){
            xb= x; yb= y;
            if(!verifica_inchiodatura_semplicenero(scacchiera, xb, yb)){
                return 1;} break;}
        if(scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(y=y+1; y<8; y++){//su
        if(scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'){
            xb= x; yb= y;
            if(!verifica_inchiodatura_semplicenero(scacchiera, xb, yb)){
                return 1;} break;}
        if(scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
           x= X; y= Y; break;}}
  x= X; y= Y;
  for(y=y-1; y>-1; y--){//giu
        if(scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'){
            xb= x; yb= y;
            if(!verifica_inchiodatura_semplicenero(scacchiera, xb, yb)){
                return 1;} break;}
        if(scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){//diagonale sinistra giu
        if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){
            xb= x; yb= y;
            if(!verifica_inchiodatura_semplicenero(scacchiera, xb, yb)){
                return 1;} break;}
        if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){//diagonale destra giu
        if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){
           xb= x; yb= y;
            if(!verifica_inchiodatura_semplicenero(scacchiera, xb, yb)){
                return 1;} break;}
        if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x+1, y= y+1; x<8&&y<8; x++, y++){//diagonale destra su
        if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){
            xb= x; yb= y;
            if(!verifica_inchiodatura_semplicenero(scacchiera, xb, yb)){
                return 1;} break;}
        if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x-1, y= y+1; x>-1&&y<8; x--, y++){//diagonale sinistra su
        if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){
            xb= x; yb= y;
            if(!verifica_inchiodatura_semplicenero(scacchiera, xb, yb)){
                return 1;} break;}
        if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
return 0;}

int verifica_visione_pedinanerascacco (char scacchiera[8][8][4], int x, int y){
int X, Y, xb, yb;
  X= x; Y= y;
  if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){//casella non vuota
  if(x+1<8&&y-1>-1&&(scacchiera[x+1][y-1][3]=='P')){//pedoni
            xb= x+1; yb= y-1;
            if(!verifica_inchiodatura_semplicebianco(scacchiera, xb, yb)){
                return 1;}}

  if(x-1>-1&&y-1>-1&&(scacchiera[x-1][y-1][3]=='P')){
            xb= x-1; yb= y-1;
            if(!verifica_inchiodatura_semplicebianco(scacchiera, xb, yb)){
                return 1;}}}

  if(scacchiera[x][y][3]=='f'||scacchiera[x][y][3]=='e'||scacchiera[x][y][3]=='E'){//casella vuota (ci possono avanzare pedoni)
            if(y-1>-1&&(scacchiera[x][y-1][3]=='P')){
            xb= x; yb= y-1;
            if(!verifica_inchiodatura_semplicebianco(scacchiera, xb, yb)){
                return 1;}}}

//cavallo
  if(scacchiera[x+1][y+2][3]=='H'&&x+1<8&&y+2<8){
    xb= x+1; yb= y+2;
            if(!verifica_inchiodatura_semplicebianco(scacchiera, xb, yb)){
                return 1;}}

  if(scacchiera[x-1][y+2][3]=='H'&&x-1>-1&&y+2<8){
    xb= x-1; yb= y+2;
            if(!verifica_inchiodatura_semplicebianco(scacchiera, xb, yb)){
                return 1;}}

  if(scacchiera[x+1][y-2][3]=='H'&&x+1<8&&y-2>-1){
    xb= x+1; yb= y-2;
            if(!verifica_inchiodatura_semplicebianco(scacchiera, xb, yb)){
                return 1;}}

  if(scacchiera[x-1][y-2][3]=='H'&&x-1>-1&&y-2>-1){
    xb= x-1; yb= y-2;
            if(!verifica_inchiodatura_semplicebianco(scacchiera, xb, yb)){
                return 1;}}

  if(scacchiera[x+2][y+1][3]=='H'&&x+2<8&&y+1<8){
    xb= x+2; yb= y+1;
            if(!verifica_inchiodatura_semplicebianco(scacchiera, xb, yb)){
                return 1;}}

  if(scacchiera[x-2][y+1][3]=='H'&&x-2>-1&&y+1<8){
    xb= x-2; yb= y+1;
            if(!verifica_inchiodatura_semplicebianco(scacchiera, xb, yb)){
                return 1;}}

  if(scacchiera[x+2][y-1][3]=='H'&&x+2<8&&y-1>-1){
    xb= x+2; yb= y-1;
            if(!verifica_inchiodatura_semplicebianco(scacchiera, xb, yb)){
                return 1;}}

  if(scacchiera[x-2][y-1][3]=='H'&&x-2>-1&&y-1>-1){
    xb= x-2; yb= y-1;
            if(!verifica_inchiodatura_semplicebianco(scacchiera, xb, yb)){
                return 1;}}

  for(x=x-1; x>-1; x--){//sinistra
        if(scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'){
             xb= x; yb= y;
            if(!verifica_inchiodatura_semplicebianco(scacchiera, xb, yb)){
                return 1;} break;}
        if(scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x=x+1; x<8; x++){//destra
        if(scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'){
            xb= x; yb= y;
            if(!verifica_inchiodatura_semplicebianco(scacchiera, xb, yb)){
                return 1;} break;}
        if(scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(y=y+1; y<8; y++){//su
        if(scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'){
            xb= x; yb= y;
            if(!verifica_inchiodatura_semplicebianco(scacchiera, xb, yb)){
                return 1;} break;}
        if(scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
           x= X; y= Y; break;}}
  x= X; y= Y;
  for(y=y-1; y>-1; y--){//giu
        if(scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'){
            xb= x; yb= y;
            if(!verifica_inchiodatura_semplicebianco(scacchiera, xb, yb)){
                return 1;} break;}
        if(scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){//diagonale sinistra giu
        if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){
            xb= x; yb= y;
            if(!verifica_inchiodatura_semplicebianco(scacchiera, xb, yb)){
                return 1;} break;}
        if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){//diagonale destra giu
        if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){
           xb= x; yb= y;
            if(!verifica_inchiodatura_semplicebianco(scacchiera, xb, yb)){
                return 1;} break;}
        if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x+1, y= y+1; x<8&&y<8; x++, y++){//diagonale destra su
        if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){
            xb= x; yb= y;
            if(!verifica_inchiodatura_semplicebianco(scacchiera, xb, yb)){
                return 1;} break;}
        if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x-1, y= y+1; x>-1&&y<8; x--, y++){//diagonale sinistra su
        if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){
            xb= x; yb= y;
            if(!verifica_inchiodatura_semplicebianco(scacchiera, xb, yb)){
                return 1;} break;}
        if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
return 0;}

int verifica_scacco_rebianco(char scacchiera[8][8][4]){
  int x, y, X, Y;
  for(Y=7; Y>-1; Y--){//rintraccia re bianco
    for(X=0; X<8; X++){
        if(scacchiera[X][Y][3]=='K'||scacchiera[X][Y][3]=='D'){
            x= X; y= Y;}}}
  X= x; Y= y;
  if(x+1<8&&y+1<8&&(scacchiera[x+1][y+1][3]=='p'||scacchiera[x+1][y+1][3]=='k'||scacchiera[x+1][y+1][3]=='d')){//pedoni e re
            return 1;}
  if(x-1>-1&&y+1<8&&(scacchiera[x-1][y+1][3]=='p'||scacchiera[x-1][y+1][3]=='k'||scacchiera[x-1][y+1][3]=='d')){
            return 1;}
  if(x+1<8&&y-1>-1&&(scacchiera[x+1][y-1][3]=='k'||scacchiera[x+1][y-1][3]=='d')){
            return 1;}
  if(x-1>-1&&y-1>-1&&(scacchiera[x-1][y-1][3]=='k'||scacchiera[x-1][y-1][3]=='d')){
            return 1;}
  if(x+1<8&&(scacchiera[x+1][y][3]=='k'||scacchiera[x+1][y][3]=='d')){
            return 1;}
  if(x-1>-1&&(scacchiera[x-1][y][3]=='k'||scacchiera[x-1][y][3]=='d')){
            return 1;}
  if(y+1<8&&(scacchiera[x][y+1][3]=='k'||scacchiera[x][y+1][3]=='d')){
            return 1;}
  if(y-1>-1&&(scacchiera[x][y-1][3]=='k'||scacchiera[x][y-1][3]=='d')){
            return 1;}
//cavallo
  if((scacchiera[x+1][y+2][3]=='h'&&x+1<8&&y+2<8)||(scacchiera[x-1][y+2][3]=='h'&&x-1>-1&&y+2<8)||
       (scacchiera[x+1][y-2][3]=='h'&&x+1<8&&y-2>-1)||(scacchiera[x-1][y-2][3]=='h'&&x-1>-1&&y-2>-1)||
       (scacchiera[x+2][y+1][3]=='h'&&x+2<8&&y+1<8)||(scacchiera[x-2][y+1][3]=='h'&&x-2>-1&&y+1<8)||
       (scacchiera[x+2][y-1][3]=='h'&&x+2<8&&y-1>-1)||(scacchiera[x-2][y-1][3]=='h'&&x-2>-1&&y-1>-1)){
            return 1;}
  for(x=x-1; x>-1; x--){//sinistra
        if(scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'){
            return 1;}
        if(scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x=x+1; x<8; x++){//destra
        if(scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'){
            return 1;}
        if(scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(y=y+1; y<8; y++){//su
        if(scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'){
            return 1;}
        if(scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
           x= X; y= Y; break;}}
  x= X; y= Y;
  for(y=y-1; y>-1; y--){//giu
        if(scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'){
            return 1;}
        if(scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){//diagonale sinistra giu
        if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){
            return 1;}
        if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){//diagonale destra giu
        if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){
            return 1;}
        if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x+1, y= y+1; x<8&&y<8; x++, y++){//diagonale destra su
        if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){
            return 1;}
        if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x-1, y= y+1; x>-1&&y<8; x--, y++){//diagonale sinistra su
        if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){
            return 1;}
        if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
return 0;}

int verifica_scacco_renero(char scacchiera[8][8][4]){
  int x, y, X, Y;
  for(Y=7; Y>-1; Y--){//rintraccia re nero
    for(X=0; X<8; X++){
        if(scacchiera[X][Y][3]=='k'||scacchiera[X][Y][3]=='d'){
            x= X; y= Y;}}}
  X= x; Y= y;
  if(x+1<8&&y-1>-1&&(scacchiera[x+1][y-1][3]=='P'||scacchiera[x+1][y-1][3]=='K'||scacchiera[x+1][y-1][3]=='D')){//pedoni e re
            return 1;}
  if(x-1>-1&&y-1>-1&&(scacchiera[x-1][y-1][3]=='P'||scacchiera[x-1][y-1][3]=='K'||scacchiera[x-1][y-1][3]=='D')){
            return 1;}
  if(x+1<8&&y+1<8&&(scacchiera[x+1][y+1][3]=='K'||scacchiera[x+1][y+1][3]=='D')){
            return 1;}
  if(x-1>-1&&y+1<8&&(scacchiera[x-1][y+1][3]=='K'||scacchiera[x-1][y+1][3]=='D')){
            return 1;}
  if(x+1<8&&(scacchiera[x+1][y][3]=='K'||scacchiera[x+1][y][3]=='D')){
            return 1;}
  if(x-1>-1&&(scacchiera[x-1][y][3]=='K'||scacchiera[x-1][y][3]=='D')){
            return 1;}
  if(y+1<8&&(scacchiera[x][y+1][3]=='K'||scacchiera[x][y+1][3]=='D')){
            return 1;}
  if(y-1>-1&&(scacchiera[x][y-1][3]=='K'||scacchiera[x][y-1][3]=='D')){
            return 1;}
//cavllo
  if((scacchiera[x+1][y+2][3]=='H'&&x+1<8&&y+2<8)||(scacchiera[x-1][y+2][3]=='H'&&x-1>-1&&y+2<8)||
       (scacchiera[x+1][y-2][3]=='H'&&x+1<8&&y-2>-1)||(scacchiera[x-1][y-2][3]=='H'&&x-1>-1&&y-2>-1)||
       (scacchiera[x+2][y+1][3]=='H'&&x+2<8&&y+1<8)||(scacchiera[x-2][y+1][3]=='H'&&x-2>-1&&y+1<8)||
       (scacchiera[x+2][y-1][3]=='H'&&x+2<8&&y-1>-1)||(scacchiera[x-2][y-1][3]=='H'&&x-2>-1&&y-1>-1)){
            return 1;}
  for(x=x-1; x>-1; x--){//sinistra
        if(scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'){
            return 1;}
        if(scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x=x+1; x<8; x++){//destra
        if(scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'){
            return 1;}
        if(scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(y=y+1; y<8; y++){//su
        if(scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'){
            return 1;}
        if(scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
           x= X; y= Y; break;}}
  x= X; y= Y;
  for(y=y-1; y>-1; y--){//giu
        if(scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'){
            return 1;}
        if(scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){//diagonale sinistra giu
        if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){
            return 1;}
        if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){//diagonale destra giu
        if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){
            return 1;}
        if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x+1, y= y+1; x<8&&y<8; x++, y++){//diagonale destra su
        if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){
            return 1;}
        if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x-1, y= y+1; x>-1&&y<8; x--, y++){//diagonale sinistra su
        if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){
            return 1;}
        if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
return 0;}

int verifica_mossa_esistenza (char move[5]){
  if(!((move[0]>='a')&&(move[0]<='h'))||!((move[1]>='1')&(move[1]<='8'))||!((move[2]>='a')&&(move[2]<='h'))||!((move[3]>='1')&(move[3]<='8'))||(move[4]!='\0')){
    return 0;}
  else{
    return 1;}}

int verifica_mossa_pedonebianco (char scacchiera[8][8][4], char move[5]){
  int x, y;
  x= move[2]-'a'; y= move[3]-'1';
  if(move[0]==move[2]){//va avanti
    if((scacchiera[x][y][3]=='f')&&move[1]==move[3]-1){
        return 1;}
    if((scacchiera[x][y][3]=='f'&&scacchiera[x][y-1][3]=='f')&&move[1]==move[3]-2&&y==3){
        return 1;}}
  if((move[0]==move[2]+1||move[0]==move[2]-1)&&(move[1]==move[3]-1)&&
     (scacchiera[x][y][3]=='e'||scacchiera[x][y][3]=='p'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='h'||
     scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='b')){
            return 1;}
  return 0;}

int verifica_mossa_pedonenero (char scacchiera[8][8][4], char move[5]){
  int x, y;
  x= move[2]-'a'; y= move[3]-'1';
  if(move[0]==move[2]){//va avanti
    if((scacchiera[x][y][3]=='f')&&move[1]==move[3]+1){
        return 1;}
    if((scacchiera[x][y][3]=='f'&&scacchiera[x][y+1][3]=='f')&&move[1]==move[3]+2&&y==4){
        return 1;}}
  if((move[0]==move[2]+1||move[0]==move[2]-1)&&(move[1]==move[3]+1)&&
     (scacchiera[x][y][3]=='E'||scacchiera[x][y][3]=='P'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='H'||
     scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='B')){
            return 1;}
  return 0;}

int verifica_mossa_cavallobianco (char scacchiera[8][8][4], char move[5]){
  int x, y;
  x= move[2]-'a'; y= move[3]-'1';
  if((scacchiera[x][y][3]=='f'||scacchiera[x][y][3]=='e'||scacchiera[x][y][3]=='p'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='E'||
      scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='h'||scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='b')&&(((move[0]==move[2]+1||move[0]==move[2]-1)&&(move[1]==move[3]+2||move[1]==move[3]-2))||
     ((move[1]==move[3]+1||move[1]==move[3]-1)&&(move[0]==move[2]+2||move[0]==move[2]-2)))){
        return 1;}
  return 0;}

int verifica_mossa_cavallonero (char scacchiera[8][8][4], char move[5]){
  int x, y;
  x= move[2]-'a'; y= move[3]-'1';
  if((scacchiera[x][y][3]=='f'||scacchiera[x][y][3]=='e'||scacchiera[x][y][3]=='P'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='E'||
      scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='H'||scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='B')&&(((move[0]==move[2]+1||move[0]==move[2]-1)&&(move[1]==move[3]+2||move[1]==move[3]-2))||
     ((move[1]==move[3]+1||move[1]==move[3]-1)&&(move[0]==move[2]+2||move[0]==move[2]-2)))){
        return 1;}
  return 0;}

int verifica_mossa_alfierebianco (char scacchiera[8][8][4], char move[5]){
  int x, y, a;
  a= abs(move[0]-move[2]);
  x= move[0]-'a'; y= move[1]-'1';
  if(abs(move[0]-move[2])==abs(move[1]-move[3])&&move[0]!=move[2]){
    if(move[0]-move[2]<0&&move[1]-move[3]<0){//diagonale alto-destra
        for(; a>1; a--){//controllo pedine tra pos. iniziale e finale
            x++; y++;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'){
                return 0;}}
        x++; y++;//controllo destinazione
        if(scacchiera[x][y][3]=='P'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='H'||
           scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='K'||scacchiera[x][y][3]=='D'){
           return 0;}
        return 1;}
    if(move[0]-move[2]>0&&move[1]-move[3]<0){//diagonale alto-sinistra
        for(; a>1; a--){//controllo pedine tra pos. iniziale e finale
            x--; y++;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'){
                return 0;}}
        x--; y++;//controllo destinazione
        if(scacchiera[x][y][3]=='P'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='H'||
           scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='K'||scacchiera[x][y][3]=='D'){
           return 0;}
        return 1;}
    if(move[0]-move[2]>0&&move[1]-move[3]>0){//diagonale basso-sinistra
        for(; a>1; a--){//controllo pedine tra pos. iniziale e finale
            x--; y--;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'){
                return 0;}}
        x--; y--;//controllo destinazione
        if(scacchiera[x][y][3]=='P'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='H'||
           scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='K'||scacchiera[x][y][3]=='D'){
           return 0;}
        return 1;}
    if(move[0]-move[2]<0&&move[1]-move[3]>0){//diagonale basso-destra
        for(; a>1; a--){//controllo pedine tra pos. iniziale e finale
            x++; y--;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'){
                return 0;}}
        x++; y--;//controllo destinazione
        if(scacchiera[x][y][3]=='P'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='H'||
           scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='K'||scacchiera[x][y][3]=='D'){
           return 0;}
        return 1;}}
  return 0;}

int verifica_mossa_alfierenero (char scacchiera[8][8][4], char move[5]){
  int x, y, a;
  a= abs(move[0]-move[2]);
  x= move[0]-'a'; y= move[1]-'1';
  if(abs(move[0]-move[2])==abs(move[1]-move[3])&&move[0]!=move[2]){
    if(move[0]-move[2]<0&&move[1]-move[3]<0){//diagonale alto-destra
        for(; a>1; a--){//controllo pedine tra pos. iniziale e finale
            x++; y++;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='E'){
                return 0;}}
        x++; y++;//controllo destinazione
        if(scacchiera[x][y][3]=='p'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='h'||
           scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='k'||scacchiera[x][y][3]=='d'){
           return 0;}
        return 1;}
    if(move[0]-move[2]>0&&move[1]-move[3]<0){//diagonale alto-sinistra
        for(; a>1; a--){//controllo pedine tra pos. iniziale e finale
            x--; y++;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='E'){
                return 0;}}
        x--; y++;//controllo destinazione
        if(scacchiera[x][y][3]=='p'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='h'||
           scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='k'||scacchiera[x][y][3]=='d'){
           return 0;}
        return 1;}
    if(move[0]-move[2]>0&&move[1]-move[3]>0){//diagonale basso-sinistra
        for(; a>1; a--){//controllo pedine tra pos. iniziale e finale
            x--; y--;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='E'){
                return 0;}}
        x--; y--;//controllo destinazione
        if(scacchiera[x][y][3]=='p'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='h'||
           scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='k'||scacchiera[x][y][3]=='d'){
           return 0;}
        return 1;}
    if(move[0]-move[2]<0&&move[1]-move[3]>0){//diagonale basso-destra
        for(; a>1; a--){//controllo pedine tra pos. iniziale e finale
            x++; y--;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='E'){
                return 0;}}
        x++; y--;//controllo destinazione
        if(scacchiera[x][y][3]=='p'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='h'||
           scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='k'||scacchiera[x][y][3]=='d'){
           return 0;}
        return 1;}}
  return 0;}

int verifica_mossa_torrebianca (char scacchiera[8][8][4], char move[5]){
  int x, y, a, b;
  a= abs(move[0]-move[2]); b= abs(move[1]-move[3]);//a= orizzontale, b= verticale
  x= move[0]-'a'; y= move[1]-'1';
  if((move[0]==move[2])^(move[1]==move[3])){
    if(move[0]-move[2]<0){//destra
        for(; a>1; a--){
            x++;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'){
                return 0;}}
         x++;//controllo destinazione
        if(scacchiera[x][y][3]=='P'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='H'||
           scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='K'||scacchiera[x][y][3]=='D'){
           return 0;}
        return 1;}
    if(move[0]-move[2]>0){//sinistra
        for(; a>1; a--){
            x--;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'){
                return 0;}}
         x--;//controllo destinazione
        if(scacchiera[x][y][3]=='P'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='H'||
           scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='K'||scacchiera[x][y][3]=='D'){
           return 0;}
        return 1;}
    if(move[1]-move[3]<0){//alto
        for(; b>1; b--){
            y++;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'){
                return 0;}}
         y++;//controllo destinazione
        if(scacchiera[x][y][3]=='P'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='H'||
           scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='K'||scacchiera[x][y][3]=='D'){
           return 0;}
        return 1;}
    if(move[1]-move[3]>0){//basso
        for(; b>1; b--){
            y--;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'){
                return 0;}}
         y--;//controllo destinazione
        if(scacchiera[x][y][3]=='P'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='H'||
           scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='K'||scacchiera[x][y][3]=='D'){
           return 0;}
        return 1;}}
  return 0;}

int verifica_mossa_torrenera (char scacchiera[8][8][4], char move[5]){
  int x, y, a, b;
  a= abs(move[0]-move[2]); b= abs(move[1]-move[3]);//a= orizzontale, b= verticale
  x= move[0]-'a'; y= move[1]-'1';
  if((move[0]==move[2])^(move[1]==move[3])){
    if(move[0]-move[2]<0){//destra
        for(; a>1; a--){
            x++;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='E'){
                return 0;}}
         x++;//controllo destinazione
        if(scacchiera[x][y][3]=='p'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='h'||
           scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='k'||scacchiera[x][y][3]=='d'){
           return 0;}
        return 1;}
    if(move[0]-move[2]>0){//sinistra
        for(; a>1; a--){
            x--;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='E'){
                return 0;}}
         x--;//controllo destinazione
        if(scacchiera[x][y][3]=='p'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='h'||
           scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='k'||scacchiera[x][y][3]=='d'){
           return 0;}
        return 1;}
    if(move[1]-move[3]<0){//alto
        for(; b>1; b--){
            y++;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='E'){
                return 0;}}
         y++;//controllo destinazione
        if(scacchiera[x][y][3]=='p'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='h'||
           scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='k'||scacchiera[x][y][3]=='d'){
           return 0;}
        return 1;}
    if(move[1]-move[3]>0){//basso
        for(; b>1; b--){
            y--;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='E'){
                return 0;}}
         y--;//controllo destinazione
        if(scacchiera[x][y][3]=='p'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='h'||
           scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='k'||scacchiera[x][y][3]=='d'){
           return 0;}
        return 1;}}
  return 0;}

int verifica_mossa_reginabianca (char scacchiera[8][8][4], char move[5]){
  int x, y, a, b;
  a= abs(move[0]-move[2]); b= abs(move[1]-move[3]);//a= orizzontale/diagonale, b= verticale
  x= move[0]-'a'; y= move[1]-'1';
  if(abs(move[0]-move[2])==abs(move[1]-move[3])&&move[0]!=move[2]){
    if(move[0]-move[2]<0&&move[1]-move[3]<0){//diagonale alto-destra
        for(; a>1; a--){//controllo pedine tra pos. iniziale e finale
            x++; y++;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'){
                return 0;}}
        x++; y++;//controllo destinazione
        if(scacchiera[x][y][3]=='P'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='H'||
           scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='K'||scacchiera[x][y][3]=='D'){
           return 0;}
        return 1;}
    if(move[0]-move[2]>0&&move[1]-move[3]<0){//diagonale alto-sinistra
        for(; a>1; a--){//controllo pedine tra pos. iniziale e finale
            x--; y++;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'){
                return 0;}}
        x--; y++;//controllo destinazione
        if(scacchiera[x][y][3]=='P'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='H'||
           scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='K'||scacchiera[x][y][3]=='D'){
           return 0;}
        return 1;}
    if(move[0]-move[2]>0&&move[1]-move[3]>0){//diagonale basso-sinistra
        for(; a>1; a--){//controllo pedine tra pos. iniziale e finale
            x--; y--;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'){
                return 0;}}
        x--; y--;//controllo destinazione
        if(scacchiera[x][y][3]=='P'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='H'||
           scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='K'||scacchiera[x][y][3]=='D'){
           return 0;}
        return 1;}
    if(move[0]-move[2]<0&&move[1]-move[3]>0){//diagonale basso-destra
        for(; a>1; a--){//controllo pedine tra pos. iniziale e finale
            x++; y--;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'){
                return 0;}}
        x++; y--;//controllo destinazione
        if(scacchiera[x][y][3]=='P'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='H'||
           scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='K'||scacchiera[x][y][3]=='D'){
           return 0;}
        return 1;}}
  if((move[0]==move[2])^(move[1]==move[3])){
    if(move[0]-move[2]<0){//destra
        for(; a>1; a--){
            x++;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'){
                return 0;}}
         x++;//controllo destinazione
        if(scacchiera[x][y][3]=='P'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='H'||
           scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='K'||scacchiera[x][y][3]=='D'){
           return 0;}
        return 1;}
    if(move[0]-move[2]>0){//sinistra
        for(; a>1; a--){
            x--;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'){
                return 0;}}
         x--;//controllo destinazione
        if(scacchiera[x][y][3]=='P'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='H'||
           scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='K'||scacchiera[x][y][3]=='D'){
           return 0;}
        return 1;}
    if(move[1]-move[3]<0){//alto
        for(; b>1; b--){
            y++;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'){
                return 0;}}
         y++;//controllo destinazione
        if(scacchiera[x][y][3]=='P'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='H'||
           scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='K'||scacchiera[x][y][3]=='D'){
           return 0;}
        return 1;}
    if(move[1]-move[3]>0){//basso
        for(; b>1; b--){
            y--;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'){
                return 0;}}
         y--;//controllo destinazione
        if(scacchiera[x][y][3]=='P'||scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='H'||
           scacchiera[x][y][3]=='Q'||scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='K'||scacchiera[x][y][3]=='D'){
           return 0;}
        return 1;}}
  return 0;}

int verifica_mossa_reginanera (char scacchiera[8][8][4], char move[5]){
  int x, y, a, b;
  a= abs(move[0]-move[2]); b= abs(move[1]-move[3]);//a= orizzontale/diagonale, b= verticale
  x= move[0]-'a'; y= move[1]-'1';
  if(abs(move[0]-move[2])==abs(move[1]-move[3])&&move[0]!=move[2]){
    if(move[0]-move[2]<0&&move[1]-move[3]<0){//diagonale alto-destra
        for(; a>1; a--){//controllo pedine tra pos. iniziale e finale
            x++; y++;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='E'){
                return 0;}}
        x++; y++;//controllo destinazione
        if(scacchiera[x][y][3]=='p'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='h'||
           scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='k'||scacchiera[x][y][3]=='d'){
           return 0;}
        return 1;}
    if(move[0]-move[2]>0&&move[1]-move[3]<0){//diagonale alto-sinistra
        for(; a>1; a--){//controllo pedine tra pos. iniziale e finale
            x--; y++;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='E'){
                return 0;}}
        x--; y++;//controllo destinazione
        if(scacchiera[x][y][3]=='p'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='h'||
           scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='k'||scacchiera[x][y][3]=='d'){
           return 0;}
        return 1;}
    if(move[0]-move[2]>0&&move[1]-move[3]>0){//diagonale basso-sinistra
        for(; a>1; a--){//controllo pedine tra pos. iniziale e finale
            x--; y--;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='E'){
                return 0;}}
        x--; y--;//controllo destinazione
        if(scacchiera[x][y][3]=='p'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='h'||
           scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='k'||scacchiera[x][y][3]=='d'){
           return 0;}
        return 1;}
    if(move[0]-move[2]<0&&move[1]-move[3]>0){//diagonale basso-destra
        for(; a>1; a--){//controllo pedine tra pos. iniziale e finale
            x++; y--;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='E'){
                return 0;}}
        x++; y--;//controllo destinazione
        if(scacchiera[x][y][3]=='p'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='h'||
           scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='k'||scacchiera[x][y][3]=='d'){
           return 0;}
        return 1;}}
  if((move[0]==move[2])^(move[1]==move[3])){
    if(move[0]-move[2]<0){//destra
        for(; a>1; a--){
            x++;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='E'){
                return 0;}}
         x++;//controllo destinazione
        if(scacchiera[x][y][3]=='p'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='h'||
           scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='k'||scacchiera[x][y][3]=='d'){
           return 0;}
        return 1;}
    if(move[0]-move[2]>0){//sinistra
        for(; a>1; a--){
            x--;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='E'){
                return 0;}}
         x--;//controllo destinazione
        if(scacchiera[x][y][3]=='p'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='h'||
           scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='k'||scacchiera[x][y][3]=='d'){
           return 0;}
        return 1;}
    if(move[1]-move[3]<0){//alto
        for(; b>1; b--){
            y++;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='E'){
                return 0;}}
         y++;//controllo destinazione
        if(scacchiera[x][y][3]=='p'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='h'||
           scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='k'||scacchiera[x][y][3]=='d'){
           return 0;}
        return 1;}
    if(move[1]-move[3]>0){//basso
        for(; b>1; b--){
            y--;
            if(scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='E'){
                return 0;}}
         y--;//controllo destinazione
        if(scacchiera[x][y][3]=='p'||scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='h'||
           scacchiera[x][y][3]=='q'||scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='k'||scacchiera[x][y][3]=='d'){
           return 0;}
        return 1;}}
  return 0;}

int verifica_mossa_rebianco (char scacchiera[8][8][4], char move[5]){
  int x, y, xf, yf;
  x= move[0]-'a'; y= move[1]-'1'; xf= move[2]-'a'; yf= move[3]-'1';
  if(abs(move[0]-move[2])<2&&abs(move[1]-move[3])<2&&(scacchiera[xf][yf][3]=='f'||scacchiera[xf][yf][3]=='p'||scacchiera[xf][yf][3]=='h'||
     scacchiera[xf][yf][3]=='r'||scacchiera[xf][yf][3]=='t'||scacchiera[xf][yf][3]=='q'||scacchiera[xf][yf][3]=='b'||scacchiera[xf][yf][3]=='e')){
     return 1;}
  if(scacchiera[x][y][3]=='K'&&scacchiera[xf][yf][3]=='R'){
    if(xf==0&&scacchiera[x-1][y][3]=='f'&&scacchiera[x-2][y][3]=='f'&&scacchiera[x-3][y][3]=='f'&&
       !verifica_visione_casellabianca(scacchiera, x, y)&&!verifica_visione_casellabianca(scacchiera, x-1, y)&&
       !verifica_visione_casellabianca(scacchiera, x-2, y)&&!verifica_visione_casellabianca(scacchiera, x-3, y)){
        return 1;}
    if(xf==7&&scacchiera[x+1][y][3]=='f'&&scacchiera[x+2][y][3]=='f'&&
       !verifica_visione_casellabianca(scacchiera, x, y)&&!verifica_visione_casellabianca(scacchiera, x+1, y)&&
       !verifica_visione_casellabianca(scacchiera, x+2, y)){
        return 1;}}
  return 0;}

int verifica_mossa_renero (char scacchiera[8][8][4], char move[5]){
  int x, y, xf, yf;
  x= move[0]-'a'; y= move[1]-'1'; xf= move[2]-'a'; yf= move[3]-'1';
  if(abs(move[0]-move[2])<2&&abs(move[1]-move[3])<2&&(scacchiera[xf][yf][3]=='f'||scacchiera[xf][yf][3]=='P'||scacchiera[xf][yf][3]=='H'||
     scacchiera[xf][yf][3]=='R'||scacchiera[xf][yf][3]=='T'||scacchiera[xf][yf][3]=='Q'||scacchiera[xf][yf][3]=='B'||scacchiera[xf][yf][3]=='e')){
     return 1;}
  if(scacchiera[x][y][3]=='k'&&scacchiera[xf][yf][3]=='r'){
    if(xf==0&&scacchiera[x-1][y][3]=='f'&&scacchiera[x-2][y][3]=='f'&&scacchiera[x-3][y][3]=='f'&&
       !verifica_visione_casellanera(scacchiera, x, y)&&!verifica_visione_casellanera(scacchiera, x-1, y)&&
       !verifica_visione_casellanera(scacchiera, x-2, y)&&!verifica_visione_casellanera(scacchiera, x-3, y)){
        return 1;}
    if(xf==7&&scacchiera[x+1][y][3]=='f'&&scacchiera[x+2][y][3]=='f'&&
       !verifica_visione_casellanera(scacchiera, x, y)&&!verifica_visione_casellanera(scacchiera, x+1, y)&&
       !verifica_visione_casellanera(scacchiera, x+2, y)){
        return 1;}}
  return 0;}

int verifica_drawbyrepetition(char scacchieraprecedentesima[8][8][4], char scacchierattuale[8][8][4]){
int x, y;
for(y=7; y>-1; y--){
    for(x=0; x<8; x++){
        if(scacchierattuale[x][y][3]!=scacchieraprecedentesima[x][y][3])
            return 0;}}
return 1;}

int verifica_drawbymaterial(char scacchiera[8][8][4]){
int x, y, h= 0, b= 0, p= 0, q= 0, r= 0, H= 0, B= 0, P= 0, Q= 0, R= 0;
for(y=7; y>-1; y--){
    for(x=0; x<8; x++){
       switch(scacchiera[x][y][3]){
       case 'p': p++; break;
       case 'P': P++; break;
       case 'h': h++; break;
       case 'H': H++; break;
       case 'b': b++; break;
       case 'B': B++; break;
       case 'r': r++; break;
       case 'R': R++; break;
       case 'q': q++; break;
       case 'Q': Q++; break;}}}
if((p==0&&h<2&&b==0&&q==0&&r==0&&P==0&&H<2&&B==0&&Q==0&&R==0)||(p==0&&h==0&&b<2&&q==0&&r==0&&P==0&&H==0&&B<2&&Q==0&&R==0)||
   (p==0&&h==0&&b<2&&q==0&&r==0&&P==0&&H<2&&B==0&&Q==0&&R==0)||(p==0&&h<2&&b==0&&q==0&&r==0&&P==0&&H==0&&B<2&&Q==0&&R==0)){
    return 1;}
return 0;}

int verifica_stalematebianco(char scacchiera[8][8][4]){
int X, Y, x, y;
for(Y=7; Y>-1; Y--){//rintraccia re bianco
    for(X=0; X<8; X++){
        if(scacchiera[X][Y][3]=='K'||scacchiera[X][Y][3]=='D'){
            x= X; y= Y;}}}
X= x; Y= y; //controllo vie di fuga re
if((x+1>7||verifica_visione_casellabianca(scacchiera, x+1, y)||scacchiera[x+1][y][3]=='P'||scacchiera[x+1][y][3]=='H'||scacchiera[x+1][y][3]=='B'||scacchiera[x+1][y][3]=='Q'||scacchiera[x+1][y][3]=='T'||scacchiera[x+1][y][3]=='R')&&
   (x-1<0||verifica_visione_casellabianca(scacchiera, x-1, y)||scacchiera[x-1][y][3]=='P'||scacchiera[x-1][y][3]=='H'||scacchiera[x-1][y][3]=='B'||scacchiera[x-1][y][3]=='Q'||scacchiera[x-1][y][3]=='T'||scacchiera[x-1][y][3]=='R')&&
   (y+1>7||verifica_visione_casellabianca(scacchiera, x, y+1)||scacchiera[x][y+1][3]=='P'||scacchiera[x][y+1][3]=='H'||scacchiera[x][y+1][3]=='B'||scacchiera[x][y+1][3]=='Q'||scacchiera[x][y+1][3]=='T'||scacchiera[x][y+1][3]=='R')&&
   (y-1<0||verifica_visione_casellabianca(scacchiera, x, y-1)||scacchiera[x][y-1][3]=='P'||scacchiera[x][y-1][3]=='H'||scacchiera[x][y-1][3]=='B'||scacchiera[x][y-1][3]=='Q'||scacchiera[x][y-1][3]=='T'||scacchiera[x][y-1][3]=='R')&&
   (x+1>7||y+1>7||verifica_visione_casellabianca(scacchiera, x+1, y+1)||scacchiera[x+1][y+1][3]=='P'||scacchiera[x+1][y+1][3]=='H'||scacchiera[x+1][y+1][3]=='B'||scacchiera[x+1][y+1][3]=='Q'||scacchiera[x+1][y+1][3]=='T'||scacchiera[x+1][y+1][3]=='R')&&
   (x-1<0||y-1<0||verifica_visione_casellabianca(scacchiera, x-1, y-1)||scacchiera[x-1][y-1][3]=='P'||scacchiera[x-1][y-1][3]=='H'||scacchiera[x-1][y-1][3]=='B'||scacchiera[x-1][y-1][3]=='Q'||scacchiera[x-1][y-1][3]=='T'||scacchiera[x-1][y-1][3]=='R')&&
   (x+1>7||y-1<0||verifica_visione_casellabianca(scacchiera, x+1, y-1)||scacchiera[x+1][y-1][3]=='P'||scacchiera[x+1][y-1][3]=='H'||scacchiera[x+1][y-1][3]=='B'||scacchiera[x+1][y-1][3]=='Q'||scacchiera[x+1][y-1][3]=='T'||scacchiera[x+1][y-1][3]=='R')&&
   (x-1<0||y+1>7||verifica_visione_casellabianca(scacchiera, x-1, y+1)||scacchiera[x-1][y+1][3]=='P'||scacchiera[x-1][y+1][3]=='H'||scacchiera[x-1][y+1][3]=='B'||scacchiera[x-1][y+1][3]=='Q'||scacchiera[x-1][y+1][3]=='T'||scacchiera[x-1][y+1][3]=='R')){
      for(Y=7; Y>-1; Y--){//controllo mosse legali
         for(X=0; X<8; X++){
            if(!verifica_inchiodatura_assolutabianco(scacchiera, X, Y)){
               return 0;}
               }}
                if(!verifica_scacco_rebianco(scacchiera)){
                   return 1; }}
return 0;}

int verifica_stalematenero(char scacchiera[8][8][4]){
int X, Y, x, y;
for(Y=7; Y>-1; Y--){//rintraccia re nero
    for(X=0; X<8; X++){
        if(scacchiera[X][Y][3]=='k'||scacchiera[X][Y][3]=='d'){
            x= X; y= Y;}}}
X= x; Y= y; //controllo vie di fuga re
if((x+1>7||verifica_visione_casellabianca(scacchiera, x+1, y)||scacchiera[x+1][y][3]=='p'||scacchiera[x+1][y][3]=='h'||scacchiera[x+1][y][3]=='b'||scacchiera[x+1][y][3]=='q'||scacchiera[x+1][y][3]=='t'||scacchiera[x+1][y][3]=='r')&&
   (x-1<0||verifica_visione_casellabianca(scacchiera, x-1, y)||scacchiera[x-1][y][3]=='p'||scacchiera[x-1][y][3]=='h'||scacchiera[x-1][y][3]=='b'||scacchiera[x-1][y][3]=='q'||scacchiera[x-1][y][3]=='t'||scacchiera[x-1][y][3]=='r')&&
   (y+1>7||verifica_visione_casellabianca(scacchiera, x, y+1)||scacchiera[x][y+1][3]=='p'||scacchiera[x][y+1][3]=='h'||scacchiera[x][y+1][3]=='b'||scacchiera[x][y+1][3]=='q'||scacchiera[x][y+1][3]=='t'||scacchiera[x][y+1][3]=='r')&&
   (y-1<0||verifica_visione_casellabianca(scacchiera, x, y-1)||scacchiera[x][y-1][3]=='p'||scacchiera[x][y-1][3]=='h'||scacchiera[x][y-1][3]=='b'||scacchiera[x][y-1][3]=='q'||scacchiera[x][y-1][3]=='t'||scacchiera[x][y-1][3]=='r')&&
   (x+1>7||y+1>7||verifica_visione_casellabianca(scacchiera, x+1, y+1)||scacchiera[x+1][y+1][3]=='p'||scacchiera[x+1][y+1][3]=='h'||scacchiera[x+1][y+1][3]=='b'||scacchiera[x+1][y+1][3]=='q'||scacchiera[x+1][y+1][3]=='t'||scacchiera[x+1][y+1][3]=='r')&&
   (x-1<0||y-1<0||verifica_visione_casellabianca(scacchiera, x-1, y-1)||scacchiera[x-1][y-1][3]=='p'||scacchiera[x-1][y-1][3]=='h'||scacchiera[x-1][y-1][3]=='b'||scacchiera[x-1][y-1][3]=='q'||scacchiera[x-1][y-1][3]=='t'||scacchiera[x-1][y-1][3]=='r')&&
   (x+1>7||y-1<0||verifica_visione_casellabianca(scacchiera, x+1, y-1)||scacchiera[x+1][y-1][3]=='p'||scacchiera[x+1][y-1][3]=='h'||scacchiera[x+1][y-1][3]=='b'||scacchiera[x+1][y-1][3]=='q'||scacchiera[x+1][y-1][3]=='t'||scacchiera[x+1][y-1][3]=='r')&&
   (x-1<0||y+1>7||verifica_visione_casellabianca(scacchiera, x-1, y+1)||scacchiera[x-1][y+1][3]=='p'||scacchiera[x-1][y+1][3]=='h'||scacchiera[x-1][y+1][3]=='b'||scacchiera[x-1][y+1][3]=='q'||scacchiera[x-1][y+1][3]=='t'||scacchiera[x-1][y+1][3]=='r')){
      for(Y=7; Y>-1; Y--){//controllo mosse legali
         for(X=0; X<8; X++){
            if(!verifica_inchiodatura_assolutanero(scacchiera, X, Y)){
               return 0;}
               }}
                if(!verifica_scacco_renero(scacchiera)){
                   return 1; }}
return 0;}

int verifica_scaccomattoalbianco(char scacchiera[8][8][4]){
int x, y, X, Y, xs, ys, n= 0, a;
char natura;
  for(Y=7; Y>-1; Y--){//rintraccia re bianco
    for(X=0; X<8; X++){
        if(scacchiera[X][Y][3]=='K'||scacchiera[X][Y][3]=='D'){
            x= X; y= Y;}}}
  X= x; Y= y;
  if(x+1<8&&y+1<8&&(scacchiera[x+1][y+1][3]=='p')){//pedone
            n++; xs=x+1; ys=y+1; natura='p';}
  if(x-1>-1&&y+1<8&&(scacchiera[x-1][y+1][3]=='p')){
            n++; xs=x-1; ys=y+1; natura='p';}
//cavallo
  if(scacchiera[x+1][y+2][3]=='h'&&x+1<8&&y+2<8){
     n++; xs=x+1; ys=y+2; natura='h';}
  if(scacchiera[x-1][y+2][3]=='h'&&x-1>-1&&y+2<8){
     n++; xs=x-1; ys=y+2; natura='h';}
  if(scacchiera[x+1][y-2][3]=='h'&&x+1<8&&y-2>-1){
     n++; xs=x+1; ys=y-2; natura='h';}
  if(scacchiera[x-1][y-2][3]=='h'&&x-1>-1&&y-2>-1){
     n++; xs=x-1; ys=y-2; natura='h';}
  if(scacchiera[x+2][y+1][3]=='h'&&x+2<8&&y+1<8){
     n++; xs=x+2; ys=y+1; natura='h';}
  if(scacchiera[x-2][y+1][3]=='h'&&x-2>-1&&y+1<8){
     n++; xs=x-2; ys=y+1; natura='h';}
  if(scacchiera[x+2][y-1][3]=='h'&&x+2<8&&y-1>-1){
     n++; xs=x+2; ys=y-1; natura='h';}
  if(scacchiera[x-2][y-1][3]=='h'&&x-2>-1&&y-1>-1){
     n++; xs=x-2; ys=y-1; natura='h';}

  for(x=x-1; x>-1; x--){//sinistra
        if(scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'){
            n++; xs=x; ys=y; natura='r';}
        if(scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x=x+1; x<8; x++){//destra
        if(scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'){
            n++; xs=x; ys=y; natura='r';}
        if(scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(y=y+1; y<8; y++){//su
        if(scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'){
            n++; xs=x; ys=y; natura='r';}
        if(scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
           x= X; y= Y; break;}}
  x= X; y= Y;
  for(y=y-1; y>-1; y--){//giu
        if(scacchiera[x][y][3]=='r'||scacchiera[x][y][3]=='t'||scacchiera[x][y][3]=='q'){
            n++; xs=x; ys=y; natura='r';}
        if(scacchiera[x][y][3]!='r'&&scacchiera[x][y][3]!='t'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){//diagonale sinistra giu
        if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){
            n++; xs=x; ys=y; natura='b';}
        if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){//diagonale destra giu
        if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){
            n++; xs=x; ys=y; natura='b';}
        if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x+1, y= y+1; x<8&&y<8; x++, y++){//diagonale destra su
        if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){
            n++; xs=x; ys=y; natura='b';}
        if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x-1, y= y+1; x>-1&&y<8; x--, y++){//diagonale sinistra su
        if(scacchiera[x][y][3]=='b'||scacchiera[x][y][3]=='q'){
            n++; xs=x; ys=y; natura='b';}
        if(scacchiera[x][y][3]!='b'&&scacchiera[x][y][3]!='q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  X= x; Y= y;
  if(n==0){
    return 0;}
  if(n==2){//doppio scacco, controllo vie di fuga re
     if((x+1>7||verifica_visione_casellabianca(scacchiera, x+1, y)||scacchiera[x+1][y][3]=='P'||scacchiera[x+1][y][3]=='H'||scacchiera[x+1][y][3]=='B'||scacchiera[x+1][y][3]=='Q'||scacchiera[x+1][y][3]=='T'||scacchiera[x+1][y][3]=='R')&&
        (x-1<0||verifica_visione_casellabianca(scacchiera, x-1, y)||scacchiera[x-1][y][3]=='P'||scacchiera[x-1][y][3]=='H'||scacchiera[x-1][y][3]=='B'||scacchiera[x-1][y][3]=='Q'||scacchiera[x-1][y][3]=='T'||scacchiera[x-1][y][3]=='R')&&
        (y+1>7||verifica_visione_casellabianca(scacchiera, x, y+1)||scacchiera[x][y+1][3]=='P'||scacchiera[x][y+1][3]=='H'||scacchiera[x][y+1][3]=='B'||scacchiera[x][y+1][3]=='Q'||scacchiera[x][y+1][3]=='T'||scacchiera[x][y+1][3]=='R')&&
        (y-1<0||verifica_visione_casellabianca(scacchiera, x, y-1)||scacchiera[x][y-1][3]=='P'||scacchiera[x][y-1][3]=='H'||scacchiera[x][y-1][3]=='B'||scacchiera[x][y-1][3]=='Q'||scacchiera[x][y-1][3]=='T'||scacchiera[x][y-1][3]=='R')&&
        (x+1>7||y+1>7||verifica_visione_casellabianca(scacchiera, x+1, y+1)||scacchiera[x+1][y+1][3]=='P'||scacchiera[x+1][y+1][3]=='H'||scacchiera[x+1][y+1][3]=='B'||scacchiera[x+1][y+1][3]=='Q'||scacchiera[x+1][y+1][3]=='T'||scacchiera[x+1][y+1][3]=='R')&&
        (x-1<0||y-1<0||verifica_visione_casellabianca(scacchiera, x-1, y-1)||scacchiera[x-1][y-1][3]=='P'||scacchiera[x-1][y-1][3]=='H'||scacchiera[x-1][y-1][3]=='B'||scacchiera[x-1][y-1][3]=='Q'||scacchiera[x-1][y-1][3]=='T'||scacchiera[x-1][y-1][3]=='R')&&
        (x+1>7||y-1<0||verifica_visione_casellabianca(scacchiera, x+1, y-1)||scacchiera[x+1][y-1][3]=='P'||scacchiera[x+1][y-1][3]=='H'||scacchiera[x+1][y-1][3]=='B'||scacchiera[x+1][y-1][3]=='Q'||scacchiera[x+1][y-1][3]=='T'||scacchiera[x+1][y-1][3]=='R')&&
        (x-1<0||y+1>7||verifica_visione_casellabianca(scacchiera, x-1, y+1)||scacchiera[x-1][y+1][3]=='P'||scacchiera[x-1][y+1][3]=='H'||scacchiera[x-1][y+1][3]=='B'||scacchiera[x-1][y+1][3]=='Q'||scacchiera[x-1][y+1][3]=='T'||scacchiera[x-1][y+1][3]=='R')){
            return 1;}
     return 0;}

  if(n==1){//controllo vie di fuga re
     if((x+1>7||verifica_visione_casellabianca(scacchiera, x+1, y)||scacchiera[x+1][y][3]=='P'||scacchiera[x+1][y][3]=='H'||scacchiera[x+1][y][3]=='B'||scacchiera[x+1][y][3]=='Q'||scacchiera[x+1][y][3]=='T'||scacchiera[x+1][y][3]=='R')&&
        (x-1<0||verifica_visione_casellabianca(scacchiera, x-1, y)||scacchiera[x-1][y][3]=='P'||scacchiera[x-1][y][3]=='H'||scacchiera[x-1][y][3]=='B'||scacchiera[x-1][y][3]=='Q'||scacchiera[x-1][y][3]=='T'||scacchiera[x-1][y][3]=='R')&&
        (y+1>7||verifica_visione_casellabianca(scacchiera, x, y+1)||scacchiera[x][y+1][3]=='P'||scacchiera[x][y+1][3]=='H'||scacchiera[x][y+1][3]=='B'||scacchiera[x][y+1][3]=='Q'||scacchiera[x][y+1][3]=='T'||scacchiera[x][y+1][3]=='R')&&
        (y-1<0||verifica_visione_casellabianca(scacchiera, x, y-1)||scacchiera[x][y-1][3]=='P'||scacchiera[x][y-1][3]=='H'||scacchiera[x][y-1][3]=='B'||scacchiera[x][y-1][3]=='Q'||scacchiera[x][y-1][3]=='T'||scacchiera[x][y-1][3]=='R')&&
        (x+1>7||y+1>7||verifica_visione_casellabianca(scacchiera, x+1, y+1)||scacchiera[x+1][y+1][3]=='P'||scacchiera[x+1][y+1][3]=='H'||scacchiera[x+1][y+1][3]=='B'||scacchiera[x+1][y+1][3]=='Q'||scacchiera[x+1][y+1][3]=='T'||scacchiera[x+1][y+1][3]=='R')&&
        (x-1<0||y-1<0||verifica_visione_casellabianca(scacchiera, x-1, y-1)||scacchiera[x-1][y-1][3]=='P'||scacchiera[x-1][y-1][3]=='H'||scacchiera[x-1][y-1][3]=='B'||scacchiera[x-1][y-1][3]=='Q'||scacchiera[x-1][y-1][3]=='T'||scacchiera[x-1][y-1][3]=='R')&&
        (x+1>7||y-1<0||verifica_visione_casellabianca(scacchiera, x+1, y-1)||scacchiera[x+1][y-1][3]=='P'||scacchiera[x+1][y-1][3]=='H'||scacchiera[x+1][y-1][3]=='B'||scacchiera[x+1][y-1][3]=='Q'||scacchiera[x+1][y-1][3]=='T'||scacchiera[x+1][y-1][3]=='R')&&
        (x-1<0||y+1>7||verifica_visione_casellabianca(scacchiera, x-1, y+1)||scacchiera[x-1][y+1][3]=='P'||scacchiera[x-1][y+1][3]=='H'||scacchiera[x-1][y+1][3]=='B'||scacchiera[x-1][y+1][3]=='Q'||scacchiera[x-1][y+1][3]=='T'||scacchiera[x-1][y+1][3]=='R')){
            switch(natura){
              case 'p':
                   if(!verifica_visione_pedinanerascacco(scacchiera, xs, ys)){
                      return 1;}
                      return 0;
              case 'h': if(!verifica_visione_pedinanerascacco(scacchiera, xs, ys)){
                         return 1;}
                         return 0;
              case 'r': if(X-xs>0){//minaccia a sinistra
                        for(a= X-xs; a!=0; a--){
                            if(verifica_visione_pedinanerascacco(scacchiera, xs, ys)){
                            return 0;}
                            xs++;}
                            return 1;}

                        if(X-xs<0){//minaccia a destra
                        for(a= xs-X; a!=0; a--){
                            if(verifica_visione_pedinanerascacco(scacchiera, xs, ys)){
                            return 0;}
                            xs--;}
                            return 1;}

                        if(Y-ys>0){//minaccia giu
                        for(a= Y-ys; a!=0; a--){
                            if(verifica_visione_pedinanerascacco(scacchiera, xs, ys)){
                            return 0;}
                            ys++;}
                            return 1;}

                        if(Y-ys<0){//minaccia su
                        for(a= ys-Y; a!=0; a--){
                            if(verifica_visione_pedinanerascacco(scacchiera, xs, ys)){
                            return 0;}
                            ys--;}
                            return 1;}

              case 'b': if(X-xs>0&&Y-ys>0){//minaccia basso sinistra
                        for(a= X-xs; a!=0; a--){
                            if(verifica_visione_pedinanerascacco(scacchiera, xs, ys)){
                            return 0;}
                            ys++; xs++;}
                            return 1;}

                        if(X-xs<0&&Y-ys<0){//minaccia a destra
                        for(a= xs-X; a!=0; a--){
                            if(verifica_visione_pedinanerascacco(scacchiera, xs, ys)){
                            return 0;}
                            xs--;
                            ys--;}
                            return 1;}

                        if(X-xs>0&&Y-ys<0){//minaccia su sinistra
                        for(a= X-xs; a!=0; a--){
                            if(verifica_visione_pedinanerascacco(scacchiera, xs, ys)){
                            return 0;}
                            xs++; ys--;}
                            return 1;}

                        if(X-xs<0&&Y-ys>0){//minaccia giu sinistra
                        for(a= xs-X; a!=0; a--){
                            if(verifica_visione_pedinanerascacco(scacchiera, xs, ys)){
                            return 0;}
                            xs--; ys++;}
                            return 1;}}
                            }}

else{
        return 0;}
return 0;}

int verifica_scaccomattoalnero(char scacchiera[8][8][4]){
int x, y, X, Y, xs, ys, n= 0, a;
char natura;
  for(Y=7; Y>-1; Y--){//rintraccia re nero
    for(X=0; X<8; X++){
        if(scacchiera[X][Y][3]=='k'||scacchiera[X][Y][3]=='d'){
            x= X; y= Y;}}}
   X= x; Y= y;
  if(x+1<8&&y-1>-1&&(scacchiera[x+1][y-1][3]=='P')){//pedone
            n++; xs=x+1; ys=y-1; natura='P';}
  if(x-1>-1&&y-1>-1&&(scacchiera[x-1][y-1][3]=='P')){
            n++; xs=x-1; ys=y-1; natura='P';}
//cavallo
  if(scacchiera[x+1][y+2][3]=='H'&&x+1<8&&y+2<8){
     n++; xs=x+1; ys=y+2; natura='H';}
  if(scacchiera[x-1][y+2][3]=='H'&&x-1>-1&&y+2<8){
     n++; xs=x-1; ys=y+2; natura='H';}
  if(scacchiera[x+1][y-2][3]=='H'&&x+1<8&&y-2>-1){
     n++; xs=x+1; ys=y-2; natura='H';}
  if(scacchiera[x-1][y-2][3]=='H'&&x-1>-1&&y-2>-1){
     n++; xs=x-1; ys=y-2; natura='H';}
  if(scacchiera[x+2][y+1][3]=='H'&&x+2<8&&y+1<8){
     n++; xs=x+2; ys=y+1; natura='H';}
  if(scacchiera[x-2][y+1][3]=='H'&&x-2>-1&&y+1<8){
     n++; xs=x-2; ys=y+1; natura='H';}
  if(scacchiera[x+2][y-1][3]=='H'&&x+2<8&&y-1>-1){
     n++; xs=x+2; ys=y-1; natura='H';}
  if(scacchiera[x-2][y-1][3]=='H'&&x-2>-1&&y-1>-1){
     n++; xs=x-2; ys=y-1; natura='H';}

  for(x=x-1; x>-1; x--){//sinistra
        if(scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'){
            n++; xs=x; ys=y; natura='R';}
        if(scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x=x+1; x<8; x++){//destra
        if(scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'){
            n++; xs=x; ys=y; natura='R';}
        if(scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(y=y+1; y<8; y++){//su
        if(scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'){
            n++; xs=x; ys=y; natura='R';}
        if(scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
           x= X; y= Y; break;}}
  x= X; y= Y;
  for(y=y-1; y>-1; y--){//giu
        if(scacchiera[x][y][3]=='R'||scacchiera[x][y][3]=='T'||scacchiera[x][y][3]=='Q'){
            n++; xs=x; ys=y; natura='R';}
        if(scacchiera[x][y][3]!='R'&&scacchiera[x][y][3]!='T'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x-1, y= y-1; x>-1&&y>-1; x--, y--){//diagonale sinistra giu
        if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){
            n++; xs=x; ys=y; natura='B';}
        if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x+1, y= y-1; x<8&&y>-1; x++, y--){//diagonale destra giu
        if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){
            n++; xs=x; ys=y; natura='B';}
        if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x+1, y= y+1; x<8&&y<8; x++, y++){//diagonale destra su
        if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){
            n++; xs=x; ys=y; natura='B';}
        if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  x= X; y= Y;
  for(x= x-1, y= y+1; x>-1&&y<8; x--, y++){//diagonale sinistra su
        if(scacchiera[x][y][3]=='B'||scacchiera[x][y][3]=='Q'){
            n++; xs=x; ys=y; natura='B';}
        if(scacchiera[x][y][3]!='B'&&scacchiera[x][y][3]!='Q'&&scacchiera[x][y][3]!='f'&&scacchiera[x][y][3]!='e'&&scacchiera[x][y][3]!='E'){
            x= X; y= Y; break;}}
  if(n==0){
    }
  if(n==2){//doppio scacco, controllo vie di fuga re
     if((x+1>7||verifica_visione_casellanera(scacchiera, x+1, y)||scacchiera[x+1][y][3]=='p'||scacchiera[x+1][y][3]=='h'||scacchiera[x+1][y][3]=='b'||scacchiera[x+1][y][3]=='q'||scacchiera[x+1][y][3]=='t'||scacchiera[x+1][y][3]=='r')&&
        (x-1<0||verifica_visione_casellanera(scacchiera, x-1, y)||scacchiera[x-1][y][3]=='p'||scacchiera[x-1][y][3]=='h'||scacchiera[x-1][y][3]=='b'||scacchiera[x-1][y][3]=='q'||scacchiera[x-1][y][3]=='t'||scacchiera[x-1][y][3]=='r')&&
        (y+1>7||verifica_visione_casellanera(scacchiera, x, y+1)||scacchiera[x][y+1][3]=='p'||scacchiera[x][y+1][3]=='h'||scacchiera[x][y+1][3]=='b'||scacchiera[x][y+1][3]=='q'||scacchiera[x][y+1][3]=='t'||scacchiera[x][y+1][3]=='r')&&
        (y-1<0||verifica_visione_casellanera(scacchiera, x, y-1)||scacchiera[x][y-1][3]=='p'||scacchiera[x][y-1][3]=='h'||scacchiera[x][y-1][3]=='b'||scacchiera[x][y-1][3]=='q'||scacchiera[x][y-1][3]=='t'||scacchiera[x][y-1][3]=='r')&&
        (x+1>7||y+1>7||verifica_visione_casellanera(scacchiera, x+1, y+1)||scacchiera[x+1][y+1][3]=='p'||scacchiera[x+1][y+1][3]=='h'||scacchiera[x+1][y+1][3]=='b'||scacchiera[x+1][y+1][3]=='q'||scacchiera[x+1][y+1][3]=='t'||scacchiera[x+1][y+1][3]=='r')&&
        (x-1<0||y-1<0||verifica_visione_casellanera(scacchiera, x-1, y-1)||scacchiera[x-1][y-1][3]=='p'||scacchiera[x-1][y-1][3]=='h'||scacchiera[x-1][y-1][3]=='b'||scacchiera[x-1][y-1][3]=='q'||scacchiera[x-1][y-1][3]=='t'||scacchiera[x-1][y-1][3]=='r')&&
        (x+1>7||y-1<0||verifica_visione_casellanera(scacchiera, x+1, y-1)||scacchiera[x+1][y-1][3]=='p'||scacchiera[x+1][y-1][3]=='h'||scacchiera[x+1][y-1][3]=='b'||scacchiera[x+1][y-1][3]=='q'||scacchiera[x+1][y-1][3]=='t'||scacchiera[x+1][y-1][3]=='r')&&
        (x-1<0||y+1>7||verifica_visione_casellanera(scacchiera, x-1, y+1)||scacchiera[x-1][y+1][3]=='p'||scacchiera[x-1][y+1][3]=='h'||scacchiera[x-1][y+1][3]=='b'||scacchiera[x-1][y+1][3]=='q'||scacchiera[x-1][y+1][3]=='t'||scacchiera[x-1][y+1][3]=='r')){
            return 1;}
     return 0;}

  if(n==1){//controllo vie di fuga re
     if((x+1>7||verifica_visione_casellanera(scacchiera, x+1, y)||scacchiera[x+1][y][3]=='p'||scacchiera[x+1][y][3]=='h'||scacchiera[x+1][y][3]=='b'||scacchiera[x+1][y][3]=='q'||scacchiera[x+1][y][3]=='t'||scacchiera[x+1][y][3]=='r')&&
        (x-1<0||verifica_visione_casellanera(scacchiera, x-1, y)||scacchiera[x-1][y][3]=='p'||scacchiera[x-1][y][3]=='h'||scacchiera[x-1][y][3]=='b'||scacchiera[x-1][y][3]=='q'||scacchiera[x-1][y][3]=='t'||scacchiera[x-1][y][3]=='r')&&
        (y+1>7||verifica_visione_casellanera(scacchiera, x, y+1)||scacchiera[x][y+1][3]=='p'||scacchiera[x][y+1][3]=='h'||scacchiera[x][y+1][3]=='b'||scacchiera[x][y+1][3]=='q'||scacchiera[x][y+1][3]=='t'||scacchiera[x][y+1][3]=='r')&&
        (y-1<0||verifica_visione_casellanera(scacchiera, x, y-1)||scacchiera[x][y-1][3]=='p'||scacchiera[x][y-1][3]=='h'||scacchiera[x][y-1][3]=='b'||scacchiera[x][y-1][3]=='q'||scacchiera[x][y-1][3]=='t'||scacchiera[x][y-1][3]=='r')&&
        (x+1>7||y+1>7||verifica_visione_casellanera(scacchiera, x+1, y+1)||scacchiera[x+1][y+1][3]=='p'||scacchiera[x+1][y+1][3]=='h'||scacchiera[x+1][y+1][3]=='b'||scacchiera[x+1][y+1][3]=='q'||scacchiera[x+1][y+1][3]=='t'||scacchiera[x+1][y+1][3]=='r')&&
        (x-1<0||y-1<0||verifica_visione_casellanera(scacchiera, x-1, y-1)||scacchiera[x-1][y-1][3]=='p'||scacchiera[x-1][y-1][3]=='h'||scacchiera[x-1][y-1][3]=='b'||scacchiera[x-1][y-1][3]=='q'||scacchiera[x-1][y-1][3]=='t'||scacchiera[x-1][y-1][3]=='r')&&
        (x+1>7||y-1<0||verifica_visione_casellanera(scacchiera, x+1, y-1)||scacchiera[x+1][y-1][3]=='p'||scacchiera[x+1][y-1][3]=='h'||scacchiera[x+1][y-1][3]=='b'||scacchiera[x+1][y-1][3]=='q'||scacchiera[x+1][y-1][3]=='t'||scacchiera[x+1][y-1][3]=='r')&&
        (x-1<0||y+1>7||verifica_visione_casellanera(scacchiera, x-1, y+1)||scacchiera[x-1][y+1][3]=='p'||scacchiera[x-1][y+1][3]=='h'||scacchiera[x-1][y+1][3]=='b'||scacchiera[x-1][y+1][3]=='q'||scacchiera[x-1][y+1][3]=='t'||scacchiera[x-1][y+1][3]=='r')){
            switch(natura){
              case 'P':
                   if(!verifica_visione_pedinabiancascacco(scacchiera, xs, ys)){
                      return 1;}
                      return 0;
              case 'H':if(!verifica_visione_pedinabiancascacco(scacchiera, xs, ys)){
                         return 1;}
                         return 0;
              case 'R': if(X-xs>0){//minaccia a sinistra
                        for(a= X-xs; a!=0; a--){
                            if(verifica_visione_pedinabiancascacco(scacchiera, xs, ys)){
                            return 0;}
                            xs++;}
                            return 1;}

                        if(X-xs<0){//minaccia a destra
                        for(a= xs-X; a!=0; a--){
                            if(verifica_visione_pedinabiancascacco(scacchiera, xs, ys)){
                            return 0;}
                            xs--;}
                            return 1;}

                        if(Y-ys>0){//minaccia giu
                        for(a= Y-ys; a!=0; a--){
                            if(verifica_visione_pedinabiancascacco(scacchiera, xs, ys)){
                            return 0;}
                            ys++;}
                            return 1;}

                        if(Y-ys<0){//minaccia su
                        for(a= ys-Y; a!=0; a--){
                            if(verifica_visione_pedinabiancascacco(scacchiera, xs, ys)){
                            return 0;}
                            ys--;}
                            return 1;}

              case 'B': if(X-xs>0&&Y-ys>0){//minaccia basso sinistra
                        for(a= X-xs; a!=0; a--){
                            if(verifica_visione_pedinabiancascacco(scacchiera, xs, ys)){
                            return 0;}
                            ys++; xs++;}
                            return 1;}

                        if(X-xs<0&&Y-ys<0){//minaccia giu destra
                        for(a= xs-X; a!=0; a--){
                            if(verifica_visione_pedinabiancascacco(scacchiera, xs, ys)){
                            return 0;}
                            xs--;
                            ys--;}
                            return 1;}

                        if(X-xs>0&&Y-ys<0){//minaccia su sinistra
                        for(a= X-xs; a!=0; a--){
                            if(verifica_visione_pedinabiancascacco(scacchiera, xs, ys)){
                            return 0;}
                            xs++; ys--;}
                            return 1;}

                        if(X-xs<0&&Y-ys>0){//minaccia giu sinistra
                        for(a= xs-X; a!=0; a--){
                            if(verifica_visione_pedinabiancascacco(scacchiera, xs, ys)){
                            return 0;}
                            xs--; ys++;}
                            return 1;}}
                            }}

else{
        return 0;}
return 0;}





//nuova funziona verifica scacco re senza limitazioni per verificare se gli scacchi sono due o uno, se uno utilizzare puntatori per salvare coordinate attaccante,
// poi determinare tipo di attacco e verificare vie di fuga re+ visioni caselle di mezzo verificano se non sono inchiodati.
int main()
{
//dichiarazione variabili
configurazioni configurazione[200];
int y, x, yf, xf, i=0, n, mate_w=0, mate_b=0, stalemate=0, draw=0, resign_w=0, resign_b=0, drawbyripetition=0, arrocco=0, cinquatamosse= 0;
int drawby50moves=0, drawbyinsufficientmaterial=0, vialibera=0, fault=0, enpassant_wx= 0, enpassant_wy= 0, enpassant_bx= 0, enpassant_by= 0, ripetizione= 0;
char a=0, move_w[5], move_b[5], promozione;

printf("SCACCHI\nEcco le regole:\nPer eseguire una mossa digitare le coordinate di partenza e di arrivo senza spazi (e2e4)\n");
printf("Per arroccare digitare le coordinate del re e della torre senza spazi (e1a1) \n");
printf("Digitare 'draw' per chiedere il pareggio, 'lose' per arrendersi\nValgono tutte le regole del gioco classico (provare per credere)\n");
printf("Di seguito la scacchiera:\n\n");
//stampa scacchiera a8-h1 con pedine
for(y=8; y>0; y--){
    for(x=1; x<9; x++){
        sprintf(configurazione[0].scacchiera[x-1][y-1], "%c%d", x+'a'-1, y);
        if(y==7){
           configurazione[0].scacchiera[x-1][y-1][3]= 'p';}//pawn (black)
        if(y==2){
           configurazione[0].scacchiera[x-1][y-1][3]= 'P';}//pawn (white)
        if(y==8){
           switch(x){
             case 1:
             case 8: configurazione[0].scacchiera[x-1][y-1][3]='r'; break; //rook (black)
             case 2:
             case 7: configurazione[0].scacchiera[x-1][y-1][3]='h'; break;//horse (black)
             case 3:
             case 6: configurazione[0].scacchiera[x-1][y-1][3]='b'; break;//bishop (black)
             case 4: configurazione[0].scacchiera[x-1][y-1][3]='q'; break;//queen (black)
             case 5: configurazione[0].scacchiera[x-1][y-1][3]='k'; break;}}//king (black)
        if(y==1){
           switch(x){
             case 1:
             case 8: configurazione[0].scacchiera[x-1][y-1][3]='R'; break; //rook (white)
             case 2:
             case 7: configurazione[0].scacchiera[x-1][y-1][3]='H'; break;//horse (white)
             case 3:
             case 6: configurazione[0].scacchiera[x-1][y-1][3]='B'; break;//bishop (white)
             case 4: configurazione[0].scacchiera[x-1][y-1][3]='Q'; break;//queen (white)
             case 5: configurazione[0].scacchiera[x-1][y-1][3]='K'; break;}}//king (white)
//quando la torre si muove diventa t/T e non può più arroccare, quando il re si muove diventa d/D. Quando il pedone avanza di due lascia dietro e/E per un turno permettendo en passant
        if(y==6||y==5||y==4||y==3){
           configurazione[0].scacchiera[x-1][y-1][3]='f';}//falso
        switch(configurazione[0].scacchiera[x-1][y-1][3]){
           case 'f': printf("%s   ", configurazione[0].scacchiera[x-1][y-1]); break;
           case 'p': printf("%c%c   ", a+176, a+127); break;
           case 'r': printf("%c%c   ", a+176, a+202); break;
           case 't': printf("%c%c   ", a+176, a+202); break;
           case 'h': printf("%c%c   ", a+176, a+20); break;
           case 'b': printf("%c%c   ", a+176, a+30); break;
           case 'q': printf("%c%c   ", a+176, a+12); break;
           case 'k': printf("%c%c   ", a+176, a+206); break;
           case 'd': printf("%c%c   ", a+176, a+206); break;
           case 'P': printf("%c%c   ", a+219, a+127); break;
           case 'R': printf("%c%c   ", a+219, a+202); break;
           case 'T': printf("%c%c   ", a+219, a+202); break;
           case 'H': printf("%c%c   ", a+219, a+20); break;
           case 'B': printf("%c%C   ", a+219, a+30); break;
           case 'Q': printf("%c%c   ", a+219, a+12); break;
           case 'K': printf("%c%c   ", a+219, a+206); break;
           case 'D': printf("%c%c   ", a+219, a+206); break;
           }}
        printf("\n\n");}


//ciclo while scambio di mosse fino a termine partita
while(!mate_w||!mate_b||!stalemate||!draw||!resign_w||!resign_b||!drawbyripetition||!drawby50moves||!drawbyinsufficientmaterial){
    configurazione[i+1] = configurazione[i]; i++;
    printf("E' il turno del bianco, muovi una pedina\n");
    while(!vialibera){
       gets(move_w); x= move_w[0]-'a'; y= move_w[1]-'1'; xf= move_w[2]-'a'; yf= move_w[3]-'1';
       if(strcmp(move_w, "draw")==0){
        printf("\nil bianco vuole pareggiare, accetti? Digita si, altrimenti qualsiasi tasto\n");
        gets(move_b);
        if(strcmp(move_b, "si")==0){
            draw= 1; break;}
             else{
                printf("\nPareggio rifiutato, inserisci coordinate (o arrenditi)\n"); continue;}}
       if(strcmp(move_w, "lose")==0){
        printf("\nVuoi davvero arrenderti? Digita si, altrimenti qualsiasi tasto\n");
        gets(move_w);
        if(strcmp(move_w, "si")==0){
            resign_w= 1; break;}
             else{
                printf("\nLa partita continua, inserisci coordinate\n"); continue;}}
       if(!verifica_mossa_esistenza(move_w)){
           printf("\nCoordinate inesistenti, reinseriscile:\n"); continue;}
       switch(configurazione[i].scacchiera[x][y][3]){
           case 'P': vialibera = verifica_mossa_pedonebianco(configurazione[i].scacchiera, move_w);
                    if(vialibera&& y == yf-2){
                        configurazione[i].scacchiera[x][y+1][3]= 'E'; enpassant_wx= x; enpassant_wy= y+1;}
                    if(vialibera&& yf==7){
                        printf("\nscegli a che pedone promuovere: H= cavallo, B= alfiere, T= torre, Q= regina\n");
                        scanf("%c", &promozione); fflush(stdin);
                        while(promozione!='H'&&promozione!='B'&&promozione!='T'&&promozione!='Q'){
                            printf("\nseleziona una lettera corretta\n");
                            scanf("%c", &promozione); fflush(stdin);}
                            configurazione[i].scacchiera[x][y][3]= promozione;} break;
           case 'H': vialibera = verifica_mossa_cavallobianco(configurazione[i].scacchiera, move_w); break;
           case 'B': vialibera = verifica_mossa_alfierebianco(configurazione[i].scacchiera, move_w); break;
           case 'R':
           case 'T': vialibera = verifica_mossa_torrebianca(configurazione[i].scacchiera, move_w); break;
           case 'Q': vialibera = verifica_mossa_reginabianca(configurazione[i].scacchiera, move_w); break;
           case 'K':
           case 'D': vialibera = verifica_mossa_rebianco(configurazione[i].scacchiera, move_w); break;
           default: printf("\nla mossa non corrisponde a nessuna pedina\n"); fault=1;}
       if(!vialibera&&!fault){
          printf("\nmossa non possibile\n"); }
  fault= 0;
  if(vialibera){
   //azzeramento variabili e conferma mossa
    if(configurazione[i].scacchiera[x][y][3]=='K'&&xf==0){//arrocco sinistra
       configurazione[i].scacchiera[x][y][3]='f'; configurazione[i].scacchiera[x-4][y][3]='f';
       configurazione[i].scacchiera[x-2][y][3]= 'D'; configurazione[i].scacchiera[x-1][y][3]= 'T'; arrocco= 1;}
    if(configurazione[i].scacchiera[x][y][3]=='K'&&xf==7){//arrocco destra
       configurazione[i].scacchiera[x][y][3]='f'; configurazione[i].scacchiera[x+3][y][3]='f';
       configurazione[i].scacchiera[x+2][y][3]= 'D'; configurazione[i].scacchiera[x+1][y][3]= 'T'; arrocco= 1;}
    if(configurazione[i].scacchiera[x][y][3]=='K'){//niente più arrocco
        configurazione[i].scacchiera[x][y][3]='D';}
    if(configurazione[i].scacchiera[x][y][3]=='R'){
        configurazione[i].scacchiera[x][y][3]='T';}
    if(configurazione[i].scacchiera[enpassant_bx][enpassant_by][3]== 'e'){//en passant
        configurazione[i].scacchiera[enpassant_bx][enpassant_by][3]= 'f';}
    if(!arrocco){
    configurazione[i].scacchiera[xf][yf][3]= configurazione[i].scacchiera[x][y][3];
    configurazione[i].scacchiera[x][y][3]= 'f';}
    arrocco= 0;}
if(verifica_scacco_rebianco(configurazione[i].scacchiera)&&verifica_scacco_rebianco(configurazione[i-1].scacchiera)&&configurazione[i].scacchiera[xf][yf][3]!='D'){
    printf("\nIl re e' sotto scacco, ripeti la mossa\n");
    configurazione[i]= configurazione[i-1]; vialibera= 0;}
if(verifica_scacco_rebianco(configurazione[i].scacchiera)&&verifica_scacco_rebianco(configurazione[i-1].scacchiera)&&configurazione[i].scacchiera[xf][yf][3]=='D'){
    printf("\nLa destinazione e' sotto attacco, ripeti la mossa\n");
    configurazione[i]= configurazione[i-1]; vialibera= 0;}
if(verifica_scacco_rebianco(configurazione[i].scacchiera)&&!verifica_scacco_rebianco(configurazione[i-1].scacchiera)&&configurazione[i].scacchiera[xf][yf][3]!='D'){
    printf("\nIl re e' inchiodato, ripeti la mossa\n");
    configurazione[i]= configurazione[i-1]; vialibera= 0;}
if(verifica_scacco_rebianco(configurazione[i].scacchiera)&&!verifica_scacco_rebianco(configurazione[i-1].scacchiera)&&configurazione[i].scacchiera[xf][yf][3]=='D'){
    printf("\nLa destinazione e' sotto attacco, ripeti la mossa\n");
    configurazione[i]= configurazione[i-1]; vialibera= 0;}

}
if(draw||resign_w||resign_b){
    break;}//verifica esiti prima della mossa
 vialibera= 0;cinquatamosse++;
if(configurazione[i-1].scacchiera[xf][yf][3]!='f'){
    cinquatamosse= 0;}
//stampa nuova scacchiera
printf("\n");
    for(y=1; y<9; y++){
    for(x=8; x>0; x--){
       switch(configurazione[i].scacchiera[x-1][y-1][3]){
           case 'e':
           case 'E':
           case 'f': printf("%s   ", configurazione[0].scacchiera[x-1][y-1]); break;
           case 'p': printf("%c%c   ", a+176, a+127); break;
           case 'r': printf("%c%c   ", a+176, a+202); break;
           case 't': printf("%c%c   ", a+176, a+202); break;
           case 'h': printf("%c%c   ", a+176, a+20); break;
           case 'b': printf("%c%c   ", a+176, a+30); break;
           case 'q': printf("%c%c   ", a+176, a+12); break;
           case 'k': printf("%c%c   ", a+176, a+206); break;
           case 'd': printf("%c%c   ", a+176, a+206); break;
           case 'P': printf("%c%c   ", a+219, a+127); break;
           case 'R': printf("%c%c   ", a+219, a+202); break;
           case 'T': printf("%c%c   ", a+219, a+202); break;
           case 'H': printf("%c%c   ", a+219, a+20); break;
           case 'B': printf("%c%C   ", a+219, a+30); break;
           case 'Q': printf("%c%c   ", a+219, a+12); break;
           case 'K': printf("%c%c   ", a+219, a+206); break;
           case 'D': printf("%c%c   ", a+219, a+206); break;}}
    printf("\n\n");}
//verifica esiti dopo la mossa
for(n=1; i-n>-1; n++){
    if(verifica_drawbyrepetition(configurazione[i-n].scacchiera, configurazione[i].scacchiera)){
        ripetizione++;}}
if(verifica_stalematenero(configurazione[i].scacchiera)){
    stalemate= 1;}
if(ripetizione==2){
    drawbyripetition= 1;}
ripetizione= 0;
if(verifica_drawbymaterial(configurazione[i].scacchiera)){
    drawbyinsufficientmaterial= 1;}
if(cinquatamosse>49){
    drawby50moves= 1;}
if(verifica_scaccomattoalnero(configurazione[i].scacchiera)){
    mate_w=1;}
if(mate_w||mate_b||stalemate||drawbyripetition||drawby50moves||drawbyinsufficientmaterial){
     break;}


   //turno nero
  configurazione[i+1] = configurazione[i]; i++;
    printf("E' il turno del nero, muovi una pedina\n");
    while(!vialibera){
       gets(move_b); x= move_b[0]-'a'; y= move_b[1]-'1'; xf= move_b[2]-'a'; yf= move_b[3]-'1';
       if(strcmp(move_b, "draw")==0){
        printf("\nil nero vuole pareggiare, accetti? Digita si, altrimenti qualsiasi tasto\n");
        gets(move_w);
        if(strcmp(move_w, "si")==0){
            draw= 1; break;}
            else{
                printf("\nPareggio rifiutato, inserisci coordinate (o arrenditi)\n"); continue;}}
        if(strcmp(move_b, "lose")==0){
        printf("\nVuoi davvero arrenderti? Digita si, altrimenti qualsiasi tasto\n");
        gets(move_w);
        if(strcmp(move_w, "si")==0){
            resign_b= 1; break;}
             else{
                printf("\nLa partita continua, inserisci coordinate\n"); continue;}}
       if(!verifica_mossa_esistenza(move_b)){
           printf("\nCoordinate inesistenti, reinseriscile:\n"); continue;}
       switch(configurazione[i].scacchiera[x][y][3]){
           case 'p': vialibera = verifica_mossa_pedonenero(configurazione[i].scacchiera, move_b);
                    if(vialibera&& y == yf+2){
                        configurazione[i].scacchiera[x][y-1][3]= 'e'; enpassant_bx= x; enpassant_by= y-1;}
                    if(vialibera&& yf==0){
                        printf("\nscegli a che pedone promuovere: h= cavallo, b= alfiere, t= torre, q= regina\n");
                        scanf("%c", &promozione); fflush(stdin);
                        while(promozione!='h'&&promozione!='b'&&promozione!='t'&&promozione!='q'){
                            printf("\nseleziona una lettera corretta\n");
                            scanf("%c", &promozione); fflush(stdin);}
                            configurazione[i].scacchiera[x][y][3]= promozione;} break;
           case 'h': vialibera = verifica_mossa_cavallonero(configurazione[i].scacchiera, move_b); break;
           case 'b': vialibera = verifica_mossa_alfierenero(configurazione[i].scacchiera, move_b); break;
           case 'r':
           case 't': vialibera = verifica_mossa_torrenera(configurazione[i].scacchiera, move_b); break;
           case 'q': vialibera = verifica_mossa_reginanera(configurazione[i].scacchiera, move_b); break;
           case 'k':
           case 'd': vialibera = verifica_mossa_renero(configurazione[i].scacchiera, move_b); break;
           default: printf("\nla mossa non corrisponde a nessuna pedina\n"); fault=1;}
       if(!vialibera&&!fault){
          printf("\nmossa non possibile\n"); }
          fault= 0;
//azzeramento variabili e conferma mossa
   if(vialibera){
    if(configurazione[i].scacchiera[x][y][3]=='k'&&xf==0){//arrocco sinistra
        configurazione[i].scacchiera[x][y][3]='f'; configurazione[i].scacchiera[x-4][y][3]='f';
        configurazione[i].scacchiera[x-2][y][3]= 'd'; configurazione[i].scacchiera[x-1][y][3]= 't'; arrocco= 1;}
    if(configurazione[i].scacchiera[x][y][3]=='k'&&xf==7){//arrocco destra
        configurazione[i].scacchiera[x][y][3]='f'; configurazione[i].scacchiera[x+3][y][3]='f';
        configurazione[i].scacchiera[x+2][y][3]= 'd'; configurazione[i].scacchiera[x+1][y][3]= 't'; arrocco= 1;}
    if(configurazione[i].scacchiera[x][y][3]=='k'){//niente più arrocco
        configurazione[i].scacchiera[x][y][3]='d';}
    if(configurazione[i].scacchiera[x][y][3]=='r'){
        configurazione[i].scacchiera[x][y][3]='t';}
    if(configurazione[i].scacchiera[enpassant_wx][enpassant_wy][3]== 'E'){//enpassant
        configurazione[i].scacchiera[enpassant_wx][enpassant_wy][3]= 'f';}
    if(!arrocco){
        configurazione[i].scacchiera[xf][yf][3]= configurazione[i].scacchiera[x][y][3];
        configurazione[i].scacchiera[x][y][3]= 'f';}
    arrocco= 0;}
    if(verifica_scacco_renero(configurazione[i].scacchiera)&&verifica_scacco_renero(configurazione[i-1].scacchiera)&&configurazione[i].scacchiera[xf][yf][3]!='d'){
    printf("\nIl re e' sotto scacco, ripeti la mossa\n");
    configurazione[i]= configurazione[i-1]; vialibera= 0;}
    if(verifica_scacco_renero(configurazione[i].scacchiera)&&verifica_scacco_renero(configurazione[i-1].scacchiera)&&configurazione[i].scacchiera[xf][yf][3]=='d'){
    printf("\nLa destinazione e' sotto attacco, ripeti la mossa\n");
    configurazione[i]= configurazione[i-1]; vialibera= 0;}
    if(verifica_scacco_renero(configurazione[i].scacchiera)&&!verifica_scacco_renero(configurazione[i-1].scacchiera)&&configurazione[i].scacchiera[xf][yf][3]!='d'){
    printf("\nIl re e' inchiodato, ripeti la mossa\n");
    configurazione[i]= configurazione[i-1]; vialibera= 0;}
    if(verifica_scacco_renero(configurazione[i].scacchiera)&&!verifica_scacco_renero(configurazione[i-1].scacchiera)&&configurazione[i].scacchiera[xf][yf][3]=='d'){
    printf("\nLa destinazione e' sotto attacco, ripeti la mossa\n");
    configurazione[i]= configurazione[i-1]; vialibera= 0;}
}
if(draw||resign_w||resign_b){
    break;}//verifica esiti prima della mossa
vialibera= 0; cinquatamosse++;
if(configurazione[i-1].scacchiera[xf][yf][3]!='f'){
    cinquatamosse= 0;}
//stampa nuova scacchiera
printf("\n");
    for(y=8; y>0; y--){
    for(x=1; x<9; x++){
       switch(configurazione[i].scacchiera[x-1][y-1][3]){
           case 'e':
           case 'E':
           case 'f': printf("%s   ", configurazione[0].scacchiera[x-1][y-1]); break;
           case 'p': printf("%c%c   ", a+176, a+127); break;
           case 'r': printf("%c%c   ", a+176, a+202); break;
           case 't': printf("%c%c   ", a+176, a+202); break;
           case 'h': printf("%c%c   ", a+176, a+20); break;
           case 'b': printf("%c%c   ", a+176, a+30); break;
           case 'q': printf("%c%c   ", a+176, a+12); break;
           case 'k': printf("%c%c   ", a+176, a+206); break;
           case 'd': printf("%c%c   ", a+176, a+206); break;
           case 'P': printf("%c%c   ", a+219, a+127); break;
           case 'R': printf("%c%c   ", a+219, a+202); break;
           case 'T': printf("%c%c   ", a+219, a+202); break;
           case 'H': printf("%c%c   ", a+219, a+20); break;
           case 'B': printf("%c%C   ", a+219, a+30); break;
           case 'Q': printf("%c%c   ", a+219, a+12); break;
           case 'K': printf("%c%c   ", a+219, a+206); break;
           case 'D': printf("%c%c   ", a+219, a+206); break;}}
    printf("\n\n");}
//verifica esiti dopo la mossa
for(n=1; i-n>-1; n++){
    if(verifica_drawbyrepetition(configurazione[i-n].scacchiera, configurazione[i].scacchiera)){
        ripetizione++;}}
if(verifica_stalematebianco(configurazione[i].scacchiera)){
    stalemate= 1;}
if(ripetizione==2){
    drawbyripetition= 1;}
ripetizione= 0;
if(verifica_drawbymaterial(configurazione[i].scacchiera)){
    drawbyinsufficientmaterial= 1;}
if(cinquatamosse>49){
    drawby50moves= 1;}
if(verifica_scaccomattoalbianco(configurazione[i].scacchiera)){
    mate_b=1;}
if(mate_w||mate_b||stalemate||drawbyripetition||drawby50moves||drawbyinsufficientmaterial){
     break;}

}
//conclusioni
if(mate_w){printf("Il bianco ha vinto per scacco matto");}
if(mate_b){printf("Il nero ha vinto per scacco matto");}
if(resign_w){printf("Il nero ha vinto per abbandono");}
if(resign_b){printf("Il bianco ha vinto per abbandono");}
if(draw){printf("Pareggio sia");}
if(drawbyinsufficientmaterial){printf("Pareggio, non ci sono abbastanza materiali per concludere la partita");}
if(drawby50moves){printf("Pareggio per la regola delle 50 mosse");}
if(drawbyripetition){printf("Pareggio per ripetizione");}
if(stalemate){printf("Pareggio, non ci sono mosse legali per l'avversario");}
return 0;
}

