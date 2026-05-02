// Function : FUN_40170dc0
// Address  : 0x40170dc0
// Size     : 25 bytes


undefined4 FUN_40170dc0(int param_1,uint param_2)

{
  return *(undefined4 *)(*(int *)(param_1 + ((int)param_2 >> 2) * 4) + (param_2 & 3) * 4);
}

