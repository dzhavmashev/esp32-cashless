// Function : FUN_401268fc
// Address  : 0x401268fc
// Size     : 704 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_401268fc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  byte bVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  byte abStack_26a [2];
  undefined4 uStack_268;
  byte *pbStack_264;
  undefined4 uStack_25c;
  undefined4 uStack_258;
  undefined1 auStack_250 [12];
  undefined1 auStack_244 [31];
  byte abStack_225 [513];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar10 = *(int *)(*(int *)(param_1 + 0x48) + 0x44);
  iVar12 = iVar10 * 8;
  iVar10 = iVar10 << 4;
  memw();
  FUN_40128a7c(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x38),1);
  *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x38) = 0;
  memw();
  iVar3 = (*(code *)&SUB_40094dd8)(1,iVar10);
  iVar4 = FUN_40128a18();
  if ((iVar3 != 0) && (iVar4 != 0)) {
    memw();
    FUN_401268b8(param_2,param_3,auStack_250);
    uStack_258 = 1;
    bVar1 = 0x28;
    if (2 < *(int *)(param_1 + 0x3c) - 0x16U) {
      bVar1 = 1;
    }
    abStack_26a[0] = 1;
    memw();
    bVar8 = 0;
    uStack_268 = param_4;
    pbStack_264 = abStack_26a;
    uStack_25c = param_5;
    while( true ) {
      if (bVar1 < abStack_26a[0]) {
        if (bVar8 != 0) goto LAB_40126b76;
        if (200 < abStack_26a[0]) goto LAB_40126b82;
      }
      memw();
      iVar5 = FUN_401020e4(auStack_250,0xc,2,&uStack_268,&uStack_25c,auStack_244);
      if (iVar5 < 0) break;
      iVar5 = *(int *)(*(int *)(param_1 + 0x48) + 0x44);
      memw();
      iVar5 = FUN_40101bc4(auStack_244,0x20,&DAT_3f41a84b,
                           *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x48) + 0x48) + 0xc),iVar5,
                           abStack_225 + 1,iVar5 << 3);
      if (iVar5 < 0) break;
      uVar9 = 0;
      iVar5 = *(int *)(*(int *)(param_1 + 0x48) + 0x44);
      if (iVar5 != 0) {
        iVar14 = *(int *)(*(int *)(*(int *)(param_1 + 0x48) + 0x48) + 0xc);
        iVar13 = iVar5;
        do {
          iVar13 = iVar13 + -1;
          uVar11 = (uint)(abStack_225 + 1)[iVar13] - (uint)*(byte *)(iVar14 + iVar13);
          memw();
          uVar6 = FUN_4018572c(uVar11);
          uVar9 = (uVar9 ^ uVar11) & uVar6 ^ uVar11;
        } while (iVar13 != 0);
      }
      abStack_225[1] = (byte)((int)uVar9 >> 0x1f) & abStack_225[1];
      memw();
      memw();
      iVar5 = FUN_40128a30(abStack_225 + 1,iVar5);
      if (iVar5 == 0) {
LAB_40126a69:
        uVar6 = 0xffffffff;
        iVar13 = 0;
      }
      else if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x48) + 0x48) + 0x1c) & 1) == 0) {
        abStack_26a[1] = 1;
        memw();
        memw();
        iVar13 = FUN_40128a30(abStack_26a + 1,1);
        if (iVar13 == 0) goto LAB_40126a69;
        iVar14 = FUN_40128b3c(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4c),iVar13,iVar13);
        uVar6 = 0xffffffff;
        if (-1 < iVar14) {
          iVar14 = FUN_40128b54(iVar13,*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x50),iVar13);
          uVar6 = 0xffffffff;
          if (-1 < iVar14) goto LAB_40126afd;
        }
      }
      else {
        abStack_26a[1] = 2;
        memw();
        memw();
        iVar13 = FUN_40128a30(abStack_26a + 1,1);
        if (iVar13 == 0) goto LAB_40126a69;
LAB_40126afd:
        uVar6 = FUN_40128b08(iVar5,iVar13,*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4c),iVar4);
        if (-1 < (int)uVar6) {
          FUN_40128c14(iVar4);
          uVar6 = FUN_4018572c();
          FUN_40128c2c(iVar4);
          uVar11 = FUN_4018572c();
          uVar6 = (int)uVar9 >> 0x1f & 0xffU & uVar6 & uVar11 & 1;
        }
      }
      memw();
      FUN_40128a7c(iVar5,1);
      FUN_40128a7c(iVar13,1);
      if ((int)uVar6 < 0) break;
      iVar5 = FUN_40128a90(iVar4,iVar3 + iVar12,iVar12,iVar12);
      if (iVar5 < 0) break;
      FUN_40185740(bVar8,iVar3,iVar3 + iVar12,iVar12,iVar3);
      bVar2 = FUN_4018572c(uVar6 ^ 1);
      bVar8 = bVar2 ^ bVar8 & (bVar2 ^ 0xff);
      abStack_26a[0] = abStack_26a[0] + 1;
      memw();
      memw();
    }
    if (bVar8 != 0) {
LAB_40126b76:
      iVar5 = *(int *)(param_1 + 0x48);
      uVar7 = FUN_40128a30(iVar3,iVar12);
      *(undefined4 *)(iVar5 + 0x38) = uVar7;
    }
  }
LAB_40126b82:
  memw();
  FUN_40128a7c(iVar4,1);
  FUN_4010529c(iVar3,iVar10);
  iVar3 = *(int *)(*(int *)(param_1 + 0x48) + 0x38);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return -(uint)(iVar3 == 0);
}

