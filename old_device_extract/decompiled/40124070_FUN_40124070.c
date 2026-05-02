// Function : FUN_40124070
// Address  : 0x40124070
// Size     : 88 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40124070(int param_1)

{
  uint uVar1;
  
  if ((param_1 != 0) && (uVar1 = *(uint *)(param_1 + 0x1c4), uVar1 < 0x10)) {
    *(undefined4 *)(uVar1 * 4 + 0x3ffc7660) = 0;
    _DAT_3ffc765c = (uint)(0xfffffffefffffffe >> 0x20 - (uVar1 & 0x1f)) & _DAT_3ffc765c;
  }
  if (*(int *)(param_1 + 0x48) != 0) {
    *(int *)(*(int *)(param_1 + 4) + 0xc) = *(int *)(*(int *)(param_1 + 4) + 0xc) + -1;
  }
  memw();
  (*(code *)&SUB_40094d80)(*(undefined4 *)(param_1 + 0x194));
  (*(code *)&SUB_40094d80)(*(undefined4 *)(param_1 + 0x1ac));
  (*(code *)&SUB_40094d80)(param_1);
  return;
}

