// Function : FUN_4017127c
// Address  : 0x4017127c
// Size     : 37 bytes


void FUN_4017127c(byte *param_1,uint *param_2)

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
  *param_2 = uVar2;
  return;
}

