// Function : FUN_401054f0
// Address  : 0x401054f0
// Size     : 72 bytes


void FUN_401054f0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)&SUB_40064ae0)(*(undefined4 *)(param_1 + 8));
  *param_2 = uVar1;
  memw();
  uVar1 = (*(code *)&SUB_40064ae0)(*(undefined4 *)(param_1 + 0xc));
  param_2[1] = uVar1;
  memw();
  uVar1 = (*(code *)&SUB_40064ae0)(*(undefined4 *)(param_1 + 0x10));
  param_2[2] = uVar1;
  memw();
  uVar1 = (*(code *)&SUB_40064ae0)(*(undefined4 *)(param_1 + 0x14));
  param_2[3] = uVar1;
  memw();
  uVar1 = (*(code *)&SUB_40064ae0)(*(undefined4 *)(param_1 + 0x18));
  param_2[4] = uVar1;
  memw();
  return;
}

