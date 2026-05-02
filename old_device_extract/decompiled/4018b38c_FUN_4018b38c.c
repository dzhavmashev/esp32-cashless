// Function : FUN_4018b38c
// Address  : 0x4018b38c
// Size     : 789 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018b38c(int param_1,undefined4 *param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  code *pcVar7;
  uint uVar8;
  undefined8 uVar9;
  longlong lVar10;
  uint auStack_50 [4];
  int iStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  int iStack_30;
  
  iVar2 = (**(code **)(_DAT_3ffc1a34 + 0x194))();
  _DAT_3ffca200 = _DAT_3ffc0018;
  if (iVar2 == 0) {
    _DAT_3ffca200 = _DAT_3ffc0014;
  }
  memw();
  iStack_40 = (*(code *)&SUB_4000d280)(*param_2,param_2[1],_DAT_3ffca204,0);
  param_1 = param_1 - iStack_40;
  memw();
  uVar3 = (**(code **)(_DAT_3ffc1a34 + 0x194))();
  uVar6 = _DAT_3ffca204;
  if (uVar3 == 0) {
    if (_DAT_3ffca1fc != 0) {
      if (_DAT_3ffca1fc == 1) {
        if (param_3 != 0) {
          uVar6 = (uint)*(byte *)(param_3 + 2);
          if (uVar6 == 0) {
            uVar6 = (uint)*(byte *)(param_3 + 3);
          }
          uVar6 = uVar6 * _DAT_3ffca204;
        }
      }
      else if (_DAT_3ffca1fc == 2) {
        uVar6 = (uint)_DAT_3ffca1f8;
        uStack_34 = _DAT_3ffca204;
        memw();
        uStack_38 = uVar3;
        uVar9 = (*(code *)&SUB_4000cff8)(*param_2,param_2[1],_DAT_3ffca204,0);
        iVar2 = (*(code *)&SUB_4000d280)((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),uVar6,uStack_38)
        ;
        uVar6 = uStack_34 * (uVar6 - iVar2);
      }
    }
  }
  else if (DAT_3ffca1e6 != '\0') {
    iVar2 = (**(code **)(_DAT_3ffc1a34 + 0x1c0))();
    uVar9 = (*(code *)&SUB_4000cff8)(*param_2,param_2[1],_DAT_3ffca204,0);
    uStack_3c = (uint)((ulonglong)uVar9 >> 0x20);
    uStack_34 = (uint)uVar9;
    memw();
    uVar4 = (**(code **)(_DAT_3ffc1a34 + 0x1c0))();
    iVar5 = (*(code *)&SUB_4000d280)(uStack_34,uStack_3c,uVar4,0);
    uVar6 = _DAT_3ffca204 * (iVar2 - iVar5);
  }
  iVar2 = param_1 + uVar6;
  uVar6 = iVar2 - _DAT_3ffca200;
  if (((DAT_3ffc1a44 == '\0') || (memw(), DAT_3ffc1a3c != 0)) || (_DAT_3ffc1a40 == 0)) {
    memw();
    uVar3 = _DAT_3ff73c00 + _DAT_3ffc1a30;
  }
  else {
    memw();
    iStack_30 = iVar2;
    uVar3 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
    iVar2 = iStack_30;
  }
  uVar8 = 0x65;
  while ((((uVar1 = _DAT_3ffca1f8, uVar6 < uVar3 && (-1 < (int)(uVar3 - uVar6))) ||
          ((uVar3 < uVar6 && (0x80000000 < uVar6 - uVar3)))) || (uVar6 - uVar3 < 5000))) {
    uVar8 = uVar8 - 1;
    iVar2 = iVar2 + _DAT_3ffca204;
    uVar6 = iVar2 - _DAT_3ffca200;
    if (uVar8 == 0) {
      uVar6 = 0;
      uVar3 = 0;
      if (param_3 != 0) {
        uVar6 = (uint)*(byte *)(param_3 + 3);
        uVar3 = (uint)*(byte *)(param_3 + 2);
      }
      if (((DAT_3ffc1a44 == '\0') || (memw(), DAT_3ffc1a3c != 0)) || (_DAT_3ffc1a40 == 0)) {
        memw();
        iVar5 = _DAT_3ff73c00 + _DAT_3ffc1a30;
        uVar8 = _DAT_3ffca204;
      }
      else {
        uStack_38 = _DAT_3ffca204;
        memw();
        uStack_3c = uVar6;
        uStack_34 = uVar3;
        iStack_30 = iVar2;
        iVar5 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
        uVar8 = uStack_38;
        iVar2 = iStack_30;
        uVar6 = uStack_3c;
        uVar3 = uStack_34;
      }
      memw();
      FUN_40147fe4(6,0x1000,2,0x3f436f1e,param_1,iStack_40,iVar2,uVar8,uVar6,uVar3,uVar1,iVar5);
      return;
    }
    if (((DAT_3ffc1a44 == '\0') || (memw(), DAT_3ffc1a3c != 0)) || (_DAT_3ffc1a40 == 0)) {
      memw();
      uVar3 = _DAT_3ff73c00 + _DAT_3ffc1a30;
    }
    else {
      memw();
      uStack_3c = uVar8;
      iStack_30 = iVar2;
      uVar3 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
      iVar2 = iStack_30;
      uVar8 = uStack_3c;
    }
  }
  (**(code **)(_DAT_3ffc1a34 + 0xec))(0x3ffca27c);
  lVar10 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
  if (((DAT_3ffc1a44 == '\0') || (memw(), DAT_3ffc1a3c != 0)) || (_DAT_3ffc1a40 == 0)) {
    memw();
    iVar2 = _DAT_3ff73c00 + _DAT_3ffc1a30;
  }
  else {
    memw();
    uStack_38 = (uint)((ulonglong)lVar10 >> 0x20);
    iStack_30 = (int)lVar10;
    iVar2 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
    lVar10 = CONCAT44(uStack_38,iStack_30);
  }
  _DAT_3ffca230 = lVar10 + (ulonglong)(uVar6 - iVar2);
  if (DAT_3ffc1a44 != '\0') {
    memw();
    auStack_50[0] = (uint)DAT_3ffc1a3c;
    if ((DAT_3ffc1a3c == 0) && (_DAT_3ffc1a40 != 0)) {
      memw();
      (*_DAT_3ffc7a24)(_DAT_3ffca204,DAT_3ffca1e3,iStack_40,auStack_50);
      (**(code **)(_DAT_3ffc1a34 + 0xf8))(0x3ffca27c,auStack_50[0],0);
      return;
    }
  }
  pcVar7 = *(code **)(_DAT_3ffc1a34 + 0xf8);
  if (((DAT_3ffc1a44 == '\0') || (memw(), DAT_3ffc1a3c != 0)) || (_DAT_3ffc1a40 == 0)) {
    memw();
    iVar2 = _DAT_3ff73c00 + _DAT_3ffc1a30;
  }
  else {
    iVar2 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
  }
  (*pcVar7)(0x3ffca27c,uVar6 - iVar2,0);
  return;
}

