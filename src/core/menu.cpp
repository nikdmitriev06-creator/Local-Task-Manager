#include "menu.h"

menu::menu(TaskManager &manager) : manager(manager)
{

}

void menu::enterMenu()
{
    bool menuWork = true;
    while(menuWork)
    {
        std::cout << "choose what to do:" << std::endl;
        std::cout << "1. list all tasks" << std::endl;
        std::cout << "2. create new task" << std::endl;
        std::cout << "3. start processing all tasks" << std::endl;
        std::cout << "0. exit menu" << std::endl;
        std::cin >> choice;

        switch(choice)
        {
        case(1): 
        {
            listAllTask();
            break;
        }
        case(2):
        {
            bool taskCreated = 0;
            while(!taskCreated)
            {
            clearConsole();
            std::cout << "what task do you want to create?" << std::endl;
            std::cout << "1. print task" << std::endl;
            std::cout << "2. sleep task" << std::endl;
            int taskChoice = 0;
            std::cin >> taskChoice;
            switch(taskChoice)
            {
                case(1):
                {
                    createPrintTask();
                    taskCreated = 1;
                    break;
                }
                case(2):
                {
                    createSleepTask();
                    taskCreated = 1;
                    break;
                }
                default:
                {
                    std::cout << "please enter a valid choice";
                    break;
                }
            }
                std::cout << "task created succesfully" << std::endl;
                break;
            }
            break;
        }
        case(3):
        {
            manager.start();
            break;
        }
        case(0):
        {
            menuWork = false;
            break;
            
        }
        default:
        {
            break;
        }
        }
        choice = -1;
    }
}

void menu::clearConsole() {
    std::cout << "\033[2J\033[H";
}

void menu::createPrintTask()
{
    clearConsole();
    std::cout << "enter what to print: ";
    std::string whatToPrint;
    std::cin >> whatToPrint;
    manager.CreateTask("print", whatToPrint);
}

void menu::createSleepTask()
{
    clearConsole();

    std::string howManySleep;
    while(true)
    {
        std::cout << "enter how many to sleep: ";
        std::cin >> howManySleep;
        if(isNumber(howManySleep)){
            break;
        }
    }
    manager.CreateTask("sleep", howManySleep);
}

void menu::listAllTask()
{
    clearConsole();
    std::cout << "all tasks:" << std::endl;
    manager.ListTasks();
    std::cout << std::endl << "all tasks listed" << std::endl;
    std::cout << "enter any symbol to return to menu: ";
    std::cin.ignore();
    std::cin.get();
    clearConsole();
}

bool menu::isNumber(std::string number)
{
    bool ans = true;
    if(number.empty()) return false;
    for(auto it : number)
    {
        if(!std::isdigit(it))
        {
            ans = false;
        }
    }
    return ans;
}
