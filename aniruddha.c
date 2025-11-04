#include <stdio.h>
#include <stdlib.h>


struct hospital {
    int appointment_id;
    char name[50];
    int age;
    float fees_to_pay;
};


void search_patient(struct hospital patient[], int n, int search_id) {
    for (int i = 0; i < n; i++) {
        if (patient[i].appointment_id == search_id) {
            printf("\nAPPOINTMENT ID: %d\n", patient[i].appointment_id);
            printf("NAME: %s\n", patient[i].name);
            printf("AGE: %d\n", patient[i].age);
            printf("FEES: %.2f\n", patient[i].fees_to_pay);
            printf("\n----------------------------------------\n");
            break;
        }
        else{
            printf("patient is not found in information");
        }
    }
}



void sort_by_fees_ascending(struct hospital patient[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (patient[j].fees_to_pay > patient[j + 1].fees_to_pay) {
                struct hospital temp = patient[j];
                patient[j] = patient[j + 1];
                patient[j + 1] = temp;
            }
        }
    }
}

// Function to sort patients by fees (descending)
void sort_by_fees_descending(struct hospital patient[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (patient[j].fees_to_pay < patient[j + 1].fees_to_pay) {
                struct hospital temp = patient[j];
                patient[j] = patient[j + 1];
                patient[j + 1] = temp;
            }
        }
    }
}


// Function to display all patient data
void display_patients(struct hospital patient[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nAPPOINTMENT ID: %d\n", patient[i].appointment_id);
        printf("NAME: %s\n", patient[i].name);
        printf("AGE: %d\n", patient[i].age);
        printf("FEES: %.2f\n", patient[i].fees_to_pay);
        printf("\n----------------------------------------\n");
    }
}

int main() {
    int n;
    printf("Enter number of patients coming today: ");
    scanf("%d", &n);
    struct hospital patient[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for patient %d:\n", i + 1);
        printf("Enter appointment ID: ");
        scanf("%d", &patient[i].appointment_id);

        printf("Enter name of patient: ");
        scanf("%s", patient[i].name);

        printf("Enter age of patient: ");
        scanf("%d", &patient[i].age);

        printf("Enter fees to pay: ");
        scanf("%f", &patient[i].fees_to_pay);
    }

    sort_by_fees_descending(patient, n);
    printf("\n\nPatient Data Sorted by Fees (Descending):\n");
    display_patients(patient, n);

    while (1) {
        int c;
        printf("\nMENU\n1. Search particular patient\n2. Sort by fees (ascending)\n3. Sort by fees (descending)\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1: {
                int search_id;
                printf("Enter appointment ID of patient to search: ");
                scanf("%d", &search_id);
                search_patient(patient, n, search_id);
                break;
            }
            case 2:
                sort_by_fees_ascending(patient, n);
                printf("\nPatient Data Sorted by Fees (Ascending):\n");
                display_patients(patient, n);
                break;
            case 3:
                sort_by_fees_descending(patient, n);
                printf("\nPatient Data Sorted by Fees (Descending):\n");
                display_patients(patient, n);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

