// Function : FUN_4015e850
// Address  : 0x4015e850
// Size     : 649 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4015e850(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  char *pcVar14;
  undefined1 auStack_90 [32];
  undefined1 uStack_70;
  undefined1 auStack_6f [6];
  undefined1 uStack_69;
  uint uStack_68;
  undefined1 auStack_64 [32];
  undefined1 uStack_44;
  undefined1 auStack_43 [19];
  int iStack_30;
  
  iVar3 = _DAT_3ffca0b8;
  iVar2 = _DAT_3ffc8800;
  iVar1 = _DAT_3ffbfc54;
  iVar4 = *(int *)(_DAT_3ffc8800 + 0xe4);
  if (iVar4 == 0) {
    FUN_40147fe4(1,4,2,0x3f436ce3);
    return 0;
  }
  if ((*(uint *)(iVar4 + 0xc) & 1) == 0) {
    iVar5 = _DAT_3ffbfc54 + 8;
    FUN_40154520(iVar4,auStack_43);
    uStack_44 = 0;
    memw();
    memw();
    (*(code *)&SUB_4008b3d0)(auStack_64,iVar5,0x20);
    iVar4 = *(int *)(iVar2 + 0xe4);
    pcVar8 = "passive";
    if ((*(char *)(iVar4 + 0xac) != '\0') && (pcVar8 = "p.c", *(char *)(iVar4 + 0xac) != '\x01')) {
      pcVar8 = &DAT_3f423a5a;
    }
    uVar9 = (uint)*(byte *)(iVar4 + 9);
    uVar10 = (uint)*(byte *)(iVar4 + 8);
    uVar11 = (uint)*(byte *)(iVar4 + 7);
    uVar12 = (uint)*(byte *)(iVar4 + 6);
    uVar13 = (uint)*(byte *)(iVar4 + 5);
    uVar6 = (uint)*(byte *)(iVar4 + 4);
    memw();
    FUN_40147fe4(1,4,3,0x3f435424,auStack_64,*(ushort *)(iVar4 + 0x26) & 0x3fff,
                 *(undefined1 *)(iVar4 + 0xab),pcVar8,uVar6,uVar13,uVar12,uVar11,uVar10,uVar9);
    pcVar14 = "W20";
    if (((DAT_3ffc89ee != '\a') && (pcVar14 = "", DAT_3ffc89ee != '\b')) &&
       (pcVar14 = "ve", DAT_3ffc89ee != '\x06')) {
      uVar7 = DAT_3ffc89ed - 1 & 0xff;
      pcVar14 = "on lost";
      if (uVar7 < 0xd) {
        pcVar14 = *(char **)(&DAT_3f424310 + uVar7 * 4);
      }
    }
    memw();
    FUN_40147fe4(1,4,3,0x3f435404,pcVar14,auStack_43,(int)*(char *)(iVar3 + 0xa4),pcVar8,uVar6,
                 uVar13,uVar12,uVar11,uVar10,uVar9);
    FUN_4015d408(iVar3);
    FUN_4015c604();
    if ((*(int *)(_DAT_3ffca40c + 4) == 0) || (*(int *)(_DAT_3ffca40c + 8) != 2)) {
      iStack_30 = iVar2 + 4;
      memw();
      (**(code **)(_DAT_3ffc1a34 + 0xec))(iStack_30);
      (**(code **)(_DAT_3ffc1a34 + 0xf0))(iStack_30);
      iStack_30 = iVar2 + 0x68;
      memw();
      (**(code **)(_DAT_3ffc1a34 + 0xec))(iStack_30);
      (**(code **)(_DAT_3ffc1a34 + 0xf0))(iStack_30);
      *(undefined1 *)(iVar2 + 0x7c) = 0;
      memw();
      memw();
      FUN_40162224(0);
      iVar4 = (**(code **)(_DAT_3ffc1a34 + 0x194))();
      if (iVar4 != 0) {
        FUN_4016221c();
      }
    }
    if (*(char *)(_DAT_3ffbfc54 + 0x92) == '\0') {
      (*(code *)&SUB_4008b3d0)(_DAT_3ffbfc54 + 0x93,*(int *)(iVar2 + 0xe4) + 4,6);
    }
    FUN_4014e1a8(*(undefined1 *)(*(int *)(iVar2 + 0xe4) + 0xab));
    *(uint *)(*(int *)(iVar2 + 0xe4) + 0xc) = *(uint *)(*(int *)(iVar2 + 0xe4) + 0xc) | 1;
    DAT_3ffc1a45 = 1;
    memw();
    memw();
    FUN_40147fe4(1,0xc,4,0x3f4342c4,7);
    FUN_4015a448(7);
    *(undefined1 *)(*(int *)(iVar2 + 0xe4) + 0x24) = 0;
    memw();
    memw();
    FUN_401615bc();
    if ((_DAT_3ffc8864 == 0) || (_DAT_3ffc1a40 == 0)) {
      FUN_4015d8cc(1,iVar3);
    }
    (*(code *)&SUB_4008b3d0)(auStack_90,iVar5);
    uStack_70 = (undefined1)*(undefined4 *)(iVar1 + 4);
    memw();
    memw();
    (*(code *)&SUB_4008b3d0)(auStack_6f,iVar2 + 0x9c,6);
    uStack_69 = *(undefined1 *)(*(int *)(iVar2 + 0xe4) + 0xab);
    memw();
    uStack_68 = (uint)*(byte *)(iVar3 + 0x28b);
    memw();
    (*(code *)&SUB_4008b3d0)(*(int *)(iVar2 + 0xe4) + 899,iVar5,0x20);
    (**(code **)(_DAT_3ffc89a4 + 0xc))(iVar3 + 4);
    FUN_40147fe4(1,4,4,0x3f4342ab);
    FUN_40147240(4,auStack_90,0x2c);
    FUN_40147fe4(1,4,4,0x3f434293,*(undefined1 *)(_DAT_3ffc8800 + 0x154),5);
    *(undefined1 *)(_DAT_3ffc8800 + 0x154) = 5;
    DAT_3ffc8a0b = 0;
    *(undefined1 *)(iVar3 + 0x340) = 0;
    memw();
  }
  memw();
  FUN_4015e5f8();
  return 1;
}

