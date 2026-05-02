// Function : FUN_400fa598
// Address  : 0x400fa598
// Size     : 63 bytes


int FUN_400fa598(int param_1,undefined1 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0x1101;
  if (*(int *)(param_1 + 100) == 1) {
    for (iVar2 = *(int *)(param_1 + 0x10); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
      while (iVar1 = FUN_400fbaa4(iVar2,param_2,0xff,0,0xff,0xff), iVar1 != 0x1102) {
        if (iVar1 != 0) {
          return iVar1;
        }
      }
    }
    iVar2 = 0;
  }
  return iVar2;
}

