#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    cout << "\nThe kernel version is :\n";
    system("cat /proc/sys/kernel/osrelease");

    cout << "\nThe CPU space :\n";
    system("cat /proc/cpuinfo | awk 'NR==3, NR==4{print}'");

    cout << "\nAmount of CPU time since system was last booted is : ";
    system("cat /proc/uptime");

    cout << "\nThe configured memory is :\n";
    system("cat /proc/meminfo | awk 'NR == 1{print $2}'");

    cout << "\nAmount of free memory :\n";
    system("cat /proc/meminfo | awk 'NR == 2{print $2}'");

    cout << "\nAmount of used memory is :\n";
    system("cat /proc/meminfo | awk 'NR==1 {a=$2} NR==2 {b=$2} END {print a-b}'");

    cout << endl;

    return 0;
}
