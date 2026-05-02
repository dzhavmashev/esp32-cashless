// Function : FUN_401224e0
// Address  : 0x401224e0
// Size     : 1347 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_401224e0(void)

{
  ushort uVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  int iStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 auStack_64 [3];
  undefined4 uStack_58;
  undefined2 uStack_54;
  undefined1 auStack_52 [10];
  undefined2 uStack_48;
  undefined2 uStack_46;
  uint uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined4 uStack_28;
  int iStack_24;
  
  uVar2 = _DAT_3ffc72e4;
  uVar1 = _DAT_3ffc72dc;
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  uVar3 = (uint)_DAT_3ffc72dc;
  if (uVar3 == 1) {
    memw();
    (*(code *)&SUB_4008b530)(auStack_52,0,0x2e);
    uStack_58 = 0x464c457f;
    uStack_54 = 0x101;
    auStack_52[0] = (undefined1)uVar1;
    uStack_48 = 4;
    memw();
    memw();
    uStack_46 = FUN_40185684();
    uStack_2c = uVar2;
    memw();
    uStack_40 = 0;
    uStack_38 = 0;
    uStack_34 = 0;
    uStack_28 = 0;
    uStack_30 = 0x200034;
    uStack_2a = 0x28;
    memw();
    uStack_3c = 0x34;
    memw();
    uStack_44 = uVar3;
    iVar8 = (**(code **)(_DAT_3ffc72e8 + 8))(*(undefined4 *)(_DAT_3ffc72e8 + 0x10),&uStack_58);
    if (iVar8 != 0) {
      uVar4 = (*(code *)&SUB_40094ae8)();
      (*(code *)&SUB_40007d54)(0x3ffc169d,uVar4,0x3ffc16cf,"ks_data",0x87,iVar8);
      iVar8 = -2;
      goto LAB_4012258d;
    }
  }
  do {
    iVar8 = 0x34;
    if (_DAT_3ffc72dc == 2) {
      iVar8 = 0;
    }
LAB_4012258d:
    iVar6 = iVar8;
    if (_DAT_3ffc72dc == 2) {
      if (iVar8 < 0) {
        uVar4 = (*(code *)&SUB_40094ae8)();
        uVar11 = 0x221;
        uVar10 = 0x3ffc0f61;
        goto LAB_401225ae;
      }
LAB_401225fd:
      (*(code *)&SUB_4008b530)(&uStack_70,0,0xc);
      uStack_78 = 0;
      iStack_74 = 0;
      memw();
      (*(code *)&SUB_4008b530)(auStack_64,0,0xc);
      FUN_40121a78();
      iVar5 = FUN_40121b0c();
      iVar6 = FUN_40121b20(iVar5,auStack_64,0);
      if (iVar6 != 0) {
        iVar6 = FUN_401222ec(auStack_64);
        if (_DAT_3ffc72dc == 1) {
          if (-1 < iVar6) goto LAB_40122636;
          uVar4 = (*(code *)&SUB_40094ae8)();
          uVar11 = 0x181;
          uVar10 = 0x3ffc1347;
        }
        else {
          if (0 < iVar6) goto LAB_40122636;
          uVar4 = (*(code *)&SUB_40094ae8)();
          uVar11 = 0x183;
          uVar10 = 0x3ffc1305;
          memw();
        }
LAB_4012269c:
        memw();
        (*(code *)&SUB_40007d54)(uVar10,uVar4,0x3ffc16cf,"dd_note",uVar11,iVar5,iVar6);
LAB_401226a5:
        uVar4 = (*(code *)&SUB_40094ae8)();
        (*(code *)&SUB_40007d54)(0x3ffc117d,uVar4,0x3ffc16cf,"ks_regs",0x1bb,iVar6);
LAB_401227dc:
        uVar4 = (*(code *)&SUB_40094ae8)();
        uVar11 = 0x228;
        uVar10 = 0x3ffc0ee9;
        goto LAB_401225ae;
      }
      iVar6 = 0;
LAB_40122636:
      iVar5 = 0;
      while (iVar5 = FUN_40121a80(iVar5), iVar5 != 0) {
        iVar7 = FUN_40121b0c();
        if ((iVar5 != iVar7) && (iVar7 = FUN_40121b20(iVar5,auStack_64,0), iVar7 != 0)) {
          iVar7 = FUN_401222ec(auStack_64);
          if (_DAT_3ffc72dc == 1) {
            if (iVar7 < 0) {
              uVar4 = (*(code *)&SUB_40094ae8)();
              uVar11 = 0x193;
              uVar10 = 0x3ffc12c3;
              memw();
              iVar6 = iVar7;
              goto LAB_4012269c;
            }
          }
          else if (iVar7 < 1) {
            uVar4 = (*(code *)&SUB_40094ae8)();
            uVar11 = 0x195;
            uVar10 = 0x3ffc1281;
            memw();
            iVar6 = iVar7;
            goto LAB_4012269c;
          }
          iVar6 = iVar6 + iVar7;
        }
      }
      iVar5 = FUN_40122454(iVar6);
      if (iVar5 < 1) {
        uVar4 = (*(code *)&SUB_40094ae8)();
        (*(code *)&SUB_40007d54)(0x3ffc1234,uVar4,0x3ffc16cf,"dd_note",0x19c,iVar5);
        iVar6 = iVar5;
        goto LAB_401226a5;
      }
      FUN_40121a78();
      iVar7 = 0;
LAB_40122832:
      iVar7 = FUN_40121a80(iVar7);
      if (iVar7 != 0) {
        iVar6 = FUN_40121b20(iVar7,&uStack_70,&uStack_78);
        if (iVar6 != 0) {
          iVar6 = FUN_40122370(uStack_70,uStack_70,0x158);
          if (iVar6 < 1) {
            uVar4 = (*(code *)&SUB_40094ae8)();
            (*(code *)&SUB_40007d54)(0x3ffc1415,uVar4,0x3ffc16cf,uStack_70,iVar6);
            uVar4 = (*(code *)&SUB_40094ae8)();
            memw();
            (*(code *)&SUB_40007d54)(0x3ffc11f8,uVar4,0x3ffc16cf,"segment",0x1a6,uStack_70,iVar6);
          }
          else {
            auStack_64[0] = 0;
            memw();
            uVar4 = FUN_40122cc0(&uStack_70,&uStack_7c,auStack_64);
            iVar9 = FUN_40122370(uStack_7c,auStack_64[0],uVar4);
            if (iVar9 < 1) {
              uVar4 = (*(code *)&SUB_40094ae8)();
              (*(code *)&SUB_40007d54)(0x3ffc13cf,uVar4,0x3ffc16cf,uStack_70,uStack_6c,iVar9);
              if (iVar9 == -2) {
                uVar4 = (*(code *)&SUB_40094ae8)();
                memw();
                (*(code *)&SUB_40007d54)
                          (0x3ffc11ba,uVar4,0x3ffc16cf,"segment",0x1aa,uStack_70,0xfffffffe);
                iVar6 = -2;
                goto LAB_401227b8;
              }
            }
            iVar6 = iVar9 + iVar6;
            if (0 < iVar6) {
              iVar5 = iVar5 + iVar6;
              if (iStack_74 != 0) {
                iVar6 = FUN_40122370(uStack_78,uStack_78);
                if (iVar6 < 1) {
                  uVar4 = (*(code *)&SUB_40094ae8)();
                  (*(code *)&SUB_40007d54)(0x3ffc10fb,uVar4,0x3ffc16cf,"ks_regs",0x1d4,iVar6);
                  goto LAB_401227dc;
                }
                iVar5 = iVar5 + iVar6;
              }
              goto LAB_40122832;
            }
          }
LAB_401227b8:
          uVar4 = (*(code *)&SUB_40094ae8)();
          memw();
          (*(code *)&SUB_40007d54)(0x3ffc1141,uVar4,0x3ffc16cf,"ks_regs",0x1cb,iVar7,iVar6);
          goto LAB_401227dc;
        }
        goto LAB_40122832;
      }
      iVar7 = 0;
      iVar9 = 0;
      auStack_64[0] = 0;
      do {
        memw();
        iVar6 = FUN_40121a90(iVar9,auStack_64);
        if (iVar6 < 0) {
          uVar4 = (*(code *)&SUB_40094ae8)();
          (*(code *)&SUB_40007d54)(0x3ffc10d1,uVar4,0x3ffc16cf,"mp_info",0x1e5);
          iVar6 = -3;
LAB_4012286c:
          uVar4 = (*(code *)&SUB_40094ae8)();
          (*(code *)&SUB_40007d54)(0x3ffc0ea8,uVar4,0x3ffc16cf,"_header",0x22d,iVar6);
          goto LAB_401225b4;
        }
        if (iVar6 != 0) {
          iVar6 = FUN_40122370(auStack_64[0],auStack_64[0],iVar6);
          if (iVar6 < 1) {
            uVar4 = (*(code *)&SUB_40094ae8)();
            (*(code *)&SUB_40007d54)(0x3ffc1092,uVar4,0x3ffc16cf,"mp_info",0x1ed,iVar6);
            iVar7 = iVar6;
            if (iVar6 != 0) goto LAB_4012286c;
            break;
          }
          iVar7 = iVar7 + iVar6;
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 != 4);
      auStack_64[0] = 0;
      memw();
      (*(code *)&SUB_4008178c)(0x3ffc7298,0x42);
      _DAT_3ffc7294 = FUN_4018568c();
      memw();
      iVar9 = FUN_40122194("ck",0x204a,&DAT_3ffc7294,0x48);
      if (iVar9 < 1) {
        uVar4 = (*(code *)&SUB_40094ae8)();
        (*(code *)&SUB_40007d54)(0x3ffc104f,uVar4,0x3ffc16cf,"RA_INFO",0x204,iVar9);
        iVar6 = iVar9;
LAB_40122910:
        uVar4 = (*(code *)&SUB_40094ae8)();
        uVar11 = 0x233;
        uVar10 = 0x3ffc0e68;
        goto LAB_401225ae;
      }
      iVar6 = FUN_401231fc(auStack_64);
      if (iVar6 == 0) {
        uVar4 = (*(code *)&SUB_40094ae8)();
        (*(code *)&SUB_40007d54)(0x3ffc102d,uVar4,0x3ffc16cf);
        iVar6 = -3;
        goto LAB_40122910;
      }
      iVar6 = FUN_40122194("MP_INFO",0x2a5,auStack_64[0],iVar6);
      if (iVar6 < 1) {
        uVar4 = (*(code *)&SUB_40094ae8)();
        uVar11 = 0x212;
        uVar10 = 0x3ffc0fec;
LAB_40122986:
        (*(code *)&SUB_40007d54)(uVar10,uVar4,0x3ffc16cf,"RA_INFO",uVar11,iVar6);
        goto LAB_40122910;
      }
      iVar6 = FUN_40122454(iVar9 + iVar6);
      if (iVar6 < 1) {
        uVar4 = (*(code *)&SUB_40094ae8)();
        uVar11 = 0x217;
        uVar10 = 0x3ffc0f9e;
        goto LAB_40122986;
      }
      iVar6 = iVar6 + iVar8 + iVar5 + iVar7;
    }
    else {
      if (0 < iVar8) goto LAB_401225fd;
      uVar4 = (*(code *)&SUB_40094ae8)();
      uVar11 = 0x223;
      uVar10 = 0x3ffc0f24;
LAB_401225ae:
      (*(code *)&SUB_40007d54)(uVar10,uVar4,0x3ffc16cf,"_header",uVar11,iVar6);
    }
LAB_401225b4:
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) {
      return iVar6;
    }
    (*(code *)&SUB_40082ec4)();
  } while( true );
}

