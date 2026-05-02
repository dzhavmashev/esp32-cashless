// Function : FUN_40184df8
// Address  : 0x40184df8
// Size     : 45 bytes


bool FUN_40184df8(uint param_1,int param_2)

{
  bool bVar1;
  
  if ((param_2 == 0) || (0x3f < param_1)) {
    bVar1 = false;
  }
  else {
    bVar1 = (1 << 0x20 - (0x20 - (param_1 & 0x1f)) & *(uint *)(param_2 + (param_1 >> 5) * 4)) != 0;
  }
  return bVar1;
}

