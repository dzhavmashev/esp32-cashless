// Function : FUN_40170ee0
// Address  : 0x40170ee0
// Size     : 25 bytes


void FUN_40170ee0(int param_1,uint param_2,undefined4 param_3)

{
  *(undefined4 *)(*(int *)(param_1 + ((int)param_2 >> 2) * 4) + (param_2 & 3) * 4) = param_3;
  return;
}

