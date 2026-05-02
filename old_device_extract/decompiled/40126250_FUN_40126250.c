// Function : FUN_40126250
// Address  : 0x40126250
// Size     : 1637 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40126250(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iStack_1d8;
  int iStack_1d4;
  int iStack_1d0;
  int iStack_1c8;
  int iStack_1c4;
  int iStack_1c0;
  int iStack_1bc;
  int iStack_1b8;
  int iStack_1b4;
  int iStack_1b0;
  int iStack_1ac;
  int iStack_1a8;
  int iStack_1a4;
  int iStack_19c;
  int iStack_198;
  undefined1 auStack_18e [32];
  undefined1 auStack_16e [65];
  byte abStack_12d [66];
  byte abStack_eb [67];
  undefined1 auStack_a8 [132];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar2 = 0;
  if (param_2 != 0x13) goto LAB_40126895;
  memw();
  uVar3 = FUN_401857ec(param_1);
  iVar4 = FUN_40128d5c(param_1);
  (*(code *)&SUB_4008b3d0)(auStack_18e,"",0x20);
  uVar5 = FUN_40128a30(auStack_18e,0x20);
  uVar6 = FUN_401857fc(param_1);
  iStack_1bc = FUN_40128a18();
  memw();
  iVar7 = FUN_40128a18();
  iStack_1d4 = FUN_40128a18();
  memw();
  iStack_1c8 = FUN_40128a58(10);
  memw();
  iStack_1b8 = FUN_40128a18();
  memw();
  iStack_198 = FUN_40128a58(0);
  memw();
  iStack_1b4 = FUN_40128a58(1);
  memw();
  iStack_19c = FUN_40128a58(2);
  memw();
  iStack_1a4 = FUN_40128a58(3);
  memw();
  iStack_1b0 = FUN_40128a18();
  memw();
  iStack_1ac = FUN_40128a18();
  memw();
  iStack_1c4 = FUN_40128a18();
  memw();
  iStack_1c0 = FUN_40128a18();
  memw();
  iStack_1a8 = FUN_40128a18();
  memw();
  iStack_1d8 = FUN_40128a18();
  if ((((((iStack_1bc != 0) && (iVar7 != 0)) && (iStack_1d4 != 0)) &&
       ((iStack_1c8 != 0 && (iStack_1b8 != 0)))) &&
      ((iStack_198 != 0 && ((iStack_1b4 != 0 && (iStack_19c != 0)))))) &&
     ((iStack_1a4 != 0 &&
      ((((((iStack_1b0 != 0 && (iStack_1ac != 0)) && (iStack_1c4 != 0)) &&
         (((iStack_1c0 != 0 && iStack_1a8 != 0 && (iStack_1d8 != 0)) &&
          ((iVar2 = FUN_40128b3c(uVar3,iStack_1c8), -1 < iVar2 &&
           ((iVar2 = FUN_40128b9c(param_3,uVar3,iStack_1bc), -1 < iVar2 &&
            (iVar2 = FUN_40128b74(iStack_1c8,iStack_1bc,uVar3,iVar7), -1 < iVar2)))))))) &&
        (iVar2 = FUN_40128b9c(iVar7,uVar3,iStack_1d4), -1 < iVar2)) &&
       ((iVar2 = FUN_40128ad8(iVar7,iStack_1d4,iStack_1d8), -1 < iVar2 &&
        (iVar2 = FUN_40128af0(iStack_1d8,uVar3,iVar7), -1 < iVar2)))))))) {
    FUN_40126228(iVar7,iVar4);
    uVar8 = FUN_40128c14(iVar7);
    iVar2 = FUN_40128b3c(uVar3,iStack_19c,iStack_1d4);
    if ((-1 < iVar2) && (iVar2 = FUN_40128b08(iVar7,iStack_1d4,uVar3,iStack_1b8), -1 < iVar2)) {
      FUN_40126228(iStack_1b8,iVar4);
      iVar2 = FUN_40128b74(iStack_1c8,uVar5,uVar3,iVar7);
      if (((-1 < iVar2) && (iVar2 = FUN_40128b24(iVar7,uVar3,iVar7), -1 < iVar2)) &&
         (iVar2 = FUN_40128b74(uVar6,iVar7,uVar3,iStack_1b0), -1 < iVar2)) {
        FUN_40126228(iStack_1b0,iVar4);
        iVar2 = FUN_40128b3c(uVar3,uVar6,iVar7);
        if ((((-1 < iVar2) && (iVar2 = FUN_40128b24(uVar5,uVar3,iStack_1d4), -1 < iVar2)) &&
            (iVar2 = FUN_40128b74(iVar7,iStack_1d4,uVar3,iVar7), -1 < iVar2)) &&
           (((iVar2 = FUN_40128ad8(iStack_1b4,iStack_1b8,iStack_1d8), -1 < iVar2 &&
             (iVar2 = FUN_40128af0(iStack_1d8,uVar3,iStack_1d4), -1 < iVar2)) &&
            (iVar2 = FUN_40128b74(iVar7,iStack_1d4,uVar3,iStack_1ac), -1 < iVar2)))) {
          FUN_40126228(iStack_1ac,iVar4);
          iVar2 = FUN_40128a90(iStack_1b0,abStack_12d + 1,0x42,iVar4);
          if ((-1 < iVar2) &&
             (iVar2 = FUN_40128a90(iStack_1ac,abStack_eb + 1,0x42,iVar4), -1 < iVar2)) {
            uVar1 = FUN_4018572c(uVar8 ^ 1);
            FUN_40185740(uVar1,abStack_12d + 1,abStack_eb + 1,iVar4,auStack_16e);
            iStack_1d0 = FUN_40128a30(auStack_16e,iVar4);
            if (iStack_1d0 != 0) {
              memw();
              FUN_40126228(iStack_1d0,iVar4);
              iVar2 = FUN_40128b08(iStack_1d0,iStack_1a4,uVar3,iVar7);
              if (((((-1 < iVar2) &&
                    (iVar2 = FUN_40128b74(uVar5,iStack_1d0,uVar3,iStack_1d4), -1 < iVar2)) &&
                   (iVar2 = FUN_40128ad8(iVar7,iStack_1d4,iStack_1d8), -1 < iVar2)) &&
                  ((iVar2 = FUN_40128af0(iStack_1d8,uVar3,iVar7), -1 < iVar2 &&
                   (iVar2 = FUN_40128ad8(iVar7,uVar6,iStack_1d8), -1 < iVar2)))) &&
                 (iVar2 = FUN_40128af0(iStack_1d8,uVar3,iStack_1c0), -1 < iVar2)) {
                FUN_40126228(iStack_1c0,iVar4);
                iVar2 = FUN_40128b74(iStack_1c8,iStack_1bc,uVar3,iVar7);
                if ((-1 < iVar2) &&
                   (iVar2 = FUN_40128b74(iVar7,iStack_1d0,uVar3,iStack_1c4), -1 < iVar2)) {
                  FUN_40126228(iStack_1c4,iVar4);
                  iVar2 = FUN_40128b08(iStack_1c4,iStack_1a4,uVar3,iVar7);
                  if (((-1 < iVar2) &&
                      (((iVar2 = FUN_40128b74(uVar5,iStack_1c4,uVar3,iStack_1d4), -1 < iVar2 &&
                        (iVar2 = FUN_40128ad8(iVar7,iStack_1d4,iStack_1d8), -1 < iVar2)) &&
                       (iVar2 = FUN_40128af0(iStack_1d8,uVar3,iVar7), -1 < iVar2)))) &&
                     ((iVar2 = FUN_40128ad8(iVar7,uVar6,iStack_1d8), -1 < iVar2 &&
                      (iVar2 = FUN_40128af0(iStack_1d8,uVar3,iStack_1a8), -1 < iVar2)))) {
                    FUN_40126228(iStack_1a8,iVar4);
                    iVar2 = FUN_40128b3c(uVar3,iStack_1b4,iVar7);
                    if ((-1 < iVar2) &&
                       ((iVar2 = FUN_40128bd0(iVar7,1,iVar7), -1 < iVar2 &&
                        (iVar2 = FUN_40128b08(iStack_1c0,iVar7,uVar3,iStack_1d8), -1 < iVar2)))) {
                      FUN_40126228(iVar7,iVar4);
                      uVar8 = FUN_40128c14(iStack_1d8);
                      uVar9 = FUN_40128c2c(iStack_1d8);
                      uVar1 = FUN_4018572c((uVar8 | uVar9) ^ 1);
                      iVar2 = FUN_40128a90(iStack_1c0,abStack_12d + 1,0x42,iVar4);
                      if ((-1 < iVar2) &&
                         (iVar2 = FUN_40128a90(iStack_1a8,abStack_eb + 1,0x42,iVar4), -1 < iVar2)) {
                        memw();
                        FUN_40185740(uVar1,abStack_12d + 1,abStack_eb + 1,iVar4,auStack_16e);
                        iVar10 = FUN_40128a30(auStack_16e,iVar4);
                        iVar2 = 0;
                        iVar12 = 0;
                        if (iVar10 == 0) goto LAB_401267d8;
                        FUN_40126228(iVar10,iVar4);
                        iVar11 = FUN_40128a90(iStack_1d0,abStack_12d + 1,0x42,iVar4);
                        iVar2 = 0;
                        iVar12 = 0;
                        if (iVar11 < 0) goto LAB_401267d8;
                        iVar11 = FUN_40128a90(iStack_1c4,abStack_eb + 1,0x42,iVar4);
                        iVar2 = 0;
                        iVar12 = 0;
                        if (iVar11 < 0) goto LAB_401267d8;
                        FUN_40185740(uVar1,abStack_12d + 1,abStack_eb + 1,iVar4,auStack_a8);
                        iVar11 = FUN_40128a90(uVar3,abStack_12d + 1,0x42,iVar4);
                        iVar2 = 0;
                        iVar12 = 0;
                        if (iVar11 < 0) goto LAB_401267d8;
                        iVar2 = 0;
                        if ((abStack_12d[iVar4] & 3) != 3) goto LAB_401267d8;
                        memw();
                        iVar12 = FUN_40128a18();
                        iVar2 = 0;
                        if (iVar12 == 0) goto LAB_401267d8;
                        iVar11 = FUN_40128ad8(uVar3,iStack_1b4,iVar7);
                        iVar2 = 0;
                        if (iVar11 < 0) goto LAB_401267d8;
                        iVar11 = FUN_40128bd0(iVar7,2,iVar7);
                        iVar2 = 0;
                        if (iVar11 < 0) goto LAB_401267d8;
                        iVar11 = FUN_40128b08(iVar10,iVar7,uVar3,iVar12);
                        iVar2 = 0;
                        if (iVar11 < 0) goto LAB_401267d8;
                        FUN_40126228(iVar12,iVar4);
                        iVar11 = FUN_40128a90(param_3,abStack_12d + 1,0x42,iVar4);
                        iVar2 = 0;
                        if (iVar11 < 0) goto LAB_401267d8;
                        iVar11 = FUN_40128a90(iVar12,abStack_eb + 1,0x42,iVar4);
                        iVar2 = 0;
                        if (iVar11 < 0) goto LAB_401267d8;
                        uVar1 = FUN_4018572c((abStack_12d[iVar4] ^ abStack_eb[iVar4]) & 1);
                        memw();
                        iVar11 = FUN_40128b3c(uVar3,iVar12,iVar7);
                        iVar2 = 0;
                        if (iVar11 < 0) goto LAB_401267d8;
                        FUN_40126228(iVar7,iVar4);
                        iVar11 = FUN_40128a90(iVar12,abStack_12d + 1,0x42,iVar4);
                        iVar2 = 0;
                        if (iVar11 < 0) goto LAB_401267d8;
                        iVar11 = FUN_40128a90(iVar7,abStack_eb + 1,0x42,iVar4);
                        iVar2 = 0;
                        if (iVar11 < 0) goto LAB_401267d8;
                        FUN_40185740(uVar1,abStack_12d + 1,abStack_eb + 1,iVar4,auStack_a8 + iVar4);
                        iVar2 = FUN_40128dd4(param_1,auStack_a8);
                        goto LAB_401267d8;
                      }
                    }
                  }
                }
              }
              goto LAB_40126346;
            }
          }
        }
      }
    }
  }
  iStack_1d0 = 0;
