// Function : FUN_400f8368
// Address  : 0x400f8368
// Size     : 38 bytes


undefined4 FUN_400f8368(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = FUN_40184860(param_1);
  uVar2 = 0;
  if (iVar1 == 0) {
    iVar3 = *(int *)(param_1 + 0x1c);
    iVar1 = FUN_400f8354(param_1);
    uVar2 = 0;
    if (iVar3 == iVar1) {
      uVar2 = 1;
    }
  }
  return uVar2;
}

