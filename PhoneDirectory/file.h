#ifndef FILE_H
#define FILE_H
#include "queue.h"


void readFromFile(struct queue* q1);
void writeInFile(struct contact data);
void writeFromQueue(struct queue q);
void removeFile();
#endif // FILE_H
