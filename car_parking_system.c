#include <stdio.h>
#include <stdbool.h>
#include <string.h> 
#include <stdlib.h> 

#define MAX_PARKING_SLOTS 30
#define OWNER_NAME_LENGTH 20
int keepcount=0;

struct car_parking {
    char owners_name[OWNER_NAME_LENGTH];
    int vehicle_Reg;
    int parking_slot;
   
};


struct car_parking parking_slotA[MAX_PARKING_SLOTS];

bool is_occupied(int position) {
    
    if (strlen(parking_slotA[position].owners_name) > 0) { 
        //printf("Parking slot %d is occupied\n", position);
        return true;
    } else {
        return false;
    }
}

void display_parking_slot() {
    if(keepcount==0){
       printf("The parking lot is empty");
       printf("\n---------------------------------------------------\n");
       return;
    }
    int count=0;
    int min=0;
    for (int i = 0; i < MAX_PARKING_SLOTS; i++) {
        if (strlen(parking_slotA[i].owners_name) > 0) { 
          /*  printf("Parking slot %d is occupied by %s Reg: %d\n", i, parking_slotA[i].owners_name, parking_slotA[i].vehicle_Reg); */
          count++;
        } else {
            //printf("Parking slot %d is available\n", i);
            min++;
        }
    }
    printf("Parking spaces occupied: %d", count);
    printf("\nParking spaces available:  %d", min);
    printf("\n------------------------------------------------\n");
}

void search_for_car() {
    if(keepcount==0){
       printf("The parking lot is empty");
       printf("\n---------------------------------------------------\n");
       return;
    }
    int VehicleReg;
    printf("Enter the vehicle registration number: ");
    scanf("%d", &VehicleReg);

    bool found = false;
    for (int i = 0; i < MAX_PARKING_SLOTS; i++) {
        if (parking_slotA[i].vehicle_Reg == VehicleReg && strlen(parking_slotA[i].owners_name) > 0) { 
            printf("The car with registration %d is parked in parking slot %d\n", VehicleReg, i);
            printf("The owner of the car is %s\n", parking_slotA[i].owners_name);
            found = true;
        }
    }

    if (!found) {
        printf("Car with registration %d not found in the parking lot.\n", VehicleReg);
    }

    
}

void allocate_parking_space() {
    int choice=0;
    if(keepcount==30){
        printf("The parking lot is full:");
        printf("\n---------------------------------------------------\n");
        return;
    }
    while(choice!=3){
        printf("1. Allocate using order: \n");
        printf("2. Enter the position to allocate: \n");
        printf("3. To go back to main menu: \n");
        printf("\n---------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
              for(int position=0;position<MAX_PARKING_SLOTS;position++){
             if (!is_occupied(position)) {
                printf("Enter the name of the owner: ");
                scanf("%s", parking_slotA[position].owners_name);

                printf("Enter the vehicle registration number: ");
                scanf("%d", &parking_slotA[position].vehicle_Reg);
                parking_slotA[position].parking_slot = position;
                printf("Parking slot %d allocated to %s (Reg: %d)\n", position, parking_slotA[position].owners_name, parking_slotA[position].vehicle_Reg);
                printf("\n-------------------------------------\n");
                keepcount++;
             }
            }
            printf("\n The parkinglot is full\n");
        return;
        break;
     
        case 2:
              int position;
              printf("Enter the parking slot number to allocate: ");
              scanf("%d", &position);
              if (is_occupied(position)) {
                printf("The parking slot %d is already occupied.\n", position);
                break;

              }
               printf("Enter the name of the owner: ");
                scanf("%s", parking_slotA[position].owners_name);

                printf("Enter the vehicle registration number: ");
                scanf("%d", &parking_slotA[position].vehicle_Reg);
                parking_slotA[position].parking_slot = position;
                printf("Parking slot %d allocated to %s (Reg: %d)\n", position, parking_slotA[position].owners_name, parking_slotA[position].vehicle_Reg);
                printf("\n-----------------------------------------\n");
                keepcount++;
        

       ;
        break;
        case 3:
              return;
         default:
              printf("Invalid choice.\n");
              printf("\n----------------------------------------------\n");
    }
}
    

        return;
    }
 

void deallocate_parking_space() {
    int choice=0;
    if(keepcount==0){
       printf("The parking lot is empty");
       printf("\n---------------------------------------------------\n");
       return;
    }
    while(choice!=3){
        printf("1. Dealocate using order: \n");
        printf("2. Enter the position to deallocate: \n");
        printf("3. To go back to main menu: \n");
        printf("\n---------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice){
        case 1:
              for(int position=0;position<MAX_PARKING_SLOTS;position++){
             if (is_occupied(position)) {
                parking_slotA[position].owners_name[0] = '\0';
                parking_slotA[position].vehicle_Reg = 0;  
                parking_slotA[position].parking_slot = -1; 
                printf("The parking slot %d is now available.\n", position);
        
        printf("Parking slot %d was deallocated to %s (Reg: %d)\n", position, parking_slotA[position].owners_name, parking_slotA[position].vehicle_Reg);
        printf("\n---------------------------------------------------\n");
        return;
             }
        }
                 printf("\n The Parkinglot is empty");
             
             printf("\n---------------------------------------------------\n");
             return;
        
        keepcount--;
        printf("\n-------------------------------------------\n");
        break;
        case 2: 
              int position;
              printf("Enter the parking slot number to deallocate: ");
              scanf("%d", &position);
              if(position<01 || position >30){
                  printf("Enter a valid position");
                  break;
              }
              if (!is_occupied(position)) {
                printf("The parking slot %d is not occupied.\n", position);
                   return;
              }
              parking_slotA[position].owners_name[0] = '\0';
              parking_slotA[position].vehicle_Reg = 0;  
              parking_slotA[position].parking_slot = -1; 
              printf("The parking slot %d is now available.\n", position);
              printf("\n---------------------------------------------------\n");
              keepcount--;
        return;
        
        break;
        default:
              printf("Invalid choice.\n");
              printf("\n---------------------------------------------------\n");
    }
    
}

}



int main() {
    
    for(int i=0; i<MAX_PARKING_SLOTS; i++){
        parking_slotA[i].owners_name[0] = '\0'; 
        parking_slotA[i].vehicle_Reg = 0;
        parking_slotA[i].parking_slot = -1;
    }

    printf("Welcome to CU North Compass Parking System\n");
    printf("---------------------------------------------------------------------------------------------\n");

    int choice, pos;

    while (1) {
        
        printf("\n1. Allocate Parking Space\n");
        printf("2. Search for a car's parking slot\n");
        printf("3. Parkinglot Status\n");
        printf("4. Deallocate a parking slot\n");
        printf("5. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        switch (choice) {
            case 1:
                
                
                allocate_parking_space();
                break;
            case 2:
                search_for_car();
                break;
            case 3:
                display_parking_slot(); 
                break;
            case 4:
                deallocate_parking_space();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}
