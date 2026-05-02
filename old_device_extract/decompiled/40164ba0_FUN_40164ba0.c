// Function : FUN_40164ba0
// Address  : 0x40164ba0
// Size     : 489 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40164ba0(int param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  uint uVar10;
  
  if (((DAT_3ffc1a44 == '\0') || (memw(), DAT_3ffc1a3c != '\0')) || (_DAT_3ffc1a40 == 0)) {
    memw();
    iVar3 = _DAT_3ff73c00 + _DAT_3ffc1a30;
  }
  else {
    iVar3 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
  }
  uVar6 = *(undefined4 *)(param_1 + 0x38);
  uVar4 = FUN_40186c30(iVar3,uVar6);
  if (((*(uint *)(param_1 + 0x28) == 0) || (*(uint *)(param_1 + 0x3c) < 100)) || (uVar4 < 0x1e848))
  {
    uVar8 = *(undefined4 *)(param_1 + 0x4c);
    uVar4 = FUN_40186c30(uVar8,uVar6);
    if ((*(char *)(param_1 + 0xe) != '\x02') || (uVar4 < 0x1e848)) {
      return;
    }
    bVar2 = *(byte *)(*(int *)(param_1 + 0x60) + 10);
    *(undefined4 *)(param_1 + 0x38) = uVar8;
    *(undefined4 *)(param_1 + 0x5c) = 500000;
    memw();
    FUN_401641bc(param_1);
    iVar3 = *(int *)(param_1 + 0x70);
    uVar4 = (**(code **)(param_1 + 0x74))(*(undefined1 *)(param_1 + 0xd));
    iVar3 = (uVar4 & 0xffff) * 0xc + iVar3;
    *(int *)(param_1 + 0x60) = iVar3;
    bVar1 = *(byte *)(iVar3 + 10);
    if (bVar2 < bVar1) {
      *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x4c);
      memw();
    }
    else if (bVar1 < bVar2) {
      *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x4c);
      memw();
    }
  }
  else {
    uVar10 = (uint)(*(int *)(param_1 + 0x2c) << 7) / *(uint *)(param_1 + 0x28);
    uVar4 = _DAT_3ffc06dc + 1;
    _DAT_3ffc06dc = uVar4;
    *(int *)(param_1 + 0x38) = iVar3;
    *(char *)(param_1 + 0x1b) = (char)uVar10;
    memw();
    if (*(byte *)(param_1 + 0x1c) == 0) {
      uVar4 = (int)((uint)*(byte *)(*(int *)(param_1 + 0x60) + 9) * 3 + 0x80) >> 2;
      if ((uVar4 & 0xff) < (uVar10 & 0xff)) {
        *(char *)(param_1 + 0x1c) = (char)((int)((uVar10 & 0xff) + uVar4) >> 1);
        memw();
        memw();
      }
      else {
        *(char *)(param_1 + 0x1c) = (char)uVar4;
        memw();
        memw();
      }
    }
    else {
      memw();
      iVar7 = (int)((uVar10 & 0xff) + (uint)*(byte *)(param_1 + 0x1c)) >> 1;
      *(char *)(param_1 + 0x1c) = (char)iVar7;
      memw();
      memw();
      uVar10 = FUN_40186c30(iVar3,*(undefined4 *)(param_1 + 0x34));
      iVar5 = FUN_40164994(param_1,iVar7);
      if ((iVar5 == 0) || (uVar10 <= *(uint *)(param_1 + 0x5c))) {
        puVar9 = *(undefined1 **)(param_1 + 0x60);
        bVar2 = puVar9[0xb];
        if (((bVar2 & 1) != 0) || ((uVar4 & 3) == 0)) {
          memw();
          uVar4 = FUN_40164858(*(undefined1 *)(param_1 + 1),*puVar9);
          if (iVar7 < (int)((uint)(byte)puVar9[9] - (uVar4 >> 1 & 0xff))) {
            if (((bVar2 & 1) != 0) && (*(uint *)(param_1 + 0x5c) < 4000000)) {
              *(uint *)(param_1 + 0x5c) = *(uint *)(param_1 + 0x5c) << 1;
            }
            memw();
            uVar4 = FUN_40186c30(iVar3,*(undefined4 *)(param_1 + 0x30));
            if ((0x1e848 < uVar4) && (0x1e848 < uVar10)) {
              FUN_401644f4(param_1,1);
            }
          }
          else if ((bVar2 & 1) != 0) {
            puVar9[0xb] = bVar2 & 0xfe;
            memw();
            *(undefined4 *)(param_1 + 0x5c) = 500000;
          }
        }
      }
      else {
        FUN_40164570(param_1);
      }
    }
  }
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  memw();
  return;
}

