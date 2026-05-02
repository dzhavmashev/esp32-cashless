// Function : FUN_40163f08
// Address  : 0x40163f08
// Size     : 70 bytes


short FUN_40163f08(uint param_1)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  
  bVar1 = (&DAT_3f42455e)[(param_1 & 0xff) * 8];
  sVar2 = 10;
  if (7 < bVar1) {
    sVar2 = 0x10;
  }
  sVar4 = 0x120;
  if ((((1 < (byte)(bVar1 - 0x29)) && (sVar4 = 0xc0, 4 < bVar1)) && (sVar4 = 0x60, 7 < bVar1)) &&
     (sVar4 = 0x24, bVar1 < 0x10)) {
    sVar4 = 0x14;
  }
  sVar3 = FUN_40163e38(bVar1,0x1e);
  return sVar2 + sVar3 + sVar4;
}

