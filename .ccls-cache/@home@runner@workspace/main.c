//File: project1_kayak_rental.c
//Author: Eva Mae Miller
//Date: 06/22/2025
//Description: This program calculates the total charge for renting a kayak based off the type, number of hours, days, and specific rates. It prompts the user for information regarding the kayak and amount of time they rented it for. This programs then will display the total charge for the user. 

#include <stdio.h>
   // define the prices of each type of kayak
  #define solo_flat_fee 25
  #define solo_hourly_rate 10
  #define solo_max_perday 60

  #define tandem_flat_fee 35
  #define tandem_hourly_rate 12
  #define tandem_max_perday 80

  #define fishing_flat_fee 45
  #define fishing_hourly_rate 15
  #define fishing_max_perday 100

  #define pedal_flat_fee 50
  #define pedal_hourly_rate 18
  #define pedal_max_perday 120

  int main(void) {
    printf("Please select from four kayak types: 1, 2, 3, and 4\n");
        printf("Enter kayak selection: ");

  int kayakType;
  scanf("%d",  &kayakType); //read the type

  if (kayakType < 1 || kayakType > 4) { // check if it is a valid type
    printf("Invalid selection. Select from 1 to 4.\n"); 
    return 0; 
    }

  int days, hours;  //get the amount of days and hours rented
    printf("Enter days: ");
    scanf ("%d", &days);

    printf("Enter hours: "); 
  scanf("%d", &hours); 
    if (hours < 0 || hours >= 24) { // check if hours are valid
      printf("Invalid hours.\n");  
      return 0;
    }
    int totalCharge = 0;
    int maxDailyRate = 0, hourlyRate = 0;
    int extraHours = hours - 2;
// If it is rented for less than one day
    if (days == 0) {
        if (hours <= 2) {
            if (kayakType == 1)
                totalCharge = solo_flat_fee;
            else if (kayakType == 2)
                totalCharge = tandem_flat_fee;
            else if (kayakType == 3)
                totalCharge = fishing_flat_fee;
            else
                totalCharge = pedal_flat_fee;
        } else {
            // If hours it is rented for more than 2 hours (flat free + houry rate) and capping the total with the max daily charge
            if (kayakType == 1) {
                maxDailyRate = solo_max_perday;
                hourlyRate = solo_hourly_rate;
                totalCharge = solo_flat_fee + extraHours * hourlyRate;
                if (totalCharge > maxDailyRate)
                  totalCharge = maxDailyRate;
            } else if (kayakType == 2) {
                maxDailyRate = tandem_max_perday;
                hourlyRate = tandem_hourly_rate;
                totalCharge = tandem_flat_fee + extraHours * hourlyRate;
                if (totalCharge > maxDailyRate)
                  totalCharge = maxDailyRate;
            } else if (kayakType == 3) {
                maxDailyRate = fishing_max_perday;
                hourlyRate = fishing_hourly_rate;
                totalCharge = fishing_flat_fee + extraHours * hourlyRate;
                if (totalCharge > maxDailyRate)
                  totalCharge = maxDailyRate;
            } else {
                maxDailyRate = pedal_max_perday;
                hourlyRate = pedal_hourly_rate;
                totalCharge = pedal_flat_fee + extraHours * hourlyRate;
                if (totalCharge > maxDailyRate)
                  totalCharge = maxDailyRate;
            }
        }
    } else {
        // If renting for days (one or more)
        // max daily rate + possible hourly charges based from the different kayak types
        // capping the total with the max daily charge again
        if (kayakType == 1) {
            maxDailyRate = solo_max_perday;
            hourlyRate = solo_hourly_rate;
        } else if (kayakType == 2) {
            maxDailyRate = tandem_max_perday;
            hourlyRate = tandem_hourly_rate;
        } else if (kayakType == 3) {
            maxDailyRate = fishing_max_perday;
            hourlyRate = fishing_hourly_rate;
        } else {
            maxDailyRate = pedal_max_perday;
            hourlyRate = pedal_hourly_rate;
        }
        // calculate addition hours and cap it with the max daily rate
        totalCharge = days * maxDailyRate;
        int extra = hours * hourlyRate;
        if (extra > maxDailyRate)
            extra = maxDailyRate;
        totalCharge += extra;
    }
    // print the total charge
    printf("Charge($): %d\n", totalCharge);
    return 0;
  }
