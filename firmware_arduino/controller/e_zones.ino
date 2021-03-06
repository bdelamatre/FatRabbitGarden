/***

Zones

***/

void turnScheduleZonesOn(struct Schedule &thisSchedule, time_t onTime){
  for(int i=0;i<maxZones;i++){
    if(thisSchedule.zones[i]>-1){
      //fix-me: turned off switching to 
      //if(configStore.zones[(thisSchedule.zones[i])].isRunning==0){
        turnZoneOn(configStore.zones[(thisSchedule.zones[i])],onTime,1);
      //}else{
      //  turnZoneOn(configStore.zones[(thisSchedule.zones[i])],onTime,0);
      //}
    }
  }
}

void turnScheduleZonesOff(struct Schedule &thisSchedule, time_t offTime){
  for(int i=0;i<maxZones;i++){
    if(thisSchedule.zones[i]>-1){
      //if(configStore.zones[(thisSchedule.zones[i])].isRunning==1){
        turnZoneOff(configStore.zones[(thisSchedule.zones[i])],offTime,1);
      //}else{
      //  turnZoneOff(configStore.zones[(thisSchedule.zones[i])],offTime,0);
      //}
    }
  }
}

void turnZoneOn(struct Zone &thisZone, time_t onTime,int logMe){
  
  /*if(thisZone.statusSafetyOff==1){
    addErrorLog(onTime,"could not turn on zone because it was turned off as a safety percaution","");
    return;
  }*/
  
  thisZone.isRunning = 1;
  thisZone.statusRunStarted = onTime;

  digitalWrite(thisZone.pin,HIGH);
  
  if(logMe==1){
    addZoneLog(thisZone,onTime,"on","");
  }
  
}

void turnZoneOff(struct Zone &thisZone, time_t offTime, int logMe){
  
  digitalWrite(thisZone.pin,LOW);
  thisZone.isRunning = 0;
  thisZone.statusRunStarted = 0;
  
  if(logMe==1){
    addZoneLog(thisZone,offTime,"off","");
  }
}



