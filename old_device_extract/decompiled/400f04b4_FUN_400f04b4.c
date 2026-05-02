// Function : FUN_400f04b4
// Address  : 0x400f04b4
// Size     : 44 bytes


void FUN_400f04b4(undefined4 *param_1)

{
  *param_1 = &DAT_3f40a4c4;
  FUN_400f0458(param_1);
  if (param_1[0x12] != 0) {
    func_0x400902dc();
  }
  (*(code *)&LAB_40183a17_1)(param_1 + 0xc);
  (*(code *)&LAB_40183a17_1)(param_1 + 8);
  return;
}

