#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Time {
    int hour;
    int min;
};

struct CT {
    char maCT[10];
    char gaDi[20];
    char gaDen[20];
    Time startTime;
    Time endTime;
    char type;
};

void nhap(int n, CT* a, FILE *f) {
    for (int i = 0; i < n; i++) {
        fgets(a[i].maCT, sizeof(a[i].maCT), f);
        a[i].maCT[strcspn(a[i].maCT, "\n")] = '\0';
        
        fgets(a[i].gaDi, sizeof(a[i].gaDi), f);
        a[i].gaDi[strcspn(a[i].gaDi, "\n")] = '\0';
        
        fgets(a[i].gaDen, sizeof(a[i].gaDen), f);
        a[i].gaDen[strcspn(a[i].gaDen, "\n")] = '\0';
        
        fscanf(f, "%d", &a[i].startTime.hour);
        fscanf(f, "%d\n", &a[i].startTime.min);
        
        fscanf(f, "%d", &a[i].endTime.hour);
        fscanf(f, "%d\n", &a[i].endTime.min);
        
        fscanf(f, "%c\n", &a[i].type);
    }   
}

void docFile(int* n, CT** a, FILE* f) {
    char tenFile[] = "input.txt";
    
    f = fopen(tenFile, "rt");
    if (f == NULL) {
        printf("Khong the doc file %s!\n", tenFile);
        return;
    }    
    
    fscanf(f, "%d\n", n);
    
    *a = (CT*)malloc(*n * sizeof(CT));
    
    nhap(*n, *a, f);
    
    fclose(f);
}

void xuat(CT a) {
    printf("|%10s|%15s|%15s|%02d:%02d|%02d:%02d|%5c|\n", a.maCT, a.gaDi, a.gaDen, a.startTime.hour, a.startTime.min, a.endTime.hour, a.endTime.min, a.type);
}

void xuat(int n, CT* a) {
    for (int i = 0; i < n; i++) {
        xuat(a[i]);
    }
}

Time tinhKhoangThoiGian(Time a, Time b) {
    int gio = b.hour - a.hour;
    int phut = b.min - a.min;

    if (phut < 0) {
        gio -= 1;
        phut += 60;
    }

    if (gio < 0) {
        gio += 24;
    }

    Time res;
    res.hour = gio;
    res.min = phut;
    
    return res;
}


Time tongThoiGian(Time a, Time b) {
    a.hour += b.hour;
    a.min += b.min;
    if (a.min >= 60) {
        a.hour += 1;
        a.min -= 60;
    }
    return a;
}

Time tinhTongThoiGianDiChuyenTau(int n, CT* a, char loai, int* check) {
    *check = 0;
    Time res;
    res.hour = 0;
    res.min = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].type == loai) {
            *check = 1;
            res = tongThoiGian(res, tinhKhoangThoiGian(a[i].startTime, a[i].endTime));
        }
    }
    return res;
}

int soSanhThoiGian(Time a, Time b) {
    if (a.hour < b.hour) return -1;
    if (a.hour > b.hour) return 1;
    if (a.min < b.min) return -1;
    if (a.min > b.min) return 1;
    return 0;
}

Time timThoiGianNganNhatLoaiA(int n, CT* a) {
    Time thoiGianNganNhat;
    thoiGianNganNhat.hour = 24;
    thoiGianNganNhat.min = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].type == 'A') {
            Time tg = tinhKhoangThoiGian(a[i].startTime, a[i].endTime);
            if (soSanhThoiGian(tg, thoiGianNganNhat) < 0) {
                thoiGianNganNhat = tg;
            }
        }
    }
    return thoiGianNganNhat;
}

void inCChuyenTauCoThoiGianNganHonA(int n, CT* a, Time thoiGianA) {
    printf("\nCac chuyen tau loai C co thoi gian di chuyen ngan hon chuyen tau loai A:\n");
    for (int i = 0; i < n; i++) {
        if (a[i].type == 'C') {
            Time tg = tinhKhoangThoiGian(a[i].startTime, a[i].endTime);
            if (soSanhThoiGian(tg, thoiGianA) < 0) {
                xuat(a[i]);
            }
        }
    }
}

CT* timChuyenTauDiChuyenDaiNhat(int n, CT* a) {
    CT* chuyenTauDaiNhat = &a[0];
    Time thoiGianDaiNhat = tinhKhoangThoiGian(a[0].startTime, a[0].endTime);

    for (int i = 1; i < n; i++) {
        Time tg = tinhKhoangThoiGian(a[i].startTime, a[i].endTime);
        if (soSanhThoiGian(tg, thoiGianDaiNhat) > 0) {
            chuyenTauDaiNhat = &a[i];
            thoiGianDaiNhat = tg;
        }
    }

    return chuyenTauDaiNhat;
}

