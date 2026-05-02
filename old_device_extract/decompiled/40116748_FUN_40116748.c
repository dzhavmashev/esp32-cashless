// Function : FUN_40116748
// Address  : 0x40116748
// Size     : 100 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40116748(uint *param_1)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = *param_1;
  piVar2 = _DAT_3ffc83fc;
  if (((uVar4 & 0xf0) != 0xe0) || (iVar3 = _DAT_3ffc6484, _DAT_3ffc6484 == 0)) {
    for (; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      bVar1 = *(byte *)((int)piVar2 + 0xeb);
      if ((((bVar1 & 1) != 0) && ((bVar1 & 4) != 0)) && (piVar2[1] != 0)) {
        if (((uVar4 ^ piVar2[1]) & piVar2[7]) == 0) {
          return (int)piVar2;
        }
        if (((bVar1 & 2) == 0) && (uVar4 == piVar2[0xd])) {
          return (int)piVar2;
        }
      }
    }
    iVar3 = 0;
    if (((_DAT_3ffc8400 != 0) && ((*(byte *)(_DAT_3ffc8400 + 0xeb) & 5) == 5)) &&
       ((*(int *)(_DAT_3ffc8400 + 4) != 0 && ((uVar4 & 0xff) != 0x7f)))) {
      iVar3 = _DAT_3ffc8400;
    }
  }
  return iVar3;
}

