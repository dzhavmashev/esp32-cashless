// Function : FUN_4015c674
// Address  : 0x4015c674
// Size     : 422 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4015c674(void)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  
  pcVar1 = (char *)FUN_4015a07c();
  if (((*pcVar1 == '\0') && (iVar2 = FUN_4015014c(), iVar2 == 0)) &&
     (iVar3 = FUN_4015013c(), iVar11 = _DAT_3ffc8864, iVar2 = _DAT_3ffbfc54, iVar3 == 0)) {
    iVar9 = _DAT_3ffbfc54 + 0x93;
    uVar10 = (uint)DAT_3ffca0b6;
    puVar4 = &DAT_3ffc91f8;
    memw();
    iVar3 = 0;
    for (; puVar4 != &DAT_3ffc91f8 + uVar10 * 4; puVar4 = puVar4 + 4) {
      iVar8 = *(int *)(puVar4 + 0xea8);
      if (*(char *)(iVar8 + 0x28b) == '\0') {
        if ((*(char *)(iVar2 + 0x92) != '\0') &&
           (iVar5 = (*(code *)&SUB_4008b33c)(iVar9,iVar8 + 4,6), iVar5 == 0)) {
          return iVar8;
        }
        if (iVar3 == 0) {
LAB_4015c712:
          iVar3 = iVar8;
        }
        else if (iVar3 != iVar8) {
          iVar5 = FUN_4015b5d8(iVar8);
          memw();
          iVar6 = FUN_4015b5d8(iVar3);
          if (iVar6 < iVar5) goto LAB_4015c712;
        }
      }
      else if (((iVar11 != 0) && (*(char *)(iVar2 + 0x92) != '\0')) &&
              (iVar5 = (*(code *)&SUB_4008b33c)(iVar9,iVar8 + 4,6), iVar5 == 0)) {
        return iVar8;
      }
    }
  }
  else {
    iVar2 = _DAT_3ffbfc54;
    if (*(char *)(_DAT_3ffbfc54 + 0x35d) == '\0') {
      uVar7 = (uint)DAT_3ffca0b6;
      iVar11 = -0x780;
      iVar9 = _DAT_3ffbfc54 + 0x93;
      memw();
      iVar3 = 0;
      for (uVar10 = 0; (uVar10 & 0xff) < uVar7; uVar10 = uVar10 + 1) {
        iVar8 = *(int *)(&DAT_3ffca0a0 + uVar10 * 4);
        if ((*(char *)(iVar2 + 0x92) != '\0') &&
           (iVar5 = (*(code *)&SUB_4008b33c)(iVar9,iVar8 + 4,6), iVar5 == 0)) {
          return iVar8;
        }
        iVar5 = FUN_4015b5d8(iVar8);
        if (iVar11 < iVar5) {
          iVar3 = iVar8;
          iVar11 = iVar5;
        }
      }
    }
    else {
      iVar11 = _DAT_3ffbfc54 + 0x93;
      uVar7 = (uint)DAT_3ffca0b6;
      iVar3 = _DAT_3ffca0a0;
      for (uVar10 = 0; (uVar10 & 0xff) < uVar7; uVar10 = uVar10 + 1) {
        iVar9 = *(int *)(&DAT_3ffca0a0 + uVar10 * 4);
        if ((*(char *)(iVar2 + 0x92) != '\0') &&
           (iVar8 = (*(code *)&SUB_4008b33c)(iVar11,iVar9 + 4,6), iVar8 == 0)) {
          return iVar9;
        }
        if (*(byte *)(iVar3 + 0x28b) < *(byte *)(iVar9 + 0x28b)) {
LAB_4015c7de:
          iVar3 = iVar9;
        }
        else if (*(byte *)(iVar3 + 0x28b) == *(byte *)(iVar9 + 0x28b)) {
          iVar8 = FUN_4015b5d8(iVar9);
          memw();
          iVar5 = FUN_4015b5d8(iVar3);
          if (iVar5 < iVar8) goto LAB_4015c7de;
        }
      }
    }
  }
  if (iVar3 == 0) {
    if (DAT_3ffca0b4 == '\x01') {
      FUN_40147fe4(1,4,5,0x3f436309);
      FUN_4015c604();
    }
  }
  else {
    FUN_40147fe4(1,4,5,0x3f4362f7);
  }
  return iVar3;
}

