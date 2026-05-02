// Function : FUN_401841e0
// Address  : 0x401841e0
// Size     : 17 bytes


byte FUN_401841e0(int param_1)

{
  byte bVar1;
  
  bVar1 = 0;
  if (param_1 != 0) {
    bVar1 = *(byte *)(param_1 + 8) >> 3 & 1;
  }
  return bVar1;
}

