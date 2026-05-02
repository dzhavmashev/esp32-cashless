// Function : FUN_4015d904
// Address  : 0x4015d904
// Size     : 812 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015d904(int *param_1,int param_2,char param_3)

{
  bool bVar1;
  byte bVar2;
  short sVar3;
  bool bVar4;
  char cVar5;
  ushort uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  bVar4 = _DAT_3ffca0b8 == param_1;
  if ((((_DAT_3ffc8864 != 0) && (*(ushort *)(_DAT_3ffbfc54 + 0x3f8) != *(ushort *)(param_2 + 10)))
      && (_DAT_3ffc8800 != 0)) &&
     ((*(int *)(_DAT_3ffc8800 + 0x98) == 5 && (*(int *)(_DAT_3ffc8800 + 0xe4) != 0)))) {
    uVar6 = 300;
    if (_DAT_3ffc1a40 == 0) {
      uVar6 = 1000;
    }
    if (uVar6 <= *(ushort *)(param_2 + 10)) {
      memw();
      (*_DAT_3ffc79b4)((short)param_1[10]);
    }
  }
  sVar3 = *(short *)(param_2 + 10);
  bVar1 = (short)param_1[10] != sVar3;
  if (bVar1) {
    *(short *)(param_1 + 10) = sVar3;
    memw();
  }
  if (*(char *)(_DAT_3ffc8800 + 0x154) != '\x05') {
    iVar7 = *(int *)(param_2 + 0x80);
    if (iVar7 == 0) {
      (*(code *)&SUB_4008b530)(param_1 + 0xcb,0,0x14);
    }
    else {
      memw();
      (*(code *)&SUB_4008b3d0)(param_1 + 0xcb,iVar7,*(byte *)(iVar7 + 1) + 2);
    }
    if ((*(int *)(param_2 + 0x3c) == 0) ||
       (bVar2 = *(byte *)(*(int *)(param_2 + 0x3c) + 1), 0x3e < bVar2)) {
      (*(code *)&SUB_4008b530)((int)param_1 + 0x342,0,0x40);
      *(undefined1 *)((int)param_1 + 0x341) = 0;
      memw();
    }
    else {
      *(byte *)((int)param_1 + 0x341) = bVar2 + 2;
      memw();
      memw();
      (*(code *)&SUB_4008b3d0)
                ((int)param_1 + 0x342,*(int *)(param_2 + 0x3c),
                 *(byte *)(*(int *)(param_2 + 0x3c) + 1) + 2);
    }
    if ((*(int *)(param_2 + 0x34) == 0) ||
       (bVar2 = *(byte *)(*(int *)(param_2 + 0x34) + 1), 0x3e < bVar2)) {
      (*(code *)&SUB_4008b530)((int)param_1 + 0x33,0,0x40);
      *(undefined1 *)(param_1 + 0xc) = 0;
      memw();
    }
    else {
      *(byte *)(param_1 + 0xc) = bVar2 + 2;
      memw();
      memw();
      (*(code *)&SUB_4008b3d0)
                ((int)param_1 + 0x33,*(int *)(param_2 + 0x34),
                 *(byte *)(*(int *)(param_2 + 0x34) + 1) + 2);
    }
    *(undefined1 *)((int)param_1 + 0x29e) = DAT_3ffc89ee;
    memw();
    *(undefined1 *)((int)param_1 + 0x29d) = DAT_3ffc89ed;
    cVar5 = DAT_3ffc8a69;
    memw();
    *(undefined2 *)(param_1 + 0xa9) = _DAT_3ffc89f4;
    *(bool *)((int)param_1 + 0x382) = cVar5 != '\0';
    memw();
    *(undefined1 *)(param_1 + 0xa7) = DAT_3ffc89ec;
    memw();
    *(undefined1 *)(param_1 + 0xa8) = DAT_3ffc89f0;
    memw();
    *(undefined1 *)((int)param_1 + 0x2a6) = DAT_3ffc89f6;
    memw();
  }
  if ((param_3 == '\0') && (iVar7 = *(int *)(param_2 + 0x18), iVar7 != 0)) {
    *(undefined1 *)((int)param_1 + 0x2f) = *(undefined1 *)(iVar7 + 2);
    memw();
    *(undefined1 *)((int)param_1 + 0x2e) = *(undefined1 *)(iVar7 + 3);
    memw();
  }
  uVar8 = *(undefined4 *)(param_2 + 0x1c);
  *(undefined2 *)(param_1 + 0xb) = *(undefined2 *)(param_2 + 8);
  memw();
  memw();
  (*(code *)&SUB_4008b3d0)(param_1 + 6,uVar8,8);
  if ((_DAT_3ffc8864 != 0) && (iVar7 = FUN_4015a384(), iVar7 != 0)) {
    memw();
    (*_DAT_3ffc7a1c)((short)param_1[10],DAT_3ffc7ae9,bVar1,0);
    DAT_3ffc7ae9 = 1;
    memw();
    if (_DAT_3ffc1a40 != 0) {
      memw();
      iVar7 = (*_DAT_3ffc7a38)();
      if (iVar7 != 0) {
        FUN_4015d8cc(1,param_1);
      }
    }
  }
  if ((((*(ushort *)(param_2 + 6) ^ *(ushort *)((int)param_1 + 0x2a)) & 0x400) != 0) && (bVar4)) {
    FUN_401869d0(&DAT_3ffc87f0,*(ushort *)(param_2 + 6) & 0x400);
  }
  *(undefined2 *)((int)param_1 + 0x2a) = *(undefined2 *)(param_2 + 6);
  memw();
  if (((*(uint *)(*param_1 + 0xa4) & 0x2000) == 0) || (*(int *)(param_2 + 0x40) == 0)) {
    if (*(char *)((int)param_1 + 0x87) != '\0') {
      (*(code *)&SUB_4008b530)((int)param_1 + 0x87,0,0x1d);
    }
  }
  else {
    param_1[3] = param_1[3] | 2;
    memw();
    iVar7 = FUN_4015868c(param_1);
    if (((iVar7 >> 0x1f) - iVar7 < 0) && (bVar4)) {
      FUN_40154c20(param_1,(int)param_1 + 0x87);
    }
  }
  if (((DAT_3ffc1a44 == '\0') || (memw(), DAT_3ffc1a3c != '\0')) || (_DAT_3ffc1a40 == 0)) {
    memw();
    iVar7 = _DAT_3ff73c00 + _DAT_3ffc1a30;
  }
  else {
    iVar7 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
  }
  uVar9 = *(undefined4 *)(param_2 + 0x2c);
  uVar8 = *(undefined4 *)(param_2 + 0x28);
  param_1[0xaa] = iVar7;
  memw();
  FUN_4014c490(param_1,uVar8,uVar9,0);
  uVar8 = 0;
  if (*(int *)(param_2 + 0x44) != 0) {
    uVar8 = FUN_4014d650();
  }
  FUN_4014c68c(param_1,uVar8);
  if (((*(int *)(param_2 + 0x44) == 0) || (*(int *)(param_2 + 0x48) == 0)) ||
     ((*(uint *)(*param_1 + 0x158) & 0x80000) == 0)) {
    if ((char)param_1[0x2b] != '\0') {
      *(undefined1 *)(param_1 + 0x2b) = 0;
      memw();
      if (param_1 == *(int **)(*param_1 + 0xe4)) {
        *(undefined1 *)(*param_1 + 0x157) = 0;
        memw();
        memw();
        FUN_4014b690((int)param_1 + 0xab);
      }
    }
  }
  else {
    FUN_4014ba40(param_1);
  }
  FUN_40154f84(param_1,*(undefined4 *)(param_2 + 0x20));
  FUN_4014c578(param_1);
  if (((_DAT_3ffc8a2c & 1) != 0) && (*(int *)(param_2 + 0x74) != 0)) {
    FUN_40158968(param_1);
  }
  return;
}

