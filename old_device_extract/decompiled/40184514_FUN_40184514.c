// Function : FUN_40184514
// Address  : 0x40184514
// Size     : 22 bytes


byte FUN_40184514(byte *param_1)

{
  byte bVar1;
  
  bVar1 = 0;
  if ((*param_1 & 0xf0) == 0x30) {
    bVar1 = *param_1 >> 3 & 1;
  }
  return bVar1;
}

