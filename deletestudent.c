#include <stdio.h>
#include <string.h>

#define MAX 100
#define NO_DATA "No_Data"

typedef struct {
    char MSSV[20];      
    char NAME[50];      
    char DATE[15];      
    char NUM[20];       
    char ADD[30];       
    char CLASS[10];     
    float math;         
    float lit;          
    float eng;          
    float aver;         
} SinhVien;


void deleteFeature(SinhVien *s) {
    strcpy(s->NAME, NO_DATA);
    strcpy(s->DATE, NO_DATA);
    strcpy(s->NUM, NO_DATA);
    strcpy(s->ADD, NO_DATA);
    strcpy(s->CLASS, NO_DATA);
    s->math = -1.0;
    s->lit  = -1.0;
    s->eng  = -1.0;
    s->aver = -1.0;
}


void deleteSinhVienTheoMSSV(SinhVien ds[], int soLuong, char *mssv) {
    for (int i = 0; i < soLuong; i++) {
        if (strcmp(ds[i].MSSV, mssv) == 0) {
            deleteFeature(&ds[i]);
            printf(">> Đã xóa thông tin sinh viên có MSSV: %s\n", mssv);
            return;
        }
    }
    printf(">> Không tìm thấy sinh viên có MSSV: %s\n", mssv);
}

int main() {
    SinhVien ds[MAX];
    int soLuong = 0;

    FILE *f = fopen("sinhvien.txt", "r");
    if (f == NULL) {
        printf("Không thể mở file sinhvien.txt\n");
        return 1;
    }

    
    while (fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%f,%f,%f,%f\n",
                  ds[soLuong].MSSV,
                  ds[soLuong].NAME,
                  ds[soLuong].DATE,
                  ds[soLuong].NUM,
                  ds[soLuong].ADD,
                  ds[soLuong].CLASS,
                  &ds[soLuong].math,
                  &ds[soLuong].lit,
                  &ds[soLuong].eng,
                  &ds[soLuong].aver) == 10) {
        soLuong++;
    }
    fclose(f);


    char mssvCanXoa[20];
    printf("Nhập MSSV cần xóa thông tin: ");
    scanf("%s", mssvCanXoa);

    deleteSinhVienTheoMSSV(ds, soLuong, mssvCanXoa);

   
    f = fopen("sinhvien.txt", "w");
    if (f == NULL) {
        printf("Không thể ghi file sinhvien.txt\n");
        return 1;
    }

    for (int i = 0; i < soLuong; i++) {
        fprintf(f, "%s,%s,%s,%s,%s,%s,%.2f,%.2f,%.2f,%.2f\n",
                ds[i].MSSV,
                ds[i].NAME,
                ds[i].DATE,
                ds[i].NUM,
                ds[i].ADD,
                ds[i].CLASS,
                ds[i].math,
                ds[i].lit,
                ds[i].eng,
                ds[i].aver);
    }
    fclose(f);

    printf(">> Đã cập nhật lại file sinhvien.txt.\n");

    return 0;
}