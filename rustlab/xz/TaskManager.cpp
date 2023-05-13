#include "TaskManager.h"
#include <iostream>

using namespace std;

ostream& os = cout;

TaskManager& TaskManager::AddTask(Task task)
{
	taskList[taskList.rbegin()->first + 1] = task;
	return *this;
}

TaskManager& TaskManager::DeleteTask(unsigned id)
{
	if (taskList.find(id) == taskList.end())
	{
		os << "Not found ID" << endl;
		return *this;
	}
	taskList.erase(id);
	return *this;
}

TaskManager& TaskManager::SetActiveTask(unsigned id)
{
	auto it = taskList.find(id);
	if (it != taskList.end()) 
	{
		currentTask = it->second;
		os << "change active task";
	}
	else
	{
		os << id << " is not found in tasks" << endl;
	}

	return *this;
}

TaskManager& TaskManager::EditTask(unsigned id, Task new_task)
{
	auto it = taskList.find(id);
	if (it != taskList.end())
	{
		it->second = new_task;
		os << "edit " << id << " task" << endl;
	}
	else
	{
		os << id << " is not found in tasks" << endl;
	}

	return *this;
}

TaskManager& TaskManager::TaskCompleted(unsigned id)
{
	auto it = taskList.find(id);
	if (it != taskList.end())
	{
		it->second.taskCompleted = true;
		os << "task: " << id << " completed" << endl;
	}
	else
	{
		os << id << " is not found in tasks" << endl;
	}

	return *this;
}

void TaskManager::DisplayTask()
{
	for (auto it = taskList.begin(); it != taskList.end(); ++it)
	{
		os << "ID: " << it->first + 1 << ", task: " << it->second.title << " | " << it->second.desc;
		os << endl;
	}
}