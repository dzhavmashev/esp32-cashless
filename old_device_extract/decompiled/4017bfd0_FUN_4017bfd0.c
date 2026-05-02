// Function : FUN_4017bfd0
// Address  : 0x4017bfd0
// Size     : 28 bytes


byte FUN_4017bfd0(uint param_1)

{
  byte bVar1;
  
  bVar1 = 0;
  if (param_1 < 0x100) {
    bVar1 = *(byte *)(param_1 + 0x3ff96355) & 8;
  }
  return bVar1;
}

