// Function : FUN_40189534
// Address  : 0x40189534
// Size     : 765 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40189534(int param_1,int param_2,uint param_3)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  uint uVar9;
  
  uVar5 = (uint)*(byte *)(param_2 + 7);
  if ((((uVar5 == 0) || (*(int *)(param_1 + 0x60) == 0)) || (*(char *)(param_1 + 0xe) != '\x02')) ||
     ((*(byte *)(param_1 + 0xb) & 4) != 0)) goto LAB_40189839;
  bVar8 = *(byte *)(param_2 + 6);
  uVar6 = (uint)bVar8;
  uVar2 = (param_3 & 0xffff) + 0x7ff >> 0xb;
  uVar7 = *(uint *)(param_2 + 4) & 0xf;
  uVar9 = (uint)*(byte *)(param_2 + 5);
  if (*(char *)(param_2 + 0x13) == '\x01') {
    uVar5 = uVar5 + uVar9 * uVar2;
    if ((*(uint *)(param_1 + 0x18) & 0x400) == 0) {
      FUN_40186cc0(param_1,(int)*(char *)(param_2 + 0xd));
    }
LAB_401895a9:
    if (uVar5 < uVar6) goto LAB_40189839;
  }
  else {
    if (bVar8 != 0) {
      uVar5 = uVar5 + (uVar9 - 1 & 0xffff) * uVar2 & 0xffff;
      goto LAB_401895a9;
    }
    uVar5 = uVar9 * uVar2;
  }
  if (0x1ffffff < *(uint *)(param_1 + 0x44) + uVar6) {
    *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) >> 1;
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) >> 1;
  }
  *(uint *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + uVar6;
  *(uint *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + uVar5;
  memw();
  uVar2 = (**(code **)(param_1 + 0x74))(*(undefined1 *)(param_1 + 0xd));
  if (bVar8 == 0) {
    bVar8 = *(char *)(param_1 + 0xc) + 1;
    *(char *)(param_1 + 0xf) = (char)uVar5 + *(char *)(param_1 + 0xf);
    memw();
    *(byte *)(param_1 + 0xc) = bVar8;
    memw();
    memw();
    iVar3 = (**(code **)(param_1 + 0x74))(0x10);
    if (((iVar3 < (int)(bVar8 + uVar2)) && (uVar2 < DAT_3ffc06f4)) ||
       ((8 < *(byte *)(param_1 + 0xc) || (0x40 < *(byte *)(param_1 + 0xf))))) goto LAB_4018975a;
  }
  else if (*(char *)(param_1 + 0xc) != '\0') {
    *(undefined1 *)(param_1 + 0xc) = 0;
    memw();
    memw();
    return;
  }
  uVar7 = FUN_401649e8(param_1);
  if (uVar7 < (uVar6 << 7) / uVar5) {
    *(undefined1 *)(param_1 + 0xf) = 0;
    memw();
  }
  if (((DAT_3ffc1a44 == '\0') || (memw(), DAT_3ffc1a3c != '\0')) || (_DAT_3ffc1a40 == 0)) {
    memw();
    iVar3 = _DAT_3ff73c00 + _DAT_3ffc1a30;
  }
  else {
    memw();
    iVar3 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
  }
  uVar5 = FUN_40186c30(iVar3,*(undefined4 *)(param_1 + 0x4c));
  uVar6 = *(uint *)(param_1 + 0x40);
  if ((uVar6 == 0) || ((uVar5 < 100000 && (uVar6 < 500)))) goto LAB_40189839;
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
  uVar6 = (uint)(*(int *)(param_1 + 0x44) << 7) / uVar6;
  uVar5 = (uint)*(byte *)(param_1 + 0x1e);
  *(int *)(param_1 + 0x4c) = iVar3;
  *(char *)(param_1 + 0x1d) = (char)uVar6;
  memw();
  if (uVar5 == 0) {
    uVar5 = uVar7 * 3 + 0x80 >> 2;
    if ((uVar5 & 0xff) < (uVar6 & 0xff)) {
      *(char *)(param_1 + 0x1e) = (char)((int)((uVar5 & 0xff) + (uVar6 & 0xff)) >> 1);
      memw();
      memw();
    }
    else {
      *(char *)(param_1 + 0x1e) = (char)uVar5;
      memw();
    }
  }
  else {
    uVar6 = (int)(uVar5 * 3 + (uVar6 & 0xff)) >> 2;
    *(char *)(param_1 + 0x1e) = (char)uVar6;
    memw();
    if (uVar5 < uVar7) {
      if (uVar6 < uVar7) {
        if ((*(char *)(param_1 + 0x27) != '\0') && (*(uint *)(param_1 + 0x5c) < 4000000)) {
          *(uint *)(param_1 + 0x5c) = *(uint *)(param_1 + 0x5c) << 1;
        }
        memw();
        uVar5 = FUN_40186c30(iVar3,*(undefined4 *)(param_1 + 0x50));
        if (100000 < uVar5) {
          uVar7 = 0;
LAB_4018975a:
          FUN_40164a58(param_1,uVar2,uVar7);
          return;
        }
        goto LAB_4018982e;
      }
      memw();
    }
    if (*(char *)(param_1 + 0x27) == '\0') {
      if (*(byte *)(param_1 + 4) != uVar2) {
        memw();
        uVar7 = FUN_40164b38(param_1);
        if (((uVar7 < uVar5) && (uVar7 < uVar6)) &&
           (uVar5 = FUN_40186c30(iVar3,*(undefined4 *)(param_1 + 0x54)),
           *(uint *)(param_1 + 0x5c) < uVar5)) {
          if (((DAT_3ffc1a44 == '\0') || (memw(), DAT_3ffc1a3c != '\0')) || (_DAT_3ffc1a40 == 0)) {
            memw();
            iVar3 = _DAT_3ff73c00 + _DAT_3ffc1a30;
          }
          else {
            iVar3 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
          }
          *(int *)(param_1 + 0x54) = iVar3;
          *(undefined1 *)(param_1 + 0xc) = 0;
          memw();
          uVar1 = *(undefined1 *)((uVar2 - 1 & 0xff) * 0xc + *(int *)(param_1 + 0x70));
          *(undefined1 *)(param_1 + 0x27) = 1;
          *(undefined1 *)(param_1 + 0xd) = uVar1;
          memw();
          memw();
          uVar4 = FUN_40163f8c();
          FUN_40186c6c(param_1,uVar4);
          FUN_401641ec(param_1);
          return;
        }
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x27) = 0;
      memw();
      *(undefined4 *)(param_1 + 0x5c) = 500000;
      memw();
    }
  }
LAB_4018982e:
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
LAB_40189839:
  memw();
  return;
}

