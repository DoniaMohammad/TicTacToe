#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

uint8 sign[10] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};

void DisplayBoard (uint8 sign[],uint8 size);
uint8 CheckWin (uint8 sign[],uint8 size);
void Player1 (uint8 sign[],uint8 size,uint8 choice);
void Player2 (uint8 sign[],uint8 size,uint8 choice);
void MultiPlayerMode (uint8 sign[],uint8 size);
void SinglePlayerMode (uint8 sign[],uint8 size);
void Computer (uint8 sign[],uint8 size,uint8 choice);
void TableInit(uint8 sign[],uint8 size);

#endif