// Function : FUN_40184178
// Address  : 0x40184178
// Size     : 36 bytes


bool FUN_40184178(int param_1)

{
  bool bVar1;
  
  bVar1 = false;
  if (param_1 != 0) {
    bVar1 = (byte)((*(byte *)(param_1 + 8) & 0x7f) - 4) < 2;
  }
  return bVar1;
}

