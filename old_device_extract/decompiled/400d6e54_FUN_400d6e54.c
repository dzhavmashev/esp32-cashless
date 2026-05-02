// Function : FUN_400d6e54
// Address  : 0x400d6e54
// Size     : 54 bytes


void FUN_400d6e54(undefined4 param_1,undefined4 param_2,int param_3)

{
  char *pcVar1;
  
  pcVar1 = "FICATES";
  if (param_3 != 2) {
    if (param_3 < 3) {
      pcVar1 = "llbacks";
      if ((param_3 == 0) || (pcVar1 = "ntering CONNECTING", param_3 == 1)) goto LAB_400d6e83;
    }
    else {
      pcVar1 = "ntering OPERATIONAL";
      if (((param_3 == 4) || (pcVar1 = "ntering MQTT_RECONNECTING", param_3 < 4)) ||
         (pcVar1 = "RL MODE ERROR", param_3 == 5)) goto LAB_400d6e83;
    }
    pcVar1 = "_OPTION_UNKNOWN";
  }
LAB_400d6e83:
  FUN_400f0be8(param_1,pcVar1);
  return;
}

