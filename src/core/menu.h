#pragma once

#include <iostream>
#include "task_manager.h"

class menu
{
int choice;
TaskManager &manager;

public:
menu(TaskManager &manager);

void enterMenu();

void clearConsole();

void createPrintTask();
void createSleepTask();

void listAllTask();
bool isNumber(std::string number);

};