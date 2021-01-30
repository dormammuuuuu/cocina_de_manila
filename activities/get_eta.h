#ifndef GET_ETA_H_INCLUDED
#define GET_ETA_H_INCLUDED
#include "var.h"
#include "other_activities.h"

void estimated_time_arrival(){
    while (addMins != 0){
        mins++;
        if (mins > 59){
            hours++;
            if (hours > 23){
                hours = 0;
            }
            mins = 0;
        }
        addMins--;
    }
    while (addHour != 0){
        hours++;
        if (hours >= 23)
            hours = 0;
        addHour--;
    }

    sprintf(hour, "%d", hours);
    if(strlen(hour)==1){
        strcat(tempHour, hour);
        strcpy(hour, tempHour);
    }

    sprintf(min,"%d", mins);
    if(strlen(min)==1){
        strcat(tempMin, min);
        strcpy(min, tempMin);
    }

    sprintf(sec,"%d", secs);
    if(strlen(sec)==1){
        strcat(tempSec, sec);
        strcpy(sec, tempSec);
    }
    sprintf(eta, "%.2s:%s:%s", hour, min, sec);
}

#endif // GET_ETA_H_INCLUDED
