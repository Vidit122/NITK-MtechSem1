#include <stdio.h>
#include <stdlib.h> // For the system() function

int main() {
    
    FILE *fp;
    
    // 1. Create and open a file to write data
    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not create data file.\n");
        return 1;
    }
    
    // 2. Write some sample data to the file
    // The data format is "x y" on each line.
    fprintf(fp, "1 2\n");
    fprintf(fp, "2 4\n");
    fprintf(fp, "3 1\n");
    fprintf(fp, "4 5\n");
    fprintf(fp, "5 3\n");
    
    // 3. Close the file
    fclose(fp);
    
    // 4. Use the system() function to call Gnuplot
    // This command tells Gnuplot to plot the data from "data.txt" with lines and points.
    printf("Plotting data with Gnuplot...\n");
    system("gnuplot -p -e \"plot 'data.txt' with linespoints\"");
    return 0;
}