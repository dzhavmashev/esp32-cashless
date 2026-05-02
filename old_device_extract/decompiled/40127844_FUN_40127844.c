// Function : FUN_40127844
// Address  : 0x40127844
// Size     : 660 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_40127844(int *param_1,undefined4 param_2,uint param_3,undefined4 param_4,
                  undefined4 param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int *piStack_12c;
  int *piStack_120;
  int *piStack_114;
  int local_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  int iStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined1 auStack_e8 [64];
  undefined1 auStack_a8 [132];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  local_100 = 0x13;
  uStack_fc = 0;
  if (param_1 == (int *)0x0) {
    param_1 = &local_100;
  }
  uVar7 = 1;
  if (param_6 != 0) {
    uVar7 = 2;
  }
  piStack_12c = (int *)0x0;
  piStack_114 = (int *)0x0;
  piStack_120 = param_1;
  do {
    iVar8 = *piStack_120;
    if (iVar8 < 1) {
      memw();
      memw();
      if (iStack_24 == _DAT_3ffc5708) {
        return piStack_114;
      }
      memw();
      (*(code *)&SUB_40082ec4)();
    }
    if ((param_3 < 0x21) && (piVar1 = (int *)(*(code *)&SUB_40094dd8)(1,0x18), piVar1 != (int *)0x0)
       ) {
      piVar1[1] = iVar8;
      memw();
      iVar2 = FUN_40128d10(iVar8);
      piVar1[2] = iVar2;
      if (iVar2 == 0) {
        iVar8 = FUN_401289f0(iVar8);
        piVar1[4] = iVar8;
        if (iVar8 != 0) {
          memw();
          iVar12 = FUN_40127314(iVar8,param_2,param_3,param_4,param_5,param_6);
          piVar1[5] = iVar12;
          goto joined_r0x40127aba;
        }
      }
      else {
        memw();
        uVar3 = FUN_401857ec();
        memw();
        uVar4 = FUN_40128d5c(iVar2);
        if (uVar4 < 0x43) {
          iVar12 = FUN_401857b8();
          iVar11 = (uVar4 + 1 >> 1) + uVar4;
          uStack_f8 = param_4;
          uStack_f0 = param_5;
          if (param_6 != 0) {
            memw();
            iStack_f4 = param_6;
            uStack_ec = (*(code *)&SUB_4008c01c)(param_6);
          }
          if (iVar12 != 0x20) goto LAB_401278f1;
          memw();
          iVar12 = FUN_401020e4(param_2,param_3,uVar7,&uStack_f8,&uStack_f0,auStack_e8);
          if (((iVar12 < 0) ||
              (iVar12 = FUN_40125fd0(0x20,auStack_e8,0x20,"Element",auStack_a8,iVar11), iVar12 < 0))
             || (iVar5 = FUN_40128a30(auStack_a8,iVar11), iVar5 == 0)) goto LAB_401278f1;
          iVar12 = FUN_40128af0(iVar5,uVar3,iVar5);
          if ((iVar12 < 0) || (iVar12 = FUN_40128a90(iVar5,auStack_a8,0x84,uVar4), iVar12 < 0)) {
            iVar12 = 0;
            iVar10 = 0;
            iVar9 = 0;
          }
          else {
            iVar9 = FUN_40126250(iVar2,iVar8,iVar5);
            iVar10 = 0;
            iVar12 = 0;
            if (iVar9 != 0) {
              iVar6 = FUN_40125fd0(0x20,auStack_e8,0x20,"t u1 P1",auStack_a8,iVar11);
              iVar12 = 0;
              iVar10 = 0;
              if (-1 < iVar6) {
                FUN_40128a7c(iVar5,1);
                iVar5 = FUN_40128a30(auStack_a8,iVar11);
                iVar10 = 0;
                iVar12 = 0;
                if (iVar5 != 0) {
                  iVar11 = FUN_40128af0(iVar5,uVar3,iVar5);
                  iVar12 = 0;
                  iVar10 = 0;
                  if (-1 < iVar11) {
                    iVar11 = FUN_40128a90(iVar5,auStack_a8,0x84,uVar4);
                    iVar12 = 0;
                    iVar10 = 0;
                    if (-1 < iVar11) {
                      iVar10 = FUN_40126250(iVar2,iVar8,iVar5);
                      iVar12 = 0;
                      if ((iVar10 != 0) && (iVar12 = FUN_40128d44(iVar2), iVar12 != 0)) {
                        memw();
                        iVar8 = FUN_40128e34(iVar2,iVar9,iVar10,iVar12);
                        if (iVar8 < 0) {
                          FUN_40128d84(iVar12,1);
                          iVar12 = 0;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else {
LAB_401278f1:
          iVar12 = 0;
          iVar10 = 0;
          iVar9 = 0;
          iVar5 = 0;
        }
        memw();
        FUN_40102884(auStack_e8,0x40);
        FUN_40102884(auStack_a8,0x84);
        FUN_40128a7c(iVar5,1);
        FUN_40128d84(iVar9,1);
        FUN_40128d84(iVar10,1);
        piVar1[3] = iVar12;
joined_r0x40127aba:
        if (iVar12 != 0) {
          if (piStack_12c == (int *)0x0) {
            memw();
            piStack_12c = piVar1;
            piStack_114 = piVar1;
          }
          else {
            *piStack_12c = (int)piVar1;
            memw();
            piStack_12c = piVar1;
          }
          goto LAB_4012793d;
        }
      }
      memw();
      FUN_40127814(piVar1);
    }
LAB_4012793d:
    piStack_120 = piStack_120 + 1;
    memw();
  } while( true );
}

