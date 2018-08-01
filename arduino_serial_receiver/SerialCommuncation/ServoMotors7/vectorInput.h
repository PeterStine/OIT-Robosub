
/*
 * VectorSetup.h
 *
 * Created: 7/19/2018 9:55:21 AM
 *  Author: jaysu
 */ 

void vectorInputInit(void (*vectorCallBackFn)(uint32_t[]));

void vectorInputCallback(char input[]);

int vectorFilter(int c);