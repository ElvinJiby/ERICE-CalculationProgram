/*
 * 09/02/2023
 * Computer Programming II - Assignment 1
 * Made by Elvin Jiby in VSCode
 *
 * A C Program that lets a user calculate their BMI, blood pressure or
 * do a cardiac risk score assessment (ERICE risk score) based on the charts
 * in the assignment details pdf (named assign1details.pdf)
*/

#include <stdio.h>

// Prototype Functions //
double bodyMassIndex(double x, double y); // BMI function prototype
void printBMI(double z); // Print BMI Results function prototype
double averageSys(int systolic[]); // Average Systolic Reading function prototype
double averageDia(int diastolic[]); // Average Diastolic Reading function prototype
void printBP(double a, double b); // Print Blood Pressure Results function prototype
int getErice(int q, int r, int s, int t, double u, double v); // ERICE Score Calculation function prototype
void printERICE(int w); // Print ERICE Results function prototype


int main(void)
{
    int choice;

    // User Choice //
    printf("Please choose the preferred assessment:\n");
    printf("Enter 1 for Body Mass Index\n");
    printf("Enter 2 for Blood Pressure\n");    
    printf("Enter 3 for Cardiac Risk Score\n");
    scanf("%d", &choice);

    // If user doesn't pick any of the options //
    while (choice < 1 || choice > 3)
    {
        printf("Invalid choice.\n");
        printf("Please choose the preferred assessment:\n");
        printf("Enter 1 for Body Mass Index\n");
        printf("Enter 2 for Blood Pressure\n");    
        printf("Enter 3 for Cardiac Risk Score\n"); 
        scanf("%d", &choice);
    }

    // Body Mass Index (BMI) //
    if (choice == 1)
    {
        // Variables //
        double weight;
        double height;

        // User Input //
        printf("Please enter your weight in kilograms:\n");
        scanf("%lf", &weight);

        while(weight <= 0)
        {
            printf("Invalid weight.\n");
            printf("Please enter your weight in kilograms:\n");
            scanf("%lf", &weight);            
        }

        printf("Please enter your height in metres:\n");
        scanf("%lf", &height);

        while (height <= 0)
        {
            printf("Invalid height.\n");
            printf("Please enter your height in metres:\n");
            scanf("%lf", &height);
        }

        // Computation //
        double BMI = bodyMassIndex(weight, height);

        // Output //  
        printf("BMI: %.1lf", BMI);
        printBMI(BMI);

        return 0;
    }

    // Blood Pressure Assessment //
    if (choice == 2)
    {
        // Variables //
        int systolic[5];
        int diastolic[5];
        double avg_systolic = 0;
        double avg_diastolic = 0;
        int i;
        int j;

        // Systolic Readings //
        printf("Please enter five systolic blood pressure readings:\n");

        for (i=0; i<5; i++)
        {
            printf("Reading %d: ", i+1);
            scanf("%d", &systolic[i]);
            printf("\n");
        }

        // Diastolic Readings //
        printf("Please enter five diastolic blood pressure readings:\n");

        for (j=0; j<5; j++)
        {
            printf("Reading %d: ", j+1);
            scanf("%d", &diastolic[j]);
            printf("\n");
        }

        // Average Readings //
        avg_systolic = averageSys(systolic);
        avg_diastolic = averageDia(diastolic);

        /* User Info Summary */
        printf("\nAverage Systolic Reading: %.0lf\n", avg_systolic);
        printf("Average Diastolic Reading: %.0lf\n", avg_diastolic);

        // Output //
        printBP(avg_systolic, avg_diastolic);

        return 0;
    }

    // Cardiac Risk Score //
    else if(choice == 3)
    {        
        // Variables //
        int systolic[5];
        int i;
        double avg_systolic = 0;
        int age;
        int gender;
        int diabetics;
        int smokers;
        double cholesterol;

        // Age //
        printf("Please enter your age:\n");
        scanf("%d", &age);

        while(age < 30) //Error Handling
        {
            printf("Unsuitable age.\n");
            printf("Please enter your age:\n");
            scanf("%d", &age);
        }

        // Gender //
        printf("Please enter your gender: \n");
        printf("(Enter 1 for Male, 2 for Female)\n");
        scanf("%d", &gender);

        while(gender < 1 || gender > 2) //Error Handling 
        {
            printf("Invalid choice.\n");
            printf("Please enter your gender: \n");
            printf("(Enter 1 for Male, 2 for Female)\n");
            scanf("%d", &gender);           
        }

        // Diabetics //
        printf("Are you diabetic?\n");
        printf("(Enter 1 for Yes, 2 for No)\n");
        scanf("%d", &diabetics);

        while(diabetics < 1 || diabetics > 2) //Error Handling
        {
            printf("Invlid choice.\n");
            printf("Are you diabetic?\n");
            printf("(Enter 1 for Yes, 2 for No)\n");
            scanf("%d", &diabetics);
        }

        // Smokers //
        printf("Do you smoke?\n");
        printf("(Enter 1 for Yes, 2 for No)\n");
        scanf("%d", &smokers);

        while(smokers < 1 || smokers > 2) //Error Handling
        {
            printf("Invalid choice.\n");
            printf("Do you smoke?\n");
            printf("(Enter 1 for Yes, 2 for No)\n");
            scanf("%d", &smokers);        
        }

        // Cholesterol //
        printf("Please enter your cholesterol level:\n");
        scanf("%lf", &cholesterol);

        // Systolic Readings //
        printf("Please enter five systolic blood pressure readings:\n");

        for (i=0; i<5; i++)
        {
            printf("Reading %d: ", i+1);
            scanf("%d", &systolic[i]);
            printf("\n");
        }

        // Average Systolic //
        avg_systolic = averageSys(systolic);

        // ERICE Category Conditions //
        int score_ERICE = getErice(gender, diabetics, smokers, age, cholesterol, avg_systolic);
        printERICE(score_ERICE);

        return 0;
    }

}

