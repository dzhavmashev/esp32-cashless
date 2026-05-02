// Function : FUN_4011f6a8
// Address  : 0x4011f6a8
// Size     : 35 bytes


bool FUN_4011f6a8(int param_1,int param_2)

{
  return *(int *)((param_1 * 2 + param_2) * 8 + 0x3ffbe128) != 0x40085830;
}

