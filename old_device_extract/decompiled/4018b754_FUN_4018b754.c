// Function : FUN_4018b754
// Address  : 0x4018b754
// Size     : 26 bytes


int FUN_4018b754(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if ((*(uint *)(param_1 + 0x14) & 0x3ff00) != 0) {
    iVar1 = ((int)((*(uint *)(param_1 + 0x14) >> 8 & 0x3ff) + 3) >> 2) << 2;
  }
  return iVar1;
}