void inChuyenTauCungGaDiVaGaDen(int n, CT* a) {
    int printed[100] = {0}; 

    printf("\nCac chuyen tau co cung ga di va ga den:\n");

    for (int i = 0; i < n; i++) {
        int found = 0; 
        for (int j = i + 1; j < n; j++) {
            if (strcmp(a[i].gaDi, a[j].gaDi) == 0 && strcmp(a[i].gaDen, a[j].gaDen) == 0) {
                if (!printed[i]) {
                    xuat(a[i]);
                    printed[i] = 1;
                }
                if (!printed[j]) {
                    xuat(a[j]);
                    printed[j] = 1;
                }
                found = 1;
            }
        }
    }
}

CT* timChuyenTauKhoiHanhMuonNhat(int n, CT* a) {
    CT* chuyenTauMuonNhat = NULL;
    Time thoiGianMuonNhat;
    thoiGianMuonNhat.hour = -1;
    thoiGianMuonNhat.min = -1;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(a[i].gaDi, a[j].gaDi) == 0 && strcmp(a[i].gaDen, a[j].gaDen) == 0) {
                if (soSanhThoiGian(a[i].startTime, a[j].startTime) > 0) {
                    if (soSanhThoiGian(a[i].startTime, thoiGianMuonNhat) > 0) {
                        chuyenTauMuonNhat = &a[i];
                        thoiGianMuonNhat = a[i].startTime;
                    }
                } else {
                    if (soSanhThoiGian(a[j].startTime, thoiGianMuonNhat) > 0) {
                        chuyenTauMuonNhat = &a[j];
                        thoiGianMuonNhat = a[j].startTime;
                    }
                }
            }
        }
    }

    return chuyenTauMuonNhat;
}

void timVaInChuyenTauTheoGaDiVaGaDen(int n, CT* a, const char* gaDi, const char* gaDen) {
    Time thoiGianNganNhat;
    thoiGianNganNhat.hour = 24;
    thoiGianNganNhat.min = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].gaDi, gaDi) == 0 && strcmp(a[i].gaDen, gaDen) == 0) {
            Time tg = tinhKhoangThoiGian(a[i].startTime, a[i].endTime);
            if (soSanhThoiGian(tg, thoiGianNganNhat) < 0) {
                thoiGianNganNhat = tg;
            }
        }
    }

    printf("\nCac chuyen tau tu %s den %s co thoi gian di chuyen ngan nhat:\n", gaDi, gaDen);
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].gaDi, gaDi) == 0 && strcmp(a[i].gaDen, gaDen) == 0) {
            Time tg = tinhKhoangThoiGian(a[i].startTime, a[i].endTime);
            if (soSanhThoiGian(tg, thoiGianNganNhat) == 0) {
                xuat(a[i]);
            }
        }
    }
}

int main() {
    FILE *f;
    
    int n;
    CT* a = NULL;

    docFile(&n, &a, f);
    
    if (a == NULL) {
        printf("Khong doc duoc file!\n");
        return 1;
    }
    
    printf("Danh sach thong tin chuyen tau:\n");
    xuat(n, a);
    
    // Tinh tong thoi gian di chuyen cua chuyen tau loai A
    int check;
    Time res1 = tinhTongThoiGianDiChuyenTau(n, a, 'A', &check);
    if (check) {
        printf("\nTong thoi gian di chuyen cua chuyen tau loai A: %02d:%02d\n", res1.hour, res1.min);
    } else {
        printf("\nKhong co chuyen tau loai A\n");
    }
    
    // Tim thoi gian di chuyen ngan nhat cua chuyen tau loai A
    Time thoiGianNganNhatA = timThoiGianNganNhatLoaiA(n, a);
    
    // In thong tin cac chuyen tau loai C co thoi gian di chuyen ngan hon chuyen tau loai A
    inCChuyenTauCoThoiGianNganHonA(n, a, thoiGianNganNhatA);
    
    // Tim va in ra chuyen tau co thoi gian di chuyen dai nhat
    CT* chuyenTauDaiNhat = timChuyenTauDiChuyenDaiNhat(n, a);
    printf("\nChuyen tau co thoi gian di chuyen dai nhat:\n");
    xuat(*chuyenTauDaiNhat);

    // In thong tin cac chuyen tau co cung ga di va ga den
    inChuyenTauCungGaDiVaGaDen(n, a);

    // Tim va in ra chuyen tau co thoi gian khoi hanh muon nhat trong cac chuyen tau cung ga di va ga den
    CT* chuyenTauMuonNhat = timChuyenTauKhoiHanhMuonNhat(n, a);
    if (chuyenTauMuonNhat != NULL) {
        printf("\nChuyen tau co thoi gian khoi hanh muon nhat trong cac chuyen tau cung ga di va ga den:\n");
        xuat(*chuyenTauMuonNhat);
    } else {
        printf("\nKhong co chuyen tau nao co cung ga di va ga den.\n");
    }

    // Tim va in ra chuyen tau co thoi gian di chuyen ngan nhat theo ga di va ga den nhap vao
    char gaDi[20], gaDen[20];
    printf("\nNhap ga di: ");
    gets(gaDi); fflush(stdin);
    printf("Nhap ga den: ");
    gets(gaDen); fflush(stdin);
    timVaInChuyenTauTheoGaDiVaGaDen(n, a, gaDi, gaDen);

    free(a);
    return 0;
}
