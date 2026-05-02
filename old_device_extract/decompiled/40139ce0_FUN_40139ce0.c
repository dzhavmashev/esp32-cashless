// Function : FUN_40139ce0
// Address  : 0x40139ce0
// Size     : 173 bytes


int FUN_40139ce0(int param_1,undefined4 *param_2,int *param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7,uint param_8)

{
  int iVar1;
  int iVar2;
  int iStack_28;
  int iStack_24;
  
  if (*param_3 != 0) {
    memw();
    iVar1 = FUN_401864ec(param_3,param_1);
    if (iVar1 == 0) {
      return -0x3f00;
    }
    if (param_1 == 6) {
      if (param_2 != (undefined4 *)0x0) {
        iVar1 = FUN_40186508(param_3);
        if (param_8 < iVar1 + 7U >> 3) {
          return -0x4380;
        }
        iStack_28 = *param_3;
        iVar2 = param_3[1];
        memw();
        iStack_24 = iVar2;
        iVar1 = FUN_40186520(&iStack_28);
        if (iVar1 != 1) {
          iVar2 = 0;
        }
        memw();
        iVar1 = FUN_4013c204(iVar2,0,0,0,param_4,param_6,param_5,*param_2,param_2[1],param_7);
        if (iVar1 != 0) {
          return iVar1;
        }
        iVar1 = FUN_40186508(param_3);
        if (param_8 <= iVar1 + 7U >> 3) {
          return 0;
        }
        return -0x3900;
      }
    }
    else if (param_2 == (undefined4 *)0x0) {
      iVar1 = FUN_40139bec(param_3,param_4,param_5,param_6,param_7,param_8);
      return iVar1;
    }
  }
  return -16000;
}

