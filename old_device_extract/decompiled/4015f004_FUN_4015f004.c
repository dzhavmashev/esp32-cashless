// Function : FUN_4015f004
// Address  : 0x4015f004
// Size     : 460 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4015f004(int param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  char *pcVar15;
  int aiStack_40 [4];
  int iStack_30;
  
  if (param_2 != 0) {
    if ((uint)*(ushort *)(param_1 + 0x16) + (uint)*(ushort *)(param_1 + 0x14) < 0x20) {
      return 0x104;
    }
    iVar10 = *(int *)(*(int *)(param_1 + 4) + 4);
    if ((*(byte *)(iVar10 + 0x1b) & 0x20) == 0) {
      uVar1 = *(undefined1 *)(iVar10 + 0xf);
      uVar2 = *(undefined1 *)(iVar10 + 0xb);
      uVar3 = *(undefined1 *)(iVar10 + 10);
      uVar4 = *(undefined1 *)(iVar10 + 0xe);
      uVar5 = *(undefined1 *)(iVar10 + 0xd);
      uVar6 = *(undefined1 *)(iVar10 + 0xc);
      pcVar15 = "ved bit";
    }
    else {
      if ((*(char *)(iVar10 + 0x1a) == '\0') && ((*(byte *)(iVar10 + 0x1b) & 0x1f) == 0)) {
        uVar8 = FUN_40186998(iVar10);
        uVar11 = (uint)*(byte *)(iVar10 + 0x19) << 8 | (uint)*(byte *)(iVar10 + 0x1c) << 0x10 |
                 (uint)*(byte *)(iVar10 + 0x18) | (uint)*(byte *)(iVar10 + 0x1d) << 0x18;
        uVar12 = (uint)*(ushort *)(iVar10 + 0x1e);
        iVar13 = (uVar8 & 0xffff) * 8 + param_2;
        uVar14 = *(uint *)(iVar13 + 8);
        uVar8 = *(uint *)(iVar13 + 0xc);
        if (((uVar14 != 0xffffffff) || (uVar8 != 0xffffffff)) &&
           (((uVar14 == uVar11 && (uVar8 == uVar12)) ||
            (((uVar12 - uVar8) - (uint)(uVar11 < uVar11 - uVar14) & 0x8000) != 0)))) {
          memw();
          FUN_40147fe4(1,0x20,1,"P frame",*(undefined1 *)(iVar10 + 4),*(undefined1 *)(iVar10 + 5),
                       *(undefined1 *)(iVar10 + 6),*(undefined1 *)(iVar10 + 7),
                       *(undefined1 *)(iVar10 + 8),*(undefined1 *)(iVar10 + 9),
                       *(undefined1 *)(iVar10 + 10),*(undefined1 *)(iVar10 + 0xb),
                       *(undefined1 *)(iVar10 + 0xc),*(undefined1 *)(iVar10 + 0xd),
                       *(undefined1 *)(iVar10 + 0xe),*(undefined1 *)(iVar10 + 0xf),uVar11,uVar12,
                       uVar14,uVar8,*(undefined2 *)(iVar10 + 0x16));
          return 0xffffffff;
        }
        iStack_30 = iVar10 + 0x18;
        memw();
        iVar9 = (*_DAT_3ffc8acc)(param_2 + 0xa8,iVar10,iStack_30,*(undefined2 *)(param_1 + 0x16),
                                 aiStack_40,0);
        iVar7 = iStack_30;
        if (iVar9 == 0) {
          return 0xffffffff;
        }
        memw();
        iStack_30 = iVar9;
        (*(code *)&SUB_4008b3d0)(iVar7,iVar9,aiStack_40[0]);
        memw();
        aiStack_40[0] = aiStack_40[0] + 0x18;
        (**(code **)(_DAT_3ffc1a34 + 0xb0))(iStack_30);
        *(byte *)(iVar10 + 1) = *(byte *)(iVar10 + 1) & 0xbf;
        memw();
        *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + -0x10;
        memw();
        *(uint *)(iVar13 + 8) = uVar11;
        *(uint *)(iVar13 + 0xc) = uVar12;
        memw();
        return 0;
      }
      uVar1 = *(undefined1 *)(iVar10 + 0xf);
      uVar2 = *(undefined1 *)(iVar10 + 0xb);
      uVar3 = *(undefined1 *)(iVar10 + 10);
      uVar4 = *(undefined1 *)(iVar10 + 0xe);
      uVar5 = *(undefined1 *)(iVar10 + 0xd);
      uVar6 = *(undefined1 *)(iVar10 + 0xc);
      pcVar15 = " seq=%u";
      memw();
    }
    memw();
    FUN_40147fe4(1,0x20,1,pcVar15,uVar3,uVar2,uVar6,uVar5,uVar4,uVar1);
  }
  return 0xffffffff;
}

