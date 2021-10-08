// gcc employeeMain.c employeeTable.c employeeOne.c
// gcc employeeMain.c employeeTable.c employeeTwo.c

#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void)
{
    // defined in employeeOne.c or employeeTwo.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char * phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

    // defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    
    PtrToEmployee matchPtr; // Declaration

    // search by number
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);
    if (matchPtr != NULL)
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID 1045 is NOT found in the record\n");

    // search by name
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");
    
    // search by phone
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-555-2134");
    if (matchPtr != NULL)
        printf("Employee with 909-555-2134 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee with 909-555-2134 is NOT found in the record\n");  

    // search by salary
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.78);
    if (matchPtr != NULL)
        printf("Employee salary with 8.78 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee salary with 8.78 is NOT found in the record\n");
  
    
    return EXIT_SUCCESS;
}