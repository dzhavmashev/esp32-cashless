// Function : FUN_40101614
// Address  : 0x40101614
// Size     : 31 bytes


undefined4 FUN_40101614(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0x102;
  if (param_1 != 0) {
    uVar1 = 0x5002;
    if ((*(int *)(param_1 + 0x10) != 0) &&
       (iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 0xdc), iVar2 != 0)) {
      uVar1 = 0;
      *param_2 = iVar2;
    }
  }
  memw();
  return uVar1;
}

