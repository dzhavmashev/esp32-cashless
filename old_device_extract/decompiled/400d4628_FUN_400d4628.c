// Function : FUN_400d4628
// Address  : 0x400d4628
// Size     : 48 bytes


undefined1 FUN_400d4628(int param_1,byte *param_2)

{
  uint uVar1;
  
  while( true ) {
    if (*param_2 == 0) {
      return 0;
    }
    uVar1 = (*(code *)&LAB_40183c7b_1)(param_1);
    if (uVar1 == 0) break;
    if (*param_2 != uVar1) {
      return 3;
    }
    param_2 = param_2 + 1;
    *(undefined1 *)(param_1 + 0x1d) = 0;
  }
  return 2;
}