// Prototype Function Definitions
double bodyMassIndex(double x, double y) // Function that calculates a BMI given a weight and height
{
    return x / (y * y);
}

void printBMI(double z) // Function that prints BMI category
{
        if (z < 18.5)
    {
        printf("\nYou are underweight.\n");
    }
       
    if (z >= 18.5 && z < 25)
    {
        printf("\nYou are normal.\n");
    }        

    if (z >= 25 && z < 30)
    {
        printf("\nYou are overweight.\n");
    }

    if (z >= 30)
    {
        printf("\nYou are obese.\n");
    }
}

double averageSys(int systolic[]) // Gets the average systolic reading
{
    double sum_systolic = 0;

        // Average Systolic //
        for (int i=0; i<5; i++)
        {
            sum_systolic += systolic[i];
        }
        
    return sum_systolic /= sum_systolic / 5;
}

double averageDia(int diastolic[]) // Gets the average diastolic reading
{
    double sum_diastolic = 0;

        // Average Diastolic //
        for (int j=0; j<5; j++)
        {
            sum_diastolic += diastolic[j];
        }

    return sum_diastolic = sum_diastolic / 5;
}

void printBP(double a, double b)
{
        // High //
        if (a >= 140 || b >= 90)
        {
            printf("\nYour blood pressure is high.\n");
        }

        // Pre-high //
        if ( (a >= 120 && a < 140) && (b >= 80 && b < 90) )
        {
            printf("\nYour blood pressure is pre-high.\n");
        }

        // Ideal //
        if ( (a > 90 && a < 120) && (b > 60 && b < 80) )
        {
            printf("\nYour blood pressure is ideal.\n");
        }

        // Low //
        if (a <= 90 && b <= 60)
        {
            printf("\nYour blood pressure is low.\n");
        }
}


