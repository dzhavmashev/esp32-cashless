// Function : FUN_40126bc0
// Address  : 0x40126bc0
// Size     : 937 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40126bc0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  byte bStack_221;
  undefined4 uStack_220;
  undefined4 uStack_21c;
  int iStack_218;
  byte *pbStack_214;
  undefined4 uStack_20c;
  undefined4 uStack_208;
  undefined1 auStack_1fe [12];
  undefined1 auStack_1f2 [66];
  undefined1 auStack_1b0 [66];
  undefined1 auStack_16e [66];
  undefined1 auStack_12c [66];
  undefined1 auStack_ea [65];
  byte abStack_a9 [32];
  byte bStack_89;
  undefined1 auStack_66 [66];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  uStack_220 = 0;
  uStack_21c = 0;
  memw();
  (*(code *)&SUB_4008b530)(auStack_1b0,0,0x42);
  iVar2 = (*(code *)&SUB_40094d60)(param_5);
  memw();
  iVar3 = (*(code *)&SUB_40094d60)(param_5);
  if (((iVar2 != 0) && (iVar3 != 0)) && (iVar4 = FUN_40102858(iVar2,param_5), -1 < iVar4)) {
    iVar9 = *(int *)(*(int *)(param_1 + 0x48) + 0x44);
    iVar4 = FUN_40128a90(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4c),auStack_1f2,0x42,iVar9);
    if (((-1 < iVar4) &&
        (iVar4 = FUN_40128624(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4c),&uStack_220,
                              &uStack_21c), -1 < iVar4)) &&
       ((iVar4 = FUN_40128a90(uStack_220,auStack_12c,0x42,iVar9), -1 < iVar4 &&
        (iVar4 = FUN_40128a90(uStack_21c,auStack_ea,0x42,iVar9), -1 < iVar4)))) {
      FUN_401268b8(param_2,param_3,auStack_1fe);
      pbStack_214 = &bStack_221;
      uStack_208 = 1;
      bStack_221 = 1;
      memw();
      uVar8 = 0;
      uVar10 = 0;
      iStack_218 = iVar3;
      uStack_20c = param_5;
      while (bStack_221 < 0x29) {
LAB_40126ce2:
        memw();
        FUN_40185740(uVar8,iVar2,param_4,param_5,iVar3);
        iVar4 = FUN_401020e4(auStack_1fe,0xc,2,&iStack_218,&uStack_20c,abStack_a9 + 1);
        if (iVar4 < 0) {
          if (uVar8 != 0) goto LAB_40126e48;
          goto LAB_40126c20;
        }
        uVar5 = FUN_40128d78(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x40));
        memw();
        iVar4 = FUN_40101bc4(abStack_a9 + 1,0x20,&DAT_3f41a84b,auStack_1f2,
                             *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x44),auStack_16e,uVar5);
        if (iVar4 < 0) {
LAB_40126d4c:
          iVar7 = -1;
        }
        else {
          if ((uVar5 & 7) != 0) {
            FUN_40185770(auStack_16e,*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x44),
                         8 - (uVar5 & 7));
          }
          uVar11 = *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x44);
          memw();
          iVar7 = 0;
          iVar4 = (*(code *)&SUB_4008b33c)(auStack_16e,auStack_1f2,uVar11);
          if (iVar4 < 0) {
            iVar4 = FUN_40128a30(auStack_16e,uVar11);
            if (iVar4 != 0) {
              iVar6 = FUN_40128f18(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x40),iVar4);
              memw();
              FUN_40128a7c(iVar4,1);
              if (iVar6 != 0) {
                iVar7 = FUN_401286b0(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x40),auStack_12c,
                                     auStack_ea,iVar6);
                FUN_40128a7c(iVar6,1);
                goto LAB_40126d4f;
              }
            }
            goto LAB_40126d4c;
          }
        }
LAB_40126d4f:
        FUN_40185740(uVar8,auStack_1b0,auStack_16e,iVar9);
        uVar10 = bStack_89 & 1 ^ uVar8 & (bStack_89 & 1 ^ uVar10);
        (*(code *)&SUB_4008b530)(abStack_a9 + 1,0,0x20);
        if (iVar7 < 0) goto LAB_40126c20;
        uVar8 = -iVar7 & 0xffU | uVar8;
        bStack_221 = bStack_221 + 1;
        memw();
        memw();
      }
      if (uVar8 == 0) {
        if (bStack_221 < 0xc9) goto LAB_40126ce2;
        iVar4 = 0;
        goto LAB_40126c22;
      }
LAB_40126e48:
      iVar4 = FUN_40128a30(auStack_1b0,iVar9);
      if (iVar4 != 0) {
        iVar7 = FUN_40128f18(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x40),iVar4);
        if (iVar7 == 0) goto LAB_40126f08;
        iVar6 = FUN_40128838(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x40),iVar7,iVar7);
        if (iVar6 < 0) goto LAB_40126f08;
        iVar6 = FUN_40128a90(iVar7,abStack_a9 + 1,0x42,iVar9);
        if (iVar6 < 0) goto LAB_40126f08;
        iVar6 = FUN_40128b3c(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4c),iVar7,iVar7);
        if (iVar6 < 0) goto LAB_40126f08;
        iVar6 = FUN_40128a90(iVar7,auStack_66,0x42,iVar9);
        if (iVar6 < 0) goto LAB_40126f08;
        uVar1 = FUN_4018572c(abStack_a9[iVar9] & 1 ^ uVar10);
        FUN_40185740(uVar1,abStack_a9 + 1,auStack_66,iVar9,abStack_a9 + 1 + iVar9);
        (*(code *)&SUB_4008b3d0)(abStack_a9 + 1,auStack_1b0,iVar9);
        FUN_40128d84(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x34),1);
        iVar9 = *(int *)(param_1 + 0x48);
        uVar11 = FUN_40128dd4(*(undefined4 *)(iVar9 + 0x40),abStack_a9 + 1);
        *(undefined4 *)(iVar9 + 0x34) = uVar11;
        goto LAB_40126f08;
      }
    }
  }
LAB_40126c20:
  iVar4 = 0;
LAB_40126c22:
  while( true ) {
    memw();
    iVar7 = iVar4;
LAB_40126f08:
    memw();
    FUN_40102884(abStack_a9 + 1,0x84);
    FUN_40128a7c(uStack_220,0);
    FUN_40128a7c(uStack_21c,0);
    FUN_40128a7c(iVar7,1);
    (*(code *)&SUB_40094d80)(iVar2);
    FUN_4010529c(iVar3,param_5);
    FUN_40128a7c(iVar4,1);
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    (*(code *)&SUB_40082ec4)();
    iVar4 = iVar7;
  }
  return;
}

