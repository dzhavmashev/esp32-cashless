// Function : FUN_4013633c
// Address  : 0x4013633c
// Size     : 1126 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4013633c(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 undefined1 *param_6,undefined4 param_7)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iStack_150;
  int iStack_148;
  int iStack_144;
  undefined1 *puStack_140;
  undefined1 auStack_124 [12];
  undefined1 auStack_118 [12];
  undefined1 auStack_10c [12];
  undefined1 auStack_100 [12];
  undefined1 auStack_f4 [12];
  undefined1 auStack_e8 [12];
  undefined1 auStack_dc [12];
  undefined1 auStack_d0 [12];
  undefined1 auStack_c4 [12];
  undefined1 auStack_b8 [12];
  undefined1 auStack_ac [24];
  undefined1 auStack_94 [12];
  undefined1 auStack_88 [100];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  iVar2 = FUN_401362d4(param_1,param_3);
  if (iVar2 != 0) goto LAB_401364e0;
  iVar2 = FUN_40136114(param_1,param_4);
  if (iVar2 != 0) goto LAB_401364e0;
  iVar3 = FUN_401863d8(param_1);
  iVar2 = -0x4f80;
  if (iVar3 == 2) {
    FUN_40138c04(auStack_88);
    FUN_4013562c(auStack_ac);
    FUN_40186008(auStack_124);
    iStack_144 = param_5;
    puStack_140 = param_6;
    if (param_5 == 0) {
      memw();
      iVar2 = FUN_40134e20(auStack_88,param_3,*(int *)(param_1 + 0x5c) + 7U >> 3);
      if (iVar2 != 0) goto LAB_40136499;
      puStack_140 = auStack_88;
      iStack_144 = 0x40134e08;
    }
    memw();
    iVar2 = FUN_4013167c(auStack_124,param_4);
    if (iVar2 != 0) goto LAB_40136499;
    iVar2 = FUN_4013572c(auStack_ac,param_4);
    if (iVar2 != 0) goto LAB_40136499;
    iVar2 = FUN_40131700(param_2,1);
    if (iVar2 != 0) goto LAB_40136499;
    iVar3 = param_2 + 0x18;
    iVar2 = FUN_40131700(iVar3,0);
    if (iVar2 != 0) goto LAB_40136499;
    FUN_40131548(param_2 + 0xc);
    while( true ) {
      iStack_148 = param_1 + 4;
      memw();
      iVar2 = FUN_401860ec(auStack_ac,iStack_148);
      if (iVar2 < 0) break;
      iVar2 = FUN_40131bcc(auStack_ac,auStack_ac,iStack_148);
      if (iVar2 != 0) goto LAB_40136499;
    }
    iVar2 = FUN_40134fec(param_1,auStack_ac,iStack_144,puStack_140);
    if (iVar2 != 0) goto LAB_40136499;
    iStack_150 = *(int *)(param_1 + 0x5c);
    goto LAB_40136444;
  }
  do {
    iVar3 = FUN_401863d8(param_1);
    if (iVar3 == 1) {
      memw();
      iVar2 = FUN_401359d0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
LAB_401364e0:
    do {
      param_1 = iVar2;
      iVar3 = iStack_24;
      param_2 = _DAT_3ffc5708;
      memw();
      memw();
      if (iStack_24 == _DAT_3ffc5708) {
        return;
      }
      (*(code *)&SUB_40082ec4)();
      do {
        uVar1 = FUN_4018601c(param_3,iStack_150);
        iVar2 = FUN_401336b8(param_2,auStack_ac,uVar1);
        if ((iVar2 != 0) || (iVar2 = FUN_401336b8(iVar3,auStack_94,uVar1), iVar2 != 0))
        goto LAB_40136499;
        FUN_40186008(auStack_118);
        FUN_40186008(auStack_10c);
        FUN_40186008(auStack_100);
        FUN_40186008(auStack_f4);
        FUN_40186008(auStack_e8);
        FUN_40186008(auStack_dc);
        FUN_40186008(auStack_d0);
        FUN_40186008(auStack_c4);
        FUN_40186008(auStack_b8);
        iVar2 = FUN_40134f28(param_1,auStack_118,param_2,iVar3);
        if (((((iVar2 == 0) &&
              (((iVar2 = FUN_40134f44(param_1,auStack_10c,auStack_118), iVar2 == 0 &&
                (iVar2 = FUN_40134ebc(param_1,auStack_100,param_2,iVar3), iVar2 == 0)) &&
               (iVar2 = FUN_40134f44(param_1,auStack_f4,auStack_100), iVar2 == 0)))) &&
             (((iVar2 = FUN_40134ebc(param_1,auStack_e8,auStack_10c,auStack_f4), iVar2 == 0 &&
               (iVar2 = FUN_40134f28(param_1,auStack_dc,auStack_ac,auStack_94), iVar2 == 0)) &&
              (iVar2 = FUN_40134ebc(param_1,auStack_d0,auStack_ac,auStack_94), iVar2 == 0)))) &&
            ((iVar2 = FUN_40134f44(param_1,auStack_c4,auStack_d0,auStack_118), iVar2 == 0 &&
             (iVar2 = FUN_40134f44(param_1,auStack_b8,auStack_dc,auStack_100), iVar2 == 0)))) &&
           (((iVar2 = FUN_40134f28(param_1,auStack_ac,auStack_c4,auStack_b8), iVar2 == 0 &&
             (((iVar2 = FUN_40134f44(param_1,auStack_ac,auStack_ac), iVar2 == 0 &&
               (iVar2 = FUN_40134ebc(param_1,auStack_94,auStack_c4,auStack_b8), iVar2 == 0)) &&
              (iVar2 = FUN_40134f44(param_1,auStack_94,auStack_94), iVar2 == 0)))) &&
            (((iVar2 = FUN_40134f44(param_1,auStack_94,auStack_124), iVar2 == 0 &&
              (iVar2 = FUN_40134f44(param_1,param_2,auStack_10c,auStack_f4), iVar2 == 0)) &&
             ((iVar2 = FUN_40134f44(param_1,iVar3,param_1 + 0x10,auStack_e8), iVar2 == 0 &&
              (iVar2 = FUN_40134f28(param_1,iVar3,auStack_f4,iVar3), iVar2 == 0)))))))) {
          iVar2 = FUN_40134f44(param_1,iVar3,auStack_e8,iVar3);
        }
        FUN_40131548(auStack_118);
        FUN_40131548(auStack_10c);
        FUN_40131548(auStack_100);
        FUN_40131548(auStack_f4);
        FUN_40131548(auStack_e8);
        FUN_40131548(auStack_dc);
        FUN_40131548(auStack_d0);
        FUN_40131548(auStack_c4);
        FUN_40131548(auStack_b8);
        if ((iVar2 != 0) || (iVar2 = FUN_401336b8(param_2,auStack_ac,uVar1), iVar2 != 0))
        goto LAB_40136499;
        iVar2 = FUN_401336b8(iVar3,auStack_94,uVar1);
        iStack_150 = iStack_150 + -1;
        if (iVar2 != 0) {
          memw();
          goto LAB_40136499;
        }
LAB_40136444:
      } while (iStack_150 != -1);
      memw();
      iVar2 = FUN_40134fec(param_1,param_2,iStack_144,puStack_140);
      if (((iVar2 == 0) && (iVar2 = FUN_40132650(iVar3,iVar3,iStack_148), iVar2 == 0)) &&
         (iVar2 = FUN_40134f44(param_1,param_2,param_2,iVar3), iVar2 == 0)) {
        iVar2 = FUN_40131700(iVar3,1);
      }
LAB_40136499:
      FUN_40138f14(auStack_88);
      FUN_40135340(auStack_ac);
      FUN_40131548(auStack_124);
    } while (iVar2 != 0);
  } while( true );
}

