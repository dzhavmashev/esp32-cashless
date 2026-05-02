// Function : FUN_40186858
// Address  : 0x40186858
// Size     : 34 bytes


int FUN_40186858(uint *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = -1;
  if (param_2 != 0) {
    iVar1 = -(uint)((1 << 0x20 - (0x20 - (param_2 - 1U & 0x1f)) & *param_1) == 0);
  }
  return iVar1;
}

