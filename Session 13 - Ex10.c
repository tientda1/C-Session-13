#include <stdio.h>

void addAllItem(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Phan tu thu arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

void showItems(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Phan tu thu arr[%d] co gia tri %d\n", i, arr[i]);
    }
}

void insertItems(int arr[], int *size, int index, int value) {
    if (index < 1 || index > *size + 1) {
        printf("Vi tri khong hop le! Hay nhap trong khoang 1 den %d.\n", *size + 1);
        return;
    }
    for (int i = *size; i >= index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index - 1] = value;
    (*size)++;
}

void updateItem(int arr[], int index, int value) {
    arr[index - 1] = value;
}

void deleteItem(int arr[], int *size, int index) {
    if (index < 1 || index > *size) {
        printf("Vi tri khong hop le! Hay nhap trong khoang 1 den %d.\n", *size);
        return;
    }
    for (int i = index - 1; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void sortArray(int arr[], int size, int ascending) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if ((ascending && arr[i] > arr[j]) || (!ascending && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int linearSearch(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i + 1;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int value) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            return mid + 1;
        }
        if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[100];
    int size = 0;
    int choose, value, index;
    do {
        printf("MENU:\n");
        printf("1. Nhap so luong phan tu va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf("7. Tim kiem phan tu nhap vao\n");
        printf("8. Thoat\n");

        printf("Moi ban chon case: ");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                printf("Moi ban nhap so luong phan tu: ");
                scanf("%d", &size);
                addAllItem(arr, size);
                break;
            case 2:
                showItems(arr, size);
                break;
            case 3:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                printf("Nhap vi tri can them (bat dau tu 1): ");
                scanf("%d", &index);
                insertItems(arr, &size, index, value);
                break;
            case 4:
                printf("Nhap vi tri can sua (bat dau tu 1): ");
                scanf("%d", &index);
                printf("Nhap gia tri moi: ");
                scanf("%d", &value);
                updateItem(arr, index, value);
                break;
            case 5:
                printf("Nhap vi tri can xoa (bat dau tu 1): ");
                scanf("%d", &index);
                deleteItem(arr, &size, index);
                break;
            case 6:
                printf("Chon kieu sap xep:\n");
                printf("a. Giam dan\n");
                printf("b. Tang dan\n");
                char answer;
                getchar();
                scanf("%c", &answer);
                if (answer == 'a') {
                    sortArray(arr, size, 0);
                } else if (answer == 'b') {
                    sortArray(arr, size, 1);
                }
                break;
            case 7:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                printf("Chon phuong phap tim kiem:\n");
                printf("a. Tim kiem tuyen tinh\n");
                printf("b. Tim kiem nhi phan\n");
                getchar();
                scanf("%c", &answer);
                if (answer == 'a') {
                    index = linearSearch(arr, size, value);
                } else if (answer == 'b') {
                    sortArray(arr, size, 1);
                    index = binarySearch(arr, size, value);
                }
                if (index != -1) {
                    printf("Tim thay phan tu tai vi tri %d\n", index);
                } else {
                    printf("Khong tim thay phan tu\n");
                }
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le, moi ban chon lai!\n");
                break;
        }
    } while (choose != 8);

    return 0;
}

