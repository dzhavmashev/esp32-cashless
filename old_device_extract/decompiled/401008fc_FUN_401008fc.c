// Function : FUN_401008fc
// Address  : 0x401008fc
// Size     : 48 bytes


undefined4 FUN_401008fc(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xc);
  uVar1 = 0x102;
  if (iVar2 != 0) {
    if (*(int *)(iVar2 + 0x38) == 1) {
      if (*(int *)(iVar2 + 0x10) == 0) {
        return 0x5002;
      }
      FUN_4011bf04();
    }
    else if (*(int *)(iVar2 + 0x38) == 2) {
      return 0x5005;
    }
    *(undefined4 *)(iVar2 + 0x38) = 2;
    uVar1 = 0;
    memw();
  }
  return uVar1;
}

