/*
 * Program   : Crop Yield Analysis System
 * Module    : Software Quality Assurance (COMP 30010.1)
 * Project   : Agricultural Production Analysis System
 * Task      : Task 1c - Algorithm with Switch and If-Else
 * Description: This program analyzes crop yield data based on crop type
 *              and season, then evaluates productivity levels to generate
 *              trend reports for decision-making.
 */

#include <stdio.h>

int main() {

    int cropType;       /* 1=Wheat, 2=Rice, 3=Maize, 4=Cotton */
    int season;         /* 1=Spring, 2=Summer, 3=Autumn, 4=Winter */
    float yieldValue;   /* Yield in tons per hectare */
    float threshold;    /* Productivity threshold per crop type */
    char cropName[20];
    char seasonName[20];

    /* -------- INPUT SECTION -------- */
    printf("========================================\n");
    printf("  Agricultural Production Analysis System\n");
    printf("  Crop Yield Analysis - FR1\n");
    printf("========================================\n\n");

    printf("Select Crop Type:\n");
    printf("  1. Wheat\n");
    printf("  2. Rice\n");
    printf("  3. Maize\n");
    printf("  4. Cotton\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &cropType);

    printf("\nSelect Season:\n");
    printf("  1. Spring\n");
    printf("  2. Summer\n");
    printf("  3. Autumn\n");
    printf("  4. Winter\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &season);

    printf("\nEnter Yield Value (tons/hectare): ");
    scanf("%f", &yieldValue);

    /* -------- SWITCH: Identify Crop & Set Threshold -------- */
    switch (cropType) {
        case 1:
            sprintf(cropName, "Wheat");
            threshold = 3.5;
            break;
        case 2:
            sprintf(cropName, "Rice");
            threshold = 4.0;
            break;
        case 3:
            sprintf(cropName, "Maize");
            threshold = 4.8;    //changed maize threshold from 5 to 4,8
            break;
        case 4:
            sprintf(cropName, "Cotton");
            threshold = 2.5;
            break;
        default:
            printf("\nERROR: Invalid crop type selected.\n");
            return 1;
    }

    /* -------- SWITCH: Identify Season -------- */
    switch (season) {
        case 1:
            sprintf(seasonName, "Spring");
            break;
        case 2:
            sprintf(seasonName, "Summer");
            break;
        case 3:
            sprintf(seasonName, "Autumn");
            break;
        case 4:
            sprintf(seasonName, "Winter");
            break;
        default:
            printf("\nERROR: Invalid season selected.\n");
            return 1;
    }

    /* -------- IF-ELSE: Evaluate Productivity & Generate Report -------- */
    printf("\n========================================\n");
    printf("  CROP YIELD TREND REPORT\n");
    printf("========================================\n");
    printf("  Crop     : %s\n", cropName);
    printf("  Season   : %s\n", seasonName);
    printf("  Yield    : %.2f tons/hectare\n", yieldValue);
    printf("  Threshold: %.2f tons/hectare\n", threshold);
    printf("----------------------------------------\n");

    if (yieldValue <= 0) {
        printf("  Status   : INVALID - Yield cannot be zero or negative.\n");
        printf("  Action   : Please re-enter valid yield data.\n");
    }
    else if (yieldValue >= threshold * 1.2) {
        printf("  Status   : EXCELLENT PRODUCTIVITY\n");
        printf("  Trend    : Well above seasonal threshold.\n");
        printf("  Action   : Maintain current farming practices.\n");
    }
    else if (yieldValue >= threshold) {
        printf("  Status   : GOOD PRODUCTIVITY\n");
        printf("  Trend    : Meets seasonal threshold.\n");
        printf("  Action   : Monitor and sustain current inputs.\n");
    }
    else if (yieldValue >= threshold * 0.7) {
        printf("  Status   : LOW PRODUCTIVITY\n");
        printf("  Trend    : Below seasonal threshold.\n");
        printf("  Action   : Review soil quality and fertilizer usage.\n");
    }
    else {
        printf("  Status   : CRITICAL - VERY LOW PRODUCTIVITY\n");
        printf("  Trend    : Significantly below threshold.\n");
        printf("  Action   : Immediate intervention required.\n");
    }

    printf("========================================\n");
    printf("  Report generated successfully.\n");
    printf("========================================\n");

    return 0;
}
