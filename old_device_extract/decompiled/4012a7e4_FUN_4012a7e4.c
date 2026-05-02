// Function : FUN_4012a7e4
// Address  : 0x4012a7e4
// Size     : 142 bytes


int FUN_4012a7e4(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = -0x7100;
  if ((((param_1 != (int *)0x0) && (*param_1 != 0)) && (iVar1 = FUN_40129140(param_1), iVar1 == 0))
     && ((param_1[1] == 0x10 || (iVar1 = FUN_4012c9dc(param_1), iVar1 == 0)))) {
    if ((((*(char *)(*param_1 + 0xc) == '\0') || ((param_3 < 2 || (1 < param_1[5])))) ||
        (*(int *)(param_1[0x13] + 0x50) == 0)) ||
       (*(int *)(*(int *)(param_1[0x13] + 0x50) + 4) != 2)) {
      iVar1 = FUN_4012a788(param_1,param_2,param_3);
    }
    else {
      if (*(char *)((int)param_1 + 0xe6) == '\0') {
        iVar1 = FUN_4012a788(param_1,param_2,1);
        if (iVar1 < 1) {
          return iVar1;
        }
        *(undefined1 *)((int)param_1 + 0xe6) = 1;
        memw();
      }
      memw();
      iVar1 = FUN_4012a788(param_1,param_2 + 1,param_3 - 1);
      if (0 < iVar1) {
        *(undefined1 *)((int)param_1 + 0xe6) = 0;
        memw();
        iVar1 = iVar1 + 1;
        memw();
      }
    }
  }
  return iVar1;
}

