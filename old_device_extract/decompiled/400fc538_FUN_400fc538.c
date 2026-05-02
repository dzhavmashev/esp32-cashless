// Function : FUN_400fc538
// Address  : 0x400fc538
// Size     : 57 bytes


undefined4 FUN_400fc538(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = FUN_400f8eb4(1,2,param_1);
  uVar2 = 0x105;
  if (iVar1 != 0) {
    uVar2 = 0x1119;
    if (*(char *)(iVar1 + 0x25) == '\0') {
      iVar3 = (*(code *)&SUB_40094d60)(0x10);
      uVar2 = 0x101;
      if (iVar3 != 0) {
        FUN_400fac70(iVar3,iVar1);
        *param_2 = iVar3;
        uVar2 = 0;
      }
    }
  }
  memw();
  return uVar2;
}

