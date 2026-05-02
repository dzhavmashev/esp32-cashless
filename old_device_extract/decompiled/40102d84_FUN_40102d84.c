// Function : FUN_40102d84
// Address  : 0x40102d84
// Size     : 48 bytes


uint FUN_40102d84(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_4015a0f4();
  uVar2 = 0;
  if (uVar1 != 0) {
    uVar2 = FUN_40159fd8();
    if (uVar2 < 0xe) {
      uVar1 = (0x2410U >> (uVar2 & 0x1f) ^ 0xffffffff) & 1;
    }
    uVar2 = (uVar1 ^ 1) & 0xff;
  }
  return uVar2;
}

