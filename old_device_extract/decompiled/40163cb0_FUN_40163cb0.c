// Function : FUN_40163cb0
// Address  : 0x40163cb0
// Size     : 122 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40163cb0(int param_1,char param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = *(uint *)(*(int *)(param_1 + 0x2c) + 0x10) >> 0x14 & 0xf;
  iVar2 = param_1;
  while (iVar3 = *(int *)(iVar2 + 0x28), iVar3 != 0) {
    *(undefined4 *)(*(int *)(iVar2 + 8) + 8) = 0;
    iVar2 = iVar3;
  }
  memw();
  FUN_40163ab4(param_1);
  iVar3 = _DAT_3ffc0034;
  iVar5 = _DAT_3ffc0034 + uVar1 * 0x30;
  iVar4 = *(int *)(iVar5 + 0x20);
  *(int *)(iVar2 + 0x28) = iVar4;
  if (iVar4 == 0) {
    *(int *)(iVar5 + 0x24) = iVar2 + 0x28;
  }
  *(int *)(iVar3 + uVar1 * 0x30 + 0x20) = param_1;
  *(undefined4 *)(iVar3 + (uVar1 + 1) * 0x30 + 4) = 0;
  memw();
  FUN_40188470(uVar1);
  if (param_2 != '\0') {
    (*(code *)&SUB_40087bcc)(*(uint *)(*(int *)(param_1 + 0x2c) + 4) >> 4 & 0xf,0);
  }
  return;
}

