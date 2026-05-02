// Function : FUN_400e4a88
// Address  : 0x400e4a88
// Size     : 100 bytes


void FUN_400e4a88(undefined4 param_1,int param_2)

{
  char *pcVar1;
  
  if (param_2 == 5) {
LAB_400e4ae9:
    pcVar1 = "_failed";
    goto LAB_400e4ac4;
  }
  if (param_2 < 6) {
    if (param_2 == 2) {
LAB_400e4ae3:
      pcVar1 = "k_error";
      goto LAB_400e4ac4;
    }
    if (param_2 < 3) {
      if (param_2 == 0) {
        pcVar1 = "d - %s\n";
        goto LAB_400e4ac4;
      }
    }
    else {
      if (param_2 == 3) goto LAB_400e4ae3;
      if (param_2 == 4) goto LAB_400e4ae9;
    }
  }
  else {
    pcVar1 = "ollback";
    if (param_2 == 8) goto LAB_400e4ac4;
    if (param_2 < 9) {
      pcVar1 = "invalid";
      if ((param_2 == 6) || (pcVar1 = "ismatch", param_2 == 7)) goto LAB_400e4ac4;
    }
    else {
      pcVar1 = "";
      if (((param_2 == 10) || (pcVar1 = "ficient", param_2 < 10)) ||
         (pcVar1 = "_failed", param_2 == 0xb)) goto LAB_400e4ac4;
    }
  }
  pcVar1 = "s\n";
LAB_400e4ac4:
  FUN_400f0be8(param_1,pcVar1);
  return;
}

