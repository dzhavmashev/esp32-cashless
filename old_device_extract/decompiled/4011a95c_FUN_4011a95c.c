// Function : FUN_4011a95c
// Address  : 0x4011a95c
// Size     : 132 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4011a95c(int param_1,char param_2,byte param_3)

{
  byte bVar1;
  bool bVar2;
  
  bVar1 = *(byte *)(param_1 + param_2 + 0x94);
  bVar2 = (param_3 & 0xf7) != 0;
  if ((bVar2 && param_3 != 0x40) != ((bVar1 & 0xf7) != 0 && bVar1 != 0x40)) {
    _DAT_3ffc64b4 = 0x2ff;
    _DAT_3ffc64bc = 0x1000000;
    _DAT_3ffc64c0 = *(uint *)(param_1 + param_2 * 0x18 + 0x58) | 0xff;
    DAT_3ffc64c4 = *(char *)(param_1 + 0xee) + '\x01';
    _DAT_3ffc64b8 = 0;
    memw();
    if (bVar2 && param_3 != 0x40) {
      memw();
      FUN_4011869c();
    }
    else {
      FUN_401187d4();
    }
  }
  return;
}

