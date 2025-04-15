#include "students.h"
#include "updateAndStatus.h"
#include <stdio.h>
#include <string.h>

void input_string(char *str, int size);
void input_float(float *value);
void saveNewData(profile *s);

void update(profile *s, int ID)
{
    // nhap thong tin moi 
    input_string(s[ID].MSSV, sizeof(s[ID].MSSV));

    input_string(s[ID].NAME, sizeof(s[ID].NAME));

    input_string(s[ID].DATE, sizeof(s[ID].DATE));

    input_string(s[ID].NUM, sizeof(s[ID].NUM));

    input_string(s[ID].ADD, sizeof(s[ID].ADD));

    input_string(s[ID].CLASS, sizeof(s[ID].CLASS));

    // nhap diem so moi
    input_float(&s[ID].math);

    input_float(&s[ID].lit);

    input_float(&s[ID].eng);

    // tinh diem trung binh
    s[ID].aver = average(s, s[ID].MSSV);


    saveNewAllData(s);
}

void input_string(char *str, int size) 
{
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void input_float(float *value) 
{
    scanf("%f", value);
    getchar();
}

void saveNewData(profile *s)
{
    FILE *f = fopen("temp.txt", "w");  // Ghi de du lieu moi 
    if (f == NULL) {
        printf("ERROR!\n");
        return;
    }

    for (int i = 0; i < 500000; i++) {
        fprintf(f, "%s,%s,%s,%s,%s,%s,%.2f,%.2f,%.2f,%.2f\n",
                s[i].MSSV, s[i].NAME, s[i].DATE, s[i].NUM, s[i].ADD,
                s[i].CLASS, s[i].math, s[i].lit, s[i].eng, s[i].aver);
    }

    fclose(f);

    if (remove("students.txt") != 0) {
        printf("\nERROR");
        return;
    }

    if (rename("temp.txt", "students.txt") != 0) {
        printf("\nERROR\n");
        return;
    }

    printf("\nDữ liệu đã được cập nhật thành công\n");
}