int getErice(int q, int r, int s, int t, double u, double v) // Function that calculates the Cardiac Risk Score based on health parameters
{
    // ERICE Score; 0=Low, 1=Mild, 2=Moderate, 3=Moderate-High, 4=High, 5 = Very High //
    int ERICE;

        //////////////////////////////////////////////
        /////// MALE, DIABETIC, NON-SMOKER ///////////
        //////////////////////////////////////////////

        // Male, Diabetic, t 30-39, Non-smoker //
        if (q == 1 && r == 1 && s == 2 && (t >= 30 && t < 40))
        {
            return ERICE = 0;
        }

        // Male, Diabetic, t 40-49, Non-smoker //
        if (q == 1 && r == 1 && s == 2 && (t >= 40 && t < 50))
        {
            if(v < 160)
            {
                return ERICE = 0;
            }
            else if((v >= 160 && v < 180) && u <= 6.4)
            {
                return ERICE = 0;
            }
            else if((v >= 160 && v < 180) && u >= 6.5)
            {
                return ERICE = 1;
            }
            else if(v >= 180)
            {
                return ERICE = 1;
            }
        } 

        // Male, Diabetic, t 50-59, Non-smoker //
        if (q == 1 && r == 1 && s == 2 && (t >= 50 && t < 60))
        {
            if(v < 140)
            {
                return ERICE = 1;
            }

            else
            {
                return ERICE = 2;
            }
        }

        // Male, Diabetic, t 60-69, Non-smoker //
        if (q == 1 && r == 1 && s == 2 && (t >= 60 && t < 70))
        {
            if(v < 140 && u < 5.2)
            {
                return ERICE = 2;
            }

            else if(v < 140 && u >= 5.2)
            {
                return ERICE = 3;
            }

            else if(v >= 140)
            {
                return ERICE = 4;
            }
        }

        // Male, Diabetic, t 70-79, Non-smoker //
        if (q == 1 && r == 1 && s == 2 && (t >= 70 && t < 80))
        {
            if(v < 140)
            {
                return ERICE = 4;
            }

            else
            {
                return ERICE = 5;
            }
        }

        // Male, Diabetic, t 80 & Onwards, Non-smoker //
        if (q == 1 && r == 1 && s == 2 && t >= 80)
        {
            return ERICE = 5;
        }

        //////////////////////////////////////////////
        ////////// MALE, DIABETIC, SMOKER ////////////
        //////////////////////////////////////////////

        // Male, Diabetic, t 30-39, Smoker //
        if (q == 1 && r == 1 && s == 1 && (t >= 30 && t < 40))
        {
            return ERICE = 0;
        }

        // Male, Diabetic, t 40-49, Smoker //
        if (q == 1 && r == 1 && s == 1 && (t >= 40 && t < 50))
        {
            if(v < 140)
            {
                return ERICE = 0;
            }

            else
            {
                return ERICE = 1;
            }
        } 

        // Male, Diabetic, t 50-59, Smoker //
        if (q == 1 && r == 1 && s == 1 && (t >= 50 && t < 60))
        {
            if(v < 140 && (u < 5.2 || u >= 7.8))
            {
                return ERICE = 1;
            }

            else if(v < 140 && (u >= 5.2 && u < 7.8))
            {
                return ERICE = 2;
            }

            else if(v >= 140 && v < 160)
            {
                return ERICE = 2;
            }

            else
            {
                return ERICE = 3;
            }
        }

        // Male, Diabetic, t 60-69, Smoker //
        if (q == 1 && r == 1 && s == 1 && (t >= 60 && t < 70))
        {
            if(v < 140)
            {
                return ERICE = 3;
            }

            else if(v >= 140 && v < 160)
            {
                return ERICE = 4;
            }

            else if ((v >= 160 && v < 180) && u < 6.5)
            {
                return ERICE = 4;
            }

            else if ((v >= 160 && v < 180) && u >= 6.5)
            {
                return ERICE = 5;
            }

            else
            {
                return ERICE = 5;
            }
        }

        // Male, Diabetic, t 70-79, Smoker //
        if (q == 1 && r == 1 && s == 1 && (t >= 70 && t < 80))
        {
            if (v < 140)
            {
                return ERICE = 4;
            }

            else
            {
                return ERICE = 5;
            }
        }

        // Male, Diabetic, t 80 & Onwards, Smoker //
        if (q == 1 && r == 1 && s == 1 && t >= 80)
        {
            return ERICE = 5;
        }

        //////////////////////////////////////////////
        ////// MALE, NON-DIABETIC, NON-SMOKER /////////
        //////////////////////////////////////////////

            // Male, Non-Diabetic, t 30-39, Non-smoker //
        if (q == 1 && r == 2 && s == 2 && (t >= 30 && t < 40))
        {
            return ERICE = 0;
        }

        // Male, Non-Diabetic, t 40-49, Non-smoker //
        if (q == 1 && r == 2 && s == 2 && (t >= 40 && t < 50))
        {
            return ERICE = 0;
        } 

        // Male, Non-Diabetic, t 50-59, Non-smoker //
        if (q == 1 && r == 2 && s == 2 && (t >= 50 && t < 60))
        {
            if(v < 180)
            {
                return ERICE = 1;
            }

            else if(v >= 180 && u < 5.2)
            {
                return ERICE = 1;
            }

            else
            {
                return ERICE = 2;
            }
        }

        // Male, Non-Diabetic, t 60-69, Non-smoker //
        if (q == 1 && r == 2 && s == 2 && (t >= 60 && t < 70))
        {
            if(v < 140)
            {
                return ERICE = 2;
            }

            else
            {
                return ERICE = 3;
            }
        }

        // Male, Non-Diabetic, t 70-79, Non-smoker //
        if (q == 1 && r == 2 && s == 2 && (t >= 70 && t < 80))
        {
            if(v < 140)
            {
                return ERICE = 3;
            }

            else
            {
                return ERICE = 4;
            }
        }

        // Male, Non-Diabetic, t 80 & Onwards, Non-smoker //
        if (q == 1 && r == 2 && s == 2 && t >= 80)
        {
            return ERICE = 5;
        }

        ///////////////////////////////////////////////
        ///////// MALE, NON-DIABETIC, SMOKER /////////
        ///////////////////////////////////////////////

        // Male, Non-Diabetic, t 30-39, Smoker //
        if (q == 1 && r == 2 && s == 1 && (t >= 30 && t < 40))
        {
           return ERICE = 0;
        }

        // Male, Non-Diabetic, t 40-49, Smoker //
        if (q == 1 && r == 2 && s == 1 && (t >= 40 && t < 50))
        {
            if(v < 160)
            {
                return ERICE = 0;
            }

            else if((v >= 160 && v < 180) && u < 6.5)
            {
                return ERICE = 0;
            }

            else if((v >= 160 && v < 180) && u >= 6.5)
            {
                return ERICE = 1;
            }

            else if(v >= 180 && u < 5.2)
            {
                return ERICE = 0;
            }

            else
            {
                return ERICE = 1;
            }
        } 

        // Male, Non-Diabetic, t 50-59, Smoker //
        if (q == 1 && r == 2 && s == 1 && (t >= 50 && t < 60))
        {
            if(v < 140)
            {
                return ERICE = 1;
            }

            else
            {
                return ERICE = 2;
            }
        }

        // Male, Non-Diabetic, t 60-69, Smoker //
        if (q == 1 && r == 2 && s == 1 && (t >= 60 && t < 70))
        {
            if(v < 140 && u < 5.2)
            {
                return ERICE = 2;
            }

            else if(v < 140 && u >= 5.2)
            {
                return ERICE = 3;
            }

            else
            {
                return ERICE = 4;
            }
        }

        // Male, Non-Diabetic, t 70-79, Smoker //
        if (q == 1 && r == 2 && s == 1 && (t >= 70 && t < 80))
        {
            if(v < 140)
            {
                return ERICE = 4;
            }

            else
            {
                return ERICE = 5;
            }
        }

        // Male, Non-Diabetic, t 80 & Onwards, Smoker //
        if (q == 1 && r == 2 && s == 1 && t >= 80)
        {
            return ERICE = 5;
        }

        //////////////////////////////////////////////
        /////// FEMALE, DIABETIC, NON-SMOKER /////////
        //////////////////////////////////////////////

        // Female, Diabetic, t 30-49*, Non-smoker //
        if (q == 2 && r == 1 && s == 2 && (t >= 30 && t < 50))
        {
            return ERICE = 0;          
        }

        // Female, Diabetic, t 50-59, Non-smoker //
        if (q == 2 && r == 1 && s == 2 && (t >= 50 && t < 60))
        {
            if(v < 180)
            {
                return ERICE = 1;
            }

            else
            {
                return ERICE = 2;
            }
        } 
        

        // Female, Diabetic, t 60-69, Non-smoker //
        if (q == 2 && r == 1 && s == 2 && (t >= 60 && t < 70))
        {
            if(v < 180)
            {
                return ERICE = 2;
            }

            else
            {
                return ERICE = 4;
            }
        }

        // Female, Diabetic, t 70-79, Non-smoker //
        if (q == 2 && r == 1 && s == 2 && (t >= 70 && t < 80))
        {
            if(v < 180)
            {
                return ERICE = 4;
            }

            else
            {
                return ERICE = 5;
            }
        }

        // Female, Diabetic, t 80 & Onwards, Non-smoker //
        if (q == 2 && r == 1 && s == 2 && t >= 80)
        {
            return ERICE = 5;
        }

        //////////////////////////////////////////////
        ///////// FEMALE, DIABETIC, SMOKER ///////////
        //////////////////////////////////////////////

        // Female, Diabetic, t 30-49*, Smoker //
        if (q == 2 && r == 1 && s == 1 && (t >= 30 && t < 50))
        {
            return ERICE = 0;
        }

        // Female, Diabetic, t 50-59, Smoker //
        if (q == 2 && r == 1 && s == 1 && (t >= 50 && t < 60))
        {
            if(v < 180)
            {
                return ERICE = 2;
            }

            else
            {
                return ERICE = 3;
            }
        }

        // Female, Diabetic, t 60-69, Smoker //
        if (q == 2 && r == 1 && s == 1 && (t >= 60 && t < 70))
        {
            if(v < 180)
            {
                return ERICE = 3;
            }

            else
            {
                return ERICE = 4;
            }
        }

        // Female, Diabetic, t 70-79, Smoker //
        if (q == 2 && r == 1 && s == 1 && (t >= 70 && t < 80))
        {
            return ERICE = 5;
        }

        // Female, Diabetic, t 80 & Onwards, Smoker //
        if (q == 2 && r == 1 && s == 1 && t >= 80)
        {
            return ERICE = 5;
        }

        //////////////////////////////////////////////
        ////// FEMALE, NON-DIABETIC, NON-SMOKER //////
        //////////////////////////////////////////////

            // Female, Non-Diabetic, t 30-49*, Non-smoker //
        if (q == 2 && r == 2 && s == 2 && (t >= 30 && t < 50))
        {
            return ERICE = 0;
        }

        // Female, Non-Diabetic, t 50-59, Non-smoker //
        if (q == 2 && r == 2 && s == 2 && (t >= 50 && t < 60))
        {
            return ERICE = 1;
        }

        // Female, Non-Diabetic, t 60-69, Non-smoker //
        if (q == 2 && r == 2 && s == 2 && (t >= 60 && t < 70))
        {
            if(v < 180)
            {
                return ERICE = 1;
            }

            else
            {
                return ERICE = 2;
            }
        }

        // Female, Non-Diabetic, t 70-79, Non-smoker //
        if (q == 2 && r == 2 && s == 2 && (t >= 70 && t < 80))
        {
            if(v < 180)
            {
                return ERICE = 3;
            }

            else
            {
                return ERICE = 4;
            }
        }

        // Female, Non-Diabetic, t 80 & Onwards, Non-smoker //
        if (q == 2 && r == 2 && s == 2 && t >= 80)
        {
            return ERICE = 5;
        }

        ///////////////////////////////////////////////
        //////// FEMALE, NON-DIABETIC, SMOKER /////////
        ///////////////////////////////////////////////

        // Female, Non-Diabetic, t 30-49*, Smoker //
        if (q == 2 && r == 2 && s == 1 && (t >= 30 && t < 50))
        {
            return ERICE = 0;
        }

        // Female, Non-Diabetic, t 50-59, Smoker //
        if (q == 2 && r == 2 && s == 1 && (t >= 50 && t < 60))
        {
            if(v < 180)
            {
                return ERICE = 1;
            }

            else
            {
                return ERICE = 2;
            }
        }

        // Female, Non-Diabetic, t 60-69, Smoker //
        if (q == 2 && r == 2 && s == 1 && (t >= 60 && t < 70))
        {
            if(v < 180)
            {
                return ERICE = 2;
            }

            else
            {
                return ERICE = 4;
            }
        }

        // Female, Non-Diabetic, t 70-79, Smoker //
        if (q == 2 && r == 2 && s == 1 && (t >= 70 && t < 80))
        {
            if(v < 180)
            {
                return ERICE = 4;
            }

            else
            {
                return ERICE = 5;
            }
        }

        // Female, Non-Diabetic, t 80 & Onwards, Smoker //
        if (q == 2 && r == 2 && s == 1 && t >= 80)
        {
            return ERICE = 5;
        }
}

void printERICE(int w) // Function that prints the Cardiac Risk Score category based on a given ERICE score
{
            
        if(w == 0)
        {
            printf("\nYour ERISK score is Low.\n");
        }
        if(w == 1)
        {
            printf("\nYour ERISK score is Mild.\n");
        }
        if(w == 2)
        {
            printf("\nYour ERISK score is Moderate.\n");
        }
        if(w == 3)
        {
            printf("\nYour ERISK score is Moderate-High.\n");
        }
        if(w == 4)
        {
            printf("\nYour ERISK score is High.\n");
        }
        if(w == 5)
        {
            printf("\nYour ERISK score is Very High.\n");
        }
}