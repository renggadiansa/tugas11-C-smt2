#include <stdio.h>

typedef struct Pegawai {
    int NIP;
    char nama[50];
    char alamat[100];
    char golongan;
} Pegawai;

Pegawai dataPegawai[100];
int jumlahPegawai = 0;

int cariIndexBerdasarkanNIP(int nip);

void inputPegawai() {
    if (jumlahPegawai >= 100) {
        printf("Data pegawai sudah penuh!\n");
        return;
    }

    printf("\nInput Data Pegawai:\n");
    printf("NIP: ");
    scanf("%d", &dataPegawai[jumlahPegawai].NIP);
    printf("Nama: ");
    scanf("%s", dataPegawai[jumlahPegawai].nama);
    printf("Alamat: ");
    scanf("%s", dataPegawai[jumlahPegawai].alamat);
    printf("Golongan: ");
    scanf("  %c", &dataPegawai[jumlahPegawai].golongan);

    jumlahPegawai++;
    printf("Data pegawai berhasil ditambahkan!\n");
}

void outputPegawai() {
    if (jumlahPegawai == 0) {
        printf("Data pegawai masih kosong!\n");
        return;
    }

    printf("\nDaftar Data Pegawai:\n");
    for (int i = 0; i < jumlahPegawai; i++) {
        printf("%d. NIP: %d, Nama: %s, Alamat: %s, Golongan: %c\n", i + 1, dataPegawai[i].NIP, dataPegawai[i].nama, dataPegawai[i].alamat, dataPegawai[i].golongan);
    }
}

void cariPegawai() {
    int NIP;
    printf("\nMasukkan NIP pegawai yang dicari: ");
    scanf("%d", &NIP);

    int index = cariIndexBerdasarkanNIP(NIP);
    if (index != -1) {
        printf("Pegawai ditemukan:\n");
        printf("NIP: %d, Nama: %s, Alamat: %s, Golongan: %c\n", dataPegawai[index].NIP, dataPegawai[index].nama, dataPegawai[index].alamat, dataPegawai[index].golongan);
    } else {
        printf("Pegawai dengan NIP %d tidak ditemukan.\n", NIP);
    }
}

void sisipDataSebelum() {
    int NIP;
    printf("\nMasukkan NIP pegawai yang akan disisip sebelum: ");
    scanf("%d", &NIP);

    int index = cariIndexBerdasarkanNIP(NIP);
    if (index != -1 && jumlahPegawai < 100) {
        for (int i = jumlahPegawai; i > index; i--) {
            dataPegawai[i] = dataPegawai[i - 1];
        }

        printf("Masukkan data pegawai baru:\n");
        printf("NIP: ");
        scanf("%d", &dataPegawai[index].NIP);
        printf("Nama: ");
        scanf("%s", dataPegawai[index].nama);
        printf("Alamat: ");
        scanf("%s", dataPegawai[index].alamat);
        printf("Golongan: ");
        scanf(" %c", &dataPegawai[index].golongan);

        jumlahPegawai++;
        printf("Data pegawai berhasil disisipkan!\n");
    } else {
        printf("Tidak dapat menyisipkan data!\n");
    }
}

void sisipDataSesudah() {
    int NIP;
    printf("\nMasukkan NIP pegawai yang akan disisip sesudah: ");
    scanf("%d", &NIP);

    int index = cariIndexBerdasarkanNIP(NIP);
    if (index != -1 && jumlahPegawai < 100) {
        for (int i = jumlahPegawai; i > index + 1; i--) {
            dataPegawai[i] = dataPegawai[i - 1];
        }

        printf("Masukkan data pegawai baru:\n");
        printf("NIP: ");
        scanf("%d", &dataPegawai[index + 1].NIP);
        printf("Nama: ");
        scanf("%s", dataPegawai[index + 1].nama);
        printf("Alamat: ");
        scanf("%s", dataPegawai[index + 1].alamat);
        printf("Golongan: ");
        scanf("  %c", &dataPegawai[index + 1].golongan);

        jumlahPegawai++;
        printf("Data pegawai berhasil disisipkan!\n");
    } else {
        printf("Tidak dapat menyisipkan data!\n");
    }
}

void hapusData() {
    int NIP;
    printf("\nMasukkan NIP pegawai yang akan dihapus: ");
    scanf("%d", &NIP);

    int index = cariIndexBerdasarkanNIP(NIP);
    if (index != -1) {
        for (int i = index; i < jumlahPegawai - 1; i++) {
            dataPegawai[i] = dataPegawai[i + 1];
        }
        jumlahPegawai--;
        printf("Data pegawai berhasil dihapus!\n");
    } else {
        printf("Pegawai dengan NIP %d tidak ditemukan.\n", NIP);
    }
}

int cariIndexBerdasarkanNIP(int nip) {
    for (int i = 0; i < jumlahPegawai; i++) {
        if (dataPegawai[i].NIP == nip) {
            return i;
        }
    }
    return -1;}


int soal7() {
    int pilihan;

    do {
        printf("\nMenu Pencarian Data Pegawai:\n");
        printf("1. Input Data Pegawai\n");
        printf("2. Output Data Pegawai\n");
        printf("3. Cari Pegawai\n");
        printf("4. Sisip Data Sebelum\n");
        printf("5. Sisip Data Sesudah\n");
        printf("6. Hapus Data\n");
        printf("7. Keluar\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                inputPegawai();
                break;
            case 2:
                outputPegawai();
                break;
            case 3:
                cariPegawai();
                break;
            case 4:
                sisipDataSebelum();
                break;
            case 5:
                sisipDataSesudah();
                break;
            case 6:
                hapusData();
                break;
            case 7:
                break;
            default:
                printf("Pilihan tidak valid!");
        }
    } while (pilihan != 7);

    return 0;
}
