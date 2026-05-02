// Function : FUN_401844b0
// Address  : 0x401844b0
// Size     : 21 bytes


byte FUN_401844b0(int param_1)

{
  byte bVar1;
  
  bVar1 = 0;
  if (*(byte **)(param_1 + 4) != (byte *)0x0) {
    bVar1 = **(byte **)(param_1 + 4) & 0xf0;
  }
  return bVar1;
}

