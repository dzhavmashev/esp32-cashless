// Function : FUN_40186e90
// Address  : 0x40186e90
// Size     : 60 bytes


void FUN_40186e90(byte *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar3 = 0;
  do {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar2 = uVar2 | (bVar1 & 0x7f) << 0x20 - (0x20 - (uVar3 & 0x1f));
    uVar3 = uVar3 + 7;
  } while ((char)bVar1 < '\0');
  if ((uVar3 < 0x20) && ((bVar1 & 0x40) != 0)) {
    uVar2 = uVar2 | -1 << 0x20 - (0x20 - (uVar3 & 0x1f));
  }
  *param_2 = uVar2;
  return;
}

