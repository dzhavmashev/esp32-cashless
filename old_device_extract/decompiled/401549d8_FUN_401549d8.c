// Function : FUN_401549d8
// Address  : 0x401549d8
// Size     : 251 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401549d8(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = _DAT_3ffc8804;
  if (*(int *)(param_1 + 0x118) != 0) {
    while (iVar3 = *(int *)(param_1 + 0x118), iVar3 != 0) {
      if ((**(uint **)(iVar3 + 0x2c) & 0x40000) == 0) {
        iVar4 = *(int *)(*(int *)(iVar3 + 4) + 4);
      }
      else {
        iVar4 = *(int *)(*(int *)(iVar3 + 4) + 4) + 4;
      }
      iVar2 = *(int *)(iVar3 + 0x28);
      if (iVar2 != 0) {
        *(byte *)(iVar4 + 1) = *(byte *)(iVar4 + 1) | 0x20;
        memw();
      }
      if (param_2 == 0) {
        memw();
        iVar4 = FUN_40187c04();
        if (iVar4 == 0) {
          *(undefined4 *)(iVar3 + 0x28) = 0;
          *_DAT_3ffc8998 = iVar3;
          _DAT_3ffc8998 = (int *)(iVar3 + 0x28);
        }
        else {
          FUN_4015fb20(iVar3);
        }
        *(int *)(param_1 + 0x10c) = *(int *)(param_1 + 0x10c) + 1;
        *(int *)(iVar1 + 0x13c) = *(int *)(iVar1 + 0x13c) + 1;
        memw();
      }
      else {
        if (param_2 != 1) {
          if (((DAT_3ffc1a44 == '\0') || (memw(), DAT_3ffc1a3c != '\0')) || (_DAT_3ffc1a40 == 0)) {
            memw();
            iVar4 = _DAT_3ff73c00 + _DAT_3ffc1a30;
          }
          else {
            iVar4 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
          }
          if ((uint)(iVar4 - *(int *)(*(int *)(iVar3 + 0x2c) + 0x18)) < param_2) goto LAB_40154ad1;
        }
        *(int *)(param_1 + 0x114) = *(int *)(param_1 + 0x114) + 1;
        *(int *)(iVar1 + 0x140) = *(int *)(iVar1 + 0x140) + 1;
        memw();
        FUN_4015fb44(iVar3);
      }
      *(int *)(param_1 + 0x108) = *(int *)(param_1 + 0x108) + -1;
      *(int *)(iVar1 + 0x138) = *(int *)(iVar1 + 0x138) + -1;
      *(int *)(param_1 + 0x120) = *(int *)(param_1 + 0x120) + -1;
      *(int *)(param_1 + 0x118) = iVar2;
    }
    *(undefined4 *)(param_1 + 0x11c) = 0;
    *(undefined4 *)(param_1 + 0x120) = 0;
  }
  *(undefined4 *)(param_1 + 0x108) = 0;
LAB_40154ad1:
  memw();
  return;
}

