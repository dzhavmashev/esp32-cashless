// Function : FUN_40154b74
// Address  : 0x40154b74
// Size     : 127 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40154b74(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _DAT_3ffc8804;
  if (0 < *(int *)(param_1 + 0x10c)) {
    *(int *)(param_1 + 0x10c) = *(int *)(param_1 + 0x10c) + -1;
    *(int *)(iVar1 + 0x13c) = *(int *)(iVar1 + 0x13c) + -1;
    if ((param_1 != *(int *)(iVar1 + 0xec)) &&
       (*(char *)(*(int *)(param_2 + 0x2c) + 0x13) == '\x01')) {
      if ((DAT_3ffc1a44 == '\0') || ((memw(), DAT_3ffc1a3c != '\0' || (_DAT_3ffc1a40 == 0)))) {
        memw();
        iVar1 = _DAT_3ff73c00 + _DAT_3ffc1a30;
      }
      else {
        memw();
        iVar1 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
      }
      *(int *)(param_1 + 0x150) = iVar1;
    }
  }
  if (*(int *)(param_1 + 0x108) + *(int *)(param_1 + 0x10c) == 0) {
    memw();
    FUN_401547bc(param_1);
  }
  return;
}

