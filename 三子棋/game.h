#pragma once
#define row 3
#define col 3
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void initboard(char board[row][col], int r, int c);
void displayboard(char board[row][col], int r, int c);
void playermove(char board[row][col], int r , int c);
void computermove(char board[row][col], int ,int );
char iswin(char board[row][col],int , int );
