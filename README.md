# ENGG-1340_new

![alt text](https://github.com/sam324976/ENGG-1340_new/blob/master/img/menu.png)
## Problem statment
In this project, I am going to build up a small system of information management. The aims of this system is to provide some basic functions for employer to collect and manage the information of employee.

### Function 1: Creating record for new employee
This function is used to create record for new employee and save their information on a file. Thus, the program obtain the specific data inputted by the user and store them in to a file ("data.txt"). There are few types of data which will be inputted by user, such as employee's name, id , age , salary, role and attribute. The data will be stored vertically and be used by other functions.

### Function 2: Searching
This function is used to search a specific employee. There are 2 types of searching, one is that user can input specific type of data (name/id/role) to find specific employee. The other type of searching is user can input a salary number and ask the program to output employee with higher or lower salary compared with the input number of salary.

### Function 3: Fire
This function is used to delete the record from specifc employee. User can use data (name/id/role) to find out the position of the record and remove them. A new .txt file will be created and stored the data without the record of the employee which user want to delete. Then, the orginal "data.txt" (whihc used to stored data) will be deleted and the new file will rename to "data.txt".

### Function 4: Edit
This function is used to edit the information from the employee. All types of data except employee's name can be modified. But first, the user must know the name of the employee. It is suggested that they can find employee's name using searching if they dont know.

A menu will be created to list out all the function and allow users to choose which to use. 

## Problem setting
In this project, we are assuming that users will following the instruction provided in the program. If the user does not follow the rule, they will be back to the main menu page and asked to choose and type the information again. Users can use a specfic function multiple times without heading back to the mmain menu page if they want. It will be convenient for hem to make better information management. It is assume that user will strictly follow the instrucment from the problem, they will not type in unrelated data. For example, user is not allow to type in character if the program is asking you to input number. 
