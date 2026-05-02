// Function : FUN_4015c970
// Address  : 0x4015c970
// Size     : 745 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4015c970(void)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined1 auStack_60 [32];
  undefined1 uStack_40;
  undefined1 auStack_3f [6];
  undefined1 uStack_39;
  undefined1 uStack_38;
  int iStack_30;
  
  iVar6 = _DAT_3ffc8800;
  iStack_30 = _DAT_3ffbfc54;
  _DAT_3ffc91f8 = _DAT_3ffc91f8 | 0x10;
  memw();
  iVar3 = FUN_4015c674();
  if ((_DAT_3ffc8864 == 0) || (iVar3 == 0)) {
    bVar2 = false;
  }
  else {
    pcVar4 = (char *)FUN_4015a07c();
    bVar2 = false;
    if (*pcVar4 == '\0') {
      bVar2 = *(char *)(iVar3 + 0x28b) != '\0';
    }
    pcVar4 = (char *)FUN_4015a07c();
    if ((*pcVar4 != '\0') && (*(char *)(iVar3 + 0x28b) == '\0')) {
      bVar2 = true;
    }
  }
  if (iVar3 == 0) {
    if (!bVar2) {
      puVar5 = &DAT_3ffc7aec;
      if (DAT_3ffc7aec == '\0') {
        puVar5 = &DAT_3ffc7aed;
        if (DAT_3ffc7aed == '\0') {
          uStack_39 = 0xc9;
          goto LAB_4015ca1f;
        }
        uStack_39 = 0xf;
      }
      else {
        uStack_39 = 0xcd;
      }
      *puVar5 = 0;
      memw();
      memw();
      goto LAB_4015ca1f;
    }
  }
  else if (!bVar2) {
    uVar8 = (uint)*(byte *)(iVar3 + 9);
    uVar9 = (uint)*(byte *)(iVar3 + 8);
    uVar10 = (uint)*(byte *)(iVar3 + 7);
    uVar11 = (uint)*(byte *)(iVar3 + 6);
    memw();
    FUN_40147fe4(1,5,4,0x3f434841,*(undefined1 *)(iVar3 + 4),*(undefined1 *)(iVar3 + 5),uVar11,
                 uVar10,uVar9,uVar8);
    if (*(char *)(_DAT_3ffc8800 + 0x154) == '\x03') {
      FUN_40147fe4(1,4,4,0x3f434829,3,1,uVar11,uVar10,uVar9,uVar8);
      *(undefined1 *)(_DAT_3ffc8800 + 0x154) = 1;
      memw();
    }
    memw();
    FUN_40147fe4(1,4,5,0x3f43633c,*(undefined1 *)(iVar3 + 4),*(undefined1 *)(iVar3 + 5),
                 *(undefined1 *)(iVar3 + 6),*(undefined1 *)(iVar3 + 7),*(undefined1 *)(iVar3 + 8),
                 *(undefined1 *)(iVar3 + 9),*(undefined1 *)(iVar3 + 0x28a));
    DAT_3ffc7aea = *(byte *)(iVar3 + 0x28a) ^ 1;
    memw();
    memw();
    iVar6 = FUN_4015b9c8(iVar3);
    if (iVar6 == 0) {
      memw();
      _DAT_3ffc91f8 = _DAT_3ffc91f8 & 0xffffffef;
      return 0;
    }
    if (iVar6 == 1) {
      _DAT_3ffca0c4 = _DAT_3ffca0c4 | 0x140;
    }
    memw();
    return iVar6;
  }
  uStack_39 = 0x6e;
  if (*(char *)(iVar3 + 0x28b) == '\0') {
    uStack_39 = 0x6f;
  }
LAB_4015ca1f:
  uStack_38 = 0x80;
  memw();
  memw();
  (*(code *)&SUB_4008b530)(auStack_3f,0,6);
  iVar3 = iStack_30 + 8;
  (*(code *)&SUB_4008b3d0)(auStack_60,iVar3);
  uStack_40 = (undefined1)*(undefined4 *)(iStack_30 + 4);
  memw();
  memw();
  FUN_4015c8f0();
  FUN_4015c604();
  FUN_40147fe4(1,5,4,0x3f4348cb,uStack_39);
  (**(code **)(_DAT_3ffc89a4 + 0x10))(uStack_39);
  FUN_40147240(5,auStack_60,0x29);
  cVar1 = *(char *)(_DAT_3ffc8800 + 0x154);
  if (cVar1 != '\0') {
    if (cVar1 == '\x02') {
      FUN_40147fe4(1,5,4,0x3f43489b);
    }
    else {
      FUN_40147fe4(1,4,4,0x3f434883,cVar1,3);
      *(undefined1 *)(_DAT_3ffc8800 + 0x154) = 3;
      memw();
      memw();
      iVar7 = FUN_40186978();
      if (iVar7 != 0) {
        FUN_40147fe4(1,4,3,0x3f435681,iVar3);
      }
    }
    iVar3 = FUN_40186978();
    iVar7 = iVar6 + 4;
    if (iVar3 == 0) {
      FUN_40147fe4(1,4,4,0x3f43486d);
      (**(code **)(_DAT_3ffc1a34 + 0xec))(iVar7);
      (**(code **)(_DAT_3ffc1a34 + 0xf0))(iVar7);
      (**(code **)(_DAT_3ffc1a34 + 0xec))(iVar6 + 0x68);
      (**(code **)(_DAT_3ffc1a34 + 0xf0))(iVar6 + 0x68);
      *(undefined1 *)(iVar6 + 0x7c) = 0;
      memw();
      memw();
      FUN_40162224(0);
      iVar6 = (**(code **)(_DAT_3ffc1a34 + 0x194))();
      if (iVar6 != 0) {
        FUN_4016221c();
      }
      FUN_401615bc();
    }
    else {
      FUN_40147fe4(1,4,3,0x3f435672);
      (**(code **)(_DAT_3ffc1a34 + 0xec))(iVar7);
      (**(code **)(_DAT_3ffc1a34 + 0xf0))(iVar7);
      (**(code **)(_DAT_3ffc1a34 + 0xf4))(iVar7,0x4015b8d8,0);
      uVar12 = 4000;
      if (DAT_3ffc89ec != '\x06') {
        uVar12 = 1000;
      }
      (**(code **)(_DAT_3ffc1a34 + 0xe8))(iVar7,uVar12,0);
    }
    return 0;
  }
  FUN_40147fe4(1,5,4,0x3f4348b8);
  return 0;
}

