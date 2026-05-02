// Function : FUN_40184f30
// Address  : 0x40184f30
// Size     : 71 bytes


void FUN_40184f30(byte *param_1)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = *param_1;
  *param_1 = *param_1 << 1 | param_1[1] >> 7;
  memw();
  bVar2 = param_1[0xf] << 1;
  if ((char)bVar1 < '\0') {
    bVar2 = bVar2 ^ 0x87;
  }
  param_1[0xf] = bVar2;
  memw();
  memw();
  return;
}

