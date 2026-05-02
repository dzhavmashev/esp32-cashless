// Function : FUN_400e6198
// Address  : 0x400e6198
// Size     : 177 bytes


void FUN_400e6198(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 == 4) {
    FUN_400e4fdc(param_1);
  }
  else if (iVar1 < 5) {
    if (iVar1 == 1) {
      FUN_400e5324(param_1);
    }
    else if (iVar1 == 3) {
      FUN_400e4c44(param_1);
    }
    else if (iVar1 == 0) {
      FUN_400e4c10(param_1);
    }
  }
  else if (iVar1 == 6) {
    FUN_400e616c(param_1);
  }
  else if (iVar1 < 6) {
    FUN_400e5ac8(param_1);
  }
  else if (iVar1 == 7) {
    FUN_400e5cb4(param_1);
  }
  else if (iVar1 == 8) {
    FUN_400e53f4(param_1);
  }
  if (((*param_1 - 3U < 2) && (iVar1 = FUN_400f1a9c(), 2000 < (uint)(iVar1 - param_1[0x16]))) &&
     ((10.0 <= (float)param_1[0x15] - (float)param_1[0x7c] || ((float)param_1[0x7c] < 0.0)))) {
    FUN_400e5ecc(param_1);
    param_1[0x7c] = param_1[0x15];
  }
  return;
}

