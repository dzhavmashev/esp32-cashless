// Function : FUN_401844fc
// Address  : 0x401844fc
// Size     : 16 bytes


byte FUN_401844fc(byte *param_1)

{
  byte bVar1;
  
  bVar1 = *param_1;
  if ((bVar1 & 0xf0) != 0x30) {
    bVar1 = 0;
  }
  return bVar1 & 1;
}

