#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12

void read_file(char *sample_file, float *monthly_data) {
    FILE *file = fopen(sample_file, "r");
    for (int i = 0; i < MONTHS; i++) {
        fscanf(file, "%f", &monthly_data[i]);
    }
    fclose(file);
}

void sales_report(char *months[], float *sales) {
    printf("\nMonthly sales report for 2022:\n");
    printf("Month\tSales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%s\t$%.2f\n", months[i], sales[i]);
    }
    printf("\n");
}

void sales_summary(float *sales, char *months[]) {
    float min = sales[0];
    float max = sales[0];
    char *min_month = months[0];
    char *max_month = months[0];
    float totalSales = 0.0;
    for (int i = 0; i < MONTHS; i++) {
        if (sales[i] < min) {
            min = sales[i];
            min_month = months[i];
        }
        if (sales[i] > max) {
            max = sales[i];
            max_month = months[i];
        }
        totalSales += sales[i];
    }

    double average = totalSales / MONTHS;

    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", min, min_month);
    printf("Maximum sales: $%.2f (%s)\n", max, max_month);
    printf("Average sales: $%.2f\n", average);
}

void sixmonth_moving_average(float *sales, char *months[]) {
    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i <= MONTHS - 6; i++) {
        float average = 0.0;
        for (int j = i; j < i + 6; j++) {
            average += sales[j];
        }
        float movingAverage = average / 6;
        printf("%s - %s $%.2f\n", months[i], months[i + 5], movingAverage);
    }
    printf("\n");
}

void sort_sales(char *months[], float *sales) {
    printf("\nSales Report (Highest to Lowest):\n");
    printf("%-15s%-10s\n", "Month", "Sales");
    for (int i = 0; i < MONTHS; i++) {
        for (int j = i + 1; j < MONTHS; j++) {
            if (sales[j] > sales[i]) {
                float salesTemp = sales[i];
                sales[i] = sales[j];
                sales[j] = salesTemp;
                char *monthTemp = months[i];
                months[i] = months[j];
                months[j] = monthTemp;
            }
        }
        printf("%-10s$%-15.2f\n", months[i], sales[i]);
    }
}

int main() {
    float sales[MONTHS];
    read_file("sample.txt", sales);
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    sales_report(months, sales);
    sales_summary(sales, months);
    sixmonth_moving_average(sales, months);
    sort_sales(months, sales);

    return 0;
}
