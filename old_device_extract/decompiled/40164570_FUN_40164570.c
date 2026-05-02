// Function : FUN_40164570
// Address  : 0x40164570
// Size     : 109 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40164570(int param_1)

{
  int iVar1;
  
  FUN_401641bc(param_1);
  iVar1 = *(int *)(param_1 + 0x60);
  if (*(byte *)(param_1 + 4) < *(byte *)(iVar1 + 10)) {
    *(int *)(param_1 + 0x60) = iVar1 + -0xc;
    *(byte *)(iVar1 + -1) = *(byte *)(iVar1 + -1) | 1;
    memw();
    if (((DAT_3ffc1a44 == '\0') || (memw(), DAT_3ffc1a3c != '\0')) || (_DAT_3ffc1a40 == 0)) {
      memw();
      iVar1 = _DAT_3ff73c00 + _DAT_3ffc1a30;
    }
    else {
      memw();
      iVar1 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
    }
    *(int *)(param_1 + 0x34) = iVar1;
  }
  memw();
  return;
}