LAB_40126346:
  while( true ) {
    iVar10 = 0;
    iVar2 = 0;
    memw();
    iVar12 = iVar2;
LAB_401267d8:
    FUN_40128a7c(iStack_1d8,0);
    FUN_40128a7c(iStack_1bc,1);
    FUN_40128a7c(iVar7,1);
    FUN_40128a7c(iStack_1d4,1);
    FUN_40128a7c(iStack_1c8,0);
    FUN_40128a7c(iStack_1b8,1);
    FUN_40128a7c(iStack_1b0,1);
    FUN_40128a7c(iStack_1ac,1);
    FUN_40128a7c(iStack_1d0,1);
    FUN_40128a7c(iStack_1c4,1);
    FUN_40128a7c(iStack_1c0,1);
    FUN_40128a7c(iStack_1a8,1);
    FUN_40128a7c(iVar12,1);
    FUN_40128a7c(iVar10,1);
    FUN_40128a7c(iStack_198,0);
    FUN_40128a7c(iStack_1b4,0);
    FUN_40128a7c(iStack_19c,0);
    FUN_40128a7c(iStack_1a4,0);
    FUN_40102884(auStack_16e,0x42);
    FUN_40102884(abStack_12d + 1,0x42);
    FUN_40102884(abStack_eb + 1,0x42);
    FUN_40102884(auStack_a8,0x84);
LAB_40126895:
    iVar7 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    (*(code *)&SUB_40082ec4)();
  }
  return iVar2;
}

