// Function : FUN_40135f68
// Address  : 0x40135f68
// Size     : 188 bytes


int FUN_40135f68(int *param_1,int param_2,char *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_4 != 0) {
    iVar1 = FUN_401317d8(param_1 + 1);
    iVar2 = FUN_401863d8(param_1);
    iVar3 = -0x4e80;
    if (iVar2 == 2) {
      if (param_4 != iVar1) {
        return -0x4f80;
      }
      iVar3 = FUN_401317e8(param_2,param_3,param_4);
      if (iVar3 != 0) {
        return iVar3;
      }
      FUN_40131548(param_2 + 0xc);
      if ((*param_1 == 9) && (iVar3 = FUN_4013173c(param_2,param_4 * 8 + -1,0), iVar3 != 0)) {
        return iVar3;
      }
      iVar2 = FUN_40131700(param_2 + 0x18,1);
      iVar3 = 0;
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    iVar2 = FUN_401863d8(param_1);
    if (iVar2 != 1) {
      return iVar3;
    }
    if (*param_3 == '\0') {
      if (param_4 == 1) {
        iVar3 = FUN_40135764(param_2);
        return iVar3;
      }
    }
    else {
      if (*param_3 != '\x04') {
        return -0x4e80;
      }
      if (iVar1 * 2 + 1 == param_4) {
        iVar3 = FUN_4013183c(param_2,param_3 + 1,iVar1);
        if (iVar3 != 0) {
          return iVar3;
        }
        iVar3 = FUN_4013183c(param_2 + 0xc,param_3 + iVar1 + 1,iVar1);
        if (iVar3 == 0) {
          iVar3 = FUN_40131700(param_2 + 0x18,1);
          return iVar3;
        }
        return iVar3;
      }
    }
  }
  return -0x4f80;
}

