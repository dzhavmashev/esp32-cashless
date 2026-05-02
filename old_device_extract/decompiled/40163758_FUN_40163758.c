// Function : FUN_40163758
// Address  : 0x40163758
// Size     : 168 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_40163758(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  iVar2 = 0;
  do {
    iVar3 = FUN_401600d4(iVar2);
    if (iVar3 == 0) {
      return true;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 5);
  while( true ) {
    uVar4 = *_DAT_3ffc0034;
    if (uVar4 == 0) {
      if ((((_DAT_3ffc0034[8] == 0) && (_DAT_3ffc0034[0x14] == 0)) && (_DAT_3ffc0034[0x20] == 0)) &&
         (_DAT_3ffc0034[0xcd] == 0)) {
        return _DAT_3ffc0034[0xcf] != 0;
      }
      return true;
    }
    iVar2 = -LZCOUNT(-uVar4 & uVar4) + 0x1f;
    if (_DAT_3ffc0034[iVar2 * 0xc + 8] != 0) {
      return true;
    }
    if (_DAT_3ffc0034[(-LZCOUNT(-uVar4 & uVar4) + 0x20) * 0xc + 1] != 0) break;
    bVar1 = (byte)_DAT_3ffc0034[iVar2 * 0xc + 0xb];
    uVar5 = 4;
    if (bVar1 < 8) {
      if ((bVar1 == 0) || (bVar1 == 3)) {
        uVar5 = 2;
      }
      else {
        uVar5 = 3;
        if ((2 < bVar1) && (uVar5 = 1, 5 < bVar1)) {
          uVar5 = 0;
        }
      }
    }
    FUN_40163728(iVar2,uVar5);
  }
  return true;
}

