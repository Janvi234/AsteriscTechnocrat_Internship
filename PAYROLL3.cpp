//CORRECT ONE
#include <stdio.h>
#include <stdlib.h>
struct Employee{
  int id;
  char name[100];
  float fixedSalary;
  float extraHours;
  float hourlyRate;
  float salary;
};

void insertEmployee(struct Employee* employee){
  printf("Enter employee ID: ");
  scanf("%d", &(employee->id));
  
  printf("Enter employee name: ");
  scanf("%s", employee->name);
  
  printf("Enter employee fixed salary: $");
  scanf("%f", &(employee->fixedSalary));
  
  printf("Employee added successfully!\n");
}

void calculateSalary(struct Employee* employee){
  printf("Enter extra working hours for employee ID %d: ", employee->id);
  scanf("%f", &(employee->extraHours));
  
  printf("Enter salary per hour for employee ID %d: $", employee->id);
  scanf("%f", &(employee->hourlyRate));
  
  employee->salary = employee->fixedSalary + (employee->hourlyRate * employee->extraHours);
  
  printf("Salary calculation completed!\n");
}

void generatePayslip(struct Employee* employee){
  printf("\n*************** Employee Payslip ***************\n");
  printf("Employee ID: %d\n", employee->id);
  printf("Name: %s\n", employee->name);
  printf("Salary: $%.2f\n", employee->salary);
  printf("************************************************\n\n");
}

int main(){
  struct Employee employees[MAX_EMPLOYEES];
  int numEmployees = 0;
  int choice;
  
  printf("************ PAYROLL MANAGEMENT SYSTEM ************\n");
  
  do{
    printf("::::::MENU::::::\n");
    printf("1. Insert Employee\n");
    printf("2. Calculate Salary\n");
    printf("3. Generate Payslip\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice){
      case 0:
        printf("**************** PROGRAM EXIT ****************\n");
        exit(0);
      case 1:
        if(numEmployees < MAX_EMPLOYEES){
          insertEmployee(&employees[numEmployees]);
          numEmployees++;
        }
        else{
          printf("Maximum number of employees reached!\n");
        }
        break;
      case 2:
        if(numEmployees > 0){
          printf("Enter employee ID to calculate salary: ");
          int id;
          scanf("%d", &id);
          int index = -1;
          for(int i=0; i<numEmployees; i++){
            if(employees[i].id == id){
            index = i;
            break;
            }
          }
          
          if(index != -1){
            calculateSalary(&employees[index]);
          }
          else{
            printf("Employee with ID %d not found!\n", id);
          }
        }
        else{
          printf("No employees added yet!\n");
        }
        break;
      case 3:
        if(numEmployees > 0){
          printf("Enter employee ID to generate payslip: ");
          int id;
          scanf("%d", &id);
          int index = -1;
          for(int i=0; i<numEmployees; i++){
            if(employees[i].id == id){
              index = i;
              break;
            }
          }
          
          if(index != -1){
            generatePayslip(&employees[index]);
          }
          else{
            printf("Employee with ID %d not found!\n", id);
          }
        }
        else{
          printf("No employees added yet!\n");
        }
        break;
      default:
        printf("SORRY INVALID CHOICE... TRY AGAIN...\n");
    }
  } while(choice != 0);
  
  return 0;
}

