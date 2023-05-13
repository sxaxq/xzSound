#pragma once

#include <string>
#include <map>
#include <vector>

struct Task
{
	std::string title;
	std::string desc;
	bool taskCompleted;

	Task() = default;
	Task(std::string t, std::string d) :
		title(t), desc(d) { }
};

class TaskManager
{
public:
	TaskManager()
	{
		currentTask = Task();
		taskList[0] = {Task("Obama", "Kill")};
		completedTask = std::vector<Task>();
		noCompletedTask = std::vector<Task>();
	}

	void DisplayTask();
	TaskManager& AddTask(Task task);
	TaskManager& SetActiveTask(unsigned id);
	TaskManager& DeleteTask(unsigned id);
	TaskManager& EditTask(unsigned id, Task new_task);
	TaskManager& TaskCompleted(unsigned id);

private:
	Task currentTask;
	std::map<unsigned, Task> taskList;
	std::vector<Task> completedTask;
	std::vector<Task> noCompletedTask;
};