// Function : FUN_40132144
// Address  : 0x40132144
// Size     : 70 bytes


int FUN_40132144(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int aiStack_24 [9];
  
  if ((**(uint **)(param_1 + 8) & 1) != 0) {
    piVar3 = &DAT_3f41d2d0;
    do {
      iVar2 = *piVar3;
      if (iVar2 < 1) {
        return 0;
      }
      iVar1 = FUN_40131ad8(param_1,iVar2);
      if (iVar1 < 1) {
        return 1;
      }
      iVar2 = FUN_4018617c(aiStack_24,param_1,iVar2);
      if (iVar2 != 0) {
        return iVar2;
      }
      piVar3 = piVar3 + 1;
    } while (aiStack_24[0] != 0);
  }
  return -0xe;
}

