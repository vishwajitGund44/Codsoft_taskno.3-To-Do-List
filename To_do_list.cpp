#include <iostream>
#include <vector>
struct Task
{
    std::string description;
    bool completed;
};

void addTask(std::vector<Task>& tasks, const std::string& description) 
{
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    tasks.push_back(newTask);
    std::cout << "Task added: " << description << std::endl;
}

void viewTasks(const std::vector<Task>& tasks) 
{
    std::cout << "To-Do List:" << std::endl;
    for (size_t i = 0; i < tasks.size(); i++) 
	{
        std::cout << "[" << (i + 1) << "] ";
        if (tasks[i].completed) {
            std::cout << "[Completed] ";
        }
        std::cout << tasks[i].description << std::endl;
    }
}

void markTaskAsCompleted(std::vector<Task>& tasks, int taskNumber) 
{
    if (taskNumber >= 1 && taskNumber <= tasks.size()) 
	{
        tasks[taskNumber - 1].completed = true;
        std::cout << "Task " << taskNumber << " marked as completed." << std::endl;
    } else {
        std::cout << "Invalid task number." << std::endl;
    }
}

void removeTask(std::vector<Task>& tasks, int taskNumber) 
{
    if (taskNumber >= 1 && taskNumber <= tasks.size()) 
	{
        std::cout << "Task " << taskNumber << " removed: " << tasks[taskNumber - 1].description << std::endl;
        tasks.erase(tasks.begin() + taskNumber - 1);
    }
	 else 
	{
        std::cout << "Invalid task number." << std::endl;
    }
}

int main() 
{
    std::vector<Task> tasks;

    while (true) 
	{
        std::cout << "To-Do List Manager" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) 
		{
            case 1: 
			{
                std::string taskDescription;
                std::cin.ignore(); 
                std::cout << "Enter the task description: ";
                std::getline(std::cin, taskDescription);
                addTask(tasks, taskDescription);
                break;
            }
            case 2:
                viewTasks(tasks);
                break;
            case 3: 
			{
                int taskNumber;
                std::cout << "Enter the task number to mark as completed: ";
                std::cin >> taskNumber;
                markTaskAsCompleted(tasks, taskNumber);
                break;
            }
            case 4: 
			{
                int taskNumber;
                std::cout << "Enter the task number to remove: ";
                std::cin >> taskNumber;
                removeTask(tasks, taskNumber);
                break;
            }
            case 5:
                std::cout << "Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}
