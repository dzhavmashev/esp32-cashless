// Function : FUN_4013b574
// Address  : 0x4013b574
// Size     : 1063 bytes


int FUN_4013b574(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puStack_c4;
  undefined1 *puStack_c0;
  int iStack_bc;
  undefined1 auStack_b0 [12];
  undefined1 auStack_a4 [12];
  undefined1 auStack_98 [12];
  undefined1 auStack_8c [12];
  undefined1 auStack_80 [12];
  undefined1 auStack_74 [12];
  undefined1 auStack_68 [12];
  undefined1 auStack_5c [12];
  undefined1 auStack_50 [12];
  undefined1 auStack_44 [12];
  undefined1 auStack_38 [12];
  undefined1 auStack_2c [44];
  
  memw();
  iVar1 = FUN_4013b074(param_1,1);
  if (iVar1 != 0) {
    return -0x4080;
  }
  FUN_40186008(auStack_b0);
  FUN_40186008(auStack_a4);
  FUN_40186008(auStack_98);
  FUN_40186008(auStack_8c);
  if (param_2 != 0) {
    FUN_40186008(auStack_68);
    FUN_40186008(auStack_5c);
  }
  FUN_40186008(auStack_80);
  FUN_40186008(auStack_74);
  FUN_40186008(auStack_50);
  FUN_40186008(auStack_44);
  iVar1 = FUN_4013183c(auStack_b0,param_4,*(undefined4 *)(param_1 + 4));
  if (iVar1 == 0) {
    iVar4 = param_1 + 8;
    iVar2 = FUN_401860ec(auStack_b0,iVar4);
    iVar1 = -4;
    if (iVar2 < 0) {
      puStack_c4 = (undefined1 *)(param_1 + 0x44);
      puStack_c0 = (undefined1 *)(param_1 + 0x50);
      if (param_2 != 0) {
        memw();
        FUN_40186008(auStack_2c);
        if (*(int *)(param_1 + 0xa0) == 0) {
          iVar2 = param_1 + 0x8c;
          iStack_bc = 0xc;
          do {
            iStack_bc = iStack_bc + -1;
            if (iStack_bc == 0) {
              iVar1 = -0x4480;
              goto LAB_4013b651;
            }
            memw();
            iVar1 = FUN_401323a8(param_1 + 0x98,*(int *)(param_1 + 4) + -1,param_2,param_3);
            if (((((iVar1 != 0) ||
                  (iVar1 = FUN_401323a8(auStack_2c,*(int *)(param_1 + 4) + -1,param_2,param_3),
                  iVar1 != 0)) ||
                 (iVar1 = FUN_4013d5d8(iVar2,param_1 + 0x98,auStack_2c), iVar1 != 0)) ||
                (iVar1 = FUN_401320e0(iVar2,iVar2,iVar4), iVar1 != 0)) ||
               ((iVar1 = FUN_40132650(iVar2,iVar2,iVar4), iVar1 != 0 && (iVar1 != -0xe))))
            goto LAB_4013b651;
          } while (iVar1 == -0xe);
          iVar1 = FUN_4013d5d8(iVar2,iVar2,auStack_2c);
          if ((iVar1 == 0) && (iVar1 = FUN_401320e0(iVar2,iVar2,iVar4), iVar1 == 0)) {
            iVar1 = FUN_4013d3d8(iVar2,iVar2,param_1 + 0x14,iVar4,param_1 + 0x68);
          }
        }
        else {
          iVar2 = param_1 + 0x8c;
          iVar1 = FUN_4013d5d8(iVar2,iVar2,iVar2);
          if ((iVar1 == 0) && (iVar1 = FUN_401320e0(iVar2,iVar2,iVar4), iVar1 == 0)) {
            iVar2 = param_1 + 0x98;
            iVar1 = FUN_4013d5d8(iVar2,iVar2,iVar2);
            if (iVar1 == 0) {
              iVar1 = FUN_401320e0(iVar2,iVar2,iVar4);
            }
          }
        }
LAB_4013b651:
        FUN_40131548(auStack_2c);
        if ((((((iVar1 != 0) ||
               (iVar1 = FUN_4013d5d8(auStack_b0,auStack_b0,param_1 + 0x8c), iVar1 != 0)) ||
              (iVar1 = FUN_401320e0(auStack_b0,auStack_b0,iVar4), iVar1 != 0)) ||
             (((iVar1 = FUN_40131d74(auStack_a4,param_1 + 0x2c,1), iVar1 != 0 ||
               (iVar1 = FUN_40131d74(auStack_98,param_1 + 0x38,1), iVar1 != 0)) ||
              ((iVar1 = FUN_401323a8(auStack_8c,0x1c,param_2,param_3), iVar1 != 0 ||
               ((iVar1 = FUN_4013d5d8(auStack_68,auStack_a4,auStack_8c), iVar1 != 0 ||
                (iVar1 = FUN_40131d18(auStack_68,auStack_68,puStack_c4), iVar1 != 0)))))))) ||
            (iVar1 = FUN_401323a8(auStack_8c,0x1c,param_2,param_3), iVar1 != 0)) ||
           ((iVar1 = FUN_4013d5d8(auStack_5c,auStack_98,auStack_8c), iVar1 != 0 ||
            (iVar1 = FUN_40131d18(auStack_5c,auStack_5c,puStack_c0), iVar1 != 0))))
        goto LAB_4013b7e4;
        puStack_c0 = auStack_5c;
        puStack_c4 = auStack_68;
      }
      memw();
      iVar1 = FUN_4013167c(auStack_50,auStack_b0);
      if (iVar1 == 0) {
        iVar1 = FUN_4013d3d8(auStack_80,auStack_b0,puStack_c4,param_1 + 0x2c,param_1 + 0x74);
        if (iVar1 == 0) {
          iVar1 = FUN_4013d3d8(auStack_74,auStack_b0,puStack_c0,param_1 + 0x38,param_1 + 0x80);
          if ((((iVar1 == 0) && (iVar1 = FUN_40131d30(auStack_b0,auStack_80,auStack_74), iVar1 == 0)
               ) && (iVar1 = FUN_4013d5d8(auStack_80,auStack_b0,param_1 + 0x5c), iVar1 == 0)) &&
             (((iVar1 = FUN_401320e0(auStack_b0,auStack_80,param_1 + 0x2c), iVar1 == 0 &&
               (iVar1 = FUN_4013d5d8(auStack_80,auStack_b0,param_1 + 0x38), iVar1 == 0)) &&
              ((iVar1 = FUN_40131d18(auStack_b0,auStack_74,auStack_80), iVar1 == 0 &&
               (iVar1 = FUN_4013d3d8(auStack_44,auStack_b0,param_1 + 0x14,iVar4,param_1 + 0x68),
               iVar1 == 0)))))) {
            iVar2 = FUN_401860ec(auStack_44,auStack_50);
            iVar1 = -0x4380;
            if (iVar2 == 0) {
              if (param_2 != 0) {
                iVar2 = *(int *)(param_1 + 0xc);
                uVar3 = FUN_401861f0(*(undefined4 *)(param_1 + 0x10));
                memw();
                FUN_40186008(auStack_38);
                FUN_40186008(auStack_2c);
                iVar1 = FUN_40132284(auStack_38,iVar4);
                if (((iVar1 == 0) && (iVar1 = FUN_40131574(auStack_2c,(iVar2 + 1) * 2), iVar1 == 0))
                   && (iVar1 = FUN_40131574(auStack_b0,iVar2), iVar1 == 0)) {
                  iVar1 = FUN_40131574(param_1 + 0x98,iVar2);
                  if (iVar1 == 0) {
                    FUN_40132190(auStack_b0,auStack_38,iVar4,uVar3,auStack_2c);
                    FUN_40132190(auStack_b0,param_1 + 0x98,iVar4,uVar3,auStack_2c);
                  }
                }
                FUN_40131548(auStack_38);
                FUN_40131548(auStack_2c);
                if (iVar1 != 0) goto LAB_4013b7e4;
              }
              iVar1 = FUN_40131900(auStack_b0,param_5,*(undefined4 *)(param_1 + 4));
            }
          }
        }
      }
    }
  }
LAB_4013b7e4:
  FUN_40131548(auStack_a4);
  FUN_40131548(auStack_98);
  FUN_40131548(auStack_8c);
  if (param_2 != 0) {
    FUN_40131548(auStack_68);
    FUN_40131548(auStack_5c);
  }
  FUN_40131548(auStack_b0);
  FUN_40131548(auStack_80);
  FUN_40131548(auStack_74);
  FUN_40131548(auStack_44);
  FUN_40131548(auStack_50);
  if ((iVar1 != 0) && (-0x80 < iVar1)) {
    iVar1 = iVar1 + -0x4300;
  }
  return iVar1;
}

