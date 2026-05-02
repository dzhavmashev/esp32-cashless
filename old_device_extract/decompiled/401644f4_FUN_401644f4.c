// Function : FUN_401644f4
// Address  : 0x401644f4
// Size     : 120 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401644f4(int param_1,uint param_2)

{
  int iVar1;
  
  FUN_401641bc(param_1);
  if ((uint)*(byte *)(param_1 + 5) <
      (uint)*(byte *)(*(int *)(param_1 + 0x60) + 10) + (param_2 & 0xff)) {
    *(uint *)(param_1 + 0x60) = (uint)*(byte *)(param_1 + 5) * 0xc + *(int *)(param_1 + 0x70);
  }
  else {
    *(uint *)(param_1 + 0x60) = (param_2 & 0xff) * 0xc + *(int *)(param_1 + 0x60);
    memw();
  }
  if (((DAT_3ffc1a44 == '\0') || (memw(), DAT_3ffc1a3c != '\0')) || (_DAT_3ffc1a40 == 0)) {
    memw();
    iVar1 = _DAT_3ff73c00 + _DAT_3ffc1a30;
  }
  else {
    memw();
    iVar1 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
  }
  *(int *)(param_1 + 0x30) = iVar1;
  memw();
  return;
}

